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

#include "qabstractxmlnodemodel_wrapper.h"

// Extra includes
#include <QVector>
#include <qabstractxmlnodemodel.h>
#include <qabstractxmlreceiver.h>
#include <qsourcelocation.h>
#include <qurl.h>
#include <qxmlname.h>


// Native ---------------------------------------------------------

QAbstractXmlNodeModelWrapper::QAbstractXmlNodeModelWrapper() : QAbstractXmlNodeModel() {
    // ... middle
}

QVector<QXmlNodeModelIndex > QAbstractXmlNodeModelWrapper::attributes(const QXmlNodeModelIndex & element) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVector<QXmlNodeModelIndex >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "attributes"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.attributes()' not implemented.");
        return ::QVector<QXmlNodeModelIndex >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &element)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVector<QXmlNodeModelIndex >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.attributes", "vector", pyResult->ob_type->tp_name);
        return ::QVector<QXmlNodeModelIndex >();
    }
    ::QVector<QXmlNodeModelIndex > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QUrl QAbstractXmlNodeModelWrapper::baseUri(const QXmlNodeModelIndex & ni) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QUrl();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "baseUri"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.baseUri()' not implemented.");
        return ::QUrl();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QUrl();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.baseUri", Shiboken::SbkType< QUrl >()->tp_name, pyResult->ob_type->tp_name);
        return ::QUrl();
    }
    ::QUrl cppResult = ::QUrl();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlNodeModelIndex::DocumentOrder QAbstractXmlNodeModelWrapper::compareOrder(const QXmlNodeModelIndex & ni1, const QXmlNodeModelIndex & ni2) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlNodeModelIndex::DocumentOrder)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "compareOrder"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.compareOrder()' not implemented.");
        return ((::QXmlNodeModelIndex::DocumentOrder)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni1),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni2)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlNodeModelIndex::DocumentOrder)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.compareOrder", Shiboken::SbkType< QXmlNodeModelIndex::DocumentOrder >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlNodeModelIndex::DocumentOrder)0);
    }
    ::QXmlNodeModelIndex::DocumentOrder cppResult = ((::QXmlNodeModelIndex::DocumentOrder)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QUrl QAbstractXmlNodeModelWrapper::documentUri(const QXmlNodeModelIndex & ni) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QUrl();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "documentUri"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.documentUri()' not implemented.");
        return ::QUrl();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QUrl();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.documentUri", Shiboken::SbkType< QUrl >()->tp_name, pyResult->ob_type->tp_name);
        return ::QUrl();
    }
    ::QUrl cppResult = ::QUrl();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlNodeModelIndex QAbstractXmlNodeModelWrapper::elementById(const QXmlName & NCName) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QXmlNodeModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "elementById"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.elementById()' not implemented.");
        return ::QXmlNodeModelIndex();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &NCName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QXmlNodeModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.elementById", Shiboken::SbkType< QXmlNodeModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QXmlNodeModelIndex();
    }
    ::QXmlNodeModelIndex cppResult = ::QXmlNodeModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractXmlNodeModelWrapper::isDeepEqual(const QXmlNodeModelIndex & ni1, const QXmlNodeModelIndex & ni2) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isDeepEqual"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractXmlNodeModel::isDeepEqual(ni1, ni2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni1),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.isDeepEqual", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlNodeModelIndex::NodeKind QAbstractXmlNodeModelWrapper::kind(const QXmlNodeModelIndex & ni) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QXmlNodeModelIndex::NodeKind)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "kind"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.kind()' not implemented.");
        return ((::QXmlNodeModelIndex::NodeKind)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QXmlNodeModelIndex::NodeKind)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.kind", Shiboken::SbkType< QXmlNodeModelIndex::NodeKind >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QXmlNodeModelIndex::NodeKind)0);
    }
    ::QXmlNodeModelIndex::NodeKind cppResult = ((::QXmlNodeModelIndex::NodeKind)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlName QAbstractXmlNodeModelWrapper::name(const QXmlNodeModelIndex & ni) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QXmlName();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "name"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.name()' not implemented.");
        return ::QXmlName();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QXmlName();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.name", Shiboken::SbkType< QXmlName >()->tp_name, pyResult->ob_type->tp_name);
        return ::QXmlName();
    }
    ::QXmlName cppResult = ::QXmlName();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVector<QXmlName > QAbstractXmlNodeModelWrapper::namespaceBindings(const QXmlNodeModelIndex & n) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVector<QXmlName >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "namespaceBindings"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.namespaceBindings()' not implemented.");
        return ::QVector<QXmlName >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &n)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVector<QXmlName >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNAME_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.namespaceBindings", "vector", pyResult->ob_type->tp_name);
        return ::QVector<QXmlName >();
    }
    ::QVector<QXmlName > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

