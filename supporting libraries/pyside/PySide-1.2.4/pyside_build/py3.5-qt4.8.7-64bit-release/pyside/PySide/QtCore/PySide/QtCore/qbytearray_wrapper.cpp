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

#include "qbytearray_wrapper.h"

// Extra includes
#include <QList>
#include <QNoImplicitBoolCast>
#include <qbytearray.h>


// Begin code injection
// ========================================================================
// START of custom code block [file: glue/qbytearray_bufferprotocol.cpp]

#if PY_VERSION_HEX < 0x03000000

// QByteArray buffer protocol functions
// see: http://www.python.org/dev/peps/pep-3118/

extern "C" {

static Py_ssize_t SbkQByteArray_segcountproc(PyObject* self, Py_ssize_t* lenp)
{
    if (lenp)
        *lenp = self->ob_type->tp_as_sequence->sq_length(self);
    return 1;
}

static Py_ssize_t SbkQByteArray_readbufferproc(PyObject* self, Py_ssize_t segment, void** ptrptr)
{
    if (segment || !Shiboken::Object::isValid(self))
        return -1;

    ::QByteArray* cppSelf = ((::QByteArray*)0);
    Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], self, &(cppSelf));
    *ptrptr = reinterpret_cast<void*>(cppSelf->data());
    return cppSelf->size();
}

PyBufferProcs SbkQByteArrayBufferProc = {
    /*bf_getreadbuffer*/  &SbkQByteArray_readbufferproc,
    /*bf_getwritebuffer*/ (writebufferproc) &SbkQByteArray_readbufferproc,
    /*bf_getsegcount*/    &SbkQByteArray_segcountproc,
    /*bf_getcharbuffer*/  (charbufferproc) &SbkQByteArray_readbufferproc
};

}

#endif

// END of custom code block [file: glue/qbytearray_bufferprotocol.cpp]
// ========================================================================

