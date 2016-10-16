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

#include "qlocale_wrapper.h"

// Extra includes
#include <QDate>
#include <QList>
#include <qdatetime.h>
#include <qlocale.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QLocale_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QLocale >()))
        return -1;

    ::QLocale* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QLocale", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QLocale()
    // 1: QLocale(QLocale::Language,QLocale::Country)
    // 2: QLocale(QLocale::Language,QLocale::Script,QLocale::Country)
    // 3: QLocale(QLocale)
    // 4: QLocale(QString)
    if (numArgs == 0) {
        overloadId = 0; // QLocale()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 4; // QLocale(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QLocale(QLocale::Language,QLocale::Country)
        } else if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX]), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), (pyArgs[2])))) {
            overloadId = 2; // QLocale(QLocale::Language,QLocale::Script,QLocale::Country)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), (pyArgs[1])))) {
            overloadId = 1; // QLocale(QLocale::Language,QLocale::Country)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArgs[0])))) {
        overloadId = 3; // QLocale(QLocale)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocale_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QLocale()
        {

            if (!PyErr_Occurred()) {
                // QLocale()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLocale();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QLocale(QLocale::Language language, QLocale::Country country)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "country");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale(): got multiple values for keyword argument 'country'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocale_Init_TypeError;
                }
            }
            ::QLocale::Language cppArg0 = ((::QLocale::Language)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::Country cppArg1 = QLocale::AnyCountry;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QLocale(QLocale::Language,QLocale::Country)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLocale(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QLocale(QLocale::Language language, QLocale::Script script, QLocale::Country country)
        {
            ::QLocale::Language cppArg0 = ((::QLocale::Language)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::Script cppArg1 = ((::QLocale::Script)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QLocale::Country cppArg2 = ((::QLocale::Country)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QLocale(QLocale::Language,QLocale::Script,QLocale::Country)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLocale(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QLocale(const QLocale & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QLocale cppArg0_local = ::QLocale();
            ::QLocale* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QLocale(QLocale)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLocale(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QLocale(const QString & name)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QLocale(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QLocale(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QLocale >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QLocale_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QLocale_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QLocale.Language, PySide.QtCore.QLocale.Country = AnyCountry", "PySide.QtCore.QLocale.Language, PySide.QtCore.QLocale.Script, PySide.QtCore.QLocale.Country", "PySide.QtCore.QLocale", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale", overloads);
        return -1;
}

static PyObject* Sbk_QLocaleFunc_amText(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // amText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->amText();
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

static PyObject* Sbk_QLocaleFunc_bcp47Name(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bcp47Name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->bcp47Name();
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

static PyObject* Sbk_QLocaleFunc_c(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // c()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale cppResult = ::QLocale::c();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_countriesForLanguage(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: countriesForLanguage(QLocale::Language)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), (pyArg)))) {
        overloadId = 0; // countriesForLanguage(QLocale::Language)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_countriesForLanguage_TypeError;

    // Call function/method
    {
        ::QLocale::Language cppArg0 = ((::QLocale::Language)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // countriesForLanguage(QLocale::Language)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QLocale::Country > cppResult = ::QLocale::countriesForLanguage(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_COUNTRY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_countriesForLanguage_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.Language", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.countriesForLanguage", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_country(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // country()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale::Country cppResult = const_cast<const ::QLocale*>(cppSelf)->country();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_countryToString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: countryToString(QLocale::Country)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), (pyArg)))) {
        overloadId = 0; // countryToString(QLocale::Country)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_countryToString_TypeError;

    // Call function/method
    {
        ::QLocale::Country cppArg0 = ((::QLocale::Country)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // countryToString(QLocale::Country)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLocale::countryToString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_countryToString_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.Country", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.countryToString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_createSeparatedList(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createSeparatedList(QStringList)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // createSeparatedList(QStringList)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_createSeparatedList_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createSeparatedList(QStringList)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->createSeparatedList(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_createSeparatedList_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.createSeparatedList", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_currencySymbol(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.currencySymbol(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:currencySymbol", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: currencySymbol(QLocale::CurrencySymbolFormat)const
    if (numArgs == 0) {
        overloadId = 0; // currencySymbol(QLocale::CurrencySymbolFormat)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX]), (pyArgs[0])))) {
        overloadId = 0; // currencySymbol(QLocale::CurrencySymbolFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_currencySymbol_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "arg__1");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.currencySymbol(): got multiple values for keyword argument 'arg__1'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX]), (pyArgs[0]))))
                    goto Sbk_QLocaleFunc_currencySymbol_TypeError;
            }
        }
        ::QLocale::CurrencySymbolFormat cppArg0 = QLocale::CurrencySymbol;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // currencySymbol(QLocale::CurrencySymbolFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->currencySymbol(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_currencySymbol_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.CurrencySymbolFormat = CurrencySymbol", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.currencySymbol", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_dateFormat(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dateFormat(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:dateFormat", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: dateFormat(QLocale::FormatType)const
    if (numArgs == 0) {
        overloadId = 0; // dateFormat(QLocale::FormatType)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // dateFormat(QLocale::FormatType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_dateFormat_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dateFormat(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QLocaleFunc_dateFormat_TypeError;
            }
        }
        ::QLocale::FormatType cppArg0 = QLocale::LongFormat;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // dateFormat(QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->dateFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_dateFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.dateFormat", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_dateTimeFormat(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dateTimeFormat(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:dateTimeFormat", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: dateTimeFormat(QLocale::FormatType)const
    if (numArgs == 0) {
        overloadId = 0; // dateTimeFormat(QLocale::FormatType)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // dateTimeFormat(QLocale::FormatType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_dateTimeFormat_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dateTimeFormat(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QLocaleFunc_dateTimeFormat_TypeError;
            }
        }
        ::QLocale::FormatType cppArg0 = QLocale::LongFormat;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // dateTimeFormat(QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->dateTimeFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_dateTimeFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.dateTimeFormat", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_dayName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dayName(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dayName(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:dayName", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: dayName(int,QLocale::FormatType)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // dayName(int,QLocale::FormatType)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // dayName(int,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_dayName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.dayName(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_dayName_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // dayName(int,QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->dayName(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_dayName_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.dayName", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_decimalPoint(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // decimalPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->decimalPoint();
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

static PyObject* Sbk_QLocaleFunc_exponential(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exponential()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->exponential();
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

static PyObject* Sbk_QLocaleFunc_firstDayOfWeek(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstDayOfWeek()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DayOfWeek cppResult = const_cast<const ::QLocale*>(cppSelf)->firstDayOfWeek();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DAYOFWEEK_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_groupSeparator(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // groupSeparator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->groupSeparator();
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

static PyObject* Sbk_QLocaleFunc_language(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // language()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale::Language cppResult = const_cast<const ::QLocale*>(cppSelf)->language();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_languageToString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: languageToString(QLocale::Language)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), (pyArg)))) {
        overloadId = 0; // languageToString(QLocale::Language)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_languageToString_TypeError;

    // Call function/method
    {
        ::QLocale::Language cppArg0 = ((::QLocale::Language)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // languageToString(QLocale::Language)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLocale::languageToString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_languageToString_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.Language", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.languageToString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_matchingLocales(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "matchingLocales", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: matchingLocales(QLocale::Language,QLocale::Script,QLocale::Country)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]), (pyArgs[2])))) {
        overloadId = 0; // matchingLocales(QLocale::Language,QLocale::Script,QLocale::Country)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_matchingLocales_TypeError;

    // Call function/method
    {
        ::QLocale::Language cppArg0 = ((::QLocale::Language)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QLocale::Script cppArg1 = ((::QLocale::Script)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QLocale::Country cppArg2 = ((::QLocale::Country)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // matchingLocales(QLocale::Language,QLocale::Script,QLocale::Country)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QLocale > cppResult = ::QLocale::matchingLocales(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_matchingLocales_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.Language, PySide.QtCore.QLocale.Script, PySide.QtCore.QLocale.Country", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.matchingLocales", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_measurementSystem(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // measurementSystem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale::MeasurementSystem cppResult = const_cast<const ::QLocale*>(cppSelf)->measurementSystem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_monthName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.monthName(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.monthName(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:monthName", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: monthName(int,QLocale::FormatType)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // monthName(int,QLocale::FormatType)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // monthName(int,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_monthName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.monthName(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_monthName_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // monthName(int,QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->monthName(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_monthName_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.monthName", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_name(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->name();
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

static PyObject* Sbk_QLocaleFunc_nativeCountryName(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nativeCountryName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->nativeCountryName();
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

static PyObject* Sbk_QLocaleFunc_nativeLanguageName(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nativeLanguageName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->nativeLanguageName();
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

static PyObject* Sbk_QLocaleFunc_negativeSign(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // negativeSign()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->negativeSign();
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

static PyObject* Sbk_QLocaleFunc_numberOptions(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numberOptions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QLocale::NumberOption> cppResult = const_cast<const ::QLocale*>(cppSelf)->numberOptions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_percent(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // percent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->percent();
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

static PyObject* Sbk_QLocaleFunc_pmText(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pmText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->pmText();
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

static PyObject* Sbk_QLocaleFunc_positiveSign(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // positiveSign()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->positiveSign();
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

static PyObject* Sbk_QLocaleFunc_quoteString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.quoteString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.quoteString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:quoteString", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: quoteString(QString,QLocale::QuotationStyle)const
    // 1: quoteString(QStringRef,QLocale::QuotationStyle)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // quoteString(QStringRef,QLocale::QuotationStyle)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // quoteString(QStringRef,QLocale::QuotationStyle)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // quoteString(QString,QLocale::QuotationStyle)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // quoteString(QString,QLocale::QuotationStyle)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_quoteString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // quoteString(const QString & str, QLocale::QuotationStyle style) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "style");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.quoteString(): got multiple values for keyword argument 'style'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_quoteString_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::QuotationStyle cppArg1 = QLocale::StandardQuotation;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // quoteString(QString,QLocale::QuotationStyle)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->quoteString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // quoteString(const QStringRef & str, QLocale::QuotationStyle style) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "style");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.quoteString(): got multiple values for keyword argument 'style'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_quoteString_TypeError;
                }
            }
            ::QStringRef cppArg0 = ::QStringRef();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::QuotationStyle cppArg1 = QLocale::StandardQuotation;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // quoteString(QStringRef,QLocale::QuotationStyle)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->quoteString(cppArg0, cppArg1);
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

    Sbk_QLocaleFunc_quoteString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QLocale.QuotationStyle = StandardQuotation", "QStringRef, PySide.QtCore.QLocale.QuotationStyle = StandardQuotation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.quoteString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_script(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // script()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale::Script cppResult = const_cast<const ::QLocale*>(cppSelf)->script();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_scriptToString(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: scriptToString(QLocale::Script)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX]), (pyArg)))) {
        overloadId = 0; // scriptToString(QLocale::Script)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_scriptToString_TypeError;

    // Call function/method
    {
        ::QLocale::Script cppArg0 = ((::QLocale::Script)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // scriptToString(QLocale::Script)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QLocale::scriptToString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_scriptToString_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.Script", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.scriptToString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_setDefault(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefault(QLocale)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
        overloadId = 0; // setDefault(QLocale)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_setDefault_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLocale cppArg0_local = ::QLocale();
        ::QLocale* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDefault(QLocale)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QLocale::setDefault(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLocaleFunc_setDefault_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.setDefault", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_setNumberOptions(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumberOptions(QFlags<QLocale::NumberOption>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), (pyArg)))) {
        overloadId = 0; // setNumberOptions(QFlags<QLocale::NumberOption>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_setNumberOptions_TypeError;

    // Call function/method
    {
        ::QFlags<QLocale::NumberOption> cppArg0 = ((::QFlags<QLocale::NumberOption>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumberOptions(QFlags<QLocale::NumberOption>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumberOptions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLocaleFunc_setNumberOptions_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.NumberOptions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.setNumberOptions", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_standaloneDayName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneDayName(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneDayName(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:standaloneDayName", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: standaloneDayName(int,QLocale::FormatType)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // standaloneDayName(int,QLocale::FormatType)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // standaloneDayName(int,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_standaloneDayName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneDayName(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_standaloneDayName_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // standaloneDayName(int,QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->standaloneDayName(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_standaloneDayName_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.standaloneDayName", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_standaloneMonthName(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneMonthName(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneMonthName(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:standaloneMonthName", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: standaloneMonthName(int,QLocale::FormatType)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // standaloneMonthName(int,QLocale::FormatType)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // standaloneMonthName(int,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_standaloneMonthName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.standaloneMonthName(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_standaloneMonthName_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // standaloneMonthName(int,QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->standaloneMonthName(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_standaloneMonthName_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.standaloneMonthName", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_system(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // system()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLocale cppResult = ::QLocale::system();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_textDirection(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QLocale*>(cppSelf)->textDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_timeFormat(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.timeFormat(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:timeFormat", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: timeFormat(QLocale::FormatType)const
    if (numArgs == 0) {
        overloadId = 0; // timeFormat(QLocale::FormatType)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // timeFormat(QLocale::FormatType)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_timeFormat_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.timeFormat(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[0]))))
                    goto Sbk_QLocaleFunc_timeFormat_TypeError;
            }
        }
        ::QLocale::FormatType cppArg0 = QLocale::LongFormat;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // timeFormat(QLocale::FormatType)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->timeFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_timeFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLocale.FormatType = LongFormat", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.timeFormat", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toCurrencyString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toCurrencyString", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toCurrencyString(double,QString)const
    // 1: toCurrencyString(float,QString)const
    // 2: toCurrencyString(int,QString)const
    // 3: toCurrencyString(qlonglong,QString)const
    // 4: toCurrencyString(qulonglong,QString)const
    // 5: toCurrencyString(short,QString)const
    // 6: toCurrencyString(uint,QString)const
    // 7: toCurrencyString(ushort,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 7; // toCurrencyString(ushort,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 7; // toCurrencyString(ushort,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // toCurrencyString(uint,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 6; // toCurrencyString(uint,QString)const
        }
    } else if (PyLong_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qulonglong>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // toCurrencyString(qulonglong,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 4; // toCurrencyString(qulonglong,QString)const
        }
    } else if (PyLong_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // toCurrencyString(qlonglong,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 3; // toCurrencyString(qlonglong,QString)const
        }
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // toCurrencyString(float,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // toCurrencyString(float,QString)const
        }
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toCurrencyString(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // toCurrencyString(double,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<short>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // toCurrencyString(short,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 5; // toCurrencyString(short,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // toCurrencyString(int,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 2; // toCurrencyString(int,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toCurrencyString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toCurrencyString(double arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(double,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // toCurrencyString(float arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            float cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(float,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // toCurrencyString(int arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(int,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 3: // toCurrencyString(qlonglong arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            qlonglong cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(qlonglong,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 4: // toCurrencyString(qulonglong arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            qulonglong cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(qulonglong,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 5: // toCurrencyString(short arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            short cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(short,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 6: // toCurrencyString(uint arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            uint cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(uint,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 7: // toCurrencyString(ushort arg__1, const QString & symbol) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "symbol");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toCurrencyString(): got multiple values for keyword argument 'symbol'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toCurrencyString_TypeError;
                }
            }
            ushort cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toCurrencyString(ushort,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toCurrencyString(cppArg0, cppArg1);
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

    Sbk_QLocaleFunc_toCurrencyString_TypeError:
        const char* overloads[] = {"float, unicode = QString()", "float, unicode = QString()", "int, unicode = QString()", "long long, unicode = QString()", "unsigned long long, unicode = QString()", "short, unicode = QString()", "unsigned int, unicode = QString()", "unsigned short, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toCurrencyString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toDate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toDate", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toDate(QString,QLocale::FormatType)const
    // 1: toDate(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toDate(QString,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // toDate(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // toDate(QString,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toDate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toDate(const QString & string, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDate(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toDate_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toDate(QString,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDate cppResult = const_cast<const ::QLocale*>(cppSelf)->toDate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
            }
            break;
        }
        case 1: // toDate(const QString & string, const QString & format) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toDate(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDate cppResult = const_cast<const ::QLocale*>(cppSelf)->toDate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toDate_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QLocale.FormatType = LongFormat", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toDate", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toDateTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDateTime(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDateTime(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toDateTime", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toDateTime(QString,QLocale::FormatType)const
    // 1: toDateTime(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toDateTime(QString,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // toDateTime(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // toDateTime(QString,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toDateTime_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toDateTime(const QString & string, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toDateTime(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toDateTime_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toDateTime(QString,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDateTime cppResult = const_cast<const ::QLocale*>(cppSelf)->toDateTime(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
            }
            break;
        }
        case 1: // toDateTime(const QString & string, const QString & format) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toDateTime(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QDateTime cppResult = const_cast<const ::QLocale*>(cppSelf)->toDateTime(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toDateTime_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QLocale.FormatType = LongFormat", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toDateTime", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toDouble(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toDouble(QString,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toDouble(QString,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toDouble_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toDouble(QString,bool*)const
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double retval_ = cppSelf->toDouble(cppArg0, &ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_args,bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toDouble_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.toDouble", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toFloat(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toFloat(QString,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toFloat(QString,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toFloat_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toFloat(QString,bool*)const
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            float retval_ = cppSelf->toFloat(cppArg0, &ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_args,bool* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toFloat_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.toFloat", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toInt(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toInt(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toInt", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toInt(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toInt(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toInt(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toInt_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toInt(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toInt_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool* removed_cppArg1 = 0;
        SBK_UNUSED(removed_cppArg1)
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toInt(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int retval_ = cppSelf->toInt(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toInt_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toInt", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toLongLong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toLongLong(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toLongLong(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toLongLong", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toLongLong(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toLongLong(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toLongLong(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toLongLong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toLongLong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toLongLong_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool* removed_cppArg1 = 0;
        SBK_UNUSED(removed_cppArg1)
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toLongLong(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qlonglong retval_ = cppSelf->toLongLong(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toLongLong_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toLongLong", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toLower(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toLower(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toLower(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toLower_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toLower(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toLower(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toLower_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.toLower", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toShort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toShort(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toShort(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toShort", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toShort(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toShort(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toShort(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toShort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toShort(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toShort_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool* removed_cppArg1 = 0;
        SBK_UNUSED(removed_cppArg1)
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toShort(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            short retval_ = cppSelf->toShort(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<short>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toShort_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toShort", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:toString", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: toString(QDate,QLocale::FormatType)const
    // 1: toString(QDate,QString)const
    // 2: toString(QDateTime,QLocale::FormatType)const
    // 3: toString(QDateTime,QString)const
    // 4: toString(QTime,QLocale::FormatType)const
    // 5: toString(QTime,QString)const
    // 6: toString(double,char,int)const
    // 7: toString(float,char,int)const
    // 8: toString(int)const
    // 9: toString(qlonglong)const
    // 10: toString(short)const
    if (numArgs == 1
        && PyLong_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), (pyArgs[0])))) {
        overloadId = 9; // toString(qlonglong)const
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 7; // toString(float,char,int)const
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 7; // toString(float,char,int)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 7; // toString(float,char,int)const
            }
        }
    } else if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // toString(double,char,int)const
        } else if (SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 6; // toString(double,char,int)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 6; // toString(double,char,int)const
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<short>(), (pyArgs[0])))) {
        overloadId = 10; // toString(short)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 8; // toString(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // toString(QTime,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 5; // toString(QTime,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 4; // toString(QTime,QLocale::FormatType)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // toString(QDateTime,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 3; // toString(QDateTime,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 2; // toString(QDateTime,QLocale::FormatType)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toString(QDate,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // toString(QDate,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // toString(QDate,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toString_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toString(const QDate & date, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QDate,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // toString(const QDate & date, const QString & formatStr) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QDate,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 2: // toString(const QDateTime & dateTime, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QDateTime,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 3: // toString(const QDateTime & dateTime, const QString & format) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QDateTime,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 4: // toString(const QTime & time, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QTime,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 5: // toString(const QTime & time, const QString & formatStr) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toString(QTime,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 6: // toString(double i, char f, int prec) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
                value = PyDict_GetItemString(kwds, "prec");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'prec'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1 = 'g';
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 6;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // toString(double,char,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 7: // toString(float i, char f, int prec) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "f");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'f'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!SbkChar_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<char>(), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
                value = PyDict_GetItemString(kwds, "prec");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toString(): got multiple values for keyword argument 'prec'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QLocaleFunc_toString_TypeError;
                }
            }
            float cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            char cppArg1 = 'g';
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 6;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // toString(float,char,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 8: // toString(int i) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 9: // toString(qlonglong i) const
        {
            qlonglong cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(qlonglong)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 10: // toString(short i) const
        {
            short cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // toString(short)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toString(cppArg0);
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

    Sbk_QLocaleFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate, PySide.QtCore.QLocale.FormatType = LongFormat", "PySide.QtCore.QDate, unicode", "PySide.QtCore.QDateTime, PySide.QtCore.QLocale.FormatType = LongFormat", "PySide.QtCore.QDateTime, unicode", "PySide.QtCore.QTime, PySide.QtCore.QLocale.FormatType = LongFormat", "PySide.QtCore.QTime, unicode", "float, char = 'g', int = 6", "float, char = 'g', int = 6", "int", "long long", "short", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toString", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toTime(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toTime(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toTime", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toTime(QString,QLocale::FormatType)const
    // 1: toTime(QString,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toTime(QString,QLocale::FormatType)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // toTime(QString,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // toTime(QString,QLocale::FormatType)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toTime_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // toTime(const QString & string, QLocale::FormatType format) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toTime(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]), (pyArgs[1]))))
                        goto Sbk_QLocaleFunc_toTime_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QLocale::FormatType cppArg1 = QLocale::LongFormat;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toTime(QString,QLocale::FormatType)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTime cppResult = const_cast<const ::QLocale*>(cppSelf)->toTime(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
            }
            break;
        }
        case 1: // toTime(const QString & string, const QString & format) const
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // toTime(QString,QString)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QTime cppResult = const_cast<const ::QLocale*>(cppSelf)->toTime(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toTime_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QLocale.FormatType = LongFormat", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toTime", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toUInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUInt(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUInt(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toUInt", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toUInt(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toUInt(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toUInt(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toUInt_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUInt(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toUInt_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toUInt(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint retval_ = cppSelf->toUInt(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toUInt_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toUInt", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toULongLong(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toULongLong(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toULongLong(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toULongLong", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toULongLong(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toULongLong(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toULongLong(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toULongLong_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toULongLong(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toULongLong_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toULongLong(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qlonglong retval_ = cppSelf->toULongLong(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qlonglong>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toULongLong_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toULongLong", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toUShort(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUShort(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUShort(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:toUShort", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: toUShort(QString,bool*,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // toUShort(QString,bool*,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // toUShort(QString,bool*,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toUShort_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "base");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QLocale.toUShort(): got multiple values for keyword argument 'base'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLocaleFunc_toUShort_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool* removed_cppArg1 = 0;
        SBK_UNUSED(removed_cppArg1)
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // toUShort(QString,bool*,int)const
            // Begin code injection

            // TEMPLATE - fix_arg,bool*,arg - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ushort retval_ = cppSelf->toUShort(cppArg0, &ok_, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok_));
            // TEMPLATE - tuple_retval_ok - END
            // TEMPLATE - fix_arg,bool*,arg - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toUShort_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QLocale.toUShort", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_toUpper(PyObject* self, PyObject* pyArg)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toUpper(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toUpper(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLocaleFunc_toUpper_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toUpper(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLocale*>(cppSelf)->toUpper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLocaleFunc_toUpper_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QLocale.toUpper", overloads);
        return 0;
}

static PyObject* Sbk_QLocaleFunc_uiLanguages(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uiLanguages()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QLocale*>(cppSelf)->uiLanguages();
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

static PyObject* Sbk_QLocaleFunc_weekdays(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // weekdays()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<Qt::DayOfWeek > cppResult = const_cast<const ::QLocale*>(cppSelf)->weekdays();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QTCORE_QLIST_QT_DAYOFWEEK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLocaleFunc_zeroDigit(PyObject* self)
{
    ::QLocale* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // zeroDigit()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QChar cppResult = const_cast<const ::QLocale*>(cppSelf)->zeroDigit();
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

static PyObject* Sbk_QLocale___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QLocale& cppSelf = *(((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QLocale_methods[] = {
    {"amText", (PyCFunction)Sbk_QLocaleFunc_amText, METH_NOARGS},
    {"bcp47Name", (PyCFunction)Sbk_QLocaleFunc_bcp47Name, METH_NOARGS},
    {"c", (PyCFunction)Sbk_QLocaleFunc_c, METH_NOARGS|METH_STATIC},
    {"countriesForLanguage", (PyCFunction)Sbk_QLocaleFunc_countriesForLanguage, METH_O|METH_STATIC},
    {"country", (PyCFunction)Sbk_QLocaleFunc_country, METH_NOARGS},
    {"countryToString", (PyCFunction)Sbk_QLocaleFunc_countryToString, METH_O|METH_STATIC},
    {"createSeparatedList", (PyCFunction)Sbk_QLocaleFunc_createSeparatedList, METH_O},
    {"currencySymbol", (PyCFunction)Sbk_QLocaleFunc_currencySymbol, METH_VARARGS|METH_KEYWORDS},
    {"dateFormat", (PyCFunction)Sbk_QLocaleFunc_dateFormat, METH_VARARGS|METH_KEYWORDS},
    {"dateTimeFormat", (PyCFunction)Sbk_QLocaleFunc_dateTimeFormat, METH_VARARGS|METH_KEYWORDS},
    {"dayName", (PyCFunction)Sbk_QLocaleFunc_dayName, METH_VARARGS|METH_KEYWORDS},
    {"decimalPoint", (PyCFunction)Sbk_QLocaleFunc_decimalPoint, METH_NOARGS},
    {"exponential", (PyCFunction)Sbk_QLocaleFunc_exponential, METH_NOARGS},
    {"firstDayOfWeek", (PyCFunction)Sbk_QLocaleFunc_firstDayOfWeek, METH_NOARGS},
    {"groupSeparator", (PyCFunction)Sbk_QLocaleFunc_groupSeparator, METH_NOARGS},
    {"language", (PyCFunction)Sbk_QLocaleFunc_language, METH_NOARGS},
    {"languageToString", (PyCFunction)Sbk_QLocaleFunc_languageToString, METH_O|METH_STATIC},
    {"matchingLocales", (PyCFunction)Sbk_QLocaleFunc_matchingLocales, METH_VARARGS|METH_STATIC},
    {"measurementSystem", (PyCFunction)Sbk_QLocaleFunc_measurementSystem, METH_NOARGS},
    {"monthName", (PyCFunction)Sbk_QLocaleFunc_monthName, METH_VARARGS|METH_KEYWORDS},
    {"name", (PyCFunction)Sbk_QLocaleFunc_name, METH_NOARGS},
    {"nativeCountryName", (PyCFunction)Sbk_QLocaleFunc_nativeCountryName, METH_NOARGS},
    {"nativeLanguageName", (PyCFunction)Sbk_QLocaleFunc_nativeLanguageName, METH_NOARGS},
    {"negativeSign", (PyCFunction)Sbk_QLocaleFunc_negativeSign, METH_NOARGS},
    {"numberOptions", (PyCFunction)Sbk_QLocaleFunc_numberOptions, METH_NOARGS},
    {"percent", (PyCFunction)Sbk_QLocaleFunc_percent, METH_NOARGS},
    {"pmText", (PyCFunction)Sbk_QLocaleFunc_pmText, METH_NOARGS},
    {"positiveSign", (PyCFunction)Sbk_QLocaleFunc_positiveSign, METH_NOARGS},
    {"quoteString", (PyCFunction)Sbk_QLocaleFunc_quoteString, METH_VARARGS|METH_KEYWORDS},
    {"script", (PyCFunction)Sbk_QLocaleFunc_script, METH_NOARGS},
    {"scriptToString", (PyCFunction)Sbk_QLocaleFunc_scriptToString, METH_O|METH_STATIC},
    {"setDefault", (PyCFunction)Sbk_QLocaleFunc_setDefault, METH_O|METH_STATIC},
    {"setNumberOptions", (PyCFunction)Sbk_QLocaleFunc_setNumberOptions, METH_O},
    {"standaloneDayName", (PyCFunction)Sbk_QLocaleFunc_standaloneDayName, METH_VARARGS|METH_KEYWORDS},
    {"standaloneMonthName", (PyCFunction)Sbk_QLocaleFunc_standaloneMonthName, METH_VARARGS|METH_KEYWORDS},
    {"system", (PyCFunction)Sbk_QLocaleFunc_system, METH_NOARGS|METH_STATIC},
    {"textDirection", (PyCFunction)Sbk_QLocaleFunc_textDirection, METH_NOARGS},
    {"timeFormat", (PyCFunction)Sbk_QLocaleFunc_timeFormat, METH_VARARGS|METH_KEYWORDS},
    {"toCurrencyString", (PyCFunction)Sbk_QLocaleFunc_toCurrencyString, METH_VARARGS|METH_KEYWORDS},
    {"toDate", (PyCFunction)Sbk_QLocaleFunc_toDate, METH_VARARGS|METH_KEYWORDS},
    {"toDateTime", (PyCFunction)Sbk_QLocaleFunc_toDateTime, METH_VARARGS|METH_KEYWORDS},
    {"toDouble", (PyCFunction)Sbk_QLocaleFunc_toDouble, METH_O},
    {"toFloat", (PyCFunction)Sbk_QLocaleFunc_toFloat, METH_O},
    {"toInt", (PyCFunction)Sbk_QLocaleFunc_toInt, METH_VARARGS|METH_KEYWORDS},
    {"toLongLong", (PyCFunction)Sbk_QLocaleFunc_toLongLong, METH_VARARGS|METH_KEYWORDS},
    {"toLower", (PyCFunction)Sbk_QLocaleFunc_toLower, METH_O},
    {"toShort", (PyCFunction)Sbk_QLocaleFunc_toShort, METH_VARARGS|METH_KEYWORDS},
    {"toString", (PyCFunction)Sbk_QLocaleFunc_toString, METH_VARARGS|METH_KEYWORDS},
    {"toTime", (PyCFunction)Sbk_QLocaleFunc_toTime, METH_VARARGS|METH_KEYWORDS},
    {"toUInt", (PyCFunction)Sbk_QLocaleFunc_toUInt, METH_VARARGS|METH_KEYWORDS},
    {"toULongLong", (PyCFunction)Sbk_QLocaleFunc_toULongLong, METH_VARARGS|METH_KEYWORDS},
    {"toUShort", (PyCFunction)Sbk_QLocaleFunc_toUShort, METH_VARARGS|METH_KEYWORDS},
    {"toUpper", (PyCFunction)Sbk_QLocaleFunc_toUpper, METH_O},
    {"uiLanguages", (PyCFunction)Sbk_QLocaleFunc_uiLanguages, METH_NOARGS},
    {"weekdays", (PyCFunction)Sbk_QLocaleFunc_weekdays, METH_NOARGS},
    {"zeroDigit", (PyCFunction)Sbk_QLocaleFunc_zeroDigit, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QLocale___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QLocale_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QLocale& cppSelf = *(((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
                // operator!=(const QLocale & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QLocale cppArg0_local = ::QLocale();
                ::QLocale* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (pyArg)))) {
                // operator==(const QLocale & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QLocale cppArg0_local = ::QLocale();
                ::QLocale* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], pythonToCpp))
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
            goto Sbk_QLocale_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QLocale_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QLocale_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QLocale_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QLocale_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QLocale",
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
    /*tp_traverse*/         Sbk_QLocale_traverse,
    /*tp_clear*/            Sbk_QLocale_clear,
    /*tp_richcompare*/      Sbk_QLocale_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QLocale_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QLocale_Init,
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

PyObject* SbkPySide_QtCore_QLocale_NumberOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QLocale::NumberOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QLocale::NumberOptions)PyLong_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QLocale::NumberOptions)PyInt_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QLocale_NumberOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QLocale::NumberOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QLocale::NumberOptions)PyLong_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QLocale::NumberOptions)PyInt_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QLocale_NumberOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QLocale::NumberOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QLocale::NumberOptions)PyLong_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QLocale::NumberOptions)PyInt_AsLong(self);
    cppArg = (QLocale::NumberOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtCore_QLocale_NumberOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QLocale::NumberOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), self, &cppSelf);
    ::QLocale::NumberOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtCore_QLocale_NumberOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtCore_QLocale_NumberOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtCore_QLocale_NumberOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtCore_QLocale_NumberOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtCore_QLocale_NumberOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtCore_QLocale_NumberOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtCore_QLocale_NumberOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtCore_QLocale_NumberOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtCore_QLocale_NumberOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtCore_QLocale_NumberOption_long,
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
static void QLocale_Language_PythonToCpp_QLocale_Language(PyObject* pyIn, void* cppOut) {
    *((::QLocale::Language*)cppOut) = (::QLocale::Language) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_Language_PythonToCpp_QLocale_Language_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]))
        return QLocale_Language_PythonToCpp_QLocale_Language;
    return 0;
}
static PyObject* QLocale_Language_CppToPython_QLocale_Language(const void* cppIn) {
    int castCppIn = *((::QLocale::Language*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX], castCppIn);

}

static void QLocale_Script_PythonToCpp_QLocale_Script(PyObject* pyIn, void* cppOut) {
    *((::QLocale::Script*)cppOut) = (::QLocale::Script) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_Script_PythonToCpp_QLocale_Script_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX]))
        return QLocale_Script_PythonToCpp_QLocale_Script;
    return 0;
}
static PyObject* QLocale_Script_CppToPython_QLocale_Script(const void* cppIn) {
    int castCppIn = *((::QLocale::Script*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX], castCppIn);

}

static void QLocale_Country_PythonToCpp_QLocale_Country(PyObject* pyIn, void* cppOut) {
    *((::QLocale::Country*)cppOut) = (::QLocale::Country) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_Country_PythonToCpp_QLocale_Country_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX]))
        return QLocale_Country_PythonToCpp_QLocale_Country;
    return 0;
}
static PyObject* QLocale_Country_CppToPython_QLocale_Country(const void* cppIn) {
    int castCppIn = *((::QLocale::Country*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX], castCppIn);

}

static void QLocale_MeasurementSystem_PythonToCpp_QLocale_MeasurementSystem(PyObject* pyIn, void* cppOut) {
    *((::QLocale::MeasurementSystem*)cppOut) = (::QLocale::MeasurementSystem) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_MeasurementSystem_PythonToCpp_QLocale_MeasurementSystem_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX]))
        return QLocale_MeasurementSystem_PythonToCpp_QLocale_MeasurementSystem;
    return 0;
}
static PyObject* QLocale_MeasurementSystem_CppToPython_QLocale_MeasurementSystem(const void* cppIn) {
    int castCppIn = *((::QLocale::MeasurementSystem*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX], castCppIn);

}

static void QLocale_FormatType_PythonToCpp_QLocale_FormatType(PyObject* pyIn, void* cppOut) {
    *((::QLocale::FormatType*)cppOut) = (::QLocale::FormatType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_FormatType_PythonToCpp_QLocale_FormatType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX]))
        return QLocale_FormatType_PythonToCpp_QLocale_FormatType;
    return 0;
}
static PyObject* QLocale_FormatType_CppToPython_QLocale_FormatType(const void* cppIn) {
    int castCppIn = *((::QLocale::FormatType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX], castCppIn);

}

static void QLocale_NumberOption_PythonToCpp_QLocale_NumberOption(PyObject* pyIn, void* cppOut) {
    *((::QLocale::NumberOption*)cppOut) = (::QLocale::NumberOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_NumberOption_PythonToCpp_QLocale_NumberOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX]))
        return QLocale_NumberOption_PythonToCpp_QLocale_NumberOption;
    return 0;
}
static PyObject* QLocale_NumberOption_CppToPython_QLocale_NumberOption(const void* cppIn) {
    int castCppIn = *((::QLocale::NumberOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX], castCppIn);

}

static void QFlags_QLocale_NumberOption__PythonToCpp_QFlags_QLocale_NumberOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QLocale::NumberOption>*)cppOut) = ::QFlags<QLocale::NumberOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QLocale_NumberOption__PythonToCpp_QFlags_QLocale_NumberOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]))
        return QFlags_QLocale_NumberOption__PythonToCpp_QFlags_QLocale_NumberOption_;
    return 0;
}
static PyObject* QFlags_QLocale_NumberOption__CppToPython_QFlags_QLocale_NumberOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QLocale::NumberOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]));

}

static void QLocale_NumberOption_PythonToCpp_QFlags_QLocale_NumberOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QLocale::NumberOption>*)cppOut) = ::QFlags<QLocale::NumberOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QLocale_NumberOption_PythonToCpp_QFlags_QLocale_NumberOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX]))
        return QLocale_NumberOption_PythonToCpp_QFlags_QLocale_NumberOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QLocale_NumberOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QLocale::NumberOption>*)cppOut) = ::QFlags<QLocale::NumberOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QLocale_NumberOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QLocale_NumberOption_;
    return 0;
}
static void QLocale_CurrencySymbolFormat_PythonToCpp_QLocale_CurrencySymbolFormat(PyObject* pyIn, void* cppOut) {
    *((::QLocale::CurrencySymbolFormat*)cppOut) = (::QLocale::CurrencySymbolFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_CurrencySymbolFormat_PythonToCpp_QLocale_CurrencySymbolFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX]))
        return QLocale_CurrencySymbolFormat_PythonToCpp_QLocale_CurrencySymbolFormat;
    return 0;
}
static PyObject* QLocale_CurrencySymbolFormat_CppToPython_QLocale_CurrencySymbolFormat(const void* cppIn) {
    int castCppIn = *((::QLocale::CurrencySymbolFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX], castCppIn);

}

static void QLocale_QuotationStyle_PythonToCpp_QLocale_QuotationStyle(PyObject* pyIn, void* cppOut) {
    *((::QLocale::QuotationStyle*)cppOut) = (::QLocale::QuotationStyle) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLocale_QuotationStyle_PythonToCpp_QLocale_QuotationStyle_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX]))
        return QLocale_QuotationStyle_PythonToCpp_QLocale_QuotationStyle;
    return 0;
}
static PyObject* QLocale_QuotationStyle_CppToPython_QLocale_QuotationStyle(const void* cppIn) {
    int castCppIn = *((::QLocale::QuotationStyle*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QLocale_PythonToCpp_QLocale_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QLocale_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QLocale_PythonToCpp_QLocale_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLocale_Type))
        return QLocale_PythonToCpp_QLocale_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QLocale_PTR_CppToPython_QLocale(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QLocale*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QLocale_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QLocale_COPY_CppToPython_QLocale(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QLocale_Type, new ::QLocale(*((::QLocale*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QLocale_PythonToCpp_QLocale_COPY(PyObject* pyIn, void* cppOut) {
    *((::QLocale*)cppOut) = *((::QLocale*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QLocale_PythonToCpp_QLocale_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLocale_Type))
        return QLocale_PythonToCpp_QLocale_COPY;
    return 0;
}

// Implicit conversions.
static void QLocale_Language_PythonToCpp_QLocale(PyObject* pyIn, void* cppOut) {
    ::QLocale::Language cppIn = ((::QLocale::Language)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX]), pyIn, &cppIn);
    *((::QLocale*)cppOut) = ::QLocale(cppIn);
}
static PythonToCppFunc is_QLocale_Language_PythonToCpp_QLocale_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX], pyIn))
        return QLocale_Language_PythonToCpp_QLocale;
    return 0;
}

