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

#include "qnetworkconfigurationmanager_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qnetworkconfiguration.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QNetworkConfigurationManagerWrapper::QNetworkConfigurationManagerWrapper(QObject * parent) : QNetworkConfigurationManager(parent) {
    // ... middle
}

void QNetworkConfigurationManagerWrapper::childEvent(QChildEvent * arg__1)
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

void QNetworkConfigurationManagerWrapper::connectNotify(const char * signal)
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

void QNetworkConfigurationManagerWrapper::customEvent(QEvent * arg__1)
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

void QNetworkConfigurationManagerWrapper::disconnectNotify(const char * signal)
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

bool QNetworkConfigurationManagerWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkConfigurationManager.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QNetworkConfigurationManagerWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QNetworkConfigurationManager.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QNetworkConfigurationManagerWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QNetworkConfigurationManagerWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QNetworkConfigurationManager::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QNetworkConfigurationManagerWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QNetworkConfigurationManager::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QNetworkConfigurationManagerWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QNetworkConfigurationManagerWrapper* >(this));
        return QNetworkConfigurationManager::qt_metacast(_clname);
}

QNetworkConfigurationManagerWrapper::~QNetworkConfigurationManagerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QNetworkConfigurationManager_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QNetworkConfigurationManager >()))
        return -1;

    ::QNetworkConfigurationManagerWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QNetworkConfigurationManager", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QNetworkConfigurationManager(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QNetworkConfigurationManager(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QNetworkConfigurationManager(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkConfigurationManager_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkConfigurationManager(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QNetworkConfigurationManager_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QNetworkConfigurationManager(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QNetworkConfigurationManagerWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QNetworkConfigurationManagerWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QNetworkConfigurationManager >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QNetworkConfigurationManager_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QNetworkConfigurationManager_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkConfigurationManager", overloads);
        return -1;
}

static PyObject* Sbk_QNetworkConfigurationManagerFunc_allConfigurations(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkConfigurationManager.allConfigurations(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:allConfigurations", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: allConfigurations(QFlags<QNetworkConfiguration::StateFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // allConfigurations(QFlags<QNetworkConfiguration::StateFlag>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), (pyArgs[0])))) {
        overloadId = 0; // allConfigurations(QFlags<QNetworkConfiguration::StateFlag>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkConfigurationManagerFunc_allConfigurations_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QNetworkConfigurationManager.allConfigurations(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATION_STATEFLAG__IDX]), (pyArgs[0]))))
                    goto Sbk_QNetworkConfigurationManagerFunc_allConfigurations_TypeError;
            }
        }
        ::QFlags<QNetworkConfiguration::StateFlag> cppArg0 = QFlags<QNetworkConfiguration::StateFlag>(0);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // allConfigurations(QFlags<QNetworkConfiguration::StateFlag>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QNetworkConfiguration > cppResult = const_cast<const ::QNetworkConfigurationManager*>(cppSelf)->allConfigurations(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtNetworkTypeConverters[SBK_QTNETWORK_QLIST_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkConfigurationManagerFunc_allConfigurations_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QNetworkConfiguration.StateFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QNetworkConfigurationManager.allConfigurations", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkConfigurationManagerFunc_capabilities(PyObject* self)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capabilities()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QNetworkConfigurationManager::Capability> cppResult = const_cast<const ::QNetworkConfigurationManager*>(cppSelf)->capabilities();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QNetworkConfigurationManagerFunc_configurationFromIdentifier(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: configurationFromIdentifier(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // configurationFromIdentifier(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QNetworkConfigurationManagerFunc_configurationFromIdentifier_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // configurationFromIdentifier(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration cppResult = const_cast<const ::QNetworkConfigurationManager*>(cppSelf)->configurationFromIdentifier(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QNetworkConfigurationManagerFunc_configurationFromIdentifier_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QNetworkConfigurationManager.configurationFromIdentifier", overloads);
        return 0;
}

static PyObject* Sbk_QNetworkConfigurationManagerFunc_defaultConfiguration(PyObject* self)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultConfiguration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QNetworkConfiguration cppResult = const_cast<const ::QNetworkConfigurationManager*>(cppSelf)->defaultConfiguration();
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

