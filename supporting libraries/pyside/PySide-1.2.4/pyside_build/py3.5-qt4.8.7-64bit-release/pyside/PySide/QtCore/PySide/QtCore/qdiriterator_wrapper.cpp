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

#include "qdiriterator_wrapper.h"

// Extra includes
#include <qdir.h>
#include <qdiriterator.h>
#include <qfileinfo.h>


// Native ---------------------------------------------------------

QDirIteratorWrapper::QDirIteratorWrapper(const QDir & dir, QFlags<QDirIterator::IteratorFlag> flags) : QDirIterator(dir, flags) {
    // ... middle
}

QDirIteratorWrapper::QDirIteratorWrapper(const QString & path, QFlags<QDir::Filter> filter, QFlags<QDirIterator::IteratorFlag> flags) : QDirIterator(path, filter, flags) {
    // ... middle
}

QDirIteratorWrapper::QDirIteratorWrapper(const QString & path, QFlags<QDirIterator::IteratorFlag> flags) : QDirIterator(path, flags) {
    // ... middle
}

QDirIteratorWrapper::QDirIteratorWrapper(const QString & path, const QStringList & nameFilters, QFlags<QDir::Filter> filters, QFlags<QDirIterator::IteratorFlag> flags) : QDirIterator(path, nameFilters, filters, flags) {
    // ... middle
}

