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
#include "pyside_qtcore_python.h"

#include "qmetaproperty_wrapper.h"

// Extra includes
#include <qmetaobject.h>
#include <qobject.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMetaProperty_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMetaProperty >()))
        return -1;

    ::QMetaProperty* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QMetaProperty", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QMetaProperty()
    // 1: QMetaProperty(QMetaProperty)
    if (numArgs == 0) {
        overloadId = 0; // QMetaProperty()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMetaProperty(QMetaProperty)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaProperty_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMetaProperty()
        {

            if (!PyErr_Occurred()) {
                // QMetaProperty()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaProperty();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QMetaProperty(const QMetaProperty & QMetaProperty)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QMetaProperty cppArg0_local = ::QMetaProperty();
            ::QMetaProperty* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QMetaProperty(QMetaProperty)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QMetaProperty(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMetaProperty >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMetaProperty_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QMetaProperty_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QMetaProperty", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty", overloads);
        return -1;
}

static PyObject* Sbk_QMetaPropertyFunc_enumerator(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enumerator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaEnum cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->enumerator();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaPropertyFunc_hasNotifySignal(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasNotifySignal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->hasNotifySignal();
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

static PyObject* Sbk_QMetaPropertyFunc_hasStdCppSet(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasStdCppSet()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->hasStdCppSet();
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

static PyObject* Sbk_QMetaPropertyFunc_isConstant(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isConstant()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isConstant();
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

static PyObject* Sbk_QMetaPropertyFunc_isDesignable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isDesignable(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:isDesignable", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isDesignable(const QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // isDesignable(const QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // isDesignable(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_isDesignable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "obj");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isDesignable(): got multiple values for keyword argument 'obj'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaPropertyFunc_isDesignable_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isDesignable(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isDesignable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_isDesignable_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.isDesignable", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_isEditable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isEditable(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:isEditable", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isEditable(const QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // isEditable(const QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // isEditable(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_isEditable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "obj");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isEditable(): got multiple values for keyword argument 'obj'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaPropertyFunc_isEditable_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isEditable(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isEditable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_isEditable_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.isEditable", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_isEnumType(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnumType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isEnumType();
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

static PyObject* Sbk_QMetaPropertyFunc_isFinal(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFinal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isFinal();
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

static PyObject* Sbk_QMetaPropertyFunc_isFlagType(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFlagType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isFlagType();
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

static PyObject* Sbk_QMetaPropertyFunc_isReadable(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isReadable();
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

static PyObject* Sbk_QMetaPropertyFunc_isResettable(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isResettable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isResettable();
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

static PyObject* Sbk_QMetaPropertyFunc_isScriptable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isScriptable(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:isScriptable", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isScriptable(const QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // isScriptable(const QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // isScriptable(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_isScriptable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "obj");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isScriptable(): got multiple values for keyword argument 'obj'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaPropertyFunc_isScriptable_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isScriptable(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isScriptable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_isScriptable_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.isScriptable", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_isStored(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isStored(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:isStored", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isStored(const QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // isStored(const QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // isStored(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_isStored_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "obj");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isStored(): got multiple values for keyword argument 'obj'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaPropertyFunc_isStored_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isStored(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isStored(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_isStored_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.isStored", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_isUser(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isUser(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:isUser", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: isUser(const QObject*)const
    if (numArgs == 0) {
        overloadId = 0; // isUser(const QObject*)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // isUser(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_isUser_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "obj");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaProperty.isUser(): got multiple values for keyword argument 'obj'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaPropertyFunc_isUser_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isUser(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isUser(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_isUser_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.isUser", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_isValid(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isValid();
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

static PyObject* Sbk_QMetaPropertyFunc_isWritable(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWritable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->isWritable();
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

static PyObject* Sbk_QMetaPropertyFunc_name(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->name();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaPropertyFunc_notifySignal(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notifySignal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->notifySignal();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaPropertyFunc_notifySignalIndex(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notifySignalIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->notifySignalIndex();
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

static PyObject* Sbk_QMetaPropertyFunc_propertyIndex(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->propertyIndex();
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

static PyObject* Sbk_QMetaPropertyFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(const QObject*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // read(const QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(const QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->read(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_read_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaProperty.read", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_reset(PyObject* self, PyObject* pyArg)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reset(QObject*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // reset(QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_reset_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reset(QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->reset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_reset_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaProperty.reset", overloads);
        return 0;
}

static PyObject* Sbk_QMetaPropertyFunc_revision(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // revision()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->revision();
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

static PyObject* Sbk_QMetaPropertyFunc_type(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant::Type cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaPropertyFunc_typeName(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // typeName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->typeName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaPropertyFunc_userType(PyObject* self)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->userType();
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

static PyObject* Sbk_QMetaPropertyFunc_write(PyObject* self, PyObject* args)
{
    ::QMetaProperty* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "write", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: write(QObject*,QVariant)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // write(QObject*,QVariant)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaPropertyFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // write(QObject*,QVariant)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMetaProperty*>(cppSelf)->write(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaPropertyFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaProperty.write", overloads);
        return 0;
}

static PyObject* Sbk_QMetaProperty___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QMetaProperty& cppSelf = *(((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMetaProperty_methods[] = {
    {"enumerator", (PyCFunction)Sbk_QMetaPropertyFunc_enumerator, METH_NOARGS},
    {"hasNotifySignal", (PyCFunction)Sbk_QMetaPropertyFunc_hasNotifySignal, METH_NOARGS},
    {"hasStdCppSet", (PyCFunction)Sbk_QMetaPropertyFunc_hasStdCppSet, METH_NOARGS},
    {"isConstant", (PyCFunction)Sbk_QMetaPropertyFunc_isConstant, METH_NOARGS},
    {"isDesignable", (PyCFunction)Sbk_QMetaPropertyFunc_isDesignable, METH_VARARGS|METH_KEYWORDS},
    {"isEditable", (PyCFunction)Sbk_QMetaPropertyFunc_isEditable, METH_VARARGS|METH_KEYWORDS},
    {"isEnumType", (PyCFunction)Sbk_QMetaPropertyFunc_isEnumType, METH_NOARGS},
    {"isFinal", (PyCFunction)Sbk_QMetaPropertyFunc_isFinal, METH_NOARGS},
    {"isFlagType", (PyCFunction)Sbk_QMetaPropertyFunc_isFlagType, METH_NOARGS},
    {"isReadable", (PyCFunction)Sbk_QMetaPropertyFunc_isReadable, METH_NOARGS},
    {"isResettable", (PyCFunction)Sbk_QMetaPropertyFunc_isResettable, METH_NOARGS},
    {"isScriptable", (PyCFunction)Sbk_QMetaPropertyFunc_isScriptable, METH_VARARGS|METH_KEYWORDS},
    {"isStored", (PyCFunction)Sbk_QMetaPropertyFunc_isStored, METH_VARARGS|METH_KEYWORDS},
    {"isUser", (PyCFunction)Sbk_QMetaPropertyFunc_isUser, METH_VARARGS|METH_KEYWORDS},
    {"isValid", (PyCFunction)Sbk_QMetaPropertyFunc_isValid, METH_NOARGS},
    {"isWritable", (PyCFunction)Sbk_QMetaPropertyFunc_isWritable, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QMetaPropertyFunc_name, METH_NOARGS},
    {"notifySignal", (PyCFunction)Sbk_QMetaPropertyFunc_notifySignal, METH_NOARGS},
    {"notifySignalIndex", (PyCFunction)Sbk_QMetaPropertyFunc_notifySignalIndex, METH_NOARGS},
    {"propertyIndex", (PyCFunction)Sbk_QMetaPropertyFunc_propertyIndex, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QMetaPropertyFunc_read, METH_O},
    {"reset", (PyCFunction)Sbk_QMetaPropertyFunc_reset, METH_O},
    {"revision", (PyCFunction)Sbk_QMetaPropertyFunc_revision, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QMetaPropertyFunc_type, METH_NOARGS},
    {"typeName", (PyCFunction)Sbk_QMetaPropertyFunc_typeName, METH_NOARGS},
    {"userType", (PyCFunction)Sbk_QMetaPropertyFunc_userType, METH_NOARGS},
    {"write", (PyCFunction)Sbk_QMetaPropertyFunc_write, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QMetaProperty___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMetaProperty_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMetaProperty_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMetaProperty_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMetaProperty",
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
    /*tp_traverse*/         Sbk_QMetaProperty_traverse,
    /*tp_clear*/            Sbk_QMetaProperty_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMetaProperty_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMetaProperty_Init,
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
static void QMetaProperty_PythonToCpp_QMetaProperty_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMetaProperty_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMetaProperty_PythonToCpp_QMetaProperty_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaProperty_Type))
        return QMetaProperty_PythonToCpp_QMetaProperty_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMetaProperty_PTR_CppToPython_QMetaProperty(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMetaProperty*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMetaProperty_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QMetaProperty_COPY_CppToPython_QMetaProperty(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QMetaProperty_Type, new ::QMetaProperty(*((::QMetaProperty*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QMetaProperty_PythonToCpp_QMetaProperty_COPY(PyObject* pyIn, void* cppOut) {
    *((::QMetaProperty*)cppOut) = *((::QMetaProperty*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QMetaProperty_PythonToCpp_QMetaProperty_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaProperty_Type))
        return QMetaProperty_PythonToCpp_QMetaProperty_COPY;
    return 0;
}

void init_QMetaProperty(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMetaProperty_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMetaProperty", "QMetaProperty",
        &Sbk_QMetaProperty_Type, &Shiboken::callCppDestructor< ::QMetaProperty >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMetaProperty_Type,
        QMetaProperty_PythonToCpp_QMetaProperty_PTR,
        is_QMetaProperty_PythonToCpp_QMetaProperty_PTR_Convertible,
        QMetaProperty_PTR_CppToPython_QMetaProperty,
        QMetaProperty_COPY_CppToPython_QMetaProperty);

    Shiboken::Conversions::registerConverterName(converter, "QMetaProperty");
    Shiboken::Conversions::registerConverterName(converter, "QMetaProperty*");
    Shiboken::Conversions::registerConverterName(converter, "QMetaProperty&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMetaProperty).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QMetaProperty_PythonToCpp_QMetaProperty_COPY,
        is_QMetaProperty_PythonToCpp_QMetaProperty_COPY_Convertible);


    qRegisterMetaType< ::QMetaProperty >("QMetaProperty");
}
