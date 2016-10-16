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

#include "qregexp_wrapper.h"

// Extra includes
#include <QStringList>
#include <qregexp.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QRegExp_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QRegExp >()))
        return -1;

    ::QRegExp* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QRegExp", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QRegExp()
    // 1: QRegExp(QRegExp)
    // 2: QRegExp(QString,Qt::CaseSensitivity,QRegExp::PatternSyntax)
    if (numArgs == 0) {
        overloadId = 0; // QRegExp()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QRegExp(QString,Qt::CaseSensitivity,QRegExp::PatternSyntax)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // QRegExp(QString,Qt::CaseSensitivity,QRegExp::PatternSyntax)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2])))) {
                overloadId = 2; // QRegExp(QString,Qt::CaseSensitivity,QRegExp::PatternSyntax)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArgs[0])))) {
        overloadId = 1; // QRegExp(QRegExp)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExp_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QRegExp()
        {

            if (!PyErr_Occurred()) {
                // QRegExp()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRegExp();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QRegExp(const QRegExp & rx)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QRegExp(QRegExp)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRegExp(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QRegExp(const QString & pattern, Qt::CaseSensitivity cs, QRegExp::PatternSyntax syntax)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "cs");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp(): got multiple values for keyword argument 'cs'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), (pyArgs[1]))))
                        goto Sbk_QRegExp_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "syntax");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp(): got multiple values for keyword argument 'syntax'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArgs[2]))))
                        goto Sbk_QRegExp_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::CaseSensitivity cppArg1 = Qt::CaseSensitive;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QRegExp::PatternSyntax cppArg2 = QRegExp::RegExp;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QRegExp(QString,Qt::CaseSensitivity,QRegExp::PatternSyntax)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QRegExp(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QRegExp >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QRegExp_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QRegExp_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QRegExp", "unicode, PySide.QtCore.Qt.CaseSensitivity = Qt.CaseSensitive, PySide.QtCore.QRegExp.PatternSyntax = RegExp", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp", overloads);
        return -1;
}

static PyObject* Sbk_QRegExpFunc___reduce__(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(sii))", PyObject_Type(self), qPrintable(cppSelf->pattern()), (int)cppSelf->caseSensitivity(), (int)cppSelf->patternSyntax());
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