QDirIteratorWrapper::~QDirIteratorWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDirIterator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDirIterator >()))
        return -1;

    ::QDirIteratorWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QDirIterator", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QDirIterator(QDir,QFlags<QDirIterator::IteratorFlag>)
    // 1: QDirIterator(QString,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
    // 2: QDirIterator(QString,QFlags<QDirIterator::IteratorFlag>)
    // 3: QDirIterator(QString,QStringList,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QDirIterator(QString,QFlags<QDirIterator::IteratorFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // QDirIterator(QString,QStringList,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // QDirIterator(QString,QStringList,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[3])))) {
                    overloadId = 3; // QDirIterator(QString,QStringList,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 2; // QDirIterator(QString,QFlags<QDirIterator::IteratorFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QDirIterator(QString,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // QDirIterator(QString,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QDirIterator(QDir,QFlags<QDirIterator::IteratorFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // QDirIterator(QDir,QFlags<QDirIterator::IteratorFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirIterator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDirIterator(const QDir & dir, QFlags<QDirIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirIterator_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDir cppArg0_local = ::QDir(::QString());
            ::QDir* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QFlags<QDirIterator::IteratorFlag> cppArg1 = QDirIterator::NoIteratorFlags;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDirIterator(QDir,QFlags<QDirIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDirIteratorWrapper(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDirIterator(const QString & path, QFlags<QDir::Filter> filter, QFlags<QDirIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QDirIterator_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDir::Filter> cppArg1 = ((::QFlags<QDir::Filter>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QDirIterator::IteratorFlag> cppArg2 = QDirIterator::NoIteratorFlags;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDirIterator(QString,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDirIteratorWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDirIterator(const QString & path, QFlags<QDirIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirIterator_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDirIterator::IteratorFlag> cppArg1 = QDirIterator::NoIteratorFlags;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDirIterator(QString,QFlags<QDirIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDirIteratorWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QDirIterator(const QString & path, const QStringList & nameFilters, QFlags<QDir::Filter> filters, QFlags<QDirIterator::IteratorFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "filters");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): got multiple values for keyword argument 'filters'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[2]))))
                        goto Sbk_QDirIterator_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDirIterator(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QDirIterator_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QDir::Filter> cppArg2 = QDir::NoFilter;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QDirIterator::IteratorFlag> cppArg3 = QDirIterator::NoIteratorFlags;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QDirIterator(QString,QStringList,QFlags<QDir::Filter>,QFlags<QDirIterator::IteratorFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDirIteratorWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDirIterator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDirIterator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDirIterator_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir, PySide.QtCore.QDirIterator.IteratorFlags = QDirIterator.NoIteratorFlags", "unicode, PySide.QtCore.QDir.Filters, PySide.QtCore.QDirIterator.IteratorFlags = QDirIterator.NoIteratorFlags", "unicode, PySide.QtCore.QDirIterator.IteratorFlags = QDirIterator.NoIteratorFlags", "unicode, QStringList, PySide.QtCore.QDir.Filters = QDir.NoFilter, PySide.QtCore.QDirIterator.IteratorFlags = QDirIterator.NoIteratorFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDirIterator", overloads);
        return -1;
}

static PyObject* Sbk_QDirIteratorFunc_fileInfo(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileInfo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileInfo cppResult = const_cast<const ::QDirIterator*>(cppSelf)->fileInfo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QFILEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirIteratorFunc_fileName(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDirIterator*>(cppSelf)->fileName();
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

static PyObject* Sbk_QDirIteratorFunc_filePath(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filePath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDirIterator*>(cppSelf)->filePath();
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

static PyObject* Sbk_QDirIteratorFunc_hasNext(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasNext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDirIterator*>(cppSelf)->hasNext();
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

static PyObject* Sbk_QDirIteratorFunc_next(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // next()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->next();
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

static PyObject* Sbk_QDirIteratorFunc_path(PyObject* self)
{
    ::QDirIterator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDirIterator*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // path()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDirIterator*>(cppSelf)->path();
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

static PyMethodDef Sbk_QDirIterator_methods[] = {
    {"fileInfo", (PyCFunction)Sbk_QDirIteratorFunc_fileInfo, METH_NOARGS},
    {"fileName", (PyCFunction)Sbk_QDirIteratorFunc_fileName, METH_NOARGS},
    {"filePath", (PyCFunction)Sbk_QDirIteratorFunc_filePath, METH_NOARGS},
    {"hasNext", (PyCFunction)Sbk_QDirIteratorFunc_hasNext, METH_NOARGS},
    {"next", (PyCFunction)Sbk_QDirIteratorFunc_next, METH_NOARGS},
    {"path", (PyCFunction)Sbk_QDirIteratorFunc_path, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDirIterator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDirIterator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDirIterator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QDirIterator",
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
    /*tp_traverse*/         Sbk_QDirIterator_traverse,
    /*tp_clear*/            Sbk_QDirIterator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDirIterator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDirIterator_Init,
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

PyObject* SbkPySide_QtCore_QDirIterator_IteratorFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QDirIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDirIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDirIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDirIterator_IteratorFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QDirIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDirIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDirIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDirIterator_IteratorFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QDirIterator::IteratorFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDirIterator::IteratorFlags)PyLong_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDirIterator::IteratorFlags)PyInt_AsLong(self);
    cppArg = (QDirIterator::IteratorFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDirIterator_IteratorFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QDirIterator::IteratorFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), self, &cppSelf);
    ::QDirIterator::IteratorFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QDirIterator_IteratorFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QDirIterator_IteratorFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QDirIterator_IteratorFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QDirIterator_IteratorFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QDirIterator_IteratorFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QDirIterator_IteratorFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QDirIterator_IteratorFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QDirIterator_IteratorFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QDirIterator_IteratorFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QDirIterator_IteratorFlag_long,
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
static void QDirIterator_IteratorFlag_PythonToCpp_QDirIterator_IteratorFlag(PyObject* pyIn, void* cppOut) {
    *((::QDirIterator::IteratorFlag*)cppOut) = (::QDirIterator::IteratorFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDirIterator_IteratorFlag_PythonToCpp_QDirIterator_IteratorFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX]))
        return QDirIterator_IteratorFlag_PythonToCpp_QDirIterator_IteratorFlag;
    return 0;
}
static PyObject* QDirIterator_IteratorFlag_CppToPython_QDirIterator_IteratorFlag(const void* cppIn) {
    int castCppIn = *((::QDirIterator::IteratorFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX], castCppIn);

}

static void QFlags_QDirIterator_IteratorFlag__PythonToCpp_QFlags_QDirIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDirIterator::IteratorFlag>*)cppOut) = ::QFlags<QDirIterator::IteratorFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QDirIterator_IteratorFlag__PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]))
        return QFlags_QDirIterator_IteratorFlag__PythonToCpp_QFlags_QDirIterator_IteratorFlag_;
    return 0;
}
static PyObject* QFlags_QDirIterator_IteratorFlag__CppToPython_QFlags_QDirIterator_IteratorFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QDirIterator::IteratorFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]));

}

