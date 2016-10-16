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

#include "quuid_wrapper.h"

// Extra includes
#include <qbytearray.h>
#include <quuid.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QUuid_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QUuid >()))
        return -1;

    ::QUuid* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3 || numArgs == 4 || numArgs == 5 || numArgs == 6 || numArgs == 7 || numArgs == 8 || numArgs == 9 || numArgs == 10)
        goto Sbk_QUuid_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QUuid", 0, 11, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9]), &(pyArgs[10])))
        return -1;


    // Overloaded function decisor
    // 0: QUuid()
    // 1: QUuid(QByteArray)
    // 2: QUuid(QString)
    // 3: QUuid(QUuid)
    // 4: QUuid(const char*)
    // 5: QUuid(uint,ushort,ushort,uchar,uchar,uchar,uchar,uchar,uchar,uchar,uchar)
    if (numArgs == 0) {
        overloadId = 0; // QUuid()
    } else if (numArgs == 11
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[2])))
        && SbkChar_Check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[3])))
        && SbkChar_Check(pyArgs[4]) && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[4])))
        && SbkChar_Check(pyArgs[5]) && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[5])))
        && SbkChar_Check(pyArgs[6]) && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[6])))
        && SbkChar_Check(pyArgs[7]) && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[7])))
        && SbkChar_Check(pyArgs[8]) && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[8])))
        && SbkChar_Check(pyArgs[9]) && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[9])))
        && SbkChar_Check(pyArgs[10]) && (pythonToCpp[10] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uchar>(), (pyArgs[10])))) {
        overloadId = 5; // QUuid(uint,ushort,ushort,uchar,uchar,uchar,uchar,uchar,uchar,uchar,uchar)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 4; // QUuid(const char*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 2; // QUuid(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QUuid(QByteArray)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArgs[0])))) {
        overloadId = 3; // QUuid(QUuid)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUuid_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QUuid()
        {

            if (!PyErr_Occurred()) {
                // QUuid()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QUuid(const QByteArray & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QUuid(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QUuid(const QString & arg__1)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QUuid(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QUuid(const QUuid & QUuid)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QUuid cppArg0_local = ::QUuid();
            ::QUuid* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QUuid(QUuid)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QUuid(const char * arg__1)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QUuid(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QUuid(uint l, ushort w1, ushort w2, uchar b1, uchar b2, uchar b3, uchar b4, uchar b5, uchar b6, uchar b7, uchar b8)
        {
            uint cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ushort cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ushort cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            uchar cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            uchar cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            uchar cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            uchar cppArg6;
            pythonToCpp[6](pyArgs[6], &cppArg6);
            uchar cppArg7;
            pythonToCpp[7](pyArgs[7], &cppArg7);
            uchar cppArg8;
            pythonToCpp[8](pyArgs[8], &cppArg8);
            uchar cppArg9;
            pythonToCpp[9](pyArgs[9], &cppArg9);
            uchar cppArg10;
            pythonToCpp[10](pyArgs[10], &cppArg10);

            if (!PyErr_Occurred()) {
                // QUuid(uint,ushort,ushort,uchar,uchar,uchar,uchar,uchar,uchar,uchar,uchar)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QUuid(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8, cppArg9, cppArg10);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QUuid >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QUuid_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QUuid_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray", "unicode", "PySide.QtCore.QUuid", "" SBK_STR_NAME "", "unsigned int, unsigned short int, unsigned short int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QUuid", overloads);
        return -1;
}

static PyObject* Sbk_QUuidFunc___reduce__(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(s))", PyObject_Type(self), qPrintable(cppSelf->toString()));
            // TEMPLATE - reduce_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUuidFunc___repr__(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s('%s')", ((PyObject*)self)->ob_type->tp_name, qPrintable(cppSelf->toString()));
            pyResult = Shiboken::String::fromCString(qPrintable(format));
            // TEMPLATE - repr_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUuidFunc_createUuid(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createUuid()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUuid cppResult = ::QUuid::createUuid();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUuidFunc_fromRfc4122(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromRfc4122(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromRfc4122(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QUuidFunc_fromRfc4122_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // fromRfc4122(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUuid cppResult = ::QUuid::fromRfc4122(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QUuidFunc_fromRfc4122_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QUuid.fromRfc4122", overloads);
        return 0;
}

static PyObject* Sbk_QUuidFunc_isNull(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QUuid*>(cppSelf)->isNull();
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

static PyObject* Sbk_QUuidFunc_toByteArray(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toByteArray()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUuid*>(cppSelf)->toByteArray();
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

static PyObject* Sbk_QUuidFunc_toRfc4122(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toRfc4122()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QUuid*>(cppSelf)->toRfc4122();
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

static PyObject* Sbk_QUuidFunc_toString(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QUuid*>(cppSelf)->toString();
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

static PyObject* Sbk_QUuidFunc_variant(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // variant()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUuid::Variant cppResult = const_cast<const ::QUuid*>(cppSelf)->variant();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUuidFunc_version(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // version()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUuid::Version cppResult = const_cast<const ::QUuid*>(cppSelf)->version();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QUuid___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUuid& cppSelf = *(((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QUuid_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QUuidFunc___reduce__, METH_NOARGS},
    {"createUuid", (PyCFunction)Sbk_QUuidFunc_createUuid, METH_NOARGS|METH_STATIC},
    {"fromRfc4122", (PyCFunction)Sbk_QUuidFunc_fromRfc4122, METH_O|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QUuidFunc_isNull, METH_NOARGS},
    {"toByteArray", (PyCFunction)Sbk_QUuidFunc_toByteArray, METH_NOARGS},
    {"toRfc4122", (PyCFunction)Sbk_QUuidFunc_toRfc4122, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QUuidFunc_toString, METH_NOARGS},
    {"variant", (PyCFunction)Sbk_QUuidFunc_variant, METH_NOARGS},
    {"version", (PyCFunction)Sbk_QUuidFunc_version, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QUuid___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QUuid___nb_bool(PyObject* self)
{
    ::QUuid* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

// Rich comparison
static PyObject* Sbk_QUuid_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QUuid& cppSelf = *(((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
                // operator!=(const QUuid & orig) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUuid cppArg0_local = ::QUuid();
                ::QUuid* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_LT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
                // operator<(const QUuid & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUuid cppArg0_local = ::QUuid();
                ::QUuid* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QUuid_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
                // operator==(const QUuid & orig) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUuid cppArg0_local = ::QUuid();
                ::QUuid* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        case Py_GT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (pyArg)))) {
                // operator>(const QUuid & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QUuid cppArg0_local = ::QUuid();
                ::QUuid* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QUUID_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QUuid_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QUuid_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QUuid_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QUuid_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QUuid_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QUuid_TypeAsNumber;

static SbkObjectType Sbk_QUuid_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QUuid",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QUuidFunc___repr__,
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
    /*tp_traverse*/         Sbk_QUuid_traverse,
    /*tp_clear*/            Sbk_QUuid_clear,
    /*tp_richcompare*/      Sbk_QUuid_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QUuid_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QUuid_Init,
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
static void QUuid_Variant_PythonToCpp_QUuid_Variant(PyObject* pyIn, void* cppOut) {
    *((::QUuid::Variant*)cppOut) = (::QUuid::Variant) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QUuid_Variant_PythonToCpp_QUuid_Variant_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX]))
        return QUuid_Variant_PythonToCpp_QUuid_Variant;
    return 0;
}
static PyObject* QUuid_Variant_CppToPython_QUuid_Variant(const void* cppIn) {
    int castCppIn = *((::QUuid::Variant*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX], castCppIn);

}

static void QUuid_Version_PythonToCpp_QUuid_Version(PyObject* pyIn, void* cppOut) {
    *((::QUuid::Version*)cppOut) = (::QUuid::Version) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QUuid_Version_PythonToCpp_QUuid_Version_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX]))
        return QUuid_Version_PythonToCpp_QUuid_Version;
    return 0;
}
static PyObject* QUuid_Version_CppToPython_QUuid_Version(const void* cppIn) {
    int castCppIn = *((::QUuid::Version*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QUuid_PythonToCpp_QUuid_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QUuid_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QUuid_PythonToCpp_QUuid_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUuid_Type))
        return QUuid_PythonToCpp_QUuid_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QUuid_PTR_CppToPython_QUuid(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QUuid*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QUuid_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QUuid_COPY_CppToPython_QUuid(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QUuid_Type, new ::QUuid(*((::QUuid*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QUuid_PythonToCpp_QUuid_COPY(PyObject* pyIn, void* cppOut) {
    *((::QUuid*)cppOut) = *((::QUuid*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QUUID_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QUuid_PythonToCpp_QUuid_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QUuid_Type))
        return QUuid_PythonToCpp_QUuid_COPY;
    return 0;
}

// Implicit conversions.
static void constQByteArrayREF_PythonToCpp_QUuid(PyObject* pyIn, void* cppOut) {
    *((::QUuid*)cppOut) = ::QUuid(*((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQByteArrayREF_PythonToCpp_QUuid_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyIn))
        return constQByteArrayREF_PythonToCpp_QUuid;
    return 0;
}

static void constQStringREF_PythonToCpp_QUuid(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QUuid*)cppOut) = ::QUuid(cppIn);
}
static PythonToCppFunc is_constQStringREF_PythonToCpp_QUuid_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return constQStringREF_PythonToCpp_QUuid;
    return 0;
}

static void constcharPTR_PythonToCpp_QUuid(PyObject* pyIn, void* cppOut) {
    const char* cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), pyIn, &cppIn);
    *((::QUuid*)cppOut) = ::QUuid(cppIn);
}
static PythonToCppFunc is_constcharPTR_PythonToCpp_QUuid_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return constcharPTR_PythonToCpp_QUuid;
    return 0;
}

void init_QUuid(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QUuid_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QUuid_TypeAsNumber) = Sbk_QUuid___nb_bool;
    Sbk_QUuid_Type.super.ht_type.tp_as_number = &Sbk_QUuid_TypeAsNumber;

    SbkPySide_QtCoreTypes[SBK_QUUID_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QUuid_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QUuid", "QUuid",
        &Sbk_QUuid_Type, &Shiboken::callCppDestructor< ::QUuid >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QUuid_Type,
        QUuid_PythonToCpp_QUuid_PTR,
        is_QUuid_PythonToCpp_QUuid_PTR_Convertible,
        QUuid_PTR_CppToPython_QUuid,
        QUuid_COPY_CppToPython_QUuid);

    Shiboken::Conversions::registerConverterName(converter, "QUuid");
    Shiboken::Conversions::registerConverterName(converter, "QUuid*");
    Shiboken::Conversions::registerConverterName(converter, "QUuid&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QUuid).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QUuid_PythonToCpp_QUuid_COPY,
        is_QUuid_PythonToCpp_QUuid_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQByteArrayREF_PythonToCpp_QUuid,
        is_constQByteArrayREF_PythonToCpp_QUuid_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStringREF_PythonToCpp_QUuid,
        is_constQStringREF_PythonToCpp_QUuid_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constcharPTR_PythonToCpp_QUuid,
        is_constcharPTR_PythonToCpp_QUuid_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Variant'.
    SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QUuid_Type,
        "Variant",
        "PySide.QtCore.QUuid.Variant",
        "QUuid::Variant");
    if (!SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
        &Sbk_QUuid_Type, "VarUnknown", (long) QUuid::VarUnknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
        &Sbk_QUuid_Type, "NCS", (long) QUuid::NCS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
        &Sbk_QUuid_Type, "DCE", (long) QUuid::DCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
        &Sbk_QUuid_Type, "Microsoft", (long) QUuid::Microsoft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
        &Sbk_QUuid_Type, "Reserved", (long) QUuid::Reserved))
        return ;
    // Register converter for enum 'QUuid::Variant'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX],
            QUuid_Variant_CppToPython_QUuid_Variant);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUuid_Variant_PythonToCpp_QUuid_Variant,
            is_QUuid_Variant_PythonToCpp_QUuid_Variant_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VARIANT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QUuid::Variant");
        Shiboken::Conversions::registerConverterName(converter, "Variant");
    }
    // End of 'Variant' enum.

    // Initialization of enum 'Version'.
    SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QUuid_Type,
        "Version",
        "PySide.QtCore.QUuid.Version",
        "QUuid::Version");
    if (!SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
        &Sbk_QUuid_Type, "VerUnknown", (long) QUuid::VerUnknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
        &Sbk_QUuid_Type, "Time", (long) QUuid::Time))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
        &Sbk_QUuid_Type, "EmbeddedPOSIX", (long) QUuid::EmbeddedPOSIX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
        &Sbk_QUuid_Type, "Name", (long) QUuid::Name))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
        &Sbk_QUuid_Type, "Random", (long) QUuid::Random))
        return ;
    // Register converter for enum 'QUuid::Version'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX],
            QUuid_Version_CppToPython_QUuid_Version);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QUuid_Version_PythonToCpp_QUuid_Version,
            is_QUuid_Version_PythonToCpp_QUuid_Version_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QUUID_VERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QUuid::Version");
        Shiboken::Conversions::registerConverterName(converter, "Version");
    }
    // End of 'Version' enum.


    qRegisterMetaType< ::QUuid >("QUuid");
    qRegisterMetaType< ::QUuid::Variant >("QUuid::Variant");
    qRegisterMetaType< ::QUuid::Version >("QUuid::Version");
}
