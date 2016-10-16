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

#include "qabstractitemview_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractitemdelegate.h>
#include <qabstractitemmodel.h>
#include <qabstractitemview.h>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qevent.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qgraphicseffect.h>
#include <qgraphicsproxywidget.h>
#include <qicon.h>
#include <qinputcontext.h>
#include <qitemselectionmodel.h>
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qscrollbar.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QAbstractItemViewWrapper::QAbstractItemViewWrapper(QWidget * parent) : QAbstractItemView(parent) {
    // ... middle
}

void QAbstractItemViewWrapper::actionEvent(QActionEvent * event)
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

void QAbstractItemViewWrapper::changeEvent(QEvent * arg__1)
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

void QAbstractItemViewWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractItemViewWrapper::closeEditor(QWidget * editor, QAbstractItemDelegate::EndEditHint hint)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEditor"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::closeEditor(editor, hint);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], editor),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_ENDEDITHINT_IDX]), &hint)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::closeEvent(QCloseEvent * event)
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

void QAbstractItemViewWrapper::commitData(QWidget * editor)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "commitData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::commitData(editor);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], editor)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::connectNotify(const char * signal)
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

void QAbstractItemViewWrapper::contextMenuEvent(QContextMenuEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::contextMenuEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], arg__1)
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

void QAbstractItemViewWrapper::currentChanged(const QModelIndex & current, const QModelIndex & previous)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "currentChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::currentChanged(current, previous);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &current),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &previous)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::customEvent(QEvent * arg__1)
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

void QAbstractItemViewWrapper::dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dataChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::dataChanged(topLeft, bottomRight);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &topLeft),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &bottomRight)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QAbstractItemViewWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::disconnectNotify(const char * signal)
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

void QAbstractItemViewWrapper::doItemsLayout()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "doItemsLayout"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::doItemsLayout();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::dragEnterEvent(QDragEnterEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::dragEnterEvent(event);
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

void QAbstractItemViewWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::dragLeaveEvent(event);
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

void QAbstractItemViewWrapper::dragMoveEvent(QDragMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::dragMoveEvent(event);
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

void QAbstractItemViewWrapper::dropEvent(QDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::dropEvent(event);
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

bool QAbstractItemViewWrapper::edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "edit"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::edit(index, trigger, event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX]), &trigger),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.edit", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
    return cppResult;
}

void QAbstractItemViewWrapper::editorDestroyed(QObject * editor)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "editorDestroyed"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::editorDestroyed(editor);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], editor)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::enterEvent(QEvent * event)
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

bool QAbstractItemViewWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractItemViewWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QAbstractItemViewWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::focusInEvent(event);
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

bool QAbstractItemViewWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::focusNextPrevChild(next);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::focusOutEvent(event);
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

int QAbstractItemViewWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::hideEvent(QHideEvent * event)
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

int QAbstractItemViewWrapper::horizontalOffset() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "horizontalOffset"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.horizontalOffset()' not implemented.");
        return ((int)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.horizontalOffset", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::horizontalScrollbarAction(int action)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "horizontalScrollbarAction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::horizontalScrollbarAction(action);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        action
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::horizontalScrollbarValueChanged(int value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "horizontalScrollbarValueChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::horizontalScrollbarValueChanged(value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        value
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QModelIndex QAbstractItemViewWrapper::indexAt(const QPoint & point) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "indexAt"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.indexAt()' not implemented.");
        return ::QModelIndex();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &point)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.indexAt", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::inputMethodEvent(event);
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

QVariant QAbstractItemViewWrapper::inputMethodQuery(Qt::InputMethodQuery query) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::inputMethodQuery(query);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractItemViewWrapper::isIndexHidden(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isIndexHidden"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.isIndexHidden()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.isIndexHidden", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::keyPressEvent(event);
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

void QAbstractItemViewWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyReleaseEvent(event);
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

void QAbstractItemViewWrapper::keyboardSearch(const QString & search)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyboardSearch"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::keyboardSearch(search);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &search)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::languageChange()
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

void QAbstractItemViewWrapper::leaveEvent(QEvent * event)
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

int QAbstractItemViewWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QAbstractItemViewWrapper::minimumSizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::mouseDoubleClickEvent(event);
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

void QAbstractItemViewWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::mouseMoveEvent(event);
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

void QAbstractItemViewWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::mousePressEvent(event);
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

void QAbstractItemViewWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::mouseReleaseEvent(event);
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

QModelIndex QAbstractItemViewWrapper::moveCursor(QAbstractItemView::CursorAction cursorAction, QFlags<Qt::KeyboardModifier> modifiers)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndex();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "moveCursor"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.moveCursor()' not implemented.");
        return ::QModelIndex();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX]), &cursorAction),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), &modifiers)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndex();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.moveCursor", Shiboken::SbkType< QModelIndex >()->tp_name, pyResult->ob_type->tp_name);
        return ::QModelIndex();
    }
    ::QModelIndex cppResult = ::QModelIndex();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QAbstractItemViewWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::paintEvent(QPaintEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::paintEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], arg__1)
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

void QAbstractItemViewWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::reset();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::resizeEvent(event);
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

void QAbstractItemViewWrapper::rowsAboutToBeRemoved(const QModelIndex & parent, int start, int end)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rowsAboutToBeRemoved"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::rowsAboutToBeRemoved(parent, start, end);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Nii)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent),
        start,
        end
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::rowsInserted(const QModelIndex & parent, int start, int end)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "rowsInserted"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::rowsInserted(parent, start, end);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Nii)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &parent),
        start,
        end
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::scrollContentsBy(int dx, int dy)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scrollContentsBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::scrollContentsBy(dx, dy);
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

void QAbstractItemViewWrapper::scrollTo(const QModelIndex & index, QAbstractItemView::ScrollHint hint)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scrollTo"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.scrollTo()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX]), &hint)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::selectAll()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "selectAll"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::selectAll();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QModelIndexList QAbstractItemViewWrapper::selectedIndexes() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QModelIndexList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "selectedIndexes"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::selectedIndexes();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QModelIndexList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.selectedIndexes", "QModelIndexList", pyResult->ob_type->tp_name);
        return ::QModelIndexList();
    }
    ::QModelIndexList cppResult = ::QModelIndexList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::selectionChanged(const QItemSelection & selected, const QItemSelection & deselected)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "selectionChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::selectionChanged(selected, deselected);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &selected),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &deselected)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QFlags<QItemSelectionModel::SelectionFlag> QAbstractItemViewWrapper::selectionCommand(const QModelIndex & index, const QEvent * event) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "selectionCommand"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::selectionCommand(index, event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.selectionCommand", Shiboken::SbkType< QFlags<QItemSelectionModel::SelectionFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
    }
    ::QFlags<QItemSelectionModel::SelectionFlag> cppResult = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QAbstractItemViewWrapper::setModel(QAbstractItemModel * model)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setModel"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::setModel(model);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], model)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::setRootIndex(const QModelIndex & index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setRootIndex"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::setRootIndex(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::setSelection(const QRect & rect, QFlags<QItemSelectionModel::SelectionFlag> command)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSelection"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.setSelection()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &command)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::setSelectionModel(QItemSelectionModel * selectionModel)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSelectionModel"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::setSelectionModel(selectionModel);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], selectionModel)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::setVisible(bool visible)
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

void QAbstractItemViewWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::showEvent(event);
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

QSize QAbstractItemViewWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QAbstractItemViewWrapper::sizeHintForColumn(int column) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHintForColumn"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::sizeHintForColumn(column);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        column
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.sizeHintForColumn", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QAbstractItemViewWrapper::sizeHintForRow(int row) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHintForRow"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::sizeHintForRow(row);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        row
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.sizeHintForRow", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::startDrag(QFlags<Qt::DropAction> supportedActions)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "startDrag"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::startDrag(supportedActions);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), &supportedActions)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::tabletEvent(QTabletEvent * event)
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

void QAbstractItemViewWrapper::timerEvent(QTimerEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::timerEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], event)
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

void QAbstractItemViewWrapper::updateEditorData()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateEditorData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::updateEditorData();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::updateEditorGeometries()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateEditorGeometries"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::updateEditorGeometries();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::updateGeometries()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateGeometries"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::updateGeometries();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QAbstractItemViewWrapper::verticalOffset() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "verticalOffset"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.verticalOffset()' not implemented.");
        return ((int)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.verticalOffset", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::verticalScrollbarAction(int action)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "verticalScrollbarAction"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::verticalScrollbarAction(action);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        action
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractItemViewWrapper::verticalScrollbarValueChanged(int value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "verticalScrollbarValueChanged"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::verticalScrollbarValueChanged(value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        value
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QStyleOptionViewItem QAbstractItemViewWrapper::viewOptions() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return QStyleOptionViewItem();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "viewOptions"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::viewOptions();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return QStyleOptionViewItem();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.viewOptions", Shiboken::SbkType< QStyleOptionViewItem >()->tp_name, pyResult->ob_type->tp_name);
        return QStyleOptionViewItem();
    }
    ::QStyleOptionViewItem cppResult = ::QStyleOptionViewItem();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QAbstractItemViewWrapper::viewportEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "viewportEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractItemView::viewportEvent(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.viewportEvent", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QRect QAbstractItemViewWrapper::visualRect(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "visualRect"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.visualRect()' not implemented.");
        return ::QRect();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.visualRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRegion QAbstractItemViewWrapper::visualRegionForSelection(const QItemSelection & selection) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRegion();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "visualRegionForSelection"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.visualRegionForSelection()' not implemented.");
        return ::QRegion();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &selection)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRegion();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractItemView.visualRegionForSelection", Shiboken::SbkType< QRegion >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRegion();
    }
    ::QRegion cppResult = ::QRegion();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractItemViewWrapper::wheelEvent(QWheelEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::wheelEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], arg__1)
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