static void QDirIterator_IteratorFlag_PythonToCpp_QFlags_QDirIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDirIterator::IteratorFlag>*)cppOut) = ::QFlags<QDirIterator::IteratorFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QDirIterator_IteratorFlag_PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX]))
        return QDirIterator_IteratorFlag_PythonToCpp_QFlags_QDirIterator_IteratorFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QDirIterator_IteratorFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QDirIterator::IteratorFlag>*)cppOut) = ::QFlags<QDirIterator::IteratorFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QDirIterator_IteratorFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDirIterator_PythonToCpp_QDirIterator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDirIterator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDirIterator_PythonToCpp_QDirIterator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDirIterator_Type))
        return QDirIterator_PythonToCpp_QDirIterator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDirIterator_PTR_CppToPython_QDirIterator(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDirIterator*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDirIterator_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QDirIterator(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDirIterator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDirIterator", "QDirIterator*",
        &Sbk_QDirIterator_Type, &Shiboken::callCppDestructor< ::QDirIterator >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDirIterator_Type,
        QDirIterator_PythonToCpp_QDirIterator_PTR,
        is_QDirIterator_PythonToCpp_QDirIterator_PTR_Convertible,
        QDirIterator_PTR_CppToPython_QDirIterator);

    Shiboken::Conversions::registerConverterName(converter, "QDirIterator");
    Shiboken::Conversions::registerConverterName(converter, "QDirIterator*");
    Shiboken::Conversions::registerConverterName(converter, "QDirIterator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDirIterator).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDirIteratorWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'IteratorFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX] = PySide::QFlags::create("IteratorFlags", &SbkPySide_QtCore_QDirIterator_IteratorFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDirIterator_Type,
        "IteratorFlag",
        "PySide.QtCore.QDirIterator.IteratorFlag",
        "QDirIterator::IteratorFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX],
        &Sbk_QDirIterator_Type, "NoIteratorFlags", (long) QDirIterator::NoIteratorFlags))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX],
        &Sbk_QDirIterator_Type, "FollowSymlinks", (long) QDirIterator::FollowSymlinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX],
        &Sbk_QDirIterator_Type, "Subdirectories", (long) QDirIterator::Subdirectories))
        return ;
    // Register converter for enum 'QDirIterator::IteratorFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX],
            QDirIterator_IteratorFlag_CppToPython_QDirIterator_IteratorFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDirIterator_IteratorFlag_PythonToCpp_QDirIterator_IteratorFlag,
            is_QDirIterator_IteratorFlag_PythonToCpp_QDirIterator_IteratorFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIRITERATOR_ITERATORFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDirIterator::IteratorFlag");
        Shiboken::Conversions::registerConverterName(converter, "IteratorFlag");
    }
    // Register converter for flag 'QFlags<QDirIterator::IteratorFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX],
            QFlags_QDirIterator_IteratorFlag__CppToPython_QFlags_QDirIterator_IteratorFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDirIterator_IteratorFlag_PythonToCpp_QFlags_QDirIterator_IteratorFlag_,
            is_QDirIterator_IteratorFlag_PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QDirIterator_IteratorFlag__PythonToCpp_QFlags_QDirIterator_IteratorFlag_,
            is_QFlags_QDirIterator_IteratorFlag__PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QDirIterator_IteratorFlag_,
            is_number_PythonToCpp_QFlags_QDirIterator_IteratorFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIRITERATOR_ITERATORFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QDirIterator::IteratorFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<IteratorFlag>");
    }
    // End of 'IteratorFlag' enum/flags.


    qRegisterMetaType< ::QDirIterator::IteratorFlag >("QDirIterator::IteratorFlag");
    qRegisterMetaType< ::QDirIterator::IteratorFlags >("QDirIterator::IteratorFlags");
}
