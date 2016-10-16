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

#include "qdialogbuttonbox_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractbutton.h>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdialogbuttonbox.h>
#include <qevent.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qgraphicseffect.h>
#include <qgraphicsproxywidget.h>
#include <qicon.h>
#include <qinputcontext.h>
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
#include <qpushbutton.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QDialogButtonBoxWrapper::QDialogButtonBoxWrapper(QFlags<QDialogButtonBox::StandardButton> buttons, Qt::Orientation orientation, QWidget * parent) : QDialogButtonBox(buttons, orientation, parent) {
    // ... middle
}

QDialogButtonBoxWrapper::QDialogButtonBoxWrapper(QWidget * parent) : QDialogButtonBox(parent) {
    // ... middle
}

QDialogButtonBoxWrapper::QDialogButtonBoxWrapper(Qt::Orientation orientation, QWidget * parent) : QDialogButtonBox(orientation, parent) {
    // ... middle
}

void QDialogButtonBoxWrapper::actionEvent(QActionEvent * event)
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

void QDialogButtonBoxWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialogButtonBox::changeEvent(event);
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

void QDialogButtonBoxWrapper::childEvent(QChildEvent * arg__1)
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

void QDialogButtonBoxWrapper::closeEvent(QCloseEvent * event)
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

void QDialogButtonBoxWrapper::connectNotify(const char * signal)
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

void QDialogButtonBoxWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::contextMenuEvent(event);
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

void QDialogButtonBoxWrapper::customEvent(QEvent * arg__1)
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

int QDialogButtonBoxWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::disconnectNotify(const char * signal)
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

void QDialogButtonBoxWrapper::dragEnterEvent(QDragEnterEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragEnterEvent(event);
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

void QDialogButtonBoxWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragLeaveEvent(event);
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

void QDialogButtonBoxWrapper::dragMoveEvent(QDragMoveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dragMoveEvent(event);
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

void QDialogButtonBoxWrapper::dropEvent(QDropEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::dropEvent(event);
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

void QDialogButtonBoxWrapper::enterEvent(QEvent * event)
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

bool QDialogButtonBoxWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialogButtonBox::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDialogButtonBoxWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDialogButtonBoxWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusInEvent(event);
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

bool QDialogButtonBoxWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusNextPrevChild(next);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::focusOutEvent(event);
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

int QDialogButtonBoxWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::hideEvent(QHideEvent * event)
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

void QDialogButtonBoxWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodEvent(event);
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

QVariant QDialogButtonBoxWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodQuery(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::keyPressEvent(event);
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

void QDialogButtonBoxWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QDialogButtonBoxWrapper::languageChange()
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

void QDialogButtonBoxWrapper::leaveEvent(QEvent * event)
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

int QDialogButtonBoxWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QDialogButtonBoxWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::minimumSizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::mouseDoubleClickEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseDoubleClickEvent(event);
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

void QDialogButtonBoxWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseMoveEvent(event);
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

void QDialogButtonBoxWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mousePressEvent(event);
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

void QDialogButtonBoxWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::mouseReleaseEvent(event);
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

void QDialogButtonBoxWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QDialogButtonBoxWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::paintEvent(event);
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

void QDialogButtonBoxWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::resizeEvent(event);
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

void QDialogButtonBoxWrapper::setVisible(bool visible)
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

void QDialogButtonBoxWrapper::showEvent(QShowEvent * event)
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

QSize QDialogButtonBoxWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDialogButtonBox.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDialogButtonBoxWrapper::tabletEvent(QTabletEvent * event)
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

void QDialogButtonBoxWrapper::timerEvent(QTimerEvent * arg__1)
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

void QDialogButtonBoxWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::wheelEvent(event);
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

const QMetaObject* QDialogButtonBoxWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDialogButtonBox::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDialogButtonBoxWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDialogButtonBox::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDialogButtonBoxWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDialogButtonBoxWrapper* >(this));
        return QDialogButtonBox::qt_metacast(_clname);
}

QDialogButtonBoxWrapper::~QDialogButtonBoxWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDialogButtonBox_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"orientation", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDialogButtonBox >()))
        return -1;

    ::QDialogButtonBoxWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOO:QDialogButtonBox", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton>,Qt::Orientation,QWidget*)
    // 1: QDialogButtonBox(QWidget*)
    // 2: QDialogButtonBox(Qt::Orientation,QWidget*)
    if (numArgs == 0) {
        overloadId = 1; // QDialogButtonBox(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QDialogButtonBox(Qt::Orientation,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 2; // QDialogButtonBox(Qt::Orientation,QWidget*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QDialogButtonBox(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton>,Qt::Orientation,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton>,Qt::Orientation,QWidget*)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton>,Qt::Orientation,QWidget*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBox_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton> buttons, Qt::Orientation orientation, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "orientation");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDialogButtonBox(): got multiple values for keyword argument 'orientation'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[1]))))
                        goto Sbk_QDialogButtonBox_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDialogButtonBox(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                        goto Sbk_QDialogButtonBox_Init_TypeError;
                }
            }
            ::QFlags<QDialogButtonBox::StandardButton> cppArg0 = ((::QFlags<QDialogButtonBox::StandardButton>)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::Orientation cppArg1 = Qt::Horizontal;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QWidget* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDialogButtonBox(QFlags<QDialogButtonBox::StandardButton>,Qt::Orientation,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDialogButtonBoxWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDialogButtonBoxWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
        case 1: // QDialogButtonBox(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDialogButtonBox(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QDialogButtonBox_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDialogButtonBox(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDialogButtonBoxWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDialogButtonBoxWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QDialogButtonBox(Qt::Orientation orientation, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDialogButtonBox(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QDialogButtonBox_Init_TypeError;
                }
            }
            ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDialogButtonBox(Qt::Orientation,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDialogButtonBoxWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDialogButtonBoxWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDialogButtonBox >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDialogButtonBox_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QDialogButtonBox_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDialogButtonBox.StandardButtons, PySide.QtCore.Qt.Orientation = Qt.Horizontal, PySide.QtGui.QWidget = None", "PySide.QtGui.QWidget = None", "PySide.QtCore.Qt.Orientation, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDialogButtonBox", overloads);
        return -1;
}

