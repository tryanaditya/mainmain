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

#include "qxmlsimplereader_wrapper.h"

// Extra includes
#include <qxml.h>


// Native ---------------------------------------------------------

QXmlDTDHandler * QXmlSimpleReaderWrapper::DTDHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlDTDHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "DTDHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::DTDHandler();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.DTDHandler", Shiboken::SbkType< QXmlDTDHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlDTDHandler*)0);
    }
    ::QXmlDTDHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlSimpleReaderWrapper::QXmlSimpleReaderWrapper() : QXmlSimpleReader() {
    // ... middle
}

QXmlContentHandler * QXmlSimpleReaderWrapper::contentHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlContentHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contentHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::contentHandler();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.contentHandler", Shiboken::SbkType< QXmlContentHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlContentHandler*)0);
    }
    ::QXmlContentHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlDeclHandler * QXmlSimpleReaderWrapper::declHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlDeclHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "declHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::declHandler();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.declHandler", Shiboken::SbkType< QXmlDeclHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlDeclHandler*)0);
    }
    ::QXmlDeclHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlEntityResolver * QXmlSimpleReaderWrapper::entityResolver() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlEntityResolver*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "entityResolver"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::entityResolver();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.entityResolver", Shiboken::SbkType< QXmlEntityResolver >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlEntityResolver*)0);
    }
    ::QXmlEntityResolver* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlErrorHandler * QXmlSimpleReaderWrapper::errorHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlErrorHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "errorHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::errorHandler();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.errorHandler", Shiboken::SbkType< QXmlErrorHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlErrorHandler*)0);
    }
    ::QXmlErrorHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlSimpleReaderWrapper::feature(const QString & name, bool * ok) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "feature"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QXmlSimpleReader::feature(name, ok);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.feature", "PySequence", pyResult->ob_type->tp_name);
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

