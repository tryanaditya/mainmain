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

#include "qscriptclass_wrapper.h"

// Extra includes
#include <qscriptclass.h>
#include <qscriptclasspropertyiterator.h>
#include <qscriptengine.h>
#include <qscriptstring.h>
#include <qscriptvalue.h>


// Native ---------------------------------------------------------

QScriptClassWrapper::QScriptClassWrapper(QScriptEngine * engine) : QScriptClass(engine) {
    // ... middle
}

QVariant QScriptClassWrapper::extension(QScriptClass::Extension extension, const QVariant & argument)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "extension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::extension(extension, argument);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX]), &extension),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &argument)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.extension", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QString QScriptClassWrapper::name() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "name"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::name();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.name", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QScriptClassPropertyIterator * QScriptClassWrapper::newIterator(const QScriptValue & object)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QScriptClassPropertyIterator*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "newIterator"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::newIterator(object);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &object)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QScriptClassPropertyIterator*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASSPROPERTYITERATOR_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.newIterator", Shiboken::SbkType< QScriptClassPropertyIterator >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QScriptClassPropertyIterator*)0);
    }
    ::QScriptClassPropertyIterator* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QScriptValue QScriptClassWrapper::property(const QScriptValue & object, const QScriptString & name, uint id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QScriptValue();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "property"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::property(object, name, id);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNI)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &object),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], &name),
        id
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QScriptValue();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.property", Shiboken::SbkType< QScriptValue >()->tp_name, pyResult->ob_type->tp_name);
        return ::QScriptValue();
    }
    ::QScriptValue cppResult = ::QScriptValue();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QFlags<QScriptValue::PropertyFlag> QScriptClassWrapper::propertyFlags(const QScriptValue & object, const QScriptString & name, uint id)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QScriptValue::PropertyFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "propertyFlags"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::propertyFlags(object, name, id);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNI)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &object),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], &name),
        id
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<QScriptValue::PropertyFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.propertyFlags", Shiboken::SbkType< QFlags<QScriptValue::PropertyFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QScriptValue::PropertyFlag>)0);
    }
    ::QFlags<QScriptValue::PropertyFlag> cppResult = ((::QFlags<QScriptValue::PropertyFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QScriptValue QScriptClassWrapper::prototype() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QScriptValue();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "prototype"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::prototype();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QScriptValue();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.prototype", Shiboken::SbkType< QScriptValue >()->tp_name, pyResult->ob_type->tp_name);
        return ::QScriptValue();
    }
    ::QScriptValue cppResult = ::QScriptValue();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QScriptClassWrapper::setProperty(QScriptValue & object, const QScriptString & name, uint id, const QScriptValue & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setProperty"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::setProperty(object, name, id, value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNIN)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &object),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], &name),
        id,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QScriptClassWrapper::supportsExtension(QScriptClass::Extension extension) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "supportsExtension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QScriptClass::supportsExtension(extension);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX]), &extension)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptClass.supportsExtension", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QScriptClassWrapper::~QScriptClassWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptClass_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptClass >()))
        return -1;

    ::QScriptClassWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QScriptClass", 1, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptClass(QScriptEngine*)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (pyArgs[0])))) {
        overloadId = 0; // QScriptClass(QScriptEngine*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClass_Init_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QScriptEngine* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QScriptClass(QScriptEngine*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QScriptClassWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptClass >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptClass_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QScriptClass_Init_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngine", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptClass", overloads);
        return -1;
}

static PyObject* Sbk_QScriptClassFunc_engine(PyObject* self)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // engine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngine * cppResult = const_cast<const ::QScriptClass*>(cppSelf)->engine();
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

static PyObject* Sbk_QScriptClassFunc_extension(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptClass.extension(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptClass.extension(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:extension", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: extension(QScriptClass::Extension,QVariant)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // extension(QScriptClass::Extension,QVariant)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
            overloadId = 0; // extension(QScriptClass::Extension,QVariant)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_extension_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "argument");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptClass.extension(): got multiple values for keyword argument 'argument'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1]))))
                    goto Sbk_QScriptClassFunc_extension_TypeError;
            }
        }
        ::QScriptClass::Extension cppArg0 = ((::QScriptClass::Extension)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = QVariant();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // extension(QScriptClass::Extension,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptClass::extension(cppArg0, cppArg1) : cppSelf->extension(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptClassFunc_extension_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptClass.Extension, QVariant = QVariant()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptClass.extension", overloads);
        return 0;
}

static PyObject* Sbk_QScriptClassFunc_name(PyObject* self)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QScriptClass*>(cppSelf)->::QScriptClass::name() : const_cast<const ::QScriptClass*>(cppSelf)->name();
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

static PyObject* Sbk_QScriptClassFunc_newIterator(PyObject* self, PyObject* pyArg)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: newIterator(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // newIterator(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_newIterator_TypeError;

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
            // newIterator(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptClassPropertyIterator * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptClass::newIterator(*cppArg0) : cppSelf->newIterator(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASSPROPERTYITERATOR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptClassFunc_newIterator_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptClass.newIterator", overloads);
        return 0;
}

static PyObject* Sbk_QScriptClassFunc_property(PyObject* self, PyObject* args)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "property", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: property(QScriptValue,QScriptString,uint)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[2])))) {
        overloadId = 0; // property(QScriptValue,QScriptString,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_property_TypeError;

    // Call function/method
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
        ::QScriptString cppArg1_local = ::QScriptString();
        ::QScriptString* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        uint cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // property(QScriptValue,QScriptString,uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptClass::property(*cppArg0, *cppArg1, cppArg2) : cppSelf->property(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptClassFunc_property_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue, PySide.QtScript.QScriptString, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptClass.property", overloads);
        return 0;
}