static PyObject* Sbk_QNetworkConfigurationManagerFunc_isOnline(PyObject* self)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOnline()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QNetworkConfigurationManager*>(cppSelf)->isOnline();
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

static PyObject* Sbk_QNetworkConfigurationManagerFunc_updateConfigurations(PyObject* self)
{
    ::QNetworkConfigurationManager* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QNetworkConfigurationManager*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateConfigurations()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateConfigurations();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QNetworkConfigurationManager_methods[] = {
    {"allConfigurations", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_allConfigurations, METH_VARARGS|METH_KEYWORDS},
    {"capabilities", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_capabilities, METH_NOARGS},
    {"configurationFromIdentifier", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_configurationFromIdentifier, METH_O},
    {"defaultConfiguration", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_defaultConfiguration, METH_NOARGS},
    {"isOnline", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_isOnline, METH_NOARGS},
    {"updateConfigurations", (PyCFunction)Sbk_QNetworkConfigurationManagerFunc_updateConfigurations, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QNetworkConfigurationManager_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QNetworkConfigurationManager_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QNetworkConfigurationManager_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QNetworkConfigurationManager",
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
    /*tp_traverse*/         Sbk_QNetworkConfigurationManager_traverse,
    /*tp_clear*/            Sbk_QNetworkConfigurationManager_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QNetworkConfigurationManager_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QNetworkConfigurationManager_Init,
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

static void* Sbk_QNetworkConfigurationManager_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QNetworkConfigurationManager*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___and__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfigurationManager::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___or__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfigurationManager::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___xor__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfigurationManager::Capabilities cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyLong_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QNetworkConfigurationManager::Capabilities)PyInt_AsLong(self);
    cppArg = (QNetworkConfigurationManager::Capabilities)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), &cppResult);
}

PyObject* SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___invert__(PyObject* self, PyObject* pyArg)
{
    ::QNetworkConfigurationManager::Capabilities cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), self, &cppSelf);
    ::QNetworkConfigurationManager::Capabilities cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability_long,
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
static void QNetworkConfigurationManager_Capability_PythonToCpp_QNetworkConfigurationManager_Capability(PyObject* pyIn, void* cppOut) {
    *((::QNetworkConfigurationManager::Capability*)cppOut) = (::QNetworkConfigurationManager::Capability) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QNetworkConfigurationManager_Capability_PythonToCpp_QNetworkConfigurationManager_Capability_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX]))
        return QNetworkConfigurationManager_Capability_PythonToCpp_QNetworkConfigurationManager_Capability;
    return 0;
}
static PyObject* QNetworkConfigurationManager_Capability_CppToPython_QNetworkConfigurationManager_Capability(const void* cppIn) {
    int castCppIn = *((::QNetworkConfigurationManager::Capability*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX], castCppIn);

}

static void QFlags_QNetworkConfigurationManager_Capability__PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkConfigurationManager::Capability>*)cppOut) = ::QFlags<QNetworkConfigurationManager::Capability>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QNetworkConfigurationManager_Capability__PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]))
        return QFlags_QNetworkConfigurationManager_Capability__PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_;
    return 0;
}
static PyObject* QFlags_QNetworkConfigurationManager_Capability__CppToPython_QFlags_QNetworkConfigurationManager_Capability_(const void* cppIn) {
    int castCppIn = *((::QFlags<QNetworkConfigurationManager::Capability>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]));

}

static void QNetworkConfigurationManager_Capability_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QNetworkConfigurationManager::Capability>*)cppOut) = ::QFlags<QNetworkConfigurationManager::Capability>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QNetworkConfigurationManager_Capability_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX]))
        return QNetworkConfigurationManager_Capability_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_;
    return 0;
}
static void number_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QNetworkConfigurationManager::Capability>*)cppOut) = ::QFlags<QNetworkConfigurationManager::Capability>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QNetworkConfigurationManager_PythonToCpp_QNetworkConfigurationManager_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QNetworkConfigurationManager_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QNetworkConfigurationManager_PythonToCpp_QNetworkConfigurationManager_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QNetworkConfigurationManager_Type))
        return QNetworkConfigurationManager_PythonToCpp_QNetworkConfigurationManager_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QNetworkConfigurationManager_PTR_CppToPython_QNetworkConfigurationManager(const void* cppIn) {
    return PySide::getWrapperForQObject((::QNetworkConfigurationManager*)cppIn, &Sbk_QNetworkConfigurationManager_Type);

}

