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
#include "pyside_qtxml_python.h"

#include "qxmlreader_wrapper.h"

// Extra includes
#include <qxml.h>


// Native ---------------------------------------------------------

QXmlDTDHandler * QXmlReaderWrapper::DTDHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlDTDHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "DTDHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.DTDHandler()' not implemented.");
        return ((::QXmlDTDHandler*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlDTDHandler*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDTDHANDLER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.DTDHandler", Shiboken::SbkType< QXmlDTDHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlDTDHandler*)0);
    }
    ::QXmlDTDHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlReaderWrapper::QXmlReaderWrapper() : QXmlReader() {
    // ... middle
}

QXmlContentHandler * QXmlReaderWrapper::contentHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlContentHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contentHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.contentHandler()' not implemented.");
        return ((::QXmlContentHandler*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlContentHandler*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLCONTENTHANDLER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.contentHandler", Shiboken::SbkType< QXmlContentHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlContentHandler*)0);
    }
    ::QXmlContentHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlDeclHandler * QXmlReaderWrapper::declHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlDeclHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "declHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.declHandler()' not implemented.");
        return ((::QXmlDeclHandler*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlDeclHandler*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDECLHANDLER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.declHandler", Shiboken::SbkType< QXmlDeclHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlDeclHandler*)0);
    }
    ::QXmlDeclHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlEntityResolver * QXmlReaderWrapper::entityResolver() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlEntityResolver*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "entityResolver"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.entityResolver()' not implemented.");
        return ((::QXmlEntityResolver*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlEntityResolver*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLENTITYRESOLVER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.entityResolver", Shiboken::SbkType< QXmlEntityResolver >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlEntityResolver*)0);
    }
    ::QXmlEntityResolver* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlErrorHandler * QXmlReaderWrapper::errorHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlErrorHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "errorHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.errorHandler()' not implemented.");
        return ((::QXmlErrorHandler*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlErrorHandler*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.errorHandler", Shiboken::SbkType< QXmlErrorHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlErrorHandler*)0);
    }
    ::QXmlErrorHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlReaderWrapper::feature(const QString & name, bool * ok) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "feature"));
    if (pyOverride.isNull()) {

        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.feature()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
        // Check return type
    bool typeIsValid = PySequence_Check(pyResult);
    if (!typeIsValid) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.feature", "PySequence", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    // Begin code injection

    // TEMPLATE - fix_virtual_method_return_value_and_bool* - START
    Shiboken::AutoDecRef _py_ret_(PySequence_GetItem(pyResult, 0));
    Shiboken::AutoDecRef _py_ok_(PySequence_GetItem(pyResult, 1));
    bool cppResult;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), _py_ret_, &(cppResult));
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), _py_ok_, (ok));
    // TEMPLATE - fix_virtual_method_return_value_and_bool* - END

    // End of code injection

    return cppResult;
}

bool QXmlReaderWrapper::hasFeature(const QString & name) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasFeature"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.hasFeature()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.hasFeature", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlReaderWrapper::hasProperty(const QString & name) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasProperty"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.hasProperty()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.hasProperty", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlLexicalHandler * QXmlReaderWrapper::lexicalHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlLexicalHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "lexicalHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.lexicalHandler()' not implemented.");
        return ((::QXmlLexicalHandler*)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlLexicalHandler*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLLEXICALHANDLER_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.lexicalHandler", Shiboken::SbkType< QXmlLexicalHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlLexicalHandler*)0);
    }
    ::QXmlLexicalHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlReaderWrapper::parse(const QXmlInputSource & input)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parse"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.parse()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], &input)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.parse", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlReaderWrapper::parse(const QXmlInputSource * input)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parse"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.parse()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], input)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.parse", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

void * QXmlReaderWrapper::property(const QString & name, bool * ok) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((void*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "property"));
    if (pyOverride.isNull()) {

        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.property()' not implemented.");
        return ((void*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((void*)0);
    }
    // Check return type
        // Check return type
    bool typeIsValid = PySequence_Check(pyResult);
    if (!typeIsValid) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlReader.property", "PySequence", pyResult->ob_type->tp_name);
        return ((void*)0);
    }
    // Begin code injection

    // TEMPLATE - fix_virtual_method_return_value_and_bool* - START
    Shiboken::AutoDecRef _py_ret_(PySequence_GetItem(pyResult, 0));
    Shiboken::AutoDecRef _py_ok_(PySequence_GetItem(pyResult, 1));
    void* cppResult;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), _py_ret_, &(cppResult));
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), _py_ok_, (ok));
    // TEMPLATE - fix_virtual_method_return_value_and_bool* - END

    // End of code injection

    return cppResult;
}

