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
#include "pyside_phonon_python.h"

#include "phonon_effectparameter_wrapper.h"

// Extra includes
#include <QList>
#include <effectparameter.h>

using namespace Phonon;


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_EffectParameter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::EffectParameter >()))
        return -1;

    ::Phonon::EffectParameter* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 8) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): too many arguments");
        return -1;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): not enough arguments");
        return -1;
    } else if (numArgs == 2 || numArgs == 3)
        goto Sbk_Phonon_EffectParameter_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOOO:EffectParameter", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return -1;


    // Overloaded function decisor
    // 0: EffectParameter(Phonon::EffectParameter)
    // 1: EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[5])))) {
                if (numArgs == 6) {
                    overloadId = 1; // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
                } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[6])))) {
                    if (numArgs == 7) {
                        overloadId = 1; // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
                    } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[7])))) {
                        overloadId = 1; // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
                    }
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (pyArgs[0])))) {
        overloadId = 0; // EffectParameter(Phonon::EffectParameter)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_EffectParameter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // EffectParameter(const Phonon::EffectParameter & rhs)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Phonon::EffectParameter cppArg0_local = ::Phonon::EffectParameter();
            ::Phonon::EffectParameter* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // EffectParameter(Phonon::EffectParameter)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::EffectParameter(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // EffectParameter(int parameterId, const QString & name, QFlags<Phonon::EffectParameter::Hint> hints, const QVariant & defaultValue, const QVariant & min, const QVariant & max, const QList<QVariant > & values, const QString & description)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "min");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): got multiple values for keyword argument 'min'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[4]))))
                        goto Sbk_Phonon_EffectParameter_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "max");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): got multiple values for keyword argument 'max'.");
                    return -1;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[5]))))
                        goto Sbk_Phonon_EffectParameter_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "values");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): got multiple values for keyword argument 'values'.");
                    return -1;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], (pyArgs[6]))))
                        goto Sbk_Phonon_EffectParameter_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "description");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.phonon.EffectParameter(): got multiple values for keyword argument 'description'.");
                    return -1;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[7]))))
                        goto Sbk_Phonon_EffectParameter_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<Phonon::EffectParameter::Hint> cppArg2 = ((::QFlags<Phonon::EffectParameter::Hint>)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QVariant cppArg3 = ::QVariant();
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QVariant cppArg4 = QVariant();
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QVariant cppArg5 = QVariant();
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            ::QList<QVariant > cppArg6;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            ::QString cppArg7 = QString();
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);

            if (!PyErr_Occurred()) {
                // EffectParameter(int,QString,QFlags<Phonon::EffectParameter::Hint>,QVariant,QVariant,QVariant,QList<QVariant>,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::Phonon::EffectParameter(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::EffectParameter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_EffectParameter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Phonon_EffectParameter_Init_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::EffectParameter", "int, unicode, PySide.phonon.Phonon::EffectParameter.Hints, QVariant, QVariant = QVariant(), QVariant = QVariant(), list = QVariantList(), unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.EffectParameter", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_EffectParameterFunc_defaultValue(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->defaultValue();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_description(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // description()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QString & cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->description();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_isLogarithmicControl(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLogarithmicControl()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->isLogarithmicControl();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_maximumValue(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->maximumValue();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_minimumValue(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->minimumValue();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_name(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QString & cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->name();
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

static PyObject* Sbk_Phonon_EffectParameterFunc_possibleValues(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // possibleValues()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QVariant > cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->possibleValues();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_phononTypeConverters[SBK_PHONON_QLIST_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_EffectParameterFunc_type(PyObject* self)
{
    ::Phonon::EffectParameter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant::Type cppResult = const_cast<const ::Phonon::EffectParameter*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_EffectParameter___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::EffectParameter& cppSelf = *(((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_EffectParameter_methods[] = {
    {"defaultValue", (PyCFunction)Sbk_Phonon_EffectParameterFunc_defaultValue, METH_NOARGS},
    {"description", (PyCFunction)Sbk_Phonon_EffectParameterFunc_description, METH_NOARGS},
    {"isLogarithmicControl", (PyCFunction)Sbk_Phonon_EffectParameterFunc_isLogarithmicControl, METH_NOARGS},
    {"maximumValue", (PyCFunction)Sbk_Phonon_EffectParameterFunc_maximumValue, METH_NOARGS},
    {"minimumValue", (PyCFunction)Sbk_Phonon_EffectParameterFunc_minimumValue, METH_NOARGS},
    {"name", (PyCFunction)Sbk_Phonon_EffectParameterFunc_name, METH_NOARGS},
    {"possibleValues", (PyCFunction)Sbk_Phonon_EffectParameterFunc_possibleValues, METH_NOARGS},
    {"type", (PyCFunction)Sbk_Phonon_EffectParameterFunc_type, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_Phonon_EffectParameter___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_Phonon_EffectParameter_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::Phonon::EffectParameter& cppSelf = *(((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        default:
            goto Sbk_Phonon_EffectParameter_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_Phonon_EffectParameter_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_Phonon_EffectParameter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_EffectParameter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_EffectParameter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.EffectParameter",
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
    /*tp_traverse*/         Sbk_Phonon_EffectParameter_traverse,
    /*tp_clear*/            Sbk_Phonon_EffectParameter_clear,
    /*tp_richcompare*/      Sbk_Phonon_EffectParameter_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_EffectParameter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_EffectParameter_Init,
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

PyObject* SbkPySide_phonon_Phonon_EffectParameter_Hint___and__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::EffectParameter::Hints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::EffectParameter::Hints)PyLong_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::EffectParameter::Hints)PyInt_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_EffectParameter_Hint___or__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::EffectParameter::Hints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::EffectParameter::Hints)PyLong_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::EffectParameter::Hints)PyInt_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_EffectParameter_Hint___xor__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::EffectParameter::Hints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::Phonon::EffectParameter::Hints)PyLong_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::Phonon::EffectParameter::Hints)PyInt_AsLong(self);
    cppArg = (Phonon::EffectParameter::Hints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), &cppResult);
}

PyObject* SbkPySide_phonon_Phonon_EffectParameter_Hint___invert__(PyObject* self, PyObject* pyArg)
{
    ::Phonon::EffectParameter::Hints cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), self, &cppSelf);
    ::Phonon::EffectParameter::Hints cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), &cppResult);
}

