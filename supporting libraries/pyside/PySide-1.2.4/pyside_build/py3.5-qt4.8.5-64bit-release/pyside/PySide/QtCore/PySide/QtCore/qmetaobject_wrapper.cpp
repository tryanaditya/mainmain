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

#include "qmetaobject_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMetaObject_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMetaObject >()))
        return -1;

    ::QMetaObject* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QMetaObject()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QMetaObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMetaObject >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QMetaObjectFunc_cast(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cast(QObject*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // cast(QObject*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_cast_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cast(QObject*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QMetaObject*>(cppSelf)->cast(cppArg0);
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

    Sbk_QMetaObjectFunc_cast_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.cast", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_checkConnectArgs(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "checkConnectArgs", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: checkConnectArgs(const char*,const char*)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        overloadId = 0; // checkConnectArgs(const char*,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_checkConnectArgs_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        const char* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // checkConnectArgs(const char*,const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QMetaObject::checkConnectArgs(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_checkConnectArgs_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaObject.checkConnectArgs", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_classInfo(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: classInfo(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // classInfo(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_classInfo_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // classInfo(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaClassInfo cppResult = const_cast<const ::QMetaObject*>(cppSelf)->classInfo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETACLASSINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_classInfo_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.classInfo", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_classInfoCount(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // classInfoCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->classInfoCount();
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

static PyObject* Sbk_QMetaObjectFunc_classInfoOffset(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // classInfoOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->classInfoOffset();
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

static PyObject* Sbk_QMetaObjectFunc_className(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // className()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = const_cast<const ::QMetaObject*>(cppSelf)->className();
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

static PyObject* Sbk_QMetaObjectFunc_connectSlotsByName(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: connectSlotsByName(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // connectSlotsByName(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_connectSlotsByName_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // connectSlotsByName(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QMetaObject::connectSlotsByName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMetaObjectFunc_connectSlotsByName_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.connectSlotsByName", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_constructor(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: constructor(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // constructor(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_constructor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // constructor(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod cppResult = const_cast<const ::QMetaObject*>(cppSelf)->constructor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_constructor_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.constructor", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_constructorCount(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // constructorCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->constructorCount();
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

static PyObject* Sbk_QMetaObjectFunc_disconnect(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "disconnect", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: disconnect(const QObject*,int,const QObject*,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 0; // disconnect(const QObject*,int,const QObject*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_disconnect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QObject* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // disconnect(const QObject*,int,const QObject*,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QMetaObject::disconnect(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_disconnect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, int, PySide.QtCore.QObject, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaObject.disconnect", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_enumerator(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: enumerator(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // enumerator(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_enumerator_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // enumerator(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaEnum cppResult = const_cast<const ::QMetaObject*>(cppSelf)->enumerator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAENUM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_enumerator_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.enumerator", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_enumeratorCount(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enumeratorCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->enumeratorCount();
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

static PyObject* Sbk_QMetaObjectFunc_enumeratorOffset(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // enumeratorOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->enumeratorOffset();
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

static PyObject* Sbk_QMetaObjectFunc_indexOfClassInfo(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfClassInfo(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfClassInfo(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfClassInfo_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfClassInfo(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfClassInfo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfClassInfo_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfClassInfo", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfConstructor(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfConstructor(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfConstructor(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfConstructor_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfConstructor(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfConstructor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfConstructor_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfConstructor", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfEnumerator(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfEnumerator(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfEnumerator(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfEnumerator_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfEnumerator(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfEnumerator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfEnumerator_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfEnumerator", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfMethod(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfMethod(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfMethod(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfMethod_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfMethod(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfMethod(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfMethod_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfMethod", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfProperty(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfProperty(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfProperty(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfProperty_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfProperty(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfProperty_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfProperty", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfSignal(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfSignal(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfSignal(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfSignal_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfSignal(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfSignal(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfSignal_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfSignal", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_indexOfSlot(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfSlot(const char*)const
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // indexOfSlot(const char*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_indexOfSlot_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfSlot(const char*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->indexOfSlot(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_indexOfSlot_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.indexOfSlot", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_invokeMethod(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 14) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOOOOOOO:invokeMethod", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10]), &(pyArgs[11]), &(pyArgs[12]), &(pyArgs[13])))
        return 0;


    // Overloaded function decisor
    // 0: invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
    // 1: invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
    // 2: invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
    // 3: invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CONNECTIONTYPE_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                        if (numArgs == 6) {
                            overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                            if (numArgs == 7) {
                                overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                if (numArgs == 8) {
                                    overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                    if (numArgs == 9) {
                                        overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                    } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                        if (numArgs == 10) {
                                            overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                        } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                            if (numArgs == 11) {
                                                overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                            } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                if (numArgs == 12) {
                                                    overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                } else if ((pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12])))) {
                                                    if (numArgs == 13) {
                                                        overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                    } else if ((pythonToCpp[13] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[13])))) {
                                                        overloadId = 2; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                        if (numArgs == 6) {
                            overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                            if (numArgs == 7) {
                                overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                if (numArgs == 8) {
                                    overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                    if (numArgs == 9) {
                                        overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                    } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                        if (numArgs == 10) {
                                            overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                        } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                            if (numArgs == 11) {
                                                overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                            } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                if (numArgs == 12) {
                                                    overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                } else if ((pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12])))) {
                                                    overloadId = 3; // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICRETURNARGUMENT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                        if (numArgs == 6) {
                            overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                            if (numArgs == 7) {
                                overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                if (numArgs == 8) {
                                    overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                    if (numArgs == 9) {
                                        overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                    } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                        if (numArgs == 10) {
                                            overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                        } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                            if (numArgs == 11) {
                                                overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                            } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                if (numArgs == 12) {
                                                    overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                } else if ((pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12])))) {
                                                    overloadId = 1; // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                        if (numArgs == 6) {
                            overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                            if (numArgs == 7) {
                                overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                            } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                if (numArgs == 8) {
                                    overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                    if (numArgs == 9) {
                                        overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                    } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                        if (numArgs == 10) {
                                            overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                        } else if ((pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10])))) {
                                            if (numArgs == 11) {
                                                overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                            } else if ((pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11])))) {
                                                overloadId = 0; // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // invokeMethod(QObject * obj, const char * member, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericArgument cppArg2 = QGenericArgument(0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);

            if (!PyErr_Occurred()) {
                // invokeMethod(QObject*,const char*,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QMetaObject::invokeMethod(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // invokeMethod(QObject * obj, const char * member, QGenericReturnArgument ret, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[12]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[12] = value;
                    if (!(pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QGenericReturnArgument cppArg2 = ::QGenericReturnArgument(((char*)0), ((void*)0));
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);
            if (!Shiboken::Object::isValid(pyArgs[12]))
                return 0;
            ::QGenericArgument cppArg12 = QGenericArgument();
            if (pythonToCpp[12]) pythonToCpp[12](pyArgs[12], &cppArg12);

            if (!PyErr_Occurred()) {
                // invokeMethod(QObject*,const char*,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QMetaObject::invokeMethod(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // invokeMethod(QObject * obj, const char * member, Qt::ConnectionType arg__3, QGenericReturnArgument ret, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[12]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[12] = value;
                    if (!(pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[13]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[13] = value;
                    if (!(pythonToCpp[13] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[13]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::ConnectionType cppArg2 = ((::Qt::ConnectionType)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericReturnArgument cppArg3 = ::QGenericReturnArgument(((char*)0), ((void*)0));
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument(0);
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);
            if (!Shiboken::Object::isValid(pyArgs[12]))
                return 0;
            ::QGenericArgument cppArg12 = QGenericArgument();
            if (pythonToCpp[12]) pythonToCpp[12](pyArgs[12], &cppArg12);
            if (!Shiboken::Object::isValid(pyArgs[13]))
                return 0;
            ::QGenericArgument cppArg13 = QGenericArgument();
            if (pythonToCpp[13]) pythonToCpp[13](pyArgs[13], &cppArg13);

            if (!PyErr_Occurred()) {
                // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericReturnArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QMetaObject::invokeMethod(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12, cppArg13);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 3: // invokeMethod(QObject * obj, const char * member, Qt::ConnectionType type, QGenericArgument val0, QGenericArgument val1, QGenericArgument val2, QGenericArgument val3, QGenericArgument val4, QGenericArgument val5, QGenericArgument val6, QGenericArgument val7, QGenericArgument val8, QGenericArgument val9)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val0");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val0'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val1");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val1'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val2");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val2'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val3");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val3'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val4");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val4'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val5");
                if (value && pyArgs[8]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val5'.");
                    return 0;
                } else if (value) {
                    pyArgs[8] = value;
                    if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val6");
                if (value && pyArgs[9]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val6'.");
                    return 0;
                } else if (value) {
                    pyArgs[9] = value;
                    if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val7");
                if (value && pyArgs[10]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val7'.");
                    return 0;
                } else if (value) {
                    pyArgs[10] = value;
                    if (!(pythonToCpp[10] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[10]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val8");
                if (value && pyArgs[11]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val8'.");
                    return 0;
                } else if (value) {
                    pyArgs[11] = value;
                    if (!(pythonToCpp[11] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[11]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
                value = PyDict_GetItemString(kwds, "val9");
                if (value && pyArgs[12]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.invokeMethod(): got multiple values for keyword argument 'val9'.");
                    return 0;
                } else if (value) {
                    pyArgs[12] = value;
                    if (!(pythonToCpp[12] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[12]))))
                        goto Sbk_QMetaObjectFunc_invokeMethod_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::ConnectionType cppArg2 = ((::Qt::ConnectionType)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QGenericArgument cppArg3 = QGenericArgument(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QGenericArgument cppArg4 = QGenericArgument();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QGenericArgument cppArg5 = QGenericArgument();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QGenericArgument cppArg6 = QGenericArgument();
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            if (!Shiboken::Object::isValid(pyArgs[7]))
                return 0;
            ::QGenericArgument cppArg7 = QGenericArgument();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
            if (!Shiboken::Object::isValid(pyArgs[8]))
                return 0;
            ::QGenericArgument cppArg8 = QGenericArgument();
            if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
            if (!Shiboken::Object::isValid(pyArgs[9]))
                return 0;
            ::QGenericArgument cppArg9 = QGenericArgument();
            if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);
            if (!Shiboken::Object::isValid(pyArgs[10]))
                return 0;
            ::QGenericArgument cppArg10 = QGenericArgument();
            if (pythonToCpp[10]) pythonToCpp[10](pyArgs[10], &cppArg10);
            if (!Shiboken::Object::isValid(pyArgs[11]))
                return 0;
            ::QGenericArgument cppArg11 = QGenericArgument();
            if (pythonToCpp[11]) pythonToCpp[11](pyArgs[11], &cppArg11);
            if (!Shiboken::Object::isValid(pyArgs[12]))
                return 0;
            ::QGenericArgument cppArg12 = QGenericArgument();
            if (pythonToCpp[12]) pythonToCpp[12](pyArgs[12], &cppArg12);

            if (!PyErr_Occurred()) {
                // invokeMethod(QObject*,const char*,Qt::ConnectionType,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QMetaObject::invokeMethod(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10, cppArg11, cppArg12);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_invokeMethod_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.QGenericReturnArgument, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.Qt.ConnectionType, PySide.QtCore.QGenericReturnArgument, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", "PySide.QtCore.QObject, " SBK_STR_NAME ", PySide.QtCore.Qt.ConnectionType, PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaObject.invokeMethod", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_method(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: method(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // method(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_method_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // method(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaMethod cppResult = const_cast<const ::QMetaObject*>(cppSelf)->method(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAMETHOD_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_method_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.method", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_methodCount(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // methodCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->methodCount();
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

static PyObject* Sbk_QMetaObjectFunc_methodOffset(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // methodOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->methodOffset();
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

static PyObject* Sbk_QMetaObjectFunc_newInstance(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 10) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOOO:newInstance", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9])))
        return 0;


    // Overloaded function decisor
    // 0: newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    if (numArgs == 0) {
        overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5])))) {
                            if (numArgs == 6) {
                                overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6])))) {
                                if (numArgs == 7) {
                                    overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7])))) {
                                    if (numArgs == 8) {
                                        overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                    } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8])))) {
                                        if (numArgs == 9) {
                                            overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        } else if ((pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9])))) {
                                            overloadId = 0; // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_newInstance_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "val0");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val0'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[0]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val1");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val1'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[1]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val2");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val2'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[2]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val3");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val3'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[3]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val4");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val4'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[4]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val5");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val5'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[5]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val6");
            if (value && pyArgs[6]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val6'.");
                return 0;
            } else if (value) {
                pyArgs[6] = value;
                if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[6]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val7");
            if (value && pyArgs[7]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val7'.");
                return 0;
            } else if (value) {
                pyArgs[7] = value;
                if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[7]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val8");
            if (value && pyArgs[8]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val8'.");
                return 0;
            } else if (value) {
                pyArgs[8] = value;
                if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[8]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
            value = PyDict_GetItemString(kwds, "val9");
            if (value && pyArgs[9]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QMetaObject.newInstance(): got multiple values for keyword argument 'val9'.");
                return 0;
            } else if (value) {
                pyArgs[9] = value;
                if (!(pythonToCpp[9] = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QGENERICARGUMENT_IDX], (pyArgs[9]))))
                    goto Sbk_QMetaObjectFunc_newInstance_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGenericArgument cppArg0 = QGenericArgument(0);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QGenericArgument cppArg1 = QGenericArgument();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QGenericArgument cppArg2 = QGenericArgument();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QGenericArgument cppArg3 = QGenericArgument();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QGenericArgument cppArg4 = QGenericArgument();
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        if (!Shiboken::Object::isValid(pyArgs[5]))
            return 0;
        ::QGenericArgument cppArg5 = QGenericArgument();
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
        if (!Shiboken::Object::isValid(pyArgs[6]))
            return 0;
        ::QGenericArgument cppArg6 = QGenericArgument();
        if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
        if (!Shiboken::Object::isValid(pyArgs[7]))
            return 0;
        ::QGenericArgument cppArg7 = QGenericArgument();
        if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);
        if (!Shiboken::Object::isValid(pyArgs[8]))
            return 0;
        ::QGenericArgument cppArg8 = QGenericArgument();
        if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);
        if (!Shiboken::Object::isValid(pyArgs[9]))
            return 0;
        ::QGenericArgument cppArg9 = QGenericArgument();
        if (pythonToCpp[9]) pythonToCpp[9](pyArgs[9], &cppArg9);

        if (!PyErr_Occurred()) {
            // newInstance(QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument,QGenericArgument)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QMetaObject*>(cppSelf)->newInstance(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9);
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

    Sbk_QMetaObjectFunc_newInstance_TypeError:
        const char* overloads[] = {"PySide.QtCore.QGenericArgument = QGenericArgument(0), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument(), PySide.QtCore.QGenericArgument = QGenericArgument()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QMetaObject.newInstance", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_normalizedSignature(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: normalizedSignature(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // normalizedSignature(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_normalizedSignature_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // normalizedSignature(const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QMetaObject::normalizedSignature(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_normalizedSignature_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.normalizedSignature", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_normalizedType(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: normalizedType(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // normalizedType(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_normalizedType_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // normalizedType(const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QMetaObject::normalizedType(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_normalizedType_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.normalizedType", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // property(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMetaObjectFunc_property_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaProperty cppResult = const_cast<const ::QMetaObject*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMetaObjectFunc_property_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QMetaObject.property", overloads);
        return 0;
}

static PyObject* Sbk_QMetaObjectFunc_propertyCount(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->propertyCount();
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

static PyObject* Sbk_QMetaObjectFunc_propertyOffset(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // propertyOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QMetaObject*>(cppSelf)->propertyOffset();
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

static PyObject* Sbk_QMetaObjectFunc_superClass(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // superClass()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMetaObject * cppResult = const_cast<const ::QMetaObject*>(cppSelf)->superClass();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMetaObjectFunc_userProperty(PyObject* self)
{
    ::QMetaObject* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMetaObject*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // userProperty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMetaProperty cppResult = const_cast<const ::QMetaObject*>(cppSelf)->userProperty();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAPROPERTY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QMetaObject_methods[] = {
    {"cast", (PyCFunction)Sbk_QMetaObjectFunc_cast, METH_O},
    {"checkConnectArgs", (PyCFunction)Sbk_QMetaObjectFunc_checkConnectArgs, METH_VARARGS|METH_STATIC},
    {"classInfo", (PyCFunction)Sbk_QMetaObjectFunc_classInfo, METH_O},
    {"classInfoCount", (PyCFunction)Sbk_QMetaObjectFunc_classInfoCount, METH_NOARGS},
    {"classInfoOffset", (PyCFunction)Sbk_QMetaObjectFunc_classInfoOffset, METH_NOARGS},
    {"className", (PyCFunction)Sbk_QMetaObjectFunc_className, METH_NOARGS},
    {"connectSlotsByName", (PyCFunction)Sbk_QMetaObjectFunc_connectSlotsByName, METH_O|METH_STATIC},
    {"constructor", (PyCFunction)Sbk_QMetaObjectFunc_constructor, METH_O},
    {"constructorCount", (PyCFunction)Sbk_QMetaObjectFunc_constructorCount, METH_NOARGS},
    {"disconnect", (PyCFunction)Sbk_QMetaObjectFunc_disconnect, METH_VARARGS|METH_STATIC},
    {"enumerator", (PyCFunction)Sbk_QMetaObjectFunc_enumerator, METH_O},
    {"enumeratorCount", (PyCFunction)Sbk_QMetaObjectFunc_enumeratorCount, METH_NOARGS},
    {"enumeratorOffset", (PyCFunction)Sbk_QMetaObjectFunc_enumeratorOffset, METH_NOARGS},
    {"indexOfClassInfo", (PyCFunction)Sbk_QMetaObjectFunc_indexOfClassInfo, METH_O},
    {"indexOfConstructor", (PyCFunction)Sbk_QMetaObjectFunc_indexOfConstructor, METH_O},
    {"indexOfEnumerator", (PyCFunction)Sbk_QMetaObjectFunc_indexOfEnumerator, METH_O},
    {"indexOfMethod", (PyCFunction)Sbk_QMetaObjectFunc_indexOfMethod, METH_O},
    {"indexOfProperty", (PyCFunction)Sbk_QMetaObjectFunc_indexOfProperty, METH_O},
    {"indexOfSignal", (PyCFunction)Sbk_QMetaObjectFunc_indexOfSignal, METH_O},
    {"indexOfSlot", (PyCFunction)Sbk_QMetaObjectFunc_indexOfSlot, METH_O},
    {"invokeMethod", (PyCFunction)Sbk_QMetaObjectFunc_invokeMethod, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"method", (PyCFunction)Sbk_QMetaObjectFunc_method, METH_O},
    {"methodCount", (PyCFunction)Sbk_QMetaObjectFunc_methodCount, METH_NOARGS},
    {"methodOffset", (PyCFunction)Sbk_QMetaObjectFunc_methodOffset, METH_NOARGS},
    {"newInstance", (PyCFunction)Sbk_QMetaObjectFunc_newInstance, METH_VARARGS|METH_KEYWORDS},
    {"normalizedSignature", (PyCFunction)Sbk_QMetaObjectFunc_normalizedSignature, METH_O|METH_STATIC},
    {"normalizedType", (PyCFunction)Sbk_QMetaObjectFunc_normalizedType, METH_O|METH_STATIC},
    {"property", (PyCFunction)Sbk_QMetaObjectFunc_property, METH_O},
    {"propertyCount", (PyCFunction)Sbk_QMetaObjectFunc_propertyCount, METH_NOARGS},
    {"propertyOffset", (PyCFunction)Sbk_QMetaObjectFunc_propertyOffset, METH_NOARGS},
    {"superClass", (PyCFunction)Sbk_QMetaObjectFunc_superClass, METH_NOARGS},
    {"userProperty", (PyCFunction)Sbk_QMetaObjectFunc_userProperty, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMetaObject_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMetaObject_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QMetaObject_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QMetaObject",
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
    /*tp_traverse*/         Sbk_QMetaObject_traverse,
    /*tp_clear*/            Sbk_QMetaObject_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMetaObject_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMetaObject_Init,
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
static void QMetaObject_Call_PythonToCpp_QMetaObject_Call(PyObject* pyIn, void* cppOut) {
    *((::QMetaObject::Call*)cppOut) = (::QMetaObject::Call) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMetaObject_Call_PythonToCpp_QMetaObject_Call_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX]))
        return QMetaObject_Call_PythonToCpp_QMetaObject_Call;
    return 0;
}
static PyObject* QMetaObject_Call_CppToPython_QMetaObject_Call(const void* cppIn) {
    int castCppIn = *((::QMetaObject::Call*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMetaObject_PythonToCpp_QMetaObject_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMetaObject_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMetaObject_PythonToCpp_QMetaObject_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMetaObject_Type))
        return QMetaObject_PythonToCpp_QMetaObject_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMetaObject_PTR_CppToPython_QMetaObject(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QMetaObject*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QMetaObject_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QMetaObject(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMetaObject_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMetaObject", "QMetaObject*",
        &Sbk_QMetaObject_Type, &Shiboken::callCppDestructor< ::QMetaObject >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMetaObject_Type,
        QMetaObject_PythonToCpp_QMetaObject_PTR,
        is_QMetaObject_PythonToCpp_QMetaObject_PTR_Convertible,
        QMetaObject_PTR_CppToPython_QMetaObject);

    Shiboken::Conversions::registerConverterName(converter, "QMetaObject");
    Shiboken::Conversions::registerConverterName(converter, "QMetaObject*");
    Shiboken::Conversions::registerConverterName(converter, "QMetaObject&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMetaObject).name());


    // Initialization of enums.

    // Initialization of enum 'Call'.
    SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMetaObject_Type,
        "Call",
        "PySide.QtCore.QMetaObject.Call",
        "QMetaObject::Call");
    if (!SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "InvokeMetaMethod", (long) QMetaObject::InvokeMetaMethod))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "ReadProperty", (long) QMetaObject::ReadProperty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "WriteProperty", (long) QMetaObject::WriteProperty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "ResetProperty", (long) QMetaObject::ResetProperty))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "QueryPropertyDesignable", (long) QMetaObject::QueryPropertyDesignable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "QueryPropertyScriptable", (long) QMetaObject::QueryPropertyScriptable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "QueryPropertyStored", (long) QMetaObject::QueryPropertyStored))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "QueryPropertyEditable", (long) QMetaObject::QueryPropertyEditable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "QueryPropertyUser", (long) QMetaObject::QueryPropertyUser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
        &Sbk_QMetaObject_Type, "CreateInstance", (long) QMetaObject::CreateInstance))
        return ;
    // Register converter for enum 'QMetaObject::Call'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX],
            QMetaObject_Call_CppToPython_QMetaObject_Call);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMetaObject_Call_PythonToCpp_QMetaObject_Call,
            is_QMetaObject_Call_PythonToCpp_QMetaObject_Call_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_CALL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMetaObject::Call");
        Shiboken::Conversions::registerConverterName(converter, "Call");
    }
    // End of 'Call' enum.


    qRegisterMetaType< ::QMetaObject::Call >("QMetaObject::Call");
}