void init_QNetworkConfigurationManager(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QNetworkConfigurationManager_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QNetworkConfigurationManager", "QNetworkConfigurationManager*",
        &Sbk_QNetworkConfigurationManager_Type, &Shiboken::callCppDestructor< ::QNetworkConfigurationManager >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QNetworkConfigurationManager_Type,
        QNetworkConfigurationManager_PythonToCpp_QNetworkConfigurationManager_PTR,
        is_QNetworkConfigurationManager_PythonToCpp_QNetworkConfigurationManager_PTR_Convertible,
        QNetworkConfigurationManager_PTR_CppToPython_QNetworkConfigurationManager);

    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfigurationManager");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfigurationManager*");
    Shiboken::Conversions::registerConverterName(converter, "QNetworkConfigurationManager&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkConfigurationManager).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QNetworkConfigurationManagerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QNetworkConfigurationManager_Type, &Sbk_QNetworkConfigurationManager_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Capability'.
    SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX] = PySide::QFlags::create("Capabilities", &SbkPySide_QtNetwork_QNetworkConfigurationManager_Capability_as_number);
    SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QNetworkConfigurationManager_Type,
        "Capability",
        "PySide.QtNetwork.QNetworkConfigurationManager.Capability",
        "QNetworkConfigurationManager::Capability",
        SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX]);
    if (!SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "CanStartAndStopInterfaces", (long) QNetworkConfigurationManager::CanStartAndStopInterfaces))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "DirectConnectionRouting", (long) QNetworkConfigurationManager::DirectConnectionRouting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "SystemSessionSupport", (long) QNetworkConfigurationManager::SystemSessionSupport))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "ApplicationLevelRoaming", (long) QNetworkConfigurationManager::ApplicationLevelRoaming))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "ForcedRoaming", (long) QNetworkConfigurationManager::ForcedRoaming))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "DataStatistics", (long) QNetworkConfigurationManager::DataStatistics))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
        &Sbk_QNetworkConfigurationManager_Type, "NetworkSessionRequired", (long) QNetworkConfigurationManager::NetworkSessionRequired))
        return ;
    // Register converter for enum 'QNetworkConfigurationManager::Capability'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX],
            QNetworkConfigurationManager_Capability_CppToPython_QNetworkConfigurationManager_Capability);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfigurationManager_Capability_PythonToCpp_QNetworkConfigurationManager_Capability,
            is_QNetworkConfigurationManager_Capability_PythonToCpp_QNetworkConfigurationManager_Capability_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QNETWORKCONFIGURATIONMANAGER_CAPABILITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QNetworkConfigurationManager::Capability");
        Shiboken::Conversions::registerConverterName(converter, "Capability");
    }
    // Register converter for flag 'QFlags<QNetworkConfigurationManager::Capability>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX],
            QFlags_QNetworkConfigurationManager_Capability__CppToPython_QFlags_QNetworkConfigurationManager_Capability_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QNetworkConfigurationManager_Capability_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_,
            is_QNetworkConfigurationManager_Capability_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QNetworkConfigurationManager_Capability__PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_,
            is_QFlags_QNetworkConfigurationManager_Capability__PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability_,
            is_number_PythonToCpp_QFlags_QNetworkConfigurationManager_Capability__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFLAGS_QNETWORKCONFIGURATIONMANAGER_CAPABILITY__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QNetworkConfigurationManager::Capability>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Capability>");
    }
    // End of 'Capability' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QNetworkConfigurationManager_Type, &::QNetworkConfigurationManager::staticMetaObject);

    qRegisterMetaType< ::QNetworkConfigurationManager::Capability >("QNetworkConfigurationManager::Capability");
    qRegisterMetaType< ::QNetworkConfigurationManager::Capabilities >("QNetworkConfigurationManager::Capabilities");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QNetworkConfigurationManager_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QNetworkConfigurationManager_Type, &::QNetworkConfigurationManager::staticMetaObject, sizeof(::QNetworkConfigurationManager));
}