static PyObject* Sbk_QScriptClassFunc_propertyFlags(PyObject* self, PyObject* args)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "propertyFlags", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: propertyFlags(QScriptValue,QScriptString,uint)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[2])))) {
        overloadId = 0; // propertyFlags(QScriptValue,QScriptString,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_propertyFlags_TypeError;

    // Call function/method
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
        ::QScriptString cppArg1_local = ::QScriptString();
        ::QScriptString* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        uint cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // propertyFlags(QScriptValue,QScriptString,uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QScriptValue::PropertyFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptClass::propertyFlags(*cppArg0, *cppArg1, cppArg2) : cppSelf->propertyFlags(*cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTVALUE_PROPERTYFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptClassFunc_propertyFlags_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue, PySide.QtScript.QScriptString, unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptClass.propertyFlags", overloads);
        return 0;
}

static PyObject* Sbk_QScriptClassFunc_prototype(PyObject* self)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prototype()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QScriptClass*>(cppSelf)->::QScriptClass::prototype() : const_cast<const ::QScriptClass*>(cppSelf)->prototype();
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

static PyObject* Sbk_QScriptClassFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(QScriptValue&,QScriptString,uint,QScriptValue)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[3])))) {
        overloadId = 0; // setProperty(QScriptValue&,QScriptString,uint,QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_setProperty_TypeError;

    // Call function/method
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
        ::QScriptString cppArg1_local = ::QScriptString();
        ::QScriptString* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        uint cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QScriptValue cppArg3_local = ::QScriptValue();
        ::QScriptValue* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);


        if (!PyErr_Occurred()) {
            // setProperty(QScriptValue&,QScriptString,uint,QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QScriptClass::setProperty(*cppArg0, *cppArg1, cppArg2, *cppArg3) : cppSelf->setProperty(*cppArg0, *cppArg1, cppArg2, *cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptClassFunc_setProperty_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue, PySide.QtScript.QScriptString, unsigned int, PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptClass.setProperty", overloads);
        return 0;
}

