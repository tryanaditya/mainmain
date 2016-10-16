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

#include "qmainwindow_wrapper.h"

// Extra includes
#include <QList>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdockwidget.h>
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
#include <qmainwindow.h>
#include <qmargins.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstatusbar.h>
#include <qstyle.h>
#include <qtoolbar.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QMainWindowWrapper::QMainWindowWrapper(QWidget * parent, QFlags<Qt::WindowType> flags) : QMainWindow(parent, flags) {
    // ... middle
}

void QMainWindowWrapper::actionEvent(QActionEvent * event)
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

void QMainWindowWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::changeEvent(event);
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

void QMainWindowWrapper::childEvent(QChildEvent * arg__1)
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

void QMainWindowWrapper::closeEvent(QCloseEvent * event)
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

void QMainWindowWrapper::connectNotify(const char * signal)
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

void QMainWindowWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::contextMenuEvent(event);
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

QMenu * QMainWindowWrapper::createPopupMenu()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMenu*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createPopupMenu"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::createPopupMenu();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QMenu*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.createPopupMenu", Shiboken::SbkType< QMenu >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMenu*)0);
    }
    ::QMenu* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::customEvent(QEvent * arg__1)
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

int QMainWindowWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::disconnectNotify(const char * signal)
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

void QMainWindowWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void QMainWindowWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void QMainWindowWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void QMainWindowWrapper::dropEvent(QDropEvent * event)
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

void QMainWindowWrapper::enterEvent(QEvent * event)
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

bool QMainWindowWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMainWindow::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QMainWindowWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QMainWindowWrapper::focusInEvent(QFocusEvent * event)
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

bool QMainWindowWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::focusOutEvent(QFocusEvent * event)
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

int QMainWindowWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::hideEvent(QHideEvent * event)
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

void QMainWindowWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant QMainWindowWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::keyPressEvent(QKeyEvent * event)
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

void QMainWindowWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QMainWindowWrapper::languageChange()
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

void QMainWindowWrapper::leaveEvent(QEvent * event)
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

int QMainWindowWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QMainWindowWrapper::minimumSizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void QMainWindowWrapper::mouseMoveEvent(QMouseEvent * event)
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

void QMainWindowWrapper::mousePressEvent(QMouseEvent * event)
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

void QMainWindowWrapper::mouseReleaseEvent(QMouseEvent * event)
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

void QMainWindowWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QMainWindowWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::paintEvent(QPaintEvent * event)
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

void QMainWindowWrapper::resizeEvent(QResizeEvent * event)
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

void QMainWindowWrapper::setVisible(bool visible)
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

void QMainWindowWrapper::showEvent(QShowEvent * event)
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

QSize QMainWindowWrapper::sizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMainWindow.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMainWindowWrapper::tabletEvent(QTabletEvent * event)
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

void QMainWindowWrapper::timerEvent(QTimerEvent * arg__1)
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

void QMainWindowWrapper::wheelEvent(QWheelEvent * event)
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

const QMetaObject* QMainWindowWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QMainWindow::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QMainWindowWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QMainWindow::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QMainWindowWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QMainWindowWrapper* >(this));
        return QMainWindow::qt_metacast(_clname);
}

QMainWindowWrapper::~QMainWindowWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMainWindow_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"flags", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMainWindow >()))
        return -1;

    ::QMainWindowWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QMainWindow", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QMainWindow(QWidget*,QFlags<Qt::WindowType>)
    if (numArgs == 0) {
        overloadId = 0; // QMainWindow(QWidget*,QFlags<Qt::WindowType>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QMainWindow(QWidget*,QFlags<Qt::WindowType>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[1])))) {
            overloadId = 0; // QMainWindow(QWidget*,QFlags<Qt::WindowType>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindow_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QMainWindow_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow(): got multiple values for keyword argument 'flags'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[1]))))
                    goto Sbk_QMainWindow_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::WindowType> cppArg1 = QFlags<Qt::WindowType>(0);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QMainWindow(QWidget*,QFlags<Qt::WindowType>)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QMainWindowWrapper(cppArg0, cppArg1);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QMainWindowWrapper(cppArg0, cppArg1);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMainWindow >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMainWindow_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QMainWindow_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, PySide.QtCore.Qt.WindowFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow", overloads);
        return -1;
}

