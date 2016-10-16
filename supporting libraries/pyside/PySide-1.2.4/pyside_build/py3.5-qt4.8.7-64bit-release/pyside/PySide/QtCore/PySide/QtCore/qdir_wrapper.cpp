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

#include "qdir_wrapper.h"

// Extra includes
#include <QList>
#include <qdir.h>
#include <qfileinfo.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDir_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDir >()))
        return -1;

    ::QDir* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QDir", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QDir(QDir)
    // 1: QDir(QString)
    // 2: QDir(QString,QString,QFlags<QDir::SortFlag>,QFlags<QDir::Filter>)
    if (numArgs == 0) {
        overloadId = 1; // QDir(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QDir(QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QDir(QString,QString,QFlags<QDir::SortFlag>,QFlags<QDir::Filter>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 2; // QDir(QString,QString,QFlags<QDir::SortFlag>,QFlags<QDir::Filter>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[3])))) {
                    overloadId = 2; // QDir(QString,QString,QFlags<QDir::SortFlag>,QFlags<QDir::Filter>)
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (pyArgs[0])))) {
        overloadId = 0; // QDir(QDir)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDir_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDir(const QDir & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDir cppArg0_local = ::QDir(::QString());
            ::QDir* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QDir(QDir)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDir(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QDir(const QString & path)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "path");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir(): got multiple values for keyword argument 'path'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_QDir_Init_TypeError;
                }
            }
            ::QString cppArg0 = QString();
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDir(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDir(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QDir(const QString & path, const QString & nameFilter, QFlags<QDir::SortFlag> sort, QFlags<QDir::Filter> filter)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "sort");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir(): got multiple values for keyword argument 'sort'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QDir_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "filter");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir(): got multiple values for keyword argument 'filter'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[3]))))
                        goto Sbk_QDir_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QDir::SortFlag> cppArg2 = QDir::SortFlags(QDir::Name |QDir:: IgnoreCase);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QDir::Filter> cppArg3 = QDir::AllEntries;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QDir(QString,QString,QFlags<QDir::SortFlag>,QFlags<QDir::Filter>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QDir(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDir >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDir_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QDir_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir", "unicode = QString()", "unicode, unicode, PySide.QtCore.QDir.SortFlags = QDir.SortFlags(Name | IgnoreCase), PySide.QtCore.QDir.Filters = QDir.AllEntries", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir", overloads);
        return -1;
}

static PyObject* Sbk_QDirFunc___reduce__(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(s))", PyObject_Type(self), qPrintable(cppSelf->path()));
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

static PyObject* Sbk_QDirFunc_absoluteFilePath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: absoluteFilePath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // absoluteFilePath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_absoluteFilePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // absoluteFilePath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->absoluteFilePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_absoluteFilePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.absoluteFilePath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_absolutePath(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // absolutePath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->absolutePath();
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