bool QXmlSimpleReaderWrapper::hasFeature(const QString & name) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasFeature"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::hasFeature(name);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.hasFeature", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlSimpleReaderWrapper::hasProperty(const QString & name) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasProperty"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::hasProperty(name);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.hasProperty", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlLexicalHandler * QXmlSimpleReaderWrapper::lexicalHandler() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlLexicalHandler*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "lexicalHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::lexicalHandler();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.lexicalHandler", Shiboken::SbkType< QXmlLexicalHandler >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlLexicalHandler*)0);
    }
    ::QXmlLexicalHandler* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlSimpleReaderWrapper::parse(const QXmlInputSource & input)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::parse(input);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.parse", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QXmlSimpleReaderWrapper::parse(const QXmlInputSource * input)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::parse(input);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.parse", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QXmlSimpleReaderWrapper::parse(const QXmlInputSource * input, bool incremental)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::parse(input, incremental);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], input),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &incremental)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.parse", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QXmlSimpleReaderWrapper::parseContinue()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "parseContinue"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::parseContinue();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.parseContinue", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void * QXmlSimpleReaderWrapper::property(const QString & name, bool * ok) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((void*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "property"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QXmlSimpleReader::property(name, ok);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QXmlSimpleReader.property", "PySequence", pyResult->ob_type->tp_name);
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

void QXmlSimpleReaderWrapper::setContentHandler(QXmlContentHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setContentHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setContentHandler(handler);
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

void QXmlSimpleReaderWrapper::setDTDHandler(QXmlDTDHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDTDHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setDTDHandler(handler);
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

void QXmlSimpleReaderWrapper::setDeclHandler(QXmlDeclHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setDeclHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setDeclHandler(handler);
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

void QXmlSimpleReaderWrapper::setEntityResolver(QXmlEntityResolver * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setEntityResolver"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setEntityResolver(handler);
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

void QXmlSimpleReaderWrapper::setErrorHandler(QXmlErrorHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setErrorHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setErrorHandler(handler);
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

void QXmlSimpleReaderWrapper::setFeature(const QString & name, bool value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setFeature"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setFeature(name, value);
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

void QXmlSimpleReaderWrapper::setLexicalHandler(QXmlLexicalHandler * handler)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setLexicalHandler"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setLexicalHandler(handler);
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

void QXmlSimpleReaderWrapper::setProperty(const QString & name, void * value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setProperty"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QXmlSimpleReader::setProperty(name, value);
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

QXmlSimpleReaderWrapper::~QXmlSimpleReaderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QXmlSimpleReaderFunc_DTDHandler(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // DTDHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlDTDHandler * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::DTDHandler() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->DTDHandler();
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
Sbk_QXmlSimpleReader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QXmlSimpleReader >()))
        return -1;

    ::QXmlSimpleReaderWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QXmlSimpleReader()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QXmlSimpleReaderWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QXmlSimpleReader >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_contentHandler(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contentHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlContentHandler * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::contentHandler() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->contentHandler();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_declHandler(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // declHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlDeclHandler * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::declHandler() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->declHandler();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_entityResolver(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // entityResolver()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlEntityResolver * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::entityResolver() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->entityResolver();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_errorHandler(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // errorHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlErrorHandler * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::errorHandler() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->errorHandler();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_feature(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_feature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // feature(QString,bool*)const
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool retval_ = (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::feature(cppArg0, &ok_) : cppSelf->feature(cppArg0, &ok_));
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

    Sbk_QXmlSimpleReaderFunc_feature_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.feature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_hasFeature(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_hasFeature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasFeature(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::hasFeature(cppArg0) : const_cast<const ::QXmlSimpleReader*>(cppSelf)->hasFeature(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlSimpleReaderFunc_hasFeature_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.hasFeature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_hasProperty(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_hasProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasProperty(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::hasProperty(cppArg0) : const_cast<const ::QXmlSimpleReader*>(cppSelf)->hasProperty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QXmlSimpleReaderFunc_hasProperty_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.hasProperty", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_lexicalHandler(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lexicalHandler()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlLexicalHandler * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QXmlSimpleReader*>(cppSelf)->::QXmlSimpleReader::lexicalHandler() : const_cast<const ::QXmlSimpleReader*>(cppSelf)->lexicalHandler();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_parse(PyObject* self, PyObject* args)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "parse", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: parse(QXmlInputSource)
    // 1: parse(const QXmlInputSource*)
    // 2: parse(const QXmlInputSource*,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLINPUTSOURCE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // parse(QXmlInputSource)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 2; // parse(const QXmlInputSource*,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_parse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // parse(const QXmlInputSource & input)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // parse(QXmlInputSource)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::parse(*cppArg0) : cppSelf->parse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // parse(const QXmlInputSource * input)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // parse(const QXmlInputSource*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::parse(cppArg0) : cppSelf->parse(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // parse(const QXmlInputSource * input, bool incremental)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QXmlInputSource* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            bool cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // parse(const QXmlInputSource*,bool)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::parse(cppArg0, cppArg1) : cppSelf->parse(cppArg0, cppArg1);
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

    Sbk_QXmlSimpleReaderFunc_parse_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlInputSource", "PySide.QtXml.QXmlInputSource", "PySide.QtXml.QXmlInputSource, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlSimpleReader.parse", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_parseContinue(PyObject* self)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parseContinue()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::parseContinue() : cppSelf->parseContinue();
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

static PyObject* Sbk_QXmlSimpleReaderFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_property_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(QString,bool*)const
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            void * retval_ = (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::property(cppArg0, &ok_) : cppSelf->property(cppArg0, &ok_));
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

    Sbk_QXmlSimpleReaderFunc_property_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.property", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setContentHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContentHandler(QXmlContentHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLCONTENTHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setContentHandler(QXmlContentHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setContentHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlContentHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContentHandler(QXmlContentHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setContentHandler(cppArg0) : cppSelf->setContentHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setContentHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlContentHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setContentHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setDTDHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDTDHandler(QXmlDTDHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDTDHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setDTDHandler(QXmlDTDHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setDTDHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlDTDHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDTDHandler(QXmlDTDHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setDTDHandler(cppArg0) : cppSelf->setDTDHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setDTDHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlDTDHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setDTDHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setDeclHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDeclHandler(QXmlDeclHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLDECLHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setDeclHandler(QXmlDeclHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setDeclHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlDeclHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDeclHandler(QXmlDeclHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setDeclHandler(cppArg0) : cppSelf->setDeclHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setDeclHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlDeclHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setDeclHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setEntityResolver(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEntityResolver(QXmlEntityResolver*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLENTITYRESOLVER_IDX], (pyArg)))) {
        overloadId = 0; // setEntityResolver(QXmlEntityResolver*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setEntityResolver_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlEntityResolver* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEntityResolver(QXmlEntityResolver*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setEntityResolver(cppArg0) : cppSelf->setEntityResolver(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setEntityResolver_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlEntityResolver", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setEntityResolver", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setErrorHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setErrorHandler(QXmlErrorHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLERRORHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setErrorHandler(QXmlErrorHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setErrorHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlErrorHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setErrorHandler(QXmlErrorHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setErrorHandler(cppArg0) : cppSelf->setErrorHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setErrorHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlErrorHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setErrorHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setFeature(PyObject* self, PyObject* args)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setFeature_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFeature(QString,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setFeature(cppArg0, cppArg1) : cppSelf->setFeature(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setFeature_TypeError:
        const char* overloads[] = {"unicode, bool", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlSimpleReader.setFeature", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setLexicalHandler(PyObject* self, PyObject* pyArg)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLexicalHandler(QXmlLexicalHandler*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLLEXICALHANDLER_IDX], (pyArg)))) {
        overloadId = 0; // setLexicalHandler(QXmlLexicalHandler*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setLexicalHandler_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlLexicalHandler* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLexicalHandler(QXmlLexicalHandler*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setLexicalHandler(cppArg0) : cppSelf->setLexicalHandler(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setLexicalHandler_TypeError:
        const char* overloads[] = {"PySide.QtXml.QXmlLexicalHandler", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXml.QXmlSimpleReader.setLexicalHandler", overloads);
        return 0;
}

static PyObject* Sbk_QXmlSimpleReaderFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QXmlSimpleReader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QXmlSimpleReader*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QXmlSimpleReaderFunc_setProperty_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        void* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProperty(QString,void*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QXmlSimpleReader::setProperty(cppArg0, cppArg1) : cppSelf->setProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QXmlSimpleReaderFunc_setProperty_TypeError:
        const char* overloads[] = {"unicode, void", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXml.QXmlSimpleReader.setProperty", overloads);
        return 0;
}

static PyMethodDef Sbk_QXmlSimpleReader_methods[] = {
    {"DTDHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_DTDHandler, METH_NOARGS},
    {"contentHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_contentHandler, METH_NOARGS},
    {"declHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_declHandler, METH_NOARGS},
    {"entityResolver", (PyCFunction)Sbk_QXmlSimpleReaderFunc_entityResolver, METH_NOARGS},
    {"errorHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_errorHandler, METH_NOARGS},
    {"feature", (PyCFunction)Sbk_QXmlSimpleReaderFunc_feature, METH_O},
    {"hasFeature", (PyCFunction)Sbk_QXmlSimpleReaderFunc_hasFeature, METH_O},
    {"hasProperty", (PyCFunction)Sbk_QXmlSimpleReaderFunc_hasProperty, METH_O},
    {"lexicalHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_lexicalHandler, METH_NOARGS},
    {"parse", (PyCFunction)Sbk_QXmlSimpleReaderFunc_parse, METH_VARARGS},
    {"parseContinue", (PyCFunction)Sbk_QXmlSimpleReaderFunc_parseContinue, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QXmlSimpleReaderFunc_property, METH_O},
    {"setContentHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setContentHandler, METH_O},
    {"setDTDHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setDTDHandler, METH_O},
    {"setDeclHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setDeclHandler, METH_O},
    {"setEntityResolver", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setEntityResolver, METH_O},
    {"setErrorHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setErrorHandler, METH_O},
    {"setFeature", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setFeature, METH_VARARGS},
    {"setLexicalHandler", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setLexicalHandler, METH_O},
    {"setProperty", (PyCFunction)Sbk_QXmlSimpleReaderFunc_setProperty, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QXmlSimpleReader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QXmlSimpleReader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QXmlSimpleReader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXml.QXmlSimpleReader",
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
    /*tp_traverse*/         Sbk_QXmlSimpleReader_traverse,
    /*tp_clear*/            Sbk_QXmlSimpleReader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QXmlSimpleReader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QXmlSimpleReader_Init,
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

static void* Sbk_QXmlSimpleReader_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QXmlReader >()))
        return dynamic_cast< ::QXmlSimpleReader*>(reinterpret_cast< ::QXmlReader*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QXmlSimpleReader_PythonToCpp_QXmlSimpleReader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QXmlSimpleReader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QXmlSimpleReader_PythonToCpp_QXmlSimpleReader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QXmlSimpleReader_Type))
        return QXmlSimpleReader_PythonToCpp_QXmlSimpleReader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QXmlSimpleReader_PTR_CppToPython_QXmlSimpleReader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QXmlSimpleReader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QXmlSimpleReader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QXmlSimpleReader(PyObject* module)
{
    SbkPySide_QtXmlTypes[SBK_QXMLSIMPLEREADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QXmlSimpleReader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QXmlSimpleReader", "QXmlSimpleReader*",
        &Sbk_QXmlSimpleReader_Type, &Shiboken::callCppDestructor< ::QXmlSimpleReader >, (SbkObjectType*)SbkPySide_QtXmlTypes[SBK_QXMLREADER_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QXmlSimpleReader_Type,
        QXmlSimpleReader_PythonToCpp_QXmlSimpleReader_PTR,
        is_QXmlSimpleReader_PythonToCpp_QXmlSimpleReader_PTR_Convertible,
        QXmlSimpleReader_PTR_CppToPython_QXmlSimpleReader);

    Shiboken::Conversions::registerConverterName(converter, "QXmlSimpleReader");
    Shiboken::Conversions::registerConverterName(converter, "QXmlSimpleReader*");
    Shiboken::Conversions::registerConverterName(converter, "QXmlSimpleReader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlSimpleReader).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QXmlSimpleReaderWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QXmlSimpleReader_Type, &Sbk_QXmlSimpleReader_typeDiscovery);


}
