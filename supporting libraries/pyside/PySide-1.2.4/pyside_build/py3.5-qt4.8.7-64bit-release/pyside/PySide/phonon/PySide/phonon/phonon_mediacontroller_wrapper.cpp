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
#include "pyside_phonon_python.h"

#include "phonon_mediacontroller_wrapper.h"

// Extra includes
#include <QList>
#include <mediaobject.h>
#include <objectdescription.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qfont.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qurl.h>

using namespace Phonon;

// Native ---------------------------------------------------------

MediaControllerWrapper::MediaControllerWrapper(Phonon::MediaObject * parent) : Phonon::MediaController(parent) {
    // ... middle
}

void MediaControllerWrapper::childEvent(QChildEvent * arg__1)
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

void MediaControllerWrapper::connectNotify(const char * signal)
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

void MediaControllerWrapper::customEvent(QEvent * arg__1)
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

void MediaControllerWrapper::disconnectNotify(const char * signal)
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

bool MediaControllerWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaController.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool MediaControllerWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "MediaController.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void MediaControllerWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* MediaControllerWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return Phonon::MediaController::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int MediaControllerWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = Phonon::MediaController::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* MediaControllerWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< MediaControllerWrapper* >(this));
        return Phonon::MediaController::qt_metacast(_clname);
}

