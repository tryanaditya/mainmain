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
#include "pyside_qtmultimedia_python.h"

#include "qaudioenginefactoryinterface_wrapper.h"

// Extra includes
#include <QList>
#include <qaudioengine.h>
#include <qaudioformat.h>
#include <qbytearray.h>


// Native ---------------------------------------------------------

QAudioEngineFactoryInterfaceWrapper::QAudioEngineFactoryInterfaceWrapper() : QAudioEngineFactoryInterface() {
    // ... middle
}

QList<QByteArray > QAudioEngineFactoryInterfaceWrapper::availableDevices(QAudio::Mode arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<QByteArray >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "availableDevices"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.availableDevices()' not implemented.");
        return ::QList<QByteArray >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QList<QByteArray >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAudioEngineFactoryInterface.availableDevices", "list", pyResult->ob_type->tp_name);
        return ::QList<QByteArray >();
    }
    ::QList<QByteArray > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAbstractAudioDeviceInfo * QAudioEngineFactoryInterfaceWrapper::createDeviceInfo(const QByteArray & device, QAudio::Mode mode)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractAudioDeviceInfo*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createDeviceInfo"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createDeviceInfo()' not implemented.");
        return ((::QAbstractAudioDeviceInfo*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &device),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]), &mode)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractAudioDeviceInfo*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAudioEngineFactoryInterface.createDeviceInfo", Shiboken::SbkType< QAbstractAudioDeviceInfo >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractAudioDeviceInfo*)0);
    }
    ::QAbstractAudioDeviceInfo* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAbstractAudioInput * QAudioEngineFactoryInterfaceWrapper::createInput(const QByteArray & device, const QAudioFormat & format)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractAudioInput*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createInput"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createInput()' not implemented.");
        return ((::QAbstractAudioInput*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &device),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractAudioInput*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIOINPUT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAudioEngineFactoryInterface.createInput", Shiboken::SbkType< QAbstractAudioInput >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractAudioInput*)0);
    }
    ::QAbstractAudioInput* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAbstractAudioOutput * QAudioEngineFactoryInterfaceWrapper::createOutput(const QByteArray & device, const QAudioFormat & format)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QAbstractAudioOutput*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createOutput"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createOutput()' not implemented.");
        return ((::QAbstractAudioOutput*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &device),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], &format)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QAbstractAudioOutput*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIOOUTPUT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAudioEngineFactoryInterface.createOutput", Shiboken::SbkType< QAbstractAudioOutput >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QAbstractAudioOutput*)0);
    }
    ::QAbstractAudioOutput* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStringList QAudioEngineFactoryInterfaceWrapper::keys() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keys"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.keys()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAudioEngineFactoryInterface.keys", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAudioEngineFactoryInterfaceWrapper::~QAudioEngineFactoryInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAudioEngineFactoryInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAudioEngineFactoryInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAudioEngineFactoryInterface >()))
        return -1;

    ::QAudioEngineFactoryInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QAudioEngineFactoryInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QAudioEngineFactoryInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAudioEngineFactoryInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QAudioEngineFactoryInterfaceFunc_availableDevices(PyObject* self, PyObject* pyArg)
{
    ::QAudioEngineFactoryInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioEngineFactoryInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: availableDevices(QAudio::Mode)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]), (pyArg)))) {
        overloadId = 0; // availableDevices(QAudio::Mode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioEngineFactoryInterfaceFunc_availableDevices_TypeError;

    // Call function/method
    {
        ::QAudio::Mode cppArg0 = ((::QAudio::Mode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // availableDevices(QAudio::Mode)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.availableDevices()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QAudioEngineFactoryInterface*>(cppSelf)->availableDevices(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtMultimediaTypeConverters[SBK_QTMULTIMEDIA_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioEngineFactoryInterfaceFunc_availableDevices_TypeError:
        const char* overloads[] = {"PySide.QtMultimedia.QAudio.Mode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtMultimedia.QAudioEngineFactoryInterface.availableDevices", overloads);
        return 0;
}

static PyObject* Sbk_QAudioEngineFactoryInterfaceFunc_createDeviceInfo(PyObject* self, PyObject* args)
{
    ::QAudioEngineFactoryInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioEngineFactoryInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDeviceInfo", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createDeviceInfo(QByteArray,QAudio::Mode)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtMultimediaTypes[SBK_QAUDIO_MODE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // createDeviceInfo(QByteArray,QAudio::Mode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioEngineFactoryInterfaceFunc_createDeviceInfo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QAudio::Mode cppArg1 = ((::QAudio::Mode)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDeviceInfo(QByteArray,QAudio::Mode)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createDeviceInfo()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractAudioDeviceInfo * cppResult = cppSelf->createDeviceInfo(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIODEVICEINFO_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioEngineFactoryInterfaceFunc_createDeviceInfo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtMultimedia.QAudio.Mode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createDeviceInfo", overloads);
        return 0;
}

static PyObject* Sbk_QAudioEngineFactoryInterfaceFunc_createInput(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAudioEngineFactoryInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioEngineFactoryInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createInput(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createInput(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:createInput", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createInput(QByteArray,QAudioFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createInput(QByteArray,QAudioFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArgs[1])))) {
            overloadId = 0; // createInput(QByteArray,QAudioFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioEngineFactoryInterfaceFunc_createInput_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createInput(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArgs[1]))))
                    goto Sbk_QAudioEngineFactoryInterfaceFunc_createInput_TypeError;
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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QAudioFormat cppArg1_local = QAudioFormat();
        ::QAudioFormat* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // createInput(QByteArray,QAudioFormat)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createInput()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractAudioInput * cppResult = cppSelf->createInput(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIOINPUT_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioEngineFactoryInterfaceFunc_createInput_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtMultimedia.QAudioFormat = QAudioFormat()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createInput", overloads);
        return 0;
}

static PyObject* Sbk_QAudioEngineFactoryInterfaceFunc_createOutput(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAudioEngineFactoryInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAudioEngineFactoryInterface*)Shiboken::Conversions::cppPointer(SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createOutput(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createOutput(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:createOutput", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createOutput(QByteArray,QAudioFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createOutput(QByteArray,QAudioFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArgs[1])))) {
            overloadId = 0; // createOutput(QByteArray,QAudioFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAudioEngineFactoryInterfaceFunc_createOutput_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createOutput(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], (pyArgs[1]))))
                    goto Sbk_QAudioEngineFactoryInterfaceFunc_createOutput_TypeError;
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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QAudioFormat cppArg1_local = QAudioFormat();
        ::QAudioFormat* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QAUDIOFORMAT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // createOutput(QByteArray,QAudioFormat)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAudioEngineFactoryInterface.createOutput()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractAudioOutput * cppResult = cppSelf->createOutput(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtMultimediaTypes[SBK_QABSTRACTAUDIOOUTPUT_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAudioEngineFactoryInterfaceFunc_createOutput_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, PySide.QtMultimedia.QAudioFormat = QAudioFormat()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtMultimedia.QAudioEngineFactoryInterface.createOutput", overloads);
        return 0;
}

static PyMethodDef Sbk_QAudioEngineFactoryInterface_methods[] = {
    {"availableDevices", (PyCFunction)Sbk_QAudioEngineFactoryInterfaceFunc_availableDevices, METH_O},
    {"createDeviceInfo", (PyCFunction)Sbk_QAudioEngineFactoryInterfaceFunc_createDeviceInfo, METH_VARARGS},
    {"createInput", (PyCFunction)Sbk_QAudioEngineFactoryInterfaceFunc_createInput, METH_VARARGS|METH_KEYWORDS},
    {"createOutput", (PyCFunction)Sbk_QAudioEngineFactoryInterfaceFunc_createOutput, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAudioEngineFactoryInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAudioEngineFactoryInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAudioEngineFactoryInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtMultimedia.QAudioEngineFactoryInterface",
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
    /*tp_traverse*/         Sbk_QAudioEngineFactoryInterface_traverse,
    /*tp_clear*/            Sbk_QAudioEngineFactoryInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAudioEngineFactoryInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAudioEngineFactoryInterface_Init,
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

static void* Sbk_QAudioEngineFactoryInterface_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QFactoryInterface >()))
        return dynamic_cast< ::QAudioEngineFactoryInterface*>(reinterpret_cast< ::QFactoryInterface*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAudioEngineFactoryInterface_PythonToCpp_QAudioEngineFactoryInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAudioEngineFactoryInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAudioEngineFactoryInterface_PythonToCpp_QAudioEngineFactoryInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAudioEngineFactoryInterface_Type))
        return QAudioEngineFactoryInterface_PythonToCpp_QAudioEngineFactoryInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAudioEngineFactoryInterface_PTR_CppToPython_QAudioEngineFactoryInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAudioEngineFactoryInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAudioEngineFactoryInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QAudioEngineFactoryInterface(PyObject* module)
{
    SbkPySide_QtMultimediaTypes[SBK_QAUDIOENGINEFACTORYINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAudioEngineFactoryInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAudioEngineFactoryInterface", "QAudioEngineFactoryInterface*",
        &Sbk_QAudioEngineFactoryInterface_Type, &Shiboken::callCppDestructor< ::QAudioEngineFactoryInterface >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFACTORYINTERFACE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAudioEngineFactoryInterface_Type,
        QAudioEngineFactoryInterface_PythonToCpp_QAudioEngineFactoryInterface_PTR,
        is_QAudioEngineFactoryInterface_PythonToCpp_QAudioEngineFactoryInterface_PTR_Convertible,
        QAudioEngineFactoryInterface_PTR_CppToPython_QAudioEngineFactoryInterface);

    Shiboken::Conversions::registerConverterName(converter, "QAudioEngineFactoryInterface");
    Shiboken::Conversions::registerConverterName(converter, "QAudioEngineFactoryInterface*");
    Shiboken::Conversions::registerConverterName(converter, "QAudioEngineFactoryInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAudioEngineFactoryInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAudioEngineFactoryInterfaceWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAudioEngineFactoryInterface_Type, &Sbk_QAudioEngineFactoryInterface_typeDiscovery);


}
