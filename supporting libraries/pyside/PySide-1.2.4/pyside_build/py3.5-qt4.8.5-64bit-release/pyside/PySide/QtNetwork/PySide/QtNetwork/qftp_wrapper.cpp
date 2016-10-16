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

#include "qftp_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qftp.h>
#include <qiodevice.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qurlinfo.h>


// Native ---------------------------------------------------------

QFtpWrapper::QFtpWrapper(QObject * parent) : QFtp(parent) {
    // ... middle
}

void QFtpWrapper::childEvent(QChildEvent * arg__1)
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

void QFtpWrapper::connectNotify(const char * signal)
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

void QFtpWrapper::customEvent(QEvent * arg__1)
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

void QFtpWrapper::disconnectNotify(const char * signal)
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

bool QFtpWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFtp.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QFtpWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFtp.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QFtpWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QFtpWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QFtp::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QFtpWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QFtp::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QFtpWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QFtpWrapper* >(this));
        return QFtp::qt_metacast(_clname);
}

QFtpWrapper::~QFtpWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFtp_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFtp >()))
        return -1;

    ::QFtpWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QFtp", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFtp(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QFtp(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QFtp(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtp_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QFtp_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QFtp(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QFtpWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QFtpWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFtp >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFtp_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QFtp_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp", overloads);
        return -1;
}

static PyObject* Sbk_QFtpFunc_abort(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QFtpFunc_bytesAvailable(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bytesAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QFtp*>(cppSelf)->bytesAvailable();
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

static PyObject* Sbk_QFtpFunc_cd(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cd(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // cd(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_cd_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cd(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->cd(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_cd_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.cd", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_clearPendingCommands(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearPendingCommands()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearPendingCommands();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFtpFunc_close(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QFtpFunc_connectToHost(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.connectToHost(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.connectToHost(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:connectToHost", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: connectToHost(QString,quint16)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // connectToHost(QString,quint16)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
            overloadId = 0; // connectToHost(QString,quint16)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_connectToHost_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "port");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.connectToHost(): got multiple values for keyword argument 'port'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1]))))
                    goto Sbk_QFtpFunc_connectToHost_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        quint16 cppArg1 = 21;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // connectToHost(QString,quint16)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->connectToHost(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_connectToHost_TypeError:
        const char* overloads[] = {"unicode, unsigned short = 21", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.connectToHost", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_currentCommand(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentCommand()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFtp::Command cppResult = const_cast<const ::QFtp*>(cppSelf)->currentCommand();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFtpFunc_currentDevice(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIODevice * cppResult = const_cast<const ::QFtp*>(cppSelf)->currentDevice();
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

static PyObject* Sbk_QFtpFunc_currentId(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFtp*>(cppSelf)->currentId();
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

static PyObject* Sbk_QFtpFunc_error(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // error()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFtp::Error cppResult = const_cast<const ::QFtp*>(cppSelf)->error();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFtpFunc_errorString(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFtp*>(cppSelf)->errorString();
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

static PyObject* Sbk_QFtpFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.get(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.get(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:get", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: get(QString,QIODevice*,QFtp::TransferType)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // get(QString,QIODevice*,QFtp::TransferType)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // get(QString,QIODevice*,QFtp::TransferType)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // get(QString,QIODevice*,QFtp::TransferType)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_get_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dev");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.get(): got multiple values for keyword argument 'dev'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[1]))))
                    goto Sbk_QFtpFunc_get_TypeError;
            }
            value = PyDict_GetItemString(kwds, "type");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.get(): got multiple values for keyword argument 'type'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2]))))
                    goto Sbk_QFtpFunc_get_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QIODevice* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFtp::TransferType cppArg2 = QFtp::Binary;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // get(QString,QIODevice*,QFtp::TransferType)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->get(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_get_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QIODevice = None, PySide.QtNetwork.QFtp.TransferType = Binary", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.get", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_hasPendingCommands(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasPendingCommands()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFtp*>(cppSelf)->hasPendingCommands();
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

