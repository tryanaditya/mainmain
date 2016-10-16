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
#include "pyside_phonon_python.h"

#include "phonon_platformplugin_wrapper.h"

// Extra includes
#include <QList>
#include <QPair>
#include <abstractmediastream.h>
#include <objectdescription.h>
#include <pysideconversions.h>
#include <qbytearray.h>
#include <qicon.h>
#include <qobject.h>
#include <qurl.h>

using namespace Phonon;

// Native ---------------------------------------------------------

PlatformPluginWrapper::PlatformPluginWrapper() : Phonon::PlatformPlugin() {
    // ... middle
}

QString PlatformPluginWrapper::applicationName() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "applicationName"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.applicationName()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.applicationName", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QObject * PlatformPluginWrapper::createBackend()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createBackend"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createBackend()' not implemented.");
        return ((::QObject*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.createBackend", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QObject * PlatformPluginWrapper::createBackend(const QString & library, const QString & version)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createBackend"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createBackend()' not implemented.");
        return ((::QObject*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &library),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &version)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QObject*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.createBackend", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

Phonon::AbstractMediaStream * PlatformPluginWrapper::createMediaStream(const QUrl & url, QObject * parent)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::AbstractMediaStream*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createMediaStream"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createMediaStream()' not implemented.");
        return ((::Phonon::AbstractMediaStream*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &url),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], parent)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::AbstractMediaStream*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.createMediaStream", Shiboken::SbkType< Phonon::AbstractMediaStream >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::AbstractMediaStream*)0);
    }
    ::Phonon::AbstractMediaStream* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<QPair<QByteArray, QString > > PlatformPluginWrapper::deviceAccessListFor(const Phonon::AudioCaptureDevice & arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QPair<QByteArray, QString > >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deviceAccessListFor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::PlatformPlugin::deviceAccessListFor(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QPair<QByteArray, QString > >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.deviceAccessListFor", "list", pyResult->ob_type->tp_name);
        return ::QList<QPair<QByteArray, QString > >();
    }
    ::QList<QPair<QByteArray, QString > > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<QPair<QByteArray, QString > > PlatformPluginWrapper::deviceAccessListFor(const Phonon::AudioOutputDevice & arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QPair<QByteArray, QString > >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deviceAccessListFor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::PlatformPlugin::deviceAccessListFor(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QPair<QByteArray, QString > >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.deviceAccessListFor", "list", pyResult->ob_type->tp_name);
        return ::QList<QPair<QByteArray, QString > >();
    }
    ::QList<QPair<QByteArray, QString > > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<QPair<QByteArray, QString > > PlatformPluginWrapper::deviceAccessListFor(const Phonon::VideoCaptureDevice & arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QPair<QByteArray, QString > >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "deviceAccessListFor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Phonon::PlatformPlugin::deviceAccessListFor(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QPair<QByteArray, QString > >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.deviceAccessListFor", "list", pyResult->ob_type->tp_name);
        return ::QList<QPair<QByteArray, QString > >();
    }
    ::QList<QPair<QByteArray, QString > > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QIcon PlatformPluginWrapper::icon(const QString & name) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QIcon();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "icon"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.icon()' not implemented.");
        return ::QIcon();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QIcon();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.icon", Shiboken::SbkType< QIcon >()->tp_name, pyResult->ob_type->tp_name);
        return ::QIcon();
    }
    ::QIcon cppResult = ::QIcon();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PlatformPluginWrapper::isMimeTypeAvailable(const QString & mimeType) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isMimeTypeAvailable"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.isMimeTypeAvailable()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &mimeType)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.isMimeTypeAvailable", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qreal PlatformPluginWrapper::loadVolume(const QString & outputName) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "loadVolume"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.loadVolume()' not implemented.");
        return ((qreal)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &outputName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.loadVolume", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PlatformPluginWrapper::notification(const char * notificationName, const QString & text, const QStringList & actions, QObject * receiver, const char * actionSlot) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "notification"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.notification()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNNN)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), notificationName),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &text),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &actions),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], receiver),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), actionSlot)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QList<int > PlatformPluginWrapper::objectDescriptionIndexes(Phonon::ObjectDescriptionType type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<int >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "objectDescriptionIndexes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.objectDescriptionIndexes()' not implemented.");
        return ::QList<int >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX]), &type)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<int >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.objectDescriptionIndexes", "list", pyResult->ob_type->tp_name);
        return ::QList<int >();
    }
    ::QList<int > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QHash<QByteArray, QVariant > PlatformPluginWrapper::objectDescriptionProperties(Phonon::ObjectDescriptionType type, int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QHash<QByteArray, QVariant >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "objectDescriptionProperties"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.objectDescriptionProperties()' not implemented.");
        return ::QHash<QByteArray, QVariant >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX]), &type),
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QHash<QByteArray, QVariant >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PlatformPlugin.objectDescriptionProperties", "hash", pyResult->ob_type->tp_name);
        return ::QHash<QByteArray, QVariant >();
    }
    ::QHash<QByteArray, QVariant > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PlatformPluginWrapper::saveVolume(const QString & outputName, qreal volume)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "saveVolume"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.saveVolume()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Nd)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &outputName),
        volume
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