void QXmlReaderWrapper::setContentHandler(QXmlContentHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setContentHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setContentHandler()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLCONTENTHANDLER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setDTDHandler(QXmlDTDHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDTDHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setDTDHandler()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDTDHANDLER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setDeclHandler(QXmlDeclHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDeclHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setDeclHandler()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDECLHANDLER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setEntityResolver(QXmlEntityResolver * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setEntityResolver"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setEntityResolver()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLENTITYRESOLVER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setErrorHandler(QXmlErrorHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setErrorHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setErrorHandler()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setFeature(const QString & name, bool value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFeature"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setFeature()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setLexicalHandler(QXmlLexicalHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setLexicalHandler"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setLexicalHandler()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLLEXICALHANDLER_IDX], handler)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QXmlReaderWrapper::setProperty(const QString & name, void * value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setProperty"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setProperty()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &name),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QXmlReaderWrapper::~QXmlReaderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QXmlReaderFunc_DTDHandler(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // DTDHandler()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.DTDHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlDTDHandler * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->DTDHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDTDHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static int
Sbk_QXmlReader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QXmlReader' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlReader >()))
        return -1;

    ::QXmlReaderWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QXmlReader()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QXmlReaderWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlReader >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QXmlReaderFunc_contentHandler(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contentHandler()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.contentHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlContentHandler * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->contentHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLCONTENTHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlReaderFunc_declHandler(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // declHandler()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.declHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlDeclHandler * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->declHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDECLHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlReaderFunc_entityResolver(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // entityResolver()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.entityResolver()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlEntityResolver * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->entityResolver();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLENTITYRESOLVER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlReaderFunc_errorHandler(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorHandler()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.errorHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlErrorHandler * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->errorHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlReaderFunc_feature(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: feature(QString,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // feature(QString,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_feature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // feature(QString,bool*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.feature()' not implemented.");
                return 0;
            }
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool retval_ = cppSelf->feature(cppArg0, &ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &retval_));
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

    Sbk_QXmlReaderFunc_feature_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.feature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_hasFeature(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasFeature(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasFeature(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_hasFeature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasFeature(QString)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.hasFeature()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlReader*>(cppSelf)->hasFeature(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlReaderFunc_hasFeature_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.hasFeature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_hasProperty(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasProperty(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasProperty(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_hasProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasProperty(QString)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.hasProperty()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QXmlReader*>(cppSelf)->hasProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlReaderFunc_hasProperty_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.hasProperty", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_lexicalHandler(PyObject* self)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lexicalHandler()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.lexicalHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlLexicalHandler * cppResult = const_cast<const ::QXmlReader*>(cppSelf)->lexicalHandler();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLLEXICALHANDLER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QXmlReaderFunc_parse(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: parse(QXmlInputSource)
    // 1: parse(const QXmlInputSource*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], (pyArg)))) {
        overloadId = 0; // parse(QXmlInputSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_parse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // parse(const QXmlInputSource & input)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // parse(QXmlInputSource)
                if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                    PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.parse()' not implemented.");
                    return 0;
                }
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->parse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // parse(const QXmlInputSource * input)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // parse(const QXmlInputSource*)
                if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                    PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.parse()' not implemented.");
                    return 0;
                }
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->parse(cppArg0);
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

    Sbk_QXmlReaderFunc_parse_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlInputSource", "PySide.QtXml.QXmlInputSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.parse", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(QString,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // property(QString,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_property_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(QString,bool*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.property()' not implemented.");
                return 0;
            }
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * retval_ = cppSelf->property(cppArg0, &ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), retval_));
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

    Sbk_QXmlReaderFunc_property_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.property", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setContentHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContentHandler(QXmlContentHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLCONTENTHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setContentHandler(QXmlContentHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setContentHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlContentHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContentHandler(QXmlContentHandler*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setContentHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContentHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setContentHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlContentHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setContentHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setDTDHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDTDHandler(QXmlDTDHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDTDHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setDTDHandler(QXmlDTDHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setDTDHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlDTDHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDTDHandler(QXmlDTDHandler*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setDTDHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDTDHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setDTDHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlDTDHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setDTDHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setDeclHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDeclHandler(QXmlDeclHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDECLHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setDeclHandler(QXmlDeclHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setDeclHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlDeclHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDeclHandler(QXmlDeclHandler*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setDeclHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDeclHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setDeclHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlDeclHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setDeclHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setEntityResolver(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEntityResolver(QXmlEntityResolver*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLENTITYRESOLVER_IDX], (pyArg)))) {
        overloadId = 0; // setEntityResolver(QXmlEntityResolver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setEntityResolver_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlEntityResolver* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEntityResolver(QXmlEntityResolver*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setEntityResolver()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEntityResolver(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setEntityResolver_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlEntityResolver", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setEntityResolver", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setErrorHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setErrorHandler(QXmlErrorHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setErrorHandler(QXmlErrorHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setErrorHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlErrorHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setErrorHandler(QXmlErrorHandler*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setErrorHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setErrorHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setErrorHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlErrorHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setErrorHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setFeature(PyObject* self, PyObject* args)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFeature", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFeature(QString,bool)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
        overloadId = 0; // setFeature(QString,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setFeature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFeature(QString,bool)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setFeature()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFeature(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setFeature_TypeError:
        const char* overloads[] = {"unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlReader.setFeature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setLexicalHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLexicalHandler(QXmlLexicalHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLLEXICALHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setLexicalHandler(QXmlLexicalHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setLexicalHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlLexicalHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLexicalHandler(QXmlLexicalHandler*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setLexicalHandler()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLexicalHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setLexicalHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlLexicalHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlReader.setLexicalHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlReaderFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QXmlReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(QString,void*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[1])))) {
        overloadId = 0; // setProperty(QString,void*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlReaderFunc_setProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        void* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProperty(QString,void*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QXmlReader.setProperty()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlReaderFunc_setProperty_TypeError:
        const char* overloads[] = {"unicode, void", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlReader.setProperty", overloads);
        return 0;
}

static PyMethodDef Sbk_QXmlReader_methods[] = {
    {"DTDHandler", (PyCFunction)Sbk_QXmlReaderFunc_DTDHandler, METH_NOARGS},
    {"contentHandler", (PyCFunction)Sbk_QXmlReaderFunc_contentHandler, METH_NOARGS},
    {"declHandler", (PyCFunction)Sbk_QXmlReaderFunc_declHandler, METH_NOARGS},
    {"entityResolver", (PyCFunction)Sbk_QXmlReaderFunc_entityResolver, METH_NOARGS},
    {"errorHandler", (PyCFunction)Sbk_QXmlReaderFunc_errorHandler, METH_NOARGS},
    {"feature", (PyCFunction)Sbk_QXmlReaderFunc_feature, METH_O},
    {"hasFeature", (PyCFunction)Sbk_QXmlReaderFunc_hasFeature, METH_O},
    {"hasProperty", (PyCFunction)Sbk_QXmlReaderFunc_hasProperty, METH_O},
    {"lexicalHandler", (PyCFunction)Sbk_QXmlReaderFunc_lexicalHandler, METH_NOARGS},
    {"parse", (PyCFunction)Sbk_QXmlReaderFunc_parse, METH_O},
    {"property", (PyCFunction)Sbk_QXmlReaderFunc_property, METH_O},
    {"setContentHandler", (PyCFunction)Sbk_QXmlReaderFunc_setContentHandler, METH_O},
    {"setDTDHandler", (PyCFunction)Sbk_QXmlReaderFunc_setDTDHandler, METH_O},
    {"setDeclHandler", (PyCFunction)Sbk_QXmlReaderFunc_setDeclHandler, METH_O},
    {"setEntityResolver", (PyCFunction)Sbk_QXmlReaderFunc_setEntityResolver, METH_O},
    {"setErrorHandler", (PyCFunction)Sbk_QXmlReaderFunc_setErrorHandler, METH_O},
    {"setFeature", (PyCFunction)Sbk_QXmlReaderFunc_setFeature, METH_VARARGS},
    {"setLexicalHandler", (PyCFunction)Sbk_QXmlReaderFunc_setLexicalHandler, METH_O},
    {"setProperty", (PyCFunction)Sbk_QXmlReaderFunc_setProperty, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlReader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlReader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlReader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlReader",
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
    /*tp_traverse*/         Sbk_QXmlReader_traverse,
    /*tp_clear*/            Sbk_QXmlReader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlReader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlReader_Init,
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
static void QXmlReader_PythonToCpp_QXmlReader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlReader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlReader_PythonToCpp_QXmlReader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlReader_Type))
        return QXmlReader_PythonToCpp_QXmlReader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlReader_PTR_CppToPython_QXmlReader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlReader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlReader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlReader(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlReader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlReader", "QXmlReader*",
        &Sbk_QXmlReader_Type, &Shiboken::callCppDestructor< ::QXmlReader >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlReader_Type,
        QXmlReader_PythonToCpp_QXmlReader_PTR,
        is_QXmlReader_PythonToCpp_QXmlReader_PTR_Convertible,
        QXmlReader_PTR_CppToPython_QXmlReader);

    Shiboken::Conversions::registerConverterName(converter, "QXmlReader");
    Shiboken::Conversions::registerConverterName(converter, "QXmlReader*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlReader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlReader).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlReaderWrapper).name());



}
