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

#include "qnetworkaccessmanager_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractnetworkcache.h>
#include <qauthenticator.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qiodevice.h>
#include <qmetaobject.h>
#include <qnetworkconfiguration.h>
#include <qnetworkcookiejar.h>
#include <qnetworkproxy.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qsslerror.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QNetworkAccessManagerWrapper::QNetworkAccessManagerWrapper(QObject * parent) : QNetworkAccessManager(parent) {
    // ... middle
}

void QNetworkAccessManagerWrapper::childEvent(QChildEvent * arg__1)
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

void QNetworkAccessManagerWrapper::connectNotify(const char * signal)
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

QNetworkReply * QNetworkAccessManagerWrapper::createRequest(QNetworkAccessManager::Operation op, const QNetworkRequest & request, QIODevice * outgoingData)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QNetworkReply*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createRequest"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QNetworkAccessManager::createRequest(op, request, outgoingData);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), &op),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], &request),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], outgoingData)
    ));
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QNetworkReply*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkAccessManager.createRequest", Shiboken::SbkType< QNetworkReply >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QNetworkReply*)0);
    }
    ::QNetworkReply* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
    return cppResult;
}

void QNetworkAccessManagerWrapper::customEvent(QEvent * arg__1)
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

void QNetworkAccessManagerWrapper::disconnectNotify(const char * signal)
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

bool QNetworkAccessManagerWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkAccessManager.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QNetworkAccessManagerWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkAccessManager.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QNetworkAccessManagerWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QNetworkAccessManagerWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QNetworkAccessManager::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QNetworkAccessManagerWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QNetworkAccessManager::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QNetworkAccessManagerWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QNetworkAccessManagerWrapper* >(this));
        return QNetworkAccessManager::qt_metacast(_clname);
}

