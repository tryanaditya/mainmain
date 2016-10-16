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

#include "qfontdatabase_wrapper.h"

// Extra includes
#include <QList>
#include <QStringList>
#include <qbytearray.h>
#include <qfont.h>
#include <qfontinfo.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFontDatabase_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFontDatabase >()))
        return -1;

    ::QFontDatabase* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QFontDatabase", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFontDatabase()
    // 1: QFontDatabase(QFontDatabase)
    if (numArgs == 0) {
        overloadId = 0; // QFontDatabase()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (pyArgs[0])))) {
        overloadId = 1; // QFontDatabase(QFontDatabase)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabase_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFontDatabase()
        {

            if (!PyErr_Occurred()) {
                // QFontDatabase()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontDatabase();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QFontDatabase(const QFontDatabase & QFontDatabase)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QFontDatabase cppArg0_local = ::QFontDatabase();
            ::QFontDatabase* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QFontDatabase(QFontDatabase)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QFontDatabase(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFontDatabase >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFontDatabase_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QFontDatabase_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QFontDatabase", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase", overloads);
        return -1;
}

static PyObject* Sbk_QFontDatabaseFunc_addApplicationFont(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addApplicationFont(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addApplicationFont(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_addApplicationFont_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addApplicationFont(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QFontDatabase::addApplicationFont(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_addApplicationFont_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.addApplicationFont", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_addApplicationFontFromData(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addApplicationFontFromData(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // addApplicationFontFromData(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_addApplicationFontFromData_TypeError;

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
            // addApplicationFontFromData(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QFontDatabase::addApplicationFontFromData(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_addApplicationFontFromData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.addApplicationFontFromData", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_applicationFontFamilies(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: applicationFontFamilies(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // applicationFontFamilies(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_applicationFontFamilies_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // applicationFontFamilies(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QFontDatabase::applicationFontFamilies(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_applicationFontFamilies_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.applicationFontFamilies", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_bold(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "bold", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: bold(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // bold(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_bold_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // bold(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->bold(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_bold_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.bold", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_families(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.families(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:families", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: families(QFontDatabase::WritingSystem)const
    if (numArgs == 0) {
        overloadId = 0; // families(QFontDatabase::WritingSystem)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), (pyArgs[0])))) {
        overloadId = 0; // families(QFontDatabase::WritingSystem)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_families_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "writingSystem");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.families(): got multiple values for keyword argument 'writingSystem'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), (pyArgs[0]))))
                    goto Sbk_QFontDatabaseFunc_families_TypeError;
            }
        }
        ::QFontDatabase::WritingSystem cppArg0 = QFontDatabase::Any;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // families(QFontDatabase::WritingSystem)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->families(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_families_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFontDatabase.WritingSystem = Any", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.families", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_font(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "font", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: font(QString,QString,int)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // font(QString,QString,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_font_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // font(QString,QString,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->font(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_font_TypeError:
        const char* overloads[] = {"unicode, unicode, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.font", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_hasFamily(PyObject* self, PyObject* pyArg)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasFamily(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasFamily(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_hasFamily_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasFamily(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->hasFamily(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_hasFamily_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.hasFamily", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_isBitmapScalable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isBitmapScalable(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isBitmapScalable(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:isBitmapScalable", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isBitmapScalable(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // isBitmapScalable(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // isBitmapScalable(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_isBitmapScalable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "style");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isBitmapScalable(): got multiple values for keyword argument 'style'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFontDatabaseFunc_isBitmapScalable_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isBitmapScalable(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->isBitmapScalable(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_isBitmapScalable_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.isBitmapScalable", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_isFixedPitch(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isFixedPitch(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isFixedPitch(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:isFixedPitch", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isFixedPitch(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // isFixedPitch(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // isFixedPitch(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_isFixedPitch_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "style");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isFixedPitch(): got multiple values for keyword argument 'style'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFontDatabaseFunc_isFixedPitch_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isFixedPitch(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->isFixedPitch(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_isFixedPitch_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.isFixedPitch", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_isScalable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isScalable(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isScalable(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:isScalable", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isScalable(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // isScalable(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // isScalable(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_isScalable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "style");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isScalable(): got multiple values for keyword argument 'style'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFontDatabaseFunc_isScalable_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isScalable(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->isScalable(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_isScalable_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.isScalable", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_isSmoothlyScalable(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isSmoothlyScalable(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isSmoothlyScalable(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:isSmoothlyScalable", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isSmoothlyScalable(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // isSmoothlyScalable(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // isSmoothlyScalable(QString,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_isSmoothlyScalable_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "style");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.isSmoothlyScalable(): got multiple values for keyword argument 'style'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFontDatabaseFunc_isSmoothlyScalable_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isSmoothlyScalable(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->isSmoothlyScalable(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_isSmoothlyScalable_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.isSmoothlyScalable", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_italic(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "italic", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: italic(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // italic(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_italic_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // italic(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->italic(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_italic_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.italic", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_pointSizes(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.pointSizes(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.pointSizes(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:pointSizes", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: pointSizes(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // pointSizes(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // pointSizes(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_pointSizes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "style");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFontDatabase.pointSizes(): got multiple values for keyword argument 'style'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFontDatabaseFunc_pointSizes_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // pointSizes(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = cppSelf->pointSizes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_pointSizes_TypeError:
        const char* overloads[] = {"unicode, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.pointSizes", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_removeAllApplicationFonts(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeAllApplicationFonts()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QFontDatabase::removeAllApplicationFonts();
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

static PyObject* Sbk_QFontDatabaseFunc_removeApplicationFont(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeApplicationFont(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeApplicationFont(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_removeApplicationFont_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeApplicationFont(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QFontDatabase::removeApplicationFont(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_removeApplicationFont_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.removeApplicationFont", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_smoothSizes(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "smoothSizes", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: smoothSizes(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // smoothSizes(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_smoothSizes_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // smoothSizes(QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = cppSelf->smoothSizes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_smoothSizes_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.smoothSizes", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_standardSizes(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardSizes()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = ::QFontDatabase::standardSizes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFontDatabaseFunc_styleString(PyObject* self, PyObject* pyArg)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: styleString(QFont)
    // 1: styleString(QFontInfo)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // styleString(QFont)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], (pyArg)))) {
        overloadId = 1; // styleString(QFontInfo)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_styleString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // styleString(const QFont & font)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QFont cppArg0_local = ::QFont();
            ::QFont* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // styleString(QFont)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = cppSelf->styleString(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // styleString(const QFontInfo & fontInfo)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QFontInfo cppArg0_local = ::QFontInfo(::QFont());
            ::QFontInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // styleString(QFontInfo)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = cppSelf->styleString(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_styleString_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", "PySide.QtGui.QFontInfo", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.styleString", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_styles(PyObject* self, PyObject* pyArg)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: styles(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // styles(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_styles_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // styles(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->styles(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_styles_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.styles", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_supportsThreadedFontRendering(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsThreadedFontRendering()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QFontDatabase::supportsThreadedFontRendering();
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

static PyObject* Sbk_QFontDatabaseFunc_weight(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "weight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: weight(QString,QString)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // weight(QString,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_weight_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // weight(QString,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->weight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_weight_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.weight", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_writingSystemName(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writingSystemName(QFontDatabase::WritingSystem)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), (pyArg)))) {
        overloadId = 0; // writingSystemName(QFontDatabase::WritingSystem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_writingSystemName_TypeError;

    // Call function/method
    {
        ::QFontDatabase::WritingSystem cppArg0 = ((::QFontDatabase::WritingSystem)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // writingSystemName(QFontDatabase::WritingSystem)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QFontDatabase::writingSystemName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_writingSystemName_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFontDatabase.WritingSystem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.writingSystemName", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_writingSystemSample(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writingSystemSample(QFontDatabase::WritingSystem)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]), (pyArg)))) {
        overloadId = 0; // writingSystemSample(QFontDatabase::WritingSystem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_writingSystemSample_TypeError;

    // Call function/method
    {
        ::QFontDatabase::WritingSystem cppArg0 = ((::QFontDatabase::WritingSystem)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // writingSystemSample(QFontDatabase::WritingSystem)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QFontDatabase::writingSystemSample(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_writingSystemSample_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFontDatabase.WritingSystem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFontDatabase.writingSystemSample", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabaseFunc_writingSystems(PyObject* self, PyObject* args)
{
    ::QFontDatabase* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "writingSystems", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: writingSystems()const
    // 1: writingSystems(QString)const
    if (numArgs == 0) {
        overloadId = 0; // writingSystems()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // writingSystems(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFontDatabaseFunc_writingSystems_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // writingSystems() const
        {

            if (!PyErr_Occurred()) {
                // writingSystems()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QFontDatabase::WritingSystem > cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->writingSystems();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX], &cppResult);
            }
            break;
        }
        case 1: // writingSystems(const QString & family) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // writingSystems(QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QFontDatabase::WritingSystem > cppResult = const_cast<const ::QFontDatabase*>(cppSelf)->writingSystems(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFontDatabaseFunc_writingSystems_TypeError:
        const char* overloads[] = {"", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFontDatabase.writingSystems", overloads);
        return 0;
}

static PyObject* Sbk_QFontDatabase___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QFontDatabase& cppSelf = *(((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFontDatabase_methods[] = {
    {"addApplicationFont", (PyCFunction)Sbk_QFontDatabaseFunc_addApplicationFont, METH_O|METH_STATIC},
    {"addApplicationFontFromData", (PyCFunction)Sbk_QFontDatabaseFunc_addApplicationFontFromData, METH_O|METH_STATIC},
    {"applicationFontFamilies", (PyCFunction)Sbk_QFontDatabaseFunc_applicationFontFamilies, METH_O|METH_STATIC},
    {"bold", (PyCFunction)Sbk_QFontDatabaseFunc_bold, METH_VARARGS},
    {"families", (PyCFunction)Sbk_QFontDatabaseFunc_families, METH_VARARGS|METH_KEYWORDS},
    {"font", (PyCFunction)Sbk_QFontDatabaseFunc_font, METH_VARARGS},
    {"hasFamily", (PyCFunction)Sbk_QFontDatabaseFunc_hasFamily, METH_O},
    {"isBitmapScalable", (PyCFunction)Sbk_QFontDatabaseFunc_isBitmapScalable, METH_VARARGS|METH_KEYWORDS},
    {"isFixedPitch", (PyCFunction)Sbk_QFontDatabaseFunc_isFixedPitch, METH_VARARGS|METH_KEYWORDS},
    {"isScalable", (PyCFunction)Sbk_QFontDatabaseFunc_isScalable, METH_VARARGS|METH_KEYWORDS},
    {"isSmoothlyScalable", (PyCFunction)Sbk_QFontDatabaseFunc_isSmoothlyScalable, METH_VARARGS|METH_KEYWORDS},
    {"italic", (PyCFunction)Sbk_QFontDatabaseFunc_italic, METH_VARARGS},
    {"pointSizes", (PyCFunction)Sbk_QFontDatabaseFunc_pointSizes, METH_VARARGS|METH_KEYWORDS},
    {"removeAllApplicationFonts", (PyCFunction)Sbk_QFontDatabaseFunc_removeAllApplicationFonts, METH_NOARGS|METH_STATIC},
    {"removeApplicationFont", (PyCFunction)Sbk_QFontDatabaseFunc_removeApplicationFont, METH_O|METH_STATIC},
    {"smoothSizes", (PyCFunction)Sbk_QFontDatabaseFunc_smoothSizes, METH_VARARGS},
    {"standardSizes", (PyCFunction)Sbk_QFontDatabaseFunc_standardSizes, METH_NOARGS|METH_STATIC},
    {"styleString", (PyCFunction)Sbk_QFontDatabaseFunc_styleString, METH_O},
    {"styles", (PyCFunction)Sbk_QFontDatabaseFunc_styles, METH_O},
    {"supportsThreadedFontRendering", (PyCFunction)Sbk_QFontDatabaseFunc_supportsThreadedFontRendering, METH_NOARGS|METH_STATIC},
    {"weight", (PyCFunction)Sbk_QFontDatabaseFunc_weight, METH_VARARGS},
    {"writingSystemName", (PyCFunction)Sbk_QFontDatabaseFunc_writingSystemName, METH_O|METH_STATIC},
    {"writingSystemSample", (PyCFunction)Sbk_QFontDatabaseFunc_writingSystemSample, METH_O|METH_STATIC},
    {"writingSystems", (PyCFunction)Sbk_QFontDatabaseFunc_writingSystems, METH_VARARGS},

    {"__copy__", (PyCFunction)Sbk_QFontDatabase___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFontDatabase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFontDatabase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QFontDatabase_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFontDatabase",
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
    /*tp_traverse*/         Sbk_QFontDatabase_traverse,
    /*tp_clear*/            Sbk_QFontDatabase_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFontDatabase_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFontDatabase_Init,
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
static void QFontDatabase_WritingSystem_PythonToCpp_QFontDatabase_WritingSystem(PyObject* pyIn, void* cppOut) {
    *((::QFontDatabase::WritingSystem*)cppOut) = (::QFontDatabase::WritingSystem) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFontDatabase_WritingSystem_PythonToCpp_QFontDatabase_WritingSystem_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]))
        return QFontDatabase_WritingSystem_PythonToCpp_QFontDatabase_WritingSystem;
    return 0;
}
static PyObject* QFontDatabase_WritingSystem_CppToPython_QFontDatabase_WritingSystem(const void* cppIn) {
    int castCppIn = *((::QFontDatabase::WritingSystem*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFontDatabase_PythonToCpp_QFontDatabase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFontDatabase_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFontDatabase_PythonToCpp_QFontDatabase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontDatabase_Type))
        return QFontDatabase_PythonToCpp_QFontDatabase_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFontDatabase_PTR_CppToPython_QFontDatabase(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QFontDatabase*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QFontDatabase_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QFontDatabase_COPY_CppToPython_QFontDatabase(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QFontDatabase_Type, new ::QFontDatabase(*((::QFontDatabase*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QFontDatabase_PythonToCpp_QFontDatabase_COPY(PyObject* pyIn, void* cppOut) {
    *((::QFontDatabase*)cppOut) = *((::QFontDatabase*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QFontDatabase_PythonToCpp_QFontDatabase_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFontDatabase_Type))
        return QFontDatabase_PythonToCpp_QFontDatabase_COPY;
    return 0;
}

void init_QFontDatabase(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFontDatabase_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFontDatabase", "QFontDatabase",
        &Sbk_QFontDatabase_Type, &Shiboken::callCppDestructor< ::QFontDatabase >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFontDatabase_Type,
        QFontDatabase_PythonToCpp_QFontDatabase_PTR,
        is_QFontDatabase_PythonToCpp_QFontDatabase_PTR_Convertible,
        QFontDatabase_PTR_CppToPython_QFontDatabase,
        QFontDatabase_COPY_CppToPython_QFontDatabase);

    Shiboken::Conversions::registerConverterName(converter, "QFontDatabase");
    Shiboken::Conversions::registerConverterName(converter, "QFontDatabase*");
    Shiboken::Conversions::registerConverterName(converter, "QFontDatabase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFontDatabase).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QFontDatabase_PythonToCpp_QFontDatabase_COPY,
        is_QFontDatabase_PythonToCpp_QFontDatabase_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'WritingSystem'.
    SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFontDatabase_Type,
        "WritingSystem",
        "PySide.QtGui.QFontDatabase.WritingSystem",
        "QFontDatabase::WritingSystem");
    if (!SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Any", (long) QFontDatabase::Any))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Latin", (long) QFontDatabase::Latin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Greek", (long) QFontDatabase::Greek))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Cyrillic", (long) QFontDatabase::Cyrillic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Armenian", (long) QFontDatabase::Armenian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Hebrew", (long) QFontDatabase::Hebrew))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Arabic", (long) QFontDatabase::Arabic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Syriac", (long) QFontDatabase::Syriac))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Thaana", (long) QFontDatabase::Thaana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Devanagari", (long) QFontDatabase::Devanagari))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Bengali", (long) QFontDatabase::Bengali))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Gurmukhi", (long) QFontDatabase::Gurmukhi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Gujarati", (long) QFontDatabase::Gujarati))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Oriya", (long) QFontDatabase::Oriya))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Tamil", (long) QFontDatabase::Tamil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Telugu", (long) QFontDatabase::Telugu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Kannada", (long) QFontDatabase::Kannada))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Malayalam", (long) QFontDatabase::Malayalam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Sinhala", (long) QFontDatabase::Sinhala))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Thai", (long) QFontDatabase::Thai))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Lao", (long) QFontDatabase::Lao))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Tibetan", (long) QFontDatabase::Tibetan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Myanmar", (long) QFontDatabase::Myanmar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Georgian", (long) QFontDatabase::Georgian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Khmer", (long) QFontDatabase::Khmer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "SimplifiedChinese", (long) QFontDatabase::SimplifiedChinese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "TraditionalChinese", (long) QFontDatabase::TraditionalChinese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Japanese", (long) QFontDatabase::Japanese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Korean", (long) QFontDatabase::Korean))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Vietnamese", (long) QFontDatabase::Vietnamese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Symbol", (long) QFontDatabase::Symbol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Other", (long) QFontDatabase::Other))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Ogham", (long) QFontDatabase::Ogham))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Runic", (long) QFontDatabase::Runic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "Nko", (long) QFontDatabase::Nko))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
        &Sbk_QFontDatabase_Type, "WritingSystemsCount", (long) QFontDatabase::WritingSystemsCount))
        return ;
    // Register converter for enum 'QFontDatabase::WritingSystem'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX],
            QFontDatabase_WritingSystem_CppToPython_QFontDatabase_WritingSystem);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFontDatabase_WritingSystem_PythonToCpp_QFontDatabase_WritingSystem,
            is_QFontDatabase_WritingSystem_PythonToCpp_QFontDatabase_WritingSystem_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFontDatabase::WritingSystem");
        Shiboken::Conversions::registerConverterName(converter, "WritingSystem");
    }
    // End of 'WritingSystem' enum.


    qRegisterMetaType< ::QFontDatabase >("QFontDatabase");
    qRegisterMetaType< ::QFontDatabase::WritingSystem >("QFontDatabase::WritingSystem");
}
