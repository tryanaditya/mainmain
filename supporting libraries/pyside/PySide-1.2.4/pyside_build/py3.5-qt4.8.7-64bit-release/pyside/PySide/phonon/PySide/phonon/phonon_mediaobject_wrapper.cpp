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
#include <set>
#include "pyside_phonon_python.h"

#include "phonon_mediaobject_wrapper.h"

// Extra includes
#include <QList>
#include <QMultiMap>
#include <mediasource.h>
#include <path.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qurl.h>

using namespace Phonon;

// Native ---------------------------------------------------------

MediaObjectWrapper::MediaObjectWrapper(QObject * parent) : Phonon::MediaObject(parent) {
    // ... middle
}

void MediaObjectWrapper::childEvent(QChildEvent * arg__1)
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

void MediaObjectWrapper::connectNotify(const char * signal)
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

void MediaObjectWrapper::customEvent(QEvent * arg__1)
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

void MediaObjectWrapper::disconnectNotify(const char * signal)
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

bool MediaObjectWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObject.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool MediaObjectWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaObject.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void MediaObjectWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* MediaObjectWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return Phonon::MediaObject::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int MediaObjectWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = Phonon::MediaObject::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* MediaObjectWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< MediaObjectWrapper* >(this));
        return Phonon::MediaObject::qt_metacast(_clname);
}

