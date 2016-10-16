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

#include "qcoreapplication_wrapper.h"

// Extra includes
#include <QList>
#include <QStringList>
#include <QTranslator>
#include <qbytearray.h>
#include <qcoreapplication.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qtranslator.h>


// Begin code injection
// ========================================================================
// START of custom code block [file: glue/qcoreapplication_init.cpp]
// Global variables used to store argc and argv values
static int QCoreApplicationArgCount;
static char** QCoreApplicationArgValues;

void QCoreApplication_constructor(PyObject* self, PyObject* args, QCoreApplicationWrapper** cptr)
{
    if (QCoreApplication::instance()) {
        PyErr_SetString(PyExc_RuntimeError, "A QCoreApplication instance already exists.");
        return;
    }

    int numArgs = PyTuple_GET_SIZE(args);
    if (numArgs != 1
        || !Shiboken::sequenceToArgcArgv(PyTuple_GET_ITEM(args, 0), &QCoreApplicationArgCount, &QCoreApplicationArgValues, "PySideApp")) {
        PyErr_BadArgument();
        return;
    }

    *cptr = new QCoreApplicationWrapper(QCoreApplicationArgCount, QCoreApplicationArgValues);

    Shiboken::Object::releaseOwnership(reinterpret_cast<SbkObject*>(self));
    PySide::registerCleanupFunction(&PySide::destroyQCoreApplication);
    Py_INCREF(self);
}

// END of custom code block [file: glue/qcoreapplication_init.cpp]
// ========================================================================

// End of code injection

// Native ---------------------------------------------------------

QCoreApplicationWrapper::QCoreApplicationWrapper(int & argc, char ** argv) : QCoreApplication(argc, argv) {
    // ... middle
}

void QCoreApplicationWrapper::childEvent(QChildEvent * arg__1)
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

void QCoreApplicationWrapper::connectNotify(const char * signal)
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

void QCoreApplicationWrapper::customEvent(QEvent * arg__1)
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

void QCoreApplicationWrapper::disconnectNotify(const char * signal)
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

bool QCoreApplicationWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCoreApplication::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCoreApplication.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QCoreApplicationWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCoreApplication.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

bool QCoreApplicationWrapper::notify(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "notify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCoreApplication::notify(arg__1, arg__2);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCoreApplication.notify", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QCoreApplicationWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QCoreApplicationWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QCoreApplication::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QCoreApplicationWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QCoreApplication::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QCoreApplicationWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QCoreApplicationWrapper* >(this));
        return QCoreApplication::qt_metacast(_clname);
}

