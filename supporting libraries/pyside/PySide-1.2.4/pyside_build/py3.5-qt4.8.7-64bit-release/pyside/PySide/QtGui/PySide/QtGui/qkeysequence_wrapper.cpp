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

#include "qkeysequence_wrapper.h"

// Extra includes
#include <QList>
#include <qdatastream.h>
#include <qkeysequence.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QKeySequence_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QKeySequence >()))
        return -1;

    ::QKeySequence* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:QKeySequence", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QKeySequence()
    // 1: QKeySequence(QKeySequence::StandardKey)
    // 2: QKeySequence(QKeySequence)
    // 3: QKeySequence(QString)
    // 4: QKeySequence(QString,QKeySequence::SequenceFormat)
    // 5: QKeySequence(int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // QKeySequence()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QKeySequence(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 4; // QKeySequence(QString,QKeySequence::SequenceFormat)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QKeySequence(QKeySequence::StandardKey)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // QKeySequence(int,int,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 5; // QKeySequence(int,int,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 5; // QKeySequence(int,int,int,int)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                    overloadId = 5; // QKeySequence(int,int,int,int)
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArgs[0])))) {
        overloadId = 2; // QKeySequence(QKeySequence)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequence_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QKeySequence()
        {

            if (!PyErr_Occurred()) {
                // QKeySequence()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QKeySequence(QKeySequence::StandardKey key)
        {
            ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QKeySequence(QKeySequence::StandardKey)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QKeySequence(const QKeySequence & ks)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QKeySequence cppArg0_local = ::QKeySequence();
            ::QKeySequence* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QKeySequence(QKeySequence)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QKeySequence(const QString & key)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QKeySequence(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QKeySequence(const QString & key, QKeySequence::SequenceFormat format)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QKeySequence::SequenceFormat cppArg1 = ((::QKeySequence::SequenceFormat)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QKeySequence(QString,QKeySequence::SequenceFormat)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QKeySequence(int k1, int k2, int k3, int k4)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "k2");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence(): got multiple values for keyword argument 'k2'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QKeySequence_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "k3");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence(): got multiple values for keyword argument 'k3'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QKeySequence_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "k4");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence(): got multiple values for keyword argument 'k4'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QKeySequence_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QKeySequence(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QKeySequence(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QKeySequence >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QKeySequence_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QKeySequence_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QKeySequence.StandardKey", "PySide.QtGui.QKeySequence", "unicode", "unicode, PySide.QtGui.QKeySequence.SequenceFormat", "int, int = 0, int = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QKeySequence", overloads);
        return -1;
}

static PyObject* Sbk_QKeySequenceFunc___reduce__(PyObject* self)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __reduce__()
            // Begin code injection

            // TEMPLATE - reduce_code - START
            pyResult = Py_BuildValue("(N(iiii))", PyObject_Type(self), (*cppSelf)[0], (*cppSelf)[1], (*cppSelf)[2], (*cppSelf)[3]);
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

static PyObject* Sbk_QKeySequenceFunc___repr__(PyObject* self)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            // TEMPLATE - repr_code - START
            QString format = QString().sprintf("%s(%i, %i, %i, %i)", ((PyObject*)self)->ob_type->tp_name, (*cppSelf)[0], (*cppSelf)[1], (*cppSelf)[2], (*cppSelf)[3]);
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

static PyObject* Sbk_QKeySequenceFunc_count(PyObject* self)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QKeySequence*>(cppSelf)->count();
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

static PyObject* Sbk_QKeySequenceFunc_fromString(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence.fromString(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence.fromString(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromString", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromString(QString,QKeySequence::SequenceFormat)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromString(QString,QKeySequence::SequenceFormat)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fromString(QString,QKeySequence::SequenceFormat)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_fromString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence.fromString(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]), (pyArgs[1]))))
                    goto Sbk_QKeySequenceFunc_fromString_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QKeySequence::SequenceFormat cppArg1 = QKeySequence::PortableText;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fromString(QString,QKeySequence::SequenceFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeySequence cppResult = ::QKeySequence::fromString(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc_fromString_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QKeySequence.SequenceFormat = PortableText", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QKeySequence.fromString", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc_isEmpty(PyObject* self)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEmpty()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QKeySequence*>(cppSelf)->isEmpty();
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

static PyObject* Sbk_QKeySequenceFunc_keyBindings(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyBindings(QKeySequence::StandardKey)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
        overloadId = 0; // keyBindings(QKeySequence::StandardKey)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_keyBindings_TypeError;

    // Call function/method
    {
        ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyBindings(QKeySequence::StandardKey)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QKeySequence > cppResult = ::QKeySequence::keyBindings(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc_keyBindings_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence.StandardKey", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.keyBindings", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc_matches(PyObject* self, PyObject* pyArg)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: matches(QKeySequence)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
        overloadId = 0; // matches(QKeySequence)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_matches_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeySequence cppArg0_local = ::QKeySequence();
        ::QKeySequence* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // matches(QKeySequence)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeySequence::SequenceMatch cppResult = const_cast<const ::QKeySequence*>(cppSelf)->matches(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc_matches_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.matches", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc_mnemonic(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mnemonic(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // mnemonic(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_mnemonic_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mnemonic(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeySequence cppResult = ::QKeySequence::mnemonic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc_mnemonic_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.mnemonic", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QKeySequence&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
        overloadId = 0; // swap(QKeySequence&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeySequence cppArg0_local = ::QKeySequence();
        ::QKeySequence* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QKeySequence&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QKeySequenceFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.swap", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc_toString(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence.toString(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:toString", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: toString(QKeySequence::SequenceFormat)const
    if (numArgs == 0) {
        overloadId = 0; // toString(QKeySequence::SequenceFormat)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]), (pyArgs[0])))) {
        overloadId = 0; // toString(QKeySequence::SequenceFormat)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc_toString_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "format");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QKeySequence.toString(): got multiple values for keyword argument 'format'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]), (pyArgs[0]))))
                    goto Sbk_QKeySequenceFunc_toString_TypeError;
            }
        }
        ::QKeySequence::SequenceFormat cppArg0 = QKeySequence::PortableText;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // toString(QKeySequence::SequenceFormat)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QKeySequence*>(cppSelf)->toString(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc_toString_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence.SequenceFormat = PortableText", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QKeySequence.toString", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequence___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QKeySequence& cppSelf = *(((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QKeySequence_methods[] = {
    {"__reduce__", (PyCFunction)Sbk_QKeySequenceFunc___reduce__, METH_NOARGS},
    {"count", (PyCFunction)Sbk_QKeySequenceFunc_count, METH_NOARGS},
    {"fromString", (PyCFunction)Sbk_QKeySequenceFunc_fromString, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"isEmpty", (PyCFunction)Sbk_QKeySequenceFunc_isEmpty, METH_NOARGS},
    {"keyBindings", (PyCFunction)Sbk_QKeySequenceFunc_keyBindings, METH_O|METH_STATIC},
    {"matches", (PyCFunction)Sbk_QKeySequenceFunc_matches, METH_O},
    {"mnemonic", (PyCFunction)Sbk_QKeySequenceFunc_mnemonic, METH_O|METH_STATIC},
    {"swap", (PyCFunction)Sbk_QKeySequenceFunc_swap, METH_O},
    {"toString", (PyCFunction)Sbk_QKeySequenceFunc_toString, METH_VARARGS|METH_KEYWORDS},

    {"__copy__", (PyCFunction)Sbk_QKeySequence___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QKeySequenceFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QKeySequence)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QKeySequence)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QKeySequence) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QKeySequenceFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
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
    // 0: operator>>(QDataStream&,QKeySequence&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QKeySequence&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QKeySequenceFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QKeySequence&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QKeySequenceFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QKeySequence.__rshift__", overloads);
        return 0;
}

PyObject* Sbk_QKeySequenceFunc___getitem__(PyObject* self, Py_ssize_t _i)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QKeySequence* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self));
    // Begin code injection

    if (_i < 0 || _i >= cppSelf->count()) {
        PyErr_SetString(PyExc_IndexError, "index out of bounds");
        return 0;
    }
    int item = (*cppSelf)[_i];
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &item);

    // End of code injection
}

// Rich comparison
static PyObject* Sbk_QKeySequence_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QKeySequence& cppSelf = *(((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator!=(const QKeySequence & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator<(const QKeySequence & ks) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QKeySequence_RichComparison_TypeError;
            }

            break;
        case Py_LE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator<=(const QKeySequence & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf <= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QKeySequence_RichComparison_TypeError;
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator==(const QKeySequence & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
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
        case Py_GT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator>(const QKeySequence & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf > (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QKeySequence_RichComparison_TypeError;
            }

            break;
        case Py_GE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
                // operator>=(const QKeySequence & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QKeySequence cppArg0_local = ::QKeySequence();
                ::QKeySequence* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf >= (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QKeySequence_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QKeySequence_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QKeySequence_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QKeySequence_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QKeySequence_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QKeySequence_TypeAsNumber;

static PySequenceMethods Sbk_QKeySequence_TypeAsSequence;

static SbkObjectType Sbk_QKeySequence_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QKeySequence",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QKeySequenceFunc___repr__,
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
    /*tp_traverse*/         Sbk_QKeySequence_traverse,
    /*tp_clear*/            Sbk_QKeySequence_clear,
    /*tp_richcompare*/      Sbk_QKeySequence_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QKeySequence_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QKeySequence_Init,
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
static void QKeySequence_StandardKey_PythonToCpp_QKeySequence_StandardKey(PyObject* pyIn, void* cppOut) {
    *((::QKeySequence::StandardKey*)cppOut) = (::QKeySequence::StandardKey) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QKeySequence_StandardKey_PythonToCpp_QKeySequence_StandardKey_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]))
        return QKeySequence_StandardKey_PythonToCpp_QKeySequence_StandardKey;
    return 0;
}
static PyObject* QKeySequence_StandardKey_CppToPython_QKeySequence_StandardKey(const void* cppIn) {
    int castCppIn = *((::QKeySequence::StandardKey*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX], castCppIn);

}

static void QKeySequence_SequenceFormat_PythonToCpp_QKeySequence_SequenceFormat(PyObject* pyIn, void* cppOut) {
    *((::QKeySequence::SequenceFormat*)cppOut) = (::QKeySequence::SequenceFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QKeySequence_SequenceFormat_PythonToCpp_QKeySequence_SequenceFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]))
        return QKeySequence_SequenceFormat_PythonToCpp_QKeySequence_SequenceFormat;
    return 0;
}
static PyObject* QKeySequence_SequenceFormat_CppToPython_QKeySequence_SequenceFormat(const void* cppIn) {
    int castCppIn = *((::QKeySequence::SequenceFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX], castCppIn);

}

static void QKeySequence_SequenceMatch_PythonToCpp_QKeySequence_SequenceMatch(PyObject* pyIn, void* cppOut) {
    *((::QKeySequence::SequenceMatch*)cppOut) = (::QKeySequence::SequenceMatch) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QKeySequence_SequenceMatch_PythonToCpp_QKeySequence_SequenceMatch_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX]))
        return QKeySequence_SequenceMatch_PythonToCpp_QKeySequence_SequenceMatch;
    return 0;
}
static PyObject* QKeySequence_SequenceMatch_CppToPython_QKeySequence_SequenceMatch(const void* cppIn) {
    int castCppIn = *((::QKeySequence::SequenceMatch*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QKeySequence_PythonToCpp_QKeySequence_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QKeySequence_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QKeySequence_PythonToCpp_QKeySequence_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QKeySequence_Type))
        return QKeySequence_PythonToCpp_QKeySequence_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QKeySequence_PTR_CppToPython_QKeySequence(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QKeySequence*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QKeySequence_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QKeySequence_COPY_CppToPython_QKeySequence(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QKeySequence_Type, new ::QKeySequence(*((::QKeySequence*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QKeySequence_PythonToCpp_QKeySequence_COPY(PyObject* pyIn, void* cppOut) {
    *((::QKeySequence*)cppOut) = *((::QKeySequence*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QKeySequence_PythonToCpp_QKeySequence_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QKeySequence_Type))
        return QKeySequence_PythonToCpp_QKeySequence_COPY;
    return 0;
}

// Implicit conversions.
static void QKeySequence_StandardKey_PythonToCpp_QKeySequence(PyObject* pyIn, void* cppOut) {
    ::QKeySequence::StandardKey cppIn = ((::QKeySequence::StandardKey)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), pyIn, &cppIn);
    *((::QKeySequence*)cppOut) = ::QKeySequence(cppIn);
}
static PythonToCppFunc is_QKeySequence_StandardKey_PythonToCpp_QKeySequence_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX], pyIn))
        return QKeySequence_StandardKey_PythonToCpp_QKeySequence;
    return 0;
}

static void PySide_QtCore_constQStringREF_PythonToCpp_QKeySequence(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QKeySequence*)cppOut) = ::QKeySequence(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QKeySequence_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QKeySequence;
    return 0;
}

static void PySide_QtCore_int_PythonToCpp_QKeySequence(PyObject* pyIn, void* cppOut) {
    int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &cppIn);
    *((::QKeySequence*)cppOut) = ::QKeySequence(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_int_PythonToCpp_QKeySequence_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_int_PythonToCpp_QKeySequence;
    return 0;
}

void init_QKeySequence(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QKeySequence_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QKeySequence_TypeAsNumber.nb_rshift = Sbk_QKeySequenceFunc___rshift__;
    Sbk_QKeySequence_TypeAsNumber.nb_lshift = Sbk_QKeySequenceFunc___lshift__;
    Sbk_QKeySequence_Type.super.ht_type.tp_as_number = &Sbk_QKeySequence_TypeAsNumber;

    // type supports sequence protocol
    memset(&Sbk_QKeySequence_TypeAsSequence, 0, sizeof(PySequenceMethods));
    Sbk_QKeySequence_TypeAsSequence.sq_item = &Sbk_QKeySequenceFunc___getitem__;
    Sbk_QKeySequence_Type.super.ht_type.tp_as_sequence = &Sbk_QKeySequence_TypeAsSequence;

    SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QKeySequence_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QKeySequence", "QKeySequence",
        &Sbk_QKeySequence_Type, &Shiboken::callCppDestructor< ::QKeySequence >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QKeySequence_Type,
        QKeySequence_PythonToCpp_QKeySequence_PTR,
        is_QKeySequence_PythonToCpp_QKeySequence_PTR_Convertible,
        QKeySequence_PTR_CppToPython_QKeySequence,
        QKeySequence_COPY_CppToPython_QKeySequence);

    Shiboken::Conversions::registerConverterName(converter, "QKeySequence");
    Shiboken::Conversions::registerConverterName(converter, "QKeySequence*");
    Shiboken::Conversions::registerConverterName(converter, "QKeySequence&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QKeySequence).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QKeySequence_PythonToCpp_QKeySequence_COPY,
        is_QKeySequence_PythonToCpp_QKeySequence_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QKeySequence_StandardKey_PythonToCpp_QKeySequence,
        is_QKeySequence_StandardKey_PythonToCpp_QKeySequence_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QKeySequence,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QKeySequence_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_int_PythonToCpp_QKeySequence,
        is_PySide_QtCore_int_PythonToCpp_QKeySequence_Convertible);

    // Initialization of enums.

    // Initialization of enum 'StandardKey'.
    SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QKeySequence_Type,
        "StandardKey",
        "PySide.QtGui.QKeySequence.StandardKey",
        "QKeySequence::StandardKey");
    if (!SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "UnknownKey", (long) QKeySequence::UnknownKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "HelpContents", (long) QKeySequence::HelpContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "WhatsThis", (long) QKeySequence::WhatsThis))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Open", (long) QKeySequence::Open))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Close", (long) QKeySequence::Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Save", (long) QKeySequence::Save))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "New", (long) QKeySequence::New))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Delete", (long) QKeySequence::Delete))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Cut", (long) QKeySequence::Cut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Copy", (long) QKeySequence::Copy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Paste", (long) QKeySequence::Paste))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Undo", (long) QKeySequence::Undo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Redo", (long) QKeySequence::Redo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Back", (long) QKeySequence::Back))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Forward", (long) QKeySequence::Forward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Refresh", (long) QKeySequence::Refresh))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "ZoomIn", (long) QKeySequence::ZoomIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "ZoomOut", (long) QKeySequence::ZoomOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Print", (long) QKeySequence::Print))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "AddTab", (long) QKeySequence::AddTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "NextChild", (long) QKeySequence::NextChild))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "PreviousChild", (long) QKeySequence::PreviousChild))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Find", (long) QKeySequence::Find))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "FindNext", (long) QKeySequence::FindNext))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "FindPrevious", (long) QKeySequence::FindPrevious))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Replace", (long) QKeySequence::Replace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectAll", (long) QKeySequence::SelectAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Bold", (long) QKeySequence::Bold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Italic", (long) QKeySequence::Italic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Underline", (long) QKeySequence::Underline))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToNextChar", (long) QKeySequence::MoveToNextChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToPreviousChar", (long) QKeySequence::MoveToPreviousChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToNextWord", (long) QKeySequence::MoveToNextWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToPreviousWord", (long) QKeySequence::MoveToPreviousWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToNextLine", (long) QKeySequence::MoveToNextLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToPreviousLine", (long) QKeySequence::MoveToPreviousLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToNextPage", (long) QKeySequence::MoveToNextPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToPreviousPage", (long) QKeySequence::MoveToPreviousPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToStartOfLine", (long) QKeySequence::MoveToStartOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToEndOfLine", (long) QKeySequence::MoveToEndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToStartOfBlock", (long) QKeySequence::MoveToStartOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToEndOfBlock", (long) QKeySequence::MoveToEndOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToStartOfDocument", (long) QKeySequence::MoveToStartOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "MoveToEndOfDocument", (long) QKeySequence::MoveToEndOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectNextChar", (long) QKeySequence::SelectNextChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectPreviousChar", (long) QKeySequence::SelectPreviousChar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectNextWord", (long) QKeySequence::SelectNextWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectPreviousWord", (long) QKeySequence::SelectPreviousWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectNextLine", (long) QKeySequence::SelectNextLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectPreviousLine", (long) QKeySequence::SelectPreviousLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectNextPage", (long) QKeySequence::SelectNextPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectPreviousPage", (long) QKeySequence::SelectPreviousPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectStartOfLine", (long) QKeySequence::SelectStartOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectEndOfLine", (long) QKeySequence::SelectEndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectStartOfBlock", (long) QKeySequence::SelectStartOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectEndOfBlock", (long) QKeySequence::SelectEndOfBlock))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectStartOfDocument", (long) QKeySequence::SelectStartOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SelectEndOfDocument", (long) QKeySequence::SelectEndOfDocument))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "DeleteStartOfWord", (long) QKeySequence::DeleteStartOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "DeleteEndOfWord", (long) QKeySequence::DeleteEndOfWord))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "DeleteEndOfLine", (long) QKeySequence::DeleteEndOfLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "InsertParagraphSeparator", (long) QKeySequence::InsertParagraphSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "InsertLineSeparator", (long) QKeySequence::InsertLineSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "SaveAs", (long) QKeySequence::SaveAs))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Preferences", (long) QKeySequence::Preferences))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
        &Sbk_QKeySequence_Type, "Quit", (long) QKeySequence::Quit))
        return ;
    // Register converter for enum 'QKeySequence::StandardKey'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX],
            QKeySequence_StandardKey_CppToPython_QKeySequence_StandardKey);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QKeySequence_StandardKey_PythonToCpp_QKeySequence_StandardKey,
            is_QKeySequence_StandardKey_PythonToCpp_QKeySequence_StandardKey_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QKeySequence::StandardKey");
        Shiboken::Conversions::registerConverterName(converter, "StandardKey");
    }
    // End of 'StandardKey' enum.

    // Initialization of enum 'SequenceFormat'.
    SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QKeySequence_Type,
        "SequenceFormat",
        "PySide.QtGui.QKeySequence.SequenceFormat",
        "QKeySequence::SequenceFormat");
    if (!SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX],
        &Sbk_QKeySequence_Type, "NativeText", (long) QKeySequence::NativeText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX],
        &Sbk_QKeySequence_Type, "PortableText", (long) QKeySequence::PortableText))
        return ;
    // Register converter for enum 'QKeySequence::SequenceFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX],
            QKeySequence_SequenceFormat_CppToPython_QKeySequence_SequenceFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QKeySequence_SequenceFormat_PythonToCpp_QKeySequence_SequenceFormat,
            is_QKeySequence_SequenceFormat_PythonToCpp_QKeySequence_SequenceFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QKeySequence::SequenceFormat");
        Shiboken::Conversions::registerConverterName(converter, "SequenceFormat");
    }
    // End of 'SequenceFormat' enum.

    // Initialization of enum 'SequenceMatch'.
    SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QKeySequence_Type,
        "SequenceMatch",
        "PySide.QtGui.QKeySequence.SequenceMatch",
        "QKeySequence::SequenceMatch");
    if (!SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX],
        &Sbk_QKeySequence_Type, "NoMatch", (long) QKeySequence::NoMatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX],
        &Sbk_QKeySequence_Type, "PartialMatch", (long) QKeySequence::PartialMatch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX],
        &Sbk_QKeySequence_Type, "ExactMatch", (long) QKeySequence::ExactMatch))
        return ;
    // Register converter for enum 'QKeySequence::SequenceMatch'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX],
            QKeySequence_SequenceMatch_CppToPython_QKeySequence_SequenceMatch);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QKeySequence_SequenceMatch_PythonToCpp_QKeySequence_SequenceMatch,
            is_QKeySequence_SequenceMatch_PythonToCpp_QKeySequence_SequenceMatch_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QKeySequence::SequenceMatch");
        Shiboken::Conversions::registerConverterName(converter, "SequenceMatch");
    }
    // End of 'SequenceMatch' enum.


    qRegisterMetaType< ::QKeySequence >("QKeySequence");
    qRegisterMetaType< ::QKeySequence::StandardKey >("QKeySequence::StandardKey");
    qRegisterMetaType< ::QKeySequence::SequenceFormat >("QKeySequence::SequenceFormat");
    qRegisterMetaType< ::QKeySequence::SequenceMatch >("QKeySequence::SequenceMatch");
}