static PyObject* Sbk_QDialogButtonBoxFunc_addButton(PyObject* self, PyObject* args)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addButton", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addButton(QAbstractButton*,QDialogButtonBox::ButtonRole)
    // 1: addButton(QDialogButtonBox::StandardButton)
    // 2: addButton(QString,QDialogButtonBox::ButtonRole)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX]), (pyArgs[0])))) {
        overloadId = 1; // addButton(QDialogButtonBox::StandardButton)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // addButton(QAbstractButton*,QDialogButtonBox::ButtonRole)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX]), (pyArgs[1])))) {
        overloadId = 2; // addButton(QString,QDialogButtonBox::ButtonRole)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_addButton_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addButton(QAbstractButton * button, QDialogButtonBox::ButtonRole role)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QAbstractButton* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDialogButtonBox::ButtonRole cppArg1 = ((::QDialogButtonBox::ButtonRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addButton(QAbstractButton*,QDialogButtonBox::ButtonRole)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addButton(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // addButton(QDialogButtonBox::StandardButton button)
        {
            ::QDialogButtonBox::StandardButton cppArg0 = ((::QDialogButtonBox::StandardButton)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addButton(QDialogButtonBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPushButton * cppResult = cppSelf->addButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPUSHBUTTON_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 2: // addButton(const QString & text, QDialogButtonBox::ButtonRole role)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QDialogButtonBox::ButtonRole cppArg1 = ((::QDialogButtonBox::ButtonRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addButton(QString,QDialogButtonBox::ButtonRole)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPushButton * cppResult = cppSelf->addButton(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPUSHBUTTON_IDX], cppResult);
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

    Sbk_QDialogButtonBoxFunc_addButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton, PySide.QtGui.QDialogButtonBox.ButtonRole", "PySide.QtGui.QDialogButtonBox.StandardButton", "unicode, PySide.QtGui.QDialogButtonBox.ButtonRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDialogButtonBox.addButton", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_button(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: button(QDialogButtonBox::StandardButton)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // button(QDialogButtonBox::StandardButton)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_button_TypeError;

    // Call function/method
    {
        ::QDialogButtonBox::StandardButton cppArg0 = ((::QDialogButtonBox::StandardButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // button(QDialogButtonBox::StandardButton)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPushButton * cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->button(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPUSHBUTTON_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDialogButtonBoxFunc_button_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDialogButtonBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.button", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_buttonRole(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: buttonRole(QAbstractButton*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArg)))) {
        overloadId = 0; // buttonRole(QAbstractButton*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_buttonRole_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractButton* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // buttonRole(QAbstractButton*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDialogButtonBox::ButtonRole cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->buttonRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDialogButtonBoxFunc_buttonRole_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.buttonRole", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_buttons(PyObject* self)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAbstractButton * > cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->buttons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QABSTRACTBUTTONPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDialogButtonBoxFunc_centerButtons(PyObject* self)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // centerButtons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->centerButtons();
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

static PyObject* Sbk_QDialogButtonBoxFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDialogButtonBox::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDialogButtonBoxFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_clear(PyObject* self)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDialogButtonBoxFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDialogButtonBox::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDialogButtonBoxFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.event", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_orientation(PyObject* self)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // orientation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::Orientation cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->orientation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDialogButtonBoxFunc_removeButton(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeButton(QAbstractButton*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArg)))) {
        overloadId = 0; // removeButton(QAbstractButton*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_removeButton_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractButton* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeButton(QAbstractButton*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeButton(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDialogButtonBoxFunc_removeButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.removeButton", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_setCenterButtons(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCenterButtons(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCenterButtons(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_setCenterButtons_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCenterButtons(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCenterButtons(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDialogButtonBoxFunc_setCenterButtons_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.setCenterButtons", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_setOrientation(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOrientation(Qt::Orientation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // setOrientation(Qt::Orientation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_setOrientation_TypeError;

    // Call function/method
    {
        ::Qt::Orientation cppArg0 = ((::Qt::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOrientation(Qt::Orientation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOrientation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDialogButtonBoxFunc_setOrientation_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.setOrientation", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_setStandardButtons(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStandardButtons(QFlags<QDialogButtonBox::StandardButton>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), (pyArg)))) {
        overloadId = 0; // setStandardButtons(QFlags<QDialogButtonBox::StandardButton>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_setStandardButtons_TypeError;

    // Call function/method
    {
        ::QFlags<QDialogButtonBox::StandardButton> cppArg0 = ((::QFlags<QDialogButtonBox::StandardButton>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStandardButtons(QFlags<QDialogButtonBox::StandardButton>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardButtons(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDialogButtonBoxFunc_setStandardButtons_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDialogButtonBox.StandardButtons", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.setStandardButtons", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_standardButton(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: standardButton(QAbstractButton*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArg)))) {
        overloadId = 0; // standardButton(QAbstractButton*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDialogButtonBoxFunc_standardButton_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractButton* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // standardButton(QAbstractButton*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDialogButtonBox::StandardButton cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->standardButton(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDialogButtonBoxFunc_standardButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDialogButtonBox.standardButton", overloads);
        return 0;
}

static PyObject* Sbk_QDialogButtonBoxFunc_standardButtons(PyObject* self)
{
    ::QDialogButtonBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDialogButtonBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardButtons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDialogButtonBox::StandardButton> cppResult = const_cast<const ::QDialogButtonBox*>(cppSelf)->standardButtons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QDialogButtonBox_methods[] = {
    {"addButton", (PyCFunction)Sbk_QDialogButtonBoxFunc_addButton, METH_VARARGS},
    {"button", (PyCFunction)Sbk_QDialogButtonBoxFunc_button, METH_O},
    {"buttonRole", (PyCFunction)Sbk_QDialogButtonBoxFunc_buttonRole, METH_O},
    {"buttons", (PyCFunction)Sbk_QDialogButtonBoxFunc_buttons, METH_NOARGS},
    {"centerButtons", (PyCFunction)Sbk_QDialogButtonBoxFunc_centerButtons, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QDialogButtonBoxFunc_changeEvent, METH_O},
    {"clear", (PyCFunction)Sbk_QDialogButtonBoxFunc_clear, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QDialogButtonBoxFunc_event, METH_O},
    {"orientation", (PyCFunction)Sbk_QDialogButtonBoxFunc_orientation, METH_NOARGS},
    {"removeButton", (PyCFunction)Sbk_QDialogButtonBoxFunc_removeButton, METH_O},
    {"setCenterButtons", (PyCFunction)Sbk_QDialogButtonBoxFunc_setCenterButtons, METH_O},
    {"setOrientation", (PyCFunction)Sbk_QDialogButtonBoxFunc_setOrientation, METH_O},
    {"setStandardButtons", (PyCFunction)Sbk_QDialogButtonBoxFunc_setStandardButtons, METH_O},
    {"standardButton", (PyCFunction)Sbk_QDialogButtonBoxFunc_standardButton, METH_O},
    {"standardButtons", (PyCFunction)Sbk_QDialogButtonBoxFunc_standardButtons, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDialogButtonBox_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDialogButtonBox_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QDialogButtonBoxSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QDialogButtonBox* me = reinterpret_cast< ::QDialogButtonBox*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
        return static_cast< ::QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast< ::QPaintDevice*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDialogButtonBox_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDialogButtonBox",
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
    /*tp_traverse*/         Sbk_QDialogButtonBox_traverse,
    /*tp_clear*/            Sbk_QDialogButtonBox_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDialogButtonBox_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDialogButtonBox_Init,
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

static void* Sbk_QDialogButtonBox_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDialogButtonBox*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QDialogButtonBox*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QDialogButtonBox_StandardButton___and__(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDialogButtonBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDialogButtonBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDialogButtonBox_StandardButton___or__(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDialogButtonBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDialogButtonBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDialogButtonBox_StandardButton___xor__(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDialogButtonBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDialogButtonBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QDialogButtonBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDialogButtonBox_StandardButton___invert__(PyObject* self, PyObject* pyArg)
{
    ::QDialogButtonBox::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), self, &cppSelf);
    ::QDialogButtonBox::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QDialogButtonBox_StandardButton_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QDialogButtonBox_StandardButton__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QDialogButtonBox_StandardButton_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QDialogButtonBox_StandardButton__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QDialogButtonBox_StandardButton___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QDialogButtonBox_StandardButton___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QDialogButtonBox_StandardButton___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QDialogButtonBox_StandardButton___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QDialogButtonBox_StandardButton_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QDialogButtonBox_StandardButton_long,
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
static void QDialogButtonBox_ButtonRole_PythonToCpp_QDialogButtonBox_ButtonRole(PyObject* pyIn, void* cppOut) {
    *((::QDialogButtonBox::ButtonRole*)cppOut) = (::QDialogButtonBox::ButtonRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDialogButtonBox_ButtonRole_PythonToCpp_QDialogButtonBox_ButtonRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX]))
        return QDialogButtonBox_ButtonRole_PythonToCpp_QDialogButtonBox_ButtonRole;
    return 0;
}
static PyObject* QDialogButtonBox_ButtonRole_CppToPython_QDialogButtonBox_ButtonRole(const void* cppIn) {
    int castCppIn = *((::QDialogButtonBox::ButtonRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX], castCppIn);

}

static void QDialogButtonBox_StandardButton_PythonToCpp_QDialogButtonBox_StandardButton(PyObject* pyIn, void* cppOut) {
    *((::QDialogButtonBox::StandardButton*)cppOut) = (::QDialogButtonBox::StandardButton) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDialogButtonBox_StandardButton_PythonToCpp_QDialogButtonBox_StandardButton_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX]))
        return QDialogButtonBox_StandardButton_PythonToCpp_QDialogButtonBox_StandardButton;
    return 0;
}
static PyObject* QDialogButtonBox_StandardButton_CppToPython_QDialogButtonBox_StandardButton(const void* cppIn) {
    int castCppIn = *((::QDialogButtonBox::StandardButton*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX], castCppIn);

}

static void QFlags_QDialogButtonBox_StandardButton__PythonToCpp_QFlags_QDialogButtonBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDialogButtonBox::StandardButton>*)cppOut) = ::QFlags<QDialogButtonBox::StandardButton>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QDialogButtonBox_StandardButton__PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]))
        return QFlags_QDialogButtonBox_StandardButton__PythonToCpp_QFlags_QDialogButtonBox_StandardButton_;
    return 0;
}
static PyObject* QFlags_QDialogButtonBox_StandardButton__CppToPython_QFlags_QDialogButtonBox_StandardButton_(const void* cppIn) {
    int castCppIn = *((::QFlags<QDialogButtonBox::StandardButton>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]));

}

static void QDialogButtonBox_StandardButton_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDialogButtonBox::StandardButton>*)cppOut) = ::QFlags<QDialogButtonBox::StandardButton>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QDialogButtonBox_StandardButton_PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX]))
        return QDialogButtonBox_StandardButton_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_;
    return 0;
}
static void number_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QDialogButtonBox::StandardButton>*)cppOut) = ::QFlags<QDialogButtonBox::StandardButton>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_;
    return 0;
}
static void QDialogButtonBox_ButtonLayout_PythonToCpp_QDialogButtonBox_ButtonLayout(PyObject* pyIn, void* cppOut) {
    *((::QDialogButtonBox::ButtonLayout*)cppOut) = (::QDialogButtonBox::ButtonLayout) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDialogButtonBox_ButtonLayout_PythonToCpp_QDialogButtonBox_ButtonLayout_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX]))
        return QDialogButtonBox_ButtonLayout_PythonToCpp_QDialogButtonBox_ButtonLayout;
    return 0;
}
static PyObject* QDialogButtonBox_ButtonLayout_CppToPython_QDialogButtonBox_ButtonLayout(const void* cppIn) {
    int castCppIn = *((::QDialogButtonBox::ButtonLayout*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDialogButtonBox_PythonToCpp_QDialogButtonBox_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDialogButtonBox_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDialogButtonBox_PythonToCpp_QDialogButtonBox_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDialogButtonBox_Type))
        return QDialogButtonBox_PythonToCpp_QDialogButtonBox_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDialogButtonBox_PTR_CppToPython_QDialogButtonBox(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDialogButtonBox*)cppIn, &Sbk_QDialogButtonBox_Type);

}