QCoreApplicationWrapper::~QCoreApplicationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QCoreApplication_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QCoreApplication >()))
        return -1;

    ::QCoreApplicationWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QCoreApplication", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QCoreApplication(PySequence)
    if (numArgs == 1
        && PySequence_Check(pyArgs[0])) {
        overloadId = 0; // QCoreApplication(PySequence)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplication_Init_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QCoreApplication(PySequence)
            // Begin code injection

            QCoreApplication_constructor(self, args, &cptr);

            // End of code injection

        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QCoreApplication >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QCoreApplication_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QCoreApplication_Init_TypeError:
        const char* overloads[] = {"PySequence", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication", overloads);
        return -1;
}

static PyObject* Sbk_QCoreApplicationFunc_addLibraryPath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addLibraryPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addLibraryPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_addLibraryPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addLibraryPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::addLibraryPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_addLibraryPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.addLibraryPath", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_applicationDirPath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationDirPath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::applicationDirPath();
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

static PyObject* Sbk_QCoreApplicationFunc_applicationFilePath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationFilePath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::applicationFilePath();
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

static PyObject* Sbk_QCoreApplicationFunc_applicationName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::applicationName();
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

static PyObject* Sbk_QCoreApplicationFunc_applicationPid(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationPid()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = ::QCoreApplication::applicationPid();
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

static PyObject* Sbk_QCoreApplicationFunc_applicationVersion(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationVersion()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::applicationVersion();
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

static PyObject* Sbk_QCoreApplicationFunc_arguments(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // arguments()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QCoreApplication::arguments();
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

static PyObject* Sbk_QCoreApplicationFunc_closingDown(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closingDown()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QCoreApplication::closingDown();
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

static PyObject* Sbk_QCoreApplicationFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCoreApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCoreApplication::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCoreApplicationFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.event", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_exec_(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QCoreApplication::exec();
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

static PyObject* Sbk_QCoreApplicationFunc_exit(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.exit(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:exit", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exit(int)
    if (numArgs == 0) {
        overloadId = 0; // exit(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // exit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_exit_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "retcode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.exit(): got multiple values for keyword argument 'retcode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QCoreApplicationFunc_exit_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // exit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::exit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_exit_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.exit", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_flush(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flush()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::flush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QCoreApplicationFunc_hasPendingEvents(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasPendingEvents()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QCoreApplication::hasPendingEvents();
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

static PyObject* Sbk_QCoreApplicationFunc_installTranslator(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: installTranslator(QTranslator*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTRANSLATOR_IDX], (pyArg)))) {
        overloadId = 0; // installTranslator(QTranslator*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_installTranslator_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTranslator* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // installTranslator(QTranslator*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::installTranslator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_installTranslator_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTranslator", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.installTranslator", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_instance(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // instance()
            // Begin code injection

            QCoreApplication* app = QCoreApplication::instance();
            PyObject* pyApp = Py_None;
            if (app) {
                pyApp = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(app));
                if (!pyApp)
                    pyApp = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_IDX], app); // this will keep app live after python exit (extra ref)
            }
            pyResult = pyApp;
            Py_XINCREF(pyResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCoreApplicationFunc_libraryPaths(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // libraryPaths()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QCoreApplication::libraryPaths();
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

static PyObject* Sbk_QCoreApplicationFunc_notify(PyObject* self, PyObject* args)
{
    ::QCoreApplication* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCoreApplication*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "notify", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: notify(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // notify(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_notify_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // notify(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCoreApplication::notify(cppArg0, cppArg1) : cppSelf->notify(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCoreApplicationFunc_notify_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.notify", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_organizationDomain(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // organizationDomain()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::organizationDomain();
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

static PyObject* Sbk_QCoreApplicationFunc_organizationName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // organizationName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QCoreApplication::organizationName();
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

static PyObject* Sbk_QCoreApplicationFunc_postEvent(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "postEvent", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: postEvent(QObject*,QEvent*)
    // 1: postEvent(QObject*,QEvent*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // postEvent(QObject*,QEvent*)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 1; // postEvent(QObject*,QEvent*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_postEvent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // postEvent(QObject * receiver, QEvent * event)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QEvent* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // postEvent(QObject*,QEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::postEvent(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // Ownership transferences.
                Shiboken::Object::releaseOwnership(pyArgs[1]);
            }
            break;
        }
        case 1: // postEvent(QObject * receiver, QEvent * event, int priority)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QEvent* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // postEvent(QObject*,QEvent*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::postEvent(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // Ownership transferences.
                Shiboken::Object::releaseOwnership(pyArgs[1]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_postEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", "PySide.QtCore.QObject, PySide.QtCore.QEvent, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.postEvent", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_processEvents(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.processEvents(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:processEvents", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    // 1: processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
    if (numArgs == 0) {
        overloadId = 0; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_processEvents_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.processEvents(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QEVENTLOOP_PROCESSEVENTSFLAG__IDX]), (pyArgs[0]))))
                        goto Sbk_QCoreApplicationFunc_processEvents_TypeError;
                }
            }
            ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = QEventLoop::AllEvents;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // processEvents(QFlags<QEventLoop::ProcessEventsFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::processEvents(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // processEvents(QFlags<QEventLoop::ProcessEventsFlag> flags, int maxtime)
        {
            ::QFlags<QEventLoop::ProcessEventsFlag> cppArg0 = ((::QFlags<QEventLoop::ProcessEventsFlag>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // processEvents(QFlags<QEventLoop::ProcessEventsFlag>,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::processEvents(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_processEvents_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEventLoop.ProcessEventsFlags = QEventLoop.AllEvents", "PySide.QtCore.QEventLoop.ProcessEventsFlags, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.processEvents", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_quit(PyObject* self)
{

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // quit()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::quit();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QCoreApplicationFunc_removeLibraryPath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeLibraryPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // removeLibraryPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_removeLibraryPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeLibraryPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::removeLibraryPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_removeLibraryPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.removeLibraryPath", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_removePostedEvents(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removePostedEvents", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removePostedEvents(QObject*)
    // 1: removePostedEvents(QObject*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // removePostedEvents(QObject*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // removePostedEvents(QObject*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_removePostedEvents_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // removePostedEvents(QObject * receiver)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // removePostedEvents(QObject*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::removePostedEvents(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // removePostedEvents(QObject * receiver, int eventType)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // removePostedEvents(QObject*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::removePostedEvents(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_removePostedEvents_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", "PySide.QtCore.QObject, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.removePostedEvents", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_removeTranslator(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeTranslator(QTranslator*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTRANSLATOR_IDX], (pyArg)))) {
        overloadId = 0; // removeTranslator(QTranslator*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_removeTranslator_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTranslator* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeTranslator(QTranslator*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::removeTranslator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_removeTranslator_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTranslator", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.removeTranslator", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_sendEvent(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sendEvent", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sendEvent(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // sendEvent(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_sendEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sendEvent(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QCoreApplication::sendEvent(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCoreApplicationFunc_sendEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.sendEvent", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_sendPostedEvents(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QCoreApplicationFunc_sendPostedEvents_TypeError;

    if (!PyArg_UnpackTuple(args, "sendPostedEvents", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sendPostedEvents()
    // 1: sendPostedEvents(QObject*,int)
    if (numArgs == 0) {
        overloadId = 0; // sendPostedEvents()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // sendPostedEvents(QObject*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_sendPostedEvents_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // sendPostedEvents()
        {

            if (!PyErr_Occurred()) {
                // sendPostedEvents()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::sendPostedEvents();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // sendPostedEvents(QObject * receiver, int event_type)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // sendPostedEvents(QObject*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                ::QCoreApplication::sendPostedEvents(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_sendPostedEvents_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.sendPostedEvents", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setApplicationName(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setApplicationName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setApplicationName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setApplicationName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setApplicationName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setApplicationName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setApplicationName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.setApplicationName", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setApplicationVersion(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setApplicationVersion(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setApplicationVersion(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setApplicationVersion_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setApplicationVersion(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setApplicationVersion(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setApplicationVersion_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.setApplicationVersion", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setAttribute(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.setAttribute(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.setAttribute(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setAttribute", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAttribute(Qt::ApplicationAttribute,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setAttribute(Qt::ApplicationAttribute,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setAttribute(Qt::ApplicationAttribute,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setAttribute_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "on");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.setAttribute(): got multiple values for keyword argument 'on'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QCoreApplicationFunc_setAttribute_TypeError;
            }
        }
        ::Qt::ApplicationAttribute cppArg0 = ((::Qt::ApplicationAttribute)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAttribute(Qt::ApplicationAttribute,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setAttribute(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setAttribute_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ApplicationAttribute, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.setAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setLibraryPaths(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLibraryPaths(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setLibraryPaths(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setLibraryPaths_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLibraryPaths(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setLibraryPaths(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setLibraryPaths_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.setLibraryPaths", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setOrganizationDomain(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOrganizationDomain(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOrganizationDomain(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setOrganizationDomain_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOrganizationDomain(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setOrganizationDomain(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setOrganizationDomain_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.setOrganizationDomain", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_setOrganizationName(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOrganizationName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOrganizationName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_setOrganizationName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOrganizationName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QCoreApplication::setOrganizationName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCoreApplicationFunc_setOrganizationName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.setOrganizationName", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_startingUp(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startingUp()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QCoreApplication::startingUp();
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

static PyObject* Sbk_QCoreApplicationFunc_testAttribute(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testAttribute(Qt::ApplicationAttribute)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_APPLICATIONATTRIBUTE_IDX]), (pyArg)))) {
        overloadId = 0; // testAttribute(Qt::ApplicationAttribute)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_testAttribute_TypeError;

    // Call function/method
    {
        ::Qt::ApplicationAttribute cppArg0 = ((::Qt::ApplicationAttribute)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testAttribute(Qt::ApplicationAttribute)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QCoreApplication::testAttribute(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCoreApplicationFunc_testAttribute_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ApplicationAttribute", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QCoreApplication.testAttribute", overloads);
        return 0;
}

static PyObject* Sbk_QCoreApplicationFunc_translate(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.translate(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.translate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:translate", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: translate(const char*,const char*,const char*,QCoreApplication::Encoding)
    // 1: translate(const char*,const char*,const char*,QCoreApplication::Encoding,int)
    if (numArgs >= 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // translate(const char*,const char*,const char*,QCoreApplication::Encoding)
        } else if (Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // translate(const char*,const char*,const char*,QCoreApplication::Encoding)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // translate(const char*,const char*,const char*,QCoreApplication::Encoding)
                } else if (numArgs == 5
                    && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    overloadId = 1; // translate(const char*,const char*,const char*,QCoreApplication::Encoding,int)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCoreApplicationFunc_translate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translate(const char * context, const char * key, const char * disambiguation, QCoreApplication::Encoding encoding)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "disambiguation");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.translate(): got multiple values for keyword argument 'disambiguation'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2]))))
                        goto Sbk_QCoreApplicationFunc_translate_TypeError;
                }
                value = PyDict_GetItemString(kwds, "encoding");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QCoreApplication.translate(): got multiple values for keyword argument 'encoding'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX]), (pyArgs[3]))))
                        goto Sbk_QCoreApplicationFunc_translate_TypeError;
                }
            }
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            const char* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QCoreApplication::Encoding cppArg3 = QCoreApplication::CodecForTr;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // translate(const char*,const char*,const char*,QCoreApplication::Encoding)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QCoreApplication::translate(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // translate(const char * context, const char * key, const char * disambiguation, QCoreApplication::Encoding encoding, int n)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            const char* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QCoreApplication::Encoding cppArg3 = ((::QCoreApplication::Encoding)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // translate(const char*,const char*,const char*,QCoreApplication::Encoding,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = ::QCoreApplication::translate(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
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

    Sbk_QCoreApplicationFunc_translate_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME " = None, PySide.QtCore.QCoreApplication.Encoding = CodecForTr", "" SBK_STR_NAME ", " SBK_STR_NAME ", " SBK_STR_NAME ", PySide.QtCore.QCoreApplication.Encoding, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QCoreApplication.translate", overloads);
        return 0;
}

static PyMethodDef Sbk_QCoreApplication_methods[] = {
    {"addLibraryPath", (PyCFunction)Sbk_QCoreApplicationFunc_addLibraryPath, METH_O|METH_STATIC},
    {"applicationDirPath", (PyCFunction)Sbk_QCoreApplicationFunc_applicationDirPath, METH_NOARGS|METH_STATIC},
    {"applicationFilePath", (PyCFunction)Sbk_QCoreApplicationFunc_applicationFilePath, METH_NOARGS|METH_STATIC},
    {"applicationName", (PyCFunction)Sbk_QCoreApplicationFunc_applicationName, METH_NOARGS|METH_STATIC},
    {"applicationPid", (PyCFunction)Sbk_QCoreApplicationFunc_applicationPid, METH_NOARGS|METH_STATIC},
    {"applicationVersion", (PyCFunction)Sbk_QCoreApplicationFunc_applicationVersion, METH_NOARGS|METH_STATIC},
    {"arguments", (PyCFunction)Sbk_QCoreApplicationFunc_arguments, METH_NOARGS|METH_STATIC},
    {"closingDown", (PyCFunction)Sbk_QCoreApplicationFunc_closingDown, METH_NOARGS|METH_STATIC},
    {"event", (PyCFunction)Sbk_QCoreApplicationFunc_event, METH_O},
    {"exec_", (PyCFunction)Sbk_QCoreApplicationFunc_exec_, METH_NOARGS|METH_STATIC},
    {"exit", (PyCFunction)Sbk_QCoreApplicationFunc_exit, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"flush", (PyCFunction)Sbk_QCoreApplicationFunc_flush, METH_NOARGS|METH_STATIC},
    {"hasPendingEvents", (PyCFunction)Sbk_QCoreApplicationFunc_hasPendingEvents, METH_NOARGS|METH_STATIC},
    {"installTranslator", (PyCFunction)Sbk_QCoreApplicationFunc_installTranslator, METH_O|METH_STATIC},
    {"instance", (PyCFunction)Sbk_QCoreApplicationFunc_instance, METH_NOARGS|METH_STATIC},
    {"libraryPaths", (PyCFunction)Sbk_QCoreApplicationFunc_libraryPaths, METH_NOARGS|METH_STATIC},
    {"notify", (PyCFunction)Sbk_QCoreApplicationFunc_notify, METH_VARARGS},
    {"organizationDomain", (PyCFunction)Sbk_QCoreApplicationFunc_organizationDomain, METH_NOARGS|METH_STATIC},
    {"organizationName", (PyCFunction)Sbk_QCoreApplicationFunc_organizationName, METH_NOARGS|METH_STATIC},
    {"postEvent", (PyCFunction)Sbk_QCoreApplicationFunc_postEvent, METH_VARARGS|METH_STATIC},
    {"processEvents", (PyCFunction)Sbk_QCoreApplicationFunc_processEvents, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"quit", (PyCFunction)Sbk_QCoreApplicationFunc_quit, METH_NOARGS|METH_STATIC},
    {"removeLibraryPath", (PyCFunction)Sbk_QCoreApplicationFunc_removeLibraryPath, METH_O|METH_STATIC},
    {"removePostedEvents", (PyCFunction)Sbk_QCoreApplicationFunc_removePostedEvents, METH_VARARGS|METH_STATIC},
    {"removeTranslator", (PyCFunction)Sbk_QCoreApplicationFunc_removeTranslator, METH_O|METH_STATIC},
    {"sendEvent", (PyCFunction)Sbk_QCoreApplicationFunc_sendEvent, METH_VARARGS|METH_STATIC},
    {"sendPostedEvents", (PyCFunction)Sbk_QCoreApplicationFunc_sendPostedEvents, METH_VARARGS|METH_STATIC},
    {"setApplicationName", (PyCFunction)Sbk_QCoreApplicationFunc_setApplicationName, METH_O|METH_STATIC},
    {"setApplicationVersion", (PyCFunction)Sbk_QCoreApplicationFunc_setApplicationVersion, METH_O|METH_STATIC},
    {"setAttribute", (PyCFunction)Sbk_QCoreApplicationFunc_setAttribute, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setLibraryPaths", (PyCFunction)Sbk_QCoreApplicationFunc_setLibraryPaths, METH_O|METH_STATIC},
    {"setOrganizationDomain", (PyCFunction)Sbk_QCoreApplicationFunc_setOrganizationDomain, METH_O|METH_STATIC},
    {"setOrganizationName", (PyCFunction)Sbk_QCoreApplicationFunc_setOrganizationName, METH_O|METH_STATIC},
    {"startingUp", (PyCFunction)Sbk_QCoreApplicationFunc_startingUp, METH_NOARGS|METH_STATIC},
    {"testAttribute", (PyCFunction)Sbk_QCoreApplicationFunc_testAttribute, METH_O|METH_STATIC},
    {"translate", (PyCFunction)Sbk_QCoreApplicationFunc_translate, METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QCoreApplication_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QCoreApplication_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QCoreApplication_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QCoreApplication",
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
    /*tp_traverse*/         Sbk_QCoreApplication_traverse,
    /*tp_clear*/            Sbk_QCoreApplication_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QCoreApplication_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QCoreApplication_Init,
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

static void* Sbk_QCoreApplication_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QCoreApplication*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QCoreApplication_Encoding_PythonToCpp_QCoreApplication_Encoding(PyObject* pyIn, void* cppOut) {
    *((::QCoreApplication::Encoding*)cppOut) = (::QCoreApplication::Encoding) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QCoreApplication_Encoding_PythonToCpp_QCoreApplication_Encoding_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX]))
        return QCoreApplication_Encoding_PythonToCpp_QCoreApplication_Encoding;
    return 0;
}
static PyObject* QCoreApplication_Encoding_CppToPython_QCoreApplication_Encoding(const void* cppIn) {
    int castCppIn = *((::QCoreApplication::Encoding*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QCoreApplication_PythonToCpp_QCoreApplication_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QCoreApplication_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QCoreApplication_PythonToCpp_QCoreApplication_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QCoreApplication_Type))
        return QCoreApplication_PythonToCpp_QCoreApplication_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QCoreApplication_PTR_CppToPython_QCoreApplication(const void* cppIn) {
    return PySide::getWrapperForQObject((::QCoreApplication*)cppIn, &Sbk_QCoreApplication_Type);

}

void init_QCoreApplication(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QCoreApplication_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QCoreApplication", "QCoreApplication*",
        &Sbk_QCoreApplication_Type, &Shiboken::callCppDestructor< ::QCoreApplication >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QCoreApplication_Type,
        QCoreApplication_PythonToCpp_QCoreApplication_PTR,
        is_QCoreApplication_PythonToCpp_QCoreApplication_PTR_Convertible,
        QCoreApplication_PTR_CppToPython_QCoreApplication);

    Shiboken::Conversions::registerConverterName(converter, "QCoreApplication");
    Shiboken::Conversions::registerConverterName(converter, "QCoreApplication*");
    Shiboken::Conversions::registerConverterName(converter, "QCoreApplication&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCoreApplication).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCoreApplicationWrapper).name());



    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QCoreApplication_Type, &Sbk_QCoreApplication_typeDiscovery);

    // Initialization of enums.

    // Initialization of anonymous enum identified by enum value 'ApplicationFlags'.
    {
        PyObject* anonEnumItem = PyInt_FromLong((long) QCoreApplication::ApplicationFlags);
        if (PyDict_SetItemString(((SbkObjectType*)&Sbk_QCoreApplication_Type)->super.ht_type.tp_dict, "ApplicationFlags", anonEnumItem) < 0)
            return ;
        Py_DECREF(anonEnumItem);
    }
    // End of 'ApplicationFlags' enum.

    // Initialization of enum 'Encoding'.
    SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QCoreApplication_Type,
        "Encoding",
        "PySide.QtCore.QCoreApplication.Encoding",
        "QCoreApplication::Encoding");
    if (!SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX],
        &Sbk_QCoreApplication_Type, "CodecForTr", (long) QCoreApplication::CodecForTr))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX],
        &Sbk_QCoreApplication_Type, "UnicodeUTF8", (long) QCoreApplication::UnicodeUTF8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX],
        &Sbk_QCoreApplication_Type, "DefaultCodec", (long) QCoreApplication::DefaultCodec))
        return ;
    // Register converter for enum 'QCoreApplication::Encoding'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX],
            QCoreApplication_Encoding_CppToPython_QCoreApplication_Encoding);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QCoreApplication_Encoding_PythonToCpp_QCoreApplication_Encoding,
            is_QCoreApplication_Encoding_PythonToCpp_QCoreApplication_Encoding_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QCOREAPPLICATION_ENCODING_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QCoreApplication::Encoding");
        Shiboken::Conversions::registerConverterName(converter, "Encoding");
    }
    // End of 'Encoding' enum.

    PySide::Signal::registerSignals(&Sbk_QCoreApplication_Type, &::QCoreApplication::staticMetaObject);


    qRegisterMetaType< ::QCoreApplication::Encoding >("QCoreApplication::Encoding");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QCoreApplication_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QCoreApplication_Type, &::QCoreApplication::staticMetaObject, sizeof(::QCoreApplication));
}

