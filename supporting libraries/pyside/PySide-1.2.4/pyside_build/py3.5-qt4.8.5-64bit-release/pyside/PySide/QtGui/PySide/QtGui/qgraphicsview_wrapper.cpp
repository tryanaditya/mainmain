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
#include <set>
#include "pyside_qtgui_python.h"

#include "qgraphicsview_wrapper.h"

// Extra includes
#include <QList>
#include <QPainterPath>
#include <QVarLengthArray>
#include <qaction.h>
#include <qbitmap.h>
#include <qbrush.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qevent.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qgraphicseffect.h>
#include <qgraphicsitem.h>
#include <qgraphicsproxywidget.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qicon.h>
#include <qinputcontext.h>
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qmatrix.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>
#include <qregion.h>
#include <qscrollbar.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qtransform.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QGraphicsViewWrapper::QGraphicsViewWrapper(QGraphicsScene * scene, QWidget * parent) : QGraphicsView(scene, parent) {
    // ... middle
}

QGraphicsViewWrapper::QGraphicsViewWrapper(QWidget * parent) : QGraphicsView(parent) {
    // ... middle
}

void QGraphicsViewWrapper::actionEvent(QActionEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "actionEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::actionEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONEVENT_IDX], event)
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

void QGraphicsViewWrapper::changeEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFrame::changeEvent(arg__1);
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

void QGraphicsViewWrapper::childEvent(QChildEvent * arg__1)
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

void QGraphicsViewWrapper::closeEvent(QCloseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::closeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], event)
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

void QGraphicsViewWrapper::connectNotify(const char * signal)
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

void QGraphicsViewWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], event)
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

void QGraphicsViewWrapper::customEvent(QEvent * arg__1)
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

int QGraphicsViewWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::disconnectNotify(const char * signal)
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

void QGraphicsViewWrapper::dragEnterEvent(QDragEnterEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::dragEnterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], event)
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

void QGraphicsViewWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::dragLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], event)
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

void QGraphicsViewWrapper::dragMoveEvent(QDragMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::dragMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], event)
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

void QGraphicsViewWrapper::drawBackground(QPainter * painter, const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawBackground"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::drawBackground(painter, rect);
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

void QGraphicsViewWrapper::drawForeground(QPainter * painter, const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawForeground"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::drawForeground(painter, rect);
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

void QGraphicsViewWrapper::drawItems(QPainter * painter, int numItems, QGraphicsItem ** items, const QStyleOptionGraphicsItem * options)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawItems"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::drawItems(painter, numItems, items, options);
    }

    // Begin code injection

    Shiboken::AutoDecRef object(PyList_New(0));
    for (int i=0, max=numItems; i < max; i++) {
        PyList_Append(object, Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], items[i]));
    }
    PyObject *items_out = object.object();


    Shiboken::AutoDecRef option_object(PyList_New(0));
    for (int i=0, max=numItems; i < max; i++) {
        const QStyleOptionGraphicsItem* item = &options[i];
        PyList_Append(option_object, Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], &item));
    }
    PyObject* options_out = option_object.object();

    // End of code injection
    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        items_out,
        options_out
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsViewWrapper::dropEvent(QDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::dropEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], event)
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

void QGraphicsViewWrapper::enterEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "enterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::enterEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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

bool QGraphicsViewWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGraphicsViewWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QGraphicsViewWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::focusInEvent(event);
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

bool QGraphicsViewWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::focusNextPrevChild(next);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::focusOutEvent(event);
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

int QGraphicsViewWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::heightForWidth(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::hideEvent(QHideEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hideEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::hideEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QHIDEEVENT_IDX], event)
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

void QGraphicsViewWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::inputMethodEvent(event);
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

QVariant QGraphicsViewWrapper::inputMethodQuery(Qt::InputMethodQuery query) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::inputMethodQuery(query);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::keyPressEvent(event);
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

void QGraphicsViewWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::keyReleaseEvent(event);
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

void QGraphicsViewWrapper::languageChange()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "languageChange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::languageChange();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsViewWrapper::leaveEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "leaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::leaveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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

int QGraphicsViewWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::metric(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QGraphicsViewWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::minimumSizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::mouseDoubleClickEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
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

void QGraphicsViewWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::mouseMoveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
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

void QGraphicsViewWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::mousePressEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
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

void QGraphicsViewWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::mouseReleaseEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], event)
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

void QGraphicsViewWrapper::moveEvent(QMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "moveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::moveEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOVEEVENT_IDX], event)
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

QPaintEngine * QGraphicsViewWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEngine();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::paintEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], event)
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

void QGraphicsViewWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::resizeEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], event)
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

void QGraphicsViewWrapper::scrollContentsBy(int dx, int dy)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scrollContentsBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::scrollContentsBy(dx, dy);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
        dx,
        dy
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsViewWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::setVisible(visible);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsViewWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::showEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], event)
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

QSize QGraphicsViewWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::sizeHint();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsViewWrapper::tabletEvent(QTabletEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "tabletEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::tabletEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLETEVENT_IDX], event)
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

void QGraphicsViewWrapper::timerEvent(QTimerEvent * arg__1)
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

bool QGraphicsViewWrapper::viewportEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "viewportEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::viewportEvent(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsView.viewportEvent", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

void QGraphicsViewWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsView::wheelEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], event)
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

const QMetaObject* QGraphicsViewWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGraphicsView::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGraphicsViewWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGraphicsView::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGraphicsViewWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGraphicsViewWrapper* >(this));
        return QGraphicsView::qt_metacast(_clname);
}