void init_QDialogButtonBox(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDialogButtonBox_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDialogButtonBox", "QDialogButtonBox*",
        &Sbk_QDialogButtonBox_Type, &Shiboken::callCppDestructor< ::QDialogButtonBox >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDialogButtonBox_Type,
        QDialogButtonBox_PythonToCpp_QDialogButtonBox_PTR,
        is_QDialogButtonBox_PythonToCpp_QDialogButtonBox_PTR_Convertible,
        QDialogButtonBox_PTR_CppToPython_QDialogButtonBox);

    Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox");
    Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox*");
    Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDialogButtonBox).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDialogButtonBoxWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QDialogButtonBox_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QDialogButtonBox_Type, &Sbk_QDialogButtonBoxSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDialogButtonBox_Type, &Sbk_QDialogButtonBox_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ButtonRole'.
    SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDialogButtonBox_Type,
        "ButtonRole",
        "PySide.QtGui.QDialogButtonBox.ButtonRole",
        "QDialogButtonBox::ButtonRole");
    if (!SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "InvalidRole", (long) QDialogButtonBox::InvalidRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "AcceptRole", (long) QDialogButtonBox::AcceptRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "RejectRole", (long) QDialogButtonBox::RejectRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "DestructiveRole", (long) QDialogButtonBox::DestructiveRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "ActionRole", (long) QDialogButtonBox::ActionRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "HelpRole", (long) QDialogButtonBox::HelpRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "YesRole", (long) QDialogButtonBox::YesRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "NoRole", (long) QDialogButtonBox::NoRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "ResetRole", (long) QDialogButtonBox::ResetRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "ApplyRole", (long) QDialogButtonBox::ApplyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
        &Sbk_QDialogButtonBox_Type, "NRoles", (long) QDialogButtonBox::NRoles))
        return ;
    // Register converter for enum 'QDialogButtonBox::ButtonRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX],
            QDialogButtonBox_ButtonRole_CppToPython_QDialogButtonBox_ButtonRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDialogButtonBox_ButtonRole_PythonToCpp_QDialogButtonBox_ButtonRole,
            is_QDialogButtonBox_ButtonRole_PythonToCpp_QDialogButtonBox_ButtonRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox::ButtonRole");
        Shiboken::Conversions::registerConverterName(converter, "ButtonRole");
    }
    // End of 'ButtonRole' enum.

    // Initialization of enum 'StandardButton'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX] = PySide::QFlags::create("StandardButtons", &SbkPySide_QtGui_QDialogButtonBox_StandardButton_as_number);
    SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDialogButtonBox_Type,
        "StandardButton",
        "PySide.QtGui.QDialogButtonBox.StandardButton",
        "QDialogButtonBox::StandardButton",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "NoButton", (long) QDialogButtonBox::NoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Ok", (long) QDialogButtonBox::Ok))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Save", (long) QDialogButtonBox::Save))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "SaveAll", (long) QDialogButtonBox::SaveAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Open", (long) QDialogButtonBox::Open))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Yes", (long) QDialogButtonBox::Yes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "YesToAll", (long) QDialogButtonBox::YesToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "No", (long) QDialogButtonBox::No))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "NoToAll", (long) QDialogButtonBox::NoToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Abort", (long) QDialogButtonBox::Abort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Retry", (long) QDialogButtonBox::Retry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Ignore", (long) QDialogButtonBox::Ignore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Close", (long) QDialogButtonBox::Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Cancel", (long) QDialogButtonBox::Cancel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Discard", (long) QDialogButtonBox::Discard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Help", (long) QDialogButtonBox::Help))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Apply", (long) QDialogButtonBox::Apply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "Reset", (long) QDialogButtonBox::Reset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "RestoreDefaults", (long) QDialogButtonBox::RestoreDefaults))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "FirstButton", (long) QDialogButtonBox::FirstButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
        &Sbk_QDialogButtonBox_Type, "LastButton", (long) QDialogButtonBox::LastButton))
        return ;
    // Register converter for enum 'QDialogButtonBox::StandardButton'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX],
            QDialogButtonBox_StandardButton_CppToPython_QDialogButtonBox_StandardButton);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDialogButtonBox_StandardButton_PythonToCpp_QDialogButtonBox_StandardButton,
            is_QDialogButtonBox_StandardButton_PythonToCpp_QDialogButtonBox_StandardButton_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_STANDARDBUTTON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox::StandardButton");
        Shiboken::Conversions::registerConverterName(converter, "StandardButton");
    }
    // Register converter for flag 'QFlags<QDialogButtonBox::StandardButton>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX],
            QFlags_QDialogButtonBox_StandardButton__CppToPython_QFlags_QDialogButtonBox_StandardButton_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDialogButtonBox_StandardButton_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_,
            is_QDialogButtonBox_StandardButton_PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QDialogButtonBox_StandardButton__PythonToCpp_QFlags_QDialogButtonBox_StandardButton_,
            is_QFlags_QDialogButtonBox_StandardButton__PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QDialogButtonBox_StandardButton_,
            is_number_PythonToCpp_QFlags_QDialogButtonBox_StandardButton__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDIALOGBUTTONBOX_STANDARDBUTTON__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QDialogButtonBox::StandardButton>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StandardButton>");
    }
    // End of 'StandardButton' enum/flags.

    // Initialization of enum 'ButtonLayout'.
    SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDialogButtonBox_Type,
        "ButtonLayout",
        "PySide.QtGui.QDialogButtonBox.ButtonLayout",
        "QDialogButtonBox::ButtonLayout");
    if (!SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX],
        &Sbk_QDialogButtonBox_Type, "WinLayout", (long) QDialogButtonBox::WinLayout))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX],
        &Sbk_QDialogButtonBox_Type, "MacLayout", (long) QDialogButtonBox::MacLayout))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX],
        &Sbk_QDialogButtonBox_Type, "KdeLayout", (long) QDialogButtonBox::KdeLayout))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX],
        &Sbk_QDialogButtonBox_Type, "GnomeLayout", (long) QDialogButtonBox::GnomeLayout))
        return ;
    // Register converter for enum 'QDialogButtonBox::ButtonLayout'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX],
            QDialogButtonBox_ButtonLayout_CppToPython_QDialogButtonBox_ButtonLayout);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDialogButtonBox_ButtonLayout_PythonToCpp_QDialogButtonBox_ButtonLayout,
            is_QDialogButtonBox_ButtonLayout_PythonToCpp_QDialogButtonBox_ButtonLayout_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDIALOGBUTTONBOX_BUTTONLAYOUT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDialogButtonBox::ButtonLayout");
        Shiboken::Conversions::registerConverterName(converter, "ButtonLayout");
    }
    // End of 'ButtonLayout' enum.

    PySide::Signal::registerSignals(&Sbk_QDialogButtonBox_Type, &::QDialogButtonBox::staticMetaObject);

    qRegisterMetaType< ::QDialogButtonBox::ButtonRole >("QDialogButtonBox::ButtonRole");
    qRegisterMetaType< ::QDialogButtonBox::StandardButton >("QDialogButtonBox::StandardButton");
    qRegisterMetaType< ::QDialogButtonBox::StandardButtons >("QDialogButtonBox::StandardButtons");
    qRegisterMetaType< ::QDialogButtonBox::ButtonLayout >("QDialogButtonBox::ButtonLayout");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDialogButtonBox_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDialogButtonBox_Type, &::QDialogButtonBox::staticMetaObject, sizeof(::QDialogButtonBox));
}