static PyObject* Sbk_QDirFunc_addResourceSearchPath(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addResourceSearchPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addResourceSearchPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_addResourceSearchPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addResourceSearchPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDir::addResourceSearchPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_addResourceSearchPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.addResourceSearchPath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_addSearchPath(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addSearchPath", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addSearchPath(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // addSearchPath(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_addSearchPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addSearchPath(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDir::addSearchPath(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_addSearchPath_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.addSearchPath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_canonicalPath(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canonicalPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->canonicalPath();
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

static PyObject* Sbk_QDirFunc_cd(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cd(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // cd(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_cd_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cd(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->cd(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_cd_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.cd", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_cdUp(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cdUp()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->cdUp();
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

static PyObject* Sbk_QDirFunc_cleanPath(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cleanPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // cleanPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_cleanPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cleanPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::cleanPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_cleanPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.cleanPath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_convertSeparators(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: convertSeparators(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // convertSeparators(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_convertSeparators_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // convertSeparators(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::convertSeparators(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_convertSeparators_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.convertSeparators", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_count(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QDir*>(cppSelf)->count();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_current(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // current()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = ::QDir::current();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_currentPath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentPath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::currentPath();
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

static PyObject* Sbk_QDirFunc_dirName(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dirName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->dirName();
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

static PyObject* Sbk_QDirFunc_drives(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // drives()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QFileInfo > cppResult = ::QDir::drives();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_entryInfoList(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryInfoList(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:entryInfoList", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: entryInfoList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    // 1: entryInfoList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // entryInfoList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // entryInfoList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // entryInfoList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // entryInfoList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // entryInfoList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // entryInfoList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_entryInfoList_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // entryInfoList(QFlags<QDir::Filter> filters, QFlags<QDir::SortFlag> sort) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "filters");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryInfoList(): got multiple values for keyword argument 'filters'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0]))))
                        goto Sbk_QDirFunc_entryInfoList_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sort");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryInfoList(): got multiple values for keyword argument 'sort'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirFunc_entryInfoList_TypeError;
                }
            }
            ::QFlags<QDir::Filter> cppArg0 = QDir::NoFilter;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDir::SortFlag> cppArg1 = QDir::NoSort;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // entryInfoList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QFileInfo > cppResult = const_cast<const ::QDir*>(cppSelf)->entryInfoList(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX], &cppResult);
            }
            break;
        }
        case 1: // entryInfoList(const QStringList & nameFilters, QFlags<QDir::Filter> filters, QFlags<QDir::SortFlag> sort) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "filters");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryInfoList(): got multiple values for keyword argument 'filters'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirFunc_entryInfoList_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sort");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryInfoList(): got multiple values for keyword argument 'sort'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QDirFunc_entryInfoList_TypeError;
                }
            }
            ::QStringList cppArg0 = ::QStringList();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDir::Filter> cppArg1 = QDir::NoFilter;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QDir::SortFlag> cppArg2 = QDir::NoSort;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // entryInfoList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QFileInfo > cppResult = const_cast<const ::QDir*>(cppSelf)->entryInfoList(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QFILEINFO_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_entryInfoList_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters = QDir.NoFilter, PySide.QtCore.QDir.SortFlags = QDir.NoSort", "QStringList, PySide.QtCore.QDir.Filters = QDir.NoFilter, PySide.QtCore.QDir.SortFlags = QDir.NoSort", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.entryInfoList", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_entryList(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryList(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:entryList", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: entryList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    // 1: entryList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    if (numArgs == 0) {
        overloadId = 0; // entryList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // entryList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // entryList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 1; // entryList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // entryList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // entryList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_entryList_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // entryList(QFlags<QDir::Filter> filters, QFlags<QDir::SortFlag> sort) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "filters");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryList(): got multiple values for keyword argument 'filters'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[0]))))
                        goto Sbk_QDirFunc_entryList_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sort");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryList(): got multiple values for keyword argument 'sort'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirFunc_entryList_TypeError;
                }
            }
            ::QFlags<QDir::Filter> cppArg0 = QDir::NoFilter;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDir::SortFlag> cppArg1 = QDir::NoSort;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // entryList(QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::QDir*>(cppSelf)->entryList(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
        case 1: // entryList(const QStringList & nameFilters, QFlags<QDir::Filter> filters, QFlags<QDir::SortFlag> sort) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "filters");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryList(): got multiple values for keyword argument 'filters'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArgs[1]))))
                        goto Sbk_QDirFunc_entryList_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sort");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QDir.entryList(): got multiple values for keyword argument 'sort'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QDirFunc_entryList_TypeError;
                }
            }
            ::QStringList cppArg0 = ::QStringList();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QDir::Filter> cppArg1 = QDir::NoFilter;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QDir::SortFlag> cppArg2 = QDir::NoSort;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // entryList(QStringList,QFlags<QDir::Filter>,QFlags<QDir::SortFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QStringList cppResult = const_cast<const ::QDir*>(cppSelf)->entryList(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_entryList_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters = QDir.NoFilter, PySide.QtCore.QDir.SortFlags = QDir.NoSort", "QStringList, PySide.QtCore.QDir.Filters = QDir.NoFilter, PySide.QtCore.QDir.SortFlags = QDir.NoSort", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.entryList", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_exists(PyObject* self, PyObject* args)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "exists", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: exists()const
    // 1: exists(QString)const
    if (numArgs == 0) {
        overloadId = 0; // exists()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // exists(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_exists_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // exists() const
        {

            if (!PyErr_Occurred()) {
                // exists()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDir*>(cppSelf)->exists();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // exists(const QString & name) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // exists(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QDir*>(cppSelf)->exists(cppArg0);
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

    Sbk_QDirFunc_exists_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.exists", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_filePath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: filePath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // filePath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_filePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // filePath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->filePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_filePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.filePath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_filter(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDir::Filter> cppResult = const_cast<const ::QDir*>(cppSelf)->filter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_fromNativeSeparators(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fromNativeSeparators(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fromNativeSeparators(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_fromNativeSeparators_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fromNativeSeparators(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::fromNativeSeparators(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_fromNativeSeparators_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.fromNativeSeparators", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_home(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // home()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = ::QDir::home();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_homePath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // homePath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::homePath();
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

static PyObject* Sbk_QDirFunc_isAbsolute(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAbsolute()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->isAbsolute();
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

static PyObject* Sbk_QDirFunc_isAbsolutePath(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isAbsolutePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isAbsolutePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_isAbsolutePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isAbsolutePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QDir::isAbsolutePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_isAbsolutePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.isAbsolutePath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_isReadable(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->isReadable();
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

static PyObject* Sbk_QDirFunc_isRelative(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRelative()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->isRelative();
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

static PyObject* Sbk_QDirFunc_isRelativePath(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isRelativePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // isRelativePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_isRelativePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isRelativePath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QDir::isRelativePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_isRelativePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.isRelativePath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_isRoot(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRoot()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->isRoot();
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

static PyObject* Sbk_QDirFunc_makeAbsolute(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // makeAbsolute()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->makeAbsolute();
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

static PyObject* Sbk_QDirFunc_match(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "match", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: match(QString,QString)
    // 1: match(QStringList,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // match(QStringList,QString)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // match(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_match_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // match(const QString & filter, const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // match(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDir::match(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // match(const QStringList & filters, const QString & fileName)
        {
            ::QStringList cppArg0 = ::QStringList();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // match(QStringList,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = ::QDir::match(cppArg0, cppArg1);
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

    Sbk_QDirFunc_match_TypeError:
        const char* overloads[] = {"unicode, unicode", "QStringList, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.match", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_mkdir(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mkdir(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mkdir(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_mkdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mkdir(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->mkdir(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_mkdir_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.mkdir", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_mkpath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mkpath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mkpath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_mkpath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mkpath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->mkpath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_mkpath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.mkpath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_nameFilters(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nameFilters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QDir*>(cppSelf)->nameFilters();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_nameFiltersFromString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: nameFiltersFromString(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // nameFiltersFromString(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_nameFiltersFromString_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // nameFiltersFromString(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QDir::nameFiltersFromString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_nameFiltersFromString_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.nameFiltersFromString", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_path(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // path()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->path();
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

static PyObject* Sbk_QDirFunc_refresh(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // refresh()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QDir*>(cppSelf)->refresh();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDirFunc_relativeFilePath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: relativeFilePath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // relativeFilePath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_relativeFilePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // relativeFilePath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDir*>(cppSelf)->relativeFilePath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_relativeFilePath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.relativeFilePath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_remove(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: remove(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // remove(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_remove_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // remove(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->remove(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_remove_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.remove", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_rename(PyObject* self, PyObject* args)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rename", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: rename(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // rename(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_rename_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // rename(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->rename(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_rename_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.rename", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_rmdir(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rmdir(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // rmdir(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_rmdir_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rmdir(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->rmdir(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_rmdir_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.rmdir", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_rmpath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rmpath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // rmpath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_rmpath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rmpath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDir*>(cppSelf)->rmpath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_rmpath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.rmpath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_root(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // root()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = ::QDir::root();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_rootPath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootPath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::rootPath();
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

static PyObject* Sbk_QDirFunc_searchPaths(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: searchPaths(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // searchPaths(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_searchPaths_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // searchPaths(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QDir::searchPaths(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_searchPaths_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.searchPaths", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_separator(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // separator()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = ::QDir::separator();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QCHAR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_setCurrent(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrent(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setCurrent(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setCurrent_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrent(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QDir::setCurrent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_setCurrent_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.setCurrent", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_setFilter(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFilter(QFlags<QDir::Filter>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArg)))) {
        overloadId = 0; // setFilter(QFlags<QDir::Filter>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setFilter_TypeError;

    // Call function/method
    {
        ::QFlags<QDir::Filter> cppArg0 = ((::QFlags<QDir::Filter>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFilter(QFlags<QDir::Filter>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_setFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.setFilter", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_setNameFilters(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilters(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setNameFilters(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setNameFilters_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilters(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilters(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_setNameFilters_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.setNameFilters", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_setPath(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPath(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_setPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.setPath", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_setSearchPaths(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSearchPaths", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSearchPaths(QString,QStringList)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 0; // setSearchPaths(QString,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setSearchPaths_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStringList cppArg1 = ::QStringList();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSearchPaths(QString,QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QDir::setSearchPaths(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_setSearchPaths_TypeError:
        const char* overloads[] = {"unicode, QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QDir.setSearchPaths", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_setSorting(PyObject* self, PyObject* pyArg)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSorting(QFlags<QDir::SortFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setSorting(QFlags<QDir::SortFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_setSorting_TypeError;

    // Call function/method
    {
        ::QFlags<QDir::SortFlag> cppArg0 = ((::QFlags<QDir::SortFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSorting(QFlags<QDir::SortFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSorting(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDirFunc_setSorting_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.SortFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.setSorting", overloads);
        return 0;
}

static PyObject* Sbk_QDirFunc_sorting(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sorting()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDir::SortFlag> cppResult = const_cast<const ::QDir*>(cppSelf)->sorting();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_temp(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // temp()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = ::QDir::temp();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDirFunc_tempPath(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tempPath()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::tempPath();
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

static PyObject* Sbk_QDirFunc_toNativeSeparators(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toNativeSeparators(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toNativeSeparators(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDirFunc_toNativeSeparators_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toNativeSeparators(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QDir::toNativeSeparators(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDirFunc_toNativeSeparators_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QDir.toNativeSeparators", overloads);
        return 0;
}

static PyObject* Sbk_QDir___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDir& cppSelf = *(((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDir_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QDirFunc___reduce__, METH_NOARGS},
    {"absoluteFilePath", (PyCFunction)Sbk_QDirFunc_absoluteFilePath, METH_O},
    {"absolutePath", (PyCFunction)Sbk_QDirFunc_absolutePath, METH_NOARGS},
    {"addResourceSearchPath", (PyCFunction)Sbk_QDirFunc_addResourceSearchPath, METH_O|METH_STATIC},
    {"addSearchPath", (PyCFunction)Sbk_QDirFunc_addSearchPath, METH_VARARGS|METH_STATIC},
    {"canonicalPath", (PyCFunction)Sbk_QDirFunc_canonicalPath, METH_NOARGS},
    {"cd", (PyCFunction)Sbk_QDirFunc_cd, METH_O},
    {"cdUp", (PyCFunction)Sbk_QDirFunc_cdUp, METH_NOARGS},
    {"cleanPath", (PyCFunction)Sbk_QDirFunc_cleanPath, METH_O|METH_STATIC},
    {"convertSeparators", (PyCFunction)Sbk_QDirFunc_convertSeparators, METH_O|METH_STATIC},
    {"count", (PyCFunction)Sbk_QDirFunc_count, METH_NOARGS},
    {"current", (PyCFunction)Sbk_QDirFunc_current, METH_NOARGS|METH_STATIC},
    {"currentPath", (PyCFunction)Sbk_QDirFunc_currentPath, METH_NOARGS|METH_STATIC},
    {"dirName", (PyCFunction)Sbk_QDirFunc_dirName, METH_NOARGS},
    {"drives", (PyCFunction)Sbk_QDirFunc_drives, METH_NOARGS|METH_STATIC},
    {"entryInfoList", (PyCFunction)Sbk_QDirFunc_entryInfoList, METH_VARARGS|METH_KEYWORDS},
    {"entryList", (PyCFunction)Sbk_QDirFunc_entryList, METH_VARARGS|METH_KEYWORDS},
    {"exists", (PyCFunction)Sbk_QDirFunc_exists, METH_VARARGS},
    {"filePath", (PyCFunction)Sbk_QDirFunc_filePath, METH_O},
    {"filter", (PyCFunction)Sbk_QDirFunc_filter, METH_NOARGS},
    {"fromNativeSeparators", (PyCFunction)Sbk_QDirFunc_fromNativeSeparators, METH_O|METH_STATIC},
    {"home", (PyCFunction)Sbk_QDirFunc_home, METH_NOARGS|METH_STATIC},
    {"homePath", (PyCFunction)Sbk_QDirFunc_homePath, METH_NOARGS|METH_STATIC},
    {"isAbsolute", (PyCFunction)Sbk_QDirFunc_isAbsolute, METH_NOARGS},
    {"isAbsolutePath", (PyCFunction)Sbk_QDirFunc_isAbsolutePath, METH_O|METH_STATIC},
    {"isReadable", (PyCFunction)Sbk_QDirFunc_isReadable, METH_NOARGS},
    {"isRelative", (PyCFunction)Sbk_QDirFunc_isRelative, METH_NOARGS},
    {"isRelativePath", (PyCFunction)Sbk_QDirFunc_isRelativePath, METH_O|METH_STATIC},
    {"isRoot", (PyCFunction)Sbk_QDirFunc_isRoot, METH_NOARGS},
    {"makeAbsolute", (PyCFunction)Sbk_QDirFunc_makeAbsolute, METH_NOARGS},
    {"match", (PyCFunction)Sbk_QDirFunc_match, METH_VARARGS|METH_STATIC},
    {"mkdir", (PyCFunction)Sbk_QDirFunc_mkdir, METH_O},
    {"mkpath", (PyCFunction)Sbk_QDirFunc_mkpath, METH_O},
    {"nameFilters", (PyCFunction)Sbk_QDirFunc_nameFilters, METH_NOARGS},
    {"nameFiltersFromString", (PyCFunction)Sbk_QDirFunc_nameFiltersFromString, METH_O|METH_STATIC},
    {"path", (PyCFunction)Sbk_QDirFunc_path, METH_NOARGS},
    {"refresh", (PyCFunction)Sbk_QDirFunc_refresh, METH_NOARGS},
    {"relativeFilePath", (PyCFunction)Sbk_QDirFunc_relativeFilePath, METH_O},
    {"remove", (PyCFunction)Sbk_QDirFunc_remove, METH_O},
    {"rename", (PyCFunction)Sbk_QDirFunc_rename, METH_VARARGS},
    {"rmdir", (PyCFunction)Sbk_QDirFunc_rmdir, METH_O},
    {"rmpath", (PyCFunction)Sbk_QDirFunc_rmpath, METH_O},
    {"root", (PyCFunction)Sbk_QDirFunc_root, METH_NOARGS|METH_STATIC},
    {"rootPath", (PyCFunction)Sbk_QDirFunc_rootPath, METH_NOARGS|METH_STATIC},
    {"searchPaths", (PyCFunction)Sbk_QDirFunc_searchPaths, METH_O|METH_STATIC},
    {"separator", (PyCFunction)Sbk_QDirFunc_separator, METH_NOARGS|METH_STATIC},
    {"setCurrent", (PyCFunction)Sbk_QDirFunc_setCurrent, METH_O|METH_STATIC},
    {"setFilter", (PyCFunction)Sbk_QDirFunc_setFilter, METH_O},
    {"setNameFilters", (PyCFunction)Sbk_QDirFunc_setNameFilters, METH_O},
    {"setPath", (PyCFunction)Sbk_QDirFunc_setPath, METH_O},
    {"setSearchPaths", (PyCFunction)Sbk_QDirFunc_setSearchPaths, METH_VARARGS|METH_STATIC},
    {"setSorting", (PyCFunction)Sbk_QDirFunc_setSorting, METH_O},
    {"sorting", (PyCFunction)Sbk_QDirFunc_sorting, METH_NOARGS},
    {"temp", (PyCFunction)Sbk_QDirFunc_temp, METH_NOARGS|METH_STATIC},
    {"tempPath", (PyCFunction)Sbk_QDirFunc_tempPath, METH_NOARGS|METH_STATIC},
    {"toNativeSeparators", (PyCFunction)Sbk_QDirFunc_toNativeSeparators, METH_O|METH_STATIC},

    {"__copy__", (PyCFunction)Sbk_QDir___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QDir_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QDir& cppSelf = *(((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (pyArg)))) {
                // operator!=(const QDir & dir) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDir cppArg0_local = ::QDir(::QString());
                ::QDir* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (pyArg)))) {
                // operator==(const QDir & dir) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QDir cppArg0_local = ::QDir(::QString());
                ::QDir* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], pythonToCpp))
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
            goto Sbk_QDir_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QDir_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QDir_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDir_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QDir__repr__(PyObject* self)
{
    ::QDir* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)self));
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
static SbkObjectType Sbk_QDir_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QDir",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QDir__repr__,
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
    /*tp_traverse*/         Sbk_QDir_traverse,
    /*tp_clear*/            Sbk_QDir_clear,
    /*tp_richcompare*/      Sbk_QDir_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDir_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDir_Init,
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

PyObject* SbkPySide_QtCore_QDir_Filter___and__(PyObject* self, PyObject* pyArg)
{
    ::QDir::Filters cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::Filters)PyLong_AsLong(self);
    cppArg = (QDir::Filters)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::Filters)PyInt_AsLong(self);
    cppArg = (QDir::Filters)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_Filter___or__(PyObject* self, PyObject* pyArg)
{
    ::QDir::Filters cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::Filters)PyLong_AsLong(self);
    cppArg = (QDir::Filters)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::Filters)PyInt_AsLong(self);
    cppArg = (QDir::Filters)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_Filter___xor__(PyObject* self, PyObject* pyArg)
{
    ::QDir::Filters cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::Filters)PyLong_AsLong(self);
    cppArg = (QDir::Filters)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::Filters)PyInt_AsLong(self);
    cppArg = (QDir::Filters)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_Filter___invert__(PyObject* self, PyObject* pyArg)
{
    ::QDir::Filters cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), self, &cppSelf);
    ::QDir::Filters cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QDir_Filter_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QDir_Filter__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QDir_Filter_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QDir_Filter__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QDir_Filter___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QDir_Filter___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QDir_Filter___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QDir_Filter___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QDir_Filter_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QDir_Filter_long,
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


PyObject* SbkPySide_QtCore_QDir_SortFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QDir::SortFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::SortFlags)PyLong_AsLong(self);
    cppArg = (QDir::SortFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::SortFlags)PyInt_AsLong(self);
    cppArg = (QDir::SortFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_SortFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QDir::SortFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::SortFlags)PyLong_AsLong(self);
    cppArg = (QDir::SortFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::SortFlags)PyInt_AsLong(self);
    cppArg = (QDir::SortFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_SortFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QDir::SortFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDir::SortFlags)PyLong_AsLong(self);
    cppArg = (QDir::SortFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDir::SortFlags)PyInt_AsLong(self);
    cppArg = (QDir::SortFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QDir_SortFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QDir::SortFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), self, &cppSelf);
    ::QDir::SortFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QDir_SortFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QDir_SortFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QDir_SortFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QDir_SortFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QDir_SortFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QDir_SortFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QDir_SortFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QDir_SortFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QDir_SortFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QDir_SortFlag_long,
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
static void QDir_Filter_PythonToCpp_QDir_Filter(PyObject* pyIn, void* cppOut) {
    *((::QDir::Filter*)cppOut) = (::QDir::Filter) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDir_Filter_PythonToCpp_QDir_Filter_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX]))
        return QDir_Filter_PythonToCpp_QDir_Filter;
    return 0;
}
static PyObject* QDir_Filter_CppToPython_QDir_Filter(const void* cppIn) {
    int castCppIn = *((::QDir::Filter*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX], castCppIn);

}

static void QFlags_QDir_Filter__PythonToCpp_QFlags_QDir_Filter_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDir::Filter>*)cppOut) = ::QFlags<QDir::Filter>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QDir_Filter__PythonToCpp_QFlags_QDir_Filter__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]))
        return QFlags_QDir_Filter__PythonToCpp_QFlags_QDir_Filter_;
    return 0;
}
static PyObject* QFlags_QDir_Filter__CppToPython_QFlags_QDir_Filter_(const void* cppIn) {
    int castCppIn = *((::QFlags<QDir::Filter>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]));

}

static void QDir_Filter_PythonToCpp_QFlags_QDir_Filter_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDir::Filter>*)cppOut) = ::QFlags<QDir::Filter>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QDir_Filter_PythonToCpp_QFlags_QDir_Filter__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX]))
        return QDir_Filter_PythonToCpp_QFlags_QDir_Filter_;
    return 0;
}
static void number_PythonToCpp_QFlags_QDir_Filter_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QDir::Filter>*)cppOut) = ::QFlags<QDir::Filter>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QDir_Filter__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QDir_Filter_;
    return 0;
}
static void QDir_SortFlag_PythonToCpp_QDir_SortFlag(PyObject* pyIn, void* cppOut) {
    *((::QDir::SortFlag*)cppOut) = (::QDir::SortFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDir_SortFlag_PythonToCpp_QDir_SortFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX]))
        return QDir_SortFlag_PythonToCpp_QDir_SortFlag;
    return 0;
}
static PyObject* QDir_SortFlag_CppToPython_QDir_SortFlag(const void* cppIn) {
    int castCppIn = *((::QDir::SortFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX], castCppIn);

}

static void QFlags_QDir_SortFlag__PythonToCpp_QFlags_QDir_SortFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDir::SortFlag>*)cppOut) = ::QFlags<QDir::SortFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QDir_SortFlag__PythonToCpp_QFlags_QDir_SortFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]))
        return QFlags_QDir_SortFlag__PythonToCpp_QFlags_QDir_SortFlag_;
    return 0;
}
static PyObject* QFlags_QDir_SortFlag__CppToPython_QFlags_QDir_SortFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QDir::SortFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]));

}

static void QDir_SortFlag_PythonToCpp_QFlags_QDir_SortFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDir::SortFlag>*)cppOut) = ::QFlags<QDir::SortFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QDir_SortFlag_PythonToCpp_QFlags_QDir_SortFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX]))
        return QDir_SortFlag_PythonToCpp_QFlags_QDir_SortFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QDir_SortFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QDir::SortFlag>*)cppOut) = ::QFlags<QDir::SortFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QDir_SortFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QDir_SortFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDir_PythonToCpp_QDir_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDir_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDir_PythonToCpp_QDir_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDir_Type))
        return QDir_PythonToCpp_QDir_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDir_PTR_CppToPython_QDir(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QDir*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QDir_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QDir_COPY_CppToPython_QDir(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QDir_Type, new ::QDir(*((::QDir*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QDir_PythonToCpp_QDir_COPY(PyObject* pyIn, void* cppOut) {
    *((::QDir*)cppOut) = *((::QDir*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QDir_PythonToCpp_QDir_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDir_Type))
        return QDir_PythonToCpp_QDir_COPY;
    return 0;
}

// Implicit conversions.
static void constQStringREF_PythonToCpp_QDir(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QDir*)cppOut) = ::QDir(cppIn);
}
static PythonToCppFunc is_constQStringREF_PythonToCpp_QDir_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return constQStringREF_PythonToCpp_QDir;
    return 0;
}

void init_QDir(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QDIR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDir_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDir", "QDir",
        &Sbk_QDir_Type, &Shiboken::callCppDestructor< ::QDir >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDir_Type,
        QDir_PythonToCpp_QDir_PTR,
        is_QDir_PythonToCpp_QDir_PTR_Convertible,
        QDir_PTR_CppToPython_QDir,
        QDir_COPY_CppToPython_QDir);

    Shiboken::Conversions::registerConverterName(converter, "QDir");
    Shiboken::Conversions::registerConverterName(converter, "QDir*");
    Shiboken::Conversions::registerConverterName(converter, "QDir&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDir).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QDir_PythonToCpp_QDir_COPY,
        is_QDir_PythonToCpp_QDir_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStringREF_PythonToCpp_QDir,
        is_constQStringREF_PythonToCpp_QDir_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Filter'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX] = PySide::QFlags::create("Filters", &SbkPySide_QtCore_QDir_Filter_as_number);
    SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDir_Type,
        "Filter",
        "PySide.QtCore.QDir.Filter",
        "QDir::Filter",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Dirs", (long) QDir::Dirs))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Files", (long) QDir::Files))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Drives", (long) QDir::Drives))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "NoSymLinks", (long) QDir::NoSymLinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "AllEntries", (long) QDir::AllEntries))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "TypeMask", (long) QDir::TypeMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Readable", (long) QDir::Readable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Writable", (long) QDir::Writable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Executable", (long) QDir::Executable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "PermissionMask", (long) QDir::PermissionMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Modified", (long) QDir::Modified))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "Hidden", (long) QDir::Hidden))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "System", (long) QDir::System))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "AccessMask", (long) QDir::AccessMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "AllDirs", (long) QDir::AllDirs))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "CaseSensitive", (long) QDir::CaseSensitive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "NoDotAndDotDot", (long) QDir::NoDotAndDotDot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "NoDot", (long) QDir::NoDot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "NoDotDot", (long) QDir::NoDotDot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
        &Sbk_QDir_Type, "NoFilter", (long) QDir::NoFilter))
        return ;
    // Register converter for enum 'QDir::Filter'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX],
            QDir_Filter_CppToPython_QDir_Filter);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDir_Filter_PythonToCpp_QDir_Filter,
            is_QDir_Filter_PythonToCpp_QDir_Filter_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIR_FILTER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDir::Filter");
        Shiboken::Conversions::registerConverterName(converter, "Filter");
    }
    // Register converter for flag 'QFlags<QDir::Filter>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX],
            QFlags_QDir_Filter__CppToPython_QFlags_QDir_Filter_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDir_Filter_PythonToCpp_QFlags_QDir_Filter_,
            is_QDir_Filter_PythonToCpp_QFlags_QDir_Filter__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QDir_Filter__PythonToCpp_QFlags_QDir_Filter_,
            is_QFlags_QDir_Filter__PythonToCpp_QFlags_QDir_Filter__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QDir_Filter_,
            is_number_PythonToCpp_QFlags_QDir_Filter__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QDir::Filter>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Filter>");
    }
    // End of 'Filter' enum/flags.

    // Initialization of enum 'SortFlag'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX] = PySide::QFlags::create("SortFlags", &SbkPySide_QtCore_QDir_SortFlag_as_number);
    SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDir_Type,
        "SortFlag",
        "PySide.QtCore.QDir.SortFlag",
        "QDir::SortFlag",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Name", (long) QDir::Name))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Time", (long) QDir::Time))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Size", (long) QDir::Size))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Unsorted", (long) QDir::Unsorted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "SortByMask", (long) QDir::SortByMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "DirsFirst", (long) QDir::DirsFirst))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Reversed", (long) QDir::Reversed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "IgnoreCase", (long) QDir::IgnoreCase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "DirsLast", (long) QDir::DirsLast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "LocaleAware", (long) QDir::LocaleAware))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "Type", (long) QDir::Type))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
        &Sbk_QDir_Type, "NoSort", (long) QDir::NoSort))
        return ;
    // Register converter for enum 'QDir::SortFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX],
            QDir_SortFlag_CppToPython_QDir_SortFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDir_SortFlag_PythonToCpp_QDir_SortFlag,
            is_QDir_SortFlag_PythonToCpp_QDir_SortFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QDIR_SORTFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDir::SortFlag");
        Shiboken::Conversions::registerConverterName(converter, "SortFlag");
    }
    // Register converter for flag 'QFlags<QDir::SortFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX],
            QFlags_QDir_SortFlag__CppToPython_QFlags_QDir_SortFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDir_SortFlag_PythonToCpp_QFlags_QDir_SortFlag_,
            is_QDir_SortFlag_PythonToCpp_QFlags_QDir_SortFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QDir_SortFlag__PythonToCpp_QFlags_QDir_SortFlag_,
            is_QFlags_QDir_SortFlag__PythonToCpp_QFlags_QDir_SortFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QDir_SortFlag_,
            is_number_PythonToCpp_QFlags_QDir_SortFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_SORTFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QDir::SortFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<SortFlag>");
    }
    // End of 'SortFlag' enum/flags.


    qRegisterMetaType< ::QDir::Filter >("QDir::Filter");
    qRegisterMetaType< ::QDir::Filters >("QDir::Filters");
    qRegisterMetaType< ::QDir::SortFlag >("QDir::SortFlag");
    qRegisterMetaType< ::QDir::SortFlags >("QDir::SortFlags");
}