const QMetaObject* QAbstractItemViewWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractItemView::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractItemViewWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractItemView::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractItemViewWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractItemViewWrapper* >(this));
        return QAbstractItemView::qt_metacast(_clname);
}

QAbstractItemViewWrapper::~QAbstractItemViewWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractItemView_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QAbstractItemView' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractItemView >()))
        return -1;

    ::QAbstractItemViewWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QAbstractItemView", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractItemView(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QAbstractItemView(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAbstractItemView(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemView_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractItemView_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractItemView(QWidget*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractItemViewWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractItemViewWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractItemView >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractItemView_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QAbstractItemView_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractItemViewFunc_alternatingRowColors(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alternatingRowColors()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->alternatingRowColors();
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

static PyObject* Sbk_QAbstractItemViewFunc_autoScrollMargin(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoScrollMargin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->autoScrollMargin();
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

static PyObject* Sbk_QAbstractItemViewFunc_clearSelection(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QAbstractItemViewFunc_closeEditor(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "closeEditor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_ENDEDITHINT_IDX]), (pyArgs[1])))) {
        overloadId = 0; // closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_closeEditor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QAbstractItemDelegate::EndEditHint cppArg1 = ((::QAbstractItemDelegate::EndEditHint)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // closeEditor(QWidget*,QAbstractItemDelegate::EndEditHint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::closeEditor(cppArg0, cppArg1) : cppSelf->closeEditor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_closeEditor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtGui.QAbstractItemDelegate.EndEditHint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.closeEditor", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_closePersistentEditor(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closePersistentEditor(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // closePersistentEditor(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_closePersistentEditor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // closePersistentEditor(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->closePersistentEditor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_closePersistentEditor_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.closePersistentEditor", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_commitData(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: commitData(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // commitData(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_commitData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // commitData(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::commitData(cppArg0) : cppSelf->commitData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_commitData_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.commitData", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_currentChanged(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "currentChanged", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: currentChanged(QModelIndex,QModelIndex)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // currentChanged(QModelIndex,QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_currentChanged_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // currentChanged(QModelIndex,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::currentChanged(*cppArg0, *cppArg1) : cppSelf->currentChanged(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_currentChanged_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.currentChanged", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_currentIndex(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->currentIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_dataChanged(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "dataChanged", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: dataChanged(QModelIndex,QModelIndex)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // dataChanged(QModelIndex,QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_dataChanged_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // dataChanged(QModelIndex,QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::dataChanged(*cppArg0, *cppArg1) : cppSelf->dataChanged(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_dataChanged_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.dataChanged", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_defaultDropAction(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultDropAction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DropAction cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->defaultDropAction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_dirtyRegionOffset(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dirtyRegionOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->dirtyRegionOffset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_doAutoScroll(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doAutoScroll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->doAutoScroll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_doItemsLayout(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doItemsLayout()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::doItemsLayout() : cppSelf->doItemsLayout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_dragDropMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dragDropMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::DragDropMode cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->dragDropMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_dragDropOverwriteMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dragDropOverwriteMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->dragDropOverwriteMode();
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

static PyObject* Sbk_QAbstractItemViewFunc_dragEnabled(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dragEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->dragEnabled();
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

static PyObject* Sbk_QAbstractItemViewFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QDragEnterEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QDragEnterEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragEnterEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QDragEnterEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragEnterEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QDragLeaveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QDragLeaveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragLeaveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QDragLeaveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragLeaveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QDragMoveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QDragMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragMoveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QDragMoveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_dropIndicatorPosition(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dropIndicatorPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::DropIndicatorPosition cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->dropIndicatorPosition();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_edit(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QAbstractItemViewFunc_edit_TypeError;

    if (!PyArg_UnpackTuple(args, "edit", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: edit(QModelIndex)
    // 1: edit(QModelIndex,QAbstractItemView::EditTrigger,QEvent*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // edit(QModelIndex)
        } else if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX]), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[2])))) {
            overloadId = 1; // edit(QModelIndex,QAbstractItemView::EditTrigger,QEvent*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_edit_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // edit(const QModelIndex & index)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // edit(QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->edit(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // edit(const QModelIndex & index, QAbstractItemView::EditTrigger trigger, QEvent * event)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QAbstractItemView::EditTrigger cppArg1 = ((::QAbstractItemView::EditTrigger)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QEvent* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // edit(QModelIndex,QAbstractItemView::EditTrigger,QEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::edit(*cppArg0, cppArg1, cppArg2) : cppSelf->edit(*cppArg0, cppArg1, cppArg2);
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

    Sbk_QAbstractItemViewFunc_edit_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", "PySide.QtCore.QModelIndex, PySide.QtGui.QAbstractItemView.EditTrigger, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.edit", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_editTriggers(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // editTriggers()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QAbstractItemView::EditTrigger> cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->editTriggers();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_editorDestroyed(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: editorDestroyed(QObject*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArg)))) {
        overloadId = 0; // editorDestroyed(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_editorDestroyed_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // editorDestroyed(QObject*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::editorDestroyed(cppArg0) : cppSelf->editorDestroyed(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_editorDestroyed_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.editorDestroyed", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.event", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_executeDelayedItemsLayout(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // executeDelayedItemsLayout()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->executeDelayedItemsLayout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::focusNextPrevChild(cppArg0) : cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_hasAutoScroll(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAutoScroll()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->hasAutoScroll();
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

static PyObject* Sbk_QAbstractItemViewFunc_horizontalOffset(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalOffset()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.horizontalOffset()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->horizontalOffset();
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

static PyObject* Sbk_QAbstractItemViewFunc_horizontalScrollMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalScrollMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::ScrollMode cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->horizontalScrollMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_horizontalScrollbarAction(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: horizontalScrollbarAction(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // horizontalScrollbarAction(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_horizontalScrollbarAction_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // horizontalScrollbarAction(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::horizontalScrollbarAction(cppArg0) : cppSelf->horizontalScrollbarAction(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_horizontalScrollbarAction_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.horizontalScrollbarAction", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_horizontalScrollbarValueChanged(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: horizontalScrollbarValueChanged(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // horizontalScrollbarValueChanged(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_horizontalScrollbarValueChanged_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // horizontalScrollbarValueChanged(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::horizontalScrollbarValueChanged(cppArg0) : cppSelf->horizontalScrollbarValueChanged(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_horizontalScrollbarValueChanged_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.horizontalScrollbarValueChanged", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_iconSize(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->iconSize();
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

static PyObject* Sbk_QAbstractItemViewFunc_indexAt(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexAt(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // indexAt(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_indexAt_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPoint cppArg0_local = ::QPoint();
        ::QPoint* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // indexAt(QPoint)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.indexAt()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->indexAt(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_indexAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.indexAt", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_indexWidget(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexWidget(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // indexWidget(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_indexWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // indexWidget(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->indexWidget(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_indexWidget_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.indexWidget", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::inputMethodQuery(cppArg0) : const_cast<const ::QAbstractItemView*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_isIndexHidden(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isIndexHidden(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // isIndexHidden(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_isIndexHidden_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isIndexHidden(QModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.isIndexHidden()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->isIndexHidden(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_isIndexHidden_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.isIndexHidden", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_itemDelegate(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemDelegate", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: itemDelegate()const
    // 1: itemDelegate(QModelIndex)const
    if (numArgs == 0) {
        overloadId = 0; // itemDelegate()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 1; // itemDelegate(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_itemDelegate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // itemDelegate() const
        {

            if (!PyErr_Occurred()) {
                // itemDelegate()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QAbstractItemDelegate * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->itemDelegate();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // itemDelegate(const QModelIndex & index) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // itemDelegate(QModelIndex)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QAbstractItemDelegate * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->itemDelegate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], cppResult);
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

    Sbk_QAbstractItemViewFunc_itemDelegate_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.itemDelegate", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_itemDelegateForColumn(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemDelegateForColumn(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // itemDelegateForColumn(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_itemDelegateForColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemDelegateForColumn(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemDelegate * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->itemDelegateForColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_itemDelegateForColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.itemDelegateForColumn", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_itemDelegateForRow(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemDelegateForRow(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // itemDelegateForRow(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_itemDelegateForRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemDelegateForRow(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemDelegate * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->itemDelegateForRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_itemDelegateForRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.itemDelegateForRow", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_keyboardSearch(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyboardSearch(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // keyboardSearch(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_keyboardSearch_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyboardSearch(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::keyboardSearch(cppArg0) : cppSelf->keyboardSearch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_keyboardSearch_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.keyboardSearch", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_model(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemModel * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_moveCursor(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "moveCursor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveCursor(QAbstractItemView::CursorAction,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER__IDX]), (pyArgs[1])))) {
        overloadId = 0; // moveCursor(QAbstractItemView::CursorAction,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_moveCursor_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::CursorAction cppArg0 = ((::QAbstractItemView::CursorAction)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::KeyboardModifier> cppArg1 = ((::QFlags<Qt::KeyboardModifier>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveCursor(QAbstractItemView::CursorAction,QFlags<Qt::KeyboardModifier>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.moveCursor()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = cppSelf->moveCursor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_moveCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.CursorAction, PySide.QtCore.Qt.KeyboardModifiers", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.moveCursor", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_openPersistentEditor(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: openPersistentEditor(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // openPersistentEditor(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_openPersistentEditor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // openPersistentEditor(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->openPersistentEditor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_openPersistentEditor_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.openPersistentEditor", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_reset(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::reset() : cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_resizeEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QResizeEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_rootIndex(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rootIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->rootIndex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_rowsAboutToBeRemoved(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rowsAboutToBeRemoved", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: rowsAboutToBeRemoved(QModelIndex,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // rowsAboutToBeRemoved(QModelIndex,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_rowsAboutToBeRemoved_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // rowsAboutToBeRemoved(QModelIndex,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::rowsAboutToBeRemoved(*cppArg0, cppArg1, cppArg2) : cppSelf->rowsAboutToBeRemoved(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_rowsAboutToBeRemoved_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.rowsAboutToBeRemoved", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_rowsInserted(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rowsInserted", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: rowsInserted(QModelIndex,int,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // rowsInserted(QModelIndex,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_rowsInserted_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // rowsInserted(QModelIndex,int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::rowsInserted(*cppArg0, cppArg1, cppArg2) : cppSelf->rowsInserted(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_rowsInserted_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.rowsInserted", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_scheduleDelayedItemsLayout(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scheduleDelayedItemsLayout()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scheduleDelayedItemsLayout();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_scrollDirtyRegion(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scrollDirtyRegion", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scrollDirtyRegion(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // scrollDirtyRegion(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_scrollDirtyRegion_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scrollDirtyRegion(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scrollDirtyRegion(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_scrollDirtyRegion_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.scrollDirtyRegion", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_scrollTo(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.scrollTo(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.scrollTo(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:scrollTo", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scrollTo(QModelIndex,QAbstractItemView::ScrollHint)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // scrollTo(QModelIndex,QAbstractItemView::ScrollHint)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX]), (pyArgs[1])))) {
            overloadId = 0; // scrollTo(QModelIndex,QAbstractItemView::ScrollHint)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_scrollTo_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "hint");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.scrollTo(): got multiple values for keyword argument 'hint'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX]), (pyArgs[1]))))
                    goto Sbk_QAbstractItemViewFunc_scrollTo_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QAbstractItemView::ScrollHint cppArg1 = QAbstractItemView::EnsureVisible;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scrollTo(QModelIndex,QAbstractItemView::ScrollHint)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.scrollTo()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scrollTo(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_scrollTo_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtGui.QAbstractItemView.ScrollHint = EnsureVisible", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.scrollTo", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_scrollToBottom(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scrollToBottom()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scrollToBottom();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_scrollToTop(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scrollToTop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scrollToTop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectAll(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::selectAll() : cppSelf->selectAll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectedIndexes(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedIndexes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::selectedIndexes() : const_cast<const ::QAbstractItemView*>(cppSelf)->selectedIndexes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectionBehavior(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionBehavior()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::SelectionBehavior cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->selectionBehavior();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectionChanged(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "selectionChanged", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: selectionChanged(QItemSelection,QItemSelection)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[1])))) {
        overloadId = 0; // selectionChanged(QItemSelection,QItemSelection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_selectionChanged_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelection cppArg0_local = ::QItemSelection();
        ::QItemSelection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemSelection cppArg1_local = ::QItemSelection();
        ::QItemSelection* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // selectionChanged(QItemSelection,QItemSelection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::selectionChanged(*cppArg0, *cppArg1) : cppSelf->selectionChanged(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_selectionChanged_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelection, PySide.QtGui.QItemSelection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.selectionChanged", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectionCommand(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.selectionCommand(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.selectionCommand(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:selectionCommand", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: selectionCommand(QModelIndex,const QEvent*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // selectionCommand(QModelIndex,const QEvent*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
            overloadId = 0; // selectionCommand(QModelIndex,const QEvent*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_selectionCommand_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "event");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractItemView.selectionCommand(): got multiple values for keyword argument 'event'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1]))))
                    goto Sbk_QAbstractItemViewFunc_selectionCommand_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // selectionCommand(QModelIndex,const QEvent*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QItemSelectionModel::SelectionFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::selectionCommand(*cppArg0, cppArg1) : const_cast<const ::QAbstractItemView*>(cppSelf)->selectionCommand(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_selectionCommand_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtCore.QEvent = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.selectionCommand", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectionMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::SelectionMode cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->selectionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_selectionModel(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionModel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QItemSelectionModel * cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->selectionModel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], cppResult);

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_setAlternatingRowColors(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlternatingRowColors(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAlternatingRowColors(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setAlternatingRowColors_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAlternatingRowColors(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlternatingRowColors(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setAlternatingRowColors_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setAlternatingRowColors", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setAutoScroll(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoScroll(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoScroll(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setAutoScroll_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoScroll(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoScroll(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setAutoScroll_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setAutoScroll", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setAutoScrollMargin(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoScrollMargin(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAutoScrollMargin(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setAutoScrollMargin_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoScrollMargin(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoScrollMargin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setAutoScrollMargin_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setAutoScrollMargin", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setCurrentIndex(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentIndex(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentIndex(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setCurrentIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCurrentIndex(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setCurrentIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setCurrentIndex", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDefaultDropAction(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultDropAction(Qt::DropAction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DROPACTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDefaultDropAction(Qt::DropAction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDefaultDropAction_TypeError;

    // Call function/method
    {
        ::Qt::DropAction cppArg0 = ((::Qt::DropAction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultDropAction(Qt::DropAction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultDropAction(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDefaultDropAction_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDefaultDropAction", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDirtyRegion(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirtyRegion(QRegion)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArg)))) {
        overloadId = 0; // setDirtyRegion(QRegion)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDirtyRegion_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRegion cppArg0_local = ::QRegion();
        ::QRegion* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDirtyRegion(QRegion)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirtyRegion(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDirtyRegion_TypeError:
        const char* overloads[] = {"PySide.QtGui.QRegion", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDirtyRegion", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDragDropMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragDropMode(QAbstractItemView::DragDropMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setDragDropMode(QAbstractItemView::DragDropMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDragDropMode_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::DragDropMode cppArg0 = ((::QAbstractItemView::DragDropMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDragDropMode(QAbstractItemView::DragDropMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDragDropMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDragDropMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.DragDropMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDragDropMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDragDropOverwriteMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragDropOverwriteMode(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDragDropOverwriteMode(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDragDropOverwriteMode_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDragDropOverwriteMode(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDragDropOverwriteMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDragDropOverwriteMode_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDragDropOverwriteMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDragEnabled(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDragEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDragEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDragEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDragEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDragEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDragEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setDropIndicatorShown(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDropIndicatorShown(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDropIndicatorShown(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setDropIndicatorShown_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDropIndicatorShown(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDropIndicatorShown(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setDropIndicatorShown_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setDropIndicatorShown", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setEditTriggers(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEditTriggers(QFlags<QAbstractItemView::EditTrigger>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), (pyArg)))) {
        overloadId = 0; // setEditTriggers(QFlags<QAbstractItemView::EditTrigger>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setEditTriggers_TypeError;

    // Call function/method
    {
        ::QFlags<QAbstractItemView::EditTrigger> cppArg0 = ((::QFlags<QAbstractItemView::EditTrigger>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEditTriggers(QFlags<QAbstractItemView::EditTrigger>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEditTriggers(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setEditTriggers_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.EditTriggers", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setEditTriggers", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setHorizontalScrollMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalScrollMode(QAbstractItemView::ScrollMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setHorizontalScrollMode(QAbstractItemView::ScrollMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setHorizontalScrollMode_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::ScrollMode cppArg0 = ((::QAbstractItemView::ScrollMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalScrollMode(QAbstractItemView::ScrollMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalScrollMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setHorizontalScrollMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.ScrollMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setHorizontalScrollMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setIconSize(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconSize(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setIconSize(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setIconSize_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setIconSize(QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconSize(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setIconSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setIconSize", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setIndexWidget(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setIndexWidget", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setIndexWidget(QModelIndex,QWidget*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        overloadId = 0; // setIndexWidget(QModelIndex,QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setIndexWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setIndexWidget(QModelIndex,QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIndexWidget(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setIndexWidget_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.setIndexWidget", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setItemDelegate(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItemDelegate(QAbstractItemDelegate*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], (pyArg)))) {
        overloadId = 0; // setItemDelegate(QAbstractItemDelegate*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setItemDelegate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemDelegate* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setItemDelegate(QAbstractItemDelegate*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemDelegate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setItemDelegate(QAbstractItemDelegate*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setItemDelegate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemDelegate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setItemDelegate", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setItemDelegateForColumn(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setItemDelegateForColumn", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setItemDelegateForColumn(int,QAbstractItemDelegate*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setItemDelegateForColumn(int,QAbstractItemDelegate*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setItemDelegateForColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QAbstractItemDelegate* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setItemDelegateForColumn(int,QAbstractItemDelegate*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemDelegateForColumn(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setItemDelegateForColumn_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QAbstractItemDelegate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.setItemDelegateForColumn", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setItemDelegateForRow(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setItemDelegateForRow", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setItemDelegateForRow(int,QAbstractItemDelegate*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setItemDelegateForRow(int,QAbstractItemDelegate*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setItemDelegateForRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QAbstractItemDelegate* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setItemDelegateForRow(int,QAbstractItemDelegate*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItemDelegateForRow(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setItemDelegateForRow_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QAbstractItemDelegate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.setItemDelegateForRow", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setModel(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModel(QAbstractItemModel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], (pyArg)))) {
        overloadId = 0; // setModel(QAbstractItemModel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemModel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModel(QAbstractItemModel*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::setModel(cppArg0) : cppSelf->setModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setModel(QAbstractItemModel*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setModel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractItemModel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setModel", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setRootIndex(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRootIndex(QModelIndex)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // setRootIndex(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setRootIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setRootIndex(QModelIndex)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::setRootIndex(*cppArg0) : cppSelf->setRootIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setRootIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setRootIndex", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setSelection(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSelection", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSelection(QRect,QFlags<QItemSelectionModel::SelectionFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // setSelection(QRect,QFlags<QItemSelectionModel::SelectionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setSelection_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRect cppArg0_local = ::QRect();
        ::QRect* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QFlags<QItemSelectionModel::SelectionFlag> cppArg1 = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSelection(QRect,QFlags<QItemSelectionModel::SelectionFlag>)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.setSelection()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelection(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setSelection_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, PySide.QtGui.QItemSelectionModel.SelectionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.setSelection", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setSelectionBehavior(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelectionBehavior(QAbstractItemView::SelectionBehavior)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX]), (pyArg)))) {
        overloadId = 0; // setSelectionBehavior(QAbstractItemView::SelectionBehavior)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setSelectionBehavior_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::SelectionBehavior cppArg0 = ((::QAbstractItemView::SelectionBehavior)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelectionBehavior(QAbstractItemView::SelectionBehavior)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelectionBehavior(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setSelectionBehavior_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.SelectionBehavior", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setSelectionBehavior", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setSelectionMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelectionMode(QAbstractItemView::SelectionMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setSelectionMode(QAbstractItemView::SelectionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setSelectionMode_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::SelectionMode cppArg0 = ((::QAbstractItemView::SelectionMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelectionMode(QAbstractItemView::SelectionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelectionMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setSelectionMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.SelectionMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setSelectionMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setSelectionModel(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelectionModel(QItemSelectionModel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (pyArg)))) {
        overloadId = 0; // setSelectionModel(QItemSelectionModel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setSelectionModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QItemSelectionModel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelectionModel(QItemSelectionModel*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::setSelectionModel(cppArg0) : cppSelf->setSelectionModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setSelectionModel(QItemSelectionModel*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setSelectionModel_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelectionModel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setSelectionModel", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setState(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setState(QAbstractItemView::State)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX]), (pyArg)))) {
        overloadId = 0; // setState(QAbstractItemView::State)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setState_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::State cppArg0 = ((::QAbstractItemView::State)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setState(QAbstractItemView::State)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setState_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.State", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setState", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setTabKeyNavigation(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabKeyNavigation(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setTabKeyNavigation(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setTabKeyNavigation_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabKeyNavigation(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabKeyNavigation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setTabKeyNavigation_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setTabKeyNavigation", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setTextElideMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextElideMode(Qt::TextElideMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setTextElideMode(Qt::TextElideMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setTextElideMode_TypeError;

    // Call function/method
    {
        ::Qt::TextElideMode cppArg0 = ((::Qt::TextElideMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextElideMode(Qt::TextElideMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextElideMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setTextElideMode_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TextElideMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setTextElideMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_setVerticalScrollMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalScrollMode(QAbstractItemView::ScrollMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setVerticalScrollMode(QAbstractItemView::ScrollMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_setVerticalScrollMode_TypeError;

    // Call function/method
    {
        ::QAbstractItemView::ScrollMode cppArg0 = ((::QAbstractItemView::ScrollMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalScrollMode(QAbstractItemView::ScrollMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalScrollMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_setVerticalScrollMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView.ScrollMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.setVerticalScrollMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_showDropIndicator(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // showDropIndicator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->showDropIndicator();
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

static PyObject* Sbk_QAbstractItemViewFunc_sizeHintForColumn(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sizeHintForColumn(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // sizeHintForColumn(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_sizeHintForColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sizeHintForColumn(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::sizeHintForColumn(cppArg0) : const_cast<const ::QAbstractItemView*>(cppSelf)->sizeHintForColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_sizeHintForColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.sizeHintForColumn", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_sizeHintForIndex(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sizeHintForIndex(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // sizeHintForIndex(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_sizeHintForIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // sizeHintForIndex(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->sizeHintForIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_sizeHintForIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.sizeHintForIndex", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_sizeHintForRow(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sizeHintForRow(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // sizeHintForRow(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_sizeHintForRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sizeHintForRow(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::sizeHintForRow(cppArg0) : const_cast<const ::QAbstractItemView*>(cppSelf)->sizeHintForRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_sizeHintForRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.sizeHintForRow", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_startAutoScroll(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startAutoScroll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->startAutoScroll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_startDrag(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: startDrag(QFlags<Qt::DropAction>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DROPACTION__IDX]), (pyArg)))) {
        overloadId = 0; // startDrag(QFlags<Qt::DropAction>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_startDrag_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::DropAction> cppArg0 = ((::QFlags<Qt::DropAction>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // startDrag(QFlags<Qt::DropAction>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::startDrag(cppArg0) : cppSelf->startDrag(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_startDrag_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DropActions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.startDrag", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_state(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::State cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_stopAutoScroll(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stopAutoScroll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stopAutoScroll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_tabKeyNavigation(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabKeyNavigation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->tabKeyNavigation();
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

static PyObject* Sbk_QAbstractItemViewFunc_textElideMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textElideMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::TextElideMode cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->textElideMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTELIDEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_update(PyObject* self, PyObject* args)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "update", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: update()
    // 1: update(QModelIndex)
    if (numArgs == 0) {
        overloadId = 0; // update()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))) {
        overloadId = 1; // update(QModelIndex)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_update_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // update()
        {

            if (!PyErr_Occurred()) {
                // update()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->update();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // update(const QModelIndex & index)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // update(QModelIndex)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->update(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_update_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractItemView.update", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_updateEditorData(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateEditorData()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::updateEditorData() : cppSelf->updateEditorData();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_updateEditorGeometries(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateEditorGeometries()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::updateEditorGeometries() : cppSelf->updateEditorGeometries();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_updateGeometries(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateGeometries()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::updateGeometries() : cppSelf->updateGeometries();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractItemViewFunc_verticalOffset(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalOffset()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.verticalOffset()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->verticalOffset();
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

static PyObject* Sbk_QAbstractItemViewFunc_verticalScrollMode(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalScrollMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView::ScrollMode cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->verticalScrollMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_verticalScrollbarAction(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: verticalScrollbarAction(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // verticalScrollbarAction(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_verticalScrollbarAction_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // verticalScrollbarAction(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::verticalScrollbarAction(cppArg0) : cppSelf->verticalScrollbarAction(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_verticalScrollbarAction_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.verticalScrollbarAction", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_verticalScrollbarValueChanged(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: verticalScrollbarValueChanged(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // verticalScrollbarValueChanged(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_verticalScrollbarValueChanged_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // verticalScrollbarValueChanged(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::verticalScrollbarValueChanged(cppArg0) : cppSelf->verticalScrollbarValueChanged(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractItemViewFunc_verticalScrollbarValueChanged_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.verticalScrollbarValueChanged", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_viewOptions(PyObject* self)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewOptions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStyleOptionViewItem cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractItemView*>(cppSelf)->::QAbstractItemView::viewOptions() : const_cast<const ::QAbstractItemView*>(cppSelf)->viewOptions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONVIEWITEM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractItemViewFunc_viewportEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_viewportEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // viewportEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractItemView::viewportEvent(cppArg0) : cppSelf->viewportEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_viewportEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.viewportEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_visualRect(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: visualRect(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // visualRect(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_visualRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // visualRect(QModelIndex)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.visualRect()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->visualRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_visualRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.visualRect", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractItemViewFunc_visualRegionForSelection(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractItemView*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: visualRegionForSelection(QItemSelection)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArg)))) {
        overloadId = 0; // visualRegionForSelection(QItemSelection)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractItemViewFunc_visualRegionForSelection_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QItemSelection cppArg0_local = ::QItemSelection();
        ::QItemSelection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // visualRegionForSelection(QItemSelection)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QAbstractItemView.visualRegionForSelection()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegion cppResult = const_cast<const ::QAbstractItemView*>(cppSelf)->visualRegionForSelection(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractItemViewFunc_visualRegionForSelection_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractItemView.visualRegionForSelection", overloads);
        return 0;
}

static PyMethodDef Sbk_QAbstractItemView_methods[] = {
    {"alternatingRowColors", (PyCFunction)Sbk_QAbstractItemViewFunc_alternatingRowColors, METH_NOARGS},
    {"autoScrollMargin", (PyCFunction)Sbk_QAbstractItemViewFunc_autoScrollMargin, METH_NOARGS},
    {"clearSelection", (PyCFunction)Sbk_QAbstractItemViewFunc_clearSelection, METH_NOARGS},
    {"closeEditor", (PyCFunction)Sbk_QAbstractItemViewFunc_closeEditor, METH_VARARGS},
    {"closePersistentEditor", (PyCFunction)Sbk_QAbstractItemViewFunc_closePersistentEditor, METH_O},
    {"commitData", (PyCFunction)Sbk_QAbstractItemViewFunc_commitData, METH_O},
    {"currentChanged", (PyCFunction)Sbk_QAbstractItemViewFunc_currentChanged, METH_VARARGS},
    {"currentIndex", (PyCFunction)Sbk_QAbstractItemViewFunc_currentIndex, METH_NOARGS},
    {"dataChanged", (PyCFunction)Sbk_QAbstractItemViewFunc_dataChanged, METH_VARARGS},
    {"defaultDropAction", (PyCFunction)Sbk_QAbstractItemViewFunc_defaultDropAction, METH_NOARGS},
    {"dirtyRegionOffset", (PyCFunction)Sbk_QAbstractItemViewFunc_dirtyRegionOffset, METH_NOARGS},
    {"doAutoScroll", (PyCFunction)Sbk_QAbstractItemViewFunc_doAutoScroll, METH_NOARGS},
    {"doItemsLayout", (PyCFunction)Sbk_QAbstractItemViewFunc_doItemsLayout, METH_NOARGS},
    {"dragDropMode", (PyCFunction)Sbk_QAbstractItemViewFunc_dragDropMode, METH_NOARGS},
    {"dragDropOverwriteMode", (PyCFunction)Sbk_QAbstractItemViewFunc_dragDropOverwriteMode, METH_NOARGS},
    {"dragEnabled", (PyCFunction)Sbk_QAbstractItemViewFunc_dragEnabled, METH_NOARGS},
    {"dragEnterEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_dragLeaveEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_dragMoveEvent, METH_O},
    {"dropEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_dropEvent, METH_O},
    {"dropIndicatorPosition", (PyCFunction)Sbk_QAbstractItemViewFunc_dropIndicatorPosition, METH_NOARGS},
    {"edit", (PyCFunction)Sbk_QAbstractItemViewFunc_edit, METH_VARARGS},
    {"editTriggers", (PyCFunction)Sbk_QAbstractItemViewFunc_editTriggers, METH_NOARGS},
    {"editorDestroyed", (PyCFunction)Sbk_QAbstractItemViewFunc_editorDestroyed, METH_O},
    {"event", (PyCFunction)Sbk_QAbstractItemViewFunc_event, METH_O},
    {"executeDelayedItemsLayout", (PyCFunction)Sbk_QAbstractItemViewFunc_executeDelayedItemsLayout, METH_NOARGS},
    {"focusInEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_focusInEvent, METH_O},
    {"focusNextPrevChild", (PyCFunction)Sbk_QAbstractItemViewFunc_focusNextPrevChild, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_focusOutEvent, METH_O},
    {"hasAutoScroll", (PyCFunction)Sbk_QAbstractItemViewFunc_hasAutoScroll, METH_NOARGS},
    {"horizontalOffset", (PyCFunction)Sbk_QAbstractItemViewFunc_horizontalOffset, METH_NOARGS},
    {"horizontalScrollMode", (PyCFunction)Sbk_QAbstractItemViewFunc_horizontalScrollMode, METH_NOARGS},
    {"horizontalScrollbarAction", (PyCFunction)Sbk_QAbstractItemViewFunc_horizontalScrollbarAction, METH_O},
    {"horizontalScrollbarValueChanged", (PyCFunction)Sbk_QAbstractItemViewFunc_horizontalScrollbarValueChanged, METH_O},
    {"iconSize", (PyCFunction)Sbk_QAbstractItemViewFunc_iconSize, METH_NOARGS},
    {"indexAt", (PyCFunction)Sbk_QAbstractItemViewFunc_indexAt, METH_O},
    {"indexWidget", (PyCFunction)Sbk_QAbstractItemViewFunc_indexWidget, METH_O},
    {"inputMethodEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_inputMethodEvent, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QAbstractItemViewFunc_inputMethodQuery, METH_O},
    {"isIndexHidden", (PyCFunction)Sbk_QAbstractItemViewFunc_isIndexHidden, METH_O},
    {"itemDelegate", (PyCFunction)Sbk_QAbstractItemViewFunc_itemDelegate, METH_VARARGS},
    {"itemDelegateForColumn", (PyCFunction)Sbk_QAbstractItemViewFunc_itemDelegateForColumn, METH_O},
    {"itemDelegateForRow", (PyCFunction)Sbk_QAbstractItemViewFunc_itemDelegateForRow, METH_O},
    {"keyPressEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_keyPressEvent, METH_O},
    {"keyboardSearch", (PyCFunction)Sbk_QAbstractItemViewFunc_keyboardSearch, METH_O},
    {"model", (PyCFunction)Sbk_QAbstractItemViewFunc_model, METH_NOARGS},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_mouseReleaseEvent, METH_O},
    {"moveCursor", (PyCFunction)Sbk_QAbstractItemViewFunc_moveCursor, METH_VARARGS},
    {"openPersistentEditor", (PyCFunction)Sbk_QAbstractItemViewFunc_openPersistentEditor, METH_O},
    {"reset", (PyCFunction)Sbk_QAbstractItemViewFunc_reset, METH_NOARGS},
    {"resizeEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_resizeEvent, METH_O},
    {"rootIndex", (PyCFunction)Sbk_QAbstractItemViewFunc_rootIndex, METH_NOARGS},
    {"rowsAboutToBeRemoved", (PyCFunction)Sbk_QAbstractItemViewFunc_rowsAboutToBeRemoved, METH_VARARGS},
    {"rowsInserted", (PyCFunction)Sbk_QAbstractItemViewFunc_rowsInserted, METH_VARARGS},
    {"scheduleDelayedItemsLayout", (PyCFunction)Sbk_QAbstractItemViewFunc_scheduleDelayedItemsLayout, METH_NOARGS},
    {"scrollDirtyRegion", (PyCFunction)Sbk_QAbstractItemViewFunc_scrollDirtyRegion, METH_VARARGS},
    {"scrollTo", (PyCFunction)Sbk_QAbstractItemViewFunc_scrollTo, METH_VARARGS|METH_KEYWORDS},
    {"scrollToBottom", (PyCFunction)Sbk_QAbstractItemViewFunc_scrollToBottom, METH_NOARGS},
    {"scrollToTop", (PyCFunction)Sbk_QAbstractItemViewFunc_scrollToTop, METH_NOARGS},
    {"selectAll", (PyCFunction)Sbk_QAbstractItemViewFunc_selectAll, METH_NOARGS},
    {"selectedIndexes", (PyCFunction)Sbk_QAbstractItemViewFunc_selectedIndexes, METH_NOARGS},
    {"selectionBehavior", (PyCFunction)Sbk_QAbstractItemViewFunc_selectionBehavior, METH_NOARGS},
    {"selectionChanged", (PyCFunction)Sbk_QAbstractItemViewFunc_selectionChanged, METH_VARARGS},
    {"selectionCommand", (PyCFunction)Sbk_QAbstractItemViewFunc_selectionCommand, METH_VARARGS|METH_KEYWORDS},
    {"selectionMode", (PyCFunction)Sbk_QAbstractItemViewFunc_selectionMode, METH_NOARGS},
    {"selectionModel", (PyCFunction)Sbk_QAbstractItemViewFunc_selectionModel, METH_NOARGS},
    {"setAlternatingRowColors", (PyCFunction)Sbk_QAbstractItemViewFunc_setAlternatingRowColors, METH_O},
    {"setAutoScroll", (PyCFunction)Sbk_QAbstractItemViewFunc_setAutoScroll, METH_O},
    {"setAutoScrollMargin", (PyCFunction)Sbk_QAbstractItemViewFunc_setAutoScrollMargin, METH_O},
    {"setCurrentIndex", (PyCFunction)Sbk_QAbstractItemViewFunc_setCurrentIndex, METH_O},
    {"setDefaultDropAction", (PyCFunction)Sbk_QAbstractItemViewFunc_setDefaultDropAction, METH_O},
    {"setDirtyRegion", (PyCFunction)Sbk_QAbstractItemViewFunc_setDirtyRegion, METH_O},
    {"setDragDropMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setDragDropMode, METH_O},
    {"setDragDropOverwriteMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setDragDropOverwriteMode, METH_O},
    {"setDragEnabled", (PyCFunction)Sbk_QAbstractItemViewFunc_setDragEnabled, METH_O},
    {"setDropIndicatorShown", (PyCFunction)Sbk_QAbstractItemViewFunc_setDropIndicatorShown, METH_O},
    {"setEditTriggers", (PyCFunction)Sbk_QAbstractItemViewFunc_setEditTriggers, METH_O},
    {"setHorizontalScrollMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setHorizontalScrollMode, METH_O},
    {"setIconSize", (PyCFunction)Sbk_QAbstractItemViewFunc_setIconSize, METH_O},
    {"setIndexWidget", (PyCFunction)Sbk_QAbstractItemViewFunc_setIndexWidget, METH_VARARGS},
    {"setItemDelegate", (PyCFunction)Sbk_QAbstractItemViewFunc_setItemDelegate, METH_O},
    {"setItemDelegateForColumn", (PyCFunction)Sbk_QAbstractItemViewFunc_setItemDelegateForColumn, METH_VARARGS},
    {"setItemDelegateForRow", (PyCFunction)Sbk_QAbstractItemViewFunc_setItemDelegateForRow, METH_VARARGS},
    {"setModel", (PyCFunction)Sbk_QAbstractItemViewFunc_setModel, METH_O},
    {"setRootIndex", (PyCFunction)Sbk_QAbstractItemViewFunc_setRootIndex, METH_O},
    {"setSelection", (PyCFunction)Sbk_QAbstractItemViewFunc_setSelection, METH_VARARGS},
    {"setSelectionBehavior", (PyCFunction)Sbk_QAbstractItemViewFunc_setSelectionBehavior, METH_O},
    {"setSelectionMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setSelectionMode, METH_O},
    {"setSelectionModel", (PyCFunction)Sbk_QAbstractItemViewFunc_setSelectionModel, METH_O},
    {"setState", (PyCFunction)Sbk_QAbstractItemViewFunc_setState, METH_O},
    {"setTabKeyNavigation", (PyCFunction)Sbk_QAbstractItemViewFunc_setTabKeyNavigation, METH_O},
    {"setTextElideMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setTextElideMode, METH_O},
    {"setVerticalScrollMode", (PyCFunction)Sbk_QAbstractItemViewFunc_setVerticalScrollMode, METH_O},
    {"showDropIndicator", (PyCFunction)Sbk_QAbstractItemViewFunc_showDropIndicator, METH_NOARGS},
    {"sizeHintForColumn", (PyCFunction)Sbk_QAbstractItemViewFunc_sizeHintForColumn, METH_O},
    {"sizeHintForIndex", (PyCFunction)Sbk_QAbstractItemViewFunc_sizeHintForIndex, METH_O},
    {"sizeHintForRow", (PyCFunction)Sbk_QAbstractItemViewFunc_sizeHintForRow, METH_O},
    {"startAutoScroll", (PyCFunction)Sbk_QAbstractItemViewFunc_startAutoScroll, METH_NOARGS},
    {"startDrag", (PyCFunction)Sbk_QAbstractItemViewFunc_startDrag, METH_O},
    {"state", (PyCFunction)Sbk_QAbstractItemViewFunc_state, METH_NOARGS},
    {"stopAutoScroll", (PyCFunction)Sbk_QAbstractItemViewFunc_stopAutoScroll, METH_NOARGS},
    {"tabKeyNavigation", (PyCFunction)Sbk_QAbstractItemViewFunc_tabKeyNavigation, METH_NOARGS},
    {"textElideMode", (PyCFunction)Sbk_QAbstractItemViewFunc_textElideMode, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_timerEvent, METH_O},
    {"update", (PyCFunction)Sbk_QAbstractItemViewFunc_update, METH_VARARGS},
    {"updateEditorData", (PyCFunction)Sbk_QAbstractItemViewFunc_updateEditorData, METH_NOARGS},
    {"updateEditorGeometries", (PyCFunction)Sbk_QAbstractItemViewFunc_updateEditorGeometries, METH_NOARGS},
    {"updateGeometries", (PyCFunction)Sbk_QAbstractItemViewFunc_updateGeometries, METH_NOARGS},
    {"verticalOffset", (PyCFunction)Sbk_QAbstractItemViewFunc_verticalOffset, METH_NOARGS},
    {"verticalScrollMode", (PyCFunction)Sbk_QAbstractItemViewFunc_verticalScrollMode, METH_NOARGS},
    {"verticalScrollbarAction", (PyCFunction)Sbk_QAbstractItemViewFunc_verticalScrollbarAction, METH_O},
    {"verticalScrollbarValueChanged", (PyCFunction)Sbk_QAbstractItemViewFunc_verticalScrollbarValueChanged, METH_O},
    {"viewOptions", (PyCFunction)Sbk_QAbstractItemViewFunc_viewOptions, METH_NOARGS},
    {"viewportEvent", (PyCFunction)Sbk_QAbstractItemViewFunc_viewportEvent, METH_O},
    {"visualRect", (PyCFunction)Sbk_QAbstractItemViewFunc_visualRect, METH_O},
    {"visualRegionForSelection", (PyCFunction)Sbk_QAbstractItemViewFunc_visualRegionForSelection, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractItemView_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractItemView_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QAbstractItemViewSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QAbstractItemView* me = reinterpret_cast< ::QAbstractItemView*>(obj);
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
static SbkObjectType Sbk_QAbstractItemView_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QAbstractItemView",
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
    /*tp_traverse*/         Sbk_QAbstractItemView_traverse,
    /*tp_clear*/            Sbk_QAbstractItemView_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractItemView_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractItemView_Init,
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

static void* Sbk_QAbstractItemView_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractItemView*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QAbstractItemView*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QAbstractItemView_EditTrigger___and__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView::EditTriggers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractItemView::EditTriggers)PyLong_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractItemView::EditTriggers)PyInt_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractItemView_EditTrigger___or__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView::EditTriggers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractItemView::EditTriggers)PyLong_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractItemView::EditTriggers)PyInt_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractItemView_EditTrigger___xor__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView::EditTriggers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractItemView::EditTriggers)PyLong_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractItemView::EditTriggers)PyInt_AsLong(self);
    cppArg = (QAbstractItemView::EditTriggers)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractItemView_EditTrigger___invert__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractItemView::EditTriggers cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), self, &cppSelf);
    ::QAbstractItemView::EditTriggers cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QAbstractItemView_EditTrigger_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QAbstractItemView_EditTrigger__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QAbstractItemView_EditTrigger_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QAbstractItemView_EditTrigger__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QAbstractItemView_EditTrigger___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QAbstractItemView_EditTrigger___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QAbstractItemView_EditTrigger___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QAbstractItemView_EditTrigger___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QAbstractItemView_EditTrigger_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QAbstractItemView_EditTrigger_long,
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
static void QAbstractItemView_SelectionMode_PythonToCpp_QAbstractItemView_SelectionMode(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::SelectionMode*)cppOut) = (::QAbstractItemView::SelectionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_SelectionMode_PythonToCpp_QAbstractItemView_SelectionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX]))
        return QAbstractItemView_SelectionMode_PythonToCpp_QAbstractItemView_SelectionMode;
    return 0;
}
static PyObject* QAbstractItemView_SelectionMode_CppToPython_QAbstractItemView_SelectionMode(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::SelectionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX], castCppIn);

}

static void QAbstractItemView_SelectionBehavior_PythonToCpp_QAbstractItemView_SelectionBehavior(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::SelectionBehavior*)cppOut) = (::QAbstractItemView::SelectionBehavior) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_SelectionBehavior_PythonToCpp_QAbstractItemView_SelectionBehavior_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX]))
        return QAbstractItemView_SelectionBehavior_PythonToCpp_QAbstractItemView_SelectionBehavior;
    return 0;
}
static PyObject* QAbstractItemView_SelectionBehavior_CppToPython_QAbstractItemView_SelectionBehavior(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::SelectionBehavior*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX], castCppIn);

}

static void QAbstractItemView_ScrollHint_PythonToCpp_QAbstractItemView_ScrollHint(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::ScrollHint*)cppOut) = (::QAbstractItemView::ScrollHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_ScrollHint_PythonToCpp_QAbstractItemView_ScrollHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX]))
        return QAbstractItemView_ScrollHint_PythonToCpp_QAbstractItemView_ScrollHint;
    return 0;
}
static PyObject* QAbstractItemView_ScrollHint_CppToPython_QAbstractItemView_ScrollHint(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::ScrollHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX], castCppIn);

}

static void QAbstractItemView_EditTrigger_PythonToCpp_QAbstractItemView_EditTrigger(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::EditTrigger*)cppOut) = (::QAbstractItemView::EditTrigger) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_EditTrigger_PythonToCpp_QAbstractItemView_EditTrigger_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX]))
        return QAbstractItemView_EditTrigger_PythonToCpp_QAbstractItemView_EditTrigger;
    return 0;
}
static PyObject* QAbstractItemView_EditTrigger_CppToPython_QAbstractItemView_EditTrigger(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::EditTrigger*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX], castCppIn);

}

static void QFlags_QAbstractItemView_EditTrigger__PythonToCpp_QFlags_QAbstractItemView_EditTrigger_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractItemView::EditTrigger>*)cppOut) = ::QFlags<QAbstractItemView::EditTrigger>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QAbstractItemView_EditTrigger__PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]))
        return QFlags_QAbstractItemView_EditTrigger__PythonToCpp_QFlags_QAbstractItemView_EditTrigger_;
    return 0;
}
static PyObject* QFlags_QAbstractItemView_EditTrigger__CppToPython_QFlags_QAbstractItemView_EditTrigger_(const void* cppIn) {
    int castCppIn = *((::QFlags<QAbstractItemView::EditTrigger>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]));

}

static void QAbstractItemView_EditTrigger_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractItemView::EditTrigger>*)cppOut) = ::QFlags<QAbstractItemView::EditTrigger>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QAbstractItemView_EditTrigger_PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX]))
        return QAbstractItemView_EditTrigger_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_;
    return 0;
}
static void number_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QAbstractItemView::EditTrigger>*)cppOut) = ::QFlags<QAbstractItemView::EditTrigger>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_;
    return 0;
}
static void QAbstractItemView_ScrollMode_PythonToCpp_QAbstractItemView_ScrollMode(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::ScrollMode*)cppOut) = (::QAbstractItemView::ScrollMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_ScrollMode_PythonToCpp_QAbstractItemView_ScrollMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX]))
        return QAbstractItemView_ScrollMode_PythonToCpp_QAbstractItemView_ScrollMode;
    return 0;
}
static PyObject* QAbstractItemView_ScrollMode_CppToPython_QAbstractItemView_ScrollMode(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::ScrollMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX], castCppIn);

}

static void QAbstractItemView_DragDropMode_PythonToCpp_QAbstractItemView_DragDropMode(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::DragDropMode*)cppOut) = (::QAbstractItemView::DragDropMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_DragDropMode_PythonToCpp_QAbstractItemView_DragDropMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX]))
        return QAbstractItemView_DragDropMode_PythonToCpp_QAbstractItemView_DragDropMode;
    return 0;
}
static PyObject* QAbstractItemView_DragDropMode_CppToPython_QAbstractItemView_DragDropMode(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::DragDropMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX], castCppIn);

}

static void QAbstractItemView_CursorAction_PythonToCpp_QAbstractItemView_CursorAction(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::CursorAction*)cppOut) = (::QAbstractItemView::CursorAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_CursorAction_PythonToCpp_QAbstractItemView_CursorAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX]))
        return QAbstractItemView_CursorAction_PythonToCpp_QAbstractItemView_CursorAction;
    return 0;
}
static PyObject* QAbstractItemView_CursorAction_CppToPython_QAbstractItemView_CursorAction(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::CursorAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX], castCppIn);

}

static void QAbstractItemView_State_PythonToCpp_QAbstractItemView_State(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::State*)cppOut) = (::QAbstractItemView::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_State_PythonToCpp_QAbstractItemView_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX]))
        return QAbstractItemView_State_PythonToCpp_QAbstractItemView_State;
    return 0;
}
static PyObject* QAbstractItemView_State_CppToPython_QAbstractItemView_State(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX], castCppIn);

}

static void QAbstractItemView_DropIndicatorPosition_PythonToCpp_QAbstractItemView_DropIndicatorPosition(PyObject* pyIn, void* cppOut) {
    *((::QAbstractItemView::DropIndicatorPosition*)cppOut) = (::QAbstractItemView::DropIndicatorPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractItemView_DropIndicatorPosition_PythonToCpp_QAbstractItemView_DropIndicatorPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX]))
        return QAbstractItemView_DropIndicatorPosition_PythonToCpp_QAbstractItemView_DropIndicatorPosition;
    return 0;
}
static PyObject* QAbstractItemView_DropIndicatorPosition_CppToPython_QAbstractItemView_DropIndicatorPosition(const void* cppIn) {
    int castCppIn = *((::QAbstractItemView::DropIndicatorPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractItemView_PythonToCpp_QAbstractItemView_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractItemView_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractItemView_PythonToCpp_QAbstractItemView_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractItemView_Type))
        return QAbstractItemView_PythonToCpp_QAbstractItemView_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractItemView_PTR_CppToPython_QAbstractItemView(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractItemView*)cppIn, &Sbk_QAbstractItemView_Type);

}

void init_QAbstractItemView(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractItemView_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractItemView", "QAbstractItemView*",
        &Sbk_QAbstractItemView_Type, &Shiboken::callCppDestructor< ::QAbstractItemView >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTSCROLLAREA_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractItemView_Type,
        QAbstractItemView_PythonToCpp_QAbstractItemView_PTR,
        is_QAbstractItemView_PythonToCpp_QAbstractItemView_PTR_Convertible,
        QAbstractItemView_PTR_CppToPython_QAbstractItemView);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractItemView).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractItemViewWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QAbstractItemView_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QAbstractItemView_Type, &Sbk_QAbstractItemViewSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractItemView_Type, &Sbk_QAbstractItemView_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'SelectionMode'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "SelectionMode",
        "PySide.QtGui.QAbstractItemView.SelectionMode",
        "QAbstractItemView::SelectionMode");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
        &Sbk_QAbstractItemView_Type, "NoSelection", (long) QAbstractItemView::NoSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
        &Sbk_QAbstractItemView_Type, "SingleSelection", (long) QAbstractItemView::SingleSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
        &Sbk_QAbstractItemView_Type, "MultiSelection", (long) QAbstractItemView::MultiSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
        &Sbk_QAbstractItemView_Type, "ExtendedSelection", (long) QAbstractItemView::ExtendedSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
        &Sbk_QAbstractItemView_Type, "ContiguousSelection", (long) QAbstractItemView::ContiguousSelection))
        return ;
    // Register converter for enum 'QAbstractItemView::SelectionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX],
            QAbstractItemView_SelectionMode_CppToPython_QAbstractItemView_SelectionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_SelectionMode_PythonToCpp_QAbstractItemView_SelectionMode,
            is_QAbstractItemView_SelectionMode_PythonToCpp_QAbstractItemView_SelectionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::SelectionMode");
        Shiboken::Conversions::registerConverterName(converter, "SelectionMode");
    }
    // End of 'SelectionMode' enum.

    // Initialization of enum 'SelectionBehavior'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "SelectionBehavior",
        "PySide.QtGui.QAbstractItemView.SelectionBehavior",
        "QAbstractItemView::SelectionBehavior");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX],
        &Sbk_QAbstractItemView_Type, "SelectItems", (long) QAbstractItemView::SelectItems))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX],
        &Sbk_QAbstractItemView_Type, "SelectRows", (long) QAbstractItemView::SelectRows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX],
        &Sbk_QAbstractItemView_Type, "SelectColumns", (long) QAbstractItemView::SelectColumns))
        return ;
    // Register converter for enum 'QAbstractItemView::SelectionBehavior'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX],
            QAbstractItemView_SelectionBehavior_CppToPython_QAbstractItemView_SelectionBehavior);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_SelectionBehavior_PythonToCpp_QAbstractItemView_SelectionBehavior,
            is_QAbstractItemView_SelectionBehavior_PythonToCpp_QAbstractItemView_SelectionBehavior_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SELECTIONBEHAVIOR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::SelectionBehavior");
        Shiboken::Conversions::registerConverterName(converter, "SelectionBehavior");
    }
    // End of 'SelectionBehavior' enum.

    // Initialization of enum 'ScrollHint'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "ScrollHint",
        "PySide.QtGui.QAbstractItemView.ScrollHint",
        "QAbstractItemView::ScrollHint");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX],
        &Sbk_QAbstractItemView_Type, "EnsureVisible", (long) QAbstractItemView::EnsureVisible))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX],
        &Sbk_QAbstractItemView_Type, "PositionAtTop", (long) QAbstractItemView::PositionAtTop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX],
        &Sbk_QAbstractItemView_Type, "PositionAtBottom", (long) QAbstractItemView::PositionAtBottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX],
        &Sbk_QAbstractItemView_Type, "PositionAtCenter", (long) QAbstractItemView::PositionAtCenter))
        return ;
    // Register converter for enum 'QAbstractItemView::ScrollHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX],
            QAbstractItemView_ScrollHint_CppToPython_QAbstractItemView_ScrollHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_ScrollHint_PythonToCpp_QAbstractItemView_ScrollHint,
            is_QAbstractItemView_ScrollHint_PythonToCpp_QAbstractItemView_ScrollHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::ScrollHint");
        Shiboken::Conversions::registerConverterName(converter, "ScrollHint");
    }
    // End of 'ScrollHint' enum.

    // Initialization of enum 'EditTrigger'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX] = PySide::QFlags::create("EditTriggers", &SbkPySide_QtGui_QAbstractItemView_EditTrigger_as_number);
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "EditTrigger",
        "PySide.QtGui.QAbstractItemView.EditTrigger",
        "QAbstractItemView::EditTrigger",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "NoEditTriggers", (long) QAbstractItemView::NoEditTriggers))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "CurrentChanged", (long) QAbstractItemView::CurrentChanged))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "DoubleClicked", (long) QAbstractItemView::DoubleClicked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "SelectedClicked", (long) QAbstractItemView::SelectedClicked))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "EditKeyPressed", (long) QAbstractItemView::EditKeyPressed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "AnyKeyPressed", (long) QAbstractItemView::AnyKeyPressed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
        &Sbk_QAbstractItemView_Type, "AllEditTriggers", (long) QAbstractItemView::AllEditTriggers))
        return ;
    // Register converter for enum 'QAbstractItemView::EditTrigger'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX],
            QAbstractItemView_EditTrigger_CppToPython_QAbstractItemView_EditTrigger);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_EditTrigger_PythonToCpp_QAbstractItemView_EditTrigger,
            is_QAbstractItemView_EditTrigger_PythonToCpp_QAbstractItemView_EditTrigger_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_EDITTRIGGER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::EditTrigger");
        Shiboken::Conversions::registerConverterName(converter, "EditTrigger");
    }
    // Register converter for flag 'QFlags<QAbstractItemView::EditTrigger>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX],
            QFlags_QAbstractItemView_EditTrigger__CppToPython_QFlags_QAbstractItemView_EditTrigger_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_EditTrigger_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_,
            is_QAbstractItemView_EditTrigger_PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QAbstractItemView_EditTrigger__PythonToCpp_QFlags_QAbstractItemView_EditTrigger_,
            is_QFlags_QAbstractItemView_EditTrigger__PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QAbstractItemView_EditTrigger_,
            is_number_PythonToCpp_QFlags_QAbstractItemView_EditTrigger__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTITEMVIEW_EDITTRIGGER__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QAbstractItemView::EditTrigger>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<EditTrigger>");
    }
    // End of 'EditTrigger' enum/flags.

    // Initialization of enum 'ScrollMode'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "ScrollMode",
        "PySide.QtGui.QAbstractItemView.ScrollMode",
        "QAbstractItemView::ScrollMode");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX],
        &Sbk_QAbstractItemView_Type, "ScrollPerItem", (long) QAbstractItemView::ScrollPerItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX],
        &Sbk_QAbstractItemView_Type, "ScrollPerPixel", (long) QAbstractItemView::ScrollPerPixel))
        return ;
    // Register converter for enum 'QAbstractItemView::ScrollMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX],
            QAbstractItemView_ScrollMode_CppToPython_QAbstractItemView_ScrollMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_ScrollMode_PythonToCpp_QAbstractItemView_ScrollMode,
            is_QAbstractItemView_ScrollMode_PythonToCpp_QAbstractItemView_ScrollMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_SCROLLMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::ScrollMode");
        Shiboken::Conversions::registerConverterName(converter, "ScrollMode");
    }
    // End of 'ScrollMode' enum.

    // Initialization of enum 'DragDropMode'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "DragDropMode",
        "PySide.QtGui.QAbstractItemView.DragDropMode",
        "QAbstractItemView::DragDropMode");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
        &Sbk_QAbstractItemView_Type, "NoDragDrop", (long) QAbstractItemView::NoDragDrop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
        &Sbk_QAbstractItemView_Type, "DragOnly", (long) QAbstractItemView::DragOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
        &Sbk_QAbstractItemView_Type, "DropOnly", (long) QAbstractItemView::DropOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
        &Sbk_QAbstractItemView_Type, "DragDrop", (long) QAbstractItemView::DragDrop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
        &Sbk_QAbstractItemView_Type, "InternalMove", (long) QAbstractItemView::InternalMove))
        return ;
    // Register converter for enum 'QAbstractItemView::DragDropMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX],
            QAbstractItemView_DragDropMode_CppToPython_QAbstractItemView_DragDropMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_DragDropMode_PythonToCpp_QAbstractItemView_DragDropMode,
            is_QAbstractItemView_DragDropMode_PythonToCpp_QAbstractItemView_DragDropMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DRAGDROPMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::DragDropMode");
        Shiboken::Conversions::registerConverterName(converter, "DragDropMode");
    }
    // End of 'DragDropMode' enum.

    // Initialization of enum 'CursorAction'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "CursorAction",
        "PySide.QtGui.QAbstractItemView.CursorAction",
        "QAbstractItemView::CursorAction");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveUp", (long) QAbstractItemView::MoveUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveDown", (long) QAbstractItemView::MoveDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveLeft", (long) QAbstractItemView::MoveLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveRight", (long) QAbstractItemView::MoveRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveHome", (long) QAbstractItemView::MoveHome))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveEnd", (long) QAbstractItemView::MoveEnd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MovePageUp", (long) QAbstractItemView::MovePageUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MovePageDown", (long) QAbstractItemView::MovePageDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MoveNext", (long) QAbstractItemView::MoveNext))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
        &Sbk_QAbstractItemView_Type, "MovePrevious", (long) QAbstractItemView::MovePrevious))
        return ;
    // Register converter for enum 'QAbstractItemView::CursorAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX],
            QAbstractItemView_CursorAction_CppToPython_QAbstractItemView_CursorAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_CursorAction_PythonToCpp_QAbstractItemView_CursorAction,
            is_QAbstractItemView_CursorAction_PythonToCpp_QAbstractItemView_CursorAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_CURSORACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::CursorAction");
        Shiboken::Conversions::registerConverterName(converter, "CursorAction");
    }
    // End of 'CursorAction' enum.

    // Initialization of enum 'State'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "State",
        "PySide.QtGui.QAbstractItemView.State",
        "QAbstractItemView::State");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "NoState", (long) QAbstractItemView::NoState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "DraggingState", (long) QAbstractItemView::DraggingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "DragSelectingState", (long) QAbstractItemView::DragSelectingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "EditingState", (long) QAbstractItemView::EditingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "ExpandingState", (long) QAbstractItemView::ExpandingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "CollapsingState", (long) QAbstractItemView::CollapsingState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
        &Sbk_QAbstractItemView_Type, "AnimatingState", (long) QAbstractItemView::AnimatingState))
        return ;
    // Register converter for enum 'QAbstractItemView::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX],
            QAbstractItemView_State_CppToPython_QAbstractItemView_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_State_PythonToCpp_QAbstractItemView_State,
            is_QAbstractItemView_State_PythonToCpp_QAbstractItemView_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'DropIndicatorPosition'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractItemView_Type,
        "DropIndicatorPosition",
        "PySide.QtGui.QAbstractItemView.DropIndicatorPosition",
        "QAbstractItemView::DropIndicatorPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX],
        &Sbk_QAbstractItemView_Type, "OnItem", (long) QAbstractItemView::OnItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX],
        &Sbk_QAbstractItemView_Type, "AboveItem", (long) QAbstractItemView::AboveItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX],
        &Sbk_QAbstractItemView_Type, "BelowItem", (long) QAbstractItemView::BelowItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX],
        &Sbk_QAbstractItemView_Type, "OnViewport", (long) QAbstractItemView::OnViewport))
        return ;
    // Register converter for enum 'QAbstractItemView::DropIndicatorPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX],
            QAbstractItemView_DropIndicatorPosition_CppToPython_QAbstractItemView_DropIndicatorPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractItemView_DropIndicatorPosition_PythonToCpp_QAbstractItemView_DropIndicatorPosition,
            is_QAbstractItemView_DropIndicatorPosition_PythonToCpp_QAbstractItemView_DropIndicatorPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_DROPINDICATORPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractItemView::DropIndicatorPosition");
        Shiboken::Conversions::registerConverterName(converter, "DropIndicatorPosition");
    }
    // End of 'DropIndicatorPosition' enum.

    PySide::Signal::registerSignals(&Sbk_QAbstractItemView_Type, &::QAbstractItemView::staticMetaObject);

    qRegisterMetaType< ::QAbstractItemView::SelectionMode >("QAbstractItemView::SelectionMode");
    qRegisterMetaType< ::QAbstractItemView::SelectionBehavior >("QAbstractItemView::SelectionBehavior");
    qRegisterMetaType< ::QAbstractItemView::ScrollHint >("QAbstractItemView::ScrollHint");
    qRegisterMetaType< ::QAbstractItemView::EditTrigger >("QAbstractItemView::EditTrigger");
    qRegisterMetaType< ::QAbstractItemView::EditTriggers >("QAbstractItemView::EditTriggers");
    qRegisterMetaType< ::QAbstractItemView::ScrollMode >("QAbstractItemView::ScrollMode");
    qRegisterMetaType< ::QAbstractItemView::DragDropMode >("QAbstractItemView::DragDropMode");
    qRegisterMetaType< ::QAbstractItemView::CursorAction >("QAbstractItemView::CursorAction");
    qRegisterMetaType< ::QAbstractItemView::State >("QAbstractItemView::State");
    qRegisterMetaType< ::QAbstractItemView::DropIndicatorPosition >("QAbstractItemView::DropIndicatorPosition");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractItemView_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractItemView_Type, &::QAbstractItemView::staticMetaObject, sizeof(::QAbstractItemView));
}