MediaControllerWrapper::~MediaControllerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_MediaController_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::MediaController >()))
        return -1;

    ::MediaControllerWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "MediaController", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: MediaController(Phonon::MediaObject*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_MEDIAOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // MediaController(Phonon::MediaObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaController_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::Phonon::MediaObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // MediaController(Phonon::MediaObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::MediaControllerWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::MediaControllerWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::MediaController >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_MediaController_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_Phonon_MediaController_Init_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.MediaController", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_autoplayTitles(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoplayTitles()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->autoplayTitles();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_availableAngles(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAngles()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableAngles();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_availableAudioChannels(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableAudioChannels()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::AudioChannelDescription > cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableAudioChannels();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_AUDIOCHANNELDESCRIPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_availableChapters(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableChapters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableChapters();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_availableMenus(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableMenus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::MediaController::NavigationMenu > cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableMenus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_availableSubtitles(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableSubtitles()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Phonon::SubtitleDescription > cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableSubtitles();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_PHONON_SUBTITLEDESCRIPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_availableTitles(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableTitles()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->availableTitles();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_currentAngle(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentAngle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->currentAngle();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_currentAudioChannel(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentAudioChannel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::AudioChannelDescription cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->currentAudioChannel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_currentChapter(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentChapter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->currentChapter();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_currentSubtitle(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentSubtitle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::SubtitleDescription cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->currentSubtitle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_currentTitle(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTitle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->currentTitle();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_navigationMenuToString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: navigationMenuToString(Phonon::MediaController::NavigationMenu)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]), (pyArg)))) {
        overloadId = 0; // navigationMenuToString(Phonon::MediaController::NavigationMenu)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_navigationMenuToString_TypeError;

    // Call function/method
    {
        ::Phonon::MediaController::NavigationMenu cppArg0 = ((::Phonon::MediaController::NavigationMenu)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // navigationMenuToString(Phonon::MediaController::NavigationMenu)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::Phonon::MediaController::navigationMenuToString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_MediaControllerFunc_navigationMenuToString_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaController.NavigationMenu", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.navigationMenuToString", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_nextTitle(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nextTitle()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->nextTitle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_previousTitle(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // previousTitle()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->previousTitle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setAutoplayTitles(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoplayTitles(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoplayTitles(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setAutoplayTitles_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoplayTitles(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoplayTitles(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setAutoplayTitles_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setAutoplayTitles", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentAngle(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentAngle(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentAngle(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentAngle_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentAngle(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentAngle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentAngle_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentAngle", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentAudioChannel(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentAudioChannel(Phonon::AudioChannelDescription)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentAudioChannel(Phonon::AudioChannelDescription)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentAudioChannel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Phonon::AudioChannelDescription cppArg0_local = ::Phonon::AudioChannelDescription();
        ::Phonon::AudioChannelDescription* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCHANNELDESCRIPTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCurrentAudioChannel(Phonon::AudioChannelDescription)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentAudioChannel(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentAudioChannel_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::AudioChannelDescription", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentAudioChannel", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentChapter(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentChapter(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentChapter(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentChapter_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentChapter(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentChapter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentChapter_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentChapter", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentMenu(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentMenu(Phonon::MediaController::NavigationMenu)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]), (pyArg)))) {
        overloadId = 0; // setCurrentMenu(Phonon::MediaController::NavigationMenu)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentMenu_TypeError;

    // Call function/method
    {
        ::Phonon::MediaController::NavigationMenu cppArg0 = ((::Phonon::MediaController::NavigationMenu)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentMenu(Phonon::MediaController::NavigationMenu)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentMenu(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentMenu_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::MediaController.NavigationMenu", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentMenu", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentSubtitle(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentSubtitle(Phonon::SubtitleDescription)
    // 1: setCurrentSubtitle(QUrl)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArg)))) {
        overloadId = 1; // setCurrentSubtitle(QUrl)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentSubtitle(Phonon::SubtitleDescription)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentSubtitle_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setCurrentSubtitle(const Phonon::SubtitleDescription & stream)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::Phonon::SubtitleDescription cppArg0_local = ::Phonon::SubtitleDescription();
            ::Phonon::SubtitleDescription* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_SUBTITLEDESCRIPTION_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setCurrentSubtitle(Phonon::SubtitleDescription)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCurrentSubtitle(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setCurrentSubtitle(const QUrl & url)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QUrl cppArg0_local = ::QUrl();
            ::QUrl* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setCurrentSubtitle(QUrl)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setCurrentSubtitle(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentSubtitle_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::SubtitleDescription", "PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentSubtitle", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setCurrentTitle(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentTitle(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentTitle(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setCurrentTitle_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentTitle(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentTitle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setCurrentTitle_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setCurrentTitle", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setSubtitleAutodetect(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSubtitleAutodetect(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSubtitleAutodetect(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setSubtitleAutodetect_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSubtitleAutodetect(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSubtitleAutodetect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setSubtitleAutodetect_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setSubtitleAutodetect", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setSubtitleEncoding(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSubtitleEncoding(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setSubtitleEncoding(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setSubtitleEncoding_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSubtitleEncoding(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSubtitleEncoding(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setSubtitleEncoding_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setSubtitleEncoding", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_setSubtitleFont(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSubtitleFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setSubtitleFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_MediaControllerFunc_setSubtitleFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSubtitleFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSubtitleFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_MediaControllerFunc_setSubtitleFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.MediaController.setSubtitleFont", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_subtitleAutodetect(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // subtitleAutodetect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->subtitleAutodetect();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_subtitleEncoding(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // subtitleEncoding()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->subtitleEncoding();
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

static PyObject* Sbk_Phonon_MediaControllerFunc_subtitleFont(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // subtitleFont()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->subtitleFont();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_MediaControllerFunc_supportedFeatures(PyObject* self)
{
    ::Phonon::MediaController* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::MediaController*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedFeatures()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Phonon::MediaController::Feature> cppResult = const_cast<const ::Phonon::MediaController*>(cppSelf)->supportedFeatures();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_MediaController_methods[] = {
    {"autoplayTitles", (PyCFunction)Sbk_Phonon_MediaControllerFunc_autoplayTitles, METH_NOARGS},
    {"availableAngles", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableAngles, METH_NOARGS},
    {"availableAudioChannels", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableAudioChannels, METH_NOARGS},
    {"availableChapters", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableChapters, METH_NOARGS},
    {"availableMenus", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableMenus, METH_NOARGS},
    {"availableSubtitles", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableSubtitles, METH_NOARGS},
    {"availableTitles", (PyCFunction)Sbk_Phonon_MediaControllerFunc_availableTitles, METH_NOARGS},
    {"currentAngle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_currentAngle, METH_NOARGS},
    {"currentAudioChannel", (PyCFunction)Sbk_Phonon_MediaControllerFunc_currentAudioChannel, METH_NOARGS},
    {"currentChapter", (PyCFunction)Sbk_Phonon_MediaControllerFunc_currentChapter, METH_NOARGS},
    {"currentSubtitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_currentSubtitle, METH_NOARGS},
    {"currentTitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_currentTitle, METH_NOARGS},
    {"navigationMenuToString", (PyCFunction)Sbk_Phonon_MediaControllerFunc_navigationMenuToString, METH_O|METH_STATIC},
    {"nextTitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_nextTitle, METH_NOARGS},
    {"previousTitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_previousTitle, METH_NOARGS},
    {"setAutoplayTitles", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setAutoplayTitles, METH_O},
    {"setCurrentAngle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentAngle, METH_O},
    {"setCurrentAudioChannel", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentAudioChannel, METH_O},
    {"setCurrentChapter", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentChapter, METH_O},
    {"setCurrentMenu", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentMenu, METH_O},
    {"setCurrentSubtitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentSubtitle, METH_O},
    {"setCurrentTitle", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setCurrentTitle, METH_O},
    {"setSubtitleAutodetect", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setSubtitleAutodetect, METH_O},
    {"setSubtitleEncoding", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setSubtitleEncoding, METH_O},
    {"setSubtitleFont", (PyCFunction)Sbk_Phonon_MediaControllerFunc_setSubtitleFont, METH_O},
    {"subtitleAutodetect", (PyCFunction)Sbk_Phonon_MediaControllerFunc_subtitleAutodetect, METH_NOARGS},
    {"subtitleEncoding", (PyCFunction)Sbk_Phonon_MediaControllerFunc_subtitleEncoding, METH_NOARGS},
    {"subtitleFont", (PyCFunction)Sbk_Phonon_MediaControllerFunc_subtitleFont, METH_NOARGS},
    {"supportedFeatures", (PyCFunction)Sbk_Phonon_MediaControllerFunc_supportedFeatures, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_MediaController_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_MediaController_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_MediaController_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.MediaController",
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
    /*tp_traverse*/         Sbk_Phonon_MediaController_traverse,
    /*tp_clear*/            Sbk_Phonon_MediaController_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_MediaController_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_MediaController_Init,
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

static void* Sbk_Phonon_MediaController_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::Phonon::MediaController*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_phonon_Phonon_MediaController_Feature___and__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController::Features cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::MediaController::Features)PyLong_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::MediaController::Features)PyInt_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_MediaController_Feature___or__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController::Features cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::MediaController::Features)PyLong_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::MediaController::Features)PyInt_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_MediaController_Feature___xor__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController::Features cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::MediaController::Features)PyLong_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::MediaController::Features)PyInt_AsLong(self);
    cppArg = (Phonon::MediaController::Features)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_MediaController_Feature___invert__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::MediaController::Features cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), self, &cppSelf);
    ::Phonon::MediaController::Features cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_phonon_Phonon_MediaController_Feature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_phonon_Phonon_MediaController_Feature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_phonon_Phonon_MediaController_Feature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_phonon_Phonon_MediaController_Feature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_phonon_Phonon_MediaController_Feature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_phonon_Phonon_MediaController_Feature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_phonon_Phonon_MediaController_Feature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_phonon_Phonon_MediaController_Feature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_phonon_Phonon_MediaController_Feature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_phonon_Phonon_MediaController_Feature_long,
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
static void Phonon_MediaController_Feature_PythonToCpp_Phonon_MediaController_Feature(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaController::Feature*)cppOut) = (::Phonon::MediaController::Feature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_MediaController_Feature_PythonToCpp_Phonon_MediaController_Feature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX]))
        return Phonon_MediaController_Feature_PythonToCpp_Phonon_MediaController_Feature;
    return 0;
}
static PyObject* Phonon_MediaController_Feature_CppToPython_Phonon_MediaController_Feature(const void* cppIn) {
    int castCppIn = *((::Phonon::MediaController::Feature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX], castCppIn);

}

static void QFlags_Phonon_MediaController_Feature__PythonToCpp_QFlags_Phonon_MediaController_Feature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Phonon::MediaController::Feature>*)cppOut) = ::QFlags<Phonon::MediaController::Feature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Phonon_MediaController_Feature__PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]))
        return QFlags_Phonon_MediaController_Feature__PythonToCpp_QFlags_Phonon_MediaController_Feature_;
    return 0;
}
static PyObject* QFlags_Phonon_MediaController_Feature__CppToPython_QFlags_Phonon_MediaController_Feature_(const void* cppIn) {
    int castCppIn = *((::QFlags<Phonon::MediaController::Feature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]));

}

static void Phonon_MediaController_Feature_PythonToCpp_QFlags_Phonon_MediaController_Feature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Phonon::MediaController::Feature>*)cppOut) = ::QFlags<Phonon::MediaController::Feature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Phonon_MediaController_Feature_PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX]))
        return Phonon_MediaController_Feature_PythonToCpp_QFlags_Phonon_MediaController_Feature_;
    return 0;
}
static void number_PythonToCpp_QFlags_Phonon_MediaController_Feature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Phonon::MediaController::Feature>*)cppOut) = ::QFlags<Phonon::MediaController::Feature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Phonon_MediaController_Feature_;
    return 0;
}
static void Phonon_MediaController_NavigationMenu_PythonToCpp_Phonon_MediaController_NavigationMenu(PyObject* pyIn, void* cppOut) {
    *((::Phonon::MediaController::NavigationMenu*)cppOut) = (::Phonon::MediaController::NavigationMenu) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_MediaController_NavigationMenu_PythonToCpp_Phonon_MediaController_NavigationMenu_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX]))
        return Phonon_MediaController_NavigationMenu_PythonToCpp_Phonon_MediaController_NavigationMenu;
    return 0;
}
static PyObject* Phonon_MediaController_NavigationMenu_CppToPython_Phonon_MediaController_NavigationMenu(const void* cppIn) {
    int castCppIn = *((::Phonon::MediaController::NavigationMenu*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void MediaController_PythonToCpp_MediaController_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_MediaController_Type, pyIn, cppOut);
}
static PythonToCppFunc is_MediaController_PythonToCpp_MediaController_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_MediaController_Type))
        return MediaController_PythonToCpp_MediaController_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* MediaController_PTR_CppToPython_MediaController(const void* cppIn) {
    return PySide::getWrapperForQObject((::Phonon::MediaController*)cppIn, &Sbk_Phonon_MediaController_Type);

}