MediaObjectWrapper::~MediaObjectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_MediaObject_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX]);
    if (type != myType) {
        Shiboken::ObjectType::copyMultimpleheritance(type, myType);
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::MediaObject >()))
        return -1;

    ::MediaObjectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:MediaObject", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: MediaObject(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // MediaObject(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // MediaObject(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObject_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.MediaObject(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_Phonon_MediaObject_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // MediaObject(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::MediaObjectWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::MediaObjectWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::MediaObject >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_MediaObject_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_Phonon_MediaObject_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.MediaObject", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_clear(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_Phonon_MediaObjectFunc_clearQueue(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearQueue()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearQueue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_currentSource(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentSource()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::MediaSource cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->currentSource();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_currentTime(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->currentTime();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_enqueue(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: enqueue(Phonon::MediaSource)
    // 1: enqueue(QList<Phonon::MediaSource>)
    // 2: enqueue(QList<QUrl>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX], (pyArg)))) {
        overloadId = 2; // enqueue(QList<QUrl>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // enqueue(Phonon::MediaSource)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 1; // enqueue(QList<Phonon::MediaSource>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_enqueue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // enqueue(const Phonon::MediaSource & source)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::Phonon::MediaSource cppArg0_local = ::Phonon::MediaSource();
            ::Phonon::MediaSource* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // enqueue(Phonon::MediaSource)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->enqueue(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // enqueue(const QList<Phonon::MediaSource > & sources)
        {
            ::QList<Phonon::MediaSource > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // enqueue(QList<Phonon::MediaSource>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->enqueue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // enqueue(const QList<QUrl > & urls)
        {
            ::QList<QUrl > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // enqueue(QList<QUrl>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->enqueue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_enqueue_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaSource", "list", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.enqueue", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_errorString(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->errorString();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_errorType(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::ErrorType cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->errorType();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_ERRORTYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_hasVideo(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasVideo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->hasVideo();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_isSeekable(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSeekable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->isSeekable();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_metaData(PyObject* self, PyObject* args)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "metaData", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: metaData()const
    // 1: metaData(Phonon::MetaData)const
    // 2: metaData(QString)const
    if (numArgs == 0) {
        overloadId = 0; // metaData()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 2; // metaData(QString)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_METADATA_IDX]), (pyArgs[0])))) {
        overloadId = 1; // metaData(Phonon::MetaData)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_metaData_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // metaData() const
        {

            if (!PyErr_Occurred()) {
                // metaData()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMultiMap<QString, QString > cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->metaData();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QMULTIMAP_QSTRING_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // metaData(Phonon::MetaData key) const
        {
            ::Phonon::MetaData cppArg0 = ((::Phonon::MetaData)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // metaData(Phonon::MetaData)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->metaData(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
        case 2: // metaData(const QString & key) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // metaData(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->metaData(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_MediaObjectFunc_metaData_TypeError:
        const char* overloads[] = {"", "PySide.phonon.Phonon.MetaData", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.MediaObject.metaData", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_pause(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pause()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pause();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_play(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // play()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->play();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_prefinishMark(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prefinishMark()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->prefinishMark();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_queue(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // queue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::MediaSource > cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->queue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_remainingTime(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // remainingTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->remainingTime();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_seek(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: seek(qint64)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // seek(qint64)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_seek_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(qint64)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->seek(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_seek_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.seek", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_setCurrentSource(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentSource(Phonon::MediaSource)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentSource(Phonon::MediaSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_setCurrentSource_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::MediaSource cppArg0_local = ::Phonon::MediaSource();
        ::Phonon::MediaSource* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIASOURCE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCurrentSource(Phonon::MediaSource)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentSource(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_setCurrentSource_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.setCurrentSource", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_setPrefinishMark(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrefinishMark(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setPrefinishMark(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_setPrefinishMark_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrefinishMark(qint32)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrefinishMark(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_setPrefinishMark_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.setPrefinishMark", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_setQueue(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setQueue(QList<Phonon::MediaSource>)
    // 1: setQueue(QList<QUrl>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QURL_IDX], (pyArg)))) {
        overloadId = 1; // setQueue(QList<QUrl>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIASOURCE_IDX], (pyArg)))) {
        overloadId = 0; // setQueue(QList<Phonon::MediaSource>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_setQueue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setQueue(const QList<Phonon::MediaSource > & sources)
        {
            ::QList<Phonon::MediaSource > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setQueue(QList<Phonon::MediaSource>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setQueue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setQueue(const QList<QUrl > & urls)
        {
            ::QList<QUrl > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setQueue(QList<QUrl>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setQueue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_setQueue_TypeError:
        const char* overloads[] = {"list", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.setQueue", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_setTickInterval(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTickInterval(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setTickInterval(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_setTickInterval_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTickInterval(qint32)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTickInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_setTickInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.setTickInterval", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_setTransitionTime(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransitionTime(qint32)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), (pyArg)))) {
        overloadId = 0; // setTransitionTime(qint32)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaObjectFunc_setTransitionTime_TypeError;

    // Call function/method
    {
        qint32 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTransitionTime(qint32)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransitionTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaObjectFunc_setTransitionTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaObject.setTransitionTime", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_state(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::State cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_stop(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_tickInterval(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tickInterval()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->tickInterval();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaObjectFunc_totalTime(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // totalTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->totalTime();
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

static PyObject* Sbk_Phonon_MediaObjectFunc_transitionTime(PyObject* self)
{
    ::Phonon::MediaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaObject*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transitionTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::Phonon::MediaObject*>(cppSelf)->transitionTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_MediaObject_methods[] = {
    {"clear", (PyCFunction)Sbk_Phonon_MediaObjectFunc_clear, METH_NOARGS},
    {"clearQueue", (PyCFunction)Sbk_Phonon_MediaObjectFunc_clearQueue, METH_NOARGS},
    {"currentSource", (PyCFunction)Sbk_Phonon_MediaObjectFunc_currentSource, METH_NOARGS},
    {"currentTime", (PyCFunction)Sbk_Phonon_MediaObjectFunc_currentTime, METH_NOARGS},
    {"enqueue", (PyCFunction)Sbk_Phonon_MediaObjectFunc_enqueue, METH_O},
    {"errorString", (PyCFunction)Sbk_Phonon_MediaObjectFunc_errorString, METH_NOARGS},
    {"errorType", (PyCFunction)Sbk_Phonon_MediaObjectFunc_errorType, METH_NOARGS},
    {"hasVideo", (PyCFunction)Sbk_Phonon_MediaObjectFunc_hasVideo, METH_NOARGS},
    {"isSeekable", (PyCFunction)Sbk_Phonon_MediaObjectFunc_isSeekable, METH_NOARGS},
    {"metaData", (PyCFunction)Sbk_Phonon_MediaObjectFunc_metaData, METH_VARARGS},
    {"pause", (PyCFunction)Sbk_Phonon_MediaObjectFunc_pause, METH_NOARGS},
    {"play", (PyCFunction)Sbk_Phonon_MediaObjectFunc_play, METH_NOARGS},
    {"prefinishMark", (PyCFunction)Sbk_Phonon_MediaObjectFunc_prefinishMark, METH_NOARGS},
    {"queue", (PyCFunction)Sbk_Phonon_MediaObjectFunc_queue, METH_NOARGS},
    {"remainingTime", (PyCFunction)Sbk_Phonon_MediaObjectFunc_remainingTime, METH_NOARGS},
    {"seek", (PyCFunction)Sbk_Phonon_MediaObjectFunc_seek, METH_O},
    {"setCurrentSource", (PyCFunction)Sbk_Phonon_MediaObjectFunc_setCurrentSource, METH_O},
    {"setPrefinishMark", (PyCFunction)Sbk_Phonon_MediaObjectFunc_setPrefinishMark, METH_O},
    {"setQueue", (PyCFunction)Sbk_Phonon_MediaObjectFunc_setQueue, METH_O},
    {"setTickInterval", (PyCFunction)Sbk_Phonon_MediaObjectFunc_setTickInterval, METH_O},
    {"setTransitionTime", (PyCFunction)Sbk_Phonon_MediaObjectFunc_setTransitionTime, METH_O},
    {"state", (PyCFunction)Sbk_Phonon_MediaObjectFunc_state, METH_NOARGS},
    {"stop", (PyCFunction)Sbk_Phonon_MediaObjectFunc_stop, METH_NOARGS},
    {"tickInterval", (PyCFunction)Sbk_Phonon_MediaObjectFunc_tickInterval, METH_NOARGS},
    {"totalTime", (PyCFunction)Sbk_Phonon_MediaObjectFunc_totalTime, METH_NOARGS},
    {"transitionTime", (PyCFunction)Sbk_Phonon_MediaObjectFunc_transitionTime, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_MediaObject_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_MediaObject_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1, -1, -1 };
int*
Sbk_Phonon_MediaObject_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const Phonon::MediaObject* class_ptr = reinterpret_cast<const Phonon::MediaObject*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QObject*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QObject*>((Phonon::MediaObject*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const Phonon::MediaNode*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const Phonon::MediaNode*>((Phonon::MediaObject*)((void*)class_ptr))) - base);

        offsets.erase(0);

        int i = 0;
        for (it = offsets.begin(); it != offsets.end(); it++) {
            mi_offsets[i] = *it;
            i++;
        }
    }
    return mi_offsets;
}
static void* Sbk_Phonon_MediaObjectSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    Phonon::MediaObject* me = reinterpret_cast< ::Phonon::MediaObject*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX]))
        return static_cast< ::Phonon::MediaNode*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_MediaObject_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.MediaObject",
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
    /*tp_traverse*/         Sbk_Phonon_MediaObject_traverse,
    /*tp_clear*/            Sbk_Phonon_MediaObject_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_MediaObject_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_MediaObject_Init,
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

static void* Sbk_Phonon_MediaObject_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::Phonon::MediaObject*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Phonon::MediaNode >()))
        return dynamic_cast< ::Phonon::MediaObject*>(reinterpret_cast< ::Phonon::MediaNode*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void MediaObject_PythonToCpp_MediaObject_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_MediaObject_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MediaObject_PythonToCpp_MediaObject_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaObject_Type))
        return MediaObject_PythonToCpp_MediaObject_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MediaObject_PTR_CppToPython_MediaObject(const void* cppIn) {
    return PySide::getWrapperForQObject((::Phonon::MediaObject*)cppIn, &Sbk_Phonon_MediaObject_Type);

}

void init_Phonon_MediaObject(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_MediaObject_Type);

    PyObject* Sbk_Phonon_MediaObject_Type_bases = PyTuple_Pack(2,
        (PyObject*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX],
        (PyObject*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX]);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MediaObject", "Phonon::MediaObject*",
        &Sbk_Phonon_MediaObject_Type, &Shiboken::callCppDestructor< ::Phonon::MediaObject >, (SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX], Sbk_Phonon_MediaObject_Type_bases, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_MediaObject_Type,
        MediaObject_PythonToCpp_MediaObject_PTR,
        is_MediaObject_PythonToCpp_MediaObject_PTR_Convertible,
        MediaObject_PTR_CppToPython_MediaObject);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObject");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObject*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaObject&");
    Shiboken::Conversions::registerConverterName(converter, "MediaObject");
    Shiboken::Conversions::registerConverterName(converter, "MediaObject*");
    Shiboken::Conversions::registerConverterName(converter, "MediaObject&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::MediaObject).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::MediaObjectWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_Phonon_MediaObject_mi_init;
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_Phonon_MediaObject_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_Phonon_MediaObject_Type, &Sbk_Phonon_MediaObjectSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Phonon_MediaObject_Type, &Sbk_Phonon_MediaObject_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_Phonon_MediaObject_Type, &::Phonon::MediaObject::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_Phonon_MediaObject_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_Phonon_MediaObject_Type, &::Phonon::MediaObject::staticMetaObject, sizeof(::Phonon::MediaObject));
}
