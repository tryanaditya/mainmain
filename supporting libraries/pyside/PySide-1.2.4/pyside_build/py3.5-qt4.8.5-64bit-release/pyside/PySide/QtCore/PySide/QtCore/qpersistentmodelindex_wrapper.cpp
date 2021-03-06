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

#include "qpersistentmodelindex_wrapper.h"

// Extra includes
#include <qabstractitemmodel.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPersistentModelIndex_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPersistentModelIndex >()))
        return -1;

    ::QPersistentModelIndex* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPersistentModelIndex", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPersistentModelIndex()
    // 1: QPersistentModelIndex(QModelIndex)
    // 2: QPersistentModelIndex(QPersistentModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // QPersistentModelIndex()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 1; // QPersistentModelIndex(QModelIndex)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 2; // QPersistentModelIndex(QPersistentModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPersistentModelIndex_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPersistentModelIndex()
        {

            if (!PyErr_Occurred()) {
                // QPersistentModelIndex()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPersistentModelIndex();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPersistentModelIndex(const QModelIndex & index)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPersistentModelIndex(QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPersistentModelIndex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPersistentModelIndex(const QPersistentModelIndex & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPersistentModelIndex cppArg0_local = ::QPersistentModelIndex();
            ::QPersistentModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPersistentModelIndex(QPersistentModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPersistentModelIndex(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPersistentModelIndex >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPersistentModelIndex_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPersistentModelIndex_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QModelIndex", "PySide.QtCore.QPersistentModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QPersistentModelIndex", overloads);
        return -1;
}

static PyObject* Sbk_QPersistentModelIndexFunc_child(PyObject* self, PyObject* args)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "child", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: child(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // child(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPersistentModelIndexFunc_child_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // child(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->child(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPersistentModelIndexFunc_child_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QPersistentModelIndex.child", overloads);
        return 0;
}

static PyObject* Sbk_QPersistentModelIndexFunc_column(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // column()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->column();
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

static PyObject* Sbk_QPersistentModelIndexFunc_data(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QPersistentModelIndex.data(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:data", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: data(int)const
    if (numArgs == 0) {
        overloadId = 0; // data(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // data(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPersistentModelIndexFunc_data_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QPersistentModelIndex.data(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QPersistentModelIndexFunc_data_TypeError;
            }
        }
        int cppArg0 = Qt::DisplayRole;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // data(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPersistentModelIndexFunc_data_TypeError:
        const char* overloads[] = {"int = Qt.DisplayRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QPersistentModelIndex.data", overloads);
        return 0;
}

static PyObject* Sbk_QPersistentModelIndexFunc_flags(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->flags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPersistentModelIndexFunc_internalId(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // internalId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->internalId();
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

static PyObject* Sbk_QPersistentModelIndexFunc_internalPointer(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // internalPointer()const
            // Begin code injection

            // TEMPLATE - return_internal_pointer - START
            pyResult = reinterpret_cast<PyObject*>(cppSelf->internalPointer());
            if (!pyResult)
            pyResult = Py_None;
            Py_INCREF(pyResult);
            // TEMPLATE - return_internal_pointer - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPersistentModelIndexFunc_isValid(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->isValid();
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

static PyObject* Sbk_QPersistentModelIndexFunc_model(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractItemModel * cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPersistentModelIndexFunc_parent(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPersistentModelIndexFunc_row(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // row()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->row();
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

static PyObject* Sbk_QPersistentModelIndexFunc_sibling(PyObject* self, PyObject* args)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sibling", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sibling(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // sibling(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPersistentModelIndexFunc_sibling_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sibling(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QPersistentModelIndex*>(cppSelf)->sibling(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPersistentModelIndexFunc_sibling_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QPersistentModelIndex.sibling", overloads);
        return 0;
}

static PyObject* Sbk_QPersistentModelIndex___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPersistentModelIndex& cppSelf = *(((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPersistentModelIndex_methods[] = {
    {"child", (PyCFunction)Sbk_QPersistentModelIndexFunc_child, METH_VARARGS},
    {"column", (PyCFunction)Sbk_QPersistentModelIndexFunc_column, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QPersistentModelIndexFunc_data, METH_VARARGS|METH_KEYWORDS},
    {"flags", (PyCFunction)Sbk_QPersistentModelIndexFunc_flags, METH_NOARGS},
    {"internalId", (PyCFunction)Sbk_QPersistentModelIndexFunc_internalId, METH_NOARGS},
    {"internalPointer", (PyCFunction)Sbk_QPersistentModelIndexFunc_internalPointer, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QPersistentModelIndexFunc_isValid, METH_NOARGS},
    {"model", (PyCFunction)Sbk_QPersistentModelIndexFunc_model, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QPersistentModelIndexFunc_parent, METH_NOARGS},
    {"row", (PyCFunction)Sbk_QPersistentModelIndexFunc_row, METH_NOARGS},
    {"sibling", (PyCFunction)Sbk_QPersistentModelIndexFunc_sibling, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QPersistentModelIndex___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QPersistentModelIndex_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPersistentModelIndex& cppSelf = *(((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
                // operator!=(const QModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QModelIndex cppArg0_local = ::QModelIndex();
                ::QModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (pyArg)))) {
                // operator!=(const QPersistentModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPersistentModelIndex cppArg0_local = ::QPersistentModelIndex();
                ::QPersistentModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (pyArg)))) {
                // operator<(const QPersistentModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPersistentModelIndex cppArg0_local = ::QPersistentModelIndex();
                ::QPersistentModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QPersistentModelIndex_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
                // operator==(const QModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QModelIndex cppArg0_local = ::QModelIndex();
                ::QModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (pyArg)))) {
                // operator==(const QPersistentModelIndex & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPersistentModelIndex cppArg0_local = ::QPersistentModelIndex();
                ::QPersistentModelIndex* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], pythonToCpp))
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
            goto Sbk_QPersistentModelIndex_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPersistentModelIndex_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QPersistentModelIndex_HashFunc(PyObject* self) {
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    return qHash(*cppSelf);
}

static int Sbk_QPersistentModelIndex_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPersistentModelIndex_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QPersistentModelIndex__repr__(PyObject* self)
{
    ::QPersistentModelIndex* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPersistentModelIndex_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QPersistentModelIndex",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QPersistentModelIndex__repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QPersistentModelIndex_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QPersistentModelIndex_traverse,
    /*tp_clear*/            Sbk_QPersistentModelIndex_clear,
    /*tp_richcompare*/      Sbk_QPersistentModelIndex_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPersistentModelIndex_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPersistentModelIndex_Init,
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
static void QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPersistentModelIndex_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPersistentModelIndex_Type))
        return QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPersistentModelIndex_PTR_CppToPython_QPersistentModelIndex(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPersistentModelIndex*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPersistentModelIndex_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPersistentModelIndex_COPY_CppToPython_QPersistentModelIndex(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPersistentModelIndex_Type, new ::QPersistentModelIndex(*((::QPersistentModelIndex*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPersistentModelIndex*)cppOut) = *((::QPersistentModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPersistentModelIndex_Type))
        return QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_COPY;
    return 0;
}

// Implicit conversions.
static void constQModelIndexREF_PythonToCpp_QPersistentModelIndex(PyObject* pyIn, void* cppOut) {
    *((::QPersistentModelIndex*)cppOut) = ::QPersistentModelIndex(*((::QModelIndex*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQModelIndexREF_PythonToCpp_QPersistentModelIndex_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyIn))
        return constQModelIndexREF_PythonToCpp_QPersistentModelIndex;
    return 0;
}

void init_QPersistentModelIndex(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QPERSISTENTMODELINDEX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPersistentModelIndex_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPersistentModelIndex", "QPersistentModelIndex",
        &Sbk_QPersistentModelIndex_Type, &Shiboken::callCppDestructor< ::QPersistentModelIndex >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPersistentModelIndex_Type,
        QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_PTR,
        is_QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_PTR_Convertible,
        QPersistentModelIndex_PTR_CppToPython_QPersistentModelIndex,
        QPersistentModelIndex_COPY_CppToPython_QPersistentModelIndex);

    Shiboken::Conversions::registerConverterName(converter, "QPersistentModelIndex");
    Shiboken::Conversions::registerConverterName(converter, "QPersistentModelIndex*");
    Shiboken::Conversions::registerConverterName(converter, "QPersistentModelIndex&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPersistentModelIndex).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_COPY,
        is_QPersistentModelIndex_PythonToCpp_QPersistentModelIndex_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQModelIndexREF_PythonToCpp_QPersistentModelIndex,
        is_constQModelIndexREF_PythonToCpp_QPersistentModelIndex_Convertible);


    qRegisterMetaType< ::QPersistentModelIndex >("QPersistentModelIndex");
}