QGraphicsViewWrapper::~QGraphicsViewWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsView_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsView >()))
        return -1;

    ::QGraphicsViewWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QGraphicsView", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsView(QGraphicsScene*,QWidget*)
    // 1: QGraphicsView(QWidget*)
    if (numArgs == 0) {
        overloadId = 1; // QGraphicsView(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QGraphicsView(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGraphicsView(QGraphicsScene*,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 0; // QGraphicsView(QGraphicsScene*,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsView_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGraphicsView(QGraphicsScene * scene, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QGraphicsView_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGraphicsScene* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QGraphicsView(QGraphicsScene*,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGraphicsViewWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGraphicsViewWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 1: // QGraphicsView(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QGraphicsView_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGraphicsView(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGraphicsViewWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGraphicsViewWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsView >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsView_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QGraphicsView_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsScene, PySide.QtGui.QWidget = None", "PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsViewFunc_alignment(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->alignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_backgroundBrush(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->backgroundBrush();
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

static PyObject* Sbk_QGraphicsViewFunc_cacheMode(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGraphicsView::CacheModeFlag> cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->cacheMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_centerOn(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "centerOn", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: centerOn(const QGraphicsItem*)
    // 1: centerOn(QPointF)
    // 2: centerOn(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 2; // centerOn(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // centerOn(QPointF)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        overloadId = 0; // centerOn(const QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_centerOn_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // centerOn(const QGraphicsItem * item)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // centerOn(const QGraphicsItem*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->centerOn(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // centerOn(const QPointF & pos)
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
                // centerOn(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->centerOn(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // centerOn(qreal x, qreal y)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // centerOn(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->centerOn(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_centerOn_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", "PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.centerOn", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QDragEnterEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QDragEnterEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragEnterEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QDragEnterEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragEnterEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QDragLeaveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QDragLeaveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragLeaveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QDragLeaveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragLeaveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_dragMode(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dragMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsView::DragMode cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->dragMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QDragMoveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QDragMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragMoveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QDragMoveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_drawBackground(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_drawBackground_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::drawBackground(cppArg0, *cppArg1) : cppSelf->drawBackground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_drawBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.drawBackground", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_drawForeground(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_drawForeground_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::drawForeground(cppArg0, *cppArg1) : cppSelf->drawForeground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_drawForeground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.drawForeground", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_drawItems(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawItems", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawItems(QPainter*,int,QGraphicsItem**,const QStyleOptionGraphicsItem*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && PySequence_Check(pyArgs[1])
        && PySequence_Check(pyArgs[2])) {
        overloadId = 0; // drawItems(QPainter*,int,QGraphicsItem**,const QStyleOptionGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_drawItems_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // drawItems(QPainter*,int,QGraphicsItem**,const QStyleOptionGraphicsItem*)
            // Begin code injection

            int numItems_out = PySequence_Size(pyArgs[1-1]);


            int numItems = PySequence_Size(pyArgs[1-1]);
            Shiboken::AutoArrayPointer<QGraphicsItem*> items_out(numItems);
            for (int i=0; i < numItems; i++) {
                Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], PySequence_Fast_GET_ITEM(pyArgs[1-1], i), &(items_out[i]));
            }


            int numOptions = PySequence_Size(pyArgs[2-1]);
            Shiboken::AutoArrayPointer<QStyleOptionGraphicsItem> options_out(numOptions);
            for (int i=0; i < numOptions; i++) {
                Shiboken::Conversions::pythonToCppCopy((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], PySequence_Fast_GET_ITEM(pyArgs[1-1], i), &(options_out[i]));
            }

            // End of code injection
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::drawItems(cppArg0, numItems_out, items_out, options_out) : cppSelf->drawItems(cppArg0, numItems_out, items_out, options_out);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_drawItems_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, int, PySide.QtGui.QGraphicsItem, PySide.QtGui.QStyleOptionGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.drawItems", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_ensureVisible(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:ensureVisible", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: ensureVisible(const QGraphicsItem*,int,int)
    // 1: ensureVisible(QRectF,int,int)
    // 2: ensureVisible(qreal,qreal,qreal,qreal,int,int)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 2; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 2; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                overloadId = 2; // ensureVisible(qreal,qreal,qreal,qreal,int,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // ensureVisible(QRectF,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // ensureVisible(QRectF,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // ensureVisible(QRectF,int,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // ensureVisible(const QGraphicsItem*,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // ensureVisible(const QGraphicsItem*,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // ensureVisible(const QGraphicsItem*,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // ensureVisible(const QGraphicsItem * item, int xmargin, int ymargin)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xmargin");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'xmargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ymargin");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'ymargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 50;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 50;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // ensureVisible(const QGraphicsItem*,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->ensureVisible(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // ensureVisible(const QRectF & rect, int xmargin, int ymargin)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xmargin");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'xmargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ymargin");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'ymargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
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
        case 2: // ensureVisible(qreal x, qreal y, qreal w, qreal h, int xmargin, int ymargin)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xmargin");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'xmargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ymargin");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.ensureVisible(): got multiple values for keyword argument 'ymargin'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QGraphicsViewFunc_ensureVisible_TypeError;
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

    Sbk_QGraphicsViewFunc_ensureVisible_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, int = 50, int = 50", "PySide.QtCore.QRectF, int = 50, int = 50", "float, float, float, float, int = 50, int = 50", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.ensureVisible", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.event", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_fitInView(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.fitInView(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.fitInView(): not enough arguments");
        return 0;
    } else if (numArgs == 3)
        goto Sbk_QGraphicsViewFunc_fitInView_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:fitInView", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: fitInView(const QGraphicsItem*,Qt::AspectRatioMode)
    // 1: fitInView(QRectF,Qt::AspectRatioMode)
    // 2: fitInView(qreal,qreal,qreal,qreal,Qt::AspectRatioMode)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 2; // fitInView(qreal,qreal,qreal,qreal,Qt::AspectRatioMode)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[4])))) {
            overloadId = 2; // fitInView(qreal,qreal,qreal,qreal,Qt::AspectRatioMode)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // fitInView(QRectF,Qt::AspectRatioMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // fitInView(QRectF,Qt::AspectRatioMode)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fitInView(const QGraphicsItem*,Qt::AspectRatioMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // fitInView(const QGraphicsItem*,Qt::AspectRatioMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_fitInView_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fitInView(const QGraphicsItem * item, Qt::AspectRatioMode aspectRadioMode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectRadioMode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.fitInView(): got multiple values for keyword argument 'aspectRadioMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_fitInView_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::AspectRatioMode cppArg1 = Qt::IgnoreAspectRatio;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fitInView(const QGraphicsItem*,Qt::AspectRatioMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fitInView(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // fitInView(const QRectF & rect, Qt::AspectRatioMode aspectRadioMode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectRadioMode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.fitInView(): got multiple values for keyword argument 'aspectRadioMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_fitInView_TypeError;
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

            ::Qt::AspectRatioMode cppArg1 = Qt::IgnoreAspectRatio;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fitInView(QRectF,Qt::AspectRatioMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fitInView(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // fitInView(qreal x, qreal y, qreal w, qreal h, Qt::AspectRatioMode aspectRadioMode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "aspectRadioMode");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.fitInView(): got multiple values for keyword argument 'aspectRadioMode'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[4]))))
                        goto Sbk_QGraphicsViewFunc_fitInView_TypeError;
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
            ::Qt::AspectRatioMode cppArg4 = Qt::IgnoreAspectRatio;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // fitInView(qreal,qreal,qreal,qreal,Qt::AspectRatioMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fitInView(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_fitInView_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio", "PySide.QtCore.QRectF, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio", "float, float, float, float, PySide.QtCore.Qt.AspectRatioMode = Qt.IgnoreAspectRatio", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.fitInView", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::focusNextPrevChild(cppArg0) : cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_foregroundBrush(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // foregroundBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->foregroundBrush();
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

static PyObject* Sbk_QGraphicsViewFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsView*>(cppSelf)->::QGraphicsView::inputMethodQuery(cppArg0) : const_cast<const ::QGraphicsView*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_invalidateScene(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.invalidateScene(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:invalidateScene", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: invalidateScene(QRectF,QFlags<QGraphicsScene::SceneLayer>)
    if (numArgs == 0) {
        overloadId = 0; // invalidateScene(QRectF,QFlags<QGraphicsScene::SceneLayer>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // invalidateScene(QRectF,QFlags<QGraphicsScene::SceneLayer>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[1])))) {
            overloadId = 0; // invalidateScene(QRectF,QFlags<QGraphicsScene::SceneLayer>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_invalidateScene_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "rect");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.invalidateScene(): got multiple values for keyword argument 'rect'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsViewFunc_invalidateScene_TypeError;
            }
            value = PyDict_GetItemString(kwds, "layers");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.invalidateScene(): got multiple values for keyword argument 'layers'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSSCENE_SCENELAYER__IDX]), (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_invalidateScene_TypeError;
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
            // invalidateScene(QRectF,QFlags<QGraphicsScene::SceneLayer>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->invalidateScene(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_invalidateScene_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF = QRectF(), PySide.QtGui.QGraphicsScene.SceneLayers = QGraphicsScene.AllLayers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.invalidateScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_isInteractive(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isInteractive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->isInteractive();
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

static PyObject* Sbk_QGraphicsViewFunc_isTransformed(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isTransformed()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->isTransformed();
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

static PyObject* Sbk_QGraphicsViewFunc_itemAt(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemAt", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: itemAt(QPoint)const
    // 1: itemAt(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // itemAt(int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // itemAt(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_itemAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // itemAt(const QPoint & pos) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // itemAt(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->itemAt(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);

                // Ownership transferences.
            }
            break;
        }
        case 1: // itemAt(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // itemAt(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsItem * cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->itemAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);

                // Ownership transferences.
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_itemAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_items(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.items(): too many arguments");
        return 0;
    } else if (numArgs == 3)
        goto Sbk_QGraphicsViewFunc_items_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:items", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: items()const
    // 1: items(QPainterPath,Qt::ItemSelectionMode)const
    // 2: items(QPoint)const
    // 3: items(QPolygon,Qt::ItemSelectionMode)const
    // 4: items(QRect,Qt::ItemSelectionMode)const
    // 5: items(int,int)const
    // 6: items(int,int,int,int,Qt::ItemSelectionMode)const
    if (numArgs == 0) {
        overloadId = 0; // items()const
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 5; // items(int,int)const
        } else if (numArgs >= 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 6; // items(int,int,int,int,Qt::ItemSelectionMode)const
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[4])))) {
                overloadId = 6; // items(int,int,int,int,Qt::ItemSelectionMode)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // items(QRect,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 4; // items(QRect,Qt::ItemSelectionMode)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // items(QPolygon,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 3; // items(QPolygon,Qt::ItemSelectionMode)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 2; // items(QPoint)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // items(QPainterPath,Qt::ItemSelectionMode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // items(QPainterPath,Qt::ItemSelectionMode)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_items_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // items() const
        {

            if (!PyErr_Occurred()) {
                // items()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 1: // items(const QPainterPath & path, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_items_TypeError;
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
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 2: // items(const QPoint & pos) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // items(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 3: // items(const QPolygon & polygon, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // items(QPolygon,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 4: // items(const QRect & rect, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QGraphicsViewFunc_items_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ItemSelectionMode cppArg1 = Qt::IntersectsItemShape;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // items(QRect,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 5: // items(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // items(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSITEMPTR_IDX], &cppResult);
            }
            break;
        }
        case 6: // items(int x, int y, int w, int h, Qt::ItemSelectionMode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.items(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArgs[4]))))
                        goto Sbk_QGraphicsViewFunc_items_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::ItemSelectionMode cppArg4 = Qt::IntersectsItemShape;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // items(int,int,int,int,Qt::ItemSelectionMode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QList<QGraphicsItem * > cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->items(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
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

    Sbk_QGraphicsViewFunc_items_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "PySide.QtCore.QPoint", "PySide.QtGui.QPolygon, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "PySide.QtCore.QRect, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", "int, int", "int, int, int, int, PySide.QtCore.Qt.ItemSelectionMode = Qt.IntersectsItemShape", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.items", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_keyReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyReleaseEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_mapFromScene(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsViewFunc_mapFromScene_TypeError;

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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mapFromScene_TypeError;

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
                QPainterPath cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(*cppArg0);
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
                QPoint cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
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
                QPolygon cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], &cppResult);
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
                QPolygon cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], &cppResult);
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
                QPoint cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
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
                QPolygon cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapFromScene(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_mapFromScene_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPointF", "PySide.QtGui.QPolygonF", "PySide.QtCore.QRectF", "float, float", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.mapFromScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_mapToScene(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QGraphicsViewFunc_mapToScene_TypeError;

    if (!PyArg_UnpackTuple(args, "mapToScene", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: mapToScene(QPainterPath)const
    // 1: mapToScene(QPoint)const
    // 2: mapToScene(QPolygon)const
    // 3: mapToScene(QRect)const
    // 4: mapToScene(int,int)const
    // 5: mapToScene(int,int,int,int)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // mapToScene(int,int)const
        } else if (numArgs == 4
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 5; // mapToScene(int,int,int,int)const
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 3; // mapToScene(QRect)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArgs[0])))) {
        overloadId = 2; // mapToScene(QPolygon)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 1; // mapToScene(QPoint)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        overloadId = 0; // mapToScene(QPainterPath)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mapToScene_TypeError;

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
                QPainterPath cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
            }
            break;
        }
        case 1: // mapToScene(const QPoint & point) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QPoint)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // mapToScene(const QPolygon & polygon) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QPolygon)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 3: // mapToScene(const QRect & rect) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // mapToScene(QRect)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], &cppResult);
            }
            break;
        }
        case 4: // mapToScene(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // mapToScene(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPointF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &cppResult);
            }
            break;
        }
        case 5: // mapToScene(int x, int y, int w, int h) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // mapToScene(int,int,int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPolygonF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->mapToScene(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_QGraphicsViewFunc_mapToScene_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", "PySide.QtCore.QPoint", "PySide.QtGui.QPolygon", "PySide.QtCore.QRect", "int, int", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.mapToScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_matrix(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // matrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->matrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_optimizationFlags(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // optimizationFlags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QGraphicsView::OptimizationFlag> cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->optimizationFlags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_paintEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_render(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.render(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.render(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:render", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[3])))) {
                    overloadId = 0; // render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_render_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "target");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.render(): got multiple values for keyword argument 'target'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_render_TypeError;
            }
            value = PyDict_GetItemString(kwds, "source");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.render(): got multiple values for keyword argument 'source'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2]))))
                    goto Sbk_QGraphicsViewFunc_render_TypeError;
            }
            value = PyDict_GetItemString(kwds, "aspectRatioMode");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.render(): got multiple values for keyword argument 'aspectRatioMode'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ASPECTRATIOMODE_IDX]), (pyArgs[3]))))
                    goto Sbk_QGraphicsViewFunc_render_TypeError;
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
        ::QRect cppArg2_local = QRect();
        ::QRect* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }
        ::Qt::AspectRatioMode cppArg3 = Qt::KeepAspectRatio;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // render(QPainter*,QRectF,QRect,Qt::AspectRatioMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->render(cppArg0, *cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_render_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRectF = QRectF(), PySide.QtCore.QRect = QRect(), PySide.QtCore.Qt.AspectRatioMode = Qt.KeepAspectRatio", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.render", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_renderHints(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // renderHints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QPainter::RenderHint> cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->renderHints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_resetCachedContent(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetCachedContent()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetCachedContent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsViewFunc_resetMatrix(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetMatrix()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsViewFunc_resetTransform(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QGraphicsViewFunc_resizeAnchor(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resizeAnchor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsView::ViewportAnchor cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->resizeAnchor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_resizeEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QResizeEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_rotate(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rotate(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // rotate(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_rotate_TypeError;

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

    Sbk_QGraphicsViewFunc_rotate_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.rotate", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_rubberBandSelectionMode(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rubberBandSelectionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ItemSelectionMode cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->rubberBandSelectionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_scale(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scale", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scale(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // scale(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_scale_TypeError;

    // Call function/method
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
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_scale_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.scale", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_scene(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scene()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsScene * cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->scene();
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

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_sceneRect(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sceneRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->sceneRect();
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

static PyObject* Sbk_QGraphicsViewFunc_scrollContentsBy(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scrollContentsBy", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scrollContentsBy(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // scrollContentsBy(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_scrollContentsBy_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scrollContentsBy(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::scrollContentsBy(cppArg0, cppArg1) : cppSelf->scrollContentsBy(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_scrollContentsBy_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.scrollContentsBy", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setBackgroundBrush(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackgroundBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackgroundBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setBackgroundBrush_TypeError;

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

    Sbk_QGraphicsViewFunc_setBackgroundBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setBackgroundBrush", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setCacheMode(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCacheMode(QFlags<QGraphicsView::CacheModeFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setCacheMode(QFlags<QGraphicsView::CacheModeFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setCacheMode_TypeError;

    // Call function/method
    {
        ::QFlags<QGraphicsView::CacheModeFlag> cppArg0 = ((::QFlags<QGraphicsView::CacheModeFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCacheMode(QFlags<QGraphicsView::CacheModeFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCacheMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setCacheMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.CacheMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setCacheMode", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setDragMode(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragMode(QGraphicsView::DragMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setDragMode(QGraphicsView::DragMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setDragMode_TypeError;

    // Call function/method
    {
        ::QGraphicsView::DragMode cppArg0 = ((::QGraphicsView::DragMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDragMode(QGraphicsView::DragMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDragMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setDragMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.DragMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setDragMode", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setForegroundBrush(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForegroundBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setForegroundBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setForegroundBrush_TypeError;

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

    Sbk_QGraphicsViewFunc_setForegroundBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setForegroundBrush", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setInteractive(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInteractive(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setInteractive(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setInteractive_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInteractive(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInteractive(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setInteractive_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setInteractive", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setMatrix(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setMatrix(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setMatrix(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setMatrix", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMatrix(QMatrix,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMatrix(QMatrix,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setMatrix(QMatrix,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setMatrix_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setMatrix(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_setMatrix_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QMatrix cppArg0_local = ::QMatrix();
        ::QMatrix* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMatrix(QMatrix,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMatrix(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setMatrix_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.setMatrix", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setOptimizationFlag(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setOptimizationFlag(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setOptimizationFlag(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setOptimizationFlag", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setOptimizationFlag(QGraphicsView::OptimizationFlag,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setOptimizationFlag(QGraphicsView::OptimizationFlag,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setOptimizationFlag(QGraphicsView::OptimizationFlag,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setOptimizationFlag_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "enabled");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setOptimizationFlag(): got multiple values for keyword argument 'enabled'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_setOptimizationFlag_TypeError;
            }
        }
        ::QGraphicsView::OptimizationFlag cppArg0 = ((::QGraphicsView::OptimizationFlag)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setOptimizationFlag(QGraphicsView::OptimizationFlag,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOptimizationFlag(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setOptimizationFlag_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.OptimizationFlag, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.setOptimizationFlag", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setOptimizationFlags(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOptimizationFlags(QFlags<QGraphicsView::OptimizationFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setOptimizationFlags(QFlags<QGraphicsView::OptimizationFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setOptimizationFlags_TypeError;

    // Call function/method
    {
        ::QFlags<QGraphicsView::OptimizationFlag> cppArg0 = ((::QFlags<QGraphicsView::OptimizationFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOptimizationFlags(QFlags<QGraphicsView::OptimizationFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOptimizationFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setOptimizationFlags_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.OptimizationFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setOptimizationFlags", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setRenderHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setRenderHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setRenderHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setRenderHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRenderHint(QPainter::RenderHint,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setRenderHint(QPainter::RenderHint,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setRenderHint(QPainter::RenderHint,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setRenderHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "enabled");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setRenderHint(): got multiple values for keyword argument 'enabled'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_setRenderHint_TypeError;
            }
        }
        ::QPainter::RenderHint cppArg0 = ((::QPainter::RenderHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRenderHint(QPainter::RenderHint,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRenderHint(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setRenderHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.RenderHint, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.setRenderHint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setRenderHints(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRenderHints(QFlags<QPainter::RenderHint>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), (pyArg)))) {
        overloadId = 0; // setRenderHints(QFlags<QPainter::RenderHint>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setRenderHints_TypeError;

    // Call function/method
    {
        ::QFlags<QPainter::RenderHint> cppArg0 = ((::QFlags<QPainter::RenderHint>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRenderHints(QFlags<QPainter::RenderHint>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRenderHints(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setRenderHints_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.RenderHints", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setRenderHints", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setResizeAnchor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setResizeAnchor(QGraphicsView::ViewportAnchor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX]), (pyArg)))) {
        overloadId = 0; // setResizeAnchor(QGraphicsView::ViewportAnchor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setResizeAnchor_TypeError;

    // Call function/method
    {
        ::QGraphicsView::ViewportAnchor cppArg0 = ((::QGraphicsView::ViewportAnchor)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setResizeAnchor(QGraphicsView::ViewportAnchor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setResizeAnchor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setResizeAnchor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.ViewportAnchor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setResizeAnchor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setRubberBandSelectionMode(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRubberBandSelectionMode(Qt::ItemSelectionMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ITEMSELECTIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setRubberBandSelectionMode(Qt::ItemSelectionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setRubberBandSelectionMode_TypeError;

    // Call function/method
    {
        ::Qt::ItemSelectionMode cppArg0 = ((::Qt::ItemSelectionMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRubberBandSelectionMode(Qt::ItemSelectionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRubberBandSelectionMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setRubberBandSelectionMode_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ItemSelectionMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setRubberBandSelectionMode", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setScene(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScene(QGraphicsScene*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSSCENE_IDX], (pyArg)))) {
        overloadId = 0; // setScene(QGraphicsScene*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setScene_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsScene* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScene(QGraphicsScene*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScene(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setScene(QGraphicsScene*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setScene_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsScene", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setSceneRect(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QGraphicsViewFunc_setSceneRect_TypeError;

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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setSceneRect_TypeError;

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

    Sbk_QGraphicsViewFunc_setSceneRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", "float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.setSceneRect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setTransform(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setTransform(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setTransform(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setTransform_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsView.setTransform(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsViewFunc_setTransform_TypeError;
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

    Sbk_QGraphicsViewFunc_setTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.setTransform", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setTransformationAnchor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransformationAnchor(QGraphicsView::ViewportAnchor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX]), (pyArg)))) {
        overloadId = 0; // setTransformationAnchor(QGraphicsView::ViewportAnchor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setTransformationAnchor_TypeError;

    // Call function/method
    {
        ::QGraphicsView::ViewportAnchor cppArg0 = ((::QGraphicsView::ViewportAnchor)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTransformationAnchor(QGraphicsView::ViewportAnchor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransformationAnchor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setTransformationAnchor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.ViewportAnchor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setTransformationAnchor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setViewportUpdateMode(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setViewportUpdateMode(QGraphicsView::ViewportUpdateMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setViewportUpdateMode(QGraphicsView::ViewportUpdateMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setViewportUpdateMode_TypeError;

    // Call function/method
    {
        ::QGraphicsView::ViewportUpdateMode cppArg0 = ((::QGraphicsView::ViewportUpdateMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewportUpdateMode(QGraphicsView::ViewportUpdateMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setViewportUpdateMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setViewportUpdateMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsView.ViewportUpdateMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setViewportUpdateMode", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_setupViewport(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setupViewport(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setupViewport(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_setupViewport_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setupViewport(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setupViewport(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_setupViewport_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.setupViewport", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_shear(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_shear_TypeError;

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

    Sbk_QGraphicsViewFunc_shear_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.shear", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_showEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: showEvent(QShowEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], (pyArg)))) {
        overloadId = 0; // showEvent(QShowEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_showEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QShowEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // showEvent(QShowEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::showEvent(cppArg0) : cppSelf->showEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_showEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QShowEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.showEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_sizeHint(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsView*>(cppSelf)->::QGraphicsView::sizeHint() : const_cast<const ::QGraphicsView*>(cppSelf)->sizeHint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_transform(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->transform();
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

static PyObject* Sbk_QGraphicsViewFunc_transformationAnchor(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transformationAnchor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsView::ViewportAnchor cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->transformationAnchor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_translate(PyObject* self, PyObject* args)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_translate_TypeError;

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

    Sbk_QGraphicsViewFunc_translate_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsView.translate", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_updateScene(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateScene(QList<QRectF>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // updateScene(QList<QRectF>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_updateScene_TypeError;

    // Call function/method
    {
        ::QList<QRectF > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // updateScene(QList<QRectF>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateScene(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_updateScene_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.updateScene", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_updateSceneRect(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateSceneRect(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // updateSceneRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_updateSceneRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // updateSceneRect(QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateSceneRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_updateSceneRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.updateSceneRect", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_viewportEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: viewportEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // viewportEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_viewportEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // viewportEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::viewportEvent(cppArg0) : cppSelf->viewportEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsViewFunc_viewportEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.viewportEvent", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsViewFunc_viewportTransform(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewportTransform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->viewportTransform();
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

static PyObject* Sbk_QGraphicsViewFunc_viewportUpdateMode(PyObject* self)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewportUpdateMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsView::ViewportUpdateMode cppResult = const_cast<const ::QGraphicsView*>(cppSelf)->viewportUpdateMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsViewFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsViewFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsView::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsViewFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsView.wheelEvent", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsView_methods[] = {
    {"alignment", (PyCFunction)Sbk_QGraphicsViewFunc_alignment, METH_NOARGS},
    {"backgroundBrush", (PyCFunction)Sbk_QGraphicsViewFunc_backgroundBrush, METH_NOARGS},
    {"cacheMode", (PyCFunction)Sbk_QGraphicsViewFunc_cacheMode, METH_NOARGS},
    {"centerOn", (PyCFunction)Sbk_QGraphicsViewFunc_centerOn, METH_VARARGS},
    {"contextMenuEvent", (PyCFunction)Sbk_QGraphicsViewFunc_contextMenuEvent, METH_O},
    {"dragEnterEvent", (PyCFunction)Sbk_QGraphicsViewFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QGraphicsViewFunc_dragLeaveEvent, METH_O},
    {"dragMode", (PyCFunction)Sbk_QGraphicsViewFunc_dragMode, METH_NOARGS},
    {"dragMoveEvent", (PyCFunction)Sbk_QGraphicsViewFunc_dragMoveEvent, METH_O},
    {"drawBackground", (PyCFunction)Sbk_QGraphicsViewFunc_drawBackground, METH_VARARGS},
    {"drawForeground", (PyCFunction)Sbk_QGraphicsViewFunc_drawForeground, METH_VARARGS},
    {"drawItems", (PyCFunction)Sbk_QGraphicsViewFunc_drawItems, METH_VARARGS},
    {"dropEvent", (PyCFunction)Sbk_QGraphicsViewFunc_dropEvent, METH_O},
    {"ensureVisible", (PyCFunction)Sbk_QGraphicsViewFunc_ensureVisible, METH_VARARGS|METH_KEYWORDS},
    {"event", (PyCFunction)Sbk_QGraphicsViewFunc_event, METH_O},
    {"fitInView", (PyCFunction)Sbk_QGraphicsViewFunc_fitInView, METH_VARARGS|METH_KEYWORDS},
    {"focusInEvent", (PyCFunction)Sbk_QGraphicsViewFunc_focusInEvent, METH_O},
    {"focusNextPrevChild", (PyCFunction)Sbk_QGraphicsViewFunc_focusNextPrevChild, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QGraphicsViewFunc_focusOutEvent, METH_O},
    {"foregroundBrush", (PyCFunction)Sbk_QGraphicsViewFunc_foregroundBrush, METH_NOARGS},
    {"inputMethodEvent", (PyCFunction)Sbk_QGraphicsViewFunc_inputMethodEvent, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QGraphicsViewFunc_inputMethodQuery, METH_O},
    {"invalidateScene", (PyCFunction)Sbk_QGraphicsViewFunc_invalidateScene, METH_VARARGS|METH_KEYWORDS},
    {"isInteractive", (PyCFunction)Sbk_QGraphicsViewFunc_isInteractive, METH_NOARGS},
    {"isTransformed", (PyCFunction)Sbk_QGraphicsViewFunc_isTransformed, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGraphicsViewFunc_itemAt, METH_VARARGS},
    {"items", (PyCFunction)Sbk_QGraphicsViewFunc_items, METH_VARARGS|METH_KEYWORDS},
    {"keyPressEvent", (PyCFunction)Sbk_QGraphicsViewFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QGraphicsViewFunc_keyReleaseEvent, METH_O},
    {"mapFromScene", (PyCFunction)Sbk_QGraphicsViewFunc_mapFromScene, METH_VARARGS},
    {"mapToScene", (PyCFunction)Sbk_QGraphicsViewFunc_mapToScene, METH_VARARGS},
    {"matrix", (PyCFunction)Sbk_QGraphicsViewFunc_matrix, METH_NOARGS},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QGraphicsViewFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QGraphicsViewFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QGraphicsViewFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QGraphicsViewFunc_mouseReleaseEvent, METH_O},
    {"optimizationFlags", (PyCFunction)Sbk_QGraphicsViewFunc_optimizationFlags, METH_NOARGS},
    {"paintEvent", (PyCFunction)Sbk_QGraphicsViewFunc_paintEvent, METH_O},
    {"render", (PyCFunction)Sbk_QGraphicsViewFunc_render, METH_VARARGS|METH_KEYWORDS},
    {"renderHints", (PyCFunction)Sbk_QGraphicsViewFunc_renderHints, METH_NOARGS},
    {"resetCachedContent", (PyCFunction)Sbk_QGraphicsViewFunc_resetCachedContent, METH_NOARGS},
    {"resetMatrix", (PyCFunction)Sbk_QGraphicsViewFunc_resetMatrix, METH_NOARGS},
    {"resetTransform", (PyCFunction)Sbk_QGraphicsViewFunc_resetTransform, METH_NOARGS},
    {"resizeAnchor", (PyCFunction)Sbk_QGraphicsViewFunc_resizeAnchor, METH_NOARGS},
    {"resizeEvent", (PyCFunction)Sbk_QGraphicsViewFunc_resizeEvent, METH_O},
    {"rotate", (PyCFunction)Sbk_QGraphicsViewFunc_rotate, METH_O},
    {"rubberBandSelectionMode", (PyCFunction)Sbk_QGraphicsViewFunc_rubberBandSelectionMode, METH_NOARGS},
    {"scale", (PyCFunction)Sbk_QGraphicsViewFunc_scale, METH_VARARGS},
    {"scene", (PyCFunction)Sbk_QGraphicsViewFunc_scene, METH_NOARGS},
    {"sceneRect", (PyCFunction)Sbk_QGraphicsViewFunc_sceneRect, METH_NOARGS},
    {"scrollContentsBy", (PyCFunction)Sbk_QGraphicsViewFunc_scrollContentsBy, METH_VARARGS},
    {"setAlignment", (PyCFunction)Sbk_QGraphicsViewFunc_setAlignment, METH_O},
    {"setBackgroundBrush", (PyCFunction)Sbk_QGraphicsViewFunc_setBackgroundBrush, METH_O},
    {"setCacheMode", (PyCFunction)Sbk_QGraphicsViewFunc_setCacheMode, METH_O},
    {"setDragMode", (PyCFunction)Sbk_QGraphicsViewFunc_setDragMode, METH_O},
    {"setForegroundBrush", (PyCFunction)Sbk_QGraphicsViewFunc_setForegroundBrush, METH_O},
    {"setInteractive", (PyCFunction)Sbk_QGraphicsViewFunc_setInteractive, METH_O},
    {"setMatrix", (PyCFunction)Sbk_QGraphicsViewFunc_setMatrix, METH_VARARGS|METH_KEYWORDS},
    {"setOptimizationFlag", (PyCFunction)Sbk_QGraphicsViewFunc_setOptimizationFlag, METH_VARARGS|METH_KEYWORDS},
    {"setOptimizationFlags", (PyCFunction)Sbk_QGraphicsViewFunc_setOptimizationFlags, METH_O},
    {"setRenderHint", (PyCFunction)Sbk_QGraphicsViewFunc_setRenderHint, METH_VARARGS|METH_KEYWORDS},
    {"setRenderHints", (PyCFunction)Sbk_QGraphicsViewFunc_setRenderHints, METH_O},
    {"setResizeAnchor", (PyCFunction)Sbk_QGraphicsViewFunc_setResizeAnchor, METH_O},
    {"setRubberBandSelectionMode", (PyCFunction)Sbk_QGraphicsViewFunc_setRubberBandSelectionMode, METH_O},
    {"setScene", (PyCFunction)Sbk_QGraphicsViewFunc_setScene, METH_O},
    {"setSceneRect", (PyCFunction)Sbk_QGraphicsViewFunc_setSceneRect, METH_VARARGS},
    {"setTransform", (PyCFunction)Sbk_QGraphicsViewFunc_setTransform, METH_VARARGS|METH_KEYWORDS},
    {"setTransformationAnchor", (PyCFunction)Sbk_QGraphicsViewFunc_setTransformationAnchor, METH_O},
    {"setViewportUpdateMode", (PyCFunction)Sbk_QGraphicsViewFunc_setViewportUpdateMode, METH_O},
    {"setupViewport", (PyCFunction)Sbk_QGraphicsViewFunc_setupViewport, METH_O},
    {"shear", (PyCFunction)Sbk_QGraphicsViewFunc_shear, METH_VARARGS},
    {"showEvent", (PyCFunction)Sbk_QGraphicsViewFunc_showEvent, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QGraphicsViewFunc_sizeHint, METH_NOARGS},
    {"transform", (PyCFunction)Sbk_QGraphicsViewFunc_transform, METH_NOARGS},
    {"transformationAnchor", (PyCFunction)Sbk_QGraphicsViewFunc_transformationAnchor, METH_NOARGS},
    {"translate", (PyCFunction)Sbk_QGraphicsViewFunc_translate, METH_VARARGS},
    {"updateScene", (PyCFunction)Sbk_QGraphicsViewFunc_updateScene, METH_O},
    {"updateSceneRect", (PyCFunction)Sbk_QGraphicsViewFunc_updateSceneRect, METH_O},
    {"viewportEvent", (PyCFunction)Sbk_QGraphicsViewFunc_viewportEvent, METH_O},
    {"viewportTransform", (PyCFunction)Sbk_QGraphicsViewFunc_viewportTransform, METH_NOARGS},
    {"viewportUpdateMode", (PyCFunction)Sbk_QGraphicsViewFunc_viewportUpdateMode, METH_NOARGS},
    {"wheelEvent", (PyCFunction)Sbk_QGraphicsViewFunc_wheelEvent, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsView_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsView_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QGraphicsViewSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QGraphicsView* me = reinterpret_cast< ::QGraphicsView*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QABSTRACTSCROLLAREA_IDX]))
        return static_cast< ::QAbstractScrollArea*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QFRAME_IDX]))
        return static_cast< ::QFrame*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsView_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsView",
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
    /*tp_traverse*/         Sbk_QGraphicsView_traverse,
    /*tp_clear*/            Sbk_QGraphicsView_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsView_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsView_Init,
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

static void* Sbk_QGraphicsView_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGraphicsView*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QGraphicsView*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QGraphicsView_CacheModeFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::CacheMode cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::CacheMode)PyLong_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::CacheMode)PyInt_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_CacheModeFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::CacheMode cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::CacheMode)PyLong_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::CacheMode)PyInt_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_CacheModeFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::CacheMode cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::CacheMode)PyLong_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::CacheMode)PyInt_AsLong(self);
    cppArg = (QGraphicsView::CacheMode)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_CacheModeFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::CacheMode cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), self, &cppSelf);
    ::QGraphicsView::CacheMode cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsView_CacheModeFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsView_CacheModeFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsView_CacheModeFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsView_CacheModeFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsView_CacheModeFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsView_CacheModeFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsView_CacheModeFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsView_CacheModeFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsView_CacheModeFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsView_CacheModeFlag_long,
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


PyObject* SbkPySide_QtGui_QGraphicsView_OptimizationFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::OptimizationFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::OptimizationFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::OptimizationFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_OptimizationFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::OptimizationFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::OptimizationFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::OptimizationFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_OptimizationFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::OptimizationFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QGraphicsView::OptimizationFlags)PyLong_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QGraphicsView::OptimizationFlags)PyInt_AsLong(self);
    cppArg = (QGraphicsView::OptimizationFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QGraphicsView_OptimizationFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsView::OptimizationFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), self, &cppSelf);
    ::QGraphicsView::OptimizationFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QGraphicsView_OptimizationFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QGraphicsView_OptimizationFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QGraphicsView_OptimizationFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QGraphicsView_OptimizationFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QGraphicsView_OptimizationFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsView_OptimizationFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QGraphicsView_OptimizationFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QGraphicsView_OptimizationFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QGraphicsView_OptimizationFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QGraphicsView_OptimizationFlag_long,
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
static void QGraphicsView_ViewportAnchor_PythonToCpp_QGraphicsView_ViewportAnchor(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsView::ViewportAnchor*)cppOut) = (::QGraphicsView::ViewportAnchor) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsView_ViewportAnchor_PythonToCpp_QGraphicsView_ViewportAnchor_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX]))
        return QGraphicsView_ViewportAnchor_PythonToCpp_QGraphicsView_ViewportAnchor;
    return 0;
}
static PyObject* QGraphicsView_ViewportAnchor_CppToPython_QGraphicsView_ViewportAnchor(const void* cppIn) {
    int castCppIn = *((::QGraphicsView::ViewportAnchor*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX], castCppIn);

}

static void QGraphicsView_CacheModeFlag_PythonToCpp_QGraphicsView_CacheModeFlag(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsView::CacheModeFlag*)cppOut) = (::QGraphicsView::CacheModeFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsView_CacheModeFlag_PythonToCpp_QGraphicsView_CacheModeFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX]))
        return QGraphicsView_CacheModeFlag_PythonToCpp_QGraphicsView_CacheModeFlag;
    return 0;
}
static PyObject* QGraphicsView_CacheModeFlag_CppToPython_QGraphicsView_CacheModeFlag(const void* cppIn) {
    int castCppIn = *((::QGraphicsView::CacheModeFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX], castCppIn);

}

static void QFlags_QGraphicsView_CacheModeFlag__PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsView::CacheModeFlag>*)cppOut) = ::QFlags<QGraphicsView::CacheModeFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsView_CacheModeFlag__PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]))
        return QFlags_QGraphicsView_CacheModeFlag__PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_;
    return 0;
}
static PyObject* QFlags_QGraphicsView_CacheModeFlag__CppToPython_QFlags_QGraphicsView_CacheModeFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsView::CacheModeFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]));

}

static void QGraphicsView_CacheModeFlag_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsView::CacheModeFlag>*)cppOut) = ::QFlags<QGraphicsView::CacheModeFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsView_CacheModeFlag_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX]))
        return QGraphicsView_CacheModeFlag_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsView::CacheModeFlag>*)cppOut) = ::QFlags<QGraphicsView::CacheModeFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_;
    return 0;
}
static void QGraphicsView_DragMode_PythonToCpp_QGraphicsView_DragMode(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsView::DragMode*)cppOut) = (::QGraphicsView::DragMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsView_DragMode_PythonToCpp_QGraphicsView_DragMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX]))
        return QGraphicsView_DragMode_PythonToCpp_QGraphicsView_DragMode;
    return 0;
}
static PyObject* QGraphicsView_DragMode_CppToPython_QGraphicsView_DragMode(const void* cppIn) {
    int castCppIn = *((::QGraphicsView::DragMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX], castCppIn);

}

static void QGraphicsView_ViewportUpdateMode_PythonToCpp_QGraphicsView_ViewportUpdateMode(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsView::ViewportUpdateMode*)cppOut) = (::QGraphicsView::ViewportUpdateMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsView_ViewportUpdateMode_PythonToCpp_QGraphicsView_ViewportUpdateMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX]))
        return QGraphicsView_ViewportUpdateMode_PythonToCpp_QGraphicsView_ViewportUpdateMode;
    return 0;
}
static PyObject* QGraphicsView_ViewportUpdateMode_CppToPython_QGraphicsView_ViewportUpdateMode(const void* cppIn) {
    int castCppIn = *((::QGraphicsView::ViewportUpdateMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX], castCppIn);

}

static void QGraphicsView_OptimizationFlag_PythonToCpp_QGraphicsView_OptimizationFlag(PyObject* pyIn, void* cppOut) {
    *((::QGraphicsView::OptimizationFlag*)cppOut) = (::QGraphicsView::OptimizationFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QGraphicsView_OptimizationFlag_PythonToCpp_QGraphicsView_OptimizationFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX]))
        return QGraphicsView_OptimizationFlag_PythonToCpp_QGraphicsView_OptimizationFlag;
    return 0;
}
static PyObject* QGraphicsView_OptimizationFlag_CppToPython_QGraphicsView_OptimizationFlag(const void* cppIn) {
    int castCppIn = *((::QGraphicsView::OptimizationFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX], castCppIn);

}

