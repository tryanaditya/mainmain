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

#include "qgraphicsitem_wrapper.h"

// Extra includes
#include <QList>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qevent.h>
#include <qgraphicseffect.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicssceneevent.h>
#include <qgraphicstransform.h>
#include <qgraphicswidget.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qstyleoption.h>
#include <qtransform.h>
#include <qwidget.h>



// Native ---------------------------------------------------------

QGraphicsItemWrapper::QGraphicsItemWrapper(QGraphicsItem * parent, QGraphicsScene * scene) : QGraphicsItem(parent, scene) {
    // ... middle
}

void QGraphicsItemWrapper::advance(int phase)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "advance"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::advance(phase);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        phase
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QRectF QGraphicsItemWrapper::boundingRect() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRectF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "boundingRect"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsItem.boundingRect()' not implemented.");
        return ::QRectF();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRectF();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.boundingRect", Shiboken::SbkType< QRectF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRectF();
    }
    ::QRectF cppResult = ::QRectF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QGraphicsItemWrapper::collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode mode) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "collidesWithItem"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::collidesWithItem(other, mode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], other),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), &mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.collidesWithItem", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsItemWrapper::collidesWithPath(const QPainterPath & path, Qt::ItemSelectionMode mode) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "collidesWithPath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::collidesWithPath(path, mode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &path),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), &mode)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.collidesWithPath", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QGraphicsItemWrapper::contains(const QPointF & point) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contains"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::contains(point);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &point)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.contains", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsItemWrapper::contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::dragEnterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::dragLeaveEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::dragLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::dragMoveEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::dragMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::dropEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::dropEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QVariant QGraphicsItemWrapper::extension(const QVariant & variant) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "extension"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::extension(variant);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &variant)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.extension", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsItemWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::focusInEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::focusOutEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hoverEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::hoverEnterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::hoverLeaveEvent(QGraphicsSceneHoverEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hoverLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::hoverLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hoverMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::hoverMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::inputMethodEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QVariant QGraphicsItemWrapper::inputMethodQuery(Qt::InputMethodQuery query) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::inputMethodQuery(query);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &query)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QGraphicsItemWrapper::isObscuredBy(const QGraphicsItem * item) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isObscuredBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::isObscuredBy(item);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], item)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.isObscuredBy", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QVariant QGraphicsItemWrapper::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::itemChange(change, value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX]), &change),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.itemChange", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsItemWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::keyPressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::keyReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::mouseDoubleClickEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::mouseMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::mousePressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QGraphicsItemWrapper::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::mouseReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QPainterPath QGraphicsItemWrapper::opaqueArea() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPainterPath();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "opaqueArea"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::opaqueArea();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPainterPath();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.opaqueArea", Shiboken::SbkType< QPainterPath >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPainterPath();
    }
    ::QPainterPath cppResult = ::QPainterPath();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsItemWrapper::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paint"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsItem.paint()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QGraphicsItemWrapper::sceneEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sceneEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::sceneEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.sceneEvent", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsItemWrapper::sceneEventFilter(QGraphicsItem * watched, QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sceneEventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::sceneEventFilter(watched, event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], watched),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.sceneEventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QPainterPath QGraphicsItemWrapper::shape() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPainterPath();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "shape"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::shape();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPainterPath();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.shape", Shiboken::SbkType< QPainterPath >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPainterPath();
    }
    ::QPainterPath cppResult = ::QPainterPath();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGraphicsItemWrapper::type() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "type"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::type();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsItem.type", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsItemWrapper::wheelEvent(QGraphicsSceneWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsItem::wheelEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEWHEELEVENT_IDX], event)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QGraphicsItemWrapper::~QGraphicsItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QGraphicsItem' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsItem >()))
        return -1;

    ::QGraphicsItemWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QGraphicsItem", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsItem(QGraphicsItem*,QGraphicsScene*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsItem(QGraphicsItem*,QGraphicsScene*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGraphicsItem(QGraphicsItem*,QGraphicsScene*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (pyArgs[1])))) {
            overloadId = 0; // QGraphicsItem(QGraphicsItem*,QGraphicsScene*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItem_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsItem_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "scene");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem(): got multiple values for keyword argument 'scene'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsItem_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGraphicsItem* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QGraphicsScene* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QGraphicsItem(QGraphicsItem*,QGraphicsScene*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsItemWrapper(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsItem_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem = None, PySide.QtGui.QGraphicsScene = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsItemFunc_acceptDrops(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptDrops()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->acceptDrops();
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

