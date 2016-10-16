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
#include "pyside_qtxmlpatterns_python.h"

#include "qabstractxmlreceiver_wrapper.h"

// Extra includes
#include <qabstractxmlnodemodel.h>
#include <qabstractxmlreceiver.h>
#include <qxmlname.h>


// Native ---------------------------------------------------------

QAbstractXmlReceiverWrapper::QAbstractXmlReceiverWrapper() : QAbstractXmlReceiver() {
    // ... middle
}

void QAbstractXmlReceiverWrapper::atomicValue(const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "atomicValue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.atomicValue()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::attribute(const QXmlName & name, const QStringRef & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "attribute"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.attribute()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &name),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::characters(const QStringRef & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "characters"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.characters()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::comment(const QString & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "comment"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.comment()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::endDocument()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endDocument"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endDocument()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::endElement()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endElement"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endElement()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::endOfSequence()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "endOfSequence"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endOfSequence()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::namespaceBinding(const QXmlName & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "namespaceBinding"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.namespaceBinding()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::processingInstruction(const QXmlName & target, const QString & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "processingInstruction"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.processingInstruction()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &target),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::startDocument()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startDocument"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startDocument()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::startElement(const QXmlName & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startElement"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startElement()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &name)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::startOfSequence()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startOfSequence"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startOfSequence()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractXmlReceiverWrapper::whitespaceOnly(const QStringRef & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "whitespaceOnly"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractXmlReceiver::whitespaceOnly(value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QAbstractXmlReceiverWrapper::~QAbstractXmlReceiverWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractXmlReceiver_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractXmlReceiver' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractXmlReceiver >()))
        return -1;

    ::QAbstractXmlReceiverWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QAbstractXmlReceiver()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QAbstractXmlReceiverWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractXmlReceiver >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_atomicValue(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: atomicValue(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // atomicValue(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_atomicValue_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // atomicValue(QVariant)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.atomicValue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->atomicValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_atomicValue_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.atomicValue", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_attribute(PyObject* self, PyObject* args)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "attribute", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: attribute(QXmlName,QStringRef)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], (pyArgs[1])))) {
        overloadId = 0; // attribute(QXmlName,QStringRef)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_attribute_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlName cppArg0_local = ::QXmlName();
        ::QXmlName* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QStringRef cppArg1 = ::QStringRef();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // attribute(QXmlName,QStringRef)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.attribute()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->attribute(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_attribute_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName, QStringRef", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlReceiver.attribute", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_characters(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: characters(QStringRef)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], (pyArg)))) {
        overloadId = 0; // characters(QStringRef)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_characters_TypeError;

    // Call function/method
    {
        ::QStringRef cppArg0 = ::QStringRef();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // characters(QStringRef)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.characters()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->characters(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_characters_TypeError:
        const char* overloads[] = {"QStringRef", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.characters", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_comment(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: comment(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // comment(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_comment_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // comment(QString)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.comment()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->comment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_comment_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.comment", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_endDocument(PyObject* self)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endDocument()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endDocument()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_endElement(PyObject* self)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endElement()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endElement()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endElement();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_endOfSequence(PyObject* self)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endOfSequence()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.endOfSequence()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endOfSequence();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_namespaceBinding(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: namespaceBinding(QXmlName)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
        overloadId = 0; // namespaceBinding(QXmlName)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_namespaceBinding_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlName cppArg0_local = ::QXmlName();
        ::QXmlName* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // namespaceBinding(QXmlName)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.namespaceBinding()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->namespaceBinding(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_namespaceBinding_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.namespaceBinding", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_processingInstruction(PyObject* self, PyObject* args)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "processingInstruction", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: processingInstruction(QXmlName,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // processingInstruction(QXmlName,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_processingInstruction_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlName cppArg0_local = ::QXmlName();
        ::QXmlName* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // processingInstruction(QXmlName,QString)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.processingInstruction()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->processingInstruction(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_processingInstruction_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlReceiver.processingInstruction", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_startDocument(PyObject* self)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startDocument()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startDocument()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startDocument();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_startElement(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startElement(QXmlName)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
        overloadId = 0; // startElement(QXmlName)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_startElement_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlName cppArg0_local = ::QXmlName();
        ::QXmlName* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // startElement(QXmlName)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startElement()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startElement(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_startElement_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.startElement", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_startOfSequence(PyObject* self)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startOfSequence()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlReceiver.startOfSequence()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startOfSequence();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractXmlReceiverFunc_whitespaceOnly(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlReceiver* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlReceiver*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: whitespaceOnly(QStringRef)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGREF_IDX], (pyArg)))) {
        overloadId = 0; // whitespaceOnly(QStringRef)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlReceiverFunc_whitespaceOnly_TypeError;

    // Call function/method
    {
        ::QStringRef cppArg0 = ::QStringRef();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // whitespaceOnly(QStringRef)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractXmlReceiver::whitespaceOnly(cppArg0) : cppSelf->whitespaceOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlReceiverFunc_whitespaceOnly_TypeError:
        const char* overloads[] = {"QStringRef", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlReceiver.whitespaceOnly", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractXmlReceiver_methods[] = {
    {"atomicValue", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_atomicValue, METH_O},
    {"attribute", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_attribute, METH_VARARGS},
    {"characters", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_characters, METH_O},
    {"comment", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_comment, METH_O},
    {"endDocument", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_endDocument, METH_NOARGS},
    {"endElement", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_endElement, METH_NOARGS},
    {"endOfSequence", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_endOfSequence, METH_NOARGS},
    {"namespaceBinding", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_namespaceBinding, METH_O},
    {"processingInstruction", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_processingInstruction, METH_VARARGS},
    {"startDocument", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_startDocument, METH_NOARGS},
    {"startElement", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_startElement, METH_O},
    {"startOfSequence", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_startOfSequence, METH_NOARGS},
    {"whitespaceOnly", (PyCFunction)Sbk_QAbstractXmlReceiverFunc_whitespaceOnly, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractXmlReceiver_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractXmlReceiver_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractXmlReceiver_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QAbstractXmlReceiver",
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
    /*tp_traverse*/         Sbk_QAbstractXmlReceiver_traverse,
    /*tp_clear*/            Sbk_QAbstractXmlReceiver_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractXmlReceiver_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractXmlReceiver_Init,
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

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractXmlReceiver_PythonToCpp_QAbstractXmlReceiver_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractXmlReceiver_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractXmlReceiver_PythonToCpp_QAbstractXmlReceiver_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractXmlReceiver_Type))
        return QAbstractXmlReceiver_PythonToCpp_QAbstractXmlReceiver_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractXmlReceiver_PTR_CppToPython_QAbstractXmlReceiver(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAbstractXmlReceiver*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAbstractXmlReceiver_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QAbstractXmlReceiver(PyObject* module)
{
    SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractXmlReceiver_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractXmlReceiver", "QAbstractXmlReceiver*",
        &Sbk_QAbstractXmlReceiver_Type, &Shiboken::callCppDestructor< ::QAbstractXmlReceiver >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractXmlReceiver_Type,
        QAbstractXmlReceiver_PythonToCpp_QAbstractXmlReceiver_PTR,
        is_QAbstractXmlReceiver_PythonToCpp_QAbstractXmlReceiver_PTR_Convertible,
        QAbstractXmlReceiver_PTR_CppToPython_QAbstractXmlReceiver);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlReceiver");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlReceiver*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlReceiver&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractXmlReceiver).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractXmlReceiverWrapper).name());



}