static PyObject* Sbk_QMainWindowFunc_addDockWidget(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addDockWidget", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addDockWidget(Qt::DockWidgetArea,QDockWidget*)
    // 1: addDockWidget(Qt::DockWidgetArea,QDockWidget*,Qt::Orientation)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addDockWidget(Qt::DockWidgetArea,QDockWidget*)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[2])))) {
            overloadId = 1; // addDockWidget(Qt::DockWidgetArea,QDockWidget*,Qt::Orientation)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_addDockWidget_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addDockWidget(Qt::DockWidgetArea area, QDockWidget * dockwidget)
        {
            ::Qt::DockWidgetArea cppArg0 = ((::Qt::DockWidgetArea)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QDockWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addDockWidget(Qt::DockWidgetArea,QDockWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addDockWidget(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 1: // addDockWidget(Qt::DockWidgetArea area, QDockWidget * dockwidget, Qt::Orientation orientation)
        {
            ::Qt::DockWidgetArea cppArg0 = ((::Qt::DockWidgetArea)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QDockWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::Orientation cppArg2 = ((::Qt::Orientation)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // addDockWidget(Qt::DockWidgetArea,QDockWidget*,Qt::Orientation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addDockWidget(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_addDockWidget_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DockWidgetArea, PySide.QtGui.QDockWidget", "PySide.QtCore.Qt.DockWidgetArea, PySide.QtGui.QDockWidget, PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.addDockWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_addToolBar(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addToolBar", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addToolBar(QToolBar*)
    // 1: addToolBar(Qt::ToolBarArea,QToolBar*)
    // 2: addToolBar(QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArgs[1])))) {
        overloadId = 1; // addToolBar(Qt::ToolBarArea,QToolBar*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArgs[0])))) {
        overloadId = 0; // addToolBar(QToolBar*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 2; // addToolBar(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_addToolBar_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addToolBar(QToolBar * toolbar)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QToolBar* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addToolBar(QToolBar*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addToolBar(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // addToolBar(Qt::ToolBarArea area, QToolBar * toolbar)
        {
            ::Qt::ToolBarArea cppArg0 = ((::Qt::ToolBarArea)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QToolBar* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addToolBar(Qt::ToolBarArea,QToolBar*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addToolBar(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 2: // addToolBar(const QString & title)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addToolBar(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QToolBar * cppResult = cppSelf->addToolBar(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], cppResult);
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

    Sbk_QMainWindowFunc_addToolBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", "PySide.QtCore.Qt.ToolBarArea, PySide.QtGui.QToolBar", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.addToolBar", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_addToolBarBreak(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.addToolBarBreak(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:addToolBarBreak", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: addToolBarBreak(Qt::ToolBarArea)
    if (numArgs == 0) {
        overloadId = 0; // addToolBarBreak(Qt::ToolBarArea)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), (pyArgs[0])))) {
        overloadId = 0; // addToolBarBreak(Qt::ToolBarArea)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_addToolBarBreak_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "area");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.addToolBarBreak(): got multiple values for keyword argument 'area'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), (pyArgs[0]))))
                    goto Sbk_QMainWindowFunc_addToolBarBreak_TypeError;
            }
        }
        ::Qt::ToolBarArea cppArg0 = Qt::TopToolBarArea;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // addToolBarBreak(Qt::ToolBarArea)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addToolBarBreak(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_addToolBarBreak_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ToolBarArea = Qt.TopToolBarArea", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.addToolBarBreak", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_centralWidget(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // centralWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QMainWindow*>(cppSelf)->centralWidget();
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
}

static PyObject* Sbk_QMainWindowFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMainWindow::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_corner(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: corner(Qt::Corner)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), (pyArg)))) {
        overloadId = 0; // corner(Qt::Corner)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_corner_TypeError;

    // Call function/method
    {
        ::Qt::Corner cppArg0 = ((::Qt::Corner)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // corner(Qt::Corner)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DockWidgetArea cppResult = const_cast<const ::QMainWindow*>(cppSelf)->corner(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_corner_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Corner", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.corner", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_createPopupMenu(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createPopupMenu()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMainWindow::createPopupMenu() : cppSelf->createPopupMenu();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_dockOptions(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dockOptions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QMainWindow::DockOption> cppResult = const_cast<const ::QMainWindow*>(cppSelf)->dockOptions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_dockWidgetArea(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dockWidgetArea(QDockWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // dockWidgetArea(QDockWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_dockWidgetArea_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dockWidgetArea(QDockWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::DockWidgetArea cppResult = const_cast<const ::QMainWindow*>(cppSelf)->dockWidgetArea(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_dockWidgetArea_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.dockWidgetArea", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_documentMode(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->documentMode();
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

static PyObject* Sbk_QMainWindowFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMainWindowFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMainWindow::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.event", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_iconSize(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QMainWindow*>(cppSelf)->iconSize();
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

static PyObject* Sbk_QMainWindowFunc_insertToolBar(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertToolBar", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertToolBar(QToolBar*,QToolBar*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertToolBar(QToolBar*,QToolBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_insertToolBar_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QToolBar* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertToolBar(QToolBar*,QToolBar*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertToolBar(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_insertToolBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar, PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.insertToolBar", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_insertToolBarBreak(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertToolBarBreak(QToolBar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArg)))) {
        overloadId = 0; // insertToolBarBreak(QToolBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_insertToolBarBreak_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // insertToolBarBreak(QToolBar*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertToolBarBreak(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_insertToolBarBreak_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.insertToolBarBreak", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_isAnimated(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAnimated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->isAnimated();
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

static PyObject* Sbk_QMainWindowFunc_isDockNestingEnabled(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDockNestingEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->isDockNestingEnabled();
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

static PyObject* Sbk_QMainWindowFunc_isSeparator(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSeparator(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // isSeparator(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_isSeparator_TypeError;

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
            // isSeparator(QPoint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->isSeparator(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_isSeparator_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.isSeparator", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_menuBar(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // menuBar()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenuBar * cppResult = const_cast<const ::QMainWindow*>(cppSelf)->menuBar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENUBAR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_menuWidget(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // menuWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QMainWindow*>(cppSelf)->menuWidget();
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
}

static PyObject* Sbk_QMainWindowFunc_removeDockWidget(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeDockWidget(QDockWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // removeDockWidget(QDockWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_removeDockWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeDockWidget(QDockWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeDockWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_removeDockWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.removeDockWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_removeToolBar(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeToolBar(QToolBar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArg)))) {
        overloadId = 0; // removeToolBar(QToolBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_removeToolBar_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeToolBar(QToolBar*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeToolBar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_removeToolBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.removeToolBar", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_removeToolBarBreak(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeToolBarBreak(QToolBar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArg)))) {
        overloadId = 0; // removeToolBarBreak(QToolBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_removeToolBarBreak_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeToolBarBreak(QToolBar*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeToolBarBreak(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_removeToolBarBreak_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.removeToolBarBreak", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_restoreDockWidget(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: restoreDockWidget(QDockWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // restoreDockWidget(QDockWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_restoreDockWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // restoreDockWidget(QDockWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->restoreDockWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_restoreDockWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.restoreDockWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_restoreState(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.restoreState(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.restoreState(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:restoreState", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: restoreState(QByteArray,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // restoreState(QByteArray,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // restoreState(QByteArray,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_restoreState_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "version");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.restoreState(): got multiple values for keyword argument 'version'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QMainWindowFunc_restoreState_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // restoreState(QByteArray,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->restoreState(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_restoreState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.restoreState", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_saveState(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.saveState(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:saveState", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: saveState(int)const
    if (numArgs == 0) {
        overloadId = 0; // saveState(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // saveState(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_saveState_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "version");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMainWindow.saveState(): got multiple values for keyword argument 'version'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QMainWindowFunc_saveState_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // saveState(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QMainWindow*>(cppSelf)->saveState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_saveState_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.saveState", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setAnimated(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAnimated(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAnimated(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setAnimated_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnimated(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAnimated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setAnimated_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setAnimated", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setCentralWidget(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCentralWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setCentralWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setCentralWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCentralWidget(QWidget*)
            // Begin code injection

            // TEMPLATE - replace_child - START
            QWidget* oldChild = cppSelf->centralWidget();
            if (oldChild && (oldChild != cppArg0)) {
               Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], oldChild));
               Shiboken::Object::setParent(0, pyChild);
               Shiboken::Object::releaseOwnership(pyChild);
            }
            Shiboken::Object::setParent(self, pyArg);
            // TEMPLATE - replace_child - END

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCentralWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setCentralWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setCentralWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setCorner(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCorner", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCorner(Qt::Corner,Qt::DockWidgetArea)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setCorner(Qt::Corner,Qt::DockWidgetArea)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setCorner_TypeError;

    // Call function/method
    {
        ::Qt::Corner cppArg0 = ((::Qt::Corner)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::DockWidgetArea cppArg1 = ((::Qt::DockWidgetArea)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setCorner(Qt::Corner,Qt::DockWidgetArea)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCorner(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setCorner_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Corner, PySide.QtCore.Qt.DockWidgetArea", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.setCorner", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setDockNestingEnabled(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDockNestingEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDockNestingEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setDockNestingEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDockNestingEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDockNestingEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setDockNestingEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setDockNestingEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setDockOptions(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDockOptions(QFlags<QMainWindow::DockOption>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), (pyArg)))) {
        overloadId = 0; // setDockOptions(QFlags<QMainWindow::DockOption>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setDockOptions_TypeError;

    // Call function/method
    {
        ::QFlags<QMainWindow::DockOption> cppArg0 = ((::QFlags<QMainWindow::DockOption>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDockOptions(QFlags<QMainWindow::DockOption>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDockOptions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setDockOptions_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMainWindow.DockOptions", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setDockOptions", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setDocumentMode(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocumentMode(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDocumentMode(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setDocumentMode_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocumentMode(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocumentMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setDocumentMode_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setDocumentMode", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setIconSize(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconSize(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setIconSize(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setIconSize_TypeError;

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

    Sbk_QMainWindowFunc_setIconSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setIconSize", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setMenuBar(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMenuBar(QMenuBar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENUBAR_IDX], (pyArg)))) {
        overloadId = 0; // setMenuBar(QMenuBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setMenuBar_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMenuBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMenuBar(QMenuBar*)
            // Begin code injection

            // TEMPLATE - replace_child - START
            QMenuBar* oldChild = cppSelf->menuBar();
            if (oldChild && (oldChild != cppArg0)) {
               Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENUBAR_IDX], oldChild));
               Shiboken::Object::setParent(0, pyChild);
               Shiboken::Object::releaseOwnership(pyChild);
            }
            Shiboken::Object::setParent(self, pyArg);
            // TEMPLATE - replace_child - END

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMenuBar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setMenuBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMenuBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setMenuBar", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setMenuWidget(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMenuWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setMenuWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setMenuWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMenuWidget(QWidget*)
            // Begin code injection

            // TEMPLATE - replace_child - START
            QWidget* oldChild = cppSelf->menuWidget();
            if (oldChild && (oldChild != cppArg0)) {
               Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], oldChild));
               Shiboken::Object::setParent(0, pyChild);
               Shiboken::Object::releaseOwnership(pyChild);
            }
            Shiboken::Object::setParent(self, pyArg);
            // TEMPLATE - replace_child - END

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMenuWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setMenuWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setMenuWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setStatusBar(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatusBar(QStatusBar*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTATUSBAR_IDX], (pyArg)))) {
        overloadId = 0; // setStatusBar(QStatusBar*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setStatusBar_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStatusBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatusBar(QStatusBar*)
            // Begin code injection

            // TEMPLATE - replace_child - START
            QStatusBar* oldChild = cppSelf->statusBar();
            if (oldChild && (oldChild != cppArg0)) {
               Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTATUSBAR_IDX], oldChild));
               Shiboken::Object::setParent(0, pyChild);
               Shiboken::Object::releaseOwnership(pyChild);
            }
            Shiboken::Object::setParent(self, pyArg);
            // TEMPLATE - replace_child - END

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatusBar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setStatusBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStatusBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setStatusBar", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setTabPosition(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setTabPosition", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTabPosition(QFlags<Qt::DockWidgetArea>,QTabWidget::TabPosition)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_DOCKWIDGETAREA__IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABWIDGET_TABPOSITION_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setTabPosition(QFlags<Qt::DockWidgetArea>,QTabWidget::TabPosition)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setTabPosition_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::DockWidgetArea> cppArg0 = ((::QFlags<Qt::DockWidgetArea>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTabWidget::TabPosition cppArg1 = ((::QTabWidget::TabPosition)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setTabPosition(QFlags<Qt::DockWidgetArea>,QTabWidget::TabPosition)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabPosition(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setTabPosition_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DockWidgetAreas, PySide.QtGui.QTabWidget.TabPosition", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.setTabPosition", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setTabShape(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabShape(QTabWidget::TabShape)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABWIDGET_TABSHAPE_IDX]), (pyArg)))) {
        overloadId = 0; // setTabShape(QTabWidget::TabShape)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setTabShape_TypeError;

    // Call function/method
    {
        ::QTabWidget::TabShape cppArg0 = ((::QTabWidget::TabShape)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabShape(QTabWidget::TabShape)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabShape(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setTabShape_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTabWidget.TabShape", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setTabShape", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setToolButtonStyle(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolButtonStyle(Qt::ToolButtonStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setToolButtonStyle(Qt::ToolButtonStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setToolButtonStyle_TypeError;

    // Call function/method
    {
        ::Qt::ToolButtonStyle cppArg0 = ((::Qt::ToolButtonStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setToolButtonStyle(Qt::ToolButtonStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToolButtonStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setToolButtonStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ToolButtonStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setToolButtonStyle", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_setUnifiedTitleAndToolBarOnMac(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUnifiedTitleAndToolBarOnMac(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUnifiedTitleAndToolBarOnMac(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_setUnifiedTitleAndToolBarOnMac_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUnifiedTitleAndToolBarOnMac(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUnifiedTitleAndToolBarOnMac(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_setUnifiedTitleAndToolBarOnMac_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.setUnifiedTitleAndToolBarOnMac", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_splitDockWidget(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "splitDockWidget", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: splitDockWidget(QDockWidget*,QDockWidget*,Qt::Orientation)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[2])))) {
        overloadId = 0; // splitDockWidget(QDockWidget*,QDockWidget*,Qt::Orientation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_splitDockWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDockWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::Orientation cppArg2 = ((::Qt::Orientation)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // splitDockWidget(QDockWidget*,QDockWidget*,Qt::Orientation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->splitDockWidget(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_splitDockWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget, PySide.QtGui.QDockWidget, PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.splitDockWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_statusBar(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // statusBar()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStatusBar * cppResult = const_cast<const ::QMainWindow*>(cppSelf)->statusBar();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTATUSBAR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_tabPosition(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: tabPosition(Qt::DockWidgetArea)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_DOCKWIDGETAREA_IDX]), (pyArg)))) {
        overloadId = 0; // tabPosition(Qt::DockWidgetArea)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_tabPosition_TypeError;

    // Call function/method
    {
        ::Qt::DockWidgetArea cppArg0 = ((::Qt::DockWidgetArea)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // tabPosition(Qt::DockWidgetArea)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTabWidget::TabPosition cppResult = const_cast<const ::QMainWindow*>(cppSelf)->tabPosition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABWIDGET_TABPOSITION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_tabPosition_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.DockWidgetArea", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.tabPosition", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_tabShape(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabShape()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTabWidget::TabShape cppResult = const_cast<const ::QMainWindow*>(cppSelf)->tabShape();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTABWIDGET_TABSHAPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_tabifiedDockWidgets(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: tabifiedDockWidgets(QDockWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // tabifiedDockWidgets(QDockWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_tabifiedDockWidgets_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // tabifiedDockWidgets(QDockWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QDockWidget * > cppResult = const_cast<const ::QMainWindow*>(cppSelf)->tabifiedDockWidgets(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QDOCKWIDGETPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_tabifiedDockWidgets_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.tabifiedDockWidgets", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_tabifyDockWidget(PyObject* self, PyObject* args)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "tabifyDockWidget", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: tabifyDockWidget(QDockWidget*,QDockWidget*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDOCKWIDGET_IDX], (pyArgs[1])))) {
        overloadId = 0; // tabifyDockWidget(QDockWidget*,QDockWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_tabifyDockWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDockWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDockWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // tabifyDockWidget(QDockWidget*,QDockWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->tabifyDockWidget(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMainWindowFunc_tabifyDockWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDockWidget, PySide.QtGui.QDockWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMainWindow.tabifyDockWidget", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_toolBarArea(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toolBarArea(QToolBar*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArg)))) {
        overloadId = 0; // toolBarArea(QToolBar*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_toolBarArea_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toolBarArea(QToolBar*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ToolBarArea cppResult = const_cast<const ::QMainWindow*>(cppSelf)->toolBarArea(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBARAREA_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_toolBarArea_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.toolBarArea", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_toolBarBreak(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toolBarBreak(QToolBar*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], (pyArg)))) {
        overloadId = 0; // toolBarBreak(QToolBar*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMainWindowFunc_toolBarBreak_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QToolBar* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toolBarBreak(QToolBar*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->toolBarBreak(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMainWindowFunc_toolBarBreak_TypeError:
        const char* overloads[] = {"PySide.QtGui.QToolBar", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMainWindow.toolBarBreak", overloads);
        return 0;
}

static PyObject* Sbk_QMainWindowFunc_toolButtonStyle(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolButtonStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ToolButtonStyle cppResult = const_cast<const ::QMainWindow*>(cppSelf)->toolButtonStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TOOLBUTTONSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMainWindowFunc_unifiedTitleAndToolBarOnMac(PyObject* self)
{
    ::QMainWindow* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMainWindow*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // unifiedTitleAndToolBarOnMac()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QMainWindow*>(cppSelf)->unifiedTitleAndToolBarOnMac();
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

static PyMethodDef Sbk_QMainWindow_methods[] = {
    {"addDockWidget", (PyCFunction)Sbk_QMainWindowFunc_addDockWidget, METH_VARARGS},
    {"addToolBar", (PyCFunction)Sbk_QMainWindowFunc_addToolBar, METH_VARARGS},
    {"addToolBarBreak", (PyCFunction)Sbk_QMainWindowFunc_addToolBarBreak, METH_VARARGS|METH_KEYWORDS},
    {"centralWidget", (PyCFunction)Sbk_QMainWindowFunc_centralWidget, METH_NOARGS},
    {"contextMenuEvent", (PyCFunction)Sbk_QMainWindowFunc_contextMenuEvent, METH_O},
    {"corner", (PyCFunction)Sbk_QMainWindowFunc_corner, METH_O},
    {"createPopupMenu", (PyCFunction)Sbk_QMainWindowFunc_createPopupMenu, METH_NOARGS},
    {"dockOptions", (PyCFunction)Sbk_QMainWindowFunc_dockOptions, METH_NOARGS},
    {"dockWidgetArea", (PyCFunction)Sbk_QMainWindowFunc_dockWidgetArea, METH_O},
    {"documentMode", (PyCFunction)Sbk_QMainWindowFunc_documentMode, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QMainWindowFunc_event, METH_O},
    {"iconSize", (PyCFunction)Sbk_QMainWindowFunc_iconSize, METH_NOARGS},
    {"insertToolBar", (PyCFunction)Sbk_QMainWindowFunc_insertToolBar, METH_VARARGS},
    {"insertToolBarBreak", (PyCFunction)Sbk_QMainWindowFunc_insertToolBarBreak, METH_O},
    {"isAnimated", (PyCFunction)Sbk_QMainWindowFunc_isAnimated, METH_NOARGS},
    {"isDockNestingEnabled", (PyCFunction)Sbk_QMainWindowFunc_isDockNestingEnabled, METH_NOARGS},
    {"isSeparator", (PyCFunction)Sbk_QMainWindowFunc_isSeparator, METH_O},
    {"menuBar", (PyCFunction)Sbk_QMainWindowFunc_menuBar, METH_NOARGS},
    {"menuWidget", (PyCFunction)Sbk_QMainWindowFunc_menuWidget, METH_NOARGS},
    {"removeDockWidget", (PyCFunction)Sbk_QMainWindowFunc_removeDockWidget, METH_O},
    {"removeToolBar", (PyCFunction)Sbk_QMainWindowFunc_removeToolBar, METH_O},
    {"removeToolBarBreak", (PyCFunction)Sbk_QMainWindowFunc_removeToolBarBreak, METH_O},
    {"restoreDockWidget", (PyCFunction)Sbk_QMainWindowFunc_restoreDockWidget, METH_O},
    {"restoreState", (PyCFunction)Sbk_QMainWindowFunc_restoreState, METH_VARARGS|METH_KEYWORDS},
    {"saveState", (PyCFunction)Sbk_QMainWindowFunc_saveState, METH_VARARGS|METH_KEYWORDS},
    {"setAnimated", (PyCFunction)Sbk_QMainWindowFunc_setAnimated, METH_O},
    {"setCentralWidget", (PyCFunction)Sbk_QMainWindowFunc_setCentralWidget, METH_O},
    {"setCorner", (PyCFunction)Sbk_QMainWindowFunc_setCorner, METH_VARARGS},
    {"setDockNestingEnabled", (PyCFunction)Sbk_QMainWindowFunc_setDockNestingEnabled, METH_O},
    {"setDockOptions", (PyCFunction)Sbk_QMainWindowFunc_setDockOptions, METH_O},
    {"setDocumentMode", (PyCFunction)Sbk_QMainWindowFunc_setDocumentMode, METH_O},
    {"setIconSize", (PyCFunction)Sbk_QMainWindowFunc_setIconSize, METH_O},
    {"setMenuBar", (PyCFunction)Sbk_QMainWindowFunc_setMenuBar, METH_O},
    {"setMenuWidget", (PyCFunction)Sbk_QMainWindowFunc_setMenuWidget, METH_O},
    {"setStatusBar", (PyCFunction)Sbk_QMainWindowFunc_setStatusBar, METH_O},
    {"setTabPosition", (PyCFunction)Sbk_QMainWindowFunc_setTabPosition, METH_VARARGS},
    {"setTabShape", (PyCFunction)Sbk_QMainWindowFunc_setTabShape, METH_O},
    {"setToolButtonStyle", (PyCFunction)Sbk_QMainWindowFunc_setToolButtonStyle, METH_O},
    {"setUnifiedTitleAndToolBarOnMac", (PyCFunction)Sbk_QMainWindowFunc_setUnifiedTitleAndToolBarOnMac, METH_O},
    {"splitDockWidget", (PyCFunction)Sbk_QMainWindowFunc_splitDockWidget, METH_VARARGS},
    {"statusBar", (PyCFunction)Sbk_QMainWindowFunc_statusBar, METH_NOARGS},
    {"tabPosition", (PyCFunction)Sbk_QMainWindowFunc_tabPosition, METH_O},
    {"tabShape", (PyCFunction)Sbk_QMainWindowFunc_tabShape, METH_NOARGS},
    {"tabifiedDockWidgets", (PyCFunction)Sbk_QMainWindowFunc_tabifiedDockWidgets, METH_O},
    {"tabifyDockWidget", (PyCFunction)Sbk_QMainWindowFunc_tabifyDockWidget, METH_VARARGS},
    {"toolBarArea", (PyCFunction)Sbk_QMainWindowFunc_toolBarArea, METH_O},
    {"toolBarBreak", (PyCFunction)Sbk_QMainWindowFunc_toolBarBreak, METH_O},
    {"toolButtonStyle", (PyCFunction)Sbk_QMainWindowFunc_toolButtonStyle, METH_NOARGS},
    {"unifiedTitleAndToolBarOnMac", (PyCFunction)Sbk_QMainWindowFunc_unifiedTitleAndToolBarOnMac, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMainWindow_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMainWindow_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QMainWindowSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QMainWindow* me = reinterpret_cast< ::QMainWindow*>(obj);
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
static SbkObjectType Sbk_QMainWindow_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMainWindow",
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
    /*tp_traverse*/         Sbk_QMainWindow_traverse,
    /*tp_clear*/            Sbk_QMainWindow_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMainWindow_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMainWindow_Init,
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

static void* Sbk_QMainWindow_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QMainWindow*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QMainWindow*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QMainWindow_DockOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow::DockOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMainWindow::DockOptions)PyLong_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMainWindow::DockOptions)PyInt_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMainWindow_DockOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow::DockOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMainWindow::DockOptions)PyLong_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMainWindow::DockOptions)PyInt_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMainWindow_DockOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow::DockOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMainWindow::DockOptions)PyLong_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMainWindow::DockOptions)PyInt_AsLong(self);
    cppArg = (QMainWindow::DockOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMainWindow_DockOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QMainWindow::DockOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), self, &cppSelf);
    ::QMainWindow::DockOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QMainWindow_DockOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QMainWindow_DockOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QMainWindow_DockOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QMainWindow_DockOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QMainWindow_DockOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QMainWindow_DockOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QMainWindow_DockOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QMainWindow_DockOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QMainWindow_DockOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QMainWindow_DockOption_long,
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
static void QMainWindow_DockOption_PythonToCpp_QMainWindow_DockOption(PyObject* pyIn, void* cppOut) {
    *((::QMainWindow::DockOption*)cppOut) = (::QMainWindow::DockOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMainWindow_DockOption_PythonToCpp_QMainWindow_DockOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX]))
        return QMainWindow_DockOption_PythonToCpp_QMainWindow_DockOption;
    return 0;
}
static PyObject* QMainWindow_DockOption_CppToPython_QMainWindow_DockOption(const void* cppIn) {
    int castCppIn = *((::QMainWindow::DockOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX], castCppIn);

}

static void QFlags_QMainWindow_DockOption__PythonToCpp_QFlags_QMainWindow_DockOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QMainWindow::DockOption>*)cppOut) = ::QFlags<QMainWindow::DockOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QMainWindow_DockOption__PythonToCpp_QFlags_QMainWindow_DockOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]))
        return QFlags_QMainWindow_DockOption__PythonToCpp_QFlags_QMainWindow_DockOption_;
    return 0;
}
static PyObject* QFlags_QMainWindow_DockOption__CppToPython_QFlags_QMainWindow_DockOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QMainWindow::DockOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]));

}

static void QMainWindow_DockOption_PythonToCpp_QFlags_QMainWindow_DockOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QMainWindow::DockOption>*)cppOut) = ::QFlags<QMainWindow::DockOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QMainWindow_DockOption_PythonToCpp_QFlags_QMainWindow_DockOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX]))
        return QMainWindow_DockOption_PythonToCpp_QFlags_QMainWindow_DockOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QMainWindow_DockOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QMainWindow::DockOption>*)cppOut) = ::QFlags<QMainWindow::DockOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QMainWindow_DockOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QMainWindow_DockOption_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMainWindow_PythonToCpp_QMainWindow_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMainWindow_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMainWindow_PythonToCpp_QMainWindow_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMainWindow_Type))
        return QMainWindow_PythonToCpp_QMainWindow_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMainWindow_PTR_CppToPython_QMainWindow(const void* cppIn) {
    return PySide::getWrapperForQObject((::QMainWindow*)cppIn, &Sbk_QMainWindow_Type);

}

void init_QMainWindow(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMainWindow_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMainWindow", "QMainWindow*",
        &Sbk_QMainWindow_Type, &Shiboken::callCppDestructor< ::QMainWindow >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMainWindow_Type,
        QMainWindow_PythonToCpp_QMainWindow_PTR,
        is_QMainWindow_PythonToCpp_QMainWindow_PTR_Convertible,
        QMainWindow_PTR_CppToPython_QMainWindow);

    Shiboken::Conversions::registerConverterName(converter, "QMainWindow");
    Shiboken::Conversions::registerConverterName(converter, "QMainWindow*");
    Shiboken::Conversions::registerConverterName(converter, "QMainWindow&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMainWindow).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMainWindowWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QMainWindow_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QMainWindow_Type, &Sbk_QMainWindowSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QMainWindow_Type, &Sbk_QMainWindow_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'DockOption'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX] = PySide::QFlags::create("DockOptions", &SbkPySide_QtGui_QMainWindow_DockOption_as_number);
    SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMainWindow_Type,
        "DockOption",
        "PySide.QtGui.QMainWindow.DockOption",
        "QMainWindow::DockOption",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
        &Sbk_QMainWindow_Type, "AnimatedDocks", (long) QMainWindow::AnimatedDocks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
        &Sbk_QMainWindow_Type, "AllowNestedDocks", (long) QMainWindow::AllowNestedDocks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
        &Sbk_QMainWindow_Type, "AllowTabbedDocks", (long) QMainWindow::AllowTabbedDocks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
        &Sbk_QMainWindow_Type, "ForceTabbedDocks", (long) QMainWindow::ForceTabbedDocks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
        &Sbk_QMainWindow_Type, "VerticalTabs", (long) QMainWindow::VerticalTabs))
        return ;
    // Register converter for enum 'QMainWindow::DockOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX],
            QMainWindow_DockOption_CppToPython_QMainWindow_DockOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMainWindow_DockOption_PythonToCpp_QMainWindow_DockOption,
            is_QMainWindow_DockOption_PythonToCpp_QMainWindow_DockOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_DOCKOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMainWindow::DockOption");
        Shiboken::Conversions::registerConverterName(converter, "DockOption");
    }
    // Register converter for flag 'QFlags<QMainWindow::DockOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX],
            QFlags_QMainWindow_DockOption__CppToPython_QFlags_QMainWindow_DockOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMainWindow_DockOption_PythonToCpp_QFlags_QMainWindow_DockOption_,
            is_QMainWindow_DockOption_PythonToCpp_QFlags_QMainWindow_DockOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QMainWindow_DockOption__PythonToCpp_QFlags_QMainWindow_DockOption_,
            is_QFlags_QMainWindow_DockOption__PythonToCpp_QFlags_QMainWindow_DockOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QMainWindow_DockOption_,
            is_number_PythonToCpp_QFlags_QMainWindow_DockOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMAINWINDOW_DOCKOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QMainWindow::DockOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<DockOption>");
    }
    // End of 'DockOption' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QMainWindow_Type, &::QMainWindow::staticMetaObject);

    qRegisterMetaType< ::QMainWindow::DockOption >("QMainWindow::DockOption");
    qRegisterMetaType< ::QMainWindow::DockOptions >("QMainWindow::DockOptions");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QMainWindow_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QMainWindow_Type, &::QMainWindow::staticMetaObject, sizeof(::QMainWindow));
}
