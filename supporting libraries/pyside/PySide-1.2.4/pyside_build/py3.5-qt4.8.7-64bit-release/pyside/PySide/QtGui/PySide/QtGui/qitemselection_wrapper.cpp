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

#include "qitemselection_wrapper.h"

// Extra includes
#include <QList>
#include <QSet>
#include <QVector>
#include <qabstractitemmodel.h>
#include <qitemselectionmodel.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QItemSelection_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QItemSelection >()))
        return -1;

    ::QItemSelection* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QItemSelection", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QItemSelection()
    // 1: QItemSelection(QItemSelection)
    // 2: QItemSelection(QModelIndex,QModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // QItemSelection()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 2; // QItemSelection(QModelIndex,QModelIndex)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[0])))) {
        overloadId = 1; // QItemSelection(QItemSelection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelection_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QItemSelection()
        {

            if (!PyErr_Occurred()) {
                // QItemSelection()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelection();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QItemSelection(const QItemSelection & QItemSelection)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QItemSelection cppArg0_local = ::QItemSelection();
            ::QItemSelection* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QItemSelection(QItemSelection)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelection(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QItemSelection(const QModelIndex & topLeft, const QModelIndex & bottomRight)
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
                // QItemSelection(QModelIndex,QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QItemSelection(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QItemSelection >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QItemSelection_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QItemSelection_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QItemSelection", "PySide.QtCore.QModelIndex, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection", overloads);
        return -1;
}

static PyObject* Sbk_QItemSelectionFunc_append(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: append(QItemSelectionRange)
    // 1: append(QList<QItemSelectionRange>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // append(QItemSelectionRange)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 1; // append(QList<QItemSelectionRange>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_append_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // append(const QItemSelectionRange & t)
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
                // append(QItemSelectionRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // append(const QList<QItemSelectionRange > & t)
        {
            ::QList<QItemSelectionRange > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // append(QList<QItemSelectionRange>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->append(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_append_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.append", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QItemSelectionRange & cppResult = const_cast<const ::QItemSelection*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.at", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_back(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // back()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange & cppResult = cppSelf->back();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_clear(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QItemSelectionFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // contains(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_contains_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // contains(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->contains(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.contains", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_count(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
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
    // 1: count(QItemSelectionRange)const
    if (numArgs == 0) {
        overloadId = 0; // count()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))) {
        overloadId = 1; // count(QItemSelectionRange)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_count_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // count() const
        {

            if (!PyErr_Occurred()) {
                // count()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->count();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // count(const QItemSelectionRange & t) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
            ::QItemSelectionRange* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // count(QItemSelectionRange)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->count(*cppArg0);
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

    Sbk_QItemSelectionFunc_count_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.count", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_detachShared(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // detachShared()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->detachShared();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionFunc_empty(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // empty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->empty();
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

static PyObject* Sbk_QItemSelectionFunc_endsWith(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: endsWith(QItemSelectionRange)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // endsWith(QItemSelectionRange)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_endsWith_TypeError;

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
            // endsWith(QItemSelectionRange)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->endsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_endsWith_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.endsWith", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_first(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // first()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange & cppResult = cppSelf->first();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_fromSet(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromSet(QSet<QItemSelectionRange>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // fromSet(QSet<QItemSelectionRange>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_fromSet_TypeError;

    // Call function/method
    {
        ::QSet<QItemSelectionRange > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromSet(QSet<QItemSelectionRange>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QItemSelectionRange > cppResult = ::QItemSelection::fromSet(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_fromSet_TypeError:
        const char* overloads[] = {"QSet", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.fromSet", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_fromVector(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromVector(QVector<QItemSelectionRange>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // fromVector(QVector<QItemSelectionRange>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_fromVector_TypeError;

    // Call function/method
    {
        ::QVector<QItemSelectionRange > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromVector(QVector<QItemSelectionRange>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QItemSelectionRange > cppResult = ::QItemSelection::fromVector(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_fromVector_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.fromVector", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_front(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // front()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange & cppResult = cppSelf->front();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_indexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.indexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.indexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:indexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: indexOf(QItemSelectionRange,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexOf(QItemSelectionRange,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // indexOf(QItemSelectionRange,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_indexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.indexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QItemSelectionFunc_indexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // indexOf(QItemSelectionRange,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->indexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_indexOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.indexOf", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_indexes(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // indexes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = const_cast<const ::QItemSelection*>(cppSelf)->indexes();
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

static PyObject* Sbk_QItemSelectionFunc_insert(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insert", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insert(int,QItemSelectionRange)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[1])))) {
        overloadId = 0; // insert(int,QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_insert_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemSelectionRange cppArg1_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // insert(int,QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insert(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_insert_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.insert", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_isEmpty(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QItemSelectionFunc_isSharedWith(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSharedWith(QList<QItemSelectionRange>)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // isSharedWith(QList<QItemSelectionRange>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_isSharedWith_TypeError;

    // Call function/method
    {
        ::QList<QItemSelectionRange > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isSharedWith(QList<QItemSelectionRange>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->isSharedWith(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_isSharedWith_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.isSharedWith", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_last(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // last()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange & cppResult = cppSelf->last();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_lastIndexOf(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.lastIndexOf(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.lastIndexOf(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:lastIndexOf", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: lastIndexOf(QItemSelectionRange,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // lastIndexOf(QItemSelectionRange,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // lastIndexOf(QItemSelectionRange,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_lastIndexOf_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "from");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.lastIndexOf(): got multiple values for keyword argument 'from'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QItemSelectionFunc_lastIndexOf_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // lastIndexOf(QItemSelectionRange,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->lastIndexOf(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_lastIndexOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.lastIndexOf", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_length(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // length()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->length();
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

static PyObject* Sbk_QItemSelectionFunc_merge(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "merge", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: merge(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // merge(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_merge_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelection cppArg0_local = ::QItemSelection();
        ::QItemSelection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QFlags<QItemSelectionModel::SelectionFlag> cppArg1 = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // merge(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->merge(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_merge_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelection, PySide.QtGui.QItemSelectionModel.SelectionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.merge", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_mid(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.mid(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.mid(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_mid_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "length");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelection.mid(): got multiple values for keyword argument 'length'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QItemSelectionFunc_mid_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // mid(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QItemSelectionRange > cppResult = const_cast<const ::QItemSelection*>(cppSelf)->mid(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_mid_TypeError:
        const char* overloads[] = {"int, int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.mid", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_move(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "move", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: move(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // move(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_move_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // move(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->move(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_move_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.move", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_pop_back(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pop_back()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pop_back();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionFunc_pop_front(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pop_front()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->pop_front();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionFunc_prepend(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: prepend(QItemSelectionRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // prepend(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_prepend_TypeError;

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
            // prepend(QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->prepend(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_prepend_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.prepend", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_push_back(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: push_back(QItemSelectionRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // push_back(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_push_back_TypeError;

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
            // push_back(QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->push_back(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_push_back_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.push_back", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_push_front(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: push_front(QItemSelectionRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // push_front(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_push_front_TypeError;

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
            // push_front(QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->push_front(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_push_front_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.push_front", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_removeAll(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAll(QItemSelectionRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // removeAll(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_removeAll_TypeError;

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
            // removeAll(QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->removeAll(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_removeAll_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.removeAll", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_removeAt(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_removeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_removeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.removeAt", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_removeFirst(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeFirst()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeFirst();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionFunc_removeLast(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeLast()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeLast();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionFunc_removeOne(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeOne(QItemSelectionRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // removeOne(QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_removeOne_TypeError;

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
            // removeOne(QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->removeOne(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_removeOne_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.removeOne", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_replace(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(int,QItemSelectionRange)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(int,QItemSelectionRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_replace_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemSelectionRange cppArg1_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // replace(int,QItemSelectionRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->replace(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_replace_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.replace", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_reserve(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reserve(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // reserve(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_reserve_TypeError;

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

    Sbk_QItemSelectionFunc_reserve_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.reserve", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_select(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "select", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: select(QModelIndex,QModelIndex)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // select(QModelIndex,QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_select_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // select(QModelIndex,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->select(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_select_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.select", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_setSharable(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSharable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSharable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_setSharable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSharable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSharable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_setSharable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.setSharable", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_size(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QItemSelection*>(cppSelf)->size();
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

static PyObject* Sbk_QItemSelectionFunc_split(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "split", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: split(QItemSelectionRange,QItemSelectionRange,QItemSelection*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[2])))) {
        overloadId = 0; // split(QItemSelectionRange,QItemSelectionRange,QItemSelection*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_split_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelectionRange cppArg0_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemSelectionRange cppArg1_local = ::QItemSelectionRange();
        ::QItemSelectionRange* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QItemSelection* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // split(QItemSelectionRange,QItemSelectionRange,QItemSelection*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QItemSelection::split(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_split_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange, PySide.QtGui.QItemSelectionRange, PySide.QtGui.QItemSelection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.split", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_startsWith(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startsWith(QItemSelectionRange)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // startsWith(QItemSelectionRange)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_startsWith_TypeError;

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
            // startsWith(QItemSelectionRange)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelection*>(cppSelf)->startsWith(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_startsWith_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.startsWith", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_swap(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "swap", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: swap(QList<QItemSelectionRange>&)
    // 1: swap(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // swap(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArgs[0])))) {
        overloadId = 0; // swap(QList<QItemSelectionRange>&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_swap_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // swap(QList<QItemSelectionRange > & other)
        {
            ::QList<QItemSelectionRange > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // swap(QList<QItemSelectionRange>&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->swap(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // swap(int i, int j)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // swap(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->swap(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionFunc_swap_TypeError:
        const char* overloads[] = {"list", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.swap", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_takeAt(PyObject* self, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_takeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange cppResult = cppSelf->takeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_takeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.takeAt", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc_takeFirst(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // takeFirst()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange cppResult = cppSelf->takeFirst();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_takeLast(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // takeLast()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionRange cppResult = cppSelf->takeLast();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_toSet(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toSet()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSet<QItemSelectionRange > cppResult = const_cast<const ::QItemSelection*>(cppSelf)->toSet();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QSET_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_toVector(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVector()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QItemSelectionRange > cppResult = const_cast<const ::QItemSelection*>(cppSelf)->toVector();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionFunc_value(PyObject* self, PyObject* args)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "value", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: value(int)const
    // 1: value(int,QItemSelectionRange)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // value(int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArgs[1])))) {
            overloadId = 1; // value(int,QItemSelectionRange)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc_value_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // value(int i) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // value(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QItemSelectionRange cppResult = const_cast<const ::QItemSelection*>(cppSelf)->value(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // value(int i, const QItemSelectionRange & defaultValue) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QItemSelectionRange cppArg1_local = ::QItemSelectionRange();
            ::QItemSelectionRange* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // value(int,QItemSelectionRange)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QItemSelectionRange cppResult = const_cast<const ::QItemSelection*>(cppSelf)->value(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc_value_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtGui.QItemSelectionRange", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelection.value", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelection___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QItemSelection& cppSelf = *(((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QItemSelection_methods[] = {
    {"append", (PyCFunction)Sbk_QItemSelectionFunc_append, METH_O},
    {"at", (PyCFunction)Sbk_QItemSelectionFunc_at, METH_O},
    {"back", (PyCFunction)Sbk_QItemSelectionFunc_back, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QItemSelectionFunc_clear, METH_NOARGS},
    {"contains", (PyCFunction)Sbk_QItemSelectionFunc_contains, METH_O},
    {"count", (PyCFunction)Sbk_QItemSelectionFunc_count, METH_VARARGS},
    {"detachShared", (PyCFunction)Sbk_QItemSelectionFunc_detachShared, METH_NOARGS},
    {"empty", (PyCFunction)Sbk_QItemSelectionFunc_empty, METH_NOARGS},
    {"endsWith", (PyCFunction)Sbk_QItemSelectionFunc_endsWith, METH_O},
    {"first", (PyCFunction)Sbk_QItemSelectionFunc_first, METH_NOARGS},
    {"fromSet", (PyCFunction)Sbk_QItemSelectionFunc_fromSet, METH_O|METH_STATIC},
    {"fromVector", (PyCFunction)Sbk_QItemSelectionFunc_fromVector, METH_O|METH_STATIC},
    {"front", (PyCFunction)Sbk_QItemSelectionFunc_front, METH_NOARGS},
    {"indexOf", (PyCFunction)Sbk_QItemSelectionFunc_indexOf, METH_VARARGS|METH_KEYWORDS},
    {"indexes", (PyCFunction)Sbk_QItemSelectionFunc_indexes, METH_NOARGS},
    {"insert", (PyCFunction)Sbk_QItemSelectionFunc_insert, METH_VARARGS},
    {"isEmpty", (PyCFunction)Sbk_QItemSelectionFunc_isEmpty, METH_NOARGS},
    {"isSharedWith", (PyCFunction)Sbk_QItemSelectionFunc_isSharedWith, METH_O},
    {"last", (PyCFunction)Sbk_QItemSelectionFunc_last, METH_NOARGS},
    {"lastIndexOf", (PyCFunction)Sbk_QItemSelectionFunc_lastIndexOf, METH_VARARGS|METH_KEYWORDS},
    {"length", (PyCFunction)Sbk_QItemSelectionFunc_length, METH_NOARGS},
    {"merge", (PyCFunction)Sbk_QItemSelectionFunc_merge, METH_VARARGS},
    {"mid", (PyCFunction)Sbk_QItemSelectionFunc_mid, METH_VARARGS|METH_KEYWORDS},
    {"move", (PyCFunction)Sbk_QItemSelectionFunc_move, METH_VARARGS},
    {"pop_back", (PyCFunction)Sbk_QItemSelectionFunc_pop_back, METH_NOARGS},
    {"pop_front", (PyCFunction)Sbk_QItemSelectionFunc_pop_front, METH_NOARGS},
    {"prepend", (PyCFunction)Sbk_QItemSelectionFunc_prepend, METH_O},
    {"push_back", (PyCFunction)Sbk_QItemSelectionFunc_push_back, METH_O},
    {"push_front", (PyCFunction)Sbk_QItemSelectionFunc_push_front, METH_O},
    {"removeAll", (PyCFunction)Sbk_QItemSelectionFunc_removeAll, METH_O},
    {"removeAt", (PyCFunction)Sbk_QItemSelectionFunc_removeAt, METH_O},
    {"removeFirst", (PyCFunction)Sbk_QItemSelectionFunc_removeFirst, METH_NOARGS},
    {"removeLast", (PyCFunction)Sbk_QItemSelectionFunc_removeLast, METH_NOARGS},
    {"removeOne", (PyCFunction)Sbk_QItemSelectionFunc_removeOne, METH_O},
    {"replace", (PyCFunction)Sbk_QItemSelectionFunc_replace, METH_VARARGS},
    {"reserve", (PyCFunction)Sbk_QItemSelectionFunc_reserve, METH_O},
    {"select", (PyCFunction)Sbk_QItemSelectionFunc_select, METH_VARARGS},
    {"setSharable", (PyCFunction)Sbk_QItemSelectionFunc_setSharable, METH_O},
    {"size", (PyCFunction)Sbk_QItemSelectionFunc_size, METH_NOARGS},
    {"split", (PyCFunction)Sbk_QItemSelectionFunc_split, METH_VARARGS|METH_STATIC},
    {"startsWith", (PyCFunction)Sbk_QItemSelectionFunc_startsWith, METH_O},
    {"swap", (PyCFunction)Sbk_QItemSelectionFunc_swap, METH_VARARGS},
    {"takeAt", (PyCFunction)Sbk_QItemSelectionFunc_takeAt, METH_O},
    {"takeFirst", (PyCFunction)Sbk_QItemSelectionFunc_takeFirst, METH_NOARGS},
    {"takeLast", (PyCFunction)Sbk_QItemSelectionFunc_takeLast, METH_NOARGS},
    {"toSet", (PyCFunction)Sbk_QItemSelectionFunc_toSet, METH_NOARGS},
    {"toVector", (PyCFunction)Sbk_QItemSelectionFunc_toVector, METH_NOARGS},
    {"value", (PyCFunction)Sbk_QItemSelectionFunc_value, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QItemSelection___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QItemSelectionFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
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
    // 0: operator+(QList<QItemSelectionRange>)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QList<QItemSelectionRange>)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc___add___TypeError;

    // Call function/method
    {
        ::QList<QItemSelectionRange > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator+(QList<QItemSelectionRange>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QItemSelectionRange > cppResult = (*cppSelf) + cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionFunc___add___TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QItemSelectionRange)
    // 1: operator+=(QList<QItemSelectionRange>)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QItemSelectionRange)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 1; // operator+=(QList<QItemSelectionRange>)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc___iadd___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator+=(const QItemSelectionRange & t)
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
                // operator+=(QItemSelectionRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) += (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // operator+=(const QList<QItemSelectionRange > & l)
        {
            ::QList<QItemSelectionRange > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator+=(QList<QItemSelectionRange>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (*cppSelf) += cppArg0;
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

    Sbk_QItemSelectionFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
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
    // 0: operator<<(QItemSelectionRange)
    // 1: operator<<(QList<QItemSelectionRange>)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QItemSelectionRange)
    } else if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        overloadId = 1; // operator<<(QList<QItemSelectionRange>)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionFunc___lshift___TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // operator<<(const QItemSelectionRange & t)
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
                // operator<<(QItemSelectionRange)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QItemSelectionRange > & cppResult = (*cppSelf) << (*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
            }
            break;
        }
        case 1: // operator<<(const QList<QItemSelectionRange > & l)
        {
            ::QList<QItemSelectionRange > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // operator<<(QList<QItemSelectionRange>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QItemSelectionRange > & cppResult = (*cppSelf) << cppArg0;
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], &cppResult);
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

    Sbk_QItemSelectionFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionRange", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelection.__lshift__", overloads);
        return 0;
}

Py_ssize_t Sbk_QItemSelection__len__(PyObject* self)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    return cppSelf->size();
}
PyObject* Sbk_QItemSelection__getitem__(PyObject* self, Py_ssize_t _i)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    QItemSelection::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], &*_item);
}
int Sbk_QItemSelection__setitem__(PyObject* self, Py_ssize_t _i, PyObject* pyArg)
{
    ::QItemSelection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self));
    if (_i < 0 || _i >= (Py_ssize_t) cppSelf->size()) {
        PyErr_SetString(PyExc_IndexError, "list assignment index out of range");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
        PyErr_SetString(PyExc_TypeError, "attributed value with wrong type, 'QItemSelectionRange' or other convertible type expected");
        return -1;
    }
    if (!Shiboken::Object::isValid(pyArg))
        return -1;
    ::QItemSelectionRange cppValue = ::QItemSelectionRange();
    pythonToCpp(pyArg, &cppValue);
    QItemSelection::iterator _item = cppSelf->begin();
    for (Py_ssize_t pos = 0; pos < _i; pos++) _item++;
    *_item = cppValue;
    return 0;
}
// Rich comparison
static PyObject* Sbk_QItemSelection_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QItemSelection& cppSelf = *(((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
                // operator!=(const QList<QItemSelectionRange > & l) const
                ::QList<QItemSelectionRange > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf != (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QITEMSELECTIONRANGE_IDX], (pyArg)))) {
                // operator==(const QList<QItemSelectionRange > & l) const
                ::QList<QItemSelectionRange > cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf == (cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QItemSelection_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QItemSelection_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QItemSelection_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QItemSelection_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QItemSelection_TypeAsNumber;

static PySequenceMethods Sbk_QItemSelection_TypeAsSequence;

static SbkObjectType Sbk_QItemSelection_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QItemSelection",
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
    /*tp_traverse*/         Sbk_QItemSelection_traverse,
    /*tp_clear*/            Sbk_QItemSelection_clear,
    /*tp_richcompare*/      Sbk_QItemSelection_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QItemSelection_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QItemSelection_Init,
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
static void QItemSelection_PythonToCpp_QItemSelection_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QItemSelection_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QItemSelection_PythonToCpp_QItemSelection_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemSelection_Type))
        return QItemSelection_PythonToCpp_QItemSelection_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QItemSelection_PTR_CppToPython_QItemSelection(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QItemSelection*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QItemSelection_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QItemSelection_COPY_CppToPython_QItemSelection(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QItemSelection_Type, new ::QItemSelection(*((::QItemSelection*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QItemSelection_PythonToCpp_QItemSelection_COPY(PyObject* pyIn, void* cppOut) {
    *((::QItemSelection*)cppOut) = *((::QItemSelection*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QItemSelection_PythonToCpp_QItemSelection_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemSelection_Type))
        return QItemSelection_PythonToCpp_QItemSelection_COPY;
    return 0;
}

void init_QItemSelection(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QItemSelection_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QItemSelection_TypeAsNumber.nb_lshift = Sbk_QItemSelectionFunc___lshift__;
    Sbk_QItemSelection_TypeAsNumber.nb_inplace_add = Sbk_QItemSelectionFunc___iadd__;
    Sbk_QItemSelection_TypeAsNumber.nb_add = Sbk_QItemSelectionFunc___add__;
    Sbk_QItemSelection_Type.super.ht_type.tp_as_number = &Sbk_QItemSelection_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QItemSelection_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QItemSelection_TypeAsSequence.sq_length = Sbk_QItemSelection__len__;
    Sbk_QItemSelection_TypeAsSequence.sq_item = Sbk_QItemSelection__getitem__;
    Sbk_QItemSelection_TypeAsSequence.sq_ass_item = Sbk_QItemSelection__setitem__;
    Sbk_QItemSelection_Type.super.ht_type.tp_as_sequence = &Sbk_QItemSelection_TypeAsSequence;

    SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QItemSelection_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QItemSelection", "QItemSelection",
        &Sbk_QItemSelection_Type, &Shiboken::callCppDestructor< ::QItemSelection >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QItemSelection_Type,
        QItemSelection_PythonToCpp_QItemSelection_PTR,
        is_QItemSelection_PythonToCpp_QItemSelection_PTR_Convertible,
        QItemSelection_PTR_CppToPython_QItemSelection,
        QItemSelection_COPY_CppToPython_QItemSelection);

    Shiboken::Conversions::registerConverterName(converter, "QItemSelection");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelection*");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelection&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemSelection).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QItemSelection_PythonToCpp_QItemSelection_COPY,
        is_QItemSelection_PythonToCpp_QItemSelection_COPY_Convertible);


    qRegisterMetaType< ::QItemSelection >("QItemSelection");
}
