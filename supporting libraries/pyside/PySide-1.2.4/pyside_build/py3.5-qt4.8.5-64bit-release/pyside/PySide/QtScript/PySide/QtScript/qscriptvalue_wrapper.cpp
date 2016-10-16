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
#include "pyside_qtscript_python.h"

#include "qscriptvalue_wrapper.h"

// Extra includes
#include <QList>
#include <qdatetime.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qregexp.h>
#include <qscriptclass.h>
#include <qscriptengine.h>
#include <qscriptstring.h>
#include <qscriptvalue.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptValue_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptValue >()))
        return -1;

    ::QScriptValue* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QScriptValue", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptValue()
    // 1: QScriptValue(QScriptEngine*,QScriptValue::SpecialValue)
    // 2: QScriptValue(QScriptEngine*,bool)
    // 3: QScriptValue(QScriptEngine*,QString)
    // 4: QScriptValue(QScriptEngine*,const char*)
    // 5: QScriptValue(QScriptEngine*,double)
    // 6: QScriptValue(QScriptEngine*,int)
    // 7: QScriptValue(QScriptEngine*,uint)
    // 8: QScriptValue(QScriptValue::SpecialValue)
    // 9: QScriptValue(bool)
    // 10: QScriptValue(QScriptValue)
    // 11: QScriptValue(QString)
    // 12: QScriptValue(const char*)
    // 13: QScriptValue(double)
    // 14: QScriptValue(int)
    // 15: QScriptValue(uint)
    if (numArgs == 0) {
        overloadId = 0; // QScriptValue()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX]), (pyArgs[0])))) {
        overloadId = 8; // QScriptValue(QScriptValue::SpecialValue)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))) {
        overloadId = 15; // QScriptValue(uint)
    } else if (numArgs == 1
        && PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        overloadId = 13; // QScriptValue(double)
    } else if (numArgs == 1
        && Shiboken::String::check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[0])))) {
        overloadId = 12; // QScriptValue(const char*)
    } else if (numArgs == 1
        && PyBool_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 9; // QScriptValue(bool)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 14; // QScriptValue(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // QScriptValue(QScriptEngine*,QScriptValue::SpecialValue)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[1])))) {
            overloadId = 7; // QScriptValue(QScriptEngine*,uint)
        } else if (numArgs == 2
            && PyFloat_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 5; // QScriptValue(QScriptEngine*,double)
        } else if (numArgs == 2
            && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 4; // QScriptValue(QScriptEngine*,const char*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 3; // QScriptValue(QScriptEngine*,QString)
        } else if (numArgs == 2
            && PyBool_Check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 2; // QScriptValue(QScriptEngine*,bool)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 6; // QScriptValue(QScriptEngine*,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 11; // QScriptValue(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        overloadId = 10; // QScriptValue(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValue_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QScriptValue()
        {

            if (!PyErr_Occurred()) {
                // QScriptValue()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QScriptValue(QScriptEngine * engine, QScriptValue::SpecialValue val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QScriptValue::SpecialValue cppArg1 = ((::QScriptValue::SpecialValue)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,QScriptValue::SpecialValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QScriptValue(QScriptEngine * engine, bool val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QScriptValue(QScriptEngine * engine, const QString & val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QScriptValue(QScriptEngine * engine, const char * val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QScriptValue(QScriptEngine * engine, double val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QScriptValue(QScriptEngine * engine, int val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QScriptValue(QScriptEngine * engine, uint val)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            uint cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptEngine*,uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // QScriptValue(QScriptValue::SpecialValue value)
        {
            ::QScriptValue::SpecialValue cppArg0 = ((::QScriptValue::SpecialValue)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptValue::SpecialValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // QScriptValue(bool value)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // QScriptValue(const QScriptValue & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QScriptValue cppArg0_local = ::QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QScriptValue(QScriptValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 11: // QScriptValue(const QString & value)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 12: // QScriptValue(const char * value)
        {
            const char* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 13: // QScriptValue(double value)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 14: // QScriptValue(int value)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 15: // QScriptValue(uint value)
        {
            uint cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptValue(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QScriptValue(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptValue >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptValue_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QScriptValue_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtScript.QScriptEngine, PySide.QtScript.QScriptValue.SpecialValue", "PySide.QtScript.QScriptEngine, bool", "PySide.QtScript.QScriptEngine, unicode", "PySide.QtScript.QScriptEngine, " SBK_STR_NAME "", "PySide.QtScript.QScriptEngine, float", "PySide.QtScript.QScriptEngine, int", "PySide.QtScript.QScriptEngine, unsigned int", "PySide.QtScript.QScriptValue.SpecialValue", "bool", "PySide.QtScript.QScriptValue", "unicode", "" SBK_STR_NAME "", "float", "int", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue", overloads);
        return -1;
}

static PyObject* Sbk_QScriptValueFunc___iter__(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __iter__()
            // Begin code injection

            pyResult = Shiboken::createWrapper(new QScriptValueIterator(*cppSelf), true, true);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc___repr__(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // __repr__()
            // Begin code injection

            if (cppSelf->isVariant() || cppSelf->isString()) {
                QString format = QString().sprintf("%s(\"%s\")", ((PyObject*)self)->ob_type->tp_name, qPrintable(cppSelf->toString()));
                pyResult = Shiboken::String::fromCString(qPrintable(format));
             } else {
                pyResult = Shiboken::String::fromCString(
                                ((PyObject* )self)->ob_type->tp_name);
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

static PyObject* Sbk_QScriptValueFunc_call(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.call(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:call", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: call(QScriptValue,QList<QScriptValue>)
    // 1: call(QScriptValue,QScriptValue)
    if (numArgs == 0) {
        overloadId = 0; // call(QScriptValue,QList<QScriptValue>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // call(QScriptValue,QList<QScriptValue>)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
            overloadId = 1; // call(QScriptValue,QScriptValue)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtScriptTypeConverters[SBK_QTSCRIPT_QLIST_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
            overloadId = 0; // call(QScriptValue,QList<QScriptValue>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_call_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // call(const QScriptValue & thisObject, const QList<QScriptValue > & args)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "thisObject");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.call(): got multiple values for keyword argument 'thisObject'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0]))))
                        goto Sbk_QScriptValueFunc_call_TypeError;
                }
                value = PyDict_GetItemString(kwds, "args");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.call(): got multiple values for keyword argument 'args'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtScriptTypeConverters[SBK_QTSCRIPT_QLIST_QSCRIPTVALUE_IDX], (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_call_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptValue cppArg0_local = QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }
            ::QList<QScriptValue > cppArg1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // call(QScriptValue,QList<QScriptValue>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->call(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // call(const QScriptValue & thisObject, const QScriptValue & arguments)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptValue cppArg0_local = ::QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QScriptValue cppArg1_local = ::QScriptValue();
            ::QScriptValue* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // call(QScriptValue,QScriptValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->call(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_call_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue = QScriptValue(), list = QScriptValueList()", "PySide.QtScript.QScriptValue, PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue.call", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_construct(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.construct(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:construct", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: construct(QList<QScriptValue>)
    // 1: construct(QScriptValue)
    if (numArgs == 0) {
        overloadId = 0; // construct(QList<QScriptValue>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        overloadId = 1; // construct(QScriptValue)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtScriptTypeConverters[SBK_QTSCRIPT_QLIST_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        overloadId = 0; // construct(QList<QScriptValue>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_construct_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // construct(const QList<QScriptValue > & args)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "args");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.construct(): got multiple values for keyword argument 'args'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtScriptTypeConverters[SBK_QTSCRIPT_QLIST_QSCRIPTVALUE_IDX], (pyArgs[0]))))
                        goto Sbk_QScriptValueFunc_construct_TypeError;
                }
            }
            ::QList<QScriptValue > cppArg0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // construct(QList<QScriptValue>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->construct(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // construct(const QScriptValue & arguments)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptValue cppArg0_local = ::QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // construct(QScriptValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->construct(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_construct_TypeError:
        const char* overloads[] = {"list = QScriptValueList()", "PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue.construct", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_data(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_engine(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngine * cppResult = const_cast<const ::QScriptValue*>(cppSelf)->engine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_equals(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: equals(QScriptValue)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // equals(QScriptValue)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_equals_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // equals(QScriptValue)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->equals(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_equals_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.equals", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_instanceOf(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: instanceOf(QScriptValue)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // instanceOf(QScriptValue)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_instanceOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // instanceOf(QScriptValue)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->instanceOf(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_instanceOf_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.instanceOf", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_isArray(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isArray()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isArray();
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

static PyObject* Sbk_QScriptValueFunc_isBool(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBool()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isBool();
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

static PyObject* Sbk_QScriptValueFunc_isBoolean(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBoolean()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isBoolean();
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

static PyObject* Sbk_QScriptValueFunc_isDate(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isDate();
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

static PyObject* Sbk_QScriptValueFunc_isError(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isError()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isError();
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

static PyObject* Sbk_QScriptValueFunc_isFunction(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFunction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isFunction();
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

static PyObject* Sbk_QScriptValueFunc_isNull(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isNull();
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

static PyObject* Sbk_QScriptValueFunc_isNumber(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isNumber();
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

static PyObject* Sbk_QScriptValueFunc_isObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isObject();
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

static PyObject* Sbk_QScriptValueFunc_isQMetaObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isQMetaObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isQMetaObject();
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

static PyObject* Sbk_QScriptValueFunc_isQObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isQObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isQObject();
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

static PyObject* Sbk_QScriptValueFunc_isRegExp(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRegExp()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isRegExp();
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

static PyObject* Sbk_QScriptValueFunc_isString(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isString();
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

static PyObject* Sbk_QScriptValueFunc_isUndefined(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUndefined()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isUndefined();
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

static PyObject* Sbk_QScriptValueFunc_isValid(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isValid();
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

static PyObject* Sbk_QScriptValueFunc_isVariant(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isVariant()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->isVariant();
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

static PyObject* Sbk_QScriptValueFunc_lessThan(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: lessThan(QScriptValue)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // lessThan(QScriptValue)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_lessThan_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // lessThan(QScriptValue)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->lessThan(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_lessThan_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.lessThan", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_objectId(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // objectId()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QScriptValue*>(cppSelf)->objectId();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_property(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.property(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.property(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:property", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: property(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
    // 1: property(QString,QFlags<QScriptValue::ResolveFlag>)const
    // 2: property(quint32,QFlags<QScriptValue::ResolveFlag>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // property(quint32,QFlags<QScriptValue::ResolveFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 2; // property(quint32,QFlags<QScriptValue::ResolveFlag>)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // property(QString,QFlags<QScriptValue::ResolveFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // property(QString,QFlags<QScriptValue::ResolveFlag>)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // property(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // property(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_property_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // property(const QScriptString & name, const QFlags<QScriptValue::ResolveFlag> & mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.property(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_property_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptString cppArg0_local = ::QScriptString();
            ::QScriptString* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QFlags<QScriptValue::ResolveFlag> cppArg1 = QScriptValue::ResolvePrototype;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // property(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->property(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // property(const QString & name, const QFlags<QScriptValue::ResolveFlag> & mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.property(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_property_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QScriptValue::ResolveFlag> cppArg1 = QScriptValue::ResolvePrototype;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // property(QString,QFlags<QScriptValue::ResolveFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->property(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 2: // property(quint32 arrayIndex, const QFlags<QScriptValue::ResolveFlag> & mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.property(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_property_TypeError;
                }
            }
            quint32 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QScriptValue::ResolveFlag> cppArg1 = QScriptValue::ResolvePrototype;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // property(quint32,QFlags<QScriptValue::ResolveFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->property(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_property_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptString, PySide.QtScript.QScriptValue.ResolveFlags = QScriptValue.ResolvePrototype", "unicode, PySide.QtScript.QScriptValue.ResolveFlags = QScriptValue.ResolvePrototype", "unsigned int, PySide.QtScript.QScriptValue.ResolveFlags = QScriptValue.ResolvePrototype", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue.property", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_propertyFlags(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.propertyFlags(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.propertyFlags(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:propertyFlags", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: propertyFlags(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
    // 1: propertyFlags(QString,QFlags<QScriptValue::ResolveFlag>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // propertyFlags(QString,QFlags<QScriptValue::ResolveFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 1; // propertyFlags(QString,QFlags<QScriptValue::ResolveFlag>)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // propertyFlags(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // propertyFlags(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_propertyFlags_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // propertyFlags(const QScriptString & name, const QFlags<QScriptValue::ResolveFlag> & mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.propertyFlags(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_propertyFlags_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptString cppArg0_local = ::QScriptString();
            ::QScriptString* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QFlags<QScriptValue::ResolveFlag> cppArg1 = QScriptValue::ResolvePrototype;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // propertyFlags(QScriptString,QFlags<QScriptValue::ResolveFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QScriptValue::PropertyFlag> cppResult = const_cast<const ::QScriptValue*>(cppSelf)->propertyFlags(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
            }
            break;
        }
        case 1: // propertyFlags(const QString & name, const QFlags<QScriptValue::ResolveFlag> & mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.propertyFlags(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptValueFunc_propertyFlags_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<QScriptValue::ResolveFlag> cppArg1 = QScriptValue::ResolvePrototype;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // propertyFlags(QString,QFlags<QScriptValue::ResolveFlag>)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QFlags<QScriptValue::PropertyFlag> cppResult = const_cast<const ::QScriptValue*>(cppSelf)->propertyFlags(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_propertyFlags_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptString, PySide.QtScript.QScriptValue.ResolveFlags = QScriptValue.ResolvePrototype", "unicode, PySide.QtScript.QScriptValue.ResolveFlags = QScriptValue.ResolvePrototype", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue.propertyFlags", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_prototype(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prototype()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->prototype();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_scope(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scope()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->scope();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_scriptClass(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scriptClass()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptClass * cppResult = const_cast<const ::QScriptValue*>(cppSelf)->scriptClass();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_setData(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setData(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setData(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_setData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setData(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setData(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptValueFunc_setData_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.setData", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_setProperty(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.setProperty(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.setProperty(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setProperty", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(QScriptString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
    // 1: setProperty(QString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
    // 2: setProperty(quint32,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // setProperty(quint32,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 2; // setProperty(quint32,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // setProperty(QString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 1; // setProperty(QString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setProperty(QScriptString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2])))) {
            overloadId = 0; // setProperty(QScriptString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_setProperty_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setProperty(const QScriptString & name, const QScriptValue & value, const QFlags<QScriptValue::PropertyFlag> & flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.setProperty(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QScriptValueFunc_setProperty_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptString cppArg0_local = ::QScriptString();
            ::QScriptString* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QScriptValue cppArg1_local = ::QScriptValue();
            ::QScriptValue* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QFlags<QScriptValue::PropertyFlag> cppArg2 = QScriptValue::KeepExistingFlags;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setProperty(QScriptString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setProperty(*cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setProperty(const QString & name, const QScriptValue & value, const QFlags<QScriptValue::PropertyFlag> & flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.setProperty(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QScriptValueFunc_setProperty_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QScriptValue cppArg1_local = ::QScriptValue();
            ::QScriptValue* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QFlags<QScriptValue::PropertyFlag> cppArg2 = QScriptValue::KeepExistingFlags;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setProperty(QString,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setProperty(cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setProperty(quint32 arrayIndex, const QScriptValue & value, const QFlags<QScriptValue::PropertyFlag> & flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptValue.setProperty(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QScriptValueFunc_setProperty_TypeError;
                }
            }
            quint32 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QScriptValue cppArg1_local = ::QScriptValue();
            ::QScriptValue* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            ::QFlags<QScriptValue::PropertyFlag> cppArg2 = QScriptValue::KeepExistingFlags;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setProperty(quint32,QScriptValue,QFlags<QScriptValue::PropertyFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setProperty(cppArg0, *cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptValueFunc_setProperty_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptString, PySide.QtScript.QScriptValue, PySide.QtScript.QScriptValue.PropertyFlags = QScriptValue.KeepExistingFlags", "unicode, PySide.QtScript.QScriptValue, PySide.QtScript.QScriptValue.PropertyFlags = QScriptValue.KeepExistingFlags", "unsigned int, PySide.QtScript.QScriptValue, PySide.QtScript.QScriptValue.PropertyFlags = QScriptValue.KeepExistingFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptValue.setProperty", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_setPrototype(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrototype(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setPrototype(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_setPrototype_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPrototype(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrototype(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptValueFunc_setPrototype_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.setPrototype", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_setScope(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScope(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setScope(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_setScope_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setScope(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScope(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptValueFunc_setScope_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.setScope", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_setScriptClass(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScriptClass(QScriptClass*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (pyArg)))) {
        overloadId = 0; // setScriptClass(QScriptClass*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_setScriptClass_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptClass* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScriptClass(QScriptClass*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScriptClass(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptValueFunc_setScriptClass_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptClass", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.setScriptClass", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_strictlyEquals(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: strictlyEquals(QScriptValue)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // strictlyEquals(QScriptValue)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptValueFunc_strictlyEquals_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // strictlyEquals(QScriptValue)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->strictlyEquals(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptValueFunc_strictlyEquals_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptValue.strictlyEquals", overloads);
        return 0;
}

static PyObject* Sbk_QScriptValueFunc_toBool(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toBool()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toBool();
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

static PyObject* Sbk_QScriptValueFunc_toBoolean(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toBoolean()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toBoolean();
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

static PyObject* Sbk_QScriptValueFunc_toDateTime(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toDateTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toInt32(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toInt32()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint32 cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toInt32();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toInteger(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toInteger()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toInteger();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toNumber(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toNumber();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toQMetaObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toQMetaObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMetaObject * cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toQMetaObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toQObject(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toQObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QObject * cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toQObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toRegExp(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toRegExp()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegExp cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toRegExp();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toString(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toString()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toString();
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

static PyObject* Sbk_QScriptValueFunc_toUInt16(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toUInt16()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint16 cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toUInt16();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint16>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toUInt32(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toUInt32()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            quint32 cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toUInt32();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<quint32>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValueFunc_toVariant(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toVariant()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QScriptValue*>(cppSelf)->toVariant();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptValue___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptValue& cppSelf = *(((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QScriptValue_methods[] = {
    {"call", (PyCFunction)Sbk_QScriptValueFunc_call, METH_VARARGS|METH_KEYWORDS},
    {"construct", (PyCFunction)Sbk_QScriptValueFunc_construct, METH_VARARGS|METH_KEYWORDS},
    {"data", (PyCFunction)Sbk_QScriptValueFunc_data, METH_NOARGS},
    {"engine", (PyCFunction)Sbk_QScriptValueFunc_engine, METH_NOARGS},
    {"equals", (PyCFunction)Sbk_QScriptValueFunc_equals, METH_O},
    {"instanceOf", (PyCFunction)Sbk_QScriptValueFunc_instanceOf, METH_O},
    {"isArray", (PyCFunction)Sbk_QScriptValueFunc_isArray, METH_NOARGS},
    {"isBool", (PyCFunction)Sbk_QScriptValueFunc_isBool, METH_NOARGS},
    {"isBoolean", (PyCFunction)Sbk_QScriptValueFunc_isBoolean, METH_NOARGS},
    {"isDate", (PyCFunction)Sbk_QScriptValueFunc_isDate, METH_NOARGS},
    {"isError", (PyCFunction)Sbk_QScriptValueFunc_isError, METH_NOARGS},
    {"isFunction", (PyCFunction)Sbk_QScriptValueFunc_isFunction, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QScriptValueFunc_isNull, METH_NOARGS},
    {"isNumber", (PyCFunction)Sbk_QScriptValueFunc_isNumber, METH_NOARGS},
    {"isObject", (PyCFunction)Sbk_QScriptValueFunc_isObject, METH_NOARGS},
    {"isQMetaObject", (PyCFunction)Sbk_QScriptValueFunc_isQMetaObject, METH_NOARGS},
    {"isQObject", (PyCFunction)Sbk_QScriptValueFunc_isQObject, METH_NOARGS},
    {"isRegExp", (PyCFunction)Sbk_QScriptValueFunc_isRegExp, METH_NOARGS},
    {"isString", (PyCFunction)Sbk_QScriptValueFunc_isString, METH_NOARGS},
    {"isUndefined", (PyCFunction)Sbk_QScriptValueFunc_isUndefined, METH_NOARGS},
    {"isValid", (PyCFunction)Sbk_QScriptValueFunc_isValid, METH_NOARGS},
    {"isVariant", (PyCFunction)Sbk_QScriptValueFunc_isVariant, METH_NOARGS},
    {"lessThan", (PyCFunction)Sbk_QScriptValueFunc_lessThan, METH_O},
    {"objectId", (PyCFunction)Sbk_QScriptValueFunc_objectId, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QScriptValueFunc_property, METH_VARARGS|METH_KEYWORDS},
    {"propertyFlags", (PyCFunction)Sbk_QScriptValueFunc_propertyFlags, METH_VARARGS|METH_KEYWORDS},
    {"prototype", (PyCFunction)Sbk_QScriptValueFunc_prototype, METH_NOARGS},
    {"scope", (PyCFunction)Sbk_QScriptValueFunc_scope, METH_NOARGS},
    {"scriptClass", (PyCFunction)Sbk_QScriptValueFunc_scriptClass, METH_NOARGS},
    {"setData", (PyCFunction)Sbk_QScriptValueFunc_setData, METH_O},
    {"setProperty", (PyCFunction)Sbk_QScriptValueFunc_setProperty, METH_VARARGS|METH_KEYWORDS},
    {"setPrototype", (PyCFunction)Sbk_QScriptValueFunc_setPrototype, METH_O},
    {"setScope", (PyCFunction)Sbk_QScriptValueFunc_setScope, METH_O},
    {"setScriptClass", (PyCFunction)Sbk_QScriptValueFunc_setScriptClass, METH_O},
    {"strictlyEquals", (PyCFunction)Sbk_QScriptValueFunc_strictlyEquals, METH_O},
    {"toBool", (PyCFunction)Sbk_QScriptValueFunc_toBool, METH_NOARGS},
    {"toBoolean", (PyCFunction)Sbk_QScriptValueFunc_toBoolean, METH_NOARGS},
    {"toDateTime", (PyCFunction)Sbk_QScriptValueFunc_toDateTime, METH_NOARGS},
    {"toInt32", (PyCFunction)Sbk_QScriptValueFunc_toInt32, METH_NOARGS},
    {"toInteger", (PyCFunction)Sbk_QScriptValueFunc_toInteger, METH_NOARGS},
    {"toNumber", (PyCFunction)Sbk_QScriptValueFunc_toNumber, METH_NOARGS},
    {"toObject", (PyCFunction)Sbk_QScriptValueFunc_toObject, METH_NOARGS},
    {"toQMetaObject", (PyCFunction)Sbk_QScriptValueFunc_toQMetaObject, METH_NOARGS},
    {"toQObject", (PyCFunction)Sbk_QScriptValueFunc_toQObject, METH_NOARGS},
    {"toRegExp", (PyCFunction)Sbk_QScriptValueFunc_toRegExp, METH_NOARGS},
    {"toString", (PyCFunction)Sbk_QScriptValueFunc_toString, METH_NOARGS},
    {"toUInt16", (PyCFunction)Sbk_QScriptValueFunc_toUInt16, METH_NOARGS},
    {"toUInt32", (PyCFunction)Sbk_QScriptValueFunc_toUInt32, METH_NOARGS},
    {"toVariant", (PyCFunction)Sbk_QScriptValueFunc_toVariant, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QScriptValue___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QScriptValue___nb_bool(PyObject* self)
{
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

PyObject* Sbk_QScriptValueFunc___mgetitem__(PyObject* self, PyObject* _key)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QScriptValue* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)self));
    // Begin code injection

    Shiboken::AutoDecRef key(PyObject_Str(_key));
    QVariant res = cppSelf->property(Shiboken::String::toCString(key.object())).toVariant();
    if (res.isValid()) {
        return Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &res);
    } else {
        PyObject* errorType = PyInt_Check(_key) ? PyExc_IndexError : PyExc_KeyError;
        PyErr_SetString(errorType, "Key not found.");
        return 0;
    }

    // End of code injection
}

} // extern "C"

static int Sbk_QScriptValue_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptValue_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QScriptValue_TypeAsNumber;

static PyMappingMethods Sbk_QScriptValue_TypeAsMapping;

static SbkObjectType Sbk_QScriptValue_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptValue",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QScriptValueFunc___repr__,
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
    /*tp_traverse*/         Sbk_QScriptValue_traverse,
    /*tp_clear*/            Sbk_QScriptValue_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             Sbk_QScriptValueFunc___iter__,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptValue_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptValue_Init,
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

PyObject* SbkPySide_QtScript_QScriptValue_ResolveFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::ResolveFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::ResolveFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::ResolveFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_ResolveFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::ResolveFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::ResolveFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::ResolveFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_ResolveFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::ResolveFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::ResolveFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::ResolveFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::ResolveFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_ResolveFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::ResolveFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), self, &cppSelf);
    ::QScriptValue::ResolveFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtScript_QScriptValue_ResolveFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtScript_QScriptValue_ResolveFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtScript_QScriptValue_ResolveFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtScript_QScriptValue_ResolveFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtScript_QScriptValue_ResolveFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtScript_QScriptValue_ResolveFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtScript_QScriptValue_ResolveFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtScript_QScriptValue_ResolveFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtScript_QScriptValue_ResolveFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtScript_QScriptValue_ResolveFlag_long,
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


PyObject* SbkPySide_QtScript_QScriptValue_PropertyFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::PropertyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::PropertyFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::PropertyFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_PropertyFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::PropertyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::PropertyFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::PropertyFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_PropertyFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::PropertyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptValue::PropertyFlags)PyLong_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptValue::PropertyFlags)PyInt_AsLong(self);
    cppArg = (QScriptValue::PropertyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptValue_PropertyFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QScriptValue::PropertyFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), self, &cppSelf);
    ::QScriptValue::PropertyFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtScript_QScriptValue_PropertyFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtScript_QScriptValue_PropertyFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtScript_QScriptValue_PropertyFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtScript_QScriptValue_PropertyFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtScript_QScriptValue_PropertyFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtScript_QScriptValue_PropertyFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtScript_QScriptValue_PropertyFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtScript_QScriptValue_PropertyFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtScript_QScriptValue_PropertyFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtScript_QScriptValue_PropertyFlag_long,
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
static void QScriptValue_ResolveFlag_PythonToCpp_QScriptValue_ResolveFlag(PyObject* pyIn, void* cppOut) {
    *((::QScriptValue::ResolveFlag*)cppOut) = (::QScriptValue::ResolveFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptValue_ResolveFlag_PythonToCpp_QScriptValue_ResolveFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX]))
        return QScriptValue_ResolveFlag_PythonToCpp_QScriptValue_ResolveFlag;
    return 0;
}
static PyObject* QScriptValue_ResolveFlag_CppToPython_QScriptValue_ResolveFlag(const void* cppIn) {
    int castCppIn = *((::QScriptValue::ResolveFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX], castCppIn);

}

static void QFlags_QScriptValue_ResolveFlag__PythonToCpp_QFlags_QScriptValue_ResolveFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptValue::ResolveFlag>*)cppOut) = ::QFlags<QScriptValue::ResolveFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QScriptValue_ResolveFlag__PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]))
        return QFlags_QScriptValue_ResolveFlag__PythonToCpp_QFlags_QScriptValue_ResolveFlag_;
    return 0;
}
static PyObject* QFlags_QScriptValue_ResolveFlag__CppToPython_QFlags_QScriptValue_ResolveFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QScriptValue::ResolveFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]));

}

static void QScriptValue_ResolveFlag_PythonToCpp_QFlags_QScriptValue_ResolveFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptValue::ResolveFlag>*)cppOut) = ::QFlags<QScriptValue::ResolveFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QScriptValue_ResolveFlag_PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX]))
        return QScriptValue_ResolveFlag_PythonToCpp_QFlags_QScriptValue_ResolveFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QScriptValue_ResolveFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QScriptValue::ResolveFlag>*)cppOut) = ::QFlags<QScriptValue::ResolveFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QScriptValue_ResolveFlag_;
    return 0;
}
static void QScriptValue_PropertyFlag_PythonToCpp_QScriptValue_PropertyFlag(PyObject* pyIn, void* cppOut) {
    *((::QScriptValue::PropertyFlag*)cppOut) = (::QScriptValue::PropertyFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptValue_PropertyFlag_PythonToCpp_QScriptValue_PropertyFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX]))
        return QScriptValue_PropertyFlag_PythonToCpp_QScriptValue_PropertyFlag;
    return 0;
}
static PyObject* QScriptValue_PropertyFlag_CppToPython_QScriptValue_PropertyFlag(const void* cppIn) {
    int castCppIn = *((::QScriptValue::PropertyFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX], castCppIn);

}

static void QFlags_QScriptValue_PropertyFlag__PythonToCpp_QFlags_QScriptValue_PropertyFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptValue::PropertyFlag>*)cppOut) = ::QFlags<QScriptValue::PropertyFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QScriptValue_PropertyFlag__PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]))
        return QFlags_QScriptValue_PropertyFlag__PythonToCpp_QFlags_QScriptValue_PropertyFlag_;
    return 0;
}
static PyObject* QFlags_QScriptValue_PropertyFlag__CppToPython_QFlags_QScriptValue_PropertyFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QScriptValue::PropertyFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]));

}

static void QScriptValue_PropertyFlag_PythonToCpp_QFlags_QScriptValue_PropertyFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptValue::PropertyFlag>*)cppOut) = ::QFlags<QScriptValue::PropertyFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QScriptValue_PropertyFlag_PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX]))
        return QScriptValue_PropertyFlag_PythonToCpp_QFlags_QScriptValue_PropertyFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QScriptValue_PropertyFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QScriptValue::PropertyFlag>*)cppOut) = ::QFlags<QScriptValue::PropertyFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QScriptValue_PropertyFlag_;
    return 0;
}
static void QScriptValue_SpecialValue_PythonToCpp_QScriptValue_SpecialValue(PyObject* pyIn, void* cppOut) {
    *((::QScriptValue::SpecialValue*)cppOut) = (::QScriptValue::SpecialValue) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptValue_SpecialValue_PythonToCpp_QScriptValue_SpecialValue_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX]))
        return QScriptValue_SpecialValue_PythonToCpp_QScriptValue_SpecialValue;
    return 0;
}
static PyObject* QScriptValue_SpecialValue_CppToPython_QScriptValue_SpecialValue(const void* cppIn) {
    int castCppIn = *((::QScriptValue::SpecialValue*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptValue_PythonToCpp_QScriptValue_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptValue_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptValue_PythonToCpp_QScriptValue_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptValue_Type))
        return QScriptValue_PythonToCpp_QScriptValue_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptValue_PTR_CppToPython_QScriptValue(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptValue*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptValue_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QScriptValue_COPY_CppToPython_QScriptValue(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QScriptValue_Type, new ::QScriptValue(*((::QScriptValue*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QScriptValue_PythonToCpp_QScriptValue_COPY(PyObject* pyIn, void* cppOut) {
    *((::QScriptValue*)cppOut) = *((::QScriptValue*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QScriptValue_PythonToCpp_QScriptValue_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptValue_Type))
        return QScriptValue_PythonToCpp_QScriptValue_COPY;
    return 0;
}

// Implicit conversions.
static void QScriptValue_SpecialValue_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    ::QScriptValue::SpecialValue cppIn = ((::QScriptValue::SpecialValue)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX]), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_QScriptValue_SpecialValue_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX], pyIn))
        return QScriptValue_SpecialValue_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_bool_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    bool cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_bool_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (PyBool_Check(pyIn))
        return PySide_QtCore_bool_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_constQStringREF_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    ::QString cppIn = ::QString();
    Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constQStringREF_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constQStringREF_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_constcharPTR_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    const char* cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_constcharPTR_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (Shiboken::String::check(pyIn))
        return PySide_QtCore_constcharPTR_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_double_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    double cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_double_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (PyFloat_Check(pyIn))
        return PySide_QtCore_double_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_int_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    int cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_int_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_int_PythonToCpp_QScriptValue;
    return 0;
}

static void PySide_QtCore_uint_PythonToCpp_QScriptValue(PyObject* pyIn, void* cppOut) {
    uint cppIn;
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), pyIn, &cppIn);
    *((::QScriptValue*)cppOut) = ::QScriptValue(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_uint_PythonToCpp_QScriptValue_Convertible(PyObject* pyIn) {
    if (PyInt_Check(pyIn))
        return PySide_QtCore_uint_PythonToCpp_QScriptValue;
    return 0;
}

void init_QScriptValue(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QScriptValue_TypeAsNumber, 0, sizeof(PyNumberMethods));
    SBK_NB_BOOL(Sbk_QScriptValue_TypeAsNumber) = Sbk_QScriptValue___nb_bool;
    Sbk_QScriptValue_Type.super.ht_type.tp_as_number = &Sbk_QScriptValue_TypeAsNumber;

    // type supports mapping protocol
    memset(&Sbk_QScriptValue_TypeAsMapping, 0, sizeof(PyMappingMethods));
    Sbk_QScriptValue_TypeAsMapping.mp_ass_subscript = 0;
    Sbk_QScriptValue_TypeAsMapping.mp_length = 0;
    Sbk_QScriptValue_TypeAsMapping.mp_subscript = &Sbk_QScriptValueFunc___mgetitem__;
    Sbk_QScriptValue_Type.super.ht_type.tp_as_mapping = &Sbk_QScriptValue_TypeAsMapping;

    SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptValue_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptValue", "QScriptValue",
        &Sbk_QScriptValue_Type, &Shiboken::callCppDestructor< ::QScriptValue >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptValue_Type,
        QScriptValue_PythonToCpp_QScriptValue_PTR,
        is_QScriptValue_PythonToCpp_QScriptValue_PTR_Convertible,
        QScriptValue_PTR_CppToPython_QScriptValue,
        QScriptValue_COPY_CppToPython_QScriptValue);

    Shiboken::Conversions::registerConverterName(converter, "QScriptValue");
    Shiboken::Conversions::registerConverterName(converter, "QScriptValue*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptValue&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptValue).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QScriptValue_PythonToCpp_QScriptValue_COPY,
        is_QScriptValue_PythonToCpp_QScriptValue_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QScriptValue_SpecialValue_PythonToCpp_QScriptValue,
        is_QScriptValue_SpecialValue_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_bool_PythonToCpp_QScriptValue,
        is_PySide_QtCore_bool_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constQStringREF_PythonToCpp_QScriptValue,
        is_PySide_QtCore_constQStringREF_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_constcharPTR_PythonToCpp_QScriptValue,
        is_PySide_QtCore_constcharPTR_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_double_PythonToCpp_QScriptValue,
        is_PySide_QtCore_double_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_int_PythonToCpp_QScriptValue,
        is_PySide_QtCore_int_PythonToCpp_QScriptValue_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_uint_PythonToCpp_QScriptValue,
        is_PySide_QtCore_uint_PythonToCpp_QScriptValue_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ResolveFlag'.
    SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX] = PySide::QFlags::create("ResolveFlags", &SbkPySide_QtScript_QScriptValue_ResolveFlag_as_number);
    SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptValue_Type,
        "ResolveFlag",
        "PySide.QtScript.QScriptValue.ResolveFlag",
        "QScriptValue::ResolveFlag",
        SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX]);
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX],
        &Sbk_QScriptValue_Type, "ResolveLocal", (long) QScriptValue::ResolveLocal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX],
        &Sbk_QScriptValue_Type, "ResolvePrototype", (long) QScriptValue::ResolvePrototype))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX],
        &Sbk_QScriptValue_Type, "ResolveScope", (long) QScriptValue::ResolveScope))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX],
        &Sbk_QScriptValue_Type, "ResolveFull", (long) QScriptValue::ResolveFull))
        return ;
    // Register converter for enum 'QScriptValue::ResolveFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX],
            QScriptValue_ResolveFlag_CppToPython_QScriptValue_ResolveFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptValue_ResolveFlag_PythonToCpp_QScriptValue_ResolveFlag,
            is_QScriptValue_ResolveFlag_PythonToCpp_QScriptValue_ResolveFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_RESOLVEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptValue::ResolveFlag");
        Shiboken::Conversions::registerConverterName(converter, "ResolveFlag");
    }
    // Register converter for flag 'QFlags<QScriptValue::ResolveFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX],
            QFlags_QScriptValue_ResolveFlag__CppToPython_QFlags_QScriptValue_ResolveFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptValue_ResolveFlag_PythonToCpp_QFlags_QScriptValue_ResolveFlag_,
            is_QScriptValue_ResolveFlag_PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QScriptValue_ResolveFlag__PythonToCpp_QFlags_QScriptValue_ResolveFlag_,
            is_QFlags_QScriptValue_ResolveFlag__PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QScriptValue_ResolveFlag_,
            is_number_PythonToCpp_QFlags_QScriptValue_ResolveFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_RESOLVEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QScriptValue::ResolveFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<ResolveFlag>");
    }
    // End of 'ResolveFlag' enum/flags.

    // Initialization of enum 'PropertyFlag'.
    SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX] = PySide::QFlags::create("PropertyFlags", &SbkPySide_QtScript_QScriptValue_PropertyFlag_as_number);
    SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptValue_Type,
        "PropertyFlag",
        "PySide.QtScript.QScriptValue.PropertyFlag",
        "QScriptValue::PropertyFlag",
        SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]);
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "ReadOnly", (long) QScriptValue::ReadOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "Undeletable", (long) QScriptValue::Undeletable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "SkipInEnumeration", (long) QScriptValue::SkipInEnumeration))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "PropertyGetter", (long) QScriptValue::PropertyGetter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "PropertySetter", (long) QScriptValue::PropertySetter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "QObjectMember", (long) QScriptValue::QObjectMember))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "KeepExistingFlags", (long) QScriptValue::KeepExistingFlags))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
        &Sbk_QScriptValue_Type, "UserRange", (long) QScriptValue::UserRange))
        return ;
    // Register converter for enum 'QScriptValue::PropertyFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX],
            QScriptValue_PropertyFlag_CppToPython_QScriptValue_PropertyFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptValue_PropertyFlag_PythonToCpp_QScriptValue_PropertyFlag,
            is_QScriptValue_PropertyFlag_PythonToCpp_QScriptValue_PropertyFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_PROPERTYFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptValue::PropertyFlag");
        Shiboken::Conversions::registerConverterName(converter, "PropertyFlag");
    }
    // Register converter for flag 'QFlags<QScriptValue::PropertyFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX],
            QFlags_QScriptValue_PropertyFlag__CppToPython_QFlags_QScriptValue_PropertyFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptValue_PropertyFlag_PythonToCpp_QFlags_QScriptValue_PropertyFlag_,
            is_QScriptValue_PropertyFlag_PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QScriptValue_PropertyFlag__PythonToCpp_QFlags_QScriptValue_PropertyFlag_,
            is_QFlags_QScriptValue_PropertyFlag__PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QScriptValue_PropertyFlag_,
            is_number_PythonToCpp_QFlags_QScriptValue_PropertyFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QScriptValue::PropertyFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<PropertyFlag>");
    }
    // End of 'PropertyFlag' enum/flags.

    // Initialization of enum 'SpecialValue'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptValue_Type,
        "SpecialValue",
        "PySide.QtScript.QScriptValue.SpecialValue",
        "QScriptValue::SpecialValue");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX],
        &Sbk_QScriptValue_Type, "NullValue", (long) QScriptValue::NullValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX],
        &Sbk_QScriptValue_Type, "UndefinedValue", (long) QScriptValue::UndefinedValue))
        return ;
    // Register converter for enum 'QScriptValue::SpecialValue'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX],
            QScriptValue_SpecialValue_CppToPython_QScriptValue_SpecialValue);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptValue_SpecialValue_PythonToCpp_QScriptValue_SpecialValue,
            is_QScriptValue_SpecialValue_PythonToCpp_QScriptValue_SpecialValue_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_SPECIALVALUE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptValue::SpecialValue");
        Shiboken::Conversions::registerConverterName(converter, "SpecialValue");
    }
    // End of 'SpecialValue' enum.


    qRegisterMetaType< ::QScriptValue >("QScriptValue");
    qRegisterMetaType< ::QScriptValue::ResolveFlag >("QScriptValue::ResolveFlag");
    qRegisterMetaType< ::QScriptValue::ResolveFlags >("QScriptValue::ResolveFlags");
    qRegisterMetaType< ::QScriptValue::PropertyFlag >("QScriptValue::PropertyFlag");
    qRegisterMetaType< ::QScriptValue::PropertyFlags >("QScriptValue::PropertyFlags");
    qRegisterMetaType< ::QScriptValue::SpecialValue >("QScriptValue::SpecialValue");
}
