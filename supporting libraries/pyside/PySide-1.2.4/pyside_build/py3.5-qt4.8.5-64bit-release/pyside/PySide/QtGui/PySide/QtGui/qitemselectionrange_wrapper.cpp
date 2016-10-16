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
#include "pyside_qtgui_python.h"

#include "qitemselectionrange_wrapper.h"

// Extra includes
#include <qabstractitemmodel.h>
#include <qitemselectionmodel.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QItemSelectionRange_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QItemSelectionRange >()))
        return -1;

    ::QItemSelectionRange* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QItemSelectionRange", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QItemSelectionRange()
    // 1: QItemSelectionRange(QItemSelectionRange)
    // 2: QItemSelectionRange(QModelIndex)
    // 3: QItemSelectionRange(QModelIndex,QModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // QItemSelectionRange()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QItemSelectionRange(QModelIndex)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
            overloadId = 3; // QItemSelectionRange(QModelIndex,QModelIndex)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QItemSelectionRange(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionRange_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QItemSelectionRange()
        {

            if (!PyErr_Occurred()) {
                // QItemSelectionRange()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelectionRange();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QItemSelectionRange(const QItemSelectionRange & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
            ::QItemSelectionRange* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QItemSelectionRange(QItemSelectionRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelectionRange(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QItemSelectionRange(const QModelIndex & index)
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
                // QItemSelectionRange(QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelectionRange(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QItemSelectionRange(const QModelIndex & topLeft, const QModelIndex & bottomRight)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QModelIndex cppArg1_local = ::QModelIndex();
            ::QModelIndex* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QItemSelectionRange(QModelIndex,QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelectionRange(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QItemSelectionRange >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QItemSelectionRange_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QItemSelectionRange_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QItemSelectionRange", "PySide.QtCore.QModelIndex", "PySide.QtCore.QModelIndex, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionRange", overloads);
        return -1;
}

static PyObject* Sbk_QItemSelectionRangeFunc_bottom(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottom()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->bottom();
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

static PyObject* Sbk_QItemSelectionRangeFunc_bottomRight(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottomRight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->bottomRight();
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

static PyObject* Sbk_QItemSelectionRangeFunc_contains(PyObject* self, PyObject* args)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QItemSelectionRangeFunc_contains_TypeError;

    if (!PyArg_UnpackTuple(args, "contains", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: contains(QModelIndex)const
    // 1: contains(int,int,QModelIndex)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[2])))) {
        overloadId = 1; // contains(int,int,QModelIndex)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 0; // contains(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionRangeFunc_contains_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // contains(const QModelIndex & index) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // contains(QModelIndex)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->contains(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // contains(int row, int column, const QModelIndex & parentIndex) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QModelIndex cppArg2_local = ::QModelIndex();
            ::QModelIndex* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // contains(int,int,QModelIndex)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->contains(cppArg0, cppArg1, *cppArg2);
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

    Sbk_QItemSelectionRangeFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", "int, int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionRange.contains", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionRangeFunc_height(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->height();
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

static PyObject* Sbk_QItemSelectionRangeFunc_indexes(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indexes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->indexes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionRangeFunc_intersected(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersected(QItemSelectionRange)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // intersected(QItemSelectionRange)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionRangeFunc_intersected_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // intersected(QItemSelectionRange)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->intersected(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionRangeFunc_intersected_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelectionRange.intersected", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionRangeFunc_intersects(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: intersects(QItemSelectionRange)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // intersects(QItemSelectionRange)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionRangeFunc_intersects_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // intersects(QItemSelectionRange)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->intersects(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionRangeFunc_intersects_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelectionRange.intersects", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionRangeFunc_isEmpty(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QItemSelectionRangeFunc_isValid(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->isValid();
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

static PyObject* Sbk_QItemSelectionRangeFunc_left(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // left()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->left();
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

static PyObject* Sbk_QItemSelectionRangeFunc_model(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractItemModel * cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->model();
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

static PyObject* Sbk_QItemSelectionRangeFunc_parent(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->parent();
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

static PyObject* Sbk_QItemSelectionRangeFunc_right(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // right()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->right();
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

static PyObject* Sbk_QItemSelectionRangeFunc_top(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // top()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->top();
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

static PyObject* Sbk_QItemSelectionRangeFunc_topLeft(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topLeft()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->topLeft();
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

static PyObject* Sbk_QItemSelectionRangeFunc_width(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelectionRange*>(cppSelf)->width();
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

static PyObject* Sbk_QItemSelectionRange___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QItemSelectionRange& cppSelf = *(((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QItemSelectionRange_methods[] = {
    {"bottom", (PyCFunction)Sbk_QItemSelectionRangeFunc_bottom, METH_NOARGS},
    {"bottomRight", (PyCFunction)Sbk_QItemSelectionRangeFunc_bottomRight, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QItemSelectionRangeFunc_contains, METH_VARARGS},
    {"height", (PyCFunction)Sbk_QItemSelectionRangeFunc_height, METH_NOARGS},
    {"indexes", (PyCFunction)Sbk_QItemSelectionRangeFunc_indexes, METH_NOARGS},
    {"intersected", (PyCFunction)Sbk_QItemSelectionRangeFunc_intersected, METH_O},
    {"intersects", (PyCFunction)Sbk_QItemSelectionRangeFunc_intersects, METH_O},
    {"isEmpty", (PyCFunction)Sbk_QItemSelectionRangeFunc_isEmpty, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QItemSelectionRangeFunc_isValid, METH_NOARGS},
    {"left", (PyCFunction)Sbk_QItemSelectionRangeFunc_left, METH_NOARGS},
    {"model", (PyCFunction)Sbk_QItemSelectionRangeFunc_model, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QItemSelectionRangeFunc_parent, METH_NOARGS},
    {"right", (PyCFunction)Sbk_QItemSelectionRangeFunc_right, METH_NOARGS},
    {"top", (PyCFunction)Sbk_QItemSelectionRangeFunc_top, METH_NOARGS},
    {"topLeft", (PyCFunction)Sbk_QItemSelectionRangeFunc_topLeft, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QItemSelectionRangeFunc_width, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QItemSelectionRange___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QItemSelectionRange_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QItemSelectionRange& cppSelf = *(((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
                // operator!=(const QItemSelectionRange & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
                ::QItemSelectionRange* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
                // operator<(const QItemSelectionRange & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
                ::QItemSelectionRange* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QItemSelectionRange_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
                // operator==(const QItemSelectionRange & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
                ::QItemSelectionRange* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp))
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
            goto Sbk_QItemSelectionRange_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QItemSelectionRange_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QItemSelectionRange_HashFunc(PyObject* self) {
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
    return qHash(*cppSelf);
}

static int Sbk_QItemSelectionRange_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QItemSelectionRange_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QItemSelectionRange__repr__(PyObject* self)
{
    ::QItemSelectionRange* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QItemSelectionRange_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QItemSelectionRange",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QItemSelectionRange__repr__,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             &Sbk_QItemSelectionRange_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QItemSelectionRange_traverse,
    /*tp_clear*/            Sbk_QItemSelectionRange_clear,
    /*tp_richcompare*/      Sbk_QItemSelectionRange_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QItemSelectionRange_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QItemSelectionRange_Init,
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
static void QItemSelectionRange_PythonToCpp_QItemSelectionRange_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QItemSelectionRange_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QItemSelectionRange_PythonToCpp_QItemSelectionRange_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemSelectionRange_Type))
        return QItemSelectionRange_PythonToCpp_QItemSelectionRange_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QItemSelectionRange_PTR_CppToPython_QItemSelectionRange(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QItemSelectionRange*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QItemSelectionRange_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QItemSelectionRange_COPY_CppToPython_QItemSelectionRange(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QItemSelectionRange_Type, new ::QItemSelectionRange(*((::QItemSelectionRange*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QItemSelectionRange_PythonToCpp_QItemSelectionRange_COPY(PyObject* pyIn, void* cppOut) {
    *((::QItemSelectionRange*)cppOut) = *((::QItemSelectionRange*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QItemSelectionRange_PythonToCpp_QItemSelectionRange_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemSelectionRange_Type))
        return QItemSelectionRange_PythonToCpp_QItemSelectionRange_COPY;
    return 0;
}

void init_QItemSelectionRange(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QItemSelectionRange_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QItemSelectionRange", "QItemSelectionRange",
        &Sbk_QItemSelectionRange_Type, &Shiboken::callCppDestructor< ::QItemSelectionRange >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QItemSelectionRange_Type,
        QItemSelectionRange_PythonToCpp_QItemSelectionRange_PTR,
        is_QItemSelectionRange_PythonToCpp_QItemSelectionRange_PTR_Convertible,
        QItemSelectionRange_PTR_CppToPython_QItemSelectionRange,
        QItemSelectionRange_COPY_CppToPython_QItemSelectionRange);

    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionRange");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionRange*");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionRange&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemSelectionRange).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QItemSelectionRange_PythonToCpp_QItemSelectionRange_COPY,
        is_QItemSelectionRange_PythonToCpp_QItemSelectionRange_COPY_Convertible);


    qRegisterMetaType< ::QItemSelectionRange >("QItemSelectionRange");
}