static PyObject* SbkPySide_phonon_Phonon_EffectParameter_Hint_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_phonon_Phonon_EffectParameter_Hint__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_phonon_Phonon_EffectParameter_Hint_as_number = {
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
    /*nb_nonzero*/              SbkPySide_phonon_Phonon_EffectParameter_Hint__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_phonon_Phonon_EffectParameter_Hint___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_phonon_Phonon_EffectParameter_Hint___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_phonon_Phonon_EffectParameter_Hint___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_phonon_Phonon_EffectParameter_Hint___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_phonon_Phonon_EffectParameter_Hint_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_phonon_Phonon_EffectParameter_Hint_long,
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
static void Phonon_EffectParameter_Hint_PythonToCpp_Phonon_EffectParameter_Hint(PyObject* pyIn, void* cppOut) {
    *((::Phonon::EffectParameter::Hint*)cppOut) = (::Phonon::EffectParameter::Hint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_EffectParameter_Hint_PythonToCpp_Phonon_EffectParameter_Hint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX]))
        return Phonon_EffectParameter_Hint_PythonToCpp_Phonon_EffectParameter_Hint;
    return 0;
}
static PyObject* Phonon_EffectParameter_Hint_CppToPython_Phonon_EffectParameter_Hint(const void* cppIn) {
    int castCppIn = *((::Phonon::EffectParameter::Hint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX], castCppIn);

}

static void QFlags_Phonon_EffectParameter_Hint__PythonToCpp_QFlags_Phonon_EffectParameter_Hint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Phonon::EffectParameter::Hint>*)cppOut) = ::QFlags<Phonon::EffectParameter::Hint>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_Phonon_EffectParameter_Hint__PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]))
        return QFlags_Phonon_EffectParameter_Hint__PythonToCpp_QFlags_Phonon_EffectParameter_Hint_;
    return 0;
}
static PyObject* QFlags_Phonon_EffectParameter_Hint__CppToPython_QFlags_Phonon_EffectParameter_Hint_(const void* cppIn) {
    int castCppIn = *((::QFlags<Phonon::EffectParameter::Hint>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]));

}