// End of code injection


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QByteArray_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QByteArray >()))
        return -1;

    ::QByteArray* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QByteArray", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QByteArray()
    // 1: QByteArray(QByteArray)
    // 2: QByteArray(const char*)
    // 3: QByteArray(int,char)
    if (numArgs == 0) {
        overloadId = 0; // QByteArray()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
        overloadId = 3; // QByteArray(int,char)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 2; // QByteArray(const char*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QByteArray(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArray_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QByteArray()
        {

            if (!PyErr_Occurred()) {
                // QByteArray()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArray();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QByteArray(const QByteArray & arg__1)
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
                // QByteArray(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArray(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QByteArray(const char * arg__1)
        {

            if (!PyErr_Occurred()) {
                // QByteArray(const char*)
                // Begin code injection

                if (PyBytes_Check(pyArgs[1-1])) {
                    cptr = new QByteArray(PyBytes_AsString(pyArgs[1-1]), PyBytes_GET_SIZE(pyArgs[1-1]));
                } else if (PyUnicode_CheckExact(pyArgs[1-1])) {
                    Shiboken::AutoDecRef data(PyUnicode_AsASCIIString(pyArgs[1-1]));
                    cptr = new QByteArray(PyBytes_AsString(data.object()), PyBytes_GET_SIZE(data.object()));
                } else if (Shiboken::String::check(pyArgs[1-1])) {
                    cptr = new QByteArray(Shiboken::String::toCString(pyArgs[1-1]), Shiboken::String::len(pyArgs[1-1]));
                }

                // End of code injection

            }
            break;
        }
        case 3: // QByteArray(int size, char c)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QByteArray(int,char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QByteArray(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QByteArray >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QByteArray_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QByteArray_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QByteArray", "" SBK_STR_NAME "", "int, char", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray", overloads);
        return -1;
}

static PyObject* Sbk_QByteArrayFunc___reduce__(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(N))", PyObject_Type(self), PyBytes_FromStringAndSize(cppSelf->constData(), cppSelf->size()));
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

static PyObject* Sbk_QByteArrayFunc___repr__(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            QByteArray b(((PyObject*)self)->ob_type->tp_name);
            PyObject* aux = Shiboken::String::fromStringAndSize(cppSelf->constData(), cppSelf->size());
            if (PyUnicode_CheckExact(aux)) {
                PyObject* tmp = PyUnicode_AsASCIIString(aux);
                Py_DECREF(aux);
                aux = tmp;
            }
            b += "('";
            b += QByteArray(PyBytes_AS_STRING(aux), PyBytes_GET_SIZE(aux));
            b += "')";
            pyResult = Shiboken::String::fromStringAndSize(b.constData(), b.size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayFunc___str__(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __str__()
            // Begin code injection

            pyResult = Shiboken::String::fromStringAndSize(cppSelf->constData(), cppSelf->size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayFunc_append(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: append(char)
    // 1: append(QByteArray)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // append(char)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // append(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_append_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // append(char c)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // append(char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->append(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 1: // append(const QByteArray & a)
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
                // append(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->append(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_append_TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.append", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: at(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // at(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            char cppResult = const_cast<const ::QByteArray*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<char>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.at", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_capacity(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QByteArray*>(cppSelf)->capacity();
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

static PyObject* Sbk_QByteArrayFunc_chop(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: chop(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // chop(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_chop_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // chop(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->chop(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayFunc_chop_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.chop", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_clear(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QByteArrayFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(char)const
    // 1: contains(QByteArray)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // contains(char)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // contains(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_contains_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // contains(char c) const
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // contains(char)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBool cppResult = const_cast<const ::QByteArray*>(cppSelf)->contains(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QBOOL_IDX], &cppResult);
            }
            break;
        }
        case 1: // contains(const QByteArray & a) const
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
                // contains(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QBool cppResult = const_cast<const ::QByteArray*>(cppSelf)->contains(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QBOOL_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_contains_TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.contains", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_count(PyObject* self, PyObject* args)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "count", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: count()const
    // 1: count(char)const
    // 2: count(QByteArray)const
    if (numArgs == 0) {
        overloadId = 0; // count()const
    } else if (numArgs == 1
        && SbkChar_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[0])))) {
        overloadId = 1; // count(char)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        overloadId = 2; // count(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_count_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // count() const
        {

            if (!PyErr_Occurred()) {
                // count()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QByteArray*>(cppSelf)->count();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // count(char c) const
        {
            char cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // count(char)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QByteArray*>(cppSelf)->count(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 2: // count(const QByteArray & a) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QByteArray cppArg0_local = ::QByteArray();
            ::QByteArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // count(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QByteArray*>(cppSelf)->count(*cppArg0);
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

    Sbk_QByteArrayFunc_count_TypeError:
        const char* overloads[] = {"", "char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.count", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_data(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()
            // Begin code injection

            pyResult = PyBytes_FromStringAndSize(cppSelf->data(), cppSelf->size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayFunc_endsWith(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endsWith(char)const
    // 1: endsWith(QByteArray)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // endsWith(char)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // endsWith(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_endsWith_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // endsWith(char c) const
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // endsWith(char)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->endsWith(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // endsWith(const QByteArray & a) const
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
                // endsWith(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->endsWith(*cppArg0);
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

    Sbk_QByteArrayFunc_endsWith_TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.endsWith", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_fill(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fill(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fill(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fill", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fill(char,int)
    if (SbkChar_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fill(char,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // fill(char,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_fill_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "size");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fill(): got multiple values for keyword argument 'size'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_fill_TypeError;
            }
        }
        char cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fill(char,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray & cppResult = cppSelf->fill(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_fill_TypeError:
        const char* overloads[] = {"char, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.fill", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_fromBase64(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromBase64(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromBase64(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_fromBase64_TypeError;

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
            // fromBase64(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QByteArray::fromBase64(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_fromBase64_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.fromBase64", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_fromHex(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromHex(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // fromHex(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_fromHex_TypeError;

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
            // fromHex(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QByteArray::fromHex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_fromHex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.fromHex", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_fromPercentEncoding(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fromPercentEncoding(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fromPercentEncoding(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromPercentEncoding", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromPercentEncoding(QByteArray,char)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromPercentEncoding(QByteArray,char)
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            overloadId = 0; // fromPercentEncoding(QByteArray,char)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_fromPercentEncoding_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "percent");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.fromPercentEncoding(): got multiple values for keyword argument 'percent'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_fromPercentEncoding_TypeError;
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

        char cppArg1 = '%';
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromPercentEncoding(QByteArray,char)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = ::QByteArray::fromPercentEncoding(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_fromPercentEncoding_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, char = '%'", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.fromPercentEncoding", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_fromRawData(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromRawData(const char*,int)
    if (PyBytes_Check(pyArg)) {
        overloadId = 0; // fromRawData(const char*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_fromRawData_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fromRawData(const char*,int)
            // Begin code injection

            QByteArray cppResult = QByteArray::fromRawData(PyBytes_AsString(pyArg), PyBytes_GET_SIZE(pyArg));
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_fromRawData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.fromRawData", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_indexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.indexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.indexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:indexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: indexOf(QByteArray,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexOf(QByteArray,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // indexOf(QByteArray,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_indexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.indexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_indexOf_TypeError;
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

        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // indexOf(QByteArray,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QByteArray*>(cppSelf)->indexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_indexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.indexOf", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_insert(PyObject* self, PyObject* args)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insert(int,QByteArray)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 0; // insert(int,QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_insert_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = ::QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insert(int,QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray & cppResult = cppSelf->insert(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_insert_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.insert", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_isEmpty(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QByteArrayFunc_isNull(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->isNull();
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

static PyObject* Sbk_QByteArrayFunc_isSharedWith(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSharedWith(QByteArray)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // isSharedWith(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_isSharedWith_TypeError;

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
            // isSharedWith(QByteArray)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->isSharedWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_isSharedWith_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.isSharedWith", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_lastIndexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.lastIndexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.lastIndexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:lastIndexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lastIndexOf(QByteArray,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // lastIndexOf(QByteArray,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // lastIndexOf(QByteArray,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_lastIndexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.lastIndexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_lastIndexOf_TypeError;
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

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // lastIndexOf(QByteArray,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QByteArray*>(cppSelf)->lastIndexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_lastIndexOf_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.lastIndexOf", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_left(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: left(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // left(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_left_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // left(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->left(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_left_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.left", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_leftJustified(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.leftJustified(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.leftJustified(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:leftJustified", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: leftJustified(int,char,bool)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // leftJustified(int,char,bool)const
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // leftJustified(int,char,bool)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
                overloadId = 0; // leftJustified(int,char,bool)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_leftJustified_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "fill");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.leftJustified(): got multiple values for keyword argument 'fill'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_leftJustified_TypeError;
            }
            value = PyDict_GetItemString(kwds, "truncate");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.leftJustified(): got multiple values for keyword argument 'truncate'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2]))))
                    goto Sbk_QByteArrayFunc_leftJustified_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        char cppArg1 = ' ';
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2 = false;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // leftJustified(int,char,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->leftJustified(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_leftJustified_TypeError:
        const char* overloads[] = {"int, char = ' ', bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.leftJustified", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_length(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QByteArray*>(cppSelf)->length();
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

static PyObject* Sbk_QByteArrayFunc_mid(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.mid(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.mid(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:mid", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: mid(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // mid(int,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // mid(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_mid_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "len");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.mid(): got multiple values for keyword argument 'len'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_mid_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mid(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->mid(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_mid_TypeError:
        const char* overloads[] = {"int, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.mid", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_number(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:number", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: number(double,char,int)
    // 1: number(int,int)
    // 2: number(qlonglong,int)
    if (PyLong_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // number(qlonglong,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 2; // number(qlonglong,int)
        }
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // number(double,char,int)
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // number(double,char,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // number(double,char,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // number(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // number(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_number_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // number(double arg__1, char f, int prec)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_number_TypeError;
                }
                value = PyDict_GetItemString(kwds, "prec");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): got multiple values for keyword argument 'prec'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QByteArrayFunc_number_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1 = 'g';
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 6;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // number(double,char,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray cppResult = ::QByteArray::number(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 1: // number(int arg__1, int base)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "base");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): got multiple values for keyword argument 'base'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_number_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 10;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // number(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray cppResult = ::QByteArray::number(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 2: // number(qlonglong arg__1, int base)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "base");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.number(): got multiple values for keyword argument 'base'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_number_TypeError;
                }
            }
            qlonglong cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 10;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // number(qlonglong,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray cppResult = ::QByteArray::number(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_number_TypeError:
        const char* overloads[] = {"float, char = 'g', int = 6", "int, int = 10", "long long, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.number", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_prepend(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prepend(char)
    // 1: prepend(QByteArray)
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // prepend(char)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // prepend(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_prepend_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // prepend(char c)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // prepend(char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->prepend(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 1: // prepend(const QByteArray & a)
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
                // prepend(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->prepend(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_prepend_TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.prepend", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_remove(PyObject* self, PyObject* args)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "remove", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: remove(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // remove(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_remove_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // remove(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray & cppResult = cppSelf->remove(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_remove_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.remove", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_repeated(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: repeated(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // repeated(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_repeated_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // repeated(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->repeated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_repeated_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.repeated", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_replace(PyObject* self, PyObject* args)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: replace(char,char)
    // 1: replace(char,QByteArray)
    // 2: replace(QByteArray,QByteArray)
    // 3: replace(QString,QByteArray)
    // 4: replace(int,int,QByteArray)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[2])))) {
        overloadId = 4; // replace(int,int,QByteArray)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 3; // replace(QString,QByteArray)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[0])))) {
        if (numArgs == 2
            && SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            overloadId = 0; // replace(char,char)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            overloadId = 1; // replace(char,QByteArray)
        }
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
        overloadId = 2; // replace(QByteArray,QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_replace_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // replace(char before, char after)
        {
            char cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // replace(char,char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->replace(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 1: // replace(char before, const QByteArray & after)
        {
            char cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // replace(char,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->replace(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 2: // replace(const QByteArray & before, const QByteArray & after)
        {
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
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // replace(QByteArray,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->replace(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 3: // replace(const QString & before, const QByteArray & after)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QByteArray cppArg1_local = ::QByteArray();
            ::QByteArray* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // replace(QString,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->replace(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 4: // replace(int index, int len, const QByteArray & s)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QByteArray cppArg2_local = ::QByteArray();
            ::QByteArray* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // replace(int,int,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->replace(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_replace_TypeError:
        const char* overloads[] = {"char, char", "char, PySide.QtCore.QByteArray", "PySide.QtCore.QByteArray, PySide.QtCore.QByteArray", "unicode, PySide.QtCore.QByteArray", "int, int, PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.replace", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_reserve(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reserve(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // reserve(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_reserve_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reserve(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reserve(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayFunc_reserve_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.reserve", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_resize(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // resize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_resize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resize(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayFunc_resize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.resize", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_right(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: right(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // right(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_right_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // right(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->right(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_right_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.right", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_rightJustified(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.rightJustified(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.rightJustified(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:rightJustified", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: rightJustified(int,char,bool)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // rightJustified(int,char,bool)const
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // rightJustified(int,char,bool)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
                overloadId = 0; // rightJustified(int,char,bool)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_rightJustified_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "fill");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.rightJustified(): got multiple values for keyword argument 'fill'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_rightJustified_TypeError;
            }
            value = PyDict_GetItemString(kwds, "truncate");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.rightJustified(): got multiple values for keyword argument 'truncate'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2]))))
                    goto Sbk_QByteArrayFunc_rightJustified_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        char cppArg1 = ' ';
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2 = false;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // rightJustified(int,char,bool)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->rightJustified(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_rightJustified_TypeError:
        const char* overloads[] = {"int, char = ' ', bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.rightJustified", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_setNum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setNum", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setNum(double,char,int)
    // 1: setNum(int,int)
    // 2: setNum(qlonglong,int)
    if (PyLong_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // setNum(qlonglong,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 2; // setNum(qlonglong,int)
        }
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setNum(double,char,int)
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setNum(double,char,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // setNum(double,char,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setNum(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // setNum(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_setNum_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setNum(double arg__1, char f, int prec)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_setNum_TypeError;
                }
                value = PyDict_GetItemString(kwds, "prec");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): got multiple values for keyword argument 'prec'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QByteArrayFunc_setNum_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1 = 'g';
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 6;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setNum(double,char,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->setNum(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 1: // setNum(int arg__1, int base)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "base");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): got multiple values for keyword argument 'base'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_setNum_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 10;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setNum(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->setNum(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 2: // setNum(qlonglong arg__1, int base)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "base");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.setNum(): got multiple values for keyword argument 'base'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QByteArrayFunc_setNum_TypeError;
                }
            }
            qlonglong cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 10;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setNum(qlonglong,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QByteArray & cppResult = cppSelf->setNum(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_setNum_TypeError:
        const char* overloads[] = {"float, char = 'g', int = 6", "int, int = 10", "long long, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.setNum", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_setRawData(PyObject* self, PyObject* args)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRawData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRawData(const char*,uint)
    if (numArgs == 2
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[1])))) {
        overloadId = 0; // setRawData(const char*,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_setRawData_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        uint cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRawData(const char*,uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray & cppResult = cppSelf->setRawData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_setRawData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.setRawData", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_simplified(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // simplified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->simplified();
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

static PyObject* Sbk_QByteArrayFunc_size(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QByteArray*>(cppSelf)->size();
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

static PyObject* Sbk_QByteArrayFunc_split(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: split(char)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // split(char)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_split_TypeError;

    // Call function/method
    {
        char cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // split(char)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QByteArray > cppResult = const_cast<const ::QByteArray*>(cppSelf)->split(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_split_TypeError:
        const char* overloads[] = {"char", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.split", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_squeeze(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // squeeze()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->squeeze();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QByteArrayFunc_startsWith(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startsWith(char)const
    // 1: startsWith(QByteArray)const
    if (SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // startsWith(char)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // startsWith(QByteArray)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_startsWith_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // startsWith(char c) const
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // startsWith(char)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->startsWith(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // startsWith(const QByteArray & a) const
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
                // startsWith(QByteArray)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QByteArray*>(cppSelf)->startsWith(*cppArg0);
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

    Sbk_QByteArrayFunc_startsWith_TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.startsWith", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QByteArray&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // swap(QByteArray&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_swap_TypeError;

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
            // swap(QByteArray&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.swap", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toBase64(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toBase64()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->toBase64();
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

static PyObject* Sbk_QByteArrayFunc_toDouble(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // toDouble(bool*)const
            // Begin code injection

            // TEMPLATE - fix_bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double retval_ = cppSelf->toDouble(&ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayFunc_toFloat(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // toFloat(bool*)const
            // Begin code injection

            // TEMPLATE - fix_bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            float retval_ = cppSelf->toFloat(&ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QByteArrayFunc_toHex(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toHex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->toHex();
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

static PyObject* Sbk_QByteArrayFunc_toInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toInt(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toInt", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toInt(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toInt(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toInt(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toInt_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toInt(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toInt_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toInt(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int retval_ = cppSelf->toInt(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toInt_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toInt", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toLong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toLong(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toLong", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toLong(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toLong(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toLong(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toLong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toLong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toLong_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toLong(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            long retval_ = cppSelf->toLong(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<long>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toLong_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toLong", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toLongLong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toLongLong(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toLongLong", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toLongLong(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toLongLong(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toLongLong(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toLongLong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toLongLong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toLongLong_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toLongLong(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qlonglong retval_ = cppSelf->toLongLong(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toLongLong_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toLongLong", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toLower(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toLower()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->toLower();
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

static PyObject* Sbk_QByteArrayFunc_toPercentEncoding(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toPercentEncoding(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:toPercentEncoding", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: toPercentEncoding(QByteArray,QByteArray,char)const
    if (numArgs == 0) {
        overloadId = 0; // toPercentEncoding(QByteArray,QByteArray,char)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toPercentEncoding(QByteArray,QByteArray,char)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // toPercentEncoding(QByteArray,QByteArray,char)const
            } else if (SbkChar_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[2])))) {
                overloadId = 0; // toPercentEncoding(QByteArray,QByteArray,char)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toPercentEncoding_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "exclude");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toPercentEncoding(): got multiple values for keyword argument 'exclude'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toPercentEncoding_TypeError;
            }
            value = PyDict_GetItemString(kwds, "include");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toPercentEncoding(): got multiple values for keyword argument 'include'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[1]))))
                    goto Sbk_QByteArrayFunc_toPercentEncoding_TypeError;
            }
            value = PyDict_GetItemString(kwds, "percent");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toPercentEncoding(): got multiple values for keyword argument 'percent'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!SbkChar_Check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[2]))))
                    goto Sbk_QByteArrayFunc_toPercentEncoding_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QByteArray cppArg1_local = QByteArray();
        ::QByteArray* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
        char cppArg2 = '%';
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // toPercentEncoding(QByteArray,QByteArray,char)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->toPercentEncoding(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toPercentEncoding_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray = QByteArray(), PySide.QtCore.QByteArray = QByteArray(), char = '%'", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toPercentEncoding", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toShort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toShort(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toShort", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toShort(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toShort(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toShort(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toShort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toShort(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toShort_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toShort(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            short retval_ = cppSelf->toShort(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<short>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toShort_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toShort", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toUInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toUInt(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toUInt", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toUInt(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toUInt(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toUInt(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toUInt_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toUInt(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toUInt_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toUInt(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint retval_ = cppSelf->toUInt(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toUInt_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toUInt", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toULong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toULong(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toULong", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toULong(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toULong(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toULong(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toULong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toULong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toULong_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toULong(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ulong retval_ = cppSelf->toULong(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<ulong>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toULong_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toULong", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toULongLong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toULongLong(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toULongLong", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toULongLong(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toULongLong(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toULongLong(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toULongLong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toULongLong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toULongLong_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toULongLong(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qulonglong retval_ = cppSelf->toULongLong(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qulonglong>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toULongLong_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toULongLong", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toUShort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toUShort(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toUShort", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toUShort(bool*,int)const
    if (numArgs == 0) {
        overloadId = 0; // toUShort(bool*,int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // toUShort(bool*,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_toUShort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QByteArray.toUShort(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QByteArrayFunc_toUShort_TypeError;
            }
        }
        bool* removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)
        int cppArg0 = 10;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toUShort(bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ushort retval_ = cppSelf->toUShort(&ok_, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc_toUShort_TypeError:
        const char* overloads[] = {"PySide.QtCore.bool = 0, int = 10", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QByteArray.toUShort", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc_toUpper(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toUpper()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->toUpper();
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

static PyObject* Sbk_QByteArrayFunc_trimmed(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // trimmed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QByteArray*>(cppSelf)->trimmed();
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

static PyObject* Sbk_QByteArrayFunc_truncate(PyObject* self, PyObject* pyArg)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: truncate(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // truncate(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc_truncate_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // truncate(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->truncate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QByteArrayFunc_truncate_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.truncate", overloads);
        return 0;
}

static PyObject* Sbk_QByteArray___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray& cppSelf = *(((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QByteArray_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QByteArrayFunc___reduce__, METH_NOARGS},
    {"append", (PyCFunction)Sbk_QByteArrayFunc_append, METH_O},
    {"at", (PyCFunction)Sbk_QByteArrayFunc_at, METH_O},
    {"capacity", (PyCFunction)Sbk_QByteArrayFunc_capacity, METH_NOARGS},
    {"chop", (PyCFunction)Sbk_QByteArrayFunc_chop, METH_O},
    {"clear", (PyCFunction)Sbk_QByteArrayFunc_clear, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QByteArrayFunc_contains, METH_O},
    {"count", (PyCFunction)Sbk_QByteArrayFunc_count, METH_VARARGS},
    {"data", (PyCFunction)Sbk_QByteArrayFunc_data, METH_NOARGS},
    {"endsWith", (PyCFunction)Sbk_QByteArrayFunc_endsWith, METH_O},
    {"fill", (PyCFunction)Sbk_QByteArrayFunc_fill, METH_VARARGS|METH_KEYWORDS},
    {"fromBase64", (PyCFunction)Sbk_QByteArrayFunc_fromBase64, METH_O|METH_STATIC},
    {"fromHex", (PyCFunction)Sbk_QByteArrayFunc_fromHex, METH_O|METH_STATIC},
    {"fromPercentEncoding", (PyCFunction)Sbk_QByteArrayFunc_fromPercentEncoding, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fromRawData", (PyCFunction)Sbk_QByteArrayFunc_fromRawData, METH_O|METH_STATIC},
    {"indexOf", (PyCFunction)Sbk_QByteArrayFunc_indexOf, METH_VARARGS|METH_KEYWORDS},
    {"insert", (PyCFunction)Sbk_QByteArrayFunc_insert, METH_VARARGS},
    {"isEmpty", (PyCFunction)Sbk_QByteArrayFunc_isEmpty, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QByteArrayFunc_isNull, METH_NOARGS},
    {"isSharedWith", (PyCFunction)Sbk_QByteArrayFunc_isSharedWith, METH_O},
    {"lastIndexOf", (PyCFunction)Sbk_QByteArrayFunc_lastIndexOf, METH_VARARGS|METH_KEYWORDS},
    {"left", (PyCFunction)Sbk_QByteArrayFunc_left, METH_O},
    {"leftJustified", (PyCFunction)Sbk_QByteArrayFunc_leftJustified, METH_VARARGS|METH_KEYWORDS},
    {"length", (PyCFunction)Sbk_QByteArrayFunc_length, METH_NOARGS},
    {"mid", (PyCFunction)Sbk_QByteArrayFunc_mid, METH_VARARGS|METH_KEYWORDS},
    {"number", (PyCFunction)Sbk_QByteArrayFunc_number, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"prepend", (PyCFunction)Sbk_QByteArrayFunc_prepend, METH_O},
    {"remove", (PyCFunction)Sbk_QByteArrayFunc_remove, METH_VARARGS},
    {"repeated", (PyCFunction)Sbk_QByteArrayFunc_repeated, METH_O},
    {"replace", (PyCFunction)Sbk_QByteArrayFunc_replace, METH_VARARGS},
    {"reserve", (PyCFunction)Sbk_QByteArrayFunc_reserve, METH_O},
    {"resize", (PyCFunction)Sbk_QByteArrayFunc_resize, METH_O},
    {"right", (PyCFunction)Sbk_QByteArrayFunc_right, METH_O},
    {"rightJustified", (PyCFunction)Sbk_QByteArrayFunc_rightJustified, METH_VARARGS|METH_KEYWORDS},
    {"setNum", (PyCFunction)Sbk_QByteArrayFunc_setNum, METH_VARARGS|METH_KEYWORDS},
    {"setRawData", (PyCFunction)Sbk_QByteArrayFunc_setRawData, METH_VARARGS},
    {"simplified", (PyCFunction)Sbk_QByteArrayFunc_simplified, METH_NOARGS},
    {"size", (PyCFunction)Sbk_QByteArrayFunc_size, METH_NOARGS},
    {"split", (PyCFunction)Sbk_QByteArrayFunc_split, METH_O},
    {"squeeze", (PyCFunction)Sbk_QByteArrayFunc_squeeze, METH_NOARGS},
    {"startsWith", (PyCFunction)Sbk_QByteArrayFunc_startsWith, METH_O},
    {"swap", (PyCFunction)Sbk_QByteArrayFunc_swap, METH_O},
    {"toBase64", (PyCFunction)Sbk_QByteArrayFunc_toBase64, METH_NOARGS},
    {"toDouble", (PyCFunction)Sbk_QByteArrayFunc_toDouble, METH_NOARGS},
    {"toFloat", (PyCFunction)Sbk_QByteArrayFunc_toFloat, METH_NOARGS},
    {"toHex", (PyCFunction)Sbk_QByteArrayFunc_toHex, METH_NOARGS},
    {"toInt", (PyCFunction)Sbk_QByteArrayFunc_toInt, METH_VARARGS|METH_KEYWORDS},
    {"toLong", (PyCFunction)Sbk_QByteArrayFunc_toLong, METH_VARARGS|METH_KEYWORDS},
    {"toLongLong", (PyCFunction)Sbk_QByteArrayFunc_toLongLong, METH_VARARGS|METH_KEYWORDS},
    {"toLower", (PyCFunction)Sbk_QByteArrayFunc_toLower, METH_NOARGS},
    {"toPercentEncoding", (PyCFunction)Sbk_QByteArrayFunc_toPercentEncoding, METH_VARARGS|METH_KEYWORDS},
    {"toShort", (PyCFunction)Sbk_QByteArrayFunc_toShort, METH_VARARGS|METH_KEYWORDS},
    {"toUInt", (PyCFunction)Sbk_QByteArrayFunc_toUInt, METH_VARARGS|METH_KEYWORDS},
    {"toULong", (PyCFunction)Sbk_QByteArrayFunc_toULong, METH_VARARGS|METH_KEYWORDS},
    {"toULongLong", (PyCFunction)Sbk_QByteArrayFunc_toULongLong, METH_VARARGS|METH_KEYWORDS},
    {"toUShort", (PyCFunction)Sbk_QByteArrayFunc_toUShort, METH_VARARGS|METH_KEYWORDS},
    {"toUpper", (PyCFunction)Sbk_QByteArrayFunc_toUpper, METH_NOARGS},
    {"trimmed", (PyCFunction)Sbk_QByteArrayFunc_trimmed, METH_NOARGS},
    {"truncate", (PyCFunction)Sbk_QByteArrayFunc_truncate, METH_O},

    {"__copy__", (PyCFunction)Sbk_QByteArray___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QByteArray___nb_bool(PyObject* self)
{
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QByteArrayFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__radd__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__radd__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator+(PyBytes,QByteArray)
    // 1: operator+(PyUnicode,QByteArray)
    // 2: operator+(PyUnicode)
    // 3: operator+(char,QByteArray)
    // 4: operator+(QByteArray,char)
    // 5: operator+(QByteArray,QByteArray)
    if (!isReverse
        && SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 4; // operator+(QByteArray,char)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 5; // operator+(QByteArray,QByteArray)
    } else if (isReverse
        && SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 3; // operator+(char,QByteArray)
    } else if (!isReverse
        && PyUnicode_Check(pyArg)) {
        overloadId = 2; // operator+(PyUnicode)
    } else if (isReverse
        && PyUnicode_Check(pyArg)) {
        overloadId = 1; // operator+(PyUnicode,QByteArray)
    } else if (isReverse
        && PyBytes_Check(pyArg)) {
        overloadId = 0; // operator+(PyBytes,QByteArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc___add___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator+(PyBytes , QByteArray )
        {

            if (!PyErr_Occurred()) {
                // operator+(PyBytes,QByteArray) [reverse operator]
                // Begin code injection

                QByteArray ba = QByteArray(PyBytes_AS_STRING(pyArg), PyBytes_GET_SIZE(pyArg)) + *cppSelf;
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

                // End of code injection


            }
            break;
        }
        case 1: // operator+(PyUnicode , QByteArray )
        {

            if (!PyErr_Occurred()) {
                // operator+(PyUnicode,QByteArray) [reverse operator]
                // Begin code injection

                Shiboken::AutoDecRef str(PyUnicode_AsASCIIString(pyArg));
                if (!str.isNull()) {
                    QByteArray b(PyBytes_AS_STRING(str.object()), PyBytes_GET_SIZE(str.object()));
                    b.append(*cppSelf);
                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &b);
                }

                // End of code injection


            }
            break;
        }
        case 2: // operator+(PyUnicode arg__1)
        {

            if (!PyErr_Occurred()) {
                // operator+(PyUnicode)
                // Begin code injection

                Shiboken::AutoDecRef str(PyUnicode_AsASCIIString(pyArg));
                if (!str.isNull()) {
                    QByteArray b(PyBytes_AS_STRING(str.object()), PyBytes_GET_SIZE (str.object()));
                    b.prepend(*cppSelf);
                    pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &b);
                }

                // End of code injection


            }
            break;
        }
        case 3: // operator+(char a1)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator+(char,QByteArray) [reverse operator]
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QByteArray cppResult = cppArg0 + (*cppSelf);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 4: // operator+(char a2)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator+(QByteArray,char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QByteArray cppResult = (*cppSelf) + cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
        case 5: // operator+(const QByteArray & a2)
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
                // operator+(QByteArray,QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QByteArray cppResult = (*cppSelf) + (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
            }
            break;
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QByteArrayFunc___add___TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", "unicode", "unicode", "char", "char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QByteArrayFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(char)
    // 1: operator+=(QByteArray)
    if (!isReverse
        && SbkChar_Check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArg)))) {
        overloadId = 0; // operator+=(char)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 1; // operator+=(QByteArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QByteArrayFunc___iadd___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator+=(char c)
        {
            char cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator+=(char)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) += cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // operator+=(const QByteArray & a)
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
                // operator+=(QByteArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) += (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QByteArrayFunc___iadd___TypeError:
        const char* overloads[] = {"char", "PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QByteArray.__iadd__", overloads);
        return 0;
}

Py_ssize_t Sbk_QByteArrayFunc___len__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    return cppSelf->count();

    // End of code injection
}

PyObject* Sbk_QByteArrayFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    } else {
        char res[2];
        res[0] = cppSelf->at(_i);
        res[1] = 0;
        return PyBytes_FromStringAndSize(res, 1);
    }

    // End of code injection
}

int Sbk_QByteArrayFunc___setitem__(PyObject* self, Py_ssize_t _i, PyObject* _value)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    cppSelf->remove(_i, 1);
    PyObject* args = Py_BuildValue("(nO)", _i, _value);
    PyObject* result = Sbk_QByteArrayFunc_insert(self, args);
    Py_DECREF(args);
    Py_XDECREF(result);
    return !result ? -1 : 0;

    // End of code injection
}

PyObject* Sbk_QByteArrayFunc___getslice__(PyObject* self, Py_ssize_t _i1, Py_ssize_t _i2)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    Py_ssize_t max = cppSelf->count();
    _i1 = qBound(Py_ssize_t(0), _i1, max);
    _i2 = qBound(Py_ssize_t(0), _i2, max);
    QByteArray ba;
    if (_i1 < _i2)
        ba = cppSelf->mid(_i1, _i2 - _i1);
    return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &ba);

    // End of code injection
}

// Rich comparison
static PyObject* Sbk_QByteArray_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QByteArray& cppSelf = *(((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator!=(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
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
            if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
                // operator<(const char * a2)
                const char* cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf < (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator<(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QByteArray_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator<=(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QByteArray_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator==(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator>(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QByteArray_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
                // operator>=(const QByteArray & a2)
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QByteArray cppArg0_local = ::QByteArray();
                ::QByteArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QByteArray_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QByteArray_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QByteArray_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QByteArray_HashFunc(PyObject* self) {
    ::QByteArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)self));
    return qHash(*cppSelf);
}

static int Sbk_QByteArray_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QByteArray_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QByteArray_TypeAsNumber;

static PySequenceMethods Sbk_QByteArray_TypeAsSequence;

static SbkObjectType Sbk_QByteArray_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QByteArray",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QByteArrayFunc___repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QByteArray_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              Sbk_QByteArrayFunc___str__,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QByteArray_traverse,
    /*tp_clear*/            Sbk_QByteArray_clear,
    /*tp_richcompare*/      Sbk_QByteArray_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QByteArray_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QByteArray_Init,
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
static void QByteArray_PythonToCpp_QByteArray_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QByteArray_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QByteArray_PythonToCpp_QByteArray_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QByteArray_Type))
        return QByteArray_PythonToCpp_QByteArray_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QByteArray_PTR_CppToPython_QByteArray(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QByteArray*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QByteArray_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QByteArray_COPY_CppToPython_QByteArray(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QByteArray_Type, new ::QByteArray(*((::QByteArray*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QByteArray_PythonToCpp_QByteArray_COPY(PyObject* pyIn, void* cppOut) {
    *((::QByteArray*)cppOut) = *((::QByteArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QByteArray_PythonToCpp_QByteArray_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QByteArray_Type))
        return QByteArray_PythonToCpp_QByteArray_COPY;
    return 0;
}

// Python to C++ conversions for type 'QByteArray'.
static void Py_None_PythonToCpp_QByteArray(PyObject* pyIn, void* cppOut) {

    *((::QByteArray*)cppOut) = QByteArray();

}
static PythonToCppFunc is_Py_None_PythonToCpp_QByteArray_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Py_None_PythonToCpp_QByteArray;
    return 0;
}
static void PyString_PythonToCpp_QByteArray(PyObject* pyIn, void* cppOut) {

    *((::QByteArray*)cppOut) = QByteArray(Shiboken::String::toCString(pyIn), Shiboken::String::len(pyIn));

}
static PythonToCppFunc is_PyString_PythonToCpp_QByteArray_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PyString_PythonToCpp_QByteArray;
    return 0;
}
static void PyBytes_PythonToCpp_QByteArray(PyObject* pyIn, void* cppOut) {

    #ifdef IS_PY3K
    *((::QByteArray*)cppOut) = QByteArray(PyBytes_AS_STRING(pyIn), PyBytes_GET_SIZE(pyIn));
    #endif

}
static PythonToCppFunc is_PyBytes_PythonToCpp_QByteArray_Convertible(PyObject* pyIn) {
    if (PyBytes_Check(pyIn))
        return PyBytes_PythonToCpp_QByteArray;
    return 0;
}

void init_QByteArray(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QByteArray_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QByteArray_TypeAsNumber.nb_inplace_add = Sbk_QByteArrayFunc___iadd__;
    Sbk_QByteArray_TypeAsNumber.nb_add = Sbk_QByteArrayFunc___add__;
    SBK_NB_BOOL(Sbk_QByteArray_TypeAsNumber) = Sbk_QByteArray___nb_bool;
    Sbk_QByteArray_Type.super.ht_type.tp_as_number = &Sbk_QByteArray_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QByteArray_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QByteArray_TypeAsSequence.sq_length = &Sbk_QByteArrayFunc___len__;
    Sbk_QByteArray_TypeAsSequence.sq_item = &Sbk_QByteArrayFunc___getitem__;
    Sbk_QByteArray_TypeAsSequence.sq_ass_item = &Sbk_QByteArrayFunc___setitem__;
#ifndef IS_PY3K
    Sbk_QByteArray_TypeAsSequence.sq_slice = &Sbk_QByteArrayFunc___getslice__;
#endif
    Sbk_QByteArray_Type.super.ht_type.tp_as_sequence = &Sbk_QByteArray_TypeAsSequence;

    SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QByteArray_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QByteArray", "QByteArray",
        &Sbk_QByteArray_Type, &Shiboken::callCppDestructor< ::QByteArray >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QByteArray_Type,
        QByteArray_PythonToCpp_QByteArray_PTR,
        is_QByteArray_PythonToCpp_QByteArray_PTR_Convertible,
        QByteArray_PTR_CppToPython_QByteArray,
        QByteArray_COPY_CppToPython_QByteArray);

    Shiboken::Conversions::registerConverterName(converter, "QByteArray");
    Shiboken::Conversions::registerConverterName(converter, "QByteArray*");
    Shiboken::Conversions::registerConverterName(converter, "QByteArray&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QByteArray).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QByteArray_PythonToCpp_QByteArray_COPY,
        is_QByteArray_PythonToCpp_QByteArray_COPY_Convertible);
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Py_None_PythonToCpp_QByteArray,
        is_Py_None_PythonToCpp_QByteArray_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PyString_PythonToCpp_QByteArray,
        is_PyString_PythonToCpp_QByteArray_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PyBytes_PythonToCpp_QByteArray,
        is_PyBytes_PythonToCpp_QByteArray_Convertible);




    // Begin code injection

    #if PY_VERSION_HEX < 0x03000000
        Shiboken::SbkType<QByteArray>()->tp_as_buffer = &SbkQByteArrayBufferProc;
        Shiboken::SbkType<QByteArray>()->tp_flags |= Py_TPFLAGS_HAVE_GETCHARBUFFER;
    #endif

    // End of code injection
    qRegisterMetaType< ::QByteArray >("QByteArray");
}