static PyObject* Sbk_QFtpFunc_list(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.list(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:list", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: list(QString)
    if (numArgs == 0) {
        overloadId = 0; // list(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // list(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_list_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dir");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.list(): got multiple values for keyword argument 'dir'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QFtpFunc_list_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // list(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->list(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_list_TypeError:
        const char* overloads[] = {"unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.list", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_login(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.login(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:login", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: login(QString,QString)
    if (numArgs == 0) {
        overloadId = 0; // login(QString,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // login(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // login(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_login_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "user");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.login(): got multiple values for keyword argument 'user'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_QFtpFunc_login_TypeError;
            }
            value = PyDict_GetItemString(kwds, "password");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.login(): got multiple values for keyword argument 'password'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFtpFunc_login_TypeError;
            }
        }
        ::QString cppArg0 = QString();
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // login(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->login(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_login_TypeError:
        const char* overloads[] = {"unicode = QString(), unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.login", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_mkdir(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mkdir(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mkdir(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_mkdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mkdir(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->mkdir(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_mkdir_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.mkdir", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_put(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.put(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.put(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:put", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: put(QIODevice*,QString,QFtp::TransferType)
    // 1: put(QByteArray,QString,QFtp::TransferType)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // put(QByteArray,QString,QFtp::TransferType)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2])))) {
            overloadId = 1; // put(QByteArray,QString,QFtp::TransferType)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // put(QIODevice*,QString,QFtp::TransferType)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2])))) {
            overloadId = 0; // put(QIODevice*,QString,QFtp::TransferType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_put_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // put(QIODevice * dev, const QString & file, QFtp::TransferType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.put(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QFtpFunc_put_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFtp::TransferType cppArg2 = QFtp::Binary;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // put(QIODevice*,QString,QFtp::TransferType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->put(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // put(const QByteArray & data, const QString & file, QFtp::TransferType type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtNetwork.QFtp.put(): got multiple values for keyword argument 'type'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QFtpFunc_put_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFtp::TransferType cppArg2 = QFtp::Binary;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // put(QByteArray,QString,QFtp::TransferType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = cppSelf->put(*cppArg0, cppArg1, cppArg2);
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

    Sbk_QFtpFunc_put_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, unicode, PySide.QtNetwork.QFtp.TransferType = Binary", "PySide.QtCore.QByteArray, unicode, PySide.QtNetwork.QFtp.TransferType = Binary", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.put", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_rawCommand(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rawCommand(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // rawCommand(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_rawCommand_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rawCommand(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->rawCommand(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_rawCommand_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.rawCommand", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFtpFunc_read_TypeError;

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

    Sbk_QFtpFunc_read_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.read", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_readAll(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QFtpFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // remove(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_remove_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // remove(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->remove(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_remove_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.remove", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_rename(PyObject* self, PyObject* args)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rename", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: rename(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // rename(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_rename_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // rename(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->rename(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_rename_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.rename", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_rmdir(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rmdir(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // rmdir(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_rmdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rmdir(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->rmdir(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_rmdir_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.rmdir", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_setProxy(PyObject* self, PyObject* args)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProxy", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProxy(QString,quint16)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), (pyArgs[1])))) {
        overloadId = 0; // setProxy(QString,quint16)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_setProxy_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        quint16 cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProxy(QString,quint16)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->setProxy(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_setProxy_TypeError:
        const char* overloads[] = {"unicode, unsigned short", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtNetwork.QFtp.setProxy", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_setTransferMode(PyObject* self, PyObject* pyArg)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransferMode(QFtp::TransferMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setTransferMode(QFtp::TransferMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFtpFunc_setTransferMode_TypeError;

    // Call function/method
    {
        ::QFtp::TransferMode cppArg0 = ((::QFtp::TransferMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTransferMode(QFtp::TransferMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->setTransferMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFtpFunc_setTransferMode_TypeError:
        const char* overloads[] = {"PySide.QtNetwork.QFtp.TransferMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtNetwork.QFtp.setTransferMode", overloads);
        return 0;
}

static PyObject* Sbk_QFtpFunc_state(PyObject* self)
{
    ::QFtp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFtp*)Shiboken::Conversions::cppPointer(SbkPySide_QtNetworkTypes[SBK_QFTP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFtp::State cppResult = const_cast<const ::QFtp*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFtp_methods[] = {
    {"abort", (PyCFunction)Sbk_QFtpFunc_abort, METH_NOARGS},
    {"bytesAvailable", (PyCFunction)Sbk_QFtpFunc_bytesAvailable, METH_NOARGS},
    {"cd", (PyCFunction)Sbk_QFtpFunc_cd, METH_O},
    {"clearPendingCommands", (PyCFunction)Sbk_QFtpFunc_clearPendingCommands, METH_NOARGS},
    {"close", (PyCFunction)Sbk_QFtpFunc_close, METH_NOARGS},
    {"connectToHost", (PyCFunction)Sbk_QFtpFunc_connectToHost, METH_VARARGS|METH_KEYWORDS},
    {"currentCommand", (PyCFunction)Sbk_QFtpFunc_currentCommand, METH_NOARGS},
    {"currentDevice", (PyCFunction)Sbk_QFtpFunc_currentDevice, METH_NOARGS},
    {"currentId", (PyCFunction)Sbk_QFtpFunc_currentId, METH_NOARGS},
    {"error", (PyCFunction)Sbk_QFtpFunc_error, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QFtpFunc_errorString, METH_NOARGS},
    {"get", (PyCFunction)Sbk_QFtpFunc_get, METH_VARARGS|METH_KEYWORDS},
    {"hasPendingCommands", (PyCFunction)Sbk_QFtpFunc_hasPendingCommands, METH_NOARGS},
    {"list", (PyCFunction)Sbk_QFtpFunc_list, METH_VARARGS|METH_KEYWORDS},
    {"login", (PyCFunction)Sbk_QFtpFunc_login, METH_VARARGS|METH_KEYWORDS},
    {"mkdir", (PyCFunction)Sbk_QFtpFunc_mkdir, METH_O},
    {"put", (PyCFunction)Sbk_QFtpFunc_put, METH_VARARGS|METH_KEYWORDS},
    {"rawCommand", (PyCFunction)Sbk_QFtpFunc_rawCommand, METH_O},
    {"read", (PyCFunction)Sbk_QFtpFunc_read, METH_O},
    {"readAll", (PyCFunction)Sbk_QFtpFunc_readAll, METH_NOARGS},
    {"remove", (PyCFunction)Sbk_QFtpFunc_remove, METH_O},
    {"rename", (PyCFunction)Sbk_QFtpFunc_rename, METH_VARARGS},
    {"rmdir", (PyCFunction)Sbk_QFtpFunc_rmdir, METH_O},
    {"setProxy", (PyCFunction)Sbk_QFtpFunc_setProxy, METH_VARARGS},
    {"setTransferMode", (PyCFunction)Sbk_QFtpFunc_setTransferMode, METH_O},
    {"state", (PyCFunction)Sbk_QFtpFunc_state, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFtp_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFtp_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFtp_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtNetwork.QFtp",
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
    /*tp_traverse*/         Sbk_QFtp_traverse,
    /*tp_clear*/            Sbk_QFtp_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFtp_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFtp_Init,
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

static void* Sbk_QFtp_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QFtp*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QFtp_State_PythonToCpp_QFtp_State(PyObject* pyIn, void* cppOut) {
    *((::QFtp::State*)cppOut) = (::QFtp::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFtp_State_PythonToCpp_QFtp_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX]))
        return QFtp_State_PythonToCpp_QFtp_State;
    return 0;
}
static PyObject* QFtp_State_CppToPython_QFtp_State(const void* cppIn) {
    int castCppIn = *((::QFtp::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX], castCppIn);

}

static void QFtp_Error_PythonToCpp_QFtp_Error(PyObject* pyIn, void* cppOut) {
    *((::QFtp::Error*)cppOut) = (::QFtp::Error) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFtp_Error_PythonToCpp_QFtp_Error_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX]))
        return QFtp_Error_PythonToCpp_QFtp_Error;
    return 0;
}
static PyObject* QFtp_Error_CppToPython_QFtp_Error(const void* cppIn) {
    int castCppIn = *((::QFtp::Error*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX], castCppIn);

}

static void QFtp_Command_PythonToCpp_QFtp_Command(PyObject* pyIn, void* cppOut) {
    *((::QFtp::Command*)cppOut) = (::QFtp::Command) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFtp_Command_PythonToCpp_QFtp_Command_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX]))
        return QFtp_Command_PythonToCpp_QFtp_Command;
    return 0;
}
static PyObject* QFtp_Command_CppToPython_QFtp_Command(const void* cppIn) {
    int castCppIn = *((::QFtp::Command*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX], castCppIn);

}

static void QFtp_TransferMode_PythonToCpp_QFtp_TransferMode(PyObject* pyIn, void* cppOut) {
    *((::QFtp::TransferMode*)cppOut) = (::QFtp::TransferMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFtp_TransferMode_PythonToCpp_QFtp_TransferMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX]))
        return QFtp_TransferMode_PythonToCpp_QFtp_TransferMode;
    return 0;
}
static PyObject* QFtp_TransferMode_CppToPython_QFtp_TransferMode(const void* cppIn) {
    int castCppIn = *((::QFtp::TransferMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX], castCppIn);

}

static void QFtp_TransferType_PythonToCpp_QFtp_TransferType(PyObject* pyIn, void* cppOut) {
    *((::QFtp::TransferType*)cppOut) = (::QFtp::TransferType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFtp_TransferType_PythonToCpp_QFtp_TransferType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX]))
        return QFtp_TransferType_PythonToCpp_QFtp_TransferType;
    return 0;
}
static PyObject* QFtp_TransferType_CppToPython_QFtp_TransferType(const void* cppIn) {
    int castCppIn = *((::QFtp::TransferType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFtp_PythonToCpp_QFtp_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFtp_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFtp_PythonToCpp_QFtp_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFtp_Type))
        return QFtp_PythonToCpp_QFtp_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFtp_PTR_CppToPython_QFtp(const void* cppIn) {
    return PySide::getWrapperForQObject((::QFtp*)cppIn, &Sbk_QFtp_Type);

}

void init_QFtp(PyObject* module)
{
    SbkPySide_QtNetworkTypes[SBK_QFTP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFtp_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFtp", "QFtp*",
        &Sbk_QFtp_Type, &Shiboken::callCppDestructor< ::QFtp >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFtp_Type,
        QFtp_PythonToCpp_QFtp_PTR,
        is_QFtp_PythonToCpp_QFtp_PTR_Convertible,
        QFtp_PTR_CppToPython_QFtp);

    Shiboken::Conversions::registerConverterName(converter, "QFtp");
    Shiboken::Conversions::registerConverterName(converter, "QFtp*");
    Shiboken::Conversions::registerConverterName(converter, "QFtp&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFtp).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFtpWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFtp_Type, &Sbk_QFtp_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'State'.
    SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFtp_Type,
        "State",
        "PySide.QtNetwork.QFtp.State",
        "QFtp::State");
    if (!SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "Unconnected", (long) QFtp::Unconnected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "HostLookup", (long) QFtp::HostLookup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "Connecting", (long) QFtp::Connecting))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "Connected", (long) QFtp::Connected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "LoggedIn", (long) QFtp::LoggedIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
        &Sbk_QFtp_Type, "Closing", (long) QFtp::Closing))
        return ;
    // Register converter for enum 'QFtp::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX],
            QFtp_State_CppToPython_QFtp_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFtp_State_PythonToCpp_QFtp_State,
            is_QFtp_State_PythonToCpp_QFtp_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFtp::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'Error'.
    SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFtp_Type,
        "Error",
        "PySide.QtNetwork.QFtp.Error",
        "QFtp::Error");
    if (!SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
        &Sbk_QFtp_Type, "NoError", (long) QFtp::NoError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
        &Sbk_QFtp_Type, "UnknownError", (long) QFtp::UnknownError))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
        &Sbk_QFtp_Type, "HostNotFound", (long) QFtp::HostNotFound))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
        &Sbk_QFtp_Type, "ConnectionRefused", (long) QFtp::ConnectionRefused))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
        &Sbk_QFtp_Type, "NotConnected", (long) QFtp::NotConnected))
        return ;
    // Register converter for enum 'QFtp::Error'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX],
            QFtp_Error_CppToPython_QFtp_Error);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFtp_Error_PythonToCpp_QFtp_Error,
            is_QFtp_Error_PythonToCpp_QFtp_Error_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_ERROR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFtp::Error");
        Shiboken::Conversions::registerConverterName(converter, "Error");
    }
    // End of 'Error' enum.

    // Initialization of enum 'Command'.
    SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFtp_Type,
        "Command",
        "PySide.QtNetwork.QFtp.Command",
        "QFtp::Command");
    if (!SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "None", (long) QFtp::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "SetTransferMode", (long) QFtp::SetTransferMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "SetProxy", (long) QFtp::SetProxy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "ConnectToHost", (long) QFtp::ConnectToHost))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Login", (long) QFtp::Login))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Close", (long) QFtp::Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "List", (long) QFtp::List))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Cd", (long) QFtp::Cd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Get", (long) QFtp::Get))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Put", (long) QFtp::Put))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Remove", (long) QFtp::Remove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Mkdir", (long) QFtp::Mkdir))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Rmdir", (long) QFtp::Rmdir))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "Rename", (long) QFtp::Rename))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
        &Sbk_QFtp_Type, "RawCommand", (long) QFtp::RawCommand))
        return ;
    // Register converter for enum 'QFtp::Command'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX],
            QFtp_Command_CppToPython_QFtp_Command);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFtp_Command_PythonToCpp_QFtp_Command,
            is_QFtp_Command_PythonToCpp_QFtp_Command_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_COMMAND_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFtp::Command");
        Shiboken::Conversions::registerConverterName(converter, "Command");
    }
    // End of 'Command' enum.

    // Initialization of enum 'TransferMode'.
    SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFtp_Type,
        "TransferMode",
        "PySide.QtNetwork.QFtp.TransferMode",
        "QFtp::TransferMode");
    if (!SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX],
        &Sbk_QFtp_Type, "Active", (long) QFtp::Active))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX],
        &Sbk_QFtp_Type, "Passive", (long) QFtp::Passive))
        return ;
    // Register converter for enum 'QFtp::TransferMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX],
            QFtp_TransferMode_CppToPython_QFtp_TransferMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFtp_TransferMode_PythonToCpp_QFtp_TransferMode,
            is_QFtp_TransferMode_PythonToCpp_QFtp_TransferMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFtp::TransferMode");
        Shiboken::Conversions::registerConverterName(converter, "TransferMode");
    }
    // End of 'TransferMode' enum.

    // Initialization of enum 'TransferType'.
    SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFtp_Type,
        "TransferType",
        "PySide.QtNetwork.QFtp.TransferType",
        "QFtp::TransferType");
    if (!SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX],
        &Sbk_QFtp_Type, "Binary", (long) QFtp::Binary))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX],
        &Sbk_QFtp_Type, "Ascii", (long) QFtp::Ascii))
        return ;
    // Register converter for enum 'QFtp::TransferType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX],
            QFtp_TransferType_CppToPython_QFtp_TransferType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFtp_TransferType_PythonToCpp_QFtp_TransferType,
            is_QFtp_TransferType_PythonToCpp_QFtp_TransferType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtNetworkTypes[SBK_QFTP_TRANSFERTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFtp::TransferType");
        Shiboken::Conversions::registerConverterName(converter, "TransferType");
    }
    // End of 'TransferType' enum.

    PySide::Signal::registerSignals(&Sbk_QFtp_Type, &::QFtp::staticMetaObject);

    qRegisterMetaType< ::QFtp::State >("QFtp::State");
    qRegisterMetaType< ::QFtp::Error >("QFtp::Error");
    qRegisterMetaType< ::QFtp::Command >("QFtp::Command");
    qRegisterMetaType< ::QFtp::TransferMode >("QFtp::TransferMode");
    qRegisterMetaType< ::QFtp::TransferType >("QFtp::TransferType");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QFtp_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QFtp_Type, &::QFtp::staticMetaObject, sizeof(::QFtp));
}
