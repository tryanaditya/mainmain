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

#include "qbitarray_wrapper.h"

// Extra includes
#include <qbitarray.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QBitArray_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QBitArray >()))
        return -1;

    ::QBitArray* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QBitArray(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QBitArray", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QBitArray()
    // 1: QBitArray(QBitArray)
    // 2: QBitArray(int,bool)
    if (numArgs == 0) {
        overloadId = 0; // QBitArray()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QBitArray(int,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 2; // QBitArray(int,bool)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArgs[0])))) {
        overloadId = 1; // QBitArray(QBitArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArray_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QBitArray()
        {

            if (!PyErr_Occurred()) {
                // QBitArray()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitArray();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QBitArray(const QBitArray & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QBitArray cppArg0_local = ::QBitArray();
            ::QBitArray* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBitArray(QBitArray)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitArray(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QBitArray(int size, bool val)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "val");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QBitArray(): got multiple values for keyword argument 'val'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                        goto Sbk_QBitArray_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1 = false;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QBitArray(int,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBitArray(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QBitArray >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QBitArray_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QBitArray_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QBitArray", "int, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBitArray", overloads);
        return -1;
}

static PyObject* Sbk_QBitArrayFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QBitArrayFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBitArray*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.at", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_clear(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QBitArrayFunc_clearBit(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: clearBit(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // clearBit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_clearBit_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // clearBit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearBit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBitArrayFunc_clearBit_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.clearBit", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_count(PyObject* self, PyObject* args)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
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
    // 1: count(bool)const
    if (numArgs == 0) {
        overloadId = 0; // count()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 1; // count(bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_count_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // count() const
        {

            if (!PyErr_Occurred()) {
                // count()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QBitArray*>(cppSelf)->count();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // count(bool on) const
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // count(bool)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QBitArray*>(cppSelf)->count(cppArg0);
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

    Sbk_QBitArrayFunc_count_TypeError:
        const char* overloads[] = {"", "bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBitArray.count", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_fill(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QBitArray.fill(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QBitArray.fill(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:fill", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: fill(bool,int,int)
    // 1: fill(bool,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // fill(bool,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // fill(bool,int)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // fill(bool,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_fill_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fill(bool val, int first, int last)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // fill(bool,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fill(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // fill(bool val, int size)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "size");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QBitArray.fill(): got multiple values for keyword argument 'size'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QBitArrayFunc_fill_TypeError;
                }
            }
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = -1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fill(bool,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->fill(cppArg0, cppArg1);
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

    Sbk_QBitArrayFunc_fill_TypeError:
        const char* overloads[] = {"bool, int, int", "bool, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBitArray.fill", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_isEmpty(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBitArray*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QBitArrayFunc_isNull(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBitArray*>(cppSelf)->isNull();
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

static PyObject* Sbk_QBitArrayFunc_resize(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resize(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // resize(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_resize_TypeError;

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

    Sbk_QBitArrayFunc_resize_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.resize", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_setBit(PyObject* self, PyObject* args)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setBit", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setBit(int)
    // 1: setBit(int,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setBit(int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 1; // setBit(int,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_setBit_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setBit(int i)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setBit(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBit(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setBit(int i, bool val)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setBit(int,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBit(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBitArrayFunc_setBit_TypeError:
        const char* overloads[] = {"int", "int, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QBitArray.setBit", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_size(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QBitArray*>(cppSelf)->size();
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

static PyObject* Sbk_QBitArrayFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QBitArray&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // swap(QBitArray&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QBitArray&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBitArrayFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.swap", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_testBit(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testBit(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // testBit(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_testBit_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testBit(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBitArray*>(cppSelf)->testBit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc_testBit_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.testBit", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_toggleBit(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toggleBit(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // toggleBit(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_toggleBit_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toggleBit(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->toggleBit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc_toggleBit_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.toggleBit", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc_truncate(PyObject* self, PyObject* pyArg)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: truncate(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // truncate(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc_truncate_TypeError;

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

    Sbk_QBitArrayFunc_truncate_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.truncate", overloads);
        return 0;
}

static PyObject* Sbk_QBitArray___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitArray& cppSelf = *(((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QBitArray_methods[] = {
    {"at", (PyCFunction)Sbk_QBitArrayFunc_at, METH_O},
    {"clear", (PyCFunction)Sbk_QBitArrayFunc_clear, METH_NOARGS},
    {"clearBit", (PyCFunction)Sbk_QBitArrayFunc_clearBit, METH_O},
    {"count", (PyCFunction)Sbk_QBitArrayFunc_count, METH_VARARGS},
    {"fill", (PyCFunction)Sbk_QBitArrayFunc_fill, METH_VARARGS|METH_KEYWORDS},
    {"isEmpty", (PyCFunction)Sbk_QBitArrayFunc_isEmpty, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QBitArrayFunc_isNull, METH_NOARGS},
    {"resize", (PyCFunction)Sbk_QBitArrayFunc_resize, METH_O},
    {"setBit", (PyCFunction)Sbk_QBitArrayFunc_setBit, METH_VARARGS},
    {"size", (PyCFunction)Sbk_QBitArrayFunc_size, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QBitArrayFunc_swap, METH_O},
    {"testBit", (PyCFunction)Sbk_QBitArrayFunc_testBit, METH_O},
    {"toggleBit", (PyCFunction)Sbk_QBitArrayFunc_toggleBit, METH_O},
    {"truncate", (PyCFunction)Sbk_QBitArrayFunc_truncate, METH_O},

    {"__copy__", (PyCFunction)Sbk_QBitArray___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QBitArray___nb_bool(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QBitArrayFunc___and__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rand__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rand__"));
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
    // 0: operator&(QBitArray,QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator&(QBitArray,QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___and___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator&(QBitArray,QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitArray cppResult = (*cppSelf) & (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc___and___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__and__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___iand__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator&=(QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator&=(QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___iand___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator&=(QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) &= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QBitArrayFunc___iand___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__iand__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___xor__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rxor__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rxor__"));
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
    // 0: operator^(QBitArray,QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator^(QBitArray,QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___xor___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator^(QBitArray,QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitArray cppResult = (*cppSelf) ^ (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc___xor___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__xor__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___ixor__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator^=(QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator^=(QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___ixor___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator^=(QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) ^= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QBitArrayFunc___ixor___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__ixor__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___or__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__ror__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__ror__"));
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
    // 0: operator|(QBitArray,QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator|(QBitArray,QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___or___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator|(QBitArray,QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitArray cppResult = (*cppSelf) | (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBitArrayFunc___or___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__or__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___ior__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator|=(QBitArray)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
        overloadId = 0; // operator|=(QBitArray)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBitArrayFunc___ior___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBitArray cppArg0_local = ::QBitArray();
        ::QBitArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator|=(QBitArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) |= (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QBitArrayFunc___ior___TypeError:
        const char* overloads[] = {"PySide.QtCore.QBitArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QBitArray.__ior__", overloads);
        return 0;
}

static PyObject* Sbk_QBitArrayFunc___invert__(PyObject* self)
{
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // operator~()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBitArray cppResult = ~ (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

Py_ssize_t Sbk_QBitArrayFunc___len__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    return cppSelf->size();

    // End of code injection
}

PyObject* Sbk_QBitArrayFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    bool ret = cppSelf->at(_i);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ret);

    // End of code injection
}

int Sbk_QBitArrayFunc___setitem__(PyObject* self, Py_ssize_t _i, PyObject* _value)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    // Begin code injection

    PyObject* args = Py_BuildValue("(iiO)", _i, 1, _value);
    PyObject* result = Sbk_QBitArrayFunc_setBit(self, args);
    Py_DECREF(args);
    Py_XDECREF(result);
    return !result ? -1 : 0;

    // End of code injection
}

// Rich comparison
static PyObject* Sbk_QBitArray_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBitArray& cppSelf = *(((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
                // operator!=(const QBitArray & a) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QBitArray cppArg0_local = ::QBitArray();
                ::QBitArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
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
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (pyArg)))) {
                // operator==(const QBitArray & a) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QBitArray cppArg0_local = ::QBitArray();
                ::QBitArray* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], pythonToCpp))
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
        default:
            goto Sbk_QBitArray_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QBitArray_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QBitArray_HashFunc(PyObject* self) {
    ::QBitArray* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)self));
    return qHash(*cppSelf);
}

static int Sbk_QBitArray_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QBitArray_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QBitArray_TypeAsNumber;

static PySequenceMethods Sbk_QBitArray_TypeAsSequence;

static SbkObjectType Sbk_QBitArray_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QBitArray",
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
    /*tp_hash*/             &Sbk_QBitArray_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QBitArray_traverse,
    /*tp_clear*/            Sbk_QBitArray_clear,
    /*tp_richcompare*/      Sbk_QBitArray_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QBitArray_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QBitArray_Init,
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
static void QBitArray_PythonToCpp_QBitArray_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QBitArray_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QBitArray_PythonToCpp_QBitArray_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBitArray_Type))
        return QBitArray_PythonToCpp_QBitArray_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QBitArray_PTR_CppToPython_QBitArray(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QBitArray*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QBitArray_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QBitArray_COPY_CppToPython_QBitArray(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QBitArray_Type, new ::QBitArray(*((::QBitArray*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QBitArray_PythonToCpp_QBitArray_COPY(PyObject* pyIn, void* cppOut) {
    *((::QBitArray*)cppOut) = *((::QBitArray*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QBitArray_PythonToCpp_QBitArray_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBitArray_Type))
        return QBitArray_PythonToCpp_QBitArray_COPY;
    return 0;
}

void init_QBitArray(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QBitArray_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QBitArray_TypeAsNumber.nb_inplace_or = Sbk_QBitArrayFunc___ior__;
    Sbk_QBitArray_TypeAsNumber.nb_or = Sbk_QBitArrayFunc___or__;
    Sbk_QBitArray_TypeAsNumber.nb_inplace_and = Sbk_QBitArrayFunc___iand__;
    Sbk_QBitArray_TypeAsNumber.nb_and = Sbk_QBitArrayFunc___and__;
    Sbk_QBitArray_TypeAsNumber.nb_xor = Sbk_QBitArrayFunc___xor__;
    SBK_NB_BOOL(Sbk_QBitArray_TypeAsNumber) = Sbk_QBitArray___nb_bool;
    Sbk_QBitArray_TypeAsNumber.nb_invert = Sbk_QBitArrayFunc___invert__;
    Sbk_QBitArray_TypeAsNumber.nb_inplace_xor = Sbk_QBitArrayFunc___ixor__;
    Sbk_QBitArray_Type.super.ht_type.tp_as_number = &Sbk_QBitArray_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QBitArray_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QBitArray_TypeAsSequence.sq_length = &Sbk_QBitArrayFunc___len__;
    Sbk_QBitArray_TypeAsSequence.sq_item = &Sbk_QBitArrayFunc___getitem__;
    Sbk_QBitArray_TypeAsSequence.sq_ass_item = &Sbk_QBitArrayFunc___setitem__;
    Sbk_QBitArray_Type.super.ht_type.tp_as_sequence = &Sbk_QBitArray_TypeAsSequence;

    SbkPySide_QtCoreTypes[SBK_QBITARRAY_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QBitArray_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QBitArray", "QBitArray",
        &Sbk_QBitArray_Type, &Shiboken::callCppDestructor< ::QBitArray >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QBitArray_Type,
        QBitArray_PythonToCpp_QBitArray_PTR,
        is_QBitArray_PythonToCpp_QBitArray_PTR_Convertible,
        QBitArray_PTR_CppToPython_QBitArray,
        QBitArray_COPY_CppToPython_QBitArray);

    Shiboken::Conversions::registerConverterName(converter, "QBitArray");
    Shiboken::Conversions::registerConverterName(converter, "QBitArray*");
    Shiboken::Conversions::registerConverterName(converter, "QBitArray&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBitArray).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QBitArray_PythonToCpp_QBitArray_COPY,
        is_QBitArray_PythonToCpp_QBitArray_COPY_Convertible);


    qRegisterMetaType< ::QBitArray >("QBitArray");
}
