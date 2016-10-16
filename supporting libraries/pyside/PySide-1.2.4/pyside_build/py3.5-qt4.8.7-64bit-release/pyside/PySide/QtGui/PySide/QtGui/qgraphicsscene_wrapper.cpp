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
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtgui_python.h"

#include "qgraphicsscene_wrapper.h"

// Extra includes
#include <QList>
#include <QVarLengthArray>
#include <qbrush.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qevent.h>
#include <qfont.h>
#include <qgraphicsitem.h>
#include <qgraphicsproxywidget.h>
#include <qgraphicsscene.h>
#include <qgraphicssceneevent.h>
#include <qgraphicsview.h>
#include <qgraphicswidget.h>
#include <qline.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpalette.h>
#include <qpen.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>
#include <qstyle.h>
#include <qthread.h>
#include <qtransform.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QGraphicsSceneWrapper::QGraphicsSceneWrapper(QObject * parent) : QGraphicsScene(parent) {
    // ... middle
}

QGraphicsSceneWrapper::QGraphicsSceneWrapper(const QRectF & sceneRect, QObject * parent) : QGraphicsScene(sceneRect, parent) {
    // ... middle
}

QGraphicsSceneWrapper::QGraphicsSceneWrapper(qreal x, qreal y, qreal width, qreal height, QObject * parent) : QGraphicsScene(x, y, width, height, parent) {
    // ... middle
}

void QGraphicsSceneWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
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

void QGraphicsSceneWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsSceneWrapper::contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::contextMenuEvent(event);
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

void QGraphicsSceneWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
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

void QGraphicsSceneWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsSceneWrapper::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::dragEnterEvent(event);
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

void QGraphicsSceneWrapper::dragLeaveEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::dragLeaveEvent(event);
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

void QGraphicsSceneWrapper::dragMoveEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::dragMoveEvent(event);
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