static void constQStringREF_PythonToCpp_QLocale(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QLocale*)cppOut) = ::QLocale(cppIn);
}
static PythonToCppFunc is_constQStringREF_PythonToCpp_QLocale_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return constQStringREF_PythonToCpp_QLocale;
    return 0;
}

void init_QLocale(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QLOCALE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QLocale_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QLocale", "QLocale",
        &Sbk_QLocale_Type, &Shiboken::callCppDestructor< ::QLocale >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QLocale_Type,
        QLocale_PythonToCpp_QLocale_PTR,
        is_QLocale_PythonToCpp_QLocale_PTR_Convertible,
        QLocale_PTR_CppToPython_QLocale,
        QLocale_COPY_CppToPython_QLocale);

    Shiboken::Conversions::registerConverterName(converter, "QLocale");
    Shiboken::Conversions::registerConverterName(converter, "QLocale*");
    Shiboken::Conversions::registerConverterName(converter, "QLocale&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLocale).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QLocale_PythonToCpp_QLocale_COPY,
        is_QLocale_PythonToCpp_QLocale_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QLocale_Language_PythonToCpp_QLocale,
        is_QLocale_Language_PythonToCpp_QLocale_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQStringREF_PythonToCpp_QLocale,
        is_constQStringREF_PythonToCpp_QLocale_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Language'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "Language",
        "PySide.QtCore.QLocale.Language",
        "QLocale::Language");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "AnyLanguage", (long) QLocale::AnyLanguage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "C", (long) QLocale::C))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Abkhazian", (long) QLocale::Abkhazian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Afan", (long) QLocale::Afan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Afar", (long) QLocale::Afar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Afrikaans", (long) QLocale::Afrikaans))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Albanian", (long) QLocale::Albanian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Amharic", (long) QLocale::Amharic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Arabic", (long) QLocale::Arabic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Armenian", (long) QLocale::Armenian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Assamese", (long) QLocale::Assamese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Aymara", (long) QLocale::Aymara))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Azerbaijani", (long) QLocale::Azerbaijani))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bashkir", (long) QLocale::Bashkir))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Basque", (long) QLocale::Basque))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bengali", (long) QLocale::Bengali))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bhutani", (long) QLocale::Bhutani))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bihari", (long) QLocale::Bihari))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bislama", (long) QLocale::Bislama))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Breton", (long) QLocale::Breton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bulgarian", (long) QLocale::Bulgarian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Burmese", (long) QLocale::Burmese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Byelorussian", (long) QLocale::Byelorussian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Cambodian", (long) QLocale::Cambodian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Catalan", (long) QLocale::Catalan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Chinese", (long) QLocale::Chinese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Corsican", (long) QLocale::Corsican))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Croatian", (long) QLocale::Croatian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Czech", (long) QLocale::Czech))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Danish", (long) QLocale::Danish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Dutch", (long) QLocale::Dutch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "English", (long) QLocale::English))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Esperanto", (long) QLocale::Esperanto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Estonian", (long) QLocale::Estonian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Faroese", (long) QLocale::Faroese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "FijiLanguage", (long) QLocale::FijiLanguage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Finnish", (long) QLocale::Finnish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "French", (long) QLocale::French))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Frisian", (long) QLocale::Frisian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Gaelic", (long) QLocale::Gaelic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Galician", (long) QLocale::Galician))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Georgian", (long) QLocale::Georgian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "German", (long) QLocale::German))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Greek", (long) QLocale::Greek))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Greenlandic", (long) QLocale::Greenlandic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Guarani", (long) QLocale::Guarani))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Gujarati", (long) QLocale::Gujarati))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Hausa", (long) QLocale::Hausa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Hebrew", (long) QLocale::Hebrew))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Hindi", (long) QLocale::Hindi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Hungarian", (long) QLocale::Hungarian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Icelandic", (long) QLocale::Icelandic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Indonesian", (long) QLocale::Indonesian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Interlingua", (long) QLocale::Interlingua))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Interlingue", (long) QLocale::Interlingue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Inuktitut", (long) QLocale::Inuktitut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Inupiak", (long) QLocale::Inupiak))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Irish", (long) QLocale::Irish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Italian", (long) QLocale::Italian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Japanese", (long) QLocale::Japanese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Javanese", (long) QLocale::Javanese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kannada", (long) QLocale::Kannada))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kashmiri", (long) QLocale::Kashmiri))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kazakh", (long) QLocale::Kazakh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kinyarwanda", (long) QLocale::Kinyarwanda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kirghiz", (long) QLocale::Kirghiz))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Korean", (long) QLocale::Korean))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kurdish", (long) QLocale::Kurdish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Rundi", (long) QLocale::Rundi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Laothian", (long) QLocale::Laothian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Latin", (long) QLocale::Latin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Latvian", (long) QLocale::Latvian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Lingala", (long) QLocale::Lingala))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Lithuanian", (long) QLocale::Lithuanian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Macedonian", (long) QLocale::Macedonian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Malagasy", (long) QLocale::Malagasy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Malay", (long) QLocale::Malay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Malayalam", (long) QLocale::Malayalam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Maltese", (long) QLocale::Maltese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Maori", (long) QLocale::Maori))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Marathi", (long) QLocale::Marathi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Moldavian", (long) QLocale::Moldavian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Mongolian", (long) QLocale::Mongolian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NauruLanguage", (long) QLocale::NauruLanguage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Nepali", (long) QLocale::Nepali))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Norwegian", (long) QLocale::Norwegian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Occitan", (long) QLocale::Occitan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Oriya", (long) QLocale::Oriya))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Pashto", (long) QLocale::Pashto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Persian", (long) QLocale::Persian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Polish", (long) QLocale::Polish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Portuguese", (long) QLocale::Portuguese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Punjabi", (long) QLocale::Punjabi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Quechua", (long) QLocale::Quechua))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "RhaetoRomance", (long) QLocale::RhaetoRomance))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Romanian", (long) QLocale::Romanian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Russian", (long) QLocale::Russian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Samoan", (long) QLocale::Samoan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sangho", (long) QLocale::Sangho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sanskrit", (long) QLocale::Sanskrit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Serbian", (long) QLocale::Serbian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "SerboCroatian", (long) QLocale::SerboCroatian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sesotho", (long) QLocale::Sesotho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Setswana", (long) QLocale::Setswana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Shona", (long) QLocale::Shona))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sindhi", (long) QLocale::Sindhi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Singhalese", (long) QLocale::Singhalese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Siswati", (long) QLocale::Siswati))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Slovak", (long) QLocale::Slovak))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Slovenian", (long) QLocale::Slovenian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Somali", (long) QLocale::Somali))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Spanish", (long) QLocale::Spanish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sundanese", (long) QLocale::Sundanese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Swahili", (long) QLocale::Swahili))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Swedish", (long) QLocale::Swedish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tagalog", (long) QLocale::Tagalog))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tajik", (long) QLocale::Tajik))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tamil", (long) QLocale::Tamil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tatar", (long) QLocale::Tatar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Telugu", (long) QLocale::Telugu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Thai", (long) QLocale::Thai))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tibetan", (long) QLocale::Tibetan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tigrinya", (long) QLocale::Tigrinya))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "TongaLanguage", (long) QLocale::TongaLanguage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tsonga", (long) QLocale::Tsonga))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Turkish", (long) QLocale::Turkish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Turkmen", (long) QLocale::Turkmen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Twi", (long) QLocale::Twi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Uigur", (long) QLocale::Uigur))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Ukrainian", (long) QLocale::Ukrainian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Urdu", (long) QLocale::Urdu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Uzbek", (long) QLocale::Uzbek))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Vietnamese", (long) QLocale::Vietnamese))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Volapuk", (long) QLocale::Volapuk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Welsh", (long) QLocale::Welsh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Wolof", (long) QLocale::Wolof))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Xhosa", (long) QLocale::Xhosa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Yiddish", (long) QLocale::Yiddish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Yoruba", (long) QLocale::Yoruba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Zhuang", (long) QLocale::Zhuang))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Zulu", (long) QLocale::Zulu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Nynorsk", (long) QLocale::Nynorsk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bosnian", (long) QLocale::Bosnian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Divehi", (long) QLocale::Divehi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Manx", (long) QLocale::Manx))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Cornish", (long) QLocale::Cornish))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Akan", (long) QLocale::Akan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Konkani", (long) QLocale::Konkani))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Ga", (long) QLocale::Ga))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Igbo", (long) QLocale::Igbo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kamba", (long) QLocale::Kamba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Syriac", (long) QLocale::Syriac))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Blin", (long) QLocale::Blin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Geez", (long) QLocale::Geez))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Koro", (long) QLocale::Koro))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sidamo", (long) QLocale::Sidamo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Atsam", (long) QLocale::Atsam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tigre", (long) QLocale::Tigre))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Jju", (long) QLocale::Jju))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Friulian", (long) QLocale::Friulian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Venda", (long) QLocale::Venda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Ewe", (long) QLocale::Ewe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Walamo", (long) QLocale::Walamo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Hawaiian", (long) QLocale::Hawaiian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tyap", (long) QLocale::Tyap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Chewa", (long) QLocale::Chewa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Filipino", (long) QLocale::Filipino))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "SwissGerman", (long) QLocale::SwissGerman))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "SichuanYi", (long) QLocale::SichuanYi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kpelle", (long) QLocale::Kpelle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "LowGerman", (long) QLocale::LowGerman))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "SouthNdebele", (long) QLocale::SouthNdebele))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NorthernSotho", (long) QLocale::NorthernSotho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NorthernSami", (long) QLocale::NorthernSami))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Taroko", (long) QLocale::Taroko))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Gusii", (long) QLocale::Gusii))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Taita", (long) QLocale::Taita))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Fulah", (long) QLocale::Fulah))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kikuyu", (long) QLocale::Kikuyu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Samburu", (long) QLocale::Samburu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sena", (long) QLocale::Sena))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NorthNdebele", (long) QLocale::NorthNdebele))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Rombo", (long) QLocale::Rombo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tachelhit", (long) QLocale::Tachelhit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kabyle", (long) QLocale::Kabyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Nyankole", (long) QLocale::Nyankole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bena", (long) QLocale::Bena))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Vunjo", (long) QLocale::Vunjo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bambara", (long) QLocale::Bambara))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Embu", (long) QLocale::Embu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Cherokee", (long) QLocale::Cherokee))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Morisyen", (long) QLocale::Morisyen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Makonde", (long) QLocale::Makonde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Langi", (long) QLocale::Langi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Ganda", (long) QLocale::Ganda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bemba", (long) QLocale::Bemba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kabuverdianu", (long) QLocale::Kabuverdianu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Meru", (long) QLocale::Meru))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kalenjin", (long) QLocale::Kalenjin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Nama", (long) QLocale::Nama))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Machame", (long) QLocale::Machame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Colognian", (long) QLocale::Colognian))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Masai", (long) QLocale::Masai))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Soga", (long) QLocale::Soga))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Luyia", (long) QLocale::Luyia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Asu", (long) QLocale::Asu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Teso", (long) QLocale::Teso))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Saho", (long) QLocale::Saho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "KoyraChiini", (long) QLocale::KoyraChiini))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Rwa", (long) QLocale::Rwa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Luo", (long) QLocale::Luo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Chiga", (long) QLocale::Chiga))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "CentralMoroccoTamazight", (long) QLocale::CentralMoroccoTamazight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "KoyraboroSenni", (long) QLocale::KoyraboroSenni))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Shambala", (long) QLocale::Shambala))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bodo", (long) QLocale::Bodo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Aghem", (long) QLocale::Aghem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Basaa", (long) QLocale::Basaa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Zarma", (long) QLocale::Zarma))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Duala", (long) QLocale::Duala))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "JolaFonyi", (long) QLocale::JolaFonyi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Ewondo", (long) QLocale::Ewondo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Bafia", (long) QLocale::Bafia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "LubaKatanga", (long) QLocale::LubaKatanga))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "MakhuwaMeetto", (long) QLocale::MakhuwaMeetto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Mundang", (long) QLocale::Mundang))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kwasio", (long) QLocale::Kwasio))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Nuer", (long) QLocale::Nuer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sakha", (long) QLocale::Sakha))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Sangu", (long) QLocale::Sangu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "CongoSwahili", (long) QLocale::CongoSwahili))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Tasawaq", (long) QLocale::Tasawaq))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Vai", (long) QLocale::Vai))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Walser", (long) QLocale::Walser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Yangben", (long) QLocale::Yangben))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NorwegianBokmal", (long) QLocale::NorwegianBokmal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "NorwegianNynorsk", (long) QLocale::NorwegianNynorsk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "Kurundi", (long) QLocale::Kurundi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
        &Sbk_QLocale_Type, "LastLanguage", (long) QLocale::LastLanguage))
        return ;
    // Register converter for enum 'QLocale::Language'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX],
            QLocale_Language_CppToPython_QLocale_Language);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_Language_PythonToCpp_QLocale_Language,
            is_QLocale_Language_PythonToCpp_QLocale_Language_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_LANGUAGE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::Language");
        Shiboken::Conversions::registerConverterName(converter, "Language");
    }
    // End of 'Language' enum.

    // Initialization of enum 'Script'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "Script",
        "PySide.QtCore.QLocale.Script",
        "QLocale::Script");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "AnyScript", (long) QLocale::AnyScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "ArabicScript", (long) QLocale::ArabicScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "CyrillicScript", (long) QLocale::CyrillicScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "DeseretScript", (long) QLocale::DeseretScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "GurmukhiScript", (long) QLocale::GurmukhiScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "SimplifiedHanScript", (long) QLocale::SimplifiedHanScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "TraditionalHanScript", (long) QLocale::TraditionalHanScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "LatinScript", (long) QLocale::LatinScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "MongolianScript", (long) QLocale::MongolianScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "TifinaghScript", (long) QLocale::TifinaghScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "SimplifiedChineseScript", (long) QLocale::SimplifiedChineseScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "TraditionalChineseScript", (long) QLocale::TraditionalChineseScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
        &Sbk_QLocale_Type, "LastScript", (long) QLocale::LastScript))
        return ;
    // Register converter for enum 'QLocale::Script'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX],
            QLocale_Script_CppToPython_QLocale_Script);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_Script_PythonToCpp_QLocale_Script,
            is_QLocale_Script_PythonToCpp_QLocale_Script_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_SCRIPT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::Script");
        Shiboken::Conversions::registerConverterName(converter, "Script");
    }
    // End of 'Script' enum.

    // Initialization of enum 'Country'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "Country",
        "PySide.QtCore.QLocale.Country",
        "QLocale::Country");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "AnyCountry", (long) QLocale::AnyCountry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Afghanistan", (long) QLocale::Afghanistan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Albania", (long) QLocale::Albania))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Algeria", (long) QLocale::Algeria))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "AmericanSamoa", (long) QLocale::AmericanSamoa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Andorra", (long) QLocale::Andorra))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Angola", (long) QLocale::Angola))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Anguilla", (long) QLocale::Anguilla))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Antarctica", (long) QLocale::Antarctica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "AntiguaAndBarbuda", (long) QLocale::AntiguaAndBarbuda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Argentina", (long) QLocale::Argentina))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Armenia", (long) QLocale::Armenia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Aruba", (long) QLocale::Aruba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Australia", (long) QLocale::Australia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Austria", (long) QLocale::Austria))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Azerbaijan", (long) QLocale::Azerbaijan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bahamas", (long) QLocale::Bahamas))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bahrain", (long) QLocale::Bahrain))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bangladesh", (long) QLocale::Bangladesh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Barbados", (long) QLocale::Barbados))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Belarus", (long) QLocale::Belarus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Belgium", (long) QLocale::Belgium))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Belize", (long) QLocale::Belize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Benin", (long) QLocale::Benin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bermuda", (long) QLocale::Bermuda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bhutan", (long) QLocale::Bhutan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bolivia", (long) QLocale::Bolivia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BosniaAndHerzegowina", (long) QLocale::BosniaAndHerzegowina))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Botswana", (long) QLocale::Botswana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BouvetIsland", (long) QLocale::BouvetIsland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Brazil", (long) QLocale::Brazil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BritishIndianOceanTerritory", (long) QLocale::BritishIndianOceanTerritory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BruneiDarussalam", (long) QLocale::BruneiDarussalam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Bulgaria", (long) QLocale::Bulgaria))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BurkinaFaso", (long) QLocale::BurkinaFaso))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Burundi", (long) QLocale::Burundi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Cambodia", (long) QLocale::Cambodia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Cameroon", (long) QLocale::Cameroon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Canada", (long) QLocale::Canada))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CapeVerde", (long) QLocale::CapeVerde))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CaymanIslands", (long) QLocale::CaymanIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CentralAfricanRepublic", (long) QLocale::CentralAfricanRepublic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Chad", (long) QLocale::Chad))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Chile", (long) QLocale::Chile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "China", (long) QLocale::China))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "ChristmasIsland", (long) QLocale::ChristmasIsland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CocosIslands", (long) QLocale::CocosIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Colombia", (long) QLocale::Colombia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Comoros", (long) QLocale::Comoros))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "DemocraticRepublicOfCongo", (long) QLocale::DemocraticRepublicOfCongo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "PeoplesRepublicOfCongo", (long) QLocale::PeoplesRepublicOfCongo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CookIslands", (long) QLocale::CookIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CostaRica", (long) QLocale::CostaRica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "IvoryCoast", (long) QLocale::IvoryCoast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Croatia", (long) QLocale::Croatia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Cuba", (long) QLocale::Cuba))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Cyprus", (long) QLocale::Cyprus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "CzechRepublic", (long) QLocale::CzechRepublic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Denmark", (long) QLocale::Denmark))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Djibouti", (long) QLocale::Djibouti))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Dominica", (long) QLocale::Dominica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "DominicanRepublic", (long) QLocale::DominicanRepublic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "EastTimor", (long) QLocale::EastTimor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Ecuador", (long) QLocale::Ecuador))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Egypt", (long) QLocale::Egypt))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "ElSalvador", (long) QLocale::ElSalvador))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "EquatorialGuinea", (long) QLocale::EquatorialGuinea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Eritrea", (long) QLocale::Eritrea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Estonia", (long) QLocale::Estonia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Ethiopia", (long) QLocale::Ethiopia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FalklandIslands", (long) QLocale::FalklandIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FaroeIslands", (long) QLocale::FaroeIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FijiCountry", (long) QLocale::FijiCountry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Finland", (long) QLocale::Finland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "France", (long) QLocale::France))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "MetropolitanFrance", (long) QLocale::MetropolitanFrance))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FrenchGuiana", (long) QLocale::FrenchGuiana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FrenchPolynesia", (long) QLocale::FrenchPolynesia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "FrenchSouthernTerritories", (long) QLocale::FrenchSouthernTerritories))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Gabon", (long) QLocale::Gabon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Gambia", (long) QLocale::Gambia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Georgia", (long) QLocale::Georgia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Germany", (long) QLocale::Germany))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Ghana", (long) QLocale::Ghana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Gibraltar", (long) QLocale::Gibraltar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Greece", (long) QLocale::Greece))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Greenland", (long) QLocale::Greenland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Grenada", (long) QLocale::Grenada))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Guadeloupe", (long) QLocale::Guadeloupe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Guam", (long) QLocale::Guam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Guatemala", (long) QLocale::Guatemala))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Guinea", (long) QLocale::Guinea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "GuineaBissau", (long) QLocale::GuineaBissau))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Guyana", (long) QLocale::Guyana))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Haiti", (long) QLocale::Haiti))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "HeardAndMcDonaldIslands", (long) QLocale::HeardAndMcDonaldIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Honduras", (long) QLocale::Honduras))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "HongKong", (long) QLocale::HongKong))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Hungary", (long) QLocale::Hungary))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Iceland", (long) QLocale::Iceland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "India", (long) QLocale::India))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Indonesia", (long) QLocale::Indonesia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Iran", (long) QLocale::Iran))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Iraq", (long) QLocale::Iraq))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Ireland", (long) QLocale::Ireland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Israel", (long) QLocale::Israel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Italy", (long) QLocale::Italy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Jamaica", (long) QLocale::Jamaica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Japan", (long) QLocale::Japan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Jordan", (long) QLocale::Jordan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Kazakhstan", (long) QLocale::Kazakhstan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Kenya", (long) QLocale::Kenya))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Kiribati", (long) QLocale::Kiribati))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "DemocraticRepublicOfKorea", (long) QLocale::DemocraticRepublicOfKorea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "RepublicOfKorea", (long) QLocale::RepublicOfKorea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Kuwait", (long) QLocale::Kuwait))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Kyrgyzstan", (long) QLocale::Kyrgyzstan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Lao", (long) QLocale::Lao))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Latvia", (long) QLocale::Latvia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Lebanon", (long) QLocale::Lebanon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Lesotho", (long) QLocale::Lesotho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Liberia", (long) QLocale::Liberia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "LibyanArabJamahiriya", (long) QLocale::LibyanArabJamahiriya))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Liechtenstein", (long) QLocale::Liechtenstein))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Lithuania", (long) QLocale::Lithuania))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Luxembourg", (long) QLocale::Luxembourg))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Macau", (long) QLocale::Macau))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Macedonia", (long) QLocale::Macedonia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Madagascar", (long) QLocale::Madagascar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Malawi", (long) QLocale::Malawi))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Malaysia", (long) QLocale::Malaysia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Maldives", (long) QLocale::Maldives))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mali", (long) QLocale::Mali))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Malta", (long) QLocale::Malta))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "MarshallIslands", (long) QLocale::MarshallIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Martinique", (long) QLocale::Martinique))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mauritania", (long) QLocale::Mauritania))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mauritius", (long) QLocale::Mauritius))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mayotte", (long) QLocale::Mayotte))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mexico", (long) QLocale::Mexico))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Micronesia", (long) QLocale::Micronesia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Moldova", (long) QLocale::Moldova))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Monaco", (long) QLocale::Monaco))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mongolia", (long) QLocale::Mongolia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Montserrat", (long) QLocale::Montserrat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Morocco", (long) QLocale::Morocco))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Mozambique", (long) QLocale::Mozambique))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Myanmar", (long) QLocale::Myanmar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Namibia", (long) QLocale::Namibia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NauruCountry", (long) QLocale::NauruCountry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Nepal", (long) QLocale::Nepal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Netherlands", (long) QLocale::Netherlands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NetherlandsAntilles", (long) QLocale::NetherlandsAntilles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NewCaledonia", (long) QLocale::NewCaledonia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NewZealand", (long) QLocale::NewZealand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Nicaragua", (long) QLocale::Nicaragua))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Niger", (long) QLocale::Niger))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Nigeria", (long) QLocale::Nigeria))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Niue", (long) QLocale::Niue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NorfolkIsland", (long) QLocale::NorfolkIsland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "NorthernMarianaIslands", (long) QLocale::NorthernMarianaIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Norway", (long) QLocale::Norway))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Oman", (long) QLocale::Oman))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Pakistan", (long) QLocale::Pakistan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Palau", (long) QLocale::Palau))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "PalestinianTerritory", (long) QLocale::PalestinianTerritory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Panama", (long) QLocale::Panama))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "PapuaNewGuinea", (long) QLocale::PapuaNewGuinea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Paraguay", (long) QLocale::Paraguay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Peru", (long) QLocale::Peru))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Philippines", (long) QLocale::Philippines))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Pitcairn", (long) QLocale::Pitcairn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Poland", (long) QLocale::Poland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Portugal", (long) QLocale::Portugal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "PuertoRico", (long) QLocale::PuertoRico))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Qatar", (long) QLocale::Qatar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Reunion", (long) QLocale::Reunion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Romania", (long) QLocale::Romania))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "RussianFederation", (long) QLocale::RussianFederation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Rwanda", (long) QLocale::Rwanda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SaintKittsAndNevis", (long) QLocale::SaintKittsAndNevis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "StLucia", (long) QLocale::StLucia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "StVincentAndTheGrenadines", (long) QLocale::StVincentAndTheGrenadines))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Samoa", (long) QLocale::Samoa))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SanMarino", (long) QLocale::SanMarino))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SaoTomeAndPrincipe", (long) QLocale::SaoTomeAndPrincipe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SaudiArabia", (long) QLocale::SaudiArabia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Senegal", (long) QLocale::Senegal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Seychelles", (long) QLocale::Seychelles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SierraLeone", (long) QLocale::SierraLeone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Singapore", (long) QLocale::Singapore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Slovakia", (long) QLocale::Slovakia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Slovenia", (long) QLocale::Slovenia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SolomonIslands", (long) QLocale::SolomonIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Somalia", (long) QLocale::Somalia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SouthAfrica", (long) QLocale::SouthAfrica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SouthGeorgiaAndTheSouthSandwichIslands", (long) QLocale::SouthGeorgiaAndTheSouthSandwichIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Spain", (long) QLocale::Spain))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SriLanka", (long) QLocale::SriLanka))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "StHelena", (long) QLocale::StHelena))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "StPierreAndMiquelon", (long) QLocale::StPierreAndMiquelon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Sudan", (long) QLocale::Sudan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Suriname", (long) QLocale::Suriname))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SvalbardAndJanMayenIslands", (long) QLocale::SvalbardAndJanMayenIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Swaziland", (long) QLocale::Swaziland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Sweden", (long) QLocale::Sweden))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Switzerland", (long) QLocale::Switzerland))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SyrianArabRepublic", (long) QLocale::SyrianArabRepublic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Taiwan", (long) QLocale::Taiwan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Tajikistan", (long) QLocale::Tajikistan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Tanzania", (long) QLocale::Tanzania))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Thailand", (long) QLocale::Thailand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Togo", (long) QLocale::Togo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Tokelau", (long) QLocale::Tokelau))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "TongaCountry", (long) QLocale::TongaCountry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "TrinidadAndTobago", (long) QLocale::TrinidadAndTobago))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Tunisia", (long) QLocale::Tunisia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Turkey", (long) QLocale::Turkey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Turkmenistan", (long) QLocale::Turkmenistan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "TurksAndCaicosIslands", (long) QLocale::TurksAndCaicosIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Tuvalu", (long) QLocale::Tuvalu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Uganda", (long) QLocale::Uganda))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Ukraine", (long) QLocale::Ukraine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "UnitedArabEmirates", (long) QLocale::UnitedArabEmirates))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "UnitedKingdom", (long) QLocale::UnitedKingdom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "UnitedStates", (long) QLocale::UnitedStates))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "UnitedStatesMinorOutlyingIslands", (long) QLocale::UnitedStatesMinorOutlyingIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Uruguay", (long) QLocale::Uruguay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Uzbekistan", (long) QLocale::Uzbekistan))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Vanuatu", (long) QLocale::Vanuatu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "VaticanCityState", (long) QLocale::VaticanCityState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Venezuela", (long) QLocale::Venezuela))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "VietNam", (long) QLocale::VietNam))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "BritishVirginIslands", (long) QLocale::BritishVirginIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "USVirginIslands", (long) QLocale::USVirginIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "WallisAndFutunaIslands", (long) QLocale::WallisAndFutunaIslands))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "WesternSahara", (long) QLocale::WesternSahara))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Yemen", (long) QLocale::Yemen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Yugoslavia", (long) QLocale::Yugoslavia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Zambia", (long) QLocale::Zambia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Zimbabwe", (long) QLocale::Zimbabwe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SerbiaAndMontenegro", (long) QLocale::SerbiaAndMontenegro))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Montenegro", (long) QLocale::Montenegro))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "Serbia", (long) QLocale::Serbia))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SaintBarthelemy", (long) QLocale::SaintBarthelemy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "SaintMartin", (long) QLocale::SaintMartin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "LatinAmericaAndTheCaribbean", (long) QLocale::LatinAmericaAndTheCaribbean))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
        &Sbk_QLocale_Type, "LastCountry", (long) QLocale::LastCountry))
        return ;
    // Register converter for enum 'QLocale::Country'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX],
            QLocale_Country_CppToPython_QLocale_Country);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_Country_PythonToCpp_QLocale_Country,
            is_QLocale_Country_PythonToCpp_QLocale_Country_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_COUNTRY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::Country");
        Shiboken::Conversions::registerConverterName(converter, "Country");
    }
    // End of 'Country' enum.

    // Initialization of enum 'MeasurementSystem'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "MeasurementSystem",
        "PySide.QtCore.QLocale.MeasurementSystem",
        "QLocale::MeasurementSystem");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX],
        &Sbk_QLocale_Type, "MetricSystem", (long) QLocale::MetricSystem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX],
        &Sbk_QLocale_Type, "ImperialSystem", (long) QLocale::ImperialSystem))
        return ;
    // Register converter for enum 'QLocale::MeasurementSystem'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX],
            QLocale_MeasurementSystem_CppToPython_QLocale_MeasurementSystem);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_MeasurementSystem_PythonToCpp_QLocale_MeasurementSystem,
            is_QLocale_MeasurementSystem_PythonToCpp_QLocale_MeasurementSystem_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_MEASUREMENTSYSTEM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::MeasurementSystem");
        Shiboken::Conversions::registerConverterName(converter, "MeasurementSystem");
    }
    // End of 'MeasurementSystem' enum.

    // Initialization of enum 'FormatType'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "FormatType",
        "PySide.QtCore.QLocale.FormatType",
        "QLocale::FormatType");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX],
        &Sbk_QLocale_Type, "LongFormat", (long) QLocale::LongFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX],
        &Sbk_QLocale_Type, "ShortFormat", (long) QLocale::ShortFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX],
        &Sbk_QLocale_Type, "NarrowFormat", (long) QLocale::NarrowFormat))
        return ;
    // Register converter for enum 'QLocale::FormatType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX],
            QLocale_FormatType_CppToPython_QLocale_FormatType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_FormatType_PythonToCpp_QLocale_FormatType,
            is_QLocale_FormatType_PythonToCpp_QLocale_FormatType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_FORMATTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::FormatType");
        Shiboken::Conversions::registerConverterName(converter, "FormatType");
    }
    // End of 'FormatType' enum.

    // Initialization of enum 'NumberOption'.
    SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX] = PySide::QFlags::create("NumberOptions", &SbkPySide_QtCore_QLocale_NumberOption_as_number);
    SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "NumberOption",
        "PySide.QtCore.QLocale.NumberOption",
        "QLocale::NumberOption",
        SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX]);
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX],
        &Sbk_QLocale_Type, "OmitGroupSeparator", (long) QLocale::OmitGroupSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX],
        &Sbk_QLocale_Type, "RejectGroupSeparator", (long) QLocale::RejectGroupSeparator))
        return ;
    // Register converter for enum 'QLocale::NumberOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX],
            QLocale_NumberOption_CppToPython_QLocale_NumberOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_NumberOption_PythonToCpp_QLocale_NumberOption,
            is_QLocale_NumberOption_PythonToCpp_QLocale_NumberOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_NUMBEROPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::NumberOption");
        Shiboken::Conversions::registerConverterName(converter, "NumberOption");
    }
    // Register converter for flag 'QFlags<QLocale::NumberOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX],
            QFlags_QLocale_NumberOption__CppToPython_QFlags_QLocale_NumberOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_NumberOption_PythonToCpp_QFlags_QLocale_NumberOption_,
            is_QLocale_NumberOption_PythonToCpp_QFlags_QLocale_NumberOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QLocale_NumberOption__PythonToCpp_QFlags_QLocale_NumberOption_,
            is_QFlags_QLocale_NumberOption__PythonToCpp_QFlags_QLocale_NumberOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QLocale_NumberOption_,
            is_number_PythonToCpp_QFlags_QLocale_NumberOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QFLAGS_QLOCALE_NUMBEROPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QLocale::NumberOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<NumberOption>");
    }
    // End of 'NumberOption' enum/flags.

    // Initialization of enum 'CurrencySymbolFormat'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "CurrencySymbolFormat",
        "PySide.QtCore.QLocale.CurrencySymbolFormat",
        "QLocale::CurrencySymbolFormat");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX],
        &Sbk_QLocale_Type, "CurrencyIsoCode", (long) QLocale::CurrencyIsoCode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX],
        &Sbk_QLocale_Type, "CurrencySymbol", (long) QLocale::CurrencySymbol))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX],
        &Sbk_QLocale_Type, "CurrencyDisplayName", (long) QLocale::CurrencyDisplayName))
        return ;
    // Register converter for enum 'QLocale::CurrencySymbolFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX],
            QLocale_CurrencySymbolFormat_CppToPython_QLocale_CurrencySymbolFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_CurrencySymbolFormat_PythonToCpp_QLocale_CurrencySymbolFormat,
            is_QLocale_CurrencySymbolFormat_PythonToCpp_QLocale_CurrencySymbolFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_CURRENCYSYMBOLFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::CurrencySymbolFormat");
        Shiboken::Conversions::registerConverterName(converter, "CurrencySymbolFormat");
    }
    // End of 'CurrencySymbolFormat' enum.

    // Initialization of enum 'QuotationStyle'.
    SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLocale_Type,
        "QuotationStyle",
        "PySide.QtCore.QLocale.QuotationStyle",
        "QLocale::QuotationStyle");
    if (!SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX],
        &Sbk_QLocale_Type, "StandardQuotation", (long) QLocale::StandardQuotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX],
        &Sbk_QLocale_Type, "AlternateQuotation", (long) QLocale::AlternateQuotation))
        return ;
    // Register converter for enum 'QLocale::QuotationStyle'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX],
            QLocale_QuotationStyle_CppToPython_QLocale_QuotationStyle);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLocale_QuotationStyle_PythonToCpp_QLocale_QuotationStyle,
            is_QLocale_QuotationStyle_PythonToCpp_QLocale_QuotationStyle_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QLOCALE_QUOTATIONSTYLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLocale::QuotationStyle");
        Shiboken::Conversions::registerConverterName(converter, "QuotationStyle");
    }
    // End of 'QuotationStyle' enum.


    qRegisterMetaType< ::QLocale >("QLocale");
    qRegisterMetaType< ::QLocale::Language >("QLocale::Language");
    qRegisterMetaType< ::QLocale::Script >("QLocale::Script");
    qRegisterMetaType< ::QLocale::Country >("QLocale::Country");
    qRegisterMetaType< ::QLocale::MeasurementSystem >("QLocale::MeasurementSystem");
    qRegisterMetaType< ::QLocale::FormatType >("QLocale::FormatType");
    qRegisterMetaType< ::QLocale::NumberOption >("QLocale::NumberOption");
    qRegisterMetaType< ::QLocale::NumberOptions >("QLocale::NumberOptions");
    qRegisterMetaType< ::QLocale::CurrencySymbolFormat >("QLocale::CurrencySymbolFormat");
    qRegisterMetaType< ::QLocale::QuotationStyle >("QLocale::QuotationStyle");
}