short QAbstractXmlNodeModelWrapper::namespaceForPrefix(const QXmlNodeModelIndex & ni, const short prefix) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((short)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "namespaceForPrefix"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractXmlNodeModel::namespaceForPrefix(ni, prefix);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Nh)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &ni),
        prefix
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((short)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<short>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.namespaceForPrefix", "short", pyResult->ob_type->tp_name);
        return ((short)0);
    }
    short cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlNodeModelIndex QAbstractXmlNodeModelWrapper::nextFromSimpleAxis(QAbstractXmlNodeModel::SimpleAxis axis, const QXmlNodeModelIndex & origin) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QXmlNodeModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "nextFromSimpleAxis"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.nextFromSimpleAxis()' not implemented.");
        return ::QXmlNodeModelIndex();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX]), &axis),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &origin)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QXmlNodeModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.nextFromSimpleAxis", Shiboken::SbkType< QXmlNodeModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QXmlNodeModelIndex();
    }
    ::QXmlNodeModelIndex cppResult = ::QXmlNodeModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVector<QXmlNodeModelIndex > QAbstractXmlNodeModelWrapper::nodesByIdref(const QXmlName & NCName) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVector<QXmlNodeModelIndex >();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "nodesByIdref"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.nodesByIdref()' not implemented.");
        return ::QVector<QXmlNodeModelIndex >();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &NCName)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVector<QXmlNodeModelIndex >();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.nodesByIdref", "vector", pyResult->ob_type->tp_name);
        return ::QVector<QXmlNodeModelIndex >();
    }
    ::QVector<QXmlNodeModelIndex > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QXmlNodeModelIndex QAbstractXmlNodeModelWrapper::root(const QXmlNodeModelIndex & n) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QXmlNodeModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "root"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.root()' not implemented.");
        return ::QXmlNodeModelIndex();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &n)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QXmlNodeModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.root", Shiboken::SbkType< QXmlNodeModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QXmlNodeModelIndex();
    }
    ::QXmlNodeModelIndex cppResult = ::QXmlNodeModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractXmlNodeModelWrapper::sendNamespaces(const QXmlNodeModelIndex & n, QAbstractXmlReceiver * receiver) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sendNamespaces"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractXmlNodeModel::sendNamespaces(n, receiver);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &n),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], receiver)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QString QAbstractXmlNodeModelWrapper::stringValue(const QXmlNodeModelIndex & n) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stringValue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.stringValue()' not implemented.");
        return ::QString();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &n)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.stringValue", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QAbstractXmlNodeModelWrapper::typedValue(const QXmlNodeModelIndex & n) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "typedValue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.typedValue()' not implemented.");
        return ::QVariant();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &n)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractXmlNodeModel.typedValue", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QAbstractXmlNodeModelWrapper::~QAbstractXmlNodeModelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractXmlNodeModel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractXmlNodeModel' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractXmlNodeModel >()))
        return -1;

    ::QAbstractXmlNodeModelWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QAbstractXmlNodeModel()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QAbstractXmlNodeModelWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractXmlNodeModel >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_attributes(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: attributes(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // attributes(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_attributes_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // attributes(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.attributes()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlNodeModelIndex > cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->attributes(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_attributes_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.attributes", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_baseUri(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: baseUri(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // baseUri(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_baseUri_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // baseUri(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.baseUri()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->baseUri(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_baseUri_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.baseUri", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_compareOrder(PyObject* self, PyObject* args)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "compareOrder", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: compareOrder(QXmlNodeModelIndex,QXmlNodeModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // compareOrder(QXmlNodeModelIndex,QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_compareOrder_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlNodeModelIndex cppArg1_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // compareOrder(QXmlNodeModelIndex,QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.compareOrder()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex::DocumentOrder cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->compareOrder(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_DOCUMENTORDER_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_compareOrder_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex, PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.compareOrder", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_createIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.createIndex(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.createIndex(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:createIndex", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: createIndex(qint64)const
    // 1: createIndex(qint64,qint64)const
    // 2: createIndex(void*,qint64)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<void*>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // createIndex(void*,qint64)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
            overloadId = 2; // createIndex(void*,qint64)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createIndex(qint64)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1])))) {
            overloadId = 1; // createIndex(qint64,qint64)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_createIndex_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // createIndex(qint64 data) const
        {
            qint64 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // createIndex(qint64)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->createIndex(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
            }
            break;
        }
        case 1: // createIndex(qint64 data, qint64 additionalData) const
        {
            qint64 cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qint64 cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // createIndex(qint64,qint64)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->createIndex(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
            }
            break;
        }
        case 2: // createIndex(void * pointer, qint64 additionalData) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "additionalData");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.createIndex(): got multiple values for keyword argument 'additionalData'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArgs[1]))))
                        goto Sbk_QAbstractXmlNodeModelFunc_createIndex_TypeError;
                }
            }
            void* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qint64 cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // createIndex(void*,qint64)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->createIndex(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_createIndex_TypeError:
        const char* overloads[] = {"long long", "long long, long long", "void, long long = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.createIndex", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_documentUri(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: documentUri(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // documentUri(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_documentUri_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // documentUri(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.documentUri()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QUrl cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->documentUri(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_documentUri_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.documentUri", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_elementById(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: elementById(QXmlName)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
        overloadId = 0; // elementById(QXmlName)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_elementById_TypeError;

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
            // elementById(QXmlName)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.elementById()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->elementById(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_elementById_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.elementById", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_isDeepEqual(PyObject* self, PyObject* args)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isDeepEqual", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isDeepEqual(QXmlNodeModelIndex,QXmlNodeModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // isDeepEqual(QXmlNodeModelIndex,QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_isDeepEqual_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlNodeModelIndex cppArg1_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // isDeepEqual(QXmlNodeModelIndex,QXmlNodeModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->::QAbstractXmlNodeModel::isDeepEqual(*cppArg0, *cppArg1) : const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->isDeepEqual(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_isDeepEqual_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex, PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.isDeepEqual", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_kind(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: kind(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // kind(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_kind_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // kind(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.kind()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex::NodeKind cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->kind(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_NODEKIND_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_kind_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.kind", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_name(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: name(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // name(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_name_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // name(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.name()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlName cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->name(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_name_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.name", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_namespaceBindings(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: namespaceBindings(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // namespaceBindings(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_namespaceBindings_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // namespaceBindings(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.namespaceBindings()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlName > cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->namespaceBindings(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNAME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_namespaceBindings_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.namespaceBindings", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_namespaceForPrefix(PyObject* self, PyObject* args)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "namespaceForPrefix", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: namespaceForPrefix(QXmlNodeModelIndex,short)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<short>(), (pyArgs[1])))) {
        overloadId = 0; // namespaceForPrefix(QXmlNodeModelIndex,short)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_namespaceForPrefix_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        short cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // namespaceForPrefix(QXmlNodeModelIndex,short)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            short cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->::QAbstractXmlNodeModel::namespaceForPrefix(*cppArg0, cppArg1) : const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->namespaceForPrefix(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<short>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_namespaceForPrefix_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex, short", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.namespaceForPrefix", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_nextFromSimpleAxis(PyObject* self, PyObject* args)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "nextFromSimpleAxis", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: nextFromSimpleAxis(QAbstractXmlNodeModel::SimpleAxis,QXmlNodeModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // nextFromSimpleAxis(QAbstractXmlNodeModel::SimpleAxis,QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_nextFromSimpleAxis_TypeError;

    // Call function/method
    {
        ::QAbstractXmlNodeModel::SimpleAxis cppArg0 = ((::QAbstractXmlNodeModel::SimpleAxis)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QXmlNodeModelIndex cppArg1_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // nextFromSimpleAxis(QAbstractXmlNodeModel::SimpleAxis,QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.nextFromSimpleAxis()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->nextFromSimpleAxis(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_nextFromSimpleAxis_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QAbstractXmlNodeModel.SimpleAxis, PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.nextFromSimpleAxis", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_nodesByIdref(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: nodesByIdref(QXmlName)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNAME_IDX], (pyArg)))) {
        overloadId = 0; // nodesByIdref(QXmlName)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_nodesByIdref_TypeError;

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
            // nodesByIdref(QXmlName)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.nodesByIdref()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<QXmlNodeModelIndex > cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->nodesByIdref(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtXmlPatternsTypeConverters[SBK_QTXMLPATTERNS_QVECTOR_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_nodesByIdref_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlName", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.nodesByIdref", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_root(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: root(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // root(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_root_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // root(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.root()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QXmlNodeModelIndex cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->root(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_root_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.root", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_sendNamespaces(PyObject* self, PyObject* args)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sendNamespaces", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sendNamespaces(QXmlNodeModelIndex,QAbstractXmlReceiver*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLRECEIVER_IDX], (pyArgs[1])))) {
        overloadId = 0; // sendNamespaces(QXmlNodeModelIndex,QAbstractXmlReceiver*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_sendNamespaces_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QAbstractXmlReceiver* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sendNamespaces(QXmlNodeModelIndex,QAbstractXmlReceiver*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->::QAbstractXmlNodeModel::sendNamespaces(*cppArg0, cppArg1) : const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->sendNamespaces(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractXmlNodeModelFunc_sendNamespaces_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex, PySide.QtXmlPatterns.QAbstractXmlReceiver", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.sendNamespaces", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_sourceLocation(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sourceLocation(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // sourceLocation(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_sourceLocation_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // sourceLocation(QXmlNodeModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSourceLocation cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->sourceLocation(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QSOURCELOCATION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_sourceLocation_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.sourceLocation", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_stringValue(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stringValue(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // stringValue(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_stringValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // stringValue(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.stringValue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->stringValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_stringValue_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.stringValue", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractXmlNodeModelFunc_typedValue(PyObject* self, PyObject* pyArg)
{
    ::QAbstractXmlNodeModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractXmlNodeModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: typedValue(QXmlNodeModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // typedValue(QXmlNodeModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractXmlNodeModelFunc_typedValue_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QXmlNodeModelIndex cppArg0_local = ::QXmlNodeModelIndex();
        ::QXmlNodeModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtXmlPatternsTypes[SBK_QXMLNODEMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // typedValue(QXmlNodeModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractXmlNodeModel.typedValue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QAbstractXmlNodeModel*>(cppSelf)->typedValue(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractXmlNodeModelFunc_typedValue_TypeError:
        const char* overloads[] = {"PySide.QtXmlPatterns.QXmlNodeModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtXmlPatterns.QAbstractXmlNodeModel.typedValue", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractXmlNodeModel_methods[] = {
    {"attributes", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_attributes, METH_O},
    {"baseUri", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_baseUri, METH_O},
    {"compareOrder", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_compareOrder, METH_VARARGS},
    {"createIndex", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_createIndex, METH_VARARGS|METH_KEYWORDS},
    {"documentUri", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_documentUri, METH_O},
    {"elementById", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_elementById, METH_O},
    {"isDeepEqual", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_isDeepEqual, METH_VARARGS},
    {"kind", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_kind, METH_O},
    {"name", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_name, METH_O},
    {"namespaceBindings", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_namespaceBindings, METH_O},
    {"namespaceForPrefix", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_namespaceForPrefix, METH_VARARGS},
    {"nextFromSimpleAxis", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_nextFromSimpleAxis, METH_VARARGS},
    {"nodesByIdref", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_nodesByIdref, METH_O},
    {"root", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_root, METH_O},
    {"sendNamespaces", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_sendNamespaces, METH_VARARGS},
    {"sourceLocation", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_sourceLocation, METH_O},
    {"stringValue", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_stringValue, METH_O},
    {"typedValue", (PyCFunction)Sbk_QAbstractXmlNodeModelFunc_typedValue, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractXmlNodeModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractXmlNodeModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAbstractXmlNodeModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtXmlPatterns.QAbstractXmlNodeModel",
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
    /*tp_traverse*/         Sbk_QAbstractXmlNodeModel_traverse,
    /*tp_clear*/            Sbk_QAbstractXmlNodeModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractXmlNodeModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractXmlNodeModel_Init,
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
static void QAbstractXmlNodeModel_SimpleAxis_PythonToCpp_QAbstractXmlNodeModel_SimpleAxis(PyObject* pyIn, void* cppOut) {
    *((::QAbstractXmlNodeModel::SimpleAxis*)cppOut) = (::QAbstractXmlNodeModel::SimpleAxis) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractXmlNodeModel_SimpleAxis_PythonToCpp_QAbstractXmlNodeModel_SimpleAxis_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX]))
        return QAbstractXmlNodeModel_SimpleAxis_PythonToCpp_QAbstractXmlNodeModel_SimpleAxis;
    return 0;
}
static PyObject* QAbstractXmlNodeModel_SimpleAxis_CppToPython_QAbstractXmlNodeModel_SimpleAxis(const void* cppIn) {
    int castCppIn = *((::QAbstractXmlNodeModel::SimpleAxis*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX], castCppIn);

}

static void QAbstractXmlNodeModel_NodeCopySetting_PythonToCpp_QAbstractXmlNodeModel_NodeCopySetting(PyObject* pyIn, void* cppOut) {
    *((::QAbstractXmlNodeModel::NodeCopySetting*)cppOut) = (::QAbstractXmlNodeModel::NodeCopySetting) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractXmlNodeModel_NodeCopySetting_PythonToCpp_QAbstractXmlNodeModel_NodeCopySetting_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX]))
        return QAbstractXmlNodeModel_NodeCopySetting_PythonToCpp_QAbstractXmlNodeModel_NodeCopySetting;
    return 0;
}
static PyObject* QAbstractXmlNodeModel_NodeCopySetting_CppToPython_QAbstractXmlNodeModel_NodeCopySetting(const void* cppIn) {
    int castCppIn = *((::QAbstractXmlNodeModel::NodeCopySetting*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractXmlNodeModel_PythonToCpp_QAbstractXmlNodeModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractXmlNodeModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractXmlNodeModel_PythonToCpp_QAbstractXmlNodeModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractXmlNodeModel_Type))
        return QAbstractXmlNodeModel_PythonToCpp_QAbstractXmlNodeModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractXmlNodeModel_PTR_CppToPython_QAbstractXmlNodeModel(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QAbstractXmlNodeModel*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QAbstractXmlNodeModel_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QAbstractXmlNodeModel(PyObject* module)
{
    SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractXmlNodeModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractXmlNodeModel", "QAbstractXmlNodeModel*",
        &Sbk_QAbstractXmlNodeModel_Type, &Shiboken::callCppDestructor< ::QAbstractXmlNodeModel >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractXmlNodeModel_Type,
        QAbstractXmlNodeModel_PythonToCpp_QAbstractXmlNodeModel_PTR,
        is_QAbstractXmlNodeModel_PythonToCpp_QAbstractXmlNodeModel_PTR_Convertible,
        QAbstractXmlNodeModel_PTR_CppToPython_QAbstractXmlNodeModel);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlNodeModel");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlNodeModel*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlNodeModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractXmlNodeModel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractXmlNodeModelWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'SimpleAxis'.
    SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractXmlNodeModel_Type,
        "SimpleAxis",
        "PySide.QtXmlPatterns.QAbstractXmlNodeModel.SimpleAxis",
        "QAbstractXmlNodeModel::SimpleAxis");
    if (!SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "Parent", (long) QAbstractXmlNodeModel::Parent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "FirstChild", (long) QAbstractXmlNodeModel::FirstChild))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "PreviousSibling", (long) QAbstractXmlNodeModel::PreviousSibling))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "NextSibling", (long) QAbstractXmlNodeModel::NextSibling))
        return ;
    // Register converter for enum 'QAbstractXmlNodeModel::SimpleAxis'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX],
            QAbstractXmlNodeModel_SimpleAxis_CppToPython_QAbstractXmlNodeModel_SimpleAxis);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractXmlNodeModel_SimpleAxis_PythonToCpp_QAbstractXmlNodeModel_SimpleAxis,
            is_QAbstractXmlNodeModel_SimpleAxis_PythonToCpp_QAbstractXmlNodeModel_SimpleAxis_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_SIMPLEAXIS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlNodeModel::SimpleAxis");
        Shiboken::Conversions::registerConverterName(converter, "SimpleAxis");
    }
    // End of 'SimpleAxis' enum.

    // Initialization of enum 'NodeCopySetting'.
    SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractXmlNodeModel_Type,
        "NodeCopySetting",
        "PySide.QtXmlPatterns.QAbstractXmlNodeModel.NodeCopySetting",
        "QAbstractXmlNodeModel::NodeCopySetting");
    if (!SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "InheritNamespaces", (long) QAbstractXmlNodeModel::InheritNamespaces))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX],
        &Sbk_QAbstractXmlNodeModel_Type, "PreserveNamespaces", (long) QAbstractXmlNodeModel::PreserveNamespaces))
        return ;
    // Register converter for enum 'QAbstractXmlNodeModel::NodeCopySetting'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX],
            QAbstractXmlNodeModel_NodeCopySetting_CppToPython_QAbstractXmlNodeModel_NodeCopySetting);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractXmlNodeModel_NodeCopySetting_PythonToCpp_QAbstractXmlNodeModel_NodeCopySetting,
            is_QAbstractXmlNodeModel_NodeCopySetting_PythonToCpp_QAbstractXmlNodeModel_NodeCopySetting_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtXmlPatternsTypes[SBK_QABSTRACTXMLNODEMODEL_NODECOPYSETTING_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractXmlNodeModel::NodeCopySetting");
        Shiboken::Conversions::registerConverterName(converter, "NodeCopySetting");
    }
    // End of 'NodeCopySetting' enum.


    qRegisterMetaType< ::QAbstractXmlNodeModel::SimpleAxis >("QAbstractXmlNodeModel::SimpleAxis");
    qRegisterMetaType< ::QAbstractXmlNodeModel::NodeCopySetting >("QAbstractXmlNodeModel::NodeCopySetting");
}