void QGraphicsSceneWrapper::drawBackground(QPainter * painter, const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawBackground"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::drawBackground(painter, rect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &rect)
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

void QGraphicsSceneWrapper::drawForeground(QPainter * painter, const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawForeground"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::drawForeground(painter, rect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &rect)
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

void QGraphicsSceneWrapper::dropEvent(QGraphicsSceneDragDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::dropEvent(event);
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

bool QGraphicsSceneWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsScene.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsSceneWrapper::eventFilter(QObject * watched, QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::eventFilter(watched, event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], watched),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsScene.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QGraphicsSceneWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::focusInEvent(event);
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

void QGraphicsSceneWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::focusOutEvent(event);
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

void QGraphicsSceneWrapper::helpEvent(QGraphicsSceneHelpEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "helpEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::helpEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHELPEVENT_IDX], event)
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

void QGraphicsSceneWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::inputMethodEvent(event);
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

QVariant QGraphicsSceneWrapper::inputMethodQuery(Qt::InputMethodQuery query) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::inputMethodQuery(query);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsScene.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsSceneWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::keyPressEvent(event);
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

void QGraphicsSceneWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::keyReleaseEvent(event);
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

void QGraphicsSceneWrapper::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::mouseDoubleClickEvent(event);
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

void QGraphicsSceneWrapper::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::mouseMoveEvent(event);
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

void QGraphicsSceneWrapper::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::mousePressEvent(event);
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

void QGraphicsSceneWrapper::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::mouseReleaseEvent(event);
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

void QGraphicsSceneWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
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

void QGraphicsSceneWrapper::wheelEvent(QGraphicsSceneWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsScene::wheelEvent(event);
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

const QMetaObject* QGraphicsSceneWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGraphicsScene::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGraphicsSceneWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGraphicsScene::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGraphicsSceneWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGraphicsSceneWrapper* >(this));
        return QGraphicsScene::qt_metacast(_clname);
}

QGraphicsSceneWrapper::~QGraphicsSceneWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsScene_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsScene >()))
        return -1;

    ::QGraphicsSceneWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsScene_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:QGraphicsScene", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsScene(QObject*)
    // 1: QGraphicsScene(QRectF,QObject*)
    // 2: QGraphicsScene(qreal,qreal,qreal,qreal,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsScene(QObject*)
    } else if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 2; // QGraphicsScene(qreal,qreal,qreal,qreal,QObject*)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[4])))) {
            overloadId = 2; // QGraphicsScene(qreal,qreal,qreal,qreal,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QGraphicsScene(QRectF,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QGraphicsScene(QRectF,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsScene(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsScene_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGraphicsScene(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsScene_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGraphicsScene(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGraphicsSceneWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGraphicsSceneWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QGraphicsScene(const QRectF & sceneRect, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QGraphicsScene_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGraphicsScene(QRectF,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGraphicsSceneWrapper(*cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGraphicsSceneWrapper(*cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 2: // QGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[4]))))
                        goto Sbk_QGraphicsScene_Init_TypeError;
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
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QObject* cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QGraphicsScene(qreal,qreal,qreal,qreal,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGraphicsSceneWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGraphicsSceneWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[4], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsScene >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsScene_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGraphicsScene_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "PySide.QtCore.QRectF, PySide.QtCore.QObject = None", "float, float, float, float, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsSceneFunc_activePanel(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activePanel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->activePanel();
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

static PyObject* Sbk_QGraphicsSceneFunc_activeWindow(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activeWindow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsWidget * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->activeWindow();
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

static PyObject* Sbk_QGraphicsSceneFunc_addEllipse(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addEllipse", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addEllipse(QRectF,QPen,QBrush)
    // 1: addEllipse(qreal,qreal,qreal,qreal,QPen,QBrush)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // addEllipse(qreal,qreal,qreal,qreal,QPen,QBrush)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addEllipse(qreal,qreal,qreal,qreal,QPen,QBrush)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5])))) {
                overloadId = 1; // addEllipse(qreal,qreal,qreal,qreal,QPen,QBrush)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addEllipse(QRectF,QPen,QBrush)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addEllipse(QRectF,QPen,QBrush)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))) {
                overloadId = 0; // addEllipse(QRectF,QPen,QBrush)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addEllipse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addEllipse(const QRectF & rect, const QPen & pen, const QBrush & brush)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_addEllipse_TypeError;
                }
                value = PyDict_GetItemString(kwds, "brush");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): got multiple values for keyword argument 'brush'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2]))))
                        goto Sbk_QGraphicsSceneFunc_addEllipse_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPen cppArg1_local = QPen();
            ::QPen* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QBrush cppArg2_local = QBrush();
            ::QBrush* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // addEllipse(QRectF,QPen,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsEllipseItem * cppResult = cppSelf->addEllipse(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSELLIPSEITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // addEllipse(qreal x, qreal y, qreal w, qreal h, const QPen & pen, const QBrush & brush)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4]))))
                        goto Sbk_QGraphicsSceneFunc_addEllipse_TypeError;
                }
                value = PyDict_GetItemString(kwds, "brush");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addEllipse(): got multiple values for keyword argument 'brush'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5]))))
                        goto Sbk_QGraphicsSceneFunc_addEllipse_TypeError;
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
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPen cppArg4_local = QPen();
            ::QPen* cppArg4 = &cppArg4_local;
            if (pythonToCpp[4]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);
            }
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QBrush cppArg5_local = QBrush();
            ::QBrush* cppArg5 = &cppArg5_local;
            if (pythonToCpp[5]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[5]))
                pythonToCpp[5](pyArgs[5], &cppArg5_local);
            else
                pythonToCpp[5](pyArgs[5], &cppArg5);
            }

            if (!PyErr_Occurred()) {
                // addEllipse(qreal,qreal,qreal,qreal,QPen,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsEllipseItem * cppResult = cppSelf->addEllipse(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4, *cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSELLIPSEITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addEllipse_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", "float, float, float, float, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addEllipse", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addItem(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // addItem(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addItem(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_addItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.addItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addLine(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addLine(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addLine(): not enough arguments");
        return 0;
    } else if (numArgs == 3)
        goto Sbk_QGraphicsSceneFunc_addLine_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:addLine", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: addLine(QLineF,QPen)
    // 1: addLine(qreal,qreal,qreal,qreal,QPen)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // addLine(qreal,qreal,qreal,qreal,QPen)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4])))) {
            overloadId = 1; // addLine(qreal,qreal,qreal,qreal,QPen)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addLine(QLineF,QPen)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
            overloadId = 0; // addLine(QLineF,QPen)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addLine_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addLine(const QLineF & line, const QPen & pen)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addLine(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_addLine_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPen cppArg1_local = QPen();
            ::QPen* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // addLine(QLineF,QPen)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsLineItem * cppResult = cppSelf->addLine(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLINEITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // addLine(qreal x1, qreal y1, qreal x2, qreal y2, const QPen & pen)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addLine(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4]))))
                        goto Sbk_QGraphicsSceneFunc_addLine_TypeError;
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
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPen cppArg4_local = QPen();
            ::QPen* cppArg4 = &cppArg4_local;
            if (pythonToCpp[4]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);
            }

            if (!PyErr_Occurred()) {
                // addLine(qreal,qreal,qreal,qreal,QPen)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsLineItem * cppResult = cppSelf->addLine(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLINEITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addLine_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLineF, PySide.QtGui.QPen = QPen()", "float, float, float, float, PySide.QtGui.QPen = QPen()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addLine", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addPath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPath(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPath(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addPath", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addPath(QPainterPath,QPen,QBrush)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addPath(QPainterPath,QPen,QBrush)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addPath(QPainterPath,QPen,QBrush)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))) {
                overloadId = 0; // addPath(QPainterPath,QPen,QBrush)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addPath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "pen");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPath(): got multiple values for keyword argument 'pen'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_addPath_TypeError;
            }
            value = PyDict_GetItemString(kwds, "brush");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPath(): got multiple values for keyword argument 'brush'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsSceneFunc_addPath_TypeError;
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

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPen cppArg1_local = QPen();
        ::QPen* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QBrush cppArg2_local = QBrush();
        ::QBrush* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // addPath(QPainterPath,QPen,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsPathItem * cppResult = cppSelf->addPath(*cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSPATHITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addPath", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addPixmap(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addPixmap(QPixmap)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArg)))) {
        overloadId = 0; // addPixmap(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addPixmap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPixmap cppArg0_local = ::QPixmap();
        ::QPixmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addPixmap(QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsPixmapItem * cppResult = cppSelf->addPixmap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSPIXMAPITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.addPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addPolygon(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPolygon(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPolygon(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addPolygon", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addPolygon(QPolygonF,QPen,QBrush)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addPolygon(QPolygonF,QPen,QBrush)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addPolygon(QPolygonF,QPen,QBrush)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))) {
                overloadId = 0; // addPolygon(QPolygonF,QPen,QBrush)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addPolygon_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "pen");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPolygon(): got multiple values for keyword argument 'pen'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_addPolygon_TypeError;
            }
            value = PyDict_GetItemString(kwds, "brush");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addPolygon(): got multiple values for keyword argument 'brush'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsSceneFunc_addPolygon_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPolygonF cppArg0_local = ::QPolygonF();
        ::QPolygonF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPen cppArg1_local = QPen();
        ::QPen* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QBrush cppArg2_local = QBrush();
        ::QBrush* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // addPolygon(QPolygonF,QPen,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsPolygonItem * cppResult = cppSelf->addPolygon(*cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSPOLYGONITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addPolygon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPolygonF, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addRect(QRectF,QPen,QBrush)
    // 1: addRect(qreal,qreal,qreal,qreal,QPen,QBrush)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // addRect(qreal,qreal,qreal,qreal,QPen,QBrush)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addRect(qreal,qreal,qreal,qreal,QPen,QBrush)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5])))) {
                overloadId = 1; // addRect(qreal,qreal,qreal,qreal,QPen,QBrush)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addRect(QRectF,QPen,QBrush)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addRect(QRectF,QPen,QBrush)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))) {
                overloadId = 0; // addRect(QRectF,QPen,QBrush)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addRect(const QRectF & rect, const QPen & pen, const QBrush & brush)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_addRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "brush");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): got multiple values for keyword argument 'brush'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2]))))
                        goto Sbk_QGraphicsSceneFunc_addRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPen cppArg1_local = QPen();
            ::QPen* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QBrush cppArg2_local = QBrush();
            ::QBrush* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // addRect(QRectF,QPen,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsRectItem * cppResult = cppSelf->addRect(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSRECTITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // addRect(qreal x, qreal y, qreal w, qreal h, const QPen & pen, const QBrush & brush)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pen");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): got multiple values for keyword argument 'pen'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[4]))))
                        goto Sbk_QGraphicsSceneFunc_addRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "brush");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addRect(): got multiple values for keyword argument 'brush'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5]))))
                        goto Sbk_QGraphicsSceneFunc_addRect_TypeError;
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
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPen cppArg4_local = QPen();
            ::QPen* cppArg4 = &cppArg4_local;
            if (pythonToCpp[4]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);
            }
            if (!Shiboken::Object::isValid(pyArgs[5]))
                return 0;
            ::QBrush cppArg5_local = QBrush();
            ::QBrush* cppArg5 = &cppArg5_local;
            if (pythonToCpp[5]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[5]))
                pythonToCpp[5](pyArgs[5], &cppArg5_local);
            else
                pythonToCpp[5](pyArgs[5], &cppArg5);
            }

            if (!PyErr_Occurred()) {
                // addRect(qreal,qreal,qreal,qreal,QPen,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsRectItem * cppResult = cppSelf->addRect(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4, *cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSRECTITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", "float, float, float, float, PySide.QtGui.QPen = QPen(), PySide.QtGui.QBrush = QBrush()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addRect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addSimpleText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addSimpleText(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addSimpleText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addSimpleText", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addSimpleText(QString,QFont)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addSimpleText(QString,QFont)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1])))) {
            overloadId = 0; // addSimpleText(QString,QFont)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addSimpleText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "font");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addSimpleText(): got multiple values for keyword argument 'font'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_addSimpleText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QFont cppArg1_local = QFont();
        ::QFont* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // addSimpleText(QString,QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsSimpleTextItem * cppResult = cppSelf->addSimpleText(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSIMPLETEXTITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addSimpleText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QFont = QFont()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addSimpleText", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addText(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addText", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addText(QString,QFont)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addText(QString,QFont)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1])))) {
            overloadId = 0; // addText(QString,QFont)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "font");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addText(): got multiple values for keyword argument 'font'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_addText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QFont cppArg1_local = QFont();
        ::QFont* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // addText(QString,QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsTextItem * cppResult = cppSelf->addText(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSTEXTITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QFont = QFont()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addText", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_addWidget(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addWidget(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addWidget(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addWidget", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addWidget(QWidget*,QFlags<Qt::WindowType>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addWidget(QWidget*,QFlags<Qt::WindowType>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[1])))) {
            overloadId = 0; // addWidget(QWidget*,QFlags<Qt::WindowType>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_addWidget_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "wFlags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.addWidget(): got multiple values for keyword argument 'wFlags'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_addWidget_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::WindowType> cppArg1 = QFlags<Qt::WindowType>(0);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addWidget(QWidget*,QFlags<Qt::WindowType>)
            // Begin code injection

            QGraphicsProxyWidget * cppResult = cppSelf->addWidget(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSPROXYWIDGET_IDX], cppResult);
            Shiboken::Object::keepReference((SbkObject*)pyResult, "setWidget(QWidget*)1", pyArgs[1-1]);

            // End of code injection


            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_addWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.WindowFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.addWidget", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_advance(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // advance()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->advance();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsSceneFunc_backgroundBrush(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->backgroundBrush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_bspTreeDepth(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bspTreeDepth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->bspTreeDepth();
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