static PyObject* Sbk_QScriptClassFunc_supportsExtension(PyObject* self, PyObject* pyArg)
{
    ::QScriptClass* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptClass*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: supportsExtension(QScriptClass::Extension)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX]), (pyArg)))) {
        overloadId = 0; // supportsExtension(QScriptClass::Extension)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptClassFunc_supportsExtension_TypeError;

    // Call function/method
    {
        ::QScriptClass::Extension cppArg0 = ((::QScriptClass::Extension)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // supportsExtension(QScriptClass::Extension)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QScriptClass*>(cppSelf)->::QScriptClass::supportsExtension(cppArg0) : const_cast<const ::QScriptClass*>(cppSelf)->supportsExtension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptClassFunc_supportsExtension_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptClass.Extension", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptClass.supportsExtension", overloads);
        return 0;
}

static PyMethodDef Sbk_QScriptClass_methods[] = {
    {"engine", (PyCFunction)Sbk_QScriptClassFunc_engine, METH_NOARGS},
    {"extension", (PyCFunction)Sbk_QScriptClassFunc_extension, METH_VARARGS|METH_KEYWORDS},
    {"name", (PyCFunction)Sbk_QScriptClassFunc_name, METH_NOARGS},
    {"newIterator", (PyCFunction)Sbk_QScriptClassFunc_newIterator, METH_O},
    {"property", (PyCFunction)Sbk_QScriptClassFunc_property, METH_VARARGS},
    {"propertyFlags", (PyCFunction)Sbk_QScriptClassFunc_propertyFlags, METH_VARARGS},
    {"prototype", (PyCFunction)Sbk_QScriptClassFunc_prototype, METH_NOARGS},
    {"setProperty", (PyCFunction)Sbk_QScriptClassFunc_setProperty, METH_VARARGS},
    {"supportsExtension", (PyCFunction)Sbk_QScriptClassFunc_supportsExtension, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QScriptClass_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptClass_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QScriptClass_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptClass",
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
    /*tp_traverse*/         Sbk_QScriptClass_traverse,
    /*tp_clear*/            Sbk_QScriptClass_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptClass_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptClass_Init,
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
static void QScriptClass_QueryFlag_PythonToCpp_QScriptClass_QueryFlag(PyObject* pyIn, void* cppOut) {
    *((::QScriptClass::QueryFlag*)cppOut) = (::QScriptClass::QueryFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptClass_QueryFlag_PythonToCpp_QScriptClass_QueryFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX]))
        return QScriptClass_QueryFlag_PythonToCpp_QScriptClass_QueryFlag;
    return 0;
}
static PyObject* QScriptClass_QueryFlag_CppToPython_QScriptClass_QueryFlag(const void* cppIn) {
    int castCppIn = *((::QScriptClass::QueryFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX], castCppIn);

}

static void QScriptClass_Extension_PythonToCpp_QScriptClass_Extension(PyObject* pyIn, void* cppOut) {
    *((::QScriptClass::Extension*)cppOut) = (::QScriptClass::Extension) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptClass_Extension_PythonToCpp_QScriptClass_Extension_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX]))
        return QScriptClass_Extension_PythonToCpp_QScriptClass_Extension;
    return 0;
}
static PyObject* QScriptClass_Extension_CppToPython_QScriptClass_Extension(const void* cppIn) {
    int castCppIn = *((::QScriptClass::Extension*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptClass_PythonToCpp_QScriptClass_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptClass_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptClass_PythonToCpp_QScriptClass_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptClass_Type))
        return QScriptClass_PythonToCpp_QScriptClass_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptClass_PTR_CppToPython_QScriptClass(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QScriptClass*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QScriptClass_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QScriptClass(PyObject* module)
{
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptClass_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptClass", "QScriptClass*",
        &Sbk_QScriptClass_Type, &Shiboken::callCppDestructor< ::QScriptClass >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptClass_Type,
        QScriptClass_PythonToCpp_QScriptClass_PTR,
        is_QScriptClass_PythonToCpp_QScriptClass_PTR_Convertible,
        QScriptClass_PTR_CppToPython_QScriptClass);

    Shiboken::Conversions::registerConverterName(converter, "QScriptClass");
    Shiboken::Conversions::registerConverterName(converter, "QScriptClass*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptClass&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptClass).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptClassWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'QueryFlag'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptClass_Type,
        "QueryFlag",
        "PySide.QtScript.QScriptClass.QueryFlag",
        "QScriptClass::QueryFlag");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX],
        &Sbk_QScriptClass_Type, "HandlesReadAccess", (long) QScriptClass::HandlesReadAccess))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX],
        &Sbk_QScriptClass_Type, "HandlesWriteAccess", (long) QScriptClass::HandlesWriteAccess))
        return ;
    // Register converter for enum 'QScriptClass::QueryFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX],
            QScriptClass_QueryFlag_CppToPython_QScriptClass_QueryFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptClass_QueryFlag_PythonToCpp_QScriptClass_QueryFlag,
            is_QScriptClass_QueryFlag_PythonToCpp_QScriptClass_QueryFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_QUERYFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptClass::QueryFlag");
        Shiboken::Conversions::registerConverterName(converter, "QueryFlag");
    }
    // End of 'QueryFlag' enum.

    // Initialization of enum 'Extension'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptClass_Type,
        "Extension",
        "PySide.QtScript.QScriptClass.Extension",
        "QScriptClass::Extension");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX],
        &Sbk_QScriptClass_Type, "Callable", (long) QScriptClass::Callable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX],
        &Sbk_QScriptClass_Type, "HasInstance", (long) QScriptClass::HasInstance))
        return ;
    // Register converter for enum 'QScriptClass::Extension'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX],
            QScriptClass_Extension_CppToPython_QScriptClass_Extension);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptClass_Extension_PythonToCpp_QScriptClass_Extension,
            is_QScriptClass_Extension_PythonToCpp_QScriptClass_Extension_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_EXTENSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptClass::Extension");
        Shiboken::Conversions::registerConverterName(converter, "Extension");
    }
    // End of 'Extension' enum.


    qRegisterMetaType< ::QScriptClass::QueryFlag >("QScriptClass::QueryFlag");
    qRegisterMetaType< ::QScriptClass::Extension >("QScriptClass::Extension");
}