QNetworkAccessManagerWrapper::~QNetworkAccessManagerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkAccessManager_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkAccessManager >()))
        return -1;

    ::QNetworkAccessManagerWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QNetworkAccessManager", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkAccessManager(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkAccessManager(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QNetworkAccessManager(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManager_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QNetworkAccessManager_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QNetworkAccessManager(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QNetworkAccessManagerWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QNetworkAccessManagerWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkAccessManager >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkAccessManager_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QNetworkAccessManager_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAccessManager", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_activeConfiguration(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activeConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->activeConfiguration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_cache(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cache()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractNetworkCache * cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->cache();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QABSTRACTNETWORKCACHE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_configuration(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // configuration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->configuration();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_cookieJar(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cookieJar()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkCookieJar * cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->cookieJar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIEJAR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_createRequest(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.createRequest(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.createRequest(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:createRequest", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createRequest(QNetworkAccessManager::Operation,QNetworkRequest,QIODevice*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // createRequest(QNetworkAccessManager::Operation,QNetworkRequest,QIODevice*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
            overloadId = 0; // createRequest(QNetworkAccessManager::Operation,QNetworkRequest,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_createRequest_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "outgoingData");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.createRequest(): got multiple values for keyword argument 'outgoingData'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                    goto Sbk_QNetworkAccessManagerFunc_createRequest_TypeError;
            }
        }
        ::QNetworkAccessManager::Operation cppArg0 = ((::QNetworkAccessManager::Operation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QNetworkRequest cppArg1_local = ::QNetworkRequest(::QUrl());
        ::QNetworkRequest* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QIODevice* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createRequest(QNetworkAccessManager::Operation,QNetworkRequest,QIODevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QNetworkAccessManager::createRequest(cppArg0, *cppArg1, cppArg2) : cppSelf->createRequest(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_createRequest_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkAccessManager.Operation, PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QIODevice = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAccessManager.createRequest", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_deleteResource(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deleteResource(QNetworkRequest)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
        overloadId = 0; // deleteResource(QNetworkRequest)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_deleteResource_TypeError;

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
            // deleteResource(QNetworkRequest)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply * cppResult = cppSelf->deleteResource(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_deleteResource_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.deleteResource", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_get(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: get(QNetworkRequest)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
        overloadId = 0; // get(QNetworkRequest)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_get_TypeError;

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
            // get(QNetworkRequest)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply * cppResult = cppSelf->get(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_get_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.get", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_head(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: head(QNetworkRequest)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArg)))) {
        overloadId = 0; // head(QNetworkRequest)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_head_TypeError;

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
            // head(QNetworkRequest)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply * cppResult = cppSelf->head(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_head_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.head", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_networkAccessible(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // networkAccessible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkAccessManager::NetworkAccessibility cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->networkAccessible();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_post(PyObject* self, PyObject* args)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "post", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: post(QNetworkRequest,QIODevice*)
    // 1: post(QNetworkRequest,QByteArray)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 1; // post(QNetworkRequest,QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            overloadId = 0; // post(QNetworkRequest,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_post_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // post(const QNetworkRequest & request, QIODevice * data)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // post(QNetworkRequest,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QNetworkReply * cppResult = cppSelf->post(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // post(const QNetworkRequest & request, const QByteArray & data)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
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
                // post(QNetworkRequest,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QNetworkReply * cppResult = cppSelf->post(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_post_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QIODevice", "PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAccessManager.post", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_proxy(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxy cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->proxy();
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

static PyObject* Sbk_QNetworkAccessManagerFunc_proxyFactory(PyObject* self)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proxyFactory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkProxyFactory * cppResult = const_cast<const ::QNetworkAccessManager*>(cppSelf)->proxyFactory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYFACTORY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_put(PyObject* self, PyObject* args)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "put", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: put(QNetworkRequest,QIODevice*)
    // 1: put(QNetworkRequest,QByteArray)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 1; // put(QNetworkRequest,QByteArray)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            overloadId = 0; // put(QNetworkRequest,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_put_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // put(const QNetworkRequest & request, QIODevice * data)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QIODevice* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // put(QNetworkRequest,QIODevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QNetworkReply * cppResult = cppSelf->put(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // put(const QNetworkRequest & request, const QByteArray & data)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
            ::QNetworkRequest* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
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
                // put(QNetworkRequest,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QNetworkReply * cppResult = cppSelf->put(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_put_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QIODevice", "PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAccessManager.put", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_sendCustomRequest(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.sendCustomRequest(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.sendCustomRequest(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:sendCustomRequest", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: sendCustomRequest(QNetworkRequest,QByteArray,QIODevice*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // sendCustomRequest(QNetworkRequest,QByteArray,QIODevice*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2])))) {
            overloadId = 0; // sendCustomRequest(QNetworkRequest,QByteArray,QIODevice*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_sendCustomRequest_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "data");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkAccessManager.sendCustomRequest(): got multiple values for keyword argument 'data'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[2]))))
                    goto Sbk_QNetworkAccessManagerFunc_sendCustomRequest_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QNetworkRequest cppArg0_local = ::QNetworkRequest(::QUrl());
        ::QNetworkRequest* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREQUEST_IDX], pythonToCpp[0]))
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
            // sendCustomRequest(QNetworkRequest,QByteArray,QIODevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkReply * cppResult = cppSelf->sendCustomRequest(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKREPLY_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkAccessManagerFunc_sendCustomRequest_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkRequest, PySide.QtCore.QByteArray, PySide.QtCore.QIODevice = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkAccessManager.sendCustomRequest", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setCache(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCache(QAbstractNetworkCache*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QABSTRACTNETWORKCACHE_IDX], (pyArg)))) {
        overloadId = 0; // setCache(QAbstractNetworkCache*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setCache_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractNetworkCache* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCache(QAbstractNetworkCache*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCache(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAccessManagerFunc_setCache_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QAbstractNetworkCache", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setCache", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setConfiguration(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setConfiguration(QNetworkConfiguration)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], (pyArg)))) {
        overloadId = 0; // setConfiguration(QNetworkConfiguration)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setConfiguration_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkConfiguration cppArg0_local = ::QNetworkConfiguration();
        ::QNetworkConfiguration* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setConfiguration(QNetworkConfiguration)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setConfiguration(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAccessManagerFunc_setConfiguration_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkConfiguration", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setConfiguration", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setCookieJar(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCookieJar(QNetworkCookieJar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCOOKIEJAR_IDX], (pyArg)))) {
        overloadId = 0; // setCookieJar(QNetworkCookieJar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setCookieJar_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkCookieJar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCookieJar(QNetworkCookieJar*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCookieJar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Ownership transferences.
            Shiboken::Object::releaseOwnership(pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAccessManagerFunc_setCookieJar_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkCookieJar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setCookieJar", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setNetworkAccessible(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNetworkAccessible(QNetworkAccessManager::NetworkAccessibility)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX]), (pyArg)))) {
        overloadId = 0; // setNetworkAccessible(QNetworkAccessManager::NetworkAccessibility)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setNetworkAccessible_TypeError;

    // Call function/method
    {
        ::QNetworkAccessManager::NetworkAccessibility cppArg0 = ((::QNetworkAccessManager::NetworkAccessibility)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNetworkAccessible(QNetworkAccessManager::NetworkAccessibility)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNetworkAccessible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAccessManagerFunc_setNetworkAccessible_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkAccessManager.NetworkAccessibility", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setNetworkAccessible", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setProxy(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProxy(QNetworkProxy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXY_IDX], (pyArg)))) {
        overloadId = 0; // setProxy(QNetworkProxy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setProxy_TypeError;

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

    Sbk_QNetworkAccessManagerFunc_setProxy_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setProxy", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkAccessManagerFunc_setProxyFactory(PyObject* self, PyObject* pyArg)
{
    ::QNetworkAccessManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkAccessManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProxyFactory(QNetworkProxyFactory*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKPROXYFACTORY_IDX], (pyArg)))) {
        overloadId = 0; // setProxyFactory(QNetworkProxyFactory*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkAccessManagerFunc_setProxyFactory_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QNetworkProxyFactory* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProxyFactory(QNetworkProxyFactory*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProxyFactory(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QNetworkAccessManagerFunc_setProxyFactory_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkProxyFactory", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkAccessManager.setProxyFactory", overloads);
        return 0;
}

static PyMethodDef Sbk_QNetworkAccessManager_methods[] = {
    {"activeConfiguration", (PyCFunction)Sbk_QNetworkAccessManagerFunc_activeConfiguration, METH_NOARGS},
    {"cache", (PyCFunction)Sbk_QNetworkAccessManagerFunc_cache, METH_NOARGS},
    {"configuration", (PyCFunction)Sbk_QNetworkAccessManagerFunc_configuration, METH_NOARGS},
    {"cookieJar", (PyCFunction)Sbk_QNetworkAccessManagerFunc_cookieJar, METH_NOARGS},
    {"createRequest", (PyCFunction)Sbk_QNetworkAccessManagerFunc_createRequest, METH_VARARGS|METH_KEYWORDS},
    {"deleteResource", (PyCFunction)Sbk_QNetworkAccessManagerFunc_deleteResource, METH_O},
    {"get", (PyCFunction)Sbk_QNetworkAccessManagerFunc_get, METH_O},
    {"head", (PyCFunction)Sbk_QNetworkAccessManagerFunc_head, METH_O},
    {"networkAccessible", (PyCFunction)Sbk_QNetworkAccessManagerFunc_networkAccessible, METH_NOARGS},
    {"post", (PyCFunction)Sbk_QNetworkAccessManagerFunc_post, METH_VARARGS},
    {"proxy", (PyCFunction)Sbk_QNetworkAccessManagerFunc_proxy, METH_NOARGS},
    {"proxyFactory", (PyCFunction)Sbk_QNetworkAccessManagerFunc_proxyFactory, METH_NOARGS},
    {"put", (PyCFunction)Sbk_QNetworkAccessManagerFunc_put, METH_VARARGS},
    {"sendCustomRequest", (PyCFunction)Sbk_QNetworkAccessManagerFunc_sendCustomRequest, METH_VARARGS|METH_KEYWORDS},
    {"setCache", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setCache, METH_O},
    {"setConfiguration", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setConfiguration, METH_O},
    {"setCookieJar", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setCookieJar, METH_O},
    {"setNetworkAccessible", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setNetworkAccessible, METH_O},
    {"setProxy", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setProxy, METH_O},
    {"setProxyFactory", (PyCFunction)Sbk_QNetworkAccessManagerFunc_setProxyFactory, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QNetworkAccessManager_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkAccessManager_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkAccessManager_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkAccessManager",
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
    /*tp_traverse*/         Sbk_QNetworkAccessManager_traverse,
    /*tp_clear*/            Sbk_QNetworkAccessManager_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkAccessManager_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkAccessManager_Init,
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

static void* Sbk_QNetworkAccessManager_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QNetworkAccessManager*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QNetworkAccessManager_Operation_PythonToCpp_QNetworkAccessManager_Operation(PyObject* pyIn, void* cppOut) {
    *((::QNetworkAccessManager::Operation*)cppOut) = (::QNetworkAccessManager::Operation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkAccessManager_Operation_PythonToCpp_QNetworkAccessManager_Operation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX]))
        return QNetworkAccessManager_Operation_PythonToCpp_QNetworkAccessManager_Operation;
    return 0;
}
static PyObject* QNetworkAccessManager_Operation_CppToPython_QNetworkAccessManager_Operation(const void* cppIn) {
    int castCppIn = *((::QNetworkAccessManager::Operation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX], castCppIn);

}

static void QNetworkAccessManager_NetworkAccessibility_PythonToCpp_QNetworkAccessManager_NetworkAccessibility(PyObject* pyIn, void* cppOut) {
    *((::QNetworkAccessManager::NetworkAccessibility*)cppOut) = (::QNetworkAccessManager::NetworkAccessibility) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkAccessManager_NetworkAccessibility_PythonToCpp_QNetworkAccessManager_NetworkAccessibility_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX]))
        return QNetworkAccessManager_NetworkAccessibility_PythonToCpp_QNetworkAccessManager_NetworkAccessibility;
    return 0;
}
static PyObject* QNetworkAccessManager_NetworkAccessibility_CppToPython_QNetworkAccessManager_NetworkAccessibility(const void* cppIn) {
    int castCppIn = *((::QNetworkAccessManager::NetworkAccessibility*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkAccessManager_PythonToCpp_QNetworkAccessManager_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkAccessManager_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkAccessManager_PythonToCpp_QNetworkAccessManager_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkAccessManager_Type))
        return QNetworkAccessManager_PythonToCpp_QNetworkAccessManager_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkAccessManager_PTR_CppToPython_QNetworkAccessManager(const void* cppIn) {
    return PySide::getWrapperForQObject((::QNetworkAccessManager*)cppIn, &Sbk_QNetworkAccessManager_Type);

}

void init_QNetworkAccessManager(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkAccessManager_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkAccessManager", "QNetworkAccessManager*",
        &Sbk_QNetworkAccessManager_Type, &Shiboken::callCppDestructor< ::QNetworkAccessManager >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkAccessManager_Type,
        QNetworkAccessManager_PythonToCpp_QNetworkAccessManager_PTR,
        is_QNetworkAccessManager_PythonToCpp_QNetworkAccessManager_PTR_Convertible,
        QNetworkAccessManager_PTR_CppToPython_QNetworkAccessManager);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkAccessManager");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkAccessManager*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkAccessManager&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkAccessManager).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkAccessManagerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QNetworkAccessManager_Type, &Sbk_QNetworkAccessManager_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Operation'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkAccessManager_Type,
        "Operation",
        "PySide.QtNetwork.QNetworkAccessManager.Operation",
        "QNetworkAccessManager::Operation");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "HeadOperation", (long) QNetworkAccessManager::HeadOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "GetOperation", (long) QNetworkAccessManager::GetOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "PutOperation", (long) QNetworkAccessManager::PutOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "PostOperation", (long) QNetworkAccessManager::PostOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "DeleteOperation", (long) QNetworkAccessManager::DeleteOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "CustomOperation", (long) QNetworkAccessManager::CustomOperation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
        &Sbk_QNetworkAccessManager_Type, "UnknownOperation", (long) QNetworkAccessManager::UnknownOperation))
        return ;
    // Register converter for enum 'QNetworkAccessManager::Operation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX],
            QNetworkAccessManager_Operation_CppToPython_QNetworkAccessManager_Operation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkAccessManager_Operation_PythonToCpp_QNetworkAccessManager_Operation,
            is_QNetworkAccessManager_Operation_PythonToCpp_QNetworkAccessManager_Operation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_OPERATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkAccessManager::Operation");
        Shiboken::Conversions::registerConverterName(converter, "Operation");
    }
    // End of 'Operation' enum.

    // Initialization of enum 'NetworkAccessibility'.
    SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkAccessManager_Type,
        "NetworkAccessibility",
        "PySide.QtNetwork.QNetworkAccessManager.NetworkAccessibility",
        "QNetworkAccessManager::NetworkAccessibility");
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX],
        &Sbk_QNetworkAccessManager_Type, "UnknownAccessibility", (long) QNetworkAccessManager::UnknownAccessibility))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX],
        &Sbk_QNetworkAccessManager_Type, "NotAccessible", (long) QNetworkAccessManager::NotAccessible))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX],
        &Sbk_QNetworkAccessManager_Type, "Accessible", (long) QNetworkAccessManager::Accessible))
        return ;
    // Register converter for enum 'QNetworkAccessManager::NetworkAccessibility'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX],
            QNetworkAccessManager_NetworkAccessibility_CppToPython_QNetworkAccessManager_NetworkAccessibility);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkAccessManager_NetworkAccessibility_PythonToCpp_QNetworkAccessManager_NetworkAccessibility,
            is_QNetworkAccessManager_NetworkAccessibility_PythonToCpp_QNetworkAccessManager_NetworkAccessibility_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKACCESSMANAGER_NETWORKACCESSIBILITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkAccessManager::NetworkAccessibility");
        Shiboken::Conversions::registerConverterName(converter, "NetworkAccessibility");
    }
    // End of 'NetworkAccessibility' enum.

    PySide::Signal::registerSignals(&Sbk_QNetworkAccessManager_Type, &::QNetworkAccessManager::staticMetaObject);

    qRegisterMetaType< ::QNetworkAccessManager::Operation >("QNetworkAccessManager::Operation");
    qRegisterMetaType< ::QNetworkAccessManager::NetworkAccessibility >("QNetworkAccessManager::NetworkAccessibility");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QNetworkAccessManager_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QNetworkAccessManager_Type, &::QNetworkAccessManager::staticMetaObject, sizeof(::QNetworkAccessManager));
}