static PyObject* Sbk_QGraphicsSceneFunc_clear(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            // Begin code injection

            const QList<QGraphicsItem*> items = cppSelf->items();
            Shiboken::BindingManager& bm = Shiboken::BindingManager::instance();
            foreach (QGraphicsItem* item, items) {
                SbkObject* obj = bm.retrieveWrapper(item);
                if (obj) {
                    if (reinterpret_cast<PyObject*>(obj)->ob_refcnt > 1) // If the refcnt is 1 the object will vannish anyway.
                        Shiboken::Object::invalidate(obj);
                    Shiboken::Object::removeParent(obj);
                }
            }
            cppSelf->clear();

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsSceneFunc_clearFocus(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QGraphicsSceneFunc_clearSelection(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearSelection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearSelection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsSceneFunc_collidingItems(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.collidingItems(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.collidingItems(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:collidingItems", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: collidingItems(const QGraphicsItem*,Qt::ItemSelectionMode)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // collidingItems(const QGraphicsItem*,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // collidingItems(const QGraphicsItem*,Qt::ItemSelectionMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_collidingItems_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.collidingItems(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_collidingItems_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // collidingItems(const QGraphicsItem*,Qt::ItemSelectionMode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->collidingItems(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_collidingItems_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.collidingItems", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QGraphicsSceneContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENECONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QGraphicsSceneContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QGraphicsSceneContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_createItemGroup(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: createItemGroup(QList<QGraphicsItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], (pyArg)))) {
        overloadId = 0; // createItemGroup(QList<QGraphicsItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_createItemGroup_TypeError;

    // Call function/method
    {
        ::QList<QGraphicsItem * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createItemGroup(QList<QGraphicsItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItemGroup * cppResult = cppSelf->createItemGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEMGROUP_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::setParent(pyResult, pyArg);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_createItemGroup_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.createItemGroup", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_destroyItemGroup(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: destroyItemGroup(QGraphicsItemGroup*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEMGROUP_IDX], (pyArg)))) {
        overloadId = 0; // destroyItemGroup(QGraphicsItemGroup*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_destroyItemGroup_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItemGroup* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // destroyItemGroup(QGraphicsItemGroup*)
            // Begin code injection

            QGraphicsItem* parentItem = cppArg0->parentItem();
            Shiboken::AutoDecRef parent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], parentItem));
            foreach (QGraphicsItem* item, cppArg0->children())
                Shiboken::Object::setParent(parent, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], item));
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->destroyItemGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // the arg was destroyed by Qt.
            Shiboken::Object::invalidate(pyArg);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_destroyItemGroup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItemGroup", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.destroyItemGroup", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_drawBackground(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawBackground", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawBackground(QPainter*,QRectF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawBackground(QPainter*,QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_drawBackground_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
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
            // drawBackground(QPainter*,QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::drawBackground(cppArg0, *cppArg1) : cppSelf->drawBackground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_drawBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.drawBackground", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_drawForeground(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawForeground", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawForeground(QPainter*,QRectF)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawForeground(QPainter*,QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_drawForeground_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
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
            // drawForeground(QPainter*,QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::drawForeground(cppArg0, *cppArg1) : cppSelf->drawForeground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_drawForeground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.drawForeground", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QGraphicsSceneDragDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEDRAGDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QGraphicsSceneDragDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneDragDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QGraphicsSceneDragDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneDragDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.event", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_eventFilter(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "eventFilter", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: eventFilter(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // eventFilter(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_eventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // eventFilter(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::eventFilter(cppArg0, cppArg1) : cppSelf->eventFilter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_eventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.eventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_focusItem(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // focusItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->focusItem();
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

static PyObject* Sbk_QGraphicsSceneFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusNextPrevChild(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // focusNextPrevChild(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_font(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_foregroundBrush(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // foregroundBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->foregroundBrush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_hasFocus(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->hasFocus();
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

static PyObject* Sbk_QGraphicsSceneFunc_height(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->height();
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

static PyObject* Sbk_QGraphicsSceneFunc_helpEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: helpEvent(QGraphicsSceneHelpEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEHELPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // helpEvent(QGraphicsSceneHelpEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_helpEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneHelpEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // helpEvent(QGraphicsSceneHelpEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::helpEvent(cppArg0) : cppSelf->helpEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_helpEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneHelpEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.helpEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsScene*>(cppSelf)->::QGraphicsScene::inputMethodQuery(cppArg0) : const_cast<const ::QGraphicsScene*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_invalidate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.invalidate(): too many arguments");
        return 0;
    } else if (numArgs == 3)
        goto Sbk_QGraphicsSceneFunc_invalidate_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:invalidate", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: invalidate(QRectF,QFlags<QGraphicsScene::SceneLayer>)
    // 1: invalidate(qreal,qreal,qreal,qreal,QFlags<QGraphicsScene::SceneLayer>)
    if (numArgs == 0) {
        overloadId = 0; // invalidate(QRectF,QFlags<QGraphicsScene::SceneLayer>)
    } else if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // invalidate(qreal,qreal,qreal,qreal,QFlags<QGraphicsScene::SceneLayer>)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[4])))) {
            overloadId = 1; // invalidate(qreal,qreal,qreal,qreal,QFlags<QGraphicsScene::SceneLayer>)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // invalidate(QRectF,QFlags<QGraphicsScene::SceneLayer>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[1])))) {
            overloadId = 0; // invalidate(QRectF,QFlags<QGraphicsScene::SceneLayer>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_invalidate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // invalidate(const QRectF & rect, QFlags<QGraphicsScene::SceneLayer> layers)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.invalidate(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsSceneFunc_invalidate_TypeError;
                }
                value = PyDict_GetItemString(kwds, "layers");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.invalidate(): got multiple values for keyword argument 'layers'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_invalidate_TypeError;
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
            ::QFlags<QGraphicsScene::SceneLayer> cppArg1 = QGraphicsScene::AllLayers;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // invalidate(QRectF,QFlags<QGraphicsScene::SceneLayer>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->invalidate(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // invalidate(qreal x, qreal y, qreal w, qreal h, QFlags<QGraphicsScene::SceneLayer> layers)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "layers");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.invalidate(): got multiple values for keyword argument 'layers'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[4]))))
                        goto Sbk_QGraphicsSceneFunc_invalidate_TypeError;
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
            ::QFlags<QGraphicsScene::SceneLayer> cppArg4 = QGraphicsScene::AllLayers;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // invalidate(qreal,qreal,qreal,qreal,QFlags<QGraphicsScene::SceneLayer>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->invalidate(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_invalidate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF = QRectF(), PySide.QtGui.QGraphicsScene.SceneLayers = QGraphicsScene.AllLayers", "float, float, float, float, PySide.QtGui.QGraphicsScene.SceneLayers = QGraphicsScene.AllLayers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.invalidate", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_isActive(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->isActive();
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

static PyObject* Sbk_QGraphicsSceneFunc_isSortCacheEnabled(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSortCacheEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->isSortCacheEnabled();
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

static PyObject* Sbk_QGraphicsSceneFunc_itemAt(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemAt", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: itemAt(QPointF)const
    // 1: itemAt(QPointF,QTransform)const
    // 2: itemAt(qreal,qreal)const
    // 3: itemAt(qreal,qreal,QTransform)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // itemAt(qreal,qreal)const
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[2])))) {
            overloadId = 3; // itemAt(qreal,qreal,QTransform)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // itemAt(QPointF)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[1])))) {
            overloadId = 1; // itemAt(QPointF,QTransform)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_itemAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // itemAt(const QPointF & pos) const
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
                // itemAt(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemAt(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // itemAt(const QPointF & pos, const QTransform & deviceTransform) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTransform cppArg1_local = ::QTransform();
            ::QTransform* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // itemAt(QPointF,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemAt(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 2: // itemAt(qreal x, qreal y) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // itemAt(qreal,qreal)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 3: // itemAt(qreal x, qreal y, const QTransform & deviceTransform) const
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTransform cppArg2_local = ::QTransform();
            ::QTransform* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // itemAt(qreal,qreal,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemAt(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_itemAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF", "PySide.QtCore.QPointF, PySide.QtGui.QTransform", "float, float", "float, float, PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_itemIndexMethod(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // itemIndexMethod()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsScene::ItemIndexMethod cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemIndexMethod();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_items(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOO:items", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: items()const
    // 1: items(Qt::SortOrder)const
    // 2: items(QPainterPath,Qt::ItemSelectionMode)const
    // 3: items(QPainterPath,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
    // 4: items(QPointF)const
    // 5: items(QPointF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
    // 6: items(QPolygonF,Qt::ItemSelectionMode)const
    // 7: items(QPolygonF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
    // 8: items(QRectF,Qt::ItemSelectionMode)const
    // 9: items(QRectF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
    // 10: items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode)const
    // 11: items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
    if (numArgs == 0) {
        overloadId = 0; // items()const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 8; // items(QRectF,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 8; // items(QRectF,Qt::ItemSelectionMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 9; // items(QRectF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3])))) {
                    overloadId = 9; // items(QRectF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // items(QPointF)const
        } else if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 5; // items(QPointF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3])))) {
                overloadId = 5; // items(QPointF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // items(QPainterPath,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // items(QPainterPath,Qt::ItemSelectionMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 3; // items(QPainterPath,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3])))) {
                    overloadId = 3; // items(QPainterPath,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                }
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[0])))) {
        overloadId = 1; // items(Qt::SortOrder)const
    } else if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 10; // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 10; // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode)const
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[5])))) {
                if (numArgs == 6) {
                    overloadId = 11; // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[6])))) {
                    overloadId = 11; // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // items(QPolygonF,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 6; // items(QPolygonF,Qt::ItemSelectionMode)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 7; // items(QPolygonF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3])))) {
                    overloadId = 7; // items(QPolygonF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_items_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // items() const
        {

            if (!PyErr_Occurred()) {
                // items()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 1: // items(Qt::SortOrder order) const
        {
            ::Qt::SortOrder cppArg0 = ((::Qt::SortOrder)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // items(Qt::SortOrder)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 2: // items(const QPainterPath & path, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
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
                // items(QPainterPath,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 3: // items(const QPainterPath & path, Qt::ItemSelectionMode mode, Qt::SortOrder order, const QTransform & deviceTransform) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceTransform");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'deviceTransform'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
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

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::SortOrder cppArg2 = ((::Qt::SortOrder)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QTransform cppArg3_local = QTransform();
            ::QTransform* cppArg3 = &cppArg3_local;
            if (pythonToCpp[3]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);
            }

            if (!PyErr_Occurred()) {
                // items(QPainterPath,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 4: // items(const QPointF & pos) const
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
                // items(QPointF)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 5: // items(const QPointF & pos, Qt::ItemSelectionMode mode, Qt::SortOrder order, const QTransform & deviceTransform) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceTransform");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'deviceTransform'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::SortOrder cppArg2 = ((::Qt::SortOrder)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QTransform cppArg3_local = QTransform();
            ::QTransform* cppArg3 = &cppArg3_local;
            if (pythonToCpp[3]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);
            }

            if (!PyErr_Occurred()) {
                // items(QPointF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 6: // items(const QPolygonF & polygon, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // items(QPolygonF,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 7: // items(const QPolygonF & polygon, Qt::ItemSelectionMode mode, Qt::SortOrder order, const QTransform & deviceTransform) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceTransform");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'deviceTransform'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::SortOrder cppArg2 = ((::Qt::SortOrder)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QTransform cppArg3_local = QTransform();
            ::QTransform* cppArg3 = &cppArg3_local;
            if (pythonToCpp[3]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);
            }

            if (!PyErr_Occurred()) {
                // items(QPolygonF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 8: // items(const QRectF & rect, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // items(QRectF,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 9: // items(const QRectF & rect, Qt::ItemSelectionMode mode, Qt::SortOrder order, const QTransform & deviceTransform) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceTransform");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'deviceTransform'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[3]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::SortOrder cppArg2 = ((::Qt::SortOrder)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QTransform cppArg3_local = QTransform();
            ::QTransform* cppArg3 = &cppArg3_local;
            if (pythonToCpp[3]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);
            }

            if (!PyErr_Occurred()) {
                // items(QRectF,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(*cppArg0, cppArg1, cppArg2, *cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 10: // items(qreal x, qreal y, qreal w, qreal h, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[4]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
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
            ::Qt::ItemSelectionMode cppArg4 = Qt::IntersectsItemShape;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 11: // items(qreal x, qreal y, qreal w, qreal h, Qt::ItemSelectionMode mode, Qt::SortOrder order, const QTransform & deviceTransform) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "deviceTransform");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.items(): got multiple values for keyword argument 'deviceTransform'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[6]))))
                        goto Sbk_QGraphicsSceneFunc_items_TypeError;
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
            ::Qt::ItemSelectionMode cppArg4 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::Qt::SortOrder cppArg5 = ((::Qt::SortOrder)0);
            pythonToCpp[5](pyArgs[5], &cppArg5);
            if (!Shiboken::Object::isValid(pyArgs[6]))
                return 0;
            ::QTransform cppArg6_local = QTransform();
            ::QTransform* cppArg6 = &cppArg6_local;
            if (pythonToCpp[6]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[6]))
                pythonToCpp[6](pyArgs[6], &cppArg6_local);
            else
                pythonToCpp[6](pyArgs[6], &cppArg6);
            }

            if (!PyErr_Occurred()) {
                // items(qreal,qreal,qreal,qreal,Qt::ItemSelectionMode,Qt::SortOrder,QTransform)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->items(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, *cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_items_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.Qt.SortOrder", "PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtCore.Qt.SortOrder, PySide.QtGui.QTransform = QTransform()", "PySide.QtCore.QPointF", "PySide.QtCore.QPointF, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtCore.Qt.SortOrder, PySide.QtGui.QTransform = QTransform()", "PySide.QtGui.QPolygonF, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "PySide.QtGui.QPolygonF, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtCore.Qt.SortOrder, PySide.QtGui.QTransform = QTransform()", "PySide.QtCore.QRectF, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "PySide.QtCore.QRectF, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtCore.Qt.SortOrder, PySide.QtGui.QTransform = QTransform()", "float, float, float, float, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "float, float, float, float, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtCore.Qt.SortOrder, PySide.QtGui.QTransform = QTransform()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.items", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_itemsBoundingRect(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // itemsBoundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->itemsBoundingRect();
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

static PyObject* Sbk_QGraphicsSceneFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_keyReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyReleaseEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_mouseGrabberItem(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mouseGrabberItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->mouseGrabberItem();
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

static PyObject* Sbk_QGraphicsSceneFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QGraphicsSceneMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QGraphicsSceneMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QGraphicsSceneMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_palette(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // palette()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPalette cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->palette();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_removeItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeItem(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // removeItem(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_removeItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeItem(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_removeItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.removeItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_render(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.render(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.render(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:render", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[3])))) {
                    overloadId = 0; // render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_render_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "target");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.render(): got multiple values for keyword argument 'target'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_render_TypeError;
            }
            value = PyDict_GetItemString(kwds, "source");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.render(): got multiple values for keyword argument 'source'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsSceneFunc_render_TypeError;
            }
            value = PyDict_GetItemString(kwds, "aspectRatioMode");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.render(): got multiple values for keyword argument 'aspectRatioMode'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[3]))))
                    goto Sbk_QGraphicsSceneFunc_render_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRectF cppArg1_local = QRectF();
        ::QRectF* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
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
        ::Qt::AspectRatioMode cppArg3 = Qt::KeepAspectRatio;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // render(QPainter*,QRectF,QRectF,Qt::AspectRatioMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->render(cppArg0, *cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_render_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF = QRectF(), PySide.QtCore.QRectF = QRectF(), PySide.QtCore.Qt.AspectRatioMode = Qt.KeepAspectRatio", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.render", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_sceneRect(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sceneRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->sceneRect();
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

static PyObject* Sbk_QGraphicsSceneFunc_selectedItems(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedItems()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->selectedItems();
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

static PyObject* Sbk_QGraphicsSceneFunc_selectionArea(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionArea()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->selectionArea();
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

static PyObject* Sbk_QGraphicsSceneFunc_sendEvent(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sendEvent", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sendEvent(QGraphicsItem*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // sendEvent(QGraphicsItem*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_sendEvent_TypeError;

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
            // sendEvent(QGraphicsItem*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->sendEvent(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsSceneFunc_sendEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.sendEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setActivePanel(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActivePanel(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // setActivePanel(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setActivePanel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActivePanel(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActivePanel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setActivePanel_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setActivePanel", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setActiveWindow(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActiveWindow(QGraphicsWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setActiveWindow(QGraphicsWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setActiveWindow_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActiveWindow(QGraphicsWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActiveWindow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setActiveWindow_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setActiveWindow", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setBackgroundBrush(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackgroundBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackgroundBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setBackgroundBrush_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBackgroundBrush(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackgroundBrush(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setBackgroundBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setBackgroundBrush", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setBspTreeDepth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBspTreeDepth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setBspTreeDepth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setBspTreeDepth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBspTreeDepth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBspTreeDepth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setBspTreeDepth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setBspTreeDepth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setFocus(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.setFocus(): too many arguments");
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
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setFocus_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "focusReason");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.setFocus(): got multiple values for keyword argument 'focusReason'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]), (pyArgs[0]))))
                    goto Sbk_QGraphicsSceneFunc_setFocus_TypeError;
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

    Sbk_QGraphicsSceneFunc_setFocus_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.FocusReason = Qt.OtherFocusReason", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.setFocus", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setFocusItem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.setFocusItem(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.setFocusItem(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setFocusItem", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFocusItem(QGraphicsItem*,Qt::FocusReason)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setFocusItem(QGraphicsItem*,Qt::FocusReason)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setFocusItem(QGraphicsItem*,Qt::FocusReason)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setFocusItem_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "focusReason");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.setFocusItem(): got multiple values for keyword argument 'focusReason'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FOCUSREASON_IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsSceneFunc_setFocusItem_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::FocusReason cppArg1 = Qt::OtherFocusReason;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFocusItem(QGraphicsItem*,Qt::FocusReason)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFocusItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[0]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setFocusItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.Qt.FocusReason = Qt.OtherFocusReason", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.setFocusItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setForegroundBrush(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForegroundBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setForegroundBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setForegroundBrush_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setForegroundBrush(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForegroundBrush(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setForegroundBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setForegroundBrush", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setItemIndexMethod(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItemIndexMethod(QGraphicsScene::ItemIndexMethod)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX]), (pyArg)))) {
        overloadId = 0; // setItemIndexMethod(QGraphicsScene::ItemIndexMethod)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setItemIndexMethod_TypeError;

    // Call function/method
    {
        ::QGraphicsScene::ItemIndexMethod cppArg0 = ((::QGraphicsScene::ItemIndexMethod)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setItemIndexMethod(QGraphicsScene::ItemIndexMethod)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemIndexMethod(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setItemIndexMethod_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsScene.ItemIndexMethod", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setItemIndexMethod", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setPalette(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPalette(QPalette)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
        overloadId = 0; // setPalette(QPalette)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setPalette_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPalette cppArg0_local = ::QPalette();
        ::QPalette* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setPalette(QPalette)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPalette(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setPalette_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setPalette", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setSceneRect(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsSceneFunc_setSceneRect_TypeError;

    if (!PyArg_UnpackTuple(args, "setSceneRect", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setSceneRect(QRectF)
    // 1: setSceneRect(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 1; // setSceneRect(qreal,qreal,qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setSceneRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setSceneRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setSceneRect(const QRectF & rect)
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
                // setSceneRect(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSceneRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setSceneRect(qreal x, qreal y, qreal w, qreal h)
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
                // setSceneRect(qreal,qreal,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSceneRect(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setSceneRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.setSceneRect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setSelectionArea(PyObject* self, PyObject* args)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSelectionArea", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setSelectionArea(QPainterPath)
    // 1: setSelectionArea(QPainterPath,Qt::ItemSelectionMode)
    // 2: setSelectionArea(QPainterPath,Qt::ItemSelectionMode,QTransform)
    // 3: setSelectionArea(QPainterPath,QTransform)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setSelectionArea(QPainterPath)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[1])))) {
            overloadId = 3; // setSelectionArea(QPainterPath,QTransform)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // setSelectionArea(QPainterPath,Qt::ItemSelectionMode)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[2])))) {
                overloadId = 2; // setSelectionArea(QPainterPath,Qt::ItemSelectionMode,QTransform)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setSelectionArea_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setSelectionArea(const QPainterPath & path)
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
                // setSelectionArea(QPainterPath)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSelectionArea(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setSelectionArea(const QPainterPath & path, Qt::ItemSelectionMode mode)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setSelectionArea(QPainterPath,Qt::ItemSelectionMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSelectionArea(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setSelectionArea(const QPainterPath & path, Qt::ItemSelectionMode mode, const QTransform & deviceTransform)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = ((::Qt::ItemSelectionMode)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTransform cppArg2_local = ::QTransform();
            ::QTransform* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setSelectionArea(QPainterPath,Qt::ItemSelectionMode,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSelectionArea(*cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // setSelectionArea(const QPainterPath & path, const QTransform & deviceTransform)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainterPath cppArg0_local = ::QPainterPath();
            ::QPainterPath* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTransform cppArg1_local = ::QTransform();
            ::QTransform* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setSelectionArea(QPainterPath,QTransform)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSelectionArea(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setSelectionArea_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode", "PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode, PySide.QtGui.QTransform", "PySide.QtGui.QPainterPath, PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.setSelectionArea", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setSortCacheEnabled(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSortCacheEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSortCacheEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setSortCacheEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSortCacheEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSortCacheEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setSortCacheEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setSortCacheEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setStickyFocus(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStickyFocus(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setStickyFocus(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setStickyFocus_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStickyFocus(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStickyFocus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setStickyFocus_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setStickyFocus", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(QStyle*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (pyArg)))) {
        overloadId = 0; // setStyle(QStyle*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_setStyle_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStyle* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyle(QStyle*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_stickyFocus(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stickyFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->stickyFocus();
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

static PyObject* Sbk_QGraphicsSceneFunc_style(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStyle * cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_update(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.update(): too many arguments");
        return 0;
    } else if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsSceneFunc_update_TypeError;

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
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_update_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // update(const QRectF & rect)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rect");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsScene.update(): got multiple values for keyword argument 'rect'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsSceneFunc_update_TypeError;
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
        case 1: // update(qreal x, qreal y, qreal w, qreal h)
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

    Sbk_QGraphicsSceneFunc_update_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF = QRectF()", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsScene.update", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_views(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // views()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsView * > cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->views();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSVIEWPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsSceneFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QGraphicsSceneWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENEWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QGraphicsSceneWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsSceneFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsSceneWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QGraphicsSceneWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsScene::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsSceneFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsSceneWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsScene.wheelEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsSceneFunc_width(PyObject* self)
{
    ::QGraphicsScene* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsScene*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsScene*>(cppSelf)->width();
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

static PyMethodDef Sbk_QGraphicsScene_methods[] = {
    {"activePanel", (PyCFunction)Sbk_QGraphicsSceneFunc_activePanel, METH_NOARGS},
    {"activeWindow", (PyCFunction)Sbk_QGraphicsSceneFunc_activeWindow, METH_NOARGS},
    {"addEllipse", (PyCFunction)Sbk_QGraphicsSceneFunc_addEllipse, METH_VARARGS|METH_KEYWORDS},
    {"addItem", (PyCFunction)Sbk_QGraphicsSceneFunc_addItem, METH_O},
    {"addLine", (PyCFunction)Sbk_QGraphicsSceneFunc_addLine, METH_VARARGS|METH_KEYWORDS},
    {"addPath", (PyCFunction)Sbk_QGraphicsSceneFunc_addPath, METH_VARARGS|METH_KEYWORDS},
    {"addPixmap", (PyCFunction)Sbk_QGraphicsSceneFunc_addPixmap, METH_O},
    {"addPolygon", (PyCFunction)Sbk_QGraphicsSceneFunc_addPolygon, METH_VARARGS|METH_KEYWORDS},
    {"addRect", (PyCFunction)Sbk_QGraphicsSceneFunc_addRect, METH_VARARGS|METH_KEYWORDS},
    {"addSimpleText", (PyCFunction)Sbk_QGraphicsSceneFunc_addSimpleText, METH_VARARGS|METH_KEYWORDS},
    {"addText", (PyCFunction)Sbk_QGraphicsSceneFunc_addText, METH_VARARGS|METH_KEYWORDS},
    {"addWidget", (PyCFunction)Sbk_QGraphicsSceneFunc_addWidget, METH_VARARGS|METH_KEYWORDS},
    {"advance", (PyCFunction)Sbk_QGraphicsSceneFunc_advance, METH_NOARGS},
    {"backgroundBrush", (PyCFunction)Sbk_QGraphicsSceneFunc_backgroundBrush, METH_NOARGS},
    {"bspTreeDepth", (PyCFunction)Sbk_QGraphicsSceneFunc_bspTreeDepth, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QGraphicsSceneFunc_clear, METH_NOARGS},
    {"clearFocus", (PyCFunction)Sbk_QGraphicsSceneFunc_clearFocus, METH_NOARGS},
    {"clearSelection", (PyCFunction)Sbk_QGraphicsSceneFunc_clearSelection, METH_NOARGS},
    {"collidingItems", (PyCFunction)Sbk_QGraphicsSceneFunc_collidingItems, METH_VARARGS|METH_KEYWORDS},
    {"contextMenuEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_contextMenuEvent, METH_O},
    {"createItemGroup", (PyCFunction)Sbk_QGraphicsSceneFunc_createItemGroup, METH_O},
    {"destroyItemGroup", (PyCFunction)Sbk_QGraphicsSceneFunc_destroyItemGroup, METH_O},
    {"dragEnterEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_dragLeaveEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_dragMoveEvent, METH_O},
    {"drawBackground", (PyCFunction)Sbk_QGraphicsSceneFunc_drawBackground, METH_VARARGS},
    {"drawForeground", (PyCFunction)Sbk_QGraphicsSceneFunc_drawForeground, METH_VARARGS},
    {"dropEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_dropEvent, METH_O},
    {"event", (PyCFunction)Sbk_QGraphicsSceneFunc_event, METH_O},
    {"eventFilter", (PyCFunction)Sbk_QGraphicsSceneFunc_eventFilter, METH_VARARGS},
    {"focusInEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_focusInEvent, METH_O},
    {"focusItem", (PyCFunction)Sbk_QGraphicsSceneFunc_focusItem, METH_NOARGS},
    {"focusNextPrevChild", (PyCFunction)Sbk_QGraphicsSceneFunc_focusNextPrevChild, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_focusOutEvent, METH_O},
    {"font", (PyCFunction)Sbk_QGraphicsSceneFunc_font, METH_NOARGS},
    {"foregroundBrush", (PyCFunction)Sbk_QGraphicsSceneFunc_foregroundBrush, METH_NOARGS},
    {"hasFocus", (PyCFunction)Sbk_QGraphicsSceneFunc_hasFocus, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QGraphicsSceneFunc_height, METH_NOARGS},
    {"helpEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_helpEvent, METH_O},
    {"inputMethodEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_inputMethodEvent, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QGraphicsSceneFunc_inputMethodQuery, METH_O},
    {"invalidate", (PyCFunction)Sbk_QGraphicsSceneFunc_invalidate, METH_VARARGS|METH_KEYWORDS},
    {"isActive", (PyCFunction)Sbk_QGraphicsSceneFunc_isActive, METH_NOARGS},
    {"isSortCacheEnabled", (PyCFunction)Sbk_QGraphicsSceneFunc_isSortCacheEnabled, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGraphicsSceneFunc_itemAt, METH_VARARGS},
    {"itemIndexMethod", (PyCFunction)Sbk_QGraphicsSceneFunc_itemIndexMethod, METH_NOARGS},
    {"items", (PyCFunction)Sbk_QGraphicsSceneFunc_items, METH_VARARGS|METH_KEYWORDS},
    {"itemsBoundingRect", (PyCFunction)Sbk_QGraphicsSceneFunc_itemsBoundingRect, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_keyReleaseEvent, METH_O},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_mouseDoubleClickEvent, METH_O},
    {"mouseGrabberItem", (PyCFunction)Sbk_QGraphicsSceneFunc_mouseGrabberItem, METH_NOARGS},
    {"mouseMoveEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_mouseReleaseEvent, METH_O},
    {"palette", (PyCFunction)Sbk_QGraphicsSceneFunc_palette, METH_NOARGS},
    {"removeItem", (PyCFunction)Sbk_QGraphicsSceneFunc_removeItem, METH_O},
    {"render", (PyCFunction)Sbk_QGraphicsSceneFunc_render, METH_VARARGS|METH_KEYWORDS},
    {"sceneRect", (PyCFunction)Sbk_QGraphicsSceneFunc_sceneRect, METH_NOARGS},
    {"selectedItems", (PyCFunction)Sbk_QGraphicsSceneFunc_selectedItems, METH_NOARGS},
    {"selectionArea", (PyCFunction)Sbk_QGraphicsSceneFunc_selectionArea, METH_NOARGS},
    {"sendEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_sendEvent, METH_VARARGS},
    {"setActivePanel", (PyCFunction)Sbk_QGraphicsSceneFunc_setActivePanel, METH_O},
    {"setActiveWindow", (PyCFunction)Sbk_QGraphicsSceneFunc_setActiveWindow, METH_O},
    {"setBackgroundBrush", (PyCFunction)Sbk_QGraphicsSceneFunc_setBackgroundBrush, METH_O},
    {"setBspTreeDepth", (PyCFunction)Sbk_QGraphicsSceneFunc_setBspTreeDepth, METH_O},
    {"setFocus", (PyCFunction)Sbk_QGraphicsSceneFunc_setFocus, METH_VARARGS|METH_KEYWORDS},
    {"setFocusItem", (PyCFunction)Sbk_QGraphicsSceneFunc_setFocusItem, METH_VARARGS|METH_KEYWORDS},
    {"setFont", (PyCFunction)Sbk_QGraphicsSceneFunc_setFont, METH_O},
    {"setForegroundBrush", (PyCFunction)Sbk_QGraphicsSceneFunc_setForegroundBrush, METH_O},
    {"setItemIndexMethod", (PyCFunction)Sbk_QGraphicsSceneFunc_setItemIndexMethod, METH_O},
    {"setPalette", (PyCFunction)Sbk_QGraphicsSceneFunc_setPalette, METH_O},
    {"setSceneRect", (PyCFunction)Sbk_QGraphicsSceneFunc_setSceneRect, METH_VARARGS},
    {"setSelectionArea", (PyCFunction)Sbk_QGraphicsSceneFunc_setSelectionArea, METH_VARARGS},
    {"setSortCacheEnabled", (PyCFunction)Sbk_QGraphicsSceneFunc_setSortCacheEnabled, METH_O},
    {"setStickyFocus", (PyCFunction)Sbk_QGraphicsSceneFunc_setStickyFocus, METH_O},
    {"setStyle", (PyCFunction)Sbk_QGraphicsSceneFunc_setStyle, METH_O},
    {"stickyFocus", (PyCFunction)Sbk_QGraphicsSceneFunc_stickyFocus, METH_NOARGS},
    {"style", (PyCFunction)Sbk_QGraphicsSceneFunc_style, METH_NOARGS},
    {"update", (PyCFunction)Sbk_QGraphicsSceneFunc_update, METH_VARARGS|METH_KEYWORDS},
    {"views", (PyCFunction)Sbk_QGraphicsSceneFunc_views, METH_NOARGS},
    {"wheelEvent", (PyCFunction)Sbk_QGraphicsSceneFunc_wheelEvent, METH_O},
    {"width", (PyCFunction)Sbk_QGraphicsSceneFunc_width, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsScene_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsScene_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsScene_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsScene",
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
    /*tp_traverse*/         Sbk_QGraphicsScene_traverse,
    /*tp_clear*/            Sbk_QGraphicsScene_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsScene_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsScene_Init,
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

static void* Sbk_QGraphicsScene_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGraphicsScene*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QGraphicsScene_SceneLayer___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene::SceneLayers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsScene::SceneLayers)PyLong_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsScene::SceneLayers)PyInt_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsScene_SceneLayer___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene::SceneLayers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsScene::SceneLayers)PyLong_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsScene::SceneLayers)PyInt_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsScene_SceneLayer___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene::SceneLayers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsScene::SceneLayers)PyLong_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsScene::SceneLayers)PyInt_AsLong(self);
    cppArg = (QGraphicsScene::SceneLayers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsScene_SceneLayer___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsScene::SceneLayers cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), self, &cppSelf);
    ::QGraphicsScene::SceneLayers cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsScene_SceneLayer_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsScene_SceneLayer__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsScene_SceneLayer_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsScene_SceneLayer__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsScene_SceneLayer___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsScene_SceneLayer___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsScene_SceneLayer___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsScene_SceneLayer___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsScene_SceneLayer_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsScene_SceneLayer_long,
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
static void QGraphicsScene_ItemIndexMethod_PythonToCpp_QGraphicsScene_ItemIndexMethod(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsScene::ItemIndexMethod*)cppOut) = (::QGraphicsScene::ItemIndexMethod) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsScene_ItemIndexMethod_PythonToCpp_QGraphicsScene_ItemIndexMethod_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX]))
        return QGraphicsScene_ItemIndexMethod_PythonToCpp_QGraphicsScene_ItemIndexMethod;
    return 0;
}
static PyObject* QGraphicsScene_ItemIndexMethod_CppToPython_QGraphicsScene_ItemIndexMethod(const void* cppIn) {
    int castCppIn = *((::QGraphicsScene::ItemIndexMethod*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX], castCppIn);

}

static void QGraphicsScene_SceneLayer_PythonToCpp_QGraphicsScene_SceneLayer(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsScene::SceneLayer*)cppOut) = (::QGraphicsScene::SceneLayer) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsScene_SceneLayer_PythonToCpp_QGraphicsScene_SceneLayer_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX]))
        return QGraphicsScene_SceneLayer_PythonToCpp_QGraphicsScene_SceneLayer;
    return 0;
}
static PyObject* QGraphicsScene_SceneLayer_CppToPython_QGraphicsScene_SceneLayer(const void* cppIn) {
    int castCppIn = *((::QGraphicsScene::SceneLayer*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX], castCppIn);

}

static void QFlags_QGraphicsScene_SceneLayer__PythonToCpp_QFlags_QGraphicsScene_SceneLayer_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsScene::SceneLayer>*)cppOut) = ::QFlags<QGraphicsScene::SceneLayer>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsScene_SceneLayer__PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]))
        return QFlags_QGraphicsScene_SceneLayer__PythonToCpp_QFlags_QGraphicsScene_SceneLayer_;
    return 0;
}
static PyObject* QFlags_QGraphicsScene_SceneLayer__CppToPython_QFlags_QGraphicsScene_SceneLayer_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsScene::SceneLayer>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]));

}

