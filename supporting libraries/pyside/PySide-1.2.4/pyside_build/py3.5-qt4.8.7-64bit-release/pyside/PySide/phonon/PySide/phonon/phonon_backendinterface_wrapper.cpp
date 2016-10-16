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

#include "phonon_backendinterface_wrapper.h"

// Extra includes
#include <QList>
#include <QSet>
#include <pysideconversions.h>
#include <qbytearray.h>
#include <qobject.h>

using namespace Phonon;

// Native ---------------------------------------------------------

BackendInterfaceWrapper::BackendInterfaceWrapper() : Phonon::BackendInterface() {
    // ... middle
}

QStringList BackendInterfaceWrapper::availableMimeTypes() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "availableMimeTypes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.availableMimeTypes()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.availableMimeTypes", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool BackendInterfaceWrapper::connectNodes(QObject * arg__1, QObject * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNodes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.connectNodes()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.connectNodes", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QObject * BackendInterfaceWrapper::createObject(Phonon::BackendInterface::Class c, QObject * parent, const QList<QVariant > & args)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QObject*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createObject"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.createObject()' not implemented.");
        return ((::QObject*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX]), &c),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], parent),
        Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], &args)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.createObject", Shiboken::SbkType< QObject >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QObject*)0);
    }
    ::QObject* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool BackendInterfaceWrapper::disconnectNodes(QObject * arg__1, QObject * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNodes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.disconnectNodes()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.disconnectNodes", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool BackendInterfaceWrapper::endConnectionChange(QSet<QObject * > arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endConnectionChange"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.endConnectionChange()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX], &arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.endConnectionChange", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QList<int > BackendInterfaceWrapper::objectDescriptionIndexes(Phonon::ObjectDescriptionType type) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QList<int >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "objectDescriptionIndexes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.objectDescriptionIndexes()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.objectDescriptionIndexes", "list", pyResult->ob_type->tp_name);
        return ::QList<int >();
    }
    ::QList<int > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QHash<QByteArray, QVariant > BackendInterfaceWrapper::objectDescriptionProperties(Phonon::ObjectDescriptionType type, int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QHash<QByteArray, QVariant >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "objectDescriptionProperties"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.objectDescriptionProperties()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.objectDescriptionProperties", "hash", pyResult->ob_type->tp_name);
        return ::QHash<QByteArray, QVariant >();
    }
    ::QHash<QByteArray, QVariant > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool BackendInterfaceWrapper::startConnectionChange(QSet<QObject * > arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startConnectionChange"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.startConnectionChange()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX], &arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "BackendInterface.startConnectionChange", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

BackendInterfaceWrapper::~BackendInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_BackendInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::BackendInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::BackendInterface >()))
        return -1;

    ::BackendInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // BackendInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::BackendInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::BackendInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_availableMimeTypes(PyObject* self)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableMimeTypes()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.availableMimeTypes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::Phonon::BackendInterface*>(cppSelf)->availableMimeTypes();
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