PlatformPluginWrapper::~PlatformPluginWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_PlatformPlugin_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::PlatformPlugin' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::PlatformPlugin >()))
        return -1;

    ::PlatformPluginWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PlatformPlugin()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::PlatformPluginWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::PlatformPlugin >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_applicationName(PyObject* self)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // applicationName()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.applicationName()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->applicationName();
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

static PyObject* Sbk_Phonon_PlatformPluginFunc_createBackend(PyObject* self, PyObject* args)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_Phonon_PlatformPluginFunc_createBackend_TypeError;

    if (!PyArg_UnpackTuple(args, "createBackend", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createBackend()
    // 1: createBackend(QString,QString)
    if (numArgs == 0) {
        overloadId = 0; // createBackend()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // createBackend(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_createBackend_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // createBackend()
        {

            if (!PyErr_Occurred()) {
                // createBackend()
                if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                    PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createBackend()' not implemented.");
                    return 0;
                }
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QObject * cppResult = cppSelf->createBackend();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // createBackend(const QString & library, const QString & version)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // createBackend(QString,QString)
                if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                    PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createBackend()' not implemented.");
                    return 0;
                }
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QObject * cppResult = cppSelf->createBackend(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
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

    Sbk_Phonon_PlatformPluginFunc_createBackend_TypeError:
        const char* overloads[] = {"", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.PlatformPlugin.createBackend", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_createMediaStream(PyObject* self, PyObject* args)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createMediaStream", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createMediaStream(QUrl,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // createMediaStream(QUrl,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_createMediaStream_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QUrl cppArg0_local = ::QUrl();
        ::QUrl* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createMediaStream(QUrl,QObject*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.createMediaStream()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::AbstractMediaStream * cppResult = cppSelf->createMediaStream(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_ABSTRACTMEDIASTREAM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_createMediaStream_TypeError:
        const char* overloads[] = {"PySide.QtCore.QUrl, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.PlatformPlugin.createMediaStream", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_deviceAccessListFor(PyObject* self, PyObject* pyArg)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deviceAccessListFor(Phonon::AudioCaptureDevice)const
    // 1: deviceAccessListFor(Phonon::AudioOutputDevice)const
    // 2: deviceAccessListFor(Phonon::VideoCaptureDevice)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], (pyArg)))) {
        overloadId = 2; // deviceAccessListFor(Phonon::VideoCaptureDevice)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], (pyArg)))) {
        overloadId = 1; // deviceAccessListFor(Phonon::AudioOutputDevice)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], (pyArg)))) {
        overloadId = 0; // deviceAccessListFor(Phonon::AudioCaptureDevice)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_deviceAccessListFor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // deviceAccessListFor(const Phonon::AudioCaptureDevice & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::Phonon::AudioCaptureDevice cppArg0_local = ::Phonon::AudioCaptureDevice();
            ::Phonon::AudioCaptureDevice* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOCAPTUREDEVICE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // deviceAccessListFor(Phonon::AudioCaptureDevice)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPair<QByteArray, QString > > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->::Phonon::PlatformPlugin::deviceAccessListFor(*cppArg0) : const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->deviceAccessListFor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // deviceAccessListFor(const Phonon::AudioOutputDevice & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::Phonon::AudioOutputDevice cppArg0_local = ::Phonon::AudioOutputDevice();
            ::Phonon::AudioOutputDevice* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_AUDIOOUTPUTDEVICE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // deviceAccessListFor(Phonon::AudioOutputDevice)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPair<QByteArray, QString > > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->::Phonon::PlatformPlugin::deviceAccessListFor(*cppArg0) : const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->deviceAccessListFor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // deviceAccessListFor(const Phonon::VideoCaptureDevice & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::Phonon::VideoCaptureDevice cppArg0_local = ::Phonon::VideoCaptureDevice();
            ::Phonon::VideoCaptureDevice* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_VIDEOCAPTUREDEVICE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // deviceAccessListFor(Phonon::VideoCaptureDevice)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QPair<QByteArray, QString > > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->::Phonon::PlatformPlugin::deviceAccessListFor(*cppArg0) : const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->deviceAccessListFor(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QPAIR_QBYTEARRAY_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_deviceAccessListFor_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::AudioCaptureDevice", "PySide.phonon.Phonon::AudioOutputDevice", "PySide.phonon.Phonon::VideoCaptureDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.PlatformPlugin.deviceAccessListFor", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_icon(PyObject* self, PyObject* pyArg)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: icon(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // icon(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_icon_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // icon(QString)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.icon()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->icon(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_icon_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.PlatformPlugin.icon", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_isMimeTypeAvailable(PyObject* self, PyObject* pyArg)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isMimeTypeAvailable(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isMimeTypeAvailable(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_isMimeTypeAvailable_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isMimeTypeAvailable(QString)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.isMimeTypeAvailable()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->isMimeTypeAvailable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_isMimeTypeAvailable_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.PlatformPlugin.isMimeTypeAvailable", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_loadVolume(PyObject* self, PyObject* pyArg)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadVolume(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // loadVolume(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_loadVolume_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadVolume(QString)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.loadVolume()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->loadVolume(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_loadVolume_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.PlatformPlugin.loadVolume", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_notification(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.PlatformPlugin.notification(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.PlatformPlugin.notification(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:notification", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: notification(const char*,QString,QStringList,QObject*,const char*)const
    if (numArgs >= 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // notification(const char*,QString,QStringList,QObject*,const char*)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // notification(const char*,QString,QStringList,QObject*,const char*)const
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // notification(const char*,QString,QStringList,QObject*,const char*)const
                } else if (Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4])))) {
                    overloadId = 0; // notification(const char*,QString,QStringList,QObject*,const char*)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_notification_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "actions");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.PlatformPlugin.notification(): got multiple values for keyword argument 'actions'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[2]))))
                    goto Sbk_Phonon_PlatformPluginFunc_notification_TypeError;
            }
            value = PyDict_GetItemString(kwds, "receiver");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.PlatformPlugin.notification(): got multiple values for keyword argument 'receiver'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3]))))
                    goto Sbk_Phonon_PlatformPluginFunc_notification_TypeError;
            }
            value = PyDict_GetItemString(kwds, "actionSlot");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.PlatformPlugin.notification(): got multiple values for keyword argument 'actionSlot'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!Shiboken::String::check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[4]))))
                    goto Sbk_Phonon_PlatformPluginFunc_notification_TypeError;
            }
        }
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QStringList cppArg2 = QStringList();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QObject* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        const char* cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // notification(const char*,QString,QStringList,QObject*,const char*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.notification()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->notification(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_PlatformPluginFunc_notification_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", unicode, QStringList = QStringList(), PySide.QtCore.QObject = None, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.PlatformPlugin.notification", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_objectDescriptionIndexes(PyObject* self, PyObject* pyArg)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: objectDescriptionIndexes(Phonon::ObjectDescriptionType)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX]), (pyArg)))) {
        overloadId = 0; // objectDescriptionIndexes(Phonon::ObjectDescriptionType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_objectDescriptionIndexes_TypeError;

    // Call function/method
    {
        ::Phonon::ObjectDescriptionType cppArg0 = ((::Phonon::ObjectDescriptionType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // objectDescriptionIndexes(Phonon::ObjectDescriptionType)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.objectDescriptionIndexes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->objectDescriptionIndexes(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_objectDescriptionIndexes_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.ObjectDescriptionType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.PlatformPlugin.objectDescriptionIndexes", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_objectDescriptionProperties(PyObject* self, PyObject* args)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "objectDescriptionProperties", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: objectDescriptionProperties(Phonon::ObjectDescriptionType,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_OBJECTDESCRIPTIONTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // objectDescriptionProperties(Phonon::ObjectDescriptionType,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_objectDescriptionProperties_TypeError;

    // Call function/method
    {
        ::Phonon::ObjectDescriptionType cppArg0 = ((::Phonon::ObjectDescriptionType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // objectDescriptionProperties(Phonon::ObjectDescriptionType,int)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.objectDescriptionProperties()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHash<QByteArray, QVariant > cppResult = const_cast<const ::Phonon::PlatformPlugin*>(cppSelf)->objectDescriptionProperties(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_PlatformPluginFunc_objectDescriptionProperties_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.ObjectDescriptionType, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.PlatformPlugin.objectDescriptionProperties", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_PlatformPluginFunc_saveVolume(PyObject* self, PyObject* args)
{
    ::Phonon::PlatformPlugin* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::PlatformPlugin*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "saveVolume", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: saveVolume(QString,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // saveVolume(QString,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_PlatformPluginFunc_saveVolume_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // saveVolume(QString,qreal)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'PlatformPlugin.saveVolume()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->saveVolume(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_PlatformPluginFunc_saveVolume_TypeError:
        const char* overloads[] = {"unicode, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.PlatformPlugin.saveVolume", overloads);
        return 0;
}

static PyMethodDef Sbk_Phonon_PlatformPlugin_methods[] = {
    {"applicationName", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_applicationName, METH_NOARGS},
    {"createBackend", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_createBackend, METH_VARARGS},
    {"createMediaStream", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_createMediaStream, METH_VARARGS},
    {"deviceAccessListFor", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_deviceAccessListFor, METH_O},
    {"icon", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_icon, METH_O},
    {"isMimeTypeAvailable", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_isMimeTypeAvailable, METH_O},
    {"loadVolume", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_loadVolume, METH_O},
    {"notification", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_notification, METH_VARARGS|METH_KEYWORDS},
    {"objectDescriptionIndexes", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_objectDescriptionIndexes, METH_O},
    {"objectDescriptionProperties", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_objectDescriptionProperties, METH_VARARGS},
    {"saveVolume", (PyCFunction)Sbk_Phonon_PlatformPluginFunc_saveVolume, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_PlatformPlugin_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_PlatformPlugin_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_PlatformPlugin_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.PlatformPlugin",
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
    /*tp_traverse*/         Sbk_Phonon_PlatformPlugin_traverse,
    /*tp_clear*/            Sbk_Phonon_PlatformPlugin_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_PlatformPlugin_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_PlatformPlugin_Init,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PlatformPlugin_PythonToCpp_PlatformPlugin_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_PlatformPlugin_Type, pyIn, cppOut);
}
static PythonToCppFunc is_PlatformPlugin_PythonToCpp_PlatformPlugin_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_PlatformPlugin_Type))
        return PlatformPlugin_PythonToCpp_PlatformPlugin_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PlatformPlugin_PTR_CppToPython_PlatformPlugin(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::PlatformPlugin*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_PlatformPlugin_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_PlatformPlugin(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_PLATFORMPLUGIN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_PlatformPlugin_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "PlatformPlugin", "Phonon::PlatformPlugin*",
        &Sbk_Phonon_PlatformPlugin_Type, &Shiboken::callCppDestructor< ::Phonon::PlatformPlugin >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_PlatformPlugin_Type,
        PlatformPlugin_PythonToCpp_PlatformPlugin_PTR,
        is_PlatformPlugin_PythonToCpp_PlatformPlugin_PTR_Convertible,
        PlatformPlugin_PTR_CppToPython_PlatformPlugin);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::PlatformPlugin");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::PlatformPlugin*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::PlatformPlugin&");
    Shiboken::Conversions::registerConverterName(converter, "PlatformPlugin");
    Shiboken::Conversions::registerConverterName(converter, "PlatformPlugin*");
    Shiboken::Conversions::registerConverterName(converter, "PlatformPlugin&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::PlatformPlugin).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PlatformPluginWrapper).name());



}