static PyObject* Sbk_QRegExpFunc___repr__(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s('%s', %i, %i)", ((PyObject*)self)->ob_type->tp_name, qPrintable(cppSelf->pattern()), (int)cppSelf->caseSensitivity(), (int)cppSelf->patternSyntax());
            pyResult = Shiboken::String::fromCString(qPrintable(format));
            // TEMPLATE - repr_code - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QRegExpFunc_cap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.cap(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:cap", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: cap(int)
    if (numArgs == 0) {
        overloadId = 0; // cap(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // cap(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_cap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "nth");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.cap(): got multiple values for keyword argument 'nth'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QRegExpFunc_cap_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // cap(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->cap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_cap_TypeError:
        const char* overloads[] = {"int = 0", "int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp.cap", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_captureCount(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // captureCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QRegExp*>(cppSelf)->captureCount();
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

static PyObject* Sbk_QRegExpFunc_capturedTexts(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capturedTexts()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = cppSelf->capturedTexts();
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

static PyObject* Sbk_QRegExpFunc_caseSensitivity(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // caseSensitivity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CaseSensitivity cppResult = const_cast<const ::QRegExp*>(cppSelf)->caseSensitivity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QRegExpFunc_errorString(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorString()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = cppSelf->errorString();
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

static PyObject* Sbk_QRegExpFunc_escape(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: escape(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // escape(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_escape_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // escape(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QRegExp::escape(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_escape_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.escape", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_exactMatch(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: exactMatch(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // exactMatch(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_exactMatch_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // exactMatch(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QRegExp*>(cppSelf)->exactMatch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_exactMatch_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.exactMatch", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_indexIn(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.indexIn(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.indexIn(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:indexIn", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: indexIn(QString,int,QRegExp::CaretMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // indexIn(QString,int,QRegExp::CaretMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // indexIn(QString,int,QRegExp::CaretMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // indexIn(QString,int,QRegExp::CaretMode)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_indexIn_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "offset");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.indexIn(): got multiple values for keyword argument 'offset'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QRegExpFunc_indexIn_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caretMode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.indexIn(): got multiple values for keyword argument 'caretMode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QRegExpFunc_indexIn_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QRegExp::CaretMode cppArg2 = QRegExp::CaretAtZero;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // indexIn(QString,int,QRegExp::CaretMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QRegExp*>(cppSelf)->indexIn(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_indexIn_TypeError:
        const char* overloads[] = {"unicode, int = 0, PySide.QtCore.QRegExp.CaretMode = CaretAtZero", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp.indexIn", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_isEmpty(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QRegExp*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QRegExpFunc_isMinimal(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMinimal()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QRegExp*>(cppSelf)->isMinimal();
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

static PyObject* Sbk_QRegExpFunc_isValid(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QRegExp*>(cppSelf)->isValid();
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

static PyObject* Sbk_QRegExpFunc_lastIndexIn(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.lastIndexIn(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.lastIndexIn(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:lastIndexIn", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: lastIndexIn(QString,int,QRegExp::CaretMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // lastIndexIn(QString,int,QRegExp::CaretMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // lastIndexIn(QString,int,QRegExp::CaretMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // lastIndexIn(QString,int,QRegExp::CaretMode)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_lastIndexIn_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "offset");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.lastIndexIn(): got multiple values for keyword argument 'offset'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QRegExpFunc_lastIndexIn_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caretMode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.lastIndexIn(): got multiple values for keyword argument 'caretMode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QRegExpFunc_lastIndexIn_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QRegExp::CaretMode cppArg2 = QRegExp::CaretAtZero;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // lastIndexIn(QString,int,QRegExp::CaretMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QRegExp*>(cppSelf)->lastIndexIn(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_lastIndexIn_TypeError:
        const char* overloads[] = {"unicode, int = -1, PySide.QtCore.QRegExp.CaretMode = CaretAtZero", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp.lastIndexIn", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_matchedLength(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // matchedLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QRegExp*>(cppSelf)->matchedLength();
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

static PyObject* Sbk_QRegExpFunc_numCaptures(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numCaptures()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QRegExp*>(cppSelf)->numCaptures();
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

static PyObject* Sbk_QRegExpFunc_pattern(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pattern()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QRegExp*>(cppSelf)->pattern();
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

static PyObject* Sbk_QRegExpFunc_patternSyntax(PyObject* self)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // patternSyntax()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegExp::PatternSyntax cppResult = const_cast<const ::QRegExp*>(cppSelf)->patternSyntax();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QRegExpFunc_pos(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.pos(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:pos", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: pos(int)
    if (numArgs == 0) {
        overloadId = 0; // pos(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // pos(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_pos_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "nth");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QRegExp.pos(): got multiple values for keyword argument 'nth'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QRegExpFunc_pos_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // pos(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->pos(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_pos_TypeError:
        const char* overloads[] = {"int = 0", "int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp.pos", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_replace(PyObject* self, PyObject* args)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "replace", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: replace(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // replace(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_replace_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        SBK_UNUSED(cppArg0)
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        SBK_UNUSED(cppArg1)

        if (!PyErr_Occurred()) {
            // replace(QString,QString)
            // Begin code injection

            cppArg0.replace(*cppSelf, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg0);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QRegExpFunc_replace_TypeError:
        const char* overloads[] = {"unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QRegExp.replace", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_setCaseSensitivity(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCaseSensitivity(Qt::CaseSensitivity)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), (pyArg)))) {
        overloadId = 0; // setCaseSensitivity(Qt::CaseSensitivity)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_setCaseSensitivity_TypeError;

    // Call function/method
    {
        ::Qt::CaseSensitivity cppArg0 = ((::Qt::CaseSensitivity)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCaseSensitivity(Qt::CaseSensitivity)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCaseSensitivity(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRegExpFunc_setCaseSensitivity_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CaseSensitivity", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.setCaseSensitivity", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_setMinimal(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimal(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setMinimal(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_setMinimal_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMinimal(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimal(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRegExpFunc_setMinimal_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.setMinimal", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_setPattern(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPattern(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPattern(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_setPattern_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPattern(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPattern(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRegExpFunc_setPattern_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.setPattern", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_setPatternSyntax(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPatternSyntax(QRegExp::PatternSyntax)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]), (pyArg)))) {
        overloadId = 0; // setPatternSyntax(QRegExp::PatternSyntax)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_setPatternSyntax_TypeError;

    // Call function/method
    {
        ::QRegExp::PatternSyntax cppArg0 = ((::QRegExp::PatternSyntax)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPatternSyntax(QRegExp::PatternSyntax)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPatternSyntax(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRegExpFunc_setPatternSyntax_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRegExp.PatternSyntax", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.setPatternSyntax", overloads);
        return 0;
}

static PyObject* Sbk_QRegExpFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QRegExp* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QRegExp&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArg)))) {
        overloadId = 0; // swap(QRegExp&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QRegExpFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRegExp cppArg0_local = ::QRegExp();
        ::QRegExp* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QRegExp&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QRegExpFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRegExp", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QRegExp.swap", overloads);
        return 0;
}

static PyObject* Sbk_QRegExp___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QRegExp& cppSelf = *(((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QRegExp_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QRegExpFunc___reduce__, METH_NOARGS},
    {"cap", (PyCFunction)Sbk_QRegExpFunc_cap, METH_VARARGS|METH_KEYWORDS},
    {"captureCount", (PyCFunction)Sbk_QRegExpFunc_captureCount, METH_NOARGS},
    {"capturedTexts", (PyCFunction)Sbk_QRegExpFunc_capturedTexts, METH_NOARGS},
    {"caseSensitivity", (PyCFunction)Sbk_QRegExpFunc_caseSensitivity, METH_NOARGS},
    {"errorString", (PyCFunction)Sbk_QRegExpFunc_errorString, METH_NOARGS},
    {"escape", (PyCFunction)Sbk_QRegExpFunc_escape, METH_O|METH_STATIC},
    {"exactMatch", (PyCFunction)Sbk_QRegExpFunc_exactMatch, METH_O},
    {"indexIn", (PyCFunction)Sbk_QRegExpFunc_indexIn, METH_VARARGS|METH_KEYWORDS},
    {"isEmpty", (PyCFunction)Sbk_QRegExpFunc_isEmpty, METH_NOARGS},
    {"isMinimal", (PyCFunction)Sbk_QRegExpFunc_isMinimal, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QRegExpFunc_isValid, METH_NOARGS},
    {"lastIndexIn", (PyCFunction)Sbk_QRegExpFunc_lastIndexIn, METH_VARARGS|METH_KEYWORDS},
    {"matchedLength", (PyCFunction)Sbk_QRegExpFunc_matchedLength, METH_NOARGS},
    {"numCaptures", (PyCFunction)Sbk_QRegExpFunc_numCaptures, METH_NOARGS},
    {"pattern", (PyCFunction)Sbk_QRegExpFunc_pattern, METH_NOARGS},
    {"patternSyntax", (PyCFunction)Sbk_QRegExpFunc_patternSyntax, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QRegExpFunc_pos, METH_VARARGS|METH_KEYWORDS},
    {"replace", (PyCFunction)Sbk_QRegExpFunc_replace, METH_VARARGS},
    {"setCaseSensitivity", (PyCFunction)Sbk_QRegExpFunc_setCaseSensitivity, METH_O},
    {"setMinimal", (PyCFunction)Sbk_QRegExpFunc_setMinimal, METH_O},
    {"setPattern", (PyCFunction)Sbk_QRegExpFunc_setPattern, METH_O},
    {"setPatternSyntax", (PyCFunction)Sbk_QRegExpFunc_setPatternSyntax, METH_O},
    {"swap", (PyCFunction)Sbk_QRegExpFunc_swap, METH_O},

    {"__copy__", (PyCFunction)Sbk_QRegExp___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QRegExp_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QRegExp& cppSelf = *(((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArg)))) {
                // operator!=(const QRegExp & rx) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QRegExp cppArg0_local = ::QRegExp();
                ::QRegExp* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArg)))) {
                // operator==(const QRegExp & rx) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QRegExp cppArg0_local = ::QRegExp();
                ::QRegExp* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp))
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
            goto Sbk_QRegExp_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QRegExp_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QRegExp_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QRegExp_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QRegExp_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QRegExp",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QRegExpFunc___repr__,
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
    /*tp_traverse*/         Sbk_QRegExp_traverse,
    /*tp_clear*/            Sbk_QRegExp_clear,
    /*tp_richcompare*/      Sbk_QRegExp_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QRegExp_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QRegExp_Init,
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
static void QRegExp_PatternSyntax_PythonToCpp_QRegExp_PatternSyntax(PyObject* pyIn, void* cppOut) {
    *((::QRegExp::PatternSyntax*)cppOut) = (::QRegExp::PatternSyntax) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QRegExp_PatternSyntax_PythonToCpp_QRegExp_PatternSyntax_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX]))
        return QRegExp_PatternSyntax_PythonToCpp_QRegExp_PatternSyntax;
    return 0;
}
static PyObject* QRegExp_PatternSyntax_CppToPython_QRegExp_PatternSyntax(const void* cppIn) {
    int castCppIn = *((::QRegExp::PatternSyntax*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX], castCppIn);

}

static void QRegExp_CaretMode_PythonToCpp_QRegExp_CaretMode(PyObject* pyIn, void* cppOut) {
    *((::QRegExp::CaretMode*)cppOut) = (::QRegExp::CaretMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QRegExp_CaretMode_PythonToCpp_QRegExp_CaretMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX]))
        return QRegExp_CaretMode_PythonToCpp_QRegExp_CaretMode;
    return 0;
}
static PyObject* QRegExp_CaretMode_CppToPython_QRegExp_CaretMode(const void* cppIn) {
    int castCppIn = *((::QRegExp::CaretMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QRegExp_PythonToCpp_QRegExp_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QRegExp_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QRegExp_PythonToCpp_QRegExp_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QRegExp_Type))
        return QRegExp_PythonToCpp_QRegExp_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QRegExp_PTR_CppToPython_QRegExp(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QRegExp*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QRegExp_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QRegExp_COPY_CppToPython_QRegExp(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QRegExp_Type, new ::QRegExp(*((::QRegExp*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QRegExp_PythonToCpp_QRegExp_COPY(PyObject* pyIn, void* cppOut) {
    *((::QRegExp*)cppOut) = *((::QRegExp*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QRegExp_PythonToCpp_QRegExp_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QRegExp_Type))
        return QRegExp_PythonToCpp_QRegExp_COPY;
    return 0;
}

void init_QRegExp(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QRegExp_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QRegExp", "QRegExp",
        &Sbk_QRegExp_Type, &Shiboken::callCppDestructor< ::QRegExp >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QRegExp_Type,
        QRegExp_PythonToCpp_QRegExp_PTR,
        is_QRegExp_PythonToCpp_QRegExp_PTR_Convertible,
        QRegExp_PTR_CppToPython_QRegExp,
        QRegExp_COPY_CppToPython_QRegExp);

    Shiboken::Conversions::registerConverterName(converter, "QRegExp");
    Shiboken::Conversions::registerConverterName(converter, "QRegExp*");
    Shiboken::Conversions::registerConverterName(converter, "QRegExp&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QRegExp).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QRegExp_PythonToCpp_QRegExp_COPY,
        is_QRegExp_PythonToCpp_QRegExp_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'PatternSyntax'.
    SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QRegExp_Type,
        "PatternSyntax",
        "PySide.QtCore.QRegExp.PatternSyntax",
        "QRegExp::PatternSyntax");
    if (!SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "RegExp", (long) QRegExp::RegExp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "Wildcard", (long) QRegExp::Wildcard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "FixedString", (long) QRegExp::FixedString))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "RegExp2", (long) QRegExp::RegExp2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "WildcardUnix", (long) QRegExp::WildcardUnix))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
        &Sbk_QRegExp_Type, "W3CXmlSchema11", (long) QRegExp::W3CXmlSchema11))
        return ;
    // Register converter for enum 'QRegExp::PatternSyntax'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX],
            QRegExp_PatternSyntax_CppToPython_QRegExp_PatternSyntax);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QRegExp_PatternSyntax_PythonToCpp_QRegExp_PatternSyntax,
            is_QRegExp_PatternSyntax_PythonToCpp_QRegExp_PatternSyntax_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_PATTERNSYNTAX_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QRegExp::PatternSyntax");
        Shiboken::Conversions::registerConverterName(converter, "PatternSyntax");
    }
    // End of 'PatternSyntax' enum.

    // Initialization of enum 'CaretMode'.
    SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QRegExp_Type,
        "CaretMode",
        "PySide.QtCore.QRegExp.CaretMode",
        "QRegExp::CaretMode");
    if (!SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX],
        &Sbk_QRegExp_Type, "CaretAtZero", (long) QRegExp::CaretAtZero))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX],
        &Sbk_QRegExp_Type, "CaretAtOffset", (long) QRegExp::CaretAtOffset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX],
        &Sbk_QRegExp_Type, "CaretWontMatch", (long) QRegExp::CaretWontMatch))
        return ;
    // Register converter for enum 'QRegExp::CaretMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX],
            QRegExp_CaretMode_CppToPython_QRegExp_CaretMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QRegExp_CaretMode_PythonToCpp_QRegExp_CaretMode,
            is_QRegExp_CaretMode_PythonToCpp_QRegExp_CaretMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QREGEXP_CARETMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QRegExp::CaretMode");
        Shiboken::Conversions::registerConverterName(converter, "CaretMode");
    }
    // End of 'CaretMode' enum.


    qRegisterMetaType< ::QRegExp >("QRegExp");
    qRegisterMetaType< ::QRegExp::PatternSyntax >("QRegExp::PatternSyntax");
    qRegisterMetaType< ::QRegExp::CaretMode >("QRegExp::CaretMode");
}
