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
#include "pyside_qtwebkit_python.h"

#include "qwebelementcollection_wrapper.h"

// Extra includes
#include <QList>
#include <qwebelement.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QWebElementCollection_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QWebElementCollection >()))
        return -1;

    ::QWebElementCollection* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QWebElementCollection", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QWebElementCollection()
    // 1: QWebElementCollection(QWebElement,QString)
    // 2: QWebElementCollection(QWebElementCollection)
    if (numArgs == 0) {
        overloadId = 0; // QWebElementCollection()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (pyArgs[0])))) {
        overloadId = 2; // QWebElementCollection(QWebElementCollection)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // QWebElementCollection(QWebElement,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementCollection_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QWebElementCollection()
        {

            if (!PyErr_Occurred()) {
                // QWebElementCollection()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebElementCollection();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QWebElementCollection(const QWebElement & contextElement, const QString & query)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebElement cppArg0_local = ::QWebElement();
            ::QWebElement* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QWebElementCollection(QWebElement,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebElementCollection(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QWebElementCollection(const QWebElementCollection & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWebElementCollection cppArg0_local = ::QWebElementCollection();
            ::QWebElementCollection* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QWebElementCollection(QWebElementCollection)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QWebElementCollection(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QWebElementCollection >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QWebElementCollection_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QWebElementCollection_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtWebKit.QWebElement, unicode", "PySide.QtWebKit.QWebElementCollection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtWebKit.QWebElementCollection", overloads);
        return -1;
}

static PyObject* Sbk_QWebElementCollectionFunc_append(PyObject* self, PyObject* pyArg)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: append(QWebElementCollection)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (pyArg)))) {
        overloadId = 0; // append(QWebElementCollection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementCollectionFunc_append_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWebElementCollection cppArg0_local = ::QWebElementCollection();
        ::QWebElementCollection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // append(QWebElementCollection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->append(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QWebElementCollectionFunc_append_TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebElementCollection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElementCollection.append", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementCollectionFunc_at(PyObject* self, PyObject* pyArg)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QWebElementCollectionFunc_at_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // at(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElementCollection*>(cppSelf)->at(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementCollectionFunc_at_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElementCollection.at", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementCollectionFunc_count(PyObject* self)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QWebElementCollection*>(cppSelf)->count();
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

static PyObject* Sbk_QWebElementCollectionFunc_first(PyObject* self)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // first()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElementCollection*>(cppSelf)->first();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementCollectionFunc_last(PyObject* self)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // last()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElement cppResult = const_cast<const ::QWebElementCollection*>(cppSelf)->last();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementCollectionFunc_toList(PyObject* self)
{
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toList()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWebElement > cppResult = const_cast<const ::QWebElementCollection*>(cppSelf)->toList();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtWebKitTypeConverters[SBK_QTWEBKIT_QLIST_QWEBELEMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QWebElementCollection___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebElementCollection& cppSelf = *(((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QWebElementCollection_methods[] = {
    {"append", (PyCFunction)Sbk_QWebElementCollectionFunc_append, METH_O},
    {"at", (PyCFunction)Sbk_QWebElementCollectionFunc_at, METH_O},
    {"count", (PyCFunction)Sbk_QWebElementCollectionFunc_count, METH_NOARGS},
    {"first", (PyCFunction)Sbk_QWebElementCollectionFunc_first, METH_NOARGS},
    {"last", (PyCFunction)Sbk_QWebElementCollectionFunc_last, METH_NOARGS},
    {"toList", (PyCFunction)Sbk_QWebElementCollectionFunc_toList, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QWebElementCollection___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QWebElementCollectionFunc___add__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
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
    // 0: operator+(QWebElementCollection)const
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (pyArg)))) {
        overloadId = 0; // operator+(QWebElementCollection)const
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementCollectionFunc___add___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWebElementCollection cppArg0_local = ::QWebElementCollection();
        ::QWebElementCollection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+(QWebElementCollection)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWebElementCollection cppResult = (*cppSelf) + (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QWebElementCollectionFunc___add___TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebElementCollection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElementCollection.__add__", overloads);
        return 0;
}

static PyObject* Sbk_QWebElementCollectionFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(QWebElementCollection)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (pyArg)))) {
        overloadId = 0; // operator+=(QWebElementCollection)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QWebElementCollectionFunc___iadd___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWebElementCollection cppArg0_local = ::QWebElementCollection();
        ::QWebElementCollection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // operator+=(QWebElementCollection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) += (*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QWebElementCollectionFunc___iadd___TypeError:
        const char* overloads[] = {"PySide.QtWebKit.QWebElementCollection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtWebKit.QWebElementCollection.__iadd__", overloads);
        return 0;
}

Py_ssize_t Sbk_QWebElementCollectionFunc___len__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    // Begin code injection

    return cppSelf->count();

    // End of code injection
}

PyObject* Sbk_QWebElementCollectionFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QWebElementCollection* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= cppSelf->count()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    QWebElement element = cppSelf->at(_i);
    return Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtWebKitTypes[SBK_QWEBELEMENT_IDX], &element);

    // End of code injection
}

} // extern "C"

static int Sbk_QWebElementCollection_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QWebElementCollection_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QWebElementCollection_TypeAsNumber;

static PySequenceMethods Sbk_QWebElementCollection_TypeAsSequence;

static SbkObjectType Sbk_QWebElementCollection_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtWebKit.QWebElementCollection",
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
    /*tp_traverse*/         Sbk_QWebElementCollection_traverse,
    /*tp_clear*/            Sbk_QWebElementCollection_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QWebElementCollection_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QWebElementCollection_Init,
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
static void QWebElementCollection_PythonToCpp_QWebElementCollection_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QWebElementCollection_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QWebElementCollection_PythonToCpp_QWebElementCollection_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebElementCollection_Type))
        return QWebElementCollection_PythonToCpp_QWebElementCollection_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QWebElementCollection_PTR_CppToPython_QWebElementCollection(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QWebElementCollection*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QWebElementCollection_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QWebElementCollection_COPY_CppToPython_QWebElementCollection(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QWebElementCollection_Type, new ::QWebElementCollection(*((::QWebElementCollection*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QWebElementCollection_PythonToCpp_QWebElementCollection_COPY(PyObject* pyIn, void* cppOut) {
    *((::QWebElementCollection*)cppOut) = *((::QWebElementCollection*)Shiboken::Conversions::cppPointer(SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QWebElementCollection_PythonToCpp_QWebElementCollection_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QWebElementCollection_Type))
        return QWebElementCollection_PythonToCpp_QWebElementCollection_COPY;
    return 0;
}

void init_QWebElementCollection(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QWebElementCollection_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QWebElementCollection_TypeAsNumber.nb_inplace_add = Sbk_QWebElementCollectionFunc___iadd__;
    Sbk_QWebElementCollection_TypeAsNumber.nb_add = Sbk_QWebElementCollectionFunc___add__;
    Sbk_QWebElementCollection_Type.super.ht_type.tp_as_number = &Sbk_QWebElementCollection_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QWebElementCollection_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QWebElementCollection_TypeAsSequence.sq_length = &Sbk_QWebElementCollectionFunc___len__;
    Sbk_QWebElementCollection_TypeAsSequence.sq_item = &Sbk_QWebElementCollectionFunc___getitem__;
    Sbk_QWebElementCollection_Type.super.ht_type.tp_as_sequence = &Sbk_QWebElementCollection_TypeAsSequence;

    SbkPySide_QtWebKitTypes[SBK_QWEBELEMENTCOLLECTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QWebElementCollection_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QWebElementCollection", "QWebElementCollection",
        &Sbk_QWebElementCollection_Type, &Shiboken::callCppDestructor< ::QWebElementCollection >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QWebElementCollection_Type,
        QWebElementCollection_PythonToCpp_QWebElementCollection_PTR,
        is_QWebElementCollection_PythonToCpp_QWebElementCollection_PTR_Convertible,
        QWebElementCollection_PTR_CppToPython_QWebElementCollection,
        QWebElementCollection_COPY_CppToPython_QWebElementCollection);

    Shiboken::Conversions::registerConverterName(converter, "QWebElementCollection");
    Shiboken::Conversions::registerConverterName(converter, "QWebElementCollection*");
    Shiboken::Conversions::registerConverterName(converter, "QWebElementCollection&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QWebElementCollection).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QWebElementCollection_PythonToCpp_QWebElementCollection_COPY,
        is_QWebElementCollection_PythonToCpp_QWebElementCollection_COPY_Convertible);


    qRegisterMetaType< ::QWebElementCollection >("QWebElementCollection");
}