static void Phonon_EffectParameter_Hint_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<Phonon::EffectParameter::Hint>*)cppOut) = ::QFlags<Phonon::EffectParameter::Hint>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_Phonon_EffectParameter_Hint_PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX]))
        return Phonon_EffectParameter_Hint_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_;
    return 0;
}
static void number_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<Phonon::EffectParameter::Hint>*)cppOut) = ::QFlags<Phonon::EffectParameter::Hint>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void EffectParameter_PythonToCpp_EffectParameter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_EffectParameter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_EffectParameter_PythonToCpp_EffectParameter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_EffectParameter_Type))
        return EffectParameter_PythonToCpp_EffectParameter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* EffectParameter_PTR_CppToPython_EffectParameter(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::EffectParameter*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_EffectParameter_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* EffectParameter_COPY_CppToPython_EffectParameter(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_Phonon_EffectParameter_Type, new ::Phonon::EffectParameter(*((::Phonon::EffectParameter*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void EffectParameter_PythonToCpp_EffectParameter_COPY(PyObject* pyIn, void* cppOut) {
    *((::Phonon::EffectParameter*)cppOut) = *((::Phonon::EffectParameter*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_EffectParameter_PythonToCpp_EffectParameter_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_EffectParameter_Type))
        return EffectParameter_PythonToCpp_EffectParameter_COPY;
    return 0;
}

void init_Phonon_EffectParameter(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_EffectParameter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "EffectParameter", "Phonon::EffectParameter",
        &Sbk_Phonon_EffectParameter_Type, &Shiboken::callCppDestructor< ::Phonon::EffectParameter >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_EffectParameter_Type,
        EffectParameter_PythonToCpp_EffectParameter_PTR,
        is_EffectParameter_PythonToCpp_EffectParameter_PTR_Convertible,
        EffectParameter_PTR_CppToPython_EffectParameter,
        EffectParameter_COPY_CppToPython_EffectParameter);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectParameter");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectParameter*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectParameter&");
    Shiboken::Conversions::registerConverterName(converter, "EffectParameter");
    Shiboken::Conversions::registerConverterName(converter, "EffectParameter*");
    Shiboken::Conversions::registerConverterName(converter, "EffectParameter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::EffectParameter).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        EffectParameter_PythonToCpp_EffectParameter_COPY,
        is_EffectParameter_PythonToCpp_EffectParameter_COPY_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Hint'.
    SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX] = PySide::QFlags::create("Hints", &SbkPySide_phonon_Phonon_EffectParameter_Hint_as_number);
    SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_EffectParameter_Type,
        "Hint",
        "PySide.phonon.Phonon.EffectParameter.Hint",
        "Phonon::EffectParameter::Hint",
        SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX]);
    if (!SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX],
        &Sbk_Phonon_EffectParameter_Type, "ToggledHint", (long) Phonon::EffectParameter::ToggledHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX],
        &Sbk_Phonon_EffectParameter_Type, "LogarithmicHint", (long) Phonon::EffectParameter::LogarithmicHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX],
        &Sbk_Phonon_EffectParameter_Type, "IntegerHint", (long) Phonon::EffectParameter::IntegerHint))
        return ;
    // Register converter for enum 'Phonon::EffectParameter::Hint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX],
            Phonon_EffectParameter_Hint_CppToPython_Phonon_EffectParameter_Hint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_EffectParameter_Hint_PythonToCpp_Phonon_EffectParameter_Hint,
            is_Phonon_EffectParameter_Hint_PythonToCpp_Phonon_EffectParameter_Hint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_EFFECTPARAMETER_HINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::EffectParameter::Hint");
        Shiboken::Conversions::registerConverterName(converter, "EffectParameter::Hint");
        Shiboken::Conversions::registerConverterName(converter, "Hint");
    }
    // Register converter for flag 'QFlags<Phonon::EffectParameter::Hint>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX],
            QFlags_Phonon_EffectParameter_Hint__CppToPython_QFlags_Phonon_EffectParameter_Hint_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_EffectParameter_Hint_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_,
            is_Phonon_EffectParameter_Hint_PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Phonon_EffectParameter_Hint__PythonToCpp_QFlags_Phonon_EffectParameter_Hint_,
            is_QFlags_Phonon_EffectParameter_Hint__PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Phonon_EffectParameter_Hint_,
            is_number_PythonToCpp_QFlags_Phonon_EffectParameter_Hint__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_QFLAGS_PHONON_EFFECTPARAMETER_HINT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<Phonon::EffectParameter::Hint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<EffectParameter::Hint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Hint>");
    }
    // End of 'Hint' enum/flags.


    qRegisterMetaType< ::Phonon::EffectParameter >("EffectParameter");
    qRegisterMetaType< ::Phonon::EffectParameter >("Phonon::EffectParameter");
    qRegisterMetaType< ::Phonon::EffectParameter::Hint >("EffectParameter::Hint");
    qRegisterMetaType< ::Phonon::EffectParameter::Hint >("Phonon::EffectParameter::Hint");
    qRegisterMetaType< ::Phonon::EffectParameter::Hints >("Phonon::EffectParameter::Hints");
}
