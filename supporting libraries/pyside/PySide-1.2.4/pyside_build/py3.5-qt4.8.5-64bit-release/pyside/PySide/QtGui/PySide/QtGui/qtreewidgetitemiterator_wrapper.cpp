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

#include "qtreewidgetitemiterator_wrapper.h"

// Extra includes
#include <qtreewidget.h>
#include <qtreewidgetitemiterator.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTreeWidgetItemIterator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTreeWidgetItemIterator >()))
        return -1;

    ::QTreeWidgetItemIterator* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItemIterator(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItemIterator(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QTreeWidgetItemIterator", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTreeWidgetItemIterator(QTreeWidget*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
    // 1: QTreeWidgetItemIterator(QTreeWidgetItem*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
    // 2: QTreeWidgetItemIterator(QTreeWidgetItemIterator)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTreeWidgetItemIterator(QTreeWidgetItemIterator)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QTreeWidgetItemIterator(QTreeWidgetItem*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // QTreeWidgetItemIterator(QTreeWidgetItem*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QTreeWidgetItemIterator(QTreeWidget*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // QTreeWidgetItemIterator(QTreeWidget*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemIterator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTreeWidgetItemIterator(QTreeWidget * widget, QFlags<QTreeWidgetItemIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItemIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QTreeWidgetItemIterator_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QTreeWidgetItemIterator::IteratorFlag> cppArg1 = QTreeWidgetItemIterator::All;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItemIterator(QTreeWidget*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemIterator(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QTreeWidgetItemIterator(QTreeWidgetItem * item, QFlags<QTreeWidgetItemIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItemIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QTreeWidgetItemIterator_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QTreeWidgetItemIterator::IteratorFlag> cppArg1 = QTreeWidgetItemIterator::All;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItemIterator(QTreeWidgetItem*,QFlags<QTreeWidgetItemIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemIterator(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTreeWidgetItemIterator(const QTreeWidgetItemIterator & it)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItemIterator cppArg0_local = ::QTreeWidgetItemIterator(((::QTreeWidget*)0));
            ::QTreeWidgetItemIterator* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QTreeWidgetItemIterator(QTreeWidgetItemIterator)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemIterator(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTreeWidgetItemIterator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTreeWidgetItemIterator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTreeWidgetItemIterator_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidget, PySide.QtGui.QTreeWidgetItemIterator.IteratorFlags = QTreeWidgetItemIterator.All", "PySide.QtGui.QTreeWidgetItem, PySide.QtGui.QTreeWidgetItemIterator.IteratorFlags = QTreeWidgetItemIterator.All", "PySide.QtGui.QTreeWidgetItemIterator", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItemIterator", overloads);
        return -1;
}

static PyObject* Sbk_QTreeWidgetItemIteratorFunc___iter__(PyObject* self)
{
    ::QTreeWidgetItemIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __iter__()
            // Begin code injection

            // TEMPLATE - __iter__ - START
            Py_INCREF(self);
            pyResult = self;
            // TEMPLATE - __iter__ - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemIteratorFunc___next__(PyObject* self)
{
    ::QTreeWidgetItemIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __next__()
            // Begin code injection

            if (**cppSelf) {
                QTreeWidgetItemIterator* cppResult = new QTreeWidgetItemIterator((*cppSelf)++);
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], cppResult);
            }

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemIteratorFunc_value(PyObject* self)
{
    ::QTreeWidgetItemIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // value()
            // Begin code injection

            QTreeWidgetItem* cppResult = cppSelf->operator*();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppResult);
            Shiboken::Object::releaseOwnership(pyResult);

            // End of code injection


            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemIterator___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTreeWidgetItemIterator& cppSelf = *(((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QTreeWidgetItemIterator_methods[] = {
    {"value", (PyCFunction)Sbk_QTreeWidgetItemIteratorFunc_value, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QTreeWidgetItemIterator___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QTreeWidgetItemIteratorFunc___iadd__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTreeWidgetItemIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator+=(int)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // operator+=(int)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemIteratorFunc___iadd___TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator+=(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) += cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QTreeWidgetItemIteratorFunc___iadd___TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItemIterator.__iadd__", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemIteratorFunc___isub__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTreeWidgetItemIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: operator-=(int)
    if (!isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // operator-=(int)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemIteratorFunc___isub___TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator-=(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            (*cppSelf) -= cppArg0;
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_INCREF(self);
    return self;

    Sbk_QTreeWidgetItemIteratorFunc___isub___TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItemIterator.__isub__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QTreeWidgetItemIterator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTreeWidgetItemIterator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTreeWidgetItemIterator_TypeAsNumber;

static SbkObjectType Sbk_QTreeWidgetItemIterator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTreeWidgetItemIterator",
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
    /*tp_traverse*/         Sbk_QTreeWidgetItemIterator_traverse,
    /*tp_clear*/            Sbk_QTreeWidgetItemIterator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             Sbk_QTreeWidgetItemIteratorFunc___iter__,
    /*tp_iternext*/         Sbk_QTreeWidgetItemIteratorFunc___next__,
    /*tp_methods*/          Sbk_QTreeWidgetItemIterator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTreeWidgetItemIterator_Init,
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

PyObject* SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItemIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItemIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItemIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QTreeWidgetItemIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItemIterator::IteratorFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), self, &cppSelf);
    ::QTreeWidgetItemIterator::IteratorFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QTreeWidgetItemIterator_IteratorFlag(PyObject* pyIn, void* cppOut) {
    *((::QTreeWidgetItemIterator::IteratorFlag*)cppOut) = (::QTreeWidgetItemIterator::IteratorFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QTreeWidgetItemIterator_IteratorFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX]))
        return QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QTreeWidgetItemIterator_IteratorFlag;
    return 0;
}
static PyObject* QTreeWidgetItemIterator_IteratorFlag_CppToPython_QTreeWidgetItemIterator_IteratorFlag(const void* cppIn) {
    int castCppIn = *((::QTreeWidgetItemIterator::IteratorFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX], castCppIn);

}

static void QFlags_QTreeWidgetItemIterator_IteratorFlag__PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTreeWidgetItemIterator::IteratorFlag>*)cppOut) = ::QFlags<QTreeWidgetItemIterator::IteratorFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QTreeWidgetItemIterator_IteratorFlag__PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]))
        return QFlags_QTreeWidgetItemIterator_IteratorFlag__PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_;
    return 0;
}
static PyObject* QFlags_QTreeWidgetItemIterator_IteratorFlag__CppToPython_QFlags_QTreeWidgetItemIterator_IteratorFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QTreeWidgetItemIterator::IteratorFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]));

}