static PyObject* Sbk_Phonon_BackendInterfaceFunc_connectNodes(PyObject* self, PyObject* args)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "connectNodes", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: connectNodes(QObject*,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // connectNodes(QObject*,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_connectNodes_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // connectNodes(QObject*,QObject*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.connectNodes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->connectNodes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_connectNodes_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.BackendInterface.connectNodes", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_createObject(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.BackendInterface.createObject(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.BackendInterface.createObject(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:createObject", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createObject(Phonon::BackendInterface::Class,QObject*,QList<QVariant>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // createObject(Phonon::BackendInterface::Class,QObject*,QList<QVariant>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[2])))) {
            overloadId = 0; // createObject(Phonon::BackendInterface::Class,QObject*,QList<QVariant>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_createObject_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "args");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.BackendInterface.createObject(): got multiple values for keyword argument 'args'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[2]))))
                    goto Sbk_Phonon_BackendInterfaceFunc_createObject_TypeError;
            }
        }
        ::Phonon::BackendInterface::Class cppArg0 = ((::Phonon::BackendInterface::Class)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QList<QVariant > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createObject(Phonon::BackendInterface::Class,QObject*,QList<QVariant>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.createObject()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = cppSelf->createObject(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_createObject_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::BackendInterface.Class, PySide.QtCore.QObject, list = QList< QVariant >()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.BackendInterface.createObject", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_disconnectNodes(PyObject* self, PyObject* args)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "disconnectNodes", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: disconnectNodes(QObject*,QObject*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 0; // disconnectNodes(QObject*,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_disconnectNodes_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QObject* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // disconnectNodes(QObject*,QObject*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.disconnectNodes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->disconnectNodes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_disconnectNodes_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.BackendInterface.disconnectNodes", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_endConnectionChange(PyObject* self, PyObject* pyArg)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endConnectionChange(QSet<QObject*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX], (pyArg)))) {
        overloadId = 0; // endConnectionChange(QSet<QObject*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_endConnectionChange_TypeError;

    // Call function/method
    {
        ::QSet<QObject * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // endConnectionChange(QSet<QObject*>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.endConnectionChange()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->endConnectionChange(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_endConnectionChange_TypeError:
        const char* overloads[] = {"QSet", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.BackendInterface.endConnectionChange", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_objectDescriptionIndexes(PyObject* self, PyObject* pyArg)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_objectDescriptionIndexes_TypeError;

    // Call function/method
    {
        ::Phonon::ObjectDescriptionType cppArg0 = ((::Phonon::ObjectDescriptionType)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // objectDescriptionIndexes(Phonon::ObjectDescriptionType)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.objectDescriptionIndexes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::Phonon::BackendInterface*>(cppSelf)->objectDescriptionIndexes(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_objectDescriptionIndexes_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.ObjectDescriptionType", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.BackendInterface.objectDescriptionIndexes", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_objectDescriptionProperties(PyObject* self, PyObject* args)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_objectDescriptionProperties_TypeError;

    // Call function/method
    {
        ::Phonon::ObjectDescriptionType cppArg0 = ((::Phonon::ObjectDescriptionType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // objectDescriptionProperties(Phonon::ObjectDescriptionType,int)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.objectDescriptionProperties()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QHash<QByteArray, QVariant > cppResult = const_cast<const ::Phonon::BackendInterface*>(cppSelf)->objectDescriptionProperties(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QHASH_QBYTEARRAY_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_objectDescriptionProperties_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon.ObjectDescriptionType, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.BackendInterface.objectDescriptionProperties", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_BackendInterfaceFunc_startConnectionChange(PyObject* self, PyObject* pyArg)
{
    ::Phonon::BackendInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::BackendInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startConnectionChange(QSet<QObject*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QSET_QOBJECTPTR_IDX], (pyArg)))) {
        overloadId = 0; // startConnectionChange(QSet<QObject*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_BackendInterfaceFunc_startConnectionChange_TypeError;

    // Call function/method
    {
        ::QSet<QObject * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // startConnectionChange(QSet<QObject*>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'BackendInterface.startConnectionChange()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->startConnectionChange(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_Phonon_BackendInterfaceFunc_startConnectionChange_TypeError:
        const char* overloads[] = {"QSet", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.BackendInterface.startConnectionChange", overloads);
        return 0;
}

static PyMethodDef Sbk_Phonon_BackendInterface_methods[] = {
    {"availableMimeTypes", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_availableMimeTypes, METH_NOARGS},
    {"connectNodes", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_connectNodes, METH_VARARGS},
    {"createObject", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_createObject, METH_VARARGS|METH_KEYWORDS},
    {"disconnectNodes", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_disconnectNodes, METH_VARARGS},
    {"endConnectionChange", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_endConnectionChange, METH_O},
    {"objectDescriptionIndexes", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_objectDescriptionIndexes, METH_O},
    {"objectDescriptionProperties", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_objectDescriptionProperties, METH_VARARGS},
    {"startConnectionChange", (PyCFunction)Sbk_Phonon_BackendInterfaceFunc_startConnectionChange, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_BackendInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_BackendInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_BackendInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.BackendInterface",
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
    /*tp_traverse*/         Sbk_Phonon_BackendInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_BackendInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_BackendInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_BackendInterface_Init,
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

// Python to C++ enum conversion.
static void Phonon_BackendInterface_Class_PythonToCpp_Phonon_BackendInterface_Class(PyObject* pyIn, void* cppOut) {
    *((::Phonon::BackendInterface::Class*)cppOut) = (::Phonon::BackendInterface::Class) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_BackendInterface_Class_PythonToCpp_Phonon_BackendInterface_Class_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX]))
        return Phonon_BackendInterface_Class_PythonToCpp_Phonon_BackendInterface_Class;
    return 0;
}
static PyObject* Phonon_BackendInterface_Class_CppToPython_Phonon_BackendInterface_Class(const void* cppIn) {
    int castCppIn = *((::Phonon::BackendInterface::Class*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void BackendInterface_PythonToCpp_BackendInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_BackendInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_BackendInterface_PythonToCpp_BackendInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_BackendInterface_Type))
        return BackendInterface_PythonToCpp_BackendInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* BackendInterface_PTR_CppToPython_BackendInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::BackendInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_BackendInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_BackendInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_BackendInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "BackendInterface", "Phonon::BackendInterface*",
        &Sbk_Phonon_BackendInterface_Type, &Shiboken::callCppDestructor< ::Phonon::BackendInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_BackendInterface_Type,
        BackendInterface_PythonToCpp_BackendInterface_PTR,
        is_BackendInterface_PythonToCpp_BackendInterface_PTR_Convertible,
        BackendInterface_PTR_CppToPython_BackendInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::BackendInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::BackendInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::BackendInterface&");
    Shiboken::Conversions::registerConverterName(converter, "BackendInterface");
    Shiboken::Conversions::registerConverterName(converter, "BackendInterface*");
    Shiboken::Conversions::registerConverterName(converter, "BackendInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::BackendInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::BackendInterfaceWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'Class'.
    SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_BackendInterface_Type,
        "Class",
        "PySide.phonon.Phonon.BackendInterface.Class",
        "Phonon::BackendInterface::Class");
    if (!SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "MediaObjectClass", (long) Phonon::BackendInterface::MediaObjectClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "VolumeFaderEffectClass", (long) Phonon::BackendInterface::VolumeFaderEffectClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "AudioOutputClass", (long) Phonon::BackendInterface::AudioOutputClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "AudioDataOutputClass", (long) Phonon::BackendInterface::AudioDataOutputClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "VisualizationClass", (long) Phonon::BackendInterface::VisualizationClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "VideoDataOutputClass", (long) Phonon::BackendInterface::VideoDataOutputClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "EffectClass", (long) Phonon::BackendInterface::EffectClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "VideoWidgetClass", (long) Phonon::BackendInterface::VideoWidgetClass))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
        &Sbk_Phonon_BackendInterface_Type, "VideoGraphicsObjectClass", (long) Phonon::BackendInterface::VideoGraphicsObjectClass))
        return ;
    // Register converter for enum 'Phonon::BackendInterface::Class'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX],
            Phonon_BackendInterface_Class_CppToPython_Phonon_BackendInterface_Class);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_BackendInterface_Class_PythonToCpp_Phonon_BackendInterface_Class,
            is_Phonon_BackendInterface_Class_PythonToCpp_Phonon_BackendInterface_Class_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_BACKENDINTERFACE_CLASS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::BackendInterface::Class");
        Shiboken::Conversions::registerConverterName(converter, "BackendInterface::Class");
        Shiboken::Conversions::registerConverterName(converter, "Class");
    }
    // End of 'Class' enum.


    qRegisterMetaType< ::Phonon::BackendInterface::Class >("BackendInterface::Class");
    qRegisterMetaType< ::Phonon::BackendInterface::Class >("Phonon::BackendInterface::Class");
}