static void QGraphicsScene_SceneLayer_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsScene::SceneLayer>*)cppOut) = ::QFlags<QGraphicsScene::SceneLayer>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsScene_SceneLayer_PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX]))
        return QGraphicsScene_SceneLayer_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsScene::SceneLayer>*)cppOut) = ::QFlags<QGraphicsScene::SceneLayer>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsScene_PythonToCpp_QGraphicsScene_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsScene_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsScene_PythonToCpp_QGraphicsScene_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsScene_Type))
        return QGraphicsScene_PythonToCpp_QGraphicsScene_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsScene_PTR_CppToPython_QGraphicsScene(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGraphicsScene*)cppIn, &Sbk_QGraphicsScene_Type);

}

void init_QGraphicsScene(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsScene_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsScene", "QGraphicsScene*",
        &Sbk_QGraphicsScene_Type, &Shiboken::callCppDestructor< ::QGraphicsScene >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsScene_Type,
        QGraphicsScene_PythonToCpp_QGraphicsScene_PTR,
        is_QGraphicsScene_PythonToCpp_QGraphicsScene_PTR_Convertible,
        QGraphicsScene_PTR_CppToPython_QGraphicsScene);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsScene");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsScene*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsScene&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsScene).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsSceneWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsScene_Type, &Sbk_QGraphicsScene_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ItemIndexMethod'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsScene_Type,
        "ItemIndexMethod",
        "PySide.QtGui.QGraphicsScene.ItemIndexMethod",
        "QGraphicsScene::ItemIndexMethod");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX],
        &Sbk_QGraphicsScene_Type, "BspTreeIndex", (long) QGraphicsScene::BspTreeIndex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX],
        &Sbk_QGraphicsScene_Type, "NoIndex", (long) QGraphicsScene::NoIndex))
        return ;
    // Register converter for enum 'QGraphicsScene::ItemIndexMethod'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX],
            QGraphicsScene_ItemIndexMethod_CppToPython_QGraphicsScene_ItemIndexMethod);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsScene_ItemIndexMethod_PythonToCpp_QGraphicsScene_ItemIndexMethod,
            is_QGraphicsScene_ItemIndexMethod_PythonToCpp_QGraphicsScene_ItemIndexMethod_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_ITEMINDEXMETHOD_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsScene::ItemIndexMethod");
        Shiboken::Conversions::registerConverterName(converter, "ItemIndexMethod");
    }
    // End of 'ItemIndexMethod' enum.

    // Initialization of enum 'SceneLayer'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX] = PySide::QFlags::create("SceneLayers", &SbkPySide_QtGui_QGraphicsScene_SceneLayer_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsScene_Type,
        "SceneLayer",
        "PySide.QtGui.QGraphicsScene.SceneLayer",
        "QGraphicsScene::SceneLayer",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX],
        &Sbk_QGraphicsScene_Type, "ItemLayer", (long) QGraphicsScene::ItemLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX],
        &Sbk_QGraphicsScene_Type, "BackgroundLayer", (long) QGraphicsScene::BackgroundLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX],
        &Sbk_QGraphicsScene_Type, "ForegroundLayer", (long) QGraphicsScene::ForegroundLayer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX],
        &Sbk_QGraphicsScene_Type, "AllLayers", (long) QGraphicsScene::AllLayers))
        return ;
    // Register converter for enum 'QGraphicsScene::SceneLayer'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX],
            QGraphicsScene_SceneLayer_CppToPython_QGraphicsScene_SceneLayer);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsScene_SceneLayer_PythonToCpp_QGraphicsScene_SceneLayer,
            is_QGraphicsScene_SceneLayer_PythonToCpp_QGraphicsScene_SceneLayer_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_SCENELAYER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsScene::SceneLayer");
        Shiboken::Conversions::registerConverterName(converter, "SceneLayer");
    }
    // Register converter for flag 'QFlags<QGraphicsScene::SceneLayer>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX],
            QFlags_QGraphicsScene_SceneLayer__CppToPython_QFlags_QGraphicsScene_SceneLayer_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsScene_SceneLayer_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_,
            is_QGraphicsScene_SceneLayer_PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsScene_SceneLayer__PythonToCpp_QFlags_QGraphicsScene_SceneLayer_,
            is_QFlags_QGraphicsScene_SceneLayer__PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsScene_SceneLayer_,
            is_number_PythonToCpp_QFlags_QGraphicsScene_SceneLayer__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsScene::SceneLayer>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<SceneLayer>");
    }
    // End of 'SceneLayer' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QGraphicsScene_Type, &::QGraphicsScene::staticMetaObject);

    qRegisterMetaType< ::QGraphicsScene::ItemIndexMethod >("QGraphicsScene::ItemIndexMethod");
    qRegisterMetaType< ::QGraphicsScene::SceneLayer >("QGraphicsScene::SceneLayer");
    qRegisterMetaType< ::QGraphicsScene::SceneLayers >("QGraphicsScene::SceneLayers");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGraphicsScene_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGraphicsScene_Type, &::QGraphicsScene::staticMetaObject, sizeof(::QGraphicsScene));
}