void init_Phonon_MediaController(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_MediaController_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "MediaController", "Phonon::MediaController*",
        &Sbk_Phonon_MediaController_Type, &Shiboken::callCppDestructor< ::Phonon::MediaController >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_MediaController_Type,
        MediaController_PythonToCpp_MediaController_PTR,
        is_MediaController_PythonToCpp_MediaController_PTR_Convertible,
        MediaController_PTR_CppToPython_MediaController);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaController");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaController*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaController&");
    Shiboken::Conversions::registerConverterName(converter, "MediaController");
    Shiboken::Conversions::registerConverterName(converter, "MediaController*");
    Shiboken::Conversions::registerConverterName(converter, "MediaController&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::MediaController).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::MediaControllerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Phonon_MediaController_Type, &Sbk_Phonon_MediaController_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Feature'.
    SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX] = PySide::QFlags::create("Features", &SbkPySide_phonon_Phonon_MediaController_Feature_as_number);
    SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_MediaController_Type,
        "Feature",
        "PySide.phonon.Phonon.MediaController.Feature",
        "Phonon::MediaController::Feature",
        SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX]);
    if (!SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "Angles", (long) Phonon::MediaController::Angles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "Chapters", (long) Phonon::MediaController::Chapters))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "Navigations", (long) Phonon::MediaController::Navigations))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "Titles", (long) Phonon::MediaController::Titles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "Subtitles", (long) Phonon::MediaController::Subtitles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
        &Sbk_Phonon_MediaController_Type, "AudioChannels", (long) Phonon::MediaController::AudioChannels))
        return ;
    // Register converter for enum 'Phonon::MediaController::Feature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX],
            Phonon_MediaController_Feature_CppToPython_Phonon_MediaController_Feature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_MediaController_Feature_PythonToCpp_Phonon_MediaController_Feature,
            is_Phonon_MediaController_Feature_PythonToCpp_Phonon_MediaController_Feature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_FEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaController::Feature");
        Shiboken::Conversions::registerConverterName(converter, "MediaController::Feature");
        Shiboken::Conversions::registerConverterName(converter, "Feature");
    }
    // Register converter for flag 'QFlags<Phonon::MediaController::Feature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX],
            QFlags_Phonon_MediaController_Feature__CppToPython_QFlags_Phonon_MediaController_Feature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_MediaController_Feature_PythonToCpp_QFlags_Phonon_MediaController_Feature_,
            is_Phonon_MediaController_Feature_PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Phonon_MediaController_Feature__PythonToCpp_QFlags_Phonon_MediaController_Feature_,
            is_QFlags_Phonon_MediaController_Feature__PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Phonon_MediaController_Feature_,
            is_number_PythonToCpp_QFlags_Phonon_MediaController_Feature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_MEDIACONTROLLER_FEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Phonon::MediaController::Feature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<MediaController::Feature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Feature>");
    }
    // End of 'Feature' enum/flags.

    // Initialization of enum 'NavigationMenu'.
    SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_MediaController_Type,
        "NavigationMenu",
        "PySide.phonon.Phonon.MediaController.NavigationMenu",
        "Phonon::MediaController::NavigationMenu");
    if (!SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "RootMenu", (long) Phonon::MediaController::RootMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "TitleMenu", (long) Phonon::MediaController::TitleMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "AudioMenu", (long) Phonon::MediaController::AudioMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "SubtitleMenu", (long) Phonon::MediaController::SubtitleMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "ChapterMenu", (long) Phonon::MediaController::ChapterMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
        &Sbk_Phonon_MediaController_Type, "AngleMenu", (long) Phonon::MediaController::AngleMenu))
        return ;
    // Register converter for enum 'Phonon::MediaController::NavigationMenu'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX],
            Phonon_MediaController_NavigationMenu_CppToPython_Phonon_MediaController_NavigationMenu);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_MediaController_NavigationMenu_PythonToCpp_Phonon_MediaController_NavigationMenu,
            is_Phonon_MediaController_NavigationMenu_PythonToCpp_Phonon_MediaController_NavigationMenu_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_MEDIACONTROLLER_NAVIGATIONMENU_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::MediaController::NavigationMenu");
        Shiboken::Conversions::registerConverterName(converter, "MediaController::NavigationMenu");
        Shiboken::Conversions::registerConverterName(converter, "NavigationMenu");
    }
    // End of 'NavigationMenu' enum.

    PySide::Signal::registerSignals(&Sbk_Phonon_MediaController_Type, &::Phonon::MediaController::staticMetaObject);

    qRegisterMetaType< ::Phonon::MediaController::Feature >("MediaController::Feature");
    qRegisterMetaType< ::Phonon::MediaController::Feature >("Phonon::MediaController::Feature");
    qRegisterMetaType< ::Phonon::MediaController::Features >("Phonon::MediaController::Features");
    qRegisterMetaType< ::Phonon::MediaController::NavigationMenu >("MediaController::NavigationMenu");
    qRegisterMetaType< ::Phonon::MediaController::NavigationMenu >("Phonon::MediaController::NavigationMenu");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_Phonon_MediaController_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_Phonon_MediaController_Type, &::Phonon::MediaController::staticMetaObject, sizeof(::Phonon::MediaController));
}