static PyObject* Sbk_QGraphicsItemFunc_acceptHoverEvents(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptHoverEvents()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->acceptHoverEvents();
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

static PyObject* Sbk_QGraphicsItemFunc_acceptTouchEvents(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptTouchEvents()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->acceptTouchEvents();
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

static PyObject* Sbk_QGraphicsItemFunc_acceptedMouseButtons(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptedMouseButtons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::MouseButton> cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->acceptedMouseButtons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_acceptsHoverEvents(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptsHoverEvents()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->acceptsHoverEvents();
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

static PyObject* Sbk_QGraphicsItemFunc_addToIndex(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // addToIndex()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addToIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_advance(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: advance(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // advance(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_advance_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // advance(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::advance(cppArg0) : cppSelf->advance(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_advance_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.advance", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_boundingRect(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsItem.boundingRect()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->boundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_boundingRegion(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: boundingRegion(QTransform)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 0; // boundingRegion(QTransform)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_boundingRegion_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // boundingRegion(QTransform)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegion cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->boundingRegion(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_boundingRegion_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.boundingRegion", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_boundingRegionGranularity(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRegionGranularity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->boundingRegionGranularity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_cacheMode(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem::CacheMode cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->cacheMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_childItems(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childItems()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->childItems();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_childrenBoundingRect(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childrenBoundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->childrenBoundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_clearFocus(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearFocus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearFocus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_clipPath(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->clipPath();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_collidesWithItem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithItem(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithItem(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:collidesWithItem", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: collidesWithItem(const QGraphicsItem*,Qt::ItemSelectionMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // collidesWithItem(const QGraphicsItem*,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // collidesWithItem(const QGraphicsItem*,Qt::ItemSelectionMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_collidesWithItem_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithItem(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsItemFunc_collidesWithItem_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // collidesWithItem(const QGraphicsItem*,Qt::ItemSelectionMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::collidesWithItem(cppArg0, cppArg1) : const_cast<const ::QGraphicsItem*>(cppSelf)->collidesWithItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_collidesWithItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.collidesWithItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_collidesWithPath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithPath(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithPath(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:collidesWithPath", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: collidesWithPath(QPainterPath,Qt::ItemSelectionMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // collidesWithPath(QPainterPath,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // collidesWithPath(QPainterPath,Qt::ItemSelectionMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_collidesWithPath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidesWithPath(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsItemFunc_collidesWithPath_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // collidesWithPath(QPainterPath,Qt::ItemSelectionMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::collidesWithPath(*cppArg0, cppArg1) : const_cast<const ::QGraphicsItem*>(cppSelf)->collidesWithPath(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_collidesWithPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.collidesWithPath", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_collidingItems(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidingItems(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:collidingItems", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: collidingItems(Qt::ItemSelectionMode)const
    if (numArgs == 0) {
        overloadId = 0; // collidingItems(Qt::ItemSelectionMode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // collidingItems(Qt::ItemSelectionMode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_collidingItems_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.collidingItems(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsItemFunc_collidingItems_TypeError;
            }
        }
        ::Qt::ItemSelectionMode cppArg0 = Qt::IntersectsItemShape;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // collidingItems(Qt::ItemSelectionMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->collidingItems(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_collidingItems_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.collidingItems", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_commonAncestorItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: commonAncestorItem(const QGraphicsItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // commonAncestorItem(const QGraphicsItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_commonAncestorItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // commonAncestorItem(const QGraphicsItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->commonAncestorItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_commonAncestorItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.commonAncestorItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_contains(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contains(QPointF)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArg)))) {
        overloadId = 0; // contains(QPointF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_contains_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // contains(QPointF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::contains(*cppArg0) : const_cast<const ::QGraphicsItem*>(cppSelf)->contains(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_contains_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.contains", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QGraphicsSceneContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QGraphicsSceneContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QGraphicsSceneContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_cursor(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCursor cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->cursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_data(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: data(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // data(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_data_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // data(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_data_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.data", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_deviceTransform(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: deviceTransform(QTransform)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 0; // deviceTransform(QTransform)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_deviceTransform_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // deviceTransform(QTransform)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->deviceTransform(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_deviceTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.deviceTransform", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_effectiveOpacity(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // effectiveOpacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->effectiveOpacity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_ensureVisible(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:ensureVisible", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: ensureVisible(QRectF,int,int)
    // 1: ensureVisible(qreal,qreal,qreal,qreal,int,int)
    if (numArgs == 0) {
        overloadId = 0; // ensureVisible(QRectF,int,int)
    } else if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                overloadId = 1; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // ensureVisible(QRectF,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // ensureVisible(QRectF,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // ensureVisible(QRectF,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ensureVisible(const QRectF & rect, int xmargin, int ymargin)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "xmargin");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): got multiple values for keyword argument 'xmargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ymargin");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): got multiple values for keyword argument 'ymargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }
            int cppArg1 = 50;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 50;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // ensureVisible(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ensureVisible(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ensureVisible(qreal x, qreal y, qreal w, qreal h, int xmargin, int ymargin)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xmargin");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): got multiple values for keyword argument 'xmargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ymargin");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.ensureVisible(): got multiple values for keyword argument 'ymargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QGraphicsItemFunc_ensureVisible_TypeError;
                }
            }
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 50;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5 = 50;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // ensureVisible(qreal,qreal,qreal,qreal,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ensureVisible(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_ensureVisible_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF = QRectF(), int = 50, int = 50", "float, float, float, float, int = 50, int = 50", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.ensureVisible", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_extension(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: extension(QVariant)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // extension(QVariant)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_extension_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // extension(QVariant)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::extension(cppArg0) : const_cast<const ::QGraphicsItem*>(cppSelf)->extension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_extension_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.extension", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_filtersChildEvents(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filtersChildEvents()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->filtersChildEvents();
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

static PyObject* Sbk_QGraphicsItemFunc_flags(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGraphicsItem::GraphicsItemFlag> cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->flags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_focusItem(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focusItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->focusItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_focusProxy(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focusProxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->focusProxy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_focusScopeItem(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focusScopeItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->focusScopeItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_grabKeyboard(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // grabKeyboard()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->grabKeyboard();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_grabMouse(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // grabMouse()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->grabMouse();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_graphicsEffect(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // graphicsEffect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsEffect * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->graphicsEffect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_group(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // group()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItemGroup * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->group();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEMGROUP_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_handlesChildEvents(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // handlesChildEvents()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->handlesChildEvents();
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

static PyObject* Sbk_QGraphicsItemFunc_hasCursor(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasCursor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->hasCursor();
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

static PyObject* Sbk_QGraphicsItemFunc_hasFocus(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->hasFocus();
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

static PyObject* Sbk_QGraphicsItemFunc_hide(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hide()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hide();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_hoverEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hoverEnterEvent(QGraphicsSceneHoverEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // hoverEnterEvent(QGraphicsSceneHoverEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_hoverEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneHoverEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hoverEnterEvent(QGraphicsSceneHoverEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::hoverEnterEvent(cppArg0) : cppSelf->hoverEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_hoverEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneHoverEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.hoverEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_hoverLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hoverLeaveEvent(QGraphicsSceneHoverEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // hoverLeaveEvent(QGraphicsSceneHoverEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_hoverLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneHoverEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hoverLeaveEvent(QGraphicsSceneHoverEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::hoverLeaveEvent(cppArg0) : cppSelf->hoverLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_hoverLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneHoverEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.hoverLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_hoverMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hoverMoveEvent(QGraphicsSceneHoverEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHOVEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // hoverMoveEvent(QGraphicsSceneHoverEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_hoverMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneHoverEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hoverMoveEvent(QGraphicsSceneHoverEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::hoverMoveEvent(cppArg0) : cppSelf->hoverMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_hoverMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneHoverEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.hoverMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_inputMethodHints(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // inputMethodHints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::InputMethodHint> cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->inputMethodHints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodQuery(Qt::InputMethodQuery)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), (pyArg)))) {
        overloadId = 0; // inputMethodQuery(Qt::InputMethodQuery)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::inputMethodQuery(cppArg0) : const_cast<const ::QGraphicsItem*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_installSceneEventFilter(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: installSceneEventFilter(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // installSceneEventFilter(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_installSceneEventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // installSceneEventFilter(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->installSceneEventFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_installSceneEventFilter_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.installSceneEventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_isActive(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isActive();
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

static PyObject* Sbk_QGraphicsItemFunc_isAncestorOf(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isAncestorOf(const QGraphicsItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // isAncestorOf(const QGraphicsItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_isAncestorOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isAncestorOf(const QGraphicsItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isAncestorOf(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_isAncestorOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.isAncestorOf", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_isBlockedByModalPanel(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {
        ::QGraphicsItem** removed_cppArg0 = 0;
        SBK_UNUSED(removed_cppArg0)

        if (!PyErr_Occurred()) {
            // isBlockedByModalPanel(QGraphicsItem**)const
            // Begin code injection

            QGraphicsItem *item_ = NULL;
            bool retval_ = cppSelf->isBlockedByModalPanel(&item_);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], item_));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_isClipped(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isClipped()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isClipped();
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

static PyObject* Sbk_QGraphicsItemFunc_isEnabled(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_QGraphicsItemFunc_isObscured(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_isObscured_TypeError;

    if (!PyArg_UnpackTuple(args, "isObscured", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: isObscured()const
    // 1: isObscured(QRectF)const
    // 2: isObscured(qreal,qreal,qreal,qreal)const
    if (numArgs == 0) {
        overloadId = 0; // isObscured()const
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 2; // isObscured(qreal,qreal,qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // isObscured(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_isObscured_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // isObscured() const
        {

            if (!PyErr_Occurred()) {
                // isObscured()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isObscured();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // isObscured(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // isObscured(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isObscured(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // isObscured(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // isObscured(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isObscured(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_QGraphicsItemFunc_isObscured_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.isObscured", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_isObscuredBy(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isObscuredBy(const QGraphicsItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // isObscuredBy(const QGraphicsItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_isObscuredBy_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isObscuredBy(const QGraphicsItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::isObscuredBy(cppArg0) : const_cast<const ::QGraphicsItem*>(cppSelf)->isObscuredBy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_isObscuredBy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.isObscuredBy", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_isPanel(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isPanel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isPanel();
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

static PyObject* Sbk_QGraphicsItemFunc_isSelected(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelected()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isSelected();
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

static PyObject* Sbk_QGraphicsItemFunc_isUnderMouse(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUnderMouse()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isUnderMouse();
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

static PyObject* Sbk_QGraphicsItemFunc_isVisible(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isVisible();
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

static PyObject* Sbk_QGraphicsItemFunc_isVisibleTo(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isVisibleTo(const QGraphicsItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // isVisibleTo(const QGraphicsItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_isVisibleTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isVisibleTo(const QGraphicsItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isVisibleTo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_isVisibleTo_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.isVisibleTo", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_isWidget(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isWidget();
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

static PyObject* Sbk_QGraphicsItemFunc_isWindow(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWindow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->isWindow();
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

static PyObject* Sbk_QGraphicsItemFunc_itemChange(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemChange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: itemChange(QGraphicsItem::GraphicsItemChange,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // itemChange(QGraphicsItem::GraphicsItemChange,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_itemChange_TypeError;

    // Call function/method
    {
        ::QGraphicsItem::GraphicsItemChange cppArg0 = ((::QGraphicsItem::GraphicsItemChange)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // itemChange(QGraphicsItem::GraphicsItemChange,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::itemChange(cppArg0, cppArg1) : cppSelf->itemChange(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_itemChange_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem.GraphicsItemChange, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.itemChange", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_itemTransform(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemTransform(const QGraphicsItem*,bool*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // itemTransform(const QGraphicsItem*,bool*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_itemTransform_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemTransform(const QGraphicsItem*,bool*)const
            // Begin code injection

            // TEMPLATE - fix_args,bool* - START
            bool ok_;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform retval_ = cppSelf->itemTransform(cppArg0, &ok_);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_retval_ok - START
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &retval_));
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

    Sbk_QGraphicsItemFunc_itemTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.itemTransform", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_keyReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyReleaseEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapFromItem(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4)
        goto Sbk_QGraphicsItemFunc_mapFromItem_TypeError;

    if (!PyArg_UnpackTuple(args, "mapFromItem", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mapFromItem(const QGraphicsItem*,QPainterPath)const
    // 1: mapFromItem(const QGraphicsItem*,QPointF)const
    // 2: mapFromItem(const QGraphicsItem*,QPolygonF)const
    // 3: mapFromItem(const QGraphicsItem*,QRectF)const
    // 4: mapFromItem(const QGraphicsItem*,qreal,qreal)const
    // 5: mapFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 4; // mapFromItem(const QGraphicsItem*,qreal,qreal)const
            } else if (numArgs == 5
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
                && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
                overloadId = 5; // mapFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            overloadId = 3; // mapFromItem(const QGraphicsItem*,QRectF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[1])))) {
            overloadId = 2; // mapFromItem(const QGraphicsItem*,QPolygonF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 1; // mapFromItem(const QGraphicsItem*,QPointF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[1])))) {
            overloadId = 0; // mapFromItem(const QGraphicsItem*,QPainterPath)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapFromItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapFromItem(const QGraphicsItem * item, const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPainterPath cppArg1_local = ::QPainterPath();
            ::QPainterPath* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapFromItem(const QGraphicsItem * item, const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapFromItem(const QGraphicsItem * item, const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPolygonF cppArg1_local = ::QPolygonF();
            ::QPolygonF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapFromItem(const QGraphicsItem * item, const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRectF cppArg1_local = ::QRectF();
            ::QRectF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapFromItem(const QGraphicsItem * item, qreal x, qreal y) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapFromItem(const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // mapFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapFromItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtGui.QPainterPath", "PySide.QtGui.QGraphicsItem, PySide.QtCore.QPointF", "PySide.QtGui.QGraphicsItem, PySide.QtGui.QPolygonF", "PySide.QtGui.QGraphicsItem, PySide.QtCore.QRectF", "PySide.QtGui.QGraphicsItem, float, float", "PySide.QtGui.QGraphicsItem, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapFromItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapFromParent(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapFromParent_TypeError;

    if (!PyArg_UnpackTuple(args, "mapFromParent", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapFromParent(QPainterPath)const
    // 1: mapFromParent(QPointF)const
    // 2: mapFromParent(QPolygonF)const
    // 3: mapFromParent(QRectF)const
    // 4: mapFromParent(qreal,qreal)const
    // 5: mapFromParent(qreal,qreal,qreal,qreal)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // mapFromParent(qreal,qreal)const
        } else if (numArgs == 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 5; // mapFromParent(qreal,qreal,qreal,qreal)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // mapFromParent(QRectF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        overloadId = 2; // mapFromParent(QPolygonF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // mapFromParent(QPointF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapFromParent(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapFromParent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapFromParent(const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromParent(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapFromParent(const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromParent(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapFromParent(const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromParent(QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapFromParent(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromParent(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapFromParent(qreal x, qreal y) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // mapFromParent(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapFromParent(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapFromParent(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromParent(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapFromParent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "float, float", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapFromParent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapFromScene(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapFromScene_TypeError;

    if (!PyArg_UnpackTuple(args, "mapFromScene", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapFromScene(QPainterPath)const
    // 1: mapFromScene(QPointF)const
    // 2: mapFromScene(QPolygonF)const
    // 3: mapFromScene(QRectF)const
    // 4: mapFromScene(qreal,qreal)const
    // 5: mapFromScene(qreal,qreal,qreal,qreal)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // mapFromScene(qreal,qreal)const
        } else if (numArgs == 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 5; // mapFromScene(qreal,qreal,qreal,qreal)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // mapFromScene(QRectF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        overloadId = 2; // mapFromScene(QPolygonF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // mapFromScene(QPointF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapFromScene(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapFromScene_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapFromScene(const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromScene(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapFromScene(const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromScene(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapFromScene(const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromScene(QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapFromScene(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapFromScene(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapFromScene(qreal x, qreal y) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // mapFromScene(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapFromScene(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapFromScene(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapFromScene(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapFromScene_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "float, float", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapFromScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectFromItem(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_QGraphicsItemFunc_mapRectFromItem_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectFromItem", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectFromItem(const QGraphicsItem*,QRectF)const
    // 1: mapRectFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 5
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
            overloadId = 1; // mapRectFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            overloadId = 0; // mapRectFromItem(const QGraphicsItem*,QRectF)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectFromItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectFromItem(const QGraphicsItem * item, const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRectF cppArg1_local = ::QRectF();
            ::QRectF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapRectFromItem(const QGraphicsItem*,QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectFromItem(const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // mapRectFromItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectFromItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.QRectF", "PySide.QtGui.QGraphicsItem, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectFromItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectFromParent(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapRectFromParent_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectFromParent", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectFromParent(QRectF)const
    // 1: mapRectFromParent(qreal,qreal,qreal,qreal)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // mapRectFromParent(qreal,qreal,qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapRectFromParent(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectFromParent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectFromParent(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRectFromParent(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectFromParent(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapRectFromParent(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromParent(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectFromParent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectFromParent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectFromScene(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapRectFromScene_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectFromScene", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectFromScene(QRectF)const
    // 1: mapRectFromScene(qreal,qreal,qreal,qreal)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // mapRectFromScene(qreal,qreal,qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapRectFromScene(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectFromScene_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectFromScene(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRectFromScene(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectFromScene(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapRectFromScene(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectFromScene(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectFromScene_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectFromScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectToItem(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_QGraphicsItemFunc_mapRectToItem_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectToItem", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectToItem(const QGraphicsItem*,QRectF)const
    // 1: mapRectToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 5
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
            overloadId = 1; // mapRectToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            overloadId = 0; // mapRectToItem(const QGraphicsItem*,QRectF)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectToItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectToItem(const QGraphicsItem * item, const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRectF cppArg1_local = ::QRectF();
            ::QRectF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapRectToItem(const QGraphicsItem*,QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectToItem(const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // mapRectToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectToItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.QRectF", "PySide.QtGui.QGraphicsItem, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectToItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectToParent(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapRectToParent_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectToParent", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectToParent(QRectF)const
    // 1: mapRectToParent(qreal,qreal,qreal,qreal)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // mapRectToParent(qreal,qreal,qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapRectToParent(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectToParent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectToParent(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRectToParent(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectToParent(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapRectToParent(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToParent(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectToParent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectToParent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapRectToScene(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapRectToScene_TypeError;

    if (!PyArg_UnpackTuple(args, "mapRectToScene", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapRectToScene(QRectF)const
    // 1: mapRectToScene(qreal,qreal,qreal,qreal)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // mapRectToScene(qreal,qreal,qreal,qreal)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapRectToScene(QRectF)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapRectToScene_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapRectToScene(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapRectToScene(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapRectToScene(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapRectToScene(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapRectToScene(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapRectToScene_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapRectToScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapToItem(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4)
        goto Sbk_QGraphicsItemFunc_mapToItem_TypeError;

    if (!PyArg_UnpackTuple(args, "mapToItem", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: mapToItem(const QGraphicsItem*,QPainterPath)const
    // 1: mapToItem(const QGraphicsItem*,QPointF)const
    // 2: mapToItem(const QGraphicsItem*,QPolygonF)const
    // 3: mapToItem(const QGraphicsItem*,QRectF)const
    // 4: mapToItem(const QGraphicsItem*,qreal,qreal)const
    // 5: mapToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 4; // mapToItem(const QGraphicsItem*,qreal,qreal)const
            } else if (numArgs == 5
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
                && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
                overloadId = 5; // mapToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            overloadId = 3; // mapToItem(const QGraphicsItem*,QRectF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[1])))) {
            overloadId = 2; // mapToItem(const QGraphicsItem*,QPolygonF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
            overloadId = 1; // mapToItem(const QGraphicsItem*,QPointF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[1])))) {
            overloadId = 0; // mapToItem(const QGraphicsItem*,QPainterPath)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapToItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapToItem(const QGraphicsItem * item, const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPainterPath cppArg1_local = ::QPainterPath();
            ::QPainterPath* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapToItem(const QGraphicsItem * item, const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapToItem(const QGraphicsItem * item, const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPolygonF cppArg1_local = ::QPolygonF();
            ::QPolygonF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapToItem(const QGraphicsItem * item, const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRectF cppArg1_local = ::QRectF();
            ::QRectF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapToItem(const QGraphicsItem * item, qreal x, qreal y) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapToItem(const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // mapToItem(const QGraphicsItem*,qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapToItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtGui.QPainterPath", "PySide.QtGui.QGraphicsItem, PySide.QtCore.QPointF", "PySide.QtGui.QGraphicsItem, PySide.QtGui.QPolygonF", "PySide.QtGui.QGraphicsItem, PySide.QtCore.QRectF", "PySide.QtGui.QGraphicsItem, float, float", "PySide.QtGui.QGraphicsItem, float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapToItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapToParent(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapToParent_TypeError;

    if (!PyArg_UnpackTuple(args, "mapToParent", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapToParent(QPainterPath)const
    // 1: mapToParent(QPointF)const
    // 2: mapToParent(QPolygonF)const
    // 3: mapToParent(QRectF)const
    // 4: mapToParent(qreal,qreal)const
    // 5: mapToParent(qreal,qreal,qreal,qreal)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // mapToParent(qreal,qreal)const
        } else if (numArgs == 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 5; // mapToParent(qreal,qreal,qreal,qreal)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // mapToParent(QRectF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        overloadId = 2; // mapToParent(QPolygonF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // mapToParent(QPointF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapToParent(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapToParent_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapToParent(const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToParent(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapToParent(const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToParent(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapToParent(const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToParent(QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapToParent(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToParent(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapToParent(qreal x, qreal y) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // mapToParent(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapToParent(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapToParent(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToParent(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapToParent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "float, float", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapToParent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mapToScene(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsItemFunc_mapToScene_TypeError;

    if (!PyArg_UnpackTuple(args, "mapToScene", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapToScene(QPainterPath)const
    // 1: mapToScene(QPointF)const
    // 2: mapToScene(QPolygonF)const
    // 3: mapToScene(QRectF)const
    // 4: mapToScene(qreal,qreal)const
    // 5: mapToScene(qreal,qreal,qreal,qreal)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // mapToScene(qreal,qreal)const
        } else if (numArgs == 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
            overloadId = 5; // mapToScene(qreal,qreal,qreal,qreal)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // mapToScene(QRectF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        overloadId = 2; // mapToScene(QPolygonF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // mapToScene(QPointF)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapToScene(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mapToScene_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // mapToScene(const QPainterPath & path) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QPainterPath)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPainterPath cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapToScene(const QPointF & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapToScene(const QPolygonF & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QPolygonF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapToScene(const QRectF & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QRectF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapToScene(qreal x, qreal y) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // mapToScene(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapToScene(qreal x, qreal y, qreal w, qreal h) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapToScene(qreal,qreal,qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->mapToScene(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_mapToScene_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "float, float", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.mapToScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_moveBy(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveBy", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveBy(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // moveBy(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_moveBy_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveBy(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->moveBy(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_moveBy_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.moveBy", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_opacity(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // opacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->opacity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_opaqueArea(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // opaqueArea()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::opaqueArea() : const_cast<const ::QGraphicsItem*>(cppSelf)->opaqueArea();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_paint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.paint(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.paint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:paint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
            overloadId = 0; // paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_paint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.paint(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsItemFunc_paint_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionGraphicsItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsItem.paint()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->paint(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_paint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtGui.QStyleOptionGraphicsItem, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.paint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_panel(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // panel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->panel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_panelModality(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // panelModality()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem::PanelModality cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->panelModality();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_parentItem(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->parentItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
            Shiboken::Object::setParent(pyResult, self);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_parentObject(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsObject * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->parentObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_parentWidget(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsWidget * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->parentWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::setParent(pyResult, self);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_pos(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->pos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_prepareGeometryChange(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // prepareGeometryChange()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->prepareGeometryChange();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_removeFromIndex(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // removeFromIndex()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeFromIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_removeSceneEventFilter(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeSceneEventFilter(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // removeSceneEventFilter(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_removeSceneEventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeSceneEventFilter(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeSceneEventFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_removeSceneEventFilter_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.removeSceneEventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_resetTransform(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetTransform()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_rotate(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rotate(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // rotate(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_rotate_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rotate(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->rotate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_rotate_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.rotate", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_rotation(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rotation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->rotation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_scale(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QGraphicsItemFunc_scale_TypeError;

    if (!PyArg_UnpackTuple(args, "scale", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scale()const
    // 1: scale(qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // scale()const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // scale(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_scale_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // scale() const
        {

            if (!PyErr_Occurred()) {
                // scale()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->scale();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
            }
            break;
        }
        case 1: // scale(qreal sx, qreal sy)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // scale(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->scale(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_scale_TypeError:
        const char* overloads[] = {"", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.scale", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_scene(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scene()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsScene * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->scene();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], cppResult);

            // Begin code injection

            // TEMPLATE - scene_return_parenting - START
            if (cppResult) {
            QObject* parent = cppResult->parent();
            Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], parent));
            Shiboken::Object::setParent(pyParent, pyResult);
            }
            // TEMPLATE - scene_return_parenting - END

            // End of code injection
            Shiboken::Object::setParent(pyResult, self);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_sceneBoundingRect(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sceneBoundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->sceneBoundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_sceneEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sceneEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // sceneEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_sceneEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sceneEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::sceneEvent(cppArg0) : cppSelf->sceneEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_sceneEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.sceneEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_sceneEventFilter(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sceneEventFilter", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sceneEventFilter(QGraphicsItem*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // sceneEventFilter(QGraphicsItem*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_sceneEventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sceneEventFilter(QGraphicsItem*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::sceneEventFilter(cppArg0, cppArg1) : cppSelf->sceneEventFilter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsItemFunc_sceneEventFilter_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.sceneEventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_scenePos(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scenePos()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->scenePos();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_sceneTransform(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sceneTransform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->sceneTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_scroll(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.scroll(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.scroll(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:scroll", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: scroll(qreal,qreal,QRectF)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // scroll(qreal,qreal,QRectF)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
            overloadId = 0; // scroll(qreal,qreal,QRectF)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_scroll_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "rect");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.scroll(): got multiple values for keyword argument 'rect'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsItemFunc_scroll_TypeError;
            }
        }
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QRectF cppArg2_local = QRectF();
        ::QRectF* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // scroll(qreal,qreal,QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scroll(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_scroll_TypeError:
        const char* overloads[] = {"float, float, PySide.QtCore.QRectF = QRectF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.scroll", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setAcceptDrops(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptDrops(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAcceptDrops(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setAcceptDrops_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptDrops(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptDrops(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setAcceptDrops_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setAcceptDrops", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setAcceptHoverEvents(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptHoverEvents(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAcceptHoverEvents(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setAcceptHoverEvents_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptHoverEvents(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptHoverEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setAcceptHoverEvents_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setAcceptHoverEvents", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setAcceptTouchEvents(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptTouchEvents(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAcceptTouchEvents(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setAcceptTouchEvents_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptTouchEvents(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptTouchEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setAcceptTouchEvents_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setAcceptTouchEvents", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setAcceptedMouseButtons(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptedMouseButtons(QFlags<Qt::MouseButton>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_MOUSEBUTTON__IDX]), (pyArg)))) {
        overloadId = 0; // setAcceptedMouseButtons(QFlags<Qt::MouseButton>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setAcceptedMouseButtons_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::MouseButton> cppArg0 = ((::QFlags<Qt::MouseButton>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptedMouseButtons(QFlags<Qt::MouseButton>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptedMouseButtons(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setAcceptedMouseButtons_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.MouseButtons", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setAcceptedMouseButtons", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setAcceptsHoverEvents(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptsHoverEvents(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAcceptsHoverEvents(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setAcceptsHoverEvents_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptsHoverEvents(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptsHoverEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setAcceptsHoverEvents_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setAcceptsHoverEvents", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setActive(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActive(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setActive(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setActive_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActive(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActive(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setActive_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setActive", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setBoundingRegionGranularity(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBoundingRegionGranularity(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBoundingRegionGranularity(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setBoundingRegionGranularity_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBoundingRegionGranularity(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBoundingRegionGranularity(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setBoundingRegionGranularity_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setBoundingRegionGranularity", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setCacheMode(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setCacheMode(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setCacheMode(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setCacheMode", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCacheMode(QGraphicsItem::CacheMode,QSize)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setCacheMode(QGraphicsItem::CacheMode,QSize)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))) {
            overloadId = 0; // setCacheMode(QGraphicsItem::CacheMode,QSize)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setCacheMode_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "cacheSize");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setCacheMode(): got multiple values for keyword argument 'cacheSize'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsItemFunc_setCacheMode_TypeError;
            }
        }
        ::QGraphicsItem::CacheMode cppArg0 = ((::QGraphicsItem::CacheMode)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSize cppArg1_local = QSize();
        ::QSize* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // setCacheMode(QGraphicsItem::CacheMode,QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCacheMode(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setCacheMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem.CacheMode, PySide.QtCore.QSize = QSize()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setCacheMode", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setCursor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursor(QCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // setCursor(QCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCursor cppArg0_local = ::QCursor();
        ::QCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCursor(QCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setCursor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setData(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setData(int,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setData(int,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setData(int,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setData_TypeError:
        const char* overloads[] = {"int, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setData", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setFiltersChildEvents(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFiltersChildEvents(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFiltersChildEvents(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setFiltersChildEvents_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFiltersChildEvents(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFiltersChildEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setFiltersChildEvents_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setFiltersChildEvents", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setFlag(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setFlag(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setFlag(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setFlag", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFlag(QGraphicsItem::GraphicsItemFlag,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setFlag(QGraphicsItem::GraphicsItemFlag,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setFlag(QGraphicsItem::GraphicsItemFlag,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setFlag_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "enabled");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setFlag(): got multiple values for keyword argument 'enabled'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsItemFunc_setFlag_TypeError;
            }
        }
        ::QGraphicsItem::GraphicsItemFlag cppArg0 = ((::QGraphicsItem::GraphicsItemFlag)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFlag(QGraphicsItem::GraphicsItemFlag,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFlag(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setFlag_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem.GraphicsItemFlag, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setFlag", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setFlags(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFlags(QFlags<QGraphicsItem::GraphicsItemFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFlags(QFlags<QGraphicsItem::GraphicsItemFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setFlags_TypeError;

    // Call function/method
    {
        ::QFlags<QGraphicsItem::GraphicsItemFlag> cppArg0 = ((::QFlags<QGraphicsItem::GraphicsItemFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFlags(QFlags<QGraphicsItem::GraphicsItemFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setFlags_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem.GraphicsItemFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setFlags", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setFocus(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setFocus(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:setFocus", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: setFocus(Qt::FocusReason)
    if (numArgs == 0) {
        overloadId = 0; // setFocus(Qt::FocusReason)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]), (pyArgs[0])))) {
        overloadId = 0; // setFocus(Qt::FocusReason)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setFocus_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "focusReason");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setFocus(): got multiple values for keyword argument 'focusReason'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsItemFunc_setFocus_TypeError;
            }
        }
        ::Qt::FocusReason cppArg0 = Qt::OtherFocusReason;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // setFocus(Qt::FocusReason)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setFocus_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.FocusReason = Qt.OtherFocusReason", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setFocus", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setFocusProxy(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFocusProxy(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // setFocusProxy(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setFocusProxy_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFocusProxy(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocusProxy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setFocusProxy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setFocusProxy", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setGraphicsEffect(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGraphicsEffect(QGraphicsEffect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSEFFECT_IDX], (pyArg)))) {
        overloadId = 0; // setGraphicsEffect(QGraphicsEffect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setGraphicsEffect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsEffect* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGraphicsEffect(QGraphicsEffect*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGraphicsEffect(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setGraphicsEffect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsEffect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setGraphicsEffect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setGroup(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGroup(QGraphicsItemGroup*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEMGROUP_IDX], (pyArg)))) {
        overloadId = 0; // setGroup(QGraphicsItemGroup*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setGroup_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItemGroup* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGroup(QGraphicsItemGroup*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setGroup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItemGroup", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setGroup", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setHandlesChildEvents(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHandlesChildEvents(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHandlesChildEvents(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setHandlesChildEvents_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHandlesChildEvents(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHandlesChildEvents(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setHandlesChildEvents_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setHandlesChildEvents", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setInputMethodHints(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInputMethodHints(QFlags<Qt::InputMethodHint>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_INPUTMETHODHINT__IDX]), (pyArg)))) {
        overloadId = 0; // setInputMethodHints(QFlags<Qt::InputMethodHint>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setInputMethodHints_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::InputMethodHint> cppArg0 = ((::QFlags<Qt::InputMethodHint>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInputMethodHints(QFlags<Qt::InputMethodHint>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInputMethodHints(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setInputMethodHints_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodHints", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setInputMethodHints", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setOpacity(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOpacity(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setOpacity(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setOpacity_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOpacity(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOpacity(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setOpacity_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setOpacity", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setPanelModality(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPanelModality(QGraphicsItem::PanelModality)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX]), (pyArg)))) {
        overloadId = 0; // setPanelModality(QGraphicsItem::PanelModality)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setPanelModality_TypeError;

    // Call function/method
    {
        ::QGraphicsItem::PanelModality cppArg0 = ((::QGraphicsItem::PanelModality)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPanelModality(QGraphicsItem::PanelModality)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPanelModality(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setPanelModality_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem.PanelModality", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setPanelModality", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setParentItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setParentItem(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // setParentItem(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setParentItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParentItem(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setParentItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArg, self);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setParentItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setParentItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setPos(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPos", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPos(QPointF)
    // 1: setPos(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setPos(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setPos(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setPos_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPos(const QPointF & pos)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setPos(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPos(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPos(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPos(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPos(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setPos", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setRotation(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRotation(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setRotation(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setRotation_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRotation(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRotation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setRotation_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setRotation", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setScale(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScale(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setScale(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setScale_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScale(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScale(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setScale_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setScale", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setSelected(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelected(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSelected(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setSelected_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelected(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelected(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setSelected_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setSelected", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setToolTip_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setToolTip(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToolTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setTransform(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setTransform(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setTransform(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setTransform", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTransform(QTransform,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setTransform(QTransform,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setTransform(QTransform,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setTransform_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.setTransform(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsItemFunc_setTransform_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setTransform(QTransform,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransform(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setTransform", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setTransformOriginPoint(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setTransformOriginPoint", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTransformOriginPoint(QPointF)
    // 1: setTransformOriginPoint(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setTransformOriginPoint(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setTransformOriginPoint(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setTransformOriginPoint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setTransformOriginPoint(const QPointF & origin)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setTransformOriginPoint(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setTransformOriginPoint(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setTransformOriginPoint(qreal ax, qreal ay)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setTransformOriginPoint(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setTransformOriginPoint(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setTransformOriginPoint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.setTransformOriginPoint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setTransformations(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransformations(QList<QGraphicsTransform*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX], (pyArg)))) {
        overloadId = 0; // setTransformations(QList<QGraphicsTransform*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setTransformations_TypeError;

    // Call function/method
    {
        ::QList<QGraphicsTransform * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTransformations(QList<QGraphicsTransform*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransformations(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setTransformations_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setTransformations", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setVisible", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setX(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setX(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setX(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setX_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setX(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setX(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setX_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setX", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setY(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setY(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setY(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setY_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setY(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setY(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setY_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setY", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_setZValue(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setZValue(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setZValue(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_setZValue_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setZValue(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setZValue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_setZValue_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.setZValue", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_shape(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shape()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::shape() : const_cast<const ::QGraphicsItem*>(cppSelf)->shape();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_shear(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "shear", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: shear(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // shear(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_shear_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // shear(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->shear(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_shear_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.shear", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_show(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // show()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->show();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_stackBefore(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stackBefore(const QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // stackBefore(const QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_stackBefore_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // stackBefore(const QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stackBefore(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_stackBefore_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.stackBefore", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_toGraphicsObject(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toGraphicsObject()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsObject * cppResult = cppSelf->toGraphicsObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSOBJECT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_toolTip(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->toolTip();
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

static PyObject* Sbk_QGraphicsItemFunc_topLevelItem(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topLevelItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->topLevelItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_topLevelWidget(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // topLevelWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsWidget * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->topLevelWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_transform(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->transform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_transformOriginPoint(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transformOriginPoint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->transformOriginPoint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_transformations(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transformations()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsTransform * > cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->transformations();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSTRANSFORMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_translate(PyObject* self, PyObject* args)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translate", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: translate(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // translate(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_translate_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // translate(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->translate(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_translate_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.translate", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_type(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsItem*>(cppSelf)->::QGraphicsItem::type() : const_cast<const ::QGraphicsItem*>(cppSelf)->type();
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

static PyObject* Sbk_QGraphicsItemFunc_ungrabKeyboard(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ungrabKeyboard()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->ungrabKeyboard();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_ungrabMouse(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ungrabMouse()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->ungrabMouse();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_unsetCursor(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unsetCursor()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->unsetCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_update(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.update(): too many arguments");
        return 0;
    } else if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsItemFunc_update_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:update", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: update(QRectF)
    // 1: update(qreal,qreal,qreal,qreal)
    if (numArgs == 0) {
        overloadId = 0; // update(QRectF)
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // update(qreal,qreal,qreal,qreal)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // update(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_update_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // update(const QRectF & rect)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsItem.update(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsItemFunc_update_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (pythonToCpp[0]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);
            }

            if (!PyErr_Occurred()) {
                // update(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->update(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // update(qreal x, qreal y, qreal width, qreal height)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            qreal cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // update(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->update(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_update_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF = QRectF()", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsItem.update", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_updateMicroFocus(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateMicroFocus()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateMicroFocus();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsItemFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QGraphicsSceneWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QGraphicsSceneWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsItemFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QGraphicsSceneWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsItem::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsItemFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsItem.wheelEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsItemFunc_window(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // window()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsWidget * cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->window();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_x(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // x()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->x();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_y(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // y()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->y();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsItemFunc_zValue(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // zValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsItem*>(cppSelf)->zValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QGraphicsItem_methods[] = {
    {"acceptDrops", (PyCFunction)Sbk_QGraphicsItemFunc_acceptDrops, METH_NOARGS},
    {"acceptHoverEvents", (PyCFunction)Sbk_QGraphicsItemFunc_acceptHoverEvents, METH_NOARGS},
    {"acceptTouchEvents", (PyCFunction)Sbk_QGraphicsItemFunc_acceptTouchEvents, METH_NOARGS},
    {"acceptedMouseButtons", (PyCFunction)Sbk_QGraphicsItemFunc_acceptedMouseButtons, METH_NOARGS},
    {"acceptsHoverEvents", (PyCFunction)Sbk_QGraphicsItemFunc_acceptsHoverEvents, METH_NOARGS},
    {"addToIndex", (PyCFunction)Sbk_QGraphicsItemFunc_addToIndex, METH_NOARGS},
    {"advance", (PyCFunction)Sbk_QGraphicsItemFunc_advance, METH_O},
    {"boundingRect", (PyCFunction)Sbk_QGraphicsItemFunc_boundingRect, METH_NOARGS},
    {"boundingRegion", (PyCFunction)Sbk_QGraphicsItemFunc_boundingRegion, METH_O},
    {"boundingRegionGranularity", (PyCFunction)Sbk_QGraphicsItemFunc_boundingRegionGranularity, METH_NOARGS},
    {"cacheMode", (PyCFunction)Sbk_QGraphicsItemFunc_cacheMode, METH_NOARGS},
    {"childItems", (PyCFunction)Sbk_QGraphicsItemFunc_childItems, METH_NOARGS},
    {"childrenBoundingRect", (PyCFunction)Sbk_QGraphicsItemFunc_childrenBoundingRect, METH_NOARGS},
    {"clearFocus", (PyCFunction)Sbk_QGraphicsItemFunc_clearFocus, METH_NOARGS},
    {"clipPath", (PyCFunction)Sbk_QGraphicsItemFunc_clipPath, METH_NOARGS},
    {"collidesWithItem", (PyCFunction)Sbk_QGraphicsItemFunc_collidesWithItem, METH_VARARGS|METH_KEYWORDS},
    {"collidesWithPath", (PyCFunction)Sbk_QGraphicsItemFunc_collidesWithPath, METH_VARARGS|METH_KEYWORDS},
    {"collidingItems", (PyCFunction)Sbk_QGraphicsItemFunc_collidingItems, METH_VARARGS|METH_KEYWORDS},
    {"commonAncestorItem", (PyCFunction)Sbk_QGraphicsItemFunc_commonAncestorItem, METH_O},
    {"contains", (PyCFunction)Sbk_QGraphicsItemFunc_contains, METH_O},
    {"contextMenuEvent", (PyCFunction)Sbk_QGraphicsItemFunc_contextMenuEvent, METH_O},
    {"cursor", (PyCFunction)Sbk_QGraphicsItemFunc_cursor, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QGraphicsItemFunc_data, METH_O},
    {"deviceTransform", (PyCFunction)Sbk_QGraphicsItemFunc_deviceTransform, METH_O},
    {"dragEnterEvent", (PyCFunction)Sbk_QGraphicsItemFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QGraphicsItemFunc_dragLeaveEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QGraphicsItemFunc_dragMoveEvent, METH_O},
    {"dropEvent", (PyCFunction)Sbk_QGraphicsItemFunc_dropEvent, METH_O},
    {"effectiveOpacity", (PyCFunction)Sbk_QGraphicsItemFunc_effectiveOpacity, METH_NOARGS},
    {"ensureVisible", (PyCFunction)Sbk_QGraphicsItemFunc_ensureVisible, METH_VARARGS|METH_KEYWORDS},
    {"extension", (PyCFunction)Sbk_QGraphicsItemFunc_extension, METH_O},
    {"filtersChildEvents", (PyCFunction)Sbk_QGraphicsItemFunc_filtersChildEvents, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QGraphicsItemFunc_flags, METH_NOARGS},
    {"focusInEvent", (PyCFunction)Sbk_QGraphicsItemFunc_focusInEvent, METH_O},
    {"focusItem", (PyCFunction)Sbk_QGraphicsItemFunc_focusItem, METH_NOARGS},
    {"focusOutEvent", (PyCFunction)Sbk_QGraphicsItemFunc_focusOutEvent, METH_O},
    {"focusProxy", (PyCFunction)Sbk_QGraphicsItemFunc_focusProxy, METH_NOARGS},
    {"focusScopeItem", (PyCFunction)Sbk_QGraphicsItemFunc_focusScopeItem, METH_NOARGS},
    {"grabKeyboard", (PyCFunction)Sbk_QGraphicsItemFunc_grabKeyboard, METH_NOARGS},
    {"grabMouse", (PyCFunction)Sbk_QGraphicsItemFunc_grabMouse, METH_NOARGS},
    {"graphicsEffect", (PyCFunction)Sbk_QGraphicsItemFunc_graphicsEffect, METH_NOARGS},
    {"group", (PyCFunction)Sbk_QGraphicsItemFunc_group, METH_NOARGS},
    {"handlesChildEvents", (PyCFunction)Sbk_QGraphicsItemFunc_handlesChildEvents, METH_NOARGS},
    {"hasCursor", (PyCFunction)Sbk_QGraphicsItemFunc_hasCursor, METH_NOARGS},
    {"hasFocus", (PyCFunction)Sbk_QGraphicsItemFunc_hasFocus, METH_NOARGS},
    {"hide", (PyCFunction)Sbk_QGraphicsItemFunc_hide, METH_NOARGS},
    {"hoverEnterEvent", (PyCFunction)Sbk_QGraphicsItemFunc_hoverEnterEvent, METH_O},
    {"hoverLeaveEvent", (PyCFunction)Sbk_QGraphicsItemFunc_hoverLeaveEvent, METH_O},
    {"hoverMoveEvent", (PyCFunction)Sbk_QGraphicsItemFunc_hoverMoveEvent, METH_O},
    {"inputMethodEvent", (PyCFunction)Sbk_QGraphicsItemFunc_inputMethodEvent, METH_O},
    {"inputMethodHints", (PyCFunction)Sbk_QGraphicsItemFunc_inputMethodHints, METH_NOARGS},
    {"inputMethodQuery", (PyCFunction)Sbk_QGraphicsItemFunc_inputMethodQuery, METH_O},
    {"installSceneEventFilter", (PyCFunction)Sbk_QGraphicsItemFunc_installSceneEventFilter, METH_O},
    {"isActive", (PyCFunction)Sbk_QGraphicsItemFunc_isActive, METH_NOARGS},
    {"isAncestorOf", (PyCFunction)Sbk_QGraphicsItemFunc_isAncestorOf, METH_O},
    {"isBlockedByModalPanel", (PyCFunction)Sbk_QGraphicsItemFunc_isBlockedByModalPanel, METH_NOARGS},
    {"isClipped", (PyCFunction)Sbk_QGraphicsItemFunc_isClipped, METH_NOARGS},
    {"isEnabled", (PyCFunction)Sbk_QGraphicsItemFunc_isEnabled, METH_NOARGS},
    {"isObscured", (PyCFunction)Sbk_QGraphicsItemFunc_isObscured, METH_VARARGS},
    {"isObscuredBy", (PyCFunction)Sbk_QGraphicsItemFunc_isObscuredBy, METH_O},
    {"isPanel", (PyCFunction)Sbk_QGraphicsItemFunc_isPanel, METH_NOARGS},
    {"isSelected", (PyCFunction)Sbk_QGraphicsItemFunc_isSelected, METH_NOARGS},
    {"isUnderMouse", (PyCFunction)Sbk_QGraphicsItemFunc_isUnderMouse, METH_NOARGS},
    {"isVisible", (PyCFunction)Sbk_QGraphicsItemFunc_isVisible, METH_NOARGS},
    {"isVisibleTo", (PyCFunction)Sbk_QGraphicsItemFunc_isVisibleTo, METH_O},
    {"isWidget", (PyCFunction)Sbk_QGraphicsItemFunc_isWidget, METH_NOARGS},
    {"isWindow", (PyCFunction)Sbk_QGraphicsItemFunc_isWindow, METH_NOARGS},
    {"itemChange", (PyCFunction)Sbk_QGraphicsItemFunc_itemChange, METH_VARARGS},
    {"itemTransform", (PyCFunction)Sbk_QGraphicsItemFunc_itemTransform, METH_O},
    {"keyPressEvent", (PyCFunction)Sbk_QGraphicsItemFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QGraphicsItemFunc_keyReleaseEvent, METH_O},
    {"mapFromItem", (PyCFunction)Sbk_QGraphicsItemFunc_mapFromItem, METH_VARARGS},
    {"mapFromParent", (PyCFunction)Sbk_QGraphicsItemFunc_mapFromParent, METH_VARARGS},
    {"mapFromScene", (PyCFunction)Sbk_QGraphicsItemFunc_mapFromScene, METH_VARARGS},
    {"mapRectFromItem", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectFromItem, METH_VARARGS},
    {"mapRectFromParent", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectFromParent, METH_VARARGS},
    {"mapRectFromScene", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectFromScene, METH_VARARGS},
    {"mapRectToItem", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectToItem, METH_VARARGS},
    {"mapRectToParent", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectToParent, METH_VARARGS},
    {"mapRectToScene", (PyCFunction)Sbk_QGraphicsItemFunc_mapRectToScene, METH_VARARGS},
    {"mapToItem", (PyCFunction)Sbk_QGraphicsItemFunc_mapToItem, METH_VARARGS},
    {"mapToParent", (PyCFunction)Sbk_QGraphicsItemFunc_mapToParent, METH_VARARGS},
    {"mapToScene", (PyCFunction)Sbk_QGraphicsItemFunc_mapToScene, METH_VARARGS},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QGraphicsItemFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QGraphicsItemFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QGraphicsItemFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QGraphicsItemFunc_mouseReleaseEvent, METH_O},
    {"moveBy", (PyCFunction)Sbk_QGraphicsItemFunc_moveBy, METH_VARARGS},
    {"opacity", (PyCFunction)Sbk_QGraphicsItemFunc_opacity, METH_NOARGS},
    {"opaqueArea", (PyCFunction)Sbk_QGraphicsItemFunc_opaqueArea, METH_NOARGS},
    {"paint", (PyCFunction)Sbk_QGraphicsItemFunc_paint, METH_VARARGS|METH_KEYWORDS},
    {"panel", (PyCFunction)Sbk_QGraphicsItemFunc_panel, METH_NOARGS},
    {"panelModality", (PyCFunction)Sbk_QGraphicsItemFunc_panelModality, METH_NOARGS},
    {"parentItem", (PyCFunction)Sbk_QGraphicsItemFunc_parentItem, METH_NOARGS},
    {"parentObject", (PyCFunction)Sbk_QGraphicsItemFunc_parentObject, METH_NOARGS},
    {"parentWidget", (PyCFunction)Sbk_QGraphicsItemFunc_parentWidget, METH_NOARGS},
    {"pos", (PyCFunction)Sbk_QGraphicsItemFunc_pos, METH_NOARGS},
    {"prepareGeometryChange", (PyCFunction)Sbk_QGraphicsItemFunc_prepareGeometryChange, METH_NOARGS},
    {"removeFromIndex", (PyCFunction)Sbk_QGraphicsItemFunc_removeFromIndex, METH_NOARGS},
    {"removeSceneEventFilter", (PyCFunction)Sbk_QGraphicsItemFunc_removeSceneEventFilter, METH_O},
    {"resetTransform", (PyCFunction)Sbk_QGraphicsItemFunc_resetTransform, METH_NOARGS},
    {"rotate", (PyCFunction)Sbk_QGraphicsItemFunc_rotate, METH_O},
    {"rotation", (PyCFunction)Sbk_QGraphicsItemFunc_rotation, METH_NOARGS},
    {"scale", (PyCFunction)Sbk_QGraphicsItemFunc_scale, METH_VARARGS},
    {"scene", (PyCFunction)Sbk_QGraphicsItemFunc_scene, METH_NOARGS},
    {"sceneBoundingRect", (PyCFunction)Sbk_QGraphicsItemFunc_sceneBoundingRect, METH_NOARGS},
    {"sceneEvent", (PyCFunction)Sbk_QGraphicsItemFunc_sceneEvent, METH_O},
    {"sceneEventFilter", (PyCFunction)Sbk_QGraphicsItemFunc_sceneEventFilter, METH_VARARGS},
    {"scenePos", (PyCFunction)Sbk_QGraphicsItemFunc_scenePos, METH_NOARGS},
    {"sceneTransform", (PyCFunction)Sbk_QGraphicsItemFunc_sceneTransform, METH_NOARGS},
    {"scroll", (PyCFunction)Sbk_QGraphicsItemFunc_scroll, METH_VARARGS|METH_KEYWORDS},
    {"setAcceptDrops", (PyCFunction)Sbk_QGraphicsItemFunc_setAcceptDrops, METH_O},
    {"setAcceptHoverEvents", (PyCFunction)Sbk_QGraphicsItemFunc_setAcceptHoverEvents, METH_O},
    {"setAcceptTouchEvents", (PyCFunction)Sbk_QGraphicsItemFunc_setAcceptTouchEvents, METH_O},
    {"setAcceptedMouseButtons", (PyCFunction)Sbk_QGraphicsItemFunc_setAcceptedMouseButtons, METH_O},
    {"setAcceptsHoverEvents", (PyCFunction)Sbk_QGraphicsItemFunc_setAcceptsHoverEvents, METH_O},
    {"setActive", (PyCFunction)Sbk_QGraphicsItemFunc_setActive, METH_O},
    {"setBoundingRegionGranularity", (PyCFunction)Sbk_QGraphicsItemFunc_setBoundingRegionGranularity, METH_O},
    {"setCacheMode", (PyCFunction)Sbk_QGraphicsItemFunc_setCacheMode, METH_VARARGS|METH_KEYWORDS},
    {"setCursor", (PyCFunction)Sbk_QGraphicsItemFunc_setCursor, METH_O},
    {"setData", (PyCFunction)Sbk_QGraphicsItemFunc_setData, METH_VARARGS},
    {"setEnabled", (PyCFunction)Sbk_QGraphicsItemFunc_setEnabled, METH_O},
    {"setFiltersChildEvents", (PyCFunction)Sbk_QGraphicsItemFunc_setFiltersChildEvents, METH_O},
    {"setFlag", (PyCFunction)Sbk_QGraphicsItemFunc_setFlag, METH_VARARGS|METH_KEYWORDS},
    {"setFlags", (PyCFunction)Sbk_QGraphicsItemFunc_setFlags, METH_O},
    {"setFocus", (PyCFunction)Sbk_QGraphicsItemFunc_setFocus, METH_VARARGS|METH_KEYWORDS},
    {"setFocusProxy", (PyCFunction)Sbk_QGraphicsItemFunc_setFocusProxy, METH_O},
    {"setGraphicsEffect", (PyCFunction)Sbk_QGraphicsItemFunc_setGraphicsEffect, METH_O},
    {"setGroup", (PyCFunction)Sbk_QGraphicsItemFunc_setGroup, METH_O},
    {"setHandlesChildEvents", (PyCFunction)Sbk_QGraphicsItemFunc_setHandlesChildEvents, METH_O},
    {"setInputMethodHints", (PyCFunction)Sbk_QGraphicsItemFunc_setInputMethodHints, METH_O},
    {"setOpacity", (PyCFunction)Sbk_QGraphicsItemFunc_setOpacity, METH_O},
    {"setPanelModality", (PyCFunction)Sbk_QGraphicsItemFunc_setPanelModality, METH_O},
    {"setParentItem", (PyCFunction)Sbk_QGraphicsItemFunc_setParentItem, METH_O},
    {"setPos", (PyCFunction)Sbk_QGraphicsItemFunc_setPos, METH_VARARGS},
    {"setRotation", (PyCFunction)Sbk_QGraphicsItemFunc_setRotation, METH_O},
    {"setScale", (PyCFunction)Sbk_QGraphicsItemFunc_setScale, METH_O},
    {"setSelected", (PyCFunction)Sbk_QGraphicsItemFunc_setSelected, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QGraphicsItemFunc_setToolTip, METH_O},
    {"setTransform", (PyCFunction)Sbk_QGraphicsItemFunc_setTransform, METH_VARARGS|METH_KEYWORDS},
    {"setTransformOriginPoint", (PyCFunction)Sbk_QGraphicsItemFunc_setTransformOriginPoint, METH_VARARGS},
    {"setTransformations", (PyCFunction)Sbk_QGraphicsItemFunc_setTransformations, METH_O},
    {"setVisible", (PyCFunction)Sbk_QGraphicsItemFunc_setVisible, METH_O},
    {"setX", (PyCFunction)Sbk_QGraphicsItemFunc_setX, METH_O},
    {"setY", (PyCFunction)Sbk_QGraphicsItemFunc_setY, METH_O},
    {"setZValue", (PyCFunction)Sbk_QGraphicsItemFunc_setZValue, METH_O},
    {"shape", (PyCFunction)Sbk_QGraphicsItemFunc_shape, METH_NOARGS},
    {"shear", (PyCFunction)Sbk_QGraphicsItemFunc_shear, METH_VARARGS},
    {"show", (PyCFunction)Sbk_QGraphicsItemFunc_show, METH_NOARGS},
    {"stackBefore", (PyCFunction)Sbk_QGraphicsItemFunc_stackBefore, METH_O},
    {"toGraphicsObject", (PyCFunction)Sbk_QGraphicsItemFunc_toGraphicsObject, METH_NOARGS},
    {"toolTip", (PyCFunction)Sbk_QGraphicsItemFunc_toolTip, METH_NOARGS},
    {"topLevelItem", (PyCFunction)Sbk_QGraphicsItemFunc_topLevelItem, METH_NOARGS},
    {"topLevelWidget", (PyCFunction)Sbk_QGraphicsItemFunc_topLevelWidget, METH_NOARGS},
    {"transform", (PyCFunction)Sbk_QGraphicsItemFunc_transform, METH_NOARGS},
    {"transformOriginPoint", (PyCFunction)Sbk_QGraphicsItemFunc_transformOriginPoint, METH_NOARGS},
    {"transformations", (PyCFunction)Sbk_QGraphicsItemFunc_transformations, METH_NOARGS},
    {"translate", (PyCFunction)Sbk_QGraphicsItemFunc_translate, METH_VARARGS},
    {"type", (PyCFunction)Sbk_QGraphicsItemFunc_type, METH_NOARGS},
    {"ungrabKeyboard", (PyCFunction)Sbk_QGraphicsItemFunc_ungrabKeyboard, METH_NOARGS},
    {"ungrabMouse", (PyCFunction)Sbk_QGraphicsItemFunc_ungrabMouse, METH_NOARGS},
    {"unsetCursor", (PyCFunction)Sbk_QGraphicsItemFunc_unsetCursor, METH_NOARGS},
    {"update", (PyCFunction)Sbk_QGraphicsItemFunc_update, METH_VARARGS|METH_KEYWORDS},
    {"updateMicroFocus", (PyCFunction)Sbk_QGraphicsItemFunc_updateMicroFocus, METH_NOARGS},
    {"wheelEvent", (PyCFunction)Sbk_QGraphicsItemFunc_wheelEvent, METH_O},
    {"window", (PyCFunction)Sbk_QGraphicsItemFunc_window, METH_NOARGS},
    {"x", (PyCFunction)Sbk_QGraphicsItemFunc_x, METH_NOARGS},
    {"y", (PyCFunction)Sbk_QGraphicsItemFunc_y, METH_NOARGS},
    {"zValue", (PyCFunction)Sbk_QGraphicsItemFunc_zValue, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QGraphicsItem__repr__(PyObject* self)
{
    ::QGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsItem",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QGraphicsItem__repr__,
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
    /*tp_traverse*/         Sbk_QGraphicsItem_traverse,
    /*tp_clear*/            Sbk_QGraphicsItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsItem_Init,
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

PyObject* SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem::GraphicsItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem::GraphicsItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem::GraphicsItemFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsItem::GraphicsItemFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsItem::GraphicsItemFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), self, &cppSelf);
    ::QGraphicsItem::GraphicsItemFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag_long,
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
static void QGraphicsItem_GraphicsItemFlag_PythonToCpp_QGraphicsItem_GraphicsItemFlag(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsItem::GraphicsItemFlag*)cppOut) = (::QGraphicsItem::GraphicsItemFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsItem_GraphicsItemFlag_PythonToCpp_QGraphicsItem_GraphicsItemFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX]))
        return QGraphicsItem_GraphicsItemFlag_PythonToCpp_QGraphicsItem_GraphicsItemFlag;
    return 0;
}
static PyObject* QGraphicsItem_GraphicsItemFlag_CppToPython_QGraphicsItem_GraphicsItemFlag(const void* cppIn) {
    int castCppIn = *((::QGraphicsItem::GraphicsItemFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX], castCppIn);

}

static void QFlags_QGraphicsItem_GraphicsItemFlag__PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsItem::GraphicsItemFlag>*)cppOut) = ::QFlags<QGraphicsItem::GraphicsItemFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsItem_GraphicsItemFlag__PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]))
        return QFlags_QGraphicsItem_GraphicsItemFlag__PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_;
    return 0;
}
static PyObject* QFlags_QGraphicsItem_GraphicsItemFlag__CppToPython_QFlags_QGraphicsItem_GraphicsItemFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsItem::GraphicsItemFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]));

}

static void QGraphicsItem_GraphicsItemFlag_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsItem::GraphicsItemFlag>*)cppOut) = ::QFlags<QGraphicsItem::GraphicsItemFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsItem_GraphicsItemFlag_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX]))
        return QGraphicsItem_GraphicsItemFlag_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsItem::GraphicsItemFlag>*)cppOut) = ::QFlags<QGraphicsItem::GraphicsItemFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_;
    return 0;
}
static void QGraphicsItem_GraphicsItemChange_PythonToCpp_QGraphicsItem_GraphicsItemChange(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsItem::GraphicsItemChange*)cppOut) = (::QGraphicsItem::GraphicsItemChange) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsItem_GraphicsItemChange_PythonToCpp_QGraphicsItem_GraphicsItemChange_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX]))
        return QGraphicsItem_GraphicsItemChange_PythonToCpp_QGraphicsItem_GraphicsItemChange;
    return 0;
}
static PyObject* QGraphicsItem_GraphicsItemChange_CppToPython_QGraphicsItem_GraphicsItemChange(const void* cppIn) {
    int castCppIn = *((::QGraphicsItem::GraphicsItemChange*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX], castCppIn);

}

static void QGraphicsItem_CacheMode_PythonToCpp_QGraphicsItem_CacheMode(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsItem::CacheMode*)cppOut) = (::QGraphicsItem::CacheMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsItem_CacheMode_PythonToCpp_QGraphicsItem_CacheMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX]))
        return QGraphicsItem_CacheMode_PythonToCpp_QGraphicsItem_CacheMode;
    return 0;
}
static PyObject* QGraphicsItem_CacheMode_CppToPython_QGraphicsItem_CacheMode(const void* cppIn) {
    int castCppIn = *((::QGraphicsItem::CacheMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX], castCppIn);

}

static void QGraphicsItem_PanelModality_PythonToCpp_QGraphicsItem_PanelModality(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsItem::PanelModality*)cppOut) = (::QGraphicsItem::PanelModality) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsItem_PanelModality_PythonToCpp_QGraphicsItem_PanelModality_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX]))
        return QGraphicsItem_PanelModality_PythonToCpp_QGraphicsItem_PanelModality;
    return 0;
}
static PyObject* QGraphicsItem_PanelModality_CppToPython_QGraphicsItem_PanelModality(const void* cppIn) {
    int castCppIn = *((::QGraphicsItem::PanelModality*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX], castCppIn);

}

static void QGraphicsItem_Extension_PythonToCpp_QGraphicsItem_Extension(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsItem::Extension*)cppOut) = (::QGraphicsItem::Extension) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsItem_Extension_PythonToCpp_QGraphicsItem_Extension_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX]))
        return QGraphicsItem_Extension_PythonToCpp_QGraphicsItem_Extension;
    return 0;
}
static PyObject* QGraphicsItem_Extension_CppToPython_QGraphicsItem_Extension(const void* cppIn) {
    int castCppIn = *((::QGraphicsItem::Extension*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsItem_PythonToCpp_QGraphicsItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsItem_PythonToCpp_QGraphicsItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsItem_Type))
        return QGraphicsItem_PythonToCpp_QGraphicsItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsItem_PTR_CppToPython_QGraphicsItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsItem", "QGraphicsItem*",
        &Sbk_QGraphicsItem_Type, &Shiboken::callCppDestructor< ::QGraphicsItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsItem_Type,
        QGraphicsItem_PythonToCpp_QGraphicsItem_PTR,
        is_QGraphicsItem_PythonToCpp_QGraphicsItem_PTR_Convertible,
        QGraphicsItem_PTR_CppToPython_QGraphicsItem);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsItemWrapper).name());



    // Initialization of enums.

    // Initialization of enum 'GraphicsItemFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX] = PySide::QFlags::create("GraphicsItemFlags", &SbkPySide_QtGui_QGraphicsItem_GraphicsItemFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsItem_Type,
        "GraphicsItemFlag",
        "PySide.QtGui.QGraphicsItem.GraphicsItemFlag",
        "QGraphicsItem::GraphicsItemFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIsMovable", (long) QGraphicsItem::ItemIsMovable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIsSelectable", (long) QGraphicsItem::ItemIsSelectable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIsFocusable", (long) QGraphicsItem::ItemIsFocusable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemClipsToShape", (long) QGraphicsItem::ItemClipsToShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemClipsChildrenToShape", (long) QGraphicsItem::ItemClipsChildrenToShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIgnoresTransformations", (long) QGraphicsItem::ItemIgnoresTransformations))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIgnoresParentOpacity", (long) QGraphicsItem::ItemIgnoresParentOpacity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemDoesntPropagateOpacityToChildren", (long) QGraphicsItem::ItemDoesntPropagateOpacityToChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemStacksBehindParent", (long) QGraphicsItem::ItemStacksBehindParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemUsesExtendedStyleOption", (long) QGraphicsItem::ItemUsesExtendedStyleOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemHasNoContents", (long) QGraphicsItem::ItemHasNoContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSendsGeometryChanges", (long) QGraphicsItem::ItemSendsGeometryChanges))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemAcceptsInputMethod", (long) QGraphicsItem::ItemAcceptsInputMethod))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemNegativeZStacksBehindParent", (long) QGraphicsItem::ItemNegativeZStacksBehindParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIsPanel", (long) QGraphicsItem::ItemIsPanel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemIsFocusScope", (long) QGraphicsItem::ItemIsFocusScope))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSendsScenePositionChanges", (long) QGraphicsItem::ItemSendsScenePositionChanges))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemStopsClickFocusPropagation", (long) QGraphicsItem::ItemStopsClickFocusPropagation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
        &Sbk_QGraphicsItem_Type, "ItemStopsFocusHandling", (long) QGraphicsItem::ItemStopsFocusHandling))
        return ;
    // Register converter for enum 'QGraphicsItem::GraphicsItemFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX],
            QGraphicsItem_GraphicsItemFlag_CppToPython_QGraphicsItem_GraphicsItemFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_GraphicsItemFlag_PythonToCpp_QGraphicsItem_GraphicsItemFlag,
            is_QGraphicsItem_GraphicsItemFlag_PythonToCpp_QGraphicsItem_GraphicsItemFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem::GraphicsItemFlag");
        Shiboken::Conversions::registerConverterName(converter, "GraphicsItemFlag");
    }
    // Register converter for flag 'QFlags<QGraphicsItem::GraphicsItemFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX],
            QFlags_QGraphicsItem_GraphicsItemFlag__CppToPython_QFlags_QGraphicsItem_GraphicsItemFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_GraphicsItemFlag_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_,
            is_QGraphicsItem_GraphicsItemFlag_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsItem_GraphicsItemFlag__PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_,
            is_QFlags_QGraphicsItem_GraphicsItemFlag__PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag_,
            is_number_PythonToCpp_QFlags_QGraphicsItem_GraphicsItemFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSITEM_GRAPHICSITEMFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsItem::GraphicsItemFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<GraphicsItemFlag>");
    }
    // End of 'GraphicsItemFlag' enum/flags.

    // Initialization of enum 'GraphicsItemChange'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsItem_Type,
        "GraphicsItemChange",
        "PySide.QtGui.QGraphicsItem.GraphicsItemChange",
        "QGraphicsItem::GraphicsItemChange");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemPositionChange", (long) QGraphicsItem::ItemPositionChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemMatrixChange", (long) QGraphicsItem::ItemMatrixChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemVisibleChange", (long) QGraphicsItem::ItemVisibleChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemEnabledChange", (long) QGraphicsItem::ItemEnabledChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSelectedChange", (long) QGraphicsItem::ItemSelectedChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemParentChange", (long) QGraphicsItem::ItemParentChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemChildAddedChange", (long) QGraphicsItem::ItemChildAddedChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemChildRemovedChange", (long) QGraphicsItem::ItemChildRemovedChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemTransformChange", (long) QGraphicsItem::ItemTransformChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemPositionHasChanged", (long) QGraphicsItem::ItemPositionHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemTransformHasChanged", (long) QGraphicsItem::ItemTransformHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSceneChange", (long) QGraphicsItem::ItemSceneChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemVisibleHasChanged", (long) QGraphicsItem::ItemVisibleHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemEnabledHasChanged", (long) QGraphicsItem::ItemEnabledHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSelectedHasChanged", (long) QGraphicsItem::ItemSelectedHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemParentHasChanged", (long) QGraphicsItem::ItemParentHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemSceneHasChanged", (long) QGraphicsItem::ItemSceneHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemCursorChange", (long) QGraphicsItem::ItemCursorChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemCursorHasChanged", (long) QGraphicsItem::ItemCursorHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemToolTipChange", (long) QGraphicsItem::ItemToolTipChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemToolTipHasChanged", (long) QGraphicsItem::ItemToolTipHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemFlagsChange", (long) QGraphicsItem::ItemFlagsChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemFlagsHaveChanged", (long) QGraphicsItem::ItemFlagsHaveChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemZValueChange", (long) QGraphicsItem::ItemZValueChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemZValueHasChanged", (long) QGraphicsItem::ItemZValueHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemOpacityChange", (long) QGraphicsItem::ItemOpacityChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemOpacityHasChanged", (long) QGraphicsItem::ItemOpacityHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemScenePositionHasChanged", (long) QGraphicsItem::ItemScenePositionHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemRotationChange", (long) QGraphicsItem::ItemRotationChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemRotationHasChanged", (long) QGraphicsItem::ItemRotationHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemScaleChange", (long) QGraphicsItem::ItemScaleChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemScaleHasChanged", (long) QGraphicsItem::ItemScaleHasChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemTransformOriginPointChange", (long) QGraphicsItem::ItemTransformOriginPointChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemTransformOriginPointHasChanged", (long) QGraphicsItem::ItemTransformOriginPointHasChanged))
        return ;
    // Register converter for enum 'QGraphicsItem::GraphicsItemChange'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX],
            QGraphicsItem_GraphicsItemChange_CppToPython_QGraphicsItem_GraphicsItemChange);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_GraphicsItemChange_PythonToCpp_QGraphicsItem_GraphicsItemChange,
            is_QGraphicsItem_GraphicsItemChange_PythonToCpp_QGraphicsItem_GraphicsItemChange_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_GRAPHICSITEMCHANGE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem::GraphicsItemChange");
        Shiboken::Conversions::registerConverterName(converter, "GraphicsItemChange");
    }
    // End of 'GraphicsItemChange' enum.

    // Initialization of enum 'CacheMode'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsItem_Type,
        "CacheMode",
        "PySide.QtGui.QGraphicsItem.CacheMode",
        "QGraphicsItem::CacheMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX],
        &Sbk_QGraphicsItem_Type, "NoCache", (long) QGraphicsItem::NoCache))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX],
        &Sbk_QGraphicsItem_Type, "ItemCoordinateCache", (long) QGraphicsItem::ItemCoordinateCache))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX],
        &Sbk_QGraphicsItem_Type, "DeviceCoordinateCache", (long) QGraphicsItem::DeviceCoordinateCache))
        return ;
    // Register converter for enum 'QGraphicsItem::CacheMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX],
            QGraphicsItem_CacheMode_CppToPython_QGraphicsItem_CacheMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_CacheMode_PythonToCpp_QGraphicsItem_CacheMode,
            is_QGraphicsItem_CacheMode_PythonToCpp_QGraphicsItem_CacheMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_CACHEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem::CacheMode");
        Shiboken::Conversions::registerConverterName(converter, "CacheMode");
    }
    // End of 'CacheMode' enum.

    // Initialization of enum 'PanelModality'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsItem_Type,
        "PanelModality",
        "PySide.QtGui.QGraphicsItem.PanelModality",
        "QGraphicsItem::PanelModality");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX],
        &Sbk_QGraphicsItem_Type, "NonModal", (long) QGraphicsItem::NonModal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX],
        &Sbk_QGraphicsItem_Type, "PanelModal", (long) QGraphicsItem::PanelModal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX],
        &Sbk_QGraphicsItem_Type, "SceneModal", (long) QGraphicsItem::SceneModal))
        return ;
    // Register converter for enum 'QGraphicsItem::PanelModality'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX],
            QGraphicsItem_PanelModality_CppToPython_QGraphicsItem_PanelModality);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_PanelModality_PythonToCpp_QGraphicsItem_PanelModality,
            is_QGraphicsItem_PanelModality_PythonToCpp_QGraphicsItem_PanelModality_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_PANELMODALITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem::PanelModality");
        Shiboken::Conversions::registerConverterName(converter, "PanelModality");
    }
    // End of 'PanelModality' enum.

    // Initialization of enum 'Extension'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsItem_Type,
        "Extension",
        "PySide.QtGui.QGraphicsItem.Extension",
        "QGraphicsItem::Extension");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX],
        &Sbk_QGraphicsItem_Type, "UserExtension", (long) QGraphicsItem::UserExtension))
        return ;
    // Register converter for enum 'QGraphicsItem::Extension'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX],
            QGraphicsItem_Extension_CppToPython_QGraphicsItem_Extension);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsItem_Extension_PythonToCpp_QGraphicsItem_Extension,
            is_QGraphicsItem_Extension_PythonToCpp_QGraphicsItem_Extension_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_EXTENSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsItem::Extension");
        Shiboken::Conversions::registerConverterName(converter, "Extension");
    }
    // End of 'Extension' enum.



    // Begin code injection

    PyObject* userTypeConstant =  PyInt_FromLong(QGraphicsItem::UserType);
    PyDict_SetItemString(Sbk_QGraphicsItem_Type.super.ht_type.tp_dict, "UserType", userTypeConstant);

    // End of code injection
    qRegisterMetaType< ::QGraphicsItem::GraphicsItemFlag >("QGraphicsItem::GraphicsItemFlag");
    qRegisterMetaType< ::QGraphicsItem::GraphicsItemFlags >("QGraphicsItem::GraphicsItemFlags");
    qRegisterMetaType< ::QGraphicsItem::GraphicsItemChange >("QGraphicsItem::GraphicsItemChange");
    qRegisterMetaType< ::QGraphicsItem::CacheMode >("QGraphicsItem::CacheMode");
    qRegisterMetaType< ::QGraphicsItem::PanelModality >("QGraphicsItem::PanelModality");
    qRegisterMetaType< ::QGraphicsItem::Extension >("QGraphicsItem::Extension");
}