static void QFlags_QGraphicsView_OptimizationFlag__PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsView::OptimizationFlag>*)cppOut) = ::QFlags<QGraphicsView::OptimizationFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QGraphicsView_OptimizationFlag__PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]))
        return QFlags_QGraphicsView_OptimizationFlag__PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_;
    return 0;
}
static PyObject* QFlags_QGraphicsView_OptimizationFlag__CppToPython_QFlags_QGraphicsView_OptimizationFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QGraphicsView::OptimizationFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]));

}

static void QGraphicsView_OptimizationFlag_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QGraphicsView::OptimizationFlag>*)cppOut) = ::QFlags<QGraphicsView::OptimizationFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QGraphicsView_OptimizationFlag_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX]))
        return QGraphicsView_OptimizationFlag_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QGraphicsView::OptimizationFlag>*)cppOut) = ::QFlags<QGraphicsView::OptimizationFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsView_PythonToCpp_QGraphicsView_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsView_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsView_PythonToCpp_QGraphicsView_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsView_Type))
        return QGraphicsView_PythonToCpp_QGraphicsView_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsView_PTR_CppToPython_QGraphicsView(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGraphicsView*)cppIn, &Sbk_QGraphicsView_Type);

}

void init_QGraphicsView(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsView_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsView", "QGraphicsView*",
        &Sbk_QGraphicsView_Type, &Shiboken::callCppDestructor< ::QGraphicsView >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTSCROLLAREA_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsView_Type,
        QGraphicsView_PythonToCpp_QGraphicsView_PTR,
        is_QGraphicsView_PythonToCpp_QGraphicsView_PTR_Convertible,
        QGraphicsView_PTR_CppToPython_QGraphicsView);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsView");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsView*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsView&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsView).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsViewWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QGraphicsView_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QGraphicsView_Type, &Sbk_QGraphicsViewSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsView_Type, &Sbk_QGraphicsView_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ViewportAnchor'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsView_Type,
        "ViewportAnchor",
        "PySide.QtGui.QGraphicsView.ViewportAnchor",
        "QGraphicsView::ViewportAnchor");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX],
        &Sbk_QGraphicsView_Type, "NoAnchor", (long) QGraphicsView::NoAnchor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX],
        &Sbk_QGraphicsView_Type, "AnchorViewCenter", (long) QGraphicsView::AnchorViewCenter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX],
        &Sbk_QGraphicsView_Type, "AnchorUnderMouse", (long) QGraphicsView::AnchorUnderMouse))
        return ;
    // Register converter for enum 'QGraphicsView::ViewportAnchor'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX],
            QGraphicsView_ViewportAnchor_CppToPython_QGraphicsView_ViewportAnchor);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_ViewportAnchor_PythonToCpp_QGraphicsView_ViewportAnchor,
            is_QGraphicsView_ViewportAnchor_PythonToCpp_QGraphicsView_ViewportAnchor_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTANCHOR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsView::ViewportAnchor");
        Shiboken::Conversions::registerConverterName(converter, "ViewportAnchor");
    }
    // End of 'ViewportAnchor' enum.

    // Initialization of enum 'CacheModeFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX] = PySide::QFlags::create("CacheMode", &SbkPySide_QtGui_QGraphicsView_CacheModeFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsView_Type,
        "CacheModeFlag",
        "PySide.QtGui.QGraphicsView.CacheModeFlag",
        "QGraphicsView::CacheModeFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX],
        &Sbk_QGraphicsView_Type, "CacheNone", (long) QGraphicsView::CacheNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX],
        &Sbk_QGraphicsView_Type, "CacheBackground", (long) QGraphicsView::CacheBackground))
        return ;
    // Register converter for enum 'QGraphicsView::CacheModeFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX],
            QGraphicsView_CacheModeFlag_CppToPython_QGraphicsView_CacheModeFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_CacheModeFlag_PythonToCpp_QGraphicsView_CacheModeFlag,
            is_QGraphicsView_CacheModeFlag_PythonToCpp_QGraphicsView_CacheModeFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_CACHEMODEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsView::CacheModeFlag");
        Shiboken::Conversions::registerConverterName(converter, "CacheModeFlag");
    }
    // Register converter for flag 'QFlags<QGraphicsView::CacheModeFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX],
            QFlags_QGraphicsView_CacheModeFlag__CppToPython_QFlags_QGraphicsView_CacheModeFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_CacheModeFlag_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_,
            is_QGraphicsView_CacheModeFlag_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsView_CacheModeFlag__PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_,
            is_QFlags_QGraphicsView_CacheModeFlag__PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag_,
            is_number_PythonToCpp_QFlags_QGraphicsView_CacheModeFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_CACHEMODEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsView::CacheModeFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<CacheModeFlag>");
    }
    // End of 'CacheModeFlag' enum/flags.

    // Initialization of enum 'DragMode'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsView_Type,
        "DragMode",
        "PySide.QtGui.QGraphicsView.DragMode",
        "QGraphicsView::DragMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX],
        &Sbk_QGraphicsView_Type, "NoDrag", (long) QGraphicsView::NoDrag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX],
        &Sbk_QGraphicsView_Type, "ScrollHandDrag", (long) QGraphicsView::ScrollHandDrag))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX],
        &Sbk_QGraphicsView_Type, "RubberBandDrag", (long) QGraphicsView::RubberBandDrag))
        return ;
    // Register converter for enum 'QGraphicsView::DragMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX],
            QGraphicsView_DragMode_CppToPython_QGraphicsView_DragMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_DragMode_PythonToCpp_QGraphicsView_DragMode,
            is_QGraphicsView_DragMode_PythonToCpp_QGraphicsView_DragMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_DRAGMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsView::DragMode");
        Shiboken::Conversions::registerConverterName(converter, "DragMode");
    }
    // End of 'DragMode' enum.

    // Initialization of enum 'ViewportUpdateMode'.
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsView_Type,
        "ViewportUpdateMode",
        "PySide.QtGui.QGraphicsView.ViewportUpdateMode",
        "QGraphicsView::ViewportUpdateMode");
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
        &Sbk_QGraphicsView_Type, "FullViewportUpdate", (long) QGraphicsView::FullViewportUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
        &Sbk_QGraphicsView_Type, "MinimalViewportUpdate", (long) QGraphicsView::MinimalViewportUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
        &Sbk_QGraphicsView_Type, "SmartViewportUpdate", (long) QGraphicsView::SmartViewportUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
        &Sbk_QGraphicsView_Type, "NoViewportUpdate", (long) QGraphicsView::NoViewportUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
        &Sbk_QGraphicsView_Type, "BoundingRectViewportUpdate", (long) QGraphicsView::BoundingRectViewportUpdate))
        return ;
    // Register converter for enum 'QGraphicsView::ViewportUpdateMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX],
            QGraphicsView_ViewportUpdateMode_CppToPython_QGraphicsView_ViewportUpdateMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_ViewportUpdateMode_PythonToCpp_QGraphicsView_ViewportUpdateMode,
            is_QGraphicsView_ViewportUpdateMode_PythonToCpp_QGraphicsView_ViewportUpdateMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_VIEWPORTUPDATEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsView::ViewportUpdateMode");
        Shiboken::Conversions::registerConverterName(converter, "ViewportUpdateMode");
    }
    // End of 'ViewportUpdateMode' enum.

    // Initialization of enum 'OptimizationFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX] = PySide::QFlags::create("OptimizationFlags", &SbkPySide_QtGui_QGraphicsView_OptimizationFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QGraphicsView_Type,
        "OptimizationFlag",
        "PySide.QtGui.QGraphicsView.OptimizationFlag",
        "QGraphicsView::OptimizationFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX],
        &Sbk_QGraphicsView_Type, "DontClipPainter", (long) QGraphicsView::DontClipPainter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX],
        &Sbk_QGraphicsView_Type, "DontSavePainterState", (long) QGraphicsView::DontSavePainterState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX],
        &Sbk_QGraphicsView_Type, "DontAdjustForAntialiasing", (long) QGraphicsView::DontAdjustForAntialiasing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX],
        &Sbk_QGraphicsView_Type, "IndirectPainting", (long) QGraphicsView::IndirectPainting))
        return ;
    // Register converter for enum 'QGraphicsView::OptimizationFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX],
            QGraphicsView_OptimizationFlag_CppToPython_QGraphicsView_OptimizationFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_OptimizationFlag_PythonToCpp_QGraphicsView_OptimizationFlag,
            is_QGraphicsView_OptimizationFlag_PythonToCpp_QGraphicsView_OptimizationFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QGRAPHICSVIEW_OPTIMIZATIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QGraphicsView::OptimizationFlag");
        Shiboken::Conversions::registerConverterName(converter, "OptimizationFlag");
    }
    // Register converter for flag 'QFlags<QGraphicsView::OptimizationFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX],
            QFlags_QGraphicsView_OptimizationFlag__CppToPython_QFlags_QGraphicsView_OptimizationFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QGraphicsView_OptimizationFlag_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_,
            is_QGraphicsView_OptimizationFlag_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QGraphicsView_OptimizationFlag__PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_,
            is_QFlags_QGraphicsView_OptimizationFlag__PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag_,
            is_number_PythonToCpp_QFlags_QGraphicsView_OptimizationFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QGRAPHICSVIEW_OPTIMIZATIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QGraphicsView::OptimizationFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<OptimizationFlag>");
    }
    // End of 'OptimizationFlag' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QGraphicsView_Type, &::QGraphicsView::staticMetaObject);

    qRegisterMetaType< ::QGraphicsView::ViewportAnchor >("QGraphicsView::ViewportAnchor");
    qRegisterMetaType< ::QGraphicsView::CacheModeFlag >("QGraphicsView::CacheModeFlag");
    qRegisterMetaType< ::QGraphicsView::CacheMode >("QGraphicsView::CacheMode");
    qRegisterMetaType< ::QGraphicsView::DragMode >("QGraphicsView::DragMode");
    qRegisterMetaType< ::QGraphicsView::ViewportUpdateMode >("QGraphicsView::ViewportUpdateMode");
    qRegisterMetaType< ::QGraphicsView::OptimizationFlag >("QGraphicsView::OptimizationFlag");
    qRegisterMetaType< ::QGraphicsView::OptimizationFlags >("QGraphicsView::OptimizationFlags");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGraphicsView_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGraphicsView_Type, &::QGraphicsView::staticMetaObject, sizeof(::QGraphicsView));
}