static void QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QTreeWidgetItemIterator::IteratorFlag>*)cppOut) = ::QFlags<QTreeWidgetItemIterator::IteratorFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX]))
        return QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QTreeWidgetItemIterator::IteratorFlag>*)cppOut) = ::QFlags<QTreeWidgetItemIterator::IteratorFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTreeWidgetItemIterator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTreeWidgetItemIterator_Type))
        return QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTreeWidgetItemIterator_PTR_CppToPython_QTreeWidgetItemIterator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTreeWidgetItemIterator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTreeWidgetItemIterator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QTreeWidgetItemIterator_COPY_CppToPython_QTreeWidgetItemIterator(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QTreeWidgetItemIterator_Type, new ::QTreeWidgetItemIterator(*((::QTreeWidgetItemIterator*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_COPY(PyObject* pyIn, void* cppOut) {
    *((::QTreeWidgetItemIterator*)cppOut) = *((::QTreeWidgetItemIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTreeWidgetItemIterator_Type))
        return QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_COPY;
    return 0;
}

void init_QTreeWidgetItemIterator(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTreeWidgetItemIterator_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTreeWidgetItemIterator_TypeAsNumber.nb_inplace_subtract = Sbk_QTreeWidgetItemIteratorFunc___isub__;
    Sbk_QTreeWidgetItemIterator_TypeAsNumber.nb_inplace_add = Sbk_QTreeWidgetItemIteratorFunc___iadd__;
    Sbk_QTreeWidgetItemIterator_Type.super.ht_type.tp_as_number = &Sbk_QTreeWidgetItemIterator_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTreeWidgetItemIterator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTreeWidgetItemIterator", "QTreeWidgetItemIterator",
        &Sbk_QTreeWidgetItemIterator_Type, &Shiboken::callCppDestructor< ::QTreeWidgetItemIterator >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTreeWidgetItemIterator_Type,
        QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_PTR,
        is_QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_PTR_Convertible,
        QTreeWidgetItemIterator_PTR_CppToPython_QTreeWidgetItemIterator,
        QTreeWidgetItemIterator_COPY_CppToPython_QTreeWidgetItemIterator);

    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItemIterator");
    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItemIterator*");
    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItemIterator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTreeWidgetItemIterator).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_COPY,
        is_QTreeWidgetItemIterator_PythonToCpp_QTreeWidgetItemIterator_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'IteratorFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX] = PySide::QFlags::create("IteratorFlags", &SbkPySide_QtGui_QTreeWidgetItemIterator_IteratorFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTreeWidgetItemIterator_Type,
        "IteratorFlag",
        "PySide.QtGui.QTreeWidgetItemIterator.IteratorFlag",
        "QTreeWidgetItemIterator::IteratorFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "All", (long) QTreeWidgetItemIterator::All))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Hidden", (long) QTreeWidgetItemIterator::Hidden))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "NotHidden", (long) QTreeWidgetItemIterator::NotHidden))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Selected", (long) QTreeWidgetItemIterator::Selected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Unselected", (long) QTreeWidgetItemIterator::Unselected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Selectable", (long) QTreeWidgetItemIterator::Selectable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "NotSelectable", (long) QTreeWidgetItemIterator::NotSelectable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "DragEnabled", (long) QTreeWidgetItemIterator::DragEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "DragDisabled", (long) QTreeWidgetItemIterator::DragDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "DropEnabled", (long) QTreeWidgetItemIterator::DropEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "DropDisabled", (long) QTreeWidgetItemIterator::DropDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "HasChildren", (long) QTreeWidgetItemIterator::HasChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "NoChildren", (long) QTreeWidgetItemIterator::NoChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Checked", (long) QTreeWidgetItemIterator::Checked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "NotChecked", (long) QTreeWidgetItemIterator::NotChecked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Enabled", (long) QTreeWidgetItemIterator::Enabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Disabled", (long) QTreeWidgetItemIterator::Disabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "Editable", (long) QTreeWidgetItemIterator::Editable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "NotEditable", (long) QTreeWidgetItemIterator::NotEditable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
        &Sbk_QTreeWidgetItemIterator_Type, "UserFlag", (long) QTreeWidgetItemIterator::UserFlag))
        return ;
    // Register converter for enum 'QTreeWidgetItemIterator::IteratorFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX],
            QTreeWidgetItemIterator_IteratorFlag_CppToPython_QTreeWidgetItemIterator_IteratorFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QTreeWidgetItemIterator_IteratorFlag,
            is_QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QTreeWidgetItemIterator_IteratorFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEMITERATOR_ITERATORFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItemIterator::IteratorFlag");
        Shiboken::Conversions::registerConverterName(converter, "IteratorFlag");
    }
    // Register converter for flag 'QFlags<QTreeWidgetItemIterator::IteratorFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX],
            QFlags_QTreeWidgetItemIterator_IteratorFlag__CppToPython_QFlags_QTreeWidgetItemIterator_IteratorFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_,
            is_QTreeWidgetItemIterator_IteratorFlag_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QTreeWidgetItemIterator_IteratorFlag__PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_,
            is_QFlags_QTreeWidgetItemIterator_IteratorFlag__PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag_,
            is_number_PythonToCpp_QFlags_QTreeWidgetItemIterator_IteratorFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTREEWIDGETITEMITERATOR_ITERATORFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QTreeWidgetItemIterator::IteratorFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<IteratorFlag>");
    }
    // End of 'IteratorFlag' enum/flags.


    qRegisterMetaType< ::QTreeWidgetItemIterator::IteratorFlag >("QTreeWidgetItemIterator::IteratorFlag");
    qRegisterMetaType< ::QTreeWidgetItemIterator::IteratorFlags >("QTreeWidgetItemIterator::IteratorFlags");
}
