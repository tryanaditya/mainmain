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

#include "qmessagebox_wrapper.h"

// Extra includes
#include <QList>
#include <QPixmap>
#include <qabstractbutton.h>
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
#include <qkeysequence.h>
#include <qlayout.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpixmap.h>
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

QMessageBoxWrapper::QMessageBoxWrapper(QMessageBox::Icon icon, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QWidget * parent, QFlags<Qt::WindowType> flags) : QMessageBox(icon, title, text, buttons, parent, flags) {
    // ... middle
}

QMessageBoxWrapper::QMessageBoxWrapper(QWidget * parent) : QMessageBox(parent) {
    // ... middle
}

void QMessageBoxWrapper::accept()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "accept"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::accept();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QMessageBoxWrapper::actionEvent(QActionEvent * event)
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

void QMessageBoxWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::changeEvent(event);
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

void QMessageBoxWrapper::childEvent(QChildEvent * arg__1)
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

void QMessageBoxWrapper::closeEvent(QCloseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::closeEvent(event);
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

void QMessageBoxWrapper::connectNotify(const char * signal)
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

void QMessageBoxWrapper::contextMenuEvent(QContextMenuEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::contextMenuEvent(arg__1);
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

void QMessageBoxWrapper::customEvent(QEvent * arg__1)
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

int QMessageBoxWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::disconnectNotify(const char * signal)
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

void QMessageBoxWrapper::done(int arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "done"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::done(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QMessageBoxWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void QMessageBoxWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void QMessageBoxWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void QMessageBoxWrapper::dropEvent(QDropEvent * event)
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

void QMessageBoxWrapper::enterEvent(QEvent * event)
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

bool QMessageBoxWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::event(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QMessageBoxWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::eventFilter(arg__1, arg__2);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QMessageBoxWrapper::focusInEvent(QFocusEvent * event)
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

bool QMessageBoxWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::focusOutEvent(QFocusEvent * event)
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

int QMessageBoxWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::hideEvent(QHideEvent * event)
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

void QMessageBoxWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant QMessageBoxWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::keyPressEvent(event);
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

void QMessageBoxWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QMessageBoxWrapper::languageChange()
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

void QMessageBoxWrapper::leaveEvent(QEvent * event)
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

int QMessageBoxWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QMessageBoxWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::minimumSizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void QMessageBoxWrapper::mouseMoveEvent(QMouseEvent * event)
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

void QMessageBoxWrapper::mousePressEvent(QMouseEvent * event)
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

void QMessageBoxWrapper::mouseReleaseEvent(QMouseEvent * event)
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

void QMessageBoxWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QMessageBoxWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::paintEvent(QPaintEvent * event)
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

void QMessageBoxWrapper::reject()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reject"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::reject();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QMessageBoxWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::resizeEvent(event);
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

void QMessageBoxWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::setVisible(visible);
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

void QMessageBoxWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::showEvent(event);
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

QSize QMessageBoxWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QMessageBox::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QMessageBox.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QMessageBoxWrapper::tabletEvent(QTabletEvent * event)
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

void QMessageBoxWrapper::timerEvent(QTimerEvent * arg__1)
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

void QMessageBoxWrapper::wheelEvent(QWheelEvent * event)
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

const QMetaObject* QMessageBoxWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QMessageBox::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QMessageBoxWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QMessageBox::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QMessageBoxWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QMessageBoxWrapper* >(this));
        return QMessageBox::qt_metacast(_clname);
}

QMessageBoxWrapper::~QMessageBoxWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QMessageBox_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"buttons", "flags", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QMessageBox >()))
        return -1;

    ::QMessageBoxWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QMessageBox_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOO:QMessageBox", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return -1;


    // Overloaded function decisor
    // 0: QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
    // 1: QMessageBox(QWidget*)
    if (numArgs == 0) {
        overloadId = 1; // QMessageBox(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QMessageBox(QWidget*)
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4])))) {
                if (numArgs == 5) {
                    overloadId = 0; // QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
                } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[5])))) {
                    overloadId = 0; // QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBox_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QMessageBox(QMessageBox::Icon icon, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QWidget * parent, QFlags<Qt::WindowType> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "buttons");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox(): got multiple values for keyword argument 'buttons'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3]))))
                        goto Sbk_QMessageBox_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4]))))
                        goto Sbk_QMessageBox_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox(): got multiple values for keyword argument 'flags'.");
                    return -1;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[5]))))
                        goto Sbk_QMessageBox_Init_TypeError;
                }
            }
            ::QMessageBox::Icon cppArg0 = ((::QMessageBox::Icon)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QMessageBox::StandardButton> cppArg3 = QMessageBox::NoButton;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QWidget* cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::WindowType> cppArg5 = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // QMessageBox(QMessageBox::Icon,QString,QString,QFlags<QMessageBox::StandardButton>,QWidget*,QFlags<Qt::WindowType>)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QMessageBoxWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QMessageBoxWrapper(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[4], self);
            }
            break;
        }
        case 1: // QMessageBox(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QMessageBox_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QMessageBox(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QMessageBoxWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QMessageBoxWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QMessageBox >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QMessageBox_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 3))
        return -1;


    return 1;

    Sbk_QMessageBox_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMessageBox.Icon, unicode, unicode, PySide.QtGui.QMessageBox.StandardButtons = QMessageBox.NoButton, PySide.QtGui.QWidget = None, PySide.QtCore.Qt.WindowFlags = Qt.Dialog | Qt.MSWindowsFixedSizeDialogHint", "PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox", overloads);
        return -1;
}

static PyObject* Sbk_QMessageBoxFunc_about(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "about", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: about(QWidget*,QString,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // about(QWidget*,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_about_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = ::QString();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // about(QWidget*,QString,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QMessageBox::about(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_about_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.about", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_aboutQt(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.aboutQt(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.aboutQt(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:aboutQt", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: aboutQt(QWidget*,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // aboutQt(QWidget*,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // aboutQt(QWidget*,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_aboutQt_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "title");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.aboutQt(): got multiple values for keyword argument 'title'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QMessageBoxFunc_aboutQt_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // aboutQt(QWidget*,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QMessageBox::aboutQt(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_aboutQt_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.aboutQt", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_addButton(PyObject* self, PyObject* args)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
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
    // 0: addButton(QAbstractButton*,QMessageBox::ButtonRole)
    // 1: addButton(QMessageBox::StandardButton)
    // 2: addButton(QString,QMessageBox::ButtonRole)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[0])))) {
        overloadId = 1; // addButton(QMessageBox::StandardButton)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // addButton(QAbstractButton*,QMessageBox::ButtonRole)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX]), (pyArgs[1])))) {
        overloadId = 2; // addButton(QString,QMessageBox::ButtonRole)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_addButton_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addButton(QAbstractButton * button, QMessageBox::ButtonRole role)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QAbstractButton* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QMessageBox::ButtonRole cppArg1 = ((::QMessageBox::ButtonRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addButton(QAbstractButton*,QMessageBox::ButtonRole)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addButton(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // addButton(QMessageBox::StandardButton button)
        {
            ::QMessageBox::StandardButton cppArg0 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addButton(QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPushButton * cppResult = cppSelf->addButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPUSHBUTTON_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 2: // addButton(const QString & text, QMessageBox::ButtonRole role)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QMessageBox::ButtonRole cppArg1 = ((::QMessageBox::ButtonRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addButton(QString,QMessageBox::ButtonRole)
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

    Sbk_QMessageBoxFunc_addButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton, PySide.QtGui.QMessageBox.ButtonRole", "PySide.QtGui.QMessageBox.StandardButton", "unicode, PySide.QtGui.QMessageBox.ButtonRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.addButton", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_button(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: button(QMessageBox::StandardButton)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // button(QMessageBox::StandardButton)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_button_TypeError;

    // Call function/method
    {
        ::QMessageBox::StandardButton cppArg0 = ((::QMessageBox::StandardButton)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // button(QMessageBox::StandardButton)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractButton * cppResult = const_cast<const ::QMessageBox*>(cppSelf)->button(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_button_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMessageBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.button", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_buttonRole(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_buttonRole_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractButton* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // buttonRole(QAbstractButton*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMessageBox::ButtonRole cppResult = const_cast<const ::QMessageBox*>(cppSelf)->buttonRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_buttonRole_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.buttonRole", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_buttons(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QAbstractButton * > cppResult = const_cast<const ::QMessageBox*>(cppSelf)->buttons();
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

static PyObject* Sbk_QMessageBoxFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_clickedButton(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clickedButton()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractButton * cppResult = const_cast<const ::QMessageBox*>(cppSelf)->clickedButton();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_closeEvent(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closeEvent(QCloseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // closeEvent(QCloseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_closeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCloseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeEvent(QCloseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::closeEvent(cppArg0) : cppSelf->closeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_closeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCloseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.closeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_critical(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.critical(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.critical(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:critical", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: critical(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
    // 1: critical(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // critical(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
        } else if (numArgs == 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
            overloadId = 1; // critical(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // critical(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
                overloadId = 0; // critical(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_critical_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // critical(QWidget * parent, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defaultButton)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "buttons");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.critical(): got multiple values for keyword argument 'buttons'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3]))))
                        goto Sbk_QMessageBoxFunc_critical_TypeError;
                }
                value = PyDict_GetItemString(kwds, "defaultButton");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.critical(): got multiple values for keyword argument 'defaultButton'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4]))))
                        goto Sbk_QMessageBoxFunc_critical_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QMessageBox::StandardButton> cppArg3 = QMessageBox::Ok;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = QMessageBox::NoButton;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // critical(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMessageBox::StandardButton cppResult = ::QMessageBox::critical(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
            }
            break;
        }
        case 1: // critical(QWidget * parent, const QString & title, const QString & text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QMessageBox::StandardButton cppArg3 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // critical(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = ::QMessageBox::critical(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_critical_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButtons = QMessageBox.Ok, PySide.QtGui.QMessageBox.StandardButton = NoButton", "PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButton, PySide.QtGui.QMessageBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.critical", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_defaultButton(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultButton()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPushButton * cppResult = const_cast<const ::QMessageBox*>(cppSelf)->defaultButton();
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
}

static PyObject* Sbk_QMessageBoxFunc_detailedText(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // detailedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QMessageBox*>(cppSelf)->detailedText();
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

static PyObject* Sbk_QMessageBoxFunc_escapeButton(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // escapeButton()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractButton * cppResult = const_cast<const ::QMessageBox*>(cppSelf)->escapeButton();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.event", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_exec_(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // exec()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->exec();
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

static PyObject* Sbk_QMessageBoxFunc_icon(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMessageBox::Icon cppResult = const_cast<const ::QMessageBox*>(cppSelf)->icon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_iconPixmap(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconPixmap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QMessageBox*>(cppSelf)->iconPixmap();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_information(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.information(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.information(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:information", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: information(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
    // 1: information(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // information(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 1; // information(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
                overloadId = 1; // information(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
            }
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // information(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
                overloadId = 0; // information(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_information_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // information(QWidget * parent, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defaultButton)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "buttons");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.information(): got multiple values for keyword argument 'buttons'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3]))))
                        goto Sbk_QMessageBoxFunc_information_TypeError;
                }
                value = PyDict_GetItemString(kwds, "defaultButton");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.information(): got multiple values for keyword argument 'defaultButton'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4]))))
                        goto Sbk_QMessageBoxFunc_information_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QMessageBox::StandardButton> cppArg3 = QMessageBox::Ok;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = QMessageBox::NoButton;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // information(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMessageBox::StandardButton cppResult = ::QMessageBox::information(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
            }
            break;
        }
        case 1: // information(QWidget * parent, const QString & title, const QString & text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "button1");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.information(): got multiple values for keyword argument 'button1'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4]))))
                        goto Sbk_QMessageBoxFunc_information_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QMessageBox::StandardButton cppArg3 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = QMessageBox::NoButton;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // information(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMessageBox::StandardButton cppResult = ::QMessageBox::information(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_information_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButtons = QMessageBox.Ok, PySide.QtGui.QMessageBox.StandardButton = NoButton", "PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButton, PySide.QtGui.QMessageBox.StandardButton = NoButton", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.information", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_informativeText(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // informativeText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QMessageBox*>(cppSelf)->informativeText();
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

static PyObject* Sbk_QMessageBoxFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_open(PyObject* self, PyObject* args)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QMessageBoxFunc_open_TypeError;

    if (!PyArg_UnpackTuple(args, "open", 0, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: open()
    // 1: open(QObject*,const char*)
    if (numArgs == 0) {
        overloadId = 0; // open()
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
        overloadId = 1; // open(QObject*,const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_open_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // open()
        {

            if (!PyErr_Occurred()) {
                // open()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->open();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // open(QObject * receiver, const char * member)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // open(QObject*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->open(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_open_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.open", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_question(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.question(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.question(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:question", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: question(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
    // 1: question(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // question(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
        } else if (numArgs == 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
            overloadId = 1; // question(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // question(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
                overloadId = 0; // question(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_question_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // question(QWidget * parent, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defaultButton)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "buttons");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.question(): got multiple values for keyword argument 'buttons'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3]))))
                        goto Sbk_QMessageBoxFunc_question_TypeError;
                }
                value = PyDict_GetItemString(kwds, "defaultButton");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.question(): got multiple values for keyword argument 'defaultButton'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4]))))
                        goto Sbk_QMessageBoxFunc_question_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QMessageBox::StandardButton> cppArg3 = QMessageBox::Ok;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = QMessageBox::NoButton;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // question(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMessageBox::StandardButton cppResult = ::QMessageBox::question(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
            }
            break;
        }
        case 1: // question(QWidget * parent, const QString & title, const QString & text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QMessageBox::StandardButton cppArg3 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // question(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = ::QMessageBox::question(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_question_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButtons = QMessageBox.Ok, PySide.QtGui.QMessageBox.StandardButton = NoButton", "PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButton, PySide.QtGui.QMessageBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.question", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_removeButton(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeButton(QAbstractButton*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArg)))) {
        overloadId = 0; // removeButton(QAbstractButton*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_removeButton_TypeError;

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
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_removeButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.removeButton", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_resizeEvent(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QResizeEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setDefaultButton(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultButton(QMessageBox::StandardButton)
    // 1: setDefaultButton(QPushButton*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPUSHBUTTON_IDX], (pyArg)))) {
        overloadId = 1; // setDefaultButton(QPushButton*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArg)))) {
        overloadId = 0; // setDefaultButton(QMessageBox::StandardButton)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setDefaultButton_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setDefaultButton(QMessageBox::StandardButton button)
        {
            ::QMessageBox::StandardButton cppArg0 = ((::QMessageBox::StandardButton)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultButton(QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDefaultButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setDefaultButton(QPushButton * button)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPushButton* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultButton(QPushButton*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDefaultButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setDefaultButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMessageBox.StandardButton", "PySide.QtGui.QPushButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setDefaultButton", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setDetailedText(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDetailedText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDetailedText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setDetailedText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDetailedText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDetailedText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setDetailedText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setDetailedText", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setEscapeButton(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEscapeButton(QAbstractButton*)
    // 1: setEscapeButton(QMessageBox::StandardButton)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArg)))) {
        overloadId = 1; // setEscapeButton(QMessageBox::StandardButton)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTBUTTON_IDX], (pyArg)))) {
        overloadId = 0; // setEscapeButton(QAbstractButton*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setEscapeButton_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setEscapeButton(QAbstractButton * button)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QAbstractButton* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setEscapeButton(QAbstractButton*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEscapeButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setEscapeButton(QMessageBox::StandardButton button)
        {
            ::QMessageBox::StandardButton cppArg0 = ((::QMessageBox::StandardButton)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setEscapeButton(QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setEscapeButton(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setEscapeButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", "PySide.QtGui.QMessageBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setEscapeButton", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QMessageBox::Icon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX]), (pyArg)))) {
        overloadId = 0; // setIcon(QMessageBox::Icon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setIcon_TypeError;

    // Call function/method
    {
        ::QMessageBox::Icon cppArg0 = ((::QMessageBox::Icon)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIcon(QMessageBox::Icon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIcon(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMessageBox.Icon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setIconPixmap(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconPixmap(QPixmap)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArg)))) {
        overloadId = 0; // setIconPixmap(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setIconPixmap_TypeError;

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
            // setIconPixmap(QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconPixmap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setIconPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setIconPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setInformativeText(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInformativeText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setInformativeText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setInformativeText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInformativeText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInformativeText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setInformativeText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setInformativeText", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setStandardButtons(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStandardButtons(QFlags<QMessageBox::StandardButton>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArg)))) {
        overloadId = 0; // setStandardButtons(QFlags<QMessageBox::StandardButton>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setStandardButtons_TypeError;

    // Call function/method
    {
        ::QFlags<QMessageBox::StandardButton> cppArg0 = ((::QFlags<QMessageBox::StandardButton>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStandardButtons(QFlags<QMessageBox::StandardButton>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStandardButtons(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setStandardButtons_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMessageBox.StandardButtons", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setStandardButtons", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setText(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setText", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setTextFormat(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextFormat(Qt::TextFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX]), (pyArg)))) {
        overloadId = 0; // setTextFormat(Qt::TextFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setTextFormat_TypeError;

    // Call function/method
    {
        ::Qt::TextFormat cppArg0 = ((::Qt::TextFormat)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextFormat(Qt::TextFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setTextFormat_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TextFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setTextFormat", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setWindowModality(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWindowModality(Qt::WindowModality)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_WINDOWMODALITY_IDX]), (pyArg)))) {
        overloadId = 0; // setWindowModality(Qt::WindowModality)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setWindowModality_TypeError;

    // Call function/method
    {
        ::Qt::WindowModality cppArg0 = ((::Qt::WindowModality)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWindowModality(Qt::WindowModality)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWindowModality(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setWindowModality_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.WindowModality", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setWindowModality", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_setWindowTitle(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWindowTitle(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWindowTitle(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_setWindowTitle_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWindowTitle(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWindowTitle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_setWindowTitle_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.setWindowTitle", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_showEvent(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: showEvent(QShowEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], (pyArg)))) {
        overloadId = 0; // showEvent(QShowEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_showEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QShowEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // showEvent(QShowEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QMessageBox::showEvent(cppArg0) : cppSelf->showEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QMessageBoxFunc_showEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QShowEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.showEvent", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_sizeHint(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QMessageBox*>(cppSelf)->::QMessageBox::sizeHint() : const_cast<const ::QMessageBox*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QMessageBoxFunc_standardButton(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_standardButton_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractButton* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // standardButton(QAbstractButton*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMessageBox::StandardButton cppResult = const_cast<const ::QMessageBox*>(cppSelf)->standardButton(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_standardButton_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractButton", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QMessageBox.standardButton", overloads);
        return 0;
}

static PyObject* Sbk_QMessageBoxFunc_standardButtons(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardButtons()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QMessageBox::StandardButton> cppResult = const_cast<const ::QMessageBox*>(cppSelf)->standardButtons();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_text(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QMessageBox*>(cppSelf)->text();
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

static PyObject* Sbk_QMessageBoxFunc_textFormat(PyObject* self)
{
    ::QMessageBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QMessageBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::TextFormat cppResult = const_cast<const ::QMessageBox*>(cppSelf)->textFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TEXTFORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QMessageBoxFunc_warning(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.warning(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.warning(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:warning", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: warning(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
    // 1: warning(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // warning(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
        } else if (numArgs == 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
            overloadId = 1; // warning(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // warning(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4])))) {
                overloadId = 0; // warning(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QMessageBoxFunc_warning_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // warning(QWidget * parent, const QString & title, const QString & text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defaultButton)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "buttons");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.warning(): got multiple values for keyword argument 'buttons'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), (pyArgs[3]))))
                        goto Sbk_QMessageBoxFunc_warning_TypeError;
                }
                value = PyDict_GetItemString(kwds, "defaultButton");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QMessageBox.warning(): got multiple values for keyword argument 'defaultButton'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), (pyArgs[4]))))
                        goto Sbk_QMessageBoxFunc_warning_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QMessageBox::StandardButton> cppArg3 = QMessageBox::Ok;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = QMessageBox::NoButton;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // warning(QWidget*,QString,QString,QFlags<QMessageBox::StandardButton>,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QMessageBox::StandardButton cppResult = ::QMessageBox::warning(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]), &cppResult);
            }
            break;
        }
        case 1: // warning(QWidget * parent, const QString & title, const QString & text, QMessageBox::StandardButton button0, QMessageBox::StandardButton button1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QMessageBox::StandardButton cppArg3 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QMessageBox::StandardButton cppArg4 = ((::QMessageBox::StandardButton)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // warning(QWidget*,QString,QString,QMessageBox::StandardButton,QMessageBox::StandardButton)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                int cppResult = ::QMessageBox::warning(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QMessageBoxFunc_warning_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButtons = QMessageBox.Ok, PySide.QtGui.QMessageBox.StandardButton = NoButton", "PySide.QtGui.QWidget, unicode, unicode, PySide.QtGui.QMessageBox.StandardButton, PySide.QtGui.QMessageBox.StandardButton", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QMessageBox.warning", overloads);
        return 0;
}

static PyMethodDef Sbk_QMessageBox_methods[] = {
    {"about", (PyCFunction)Sbk_QMessageBoxFunc_about, METH_VARARGS|METH_STATIC},
    {"aboutQt", (PyCFunction)Sbk_QMessageBoxFunc_aboutQt, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"addButton", (PyCFunction)Sbk_QMessageBoxFunc_addButton, METH_VARARGS},
    {"button", (PyCFunction)Sbk_QMessageBoxFunc_button, METH_O},
    {"buttonRole", (PyCFunction)Sbk_QMessageBoxFunc_buttonRole, METH_O},
    {"buttons", (PyCFunction)Sbk_QMessageBoxFunc_buttons, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QMessageBoxFunc_changeEvent, METH_O},
    {"clickedButton", (PyCFunction)Sbk_QMessageBoxFunc_clickedButton, METH_NOARGS},
    {"closeEvent", (PyCFunction)Sbk_QMessageBoxFunc_closeEvent, METH_O},
    {"critical", (PyCFunction)Sbk_QMessageBoxFunc_critical, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"defaultButton", (PyCFunction)Sbk_QMessageBoxFunc_defaultButton, METH_NOARGS},
    {"detailedText", (PyCFunction)Sbk_QMessageBoxFunc_detailedText, METH_NOARGS},
    {"escapeButton", (PyCFunction)Sbk_QMessageBoxFunc_escapeButton, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QMessageBoxFunc_event, METH_O},
    {"exec_", (PyCFunction)Sbk_QMessageBoxFunc_exec_, METH_NOARGS},
    {"icon", (PyCFunction)Sbk_QMessageBoxFunc_icon, METH_NOARGS},
    {"iconPixmap", (PyCFunction)Sbk_QMessageBoxFunc_iconPixmap, METH_NOARGS},
    {"information", (PyCFunction)Sbk_QMessageBoxFunc_information, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"informativeText", (PyCFunction)Sbk_QMessageBoxFunc_informativeText, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QMessageBoxFunc_keyPressEvent, METH_O},
    {"open", (PyCFunction)Sbk_QMessageBoxFunc_open, METH_VARARGS},
    {"question", (PyCFunction)Sbk_QMessageBoxFunc_question, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"removeButton", (PyCFunction)Sbk_QMessageBoxFunc_removeButton, METH_O},
    {"resizeEvent", (PyCFunction)Sbk_QMessageBoxFunc_resizeEvent, METH_O},
    {"setDefaultButton", (PyCFunction)Sbk_QMessageBoxFunc_setDefaultButton, METH_O},
    {"setDetailedText", (PyCFunction)Sbk_QMessageBoxFunc_setDetailedText, METH_O},
    {"setEscapeButton", (PyCFunction)Sbk_QMessageBoxFunc_setEscapeButton, METH_O},
    {"setIcon", (PyCFunction)Sbk_QMessageBoxFunc_setIcon, METH_O},
    {"setIconPixmap", (PyCFunction)Sbk_QMessageBoxFunc_setIconPixmap, METH_O},
    {"setInformativeText", (PyCFunction)Sbk_QMessageBoxFunc_setInformativeText, METH_O},
    {"setStandardButtons", (PyCFunction)Sbk_QMessageBoxFunc_setStandardButtons, METH_O},
    {"setText", (PyCFunction)Sbk_QMessageBoxFunc_setText, METH_O},
    {"setTextFormat", (PyCFunction)Sbk_QMessageBoxFunc_setTextFormat, METH_O},
    {"setWindowModality", (PyCFunction)Sbk_QMessageBoxFunc_setWindowModality, METH_O},
    {"setWindowTitle", (PyCFunction)Sbk_QMessageBoxFunc_setWindowTitle, METH_O},
    {"showEvent", (PyCFunction)Sbk_QMessageBoxFunc_showEvent, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QMessageBoxFunc_sizeHint, METH_NOARGS},
    {"standardButton", (PyCFunction)Sbk_QMessageBoxFunc_standardButton, METH_O},
    {"standardButtons", (PyCFunction)Sbk_QMessageBoxFunc_standardButtons, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QMessageBoxFunc_text, METH_NOARGS},
    {"textFormat", (PyCFunction)Sbk_QMessageBoxFunc_textFormat, METH_NOARGS},
    {"warning", (PyCFunction)Sbk_QMessageBoxFunc_warning, METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QMessageBox_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QMessageBox_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QMessageBoxSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QMessageBox* me = reinterpret_cast< ::QMessageBox*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QDIALOG_IDX]))
        return static_cast< ::QDialog*>(me);
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
static SbkObjectType Sbk_QMessageBox_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QMessageBox",
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
    /*tp_traverse*/         Sbk_QMessageBox_traverse,
    /*tp_clear*/            Sbk_QMessageBox_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QMessageBox_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QMessageBox_Init,
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

static void* Sbk_QMessageBox_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QMessageBox*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QMessageBox*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QMessageBox_StandardButton___and__(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMessageBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMessageBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMessageBox_StandardButton___or__(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMessageBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMessageBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMessageBox_StandardButton___xor__(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QMessageBox::StandardButtons)PyLong_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QMessageBox::StandardButtons)PyInt_AsLong(self);
    cppArg = (QMessageBox::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QMessageBox_StandardButton___invert__(PyObject* self, PyObject* pyArg)
{
    ::QMessageBox::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), self, &cppSelf);
    ::QMessageBox::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QMessageBox_StandardButton_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QMessageBox_StandardButton__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QMessageBox_StandardButton_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QMessageBox_StandardButton__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QMessageBox_StandardButton___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QMessageBox_StandardButton___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QMessageBox_StandardButton___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QMessageBox_StandardButton___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QMessageBox_StandardButton_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QMessageBox_StandardButton_long,
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
static void QMessageBox_Icon_PythonToCpp_QMessageBox_Icon(PyObject* pyIn, void* cppOut) {
    *((::QMessageBox::Icon*)cppOut) = (::QMessageBox::Icon) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMessageBox_Icon_PythonToCpp_QMessageBox_Icon_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX]))
        return QMessageBox_Icon_PythonToCpp_QMessageBox_Icon;
    return 0;
}
static PyObject* QMessageBox_Icon_CppToPython_QMessageBox_Icon(const void* cppIn) {
    int castCppIn = *((::QMessageBox::Icon*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX], castCppIn);

}

static void QMessageBox_ButtonRole_PythonToCpp_QMessageBox_ButtonRole(PyObject* pyIn, void* cppOut) {
    *((::QMessageBox::ButtonRole*)cppOut) = (::QMessageBox::ButtonRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMessageBox_ButtonRole_PythonToCpp_QMessageBox_ButtonRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX]))
        return QMessageBox_ButtonRole_PythonToCpp_QMessageBox_ButtonRole;
    return 0;
}
static PyObject* QMessageBox_ButtonRole_CppToPython_QMessageBox_ButtonRole(const void* cppIn) {
    int castCppIn = *((::QMessageBox::ButtonRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX], castCppIn);

}

static void QMessageBox_StandardButton_PythonToCpp_QMessageBox_StandardButton(PyObject* pyIn, void* cppOut) {
    *((::QMessageBox::StandardButton*)cppOut) = (::QMessageBox::StandardButton) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QMessageBox_StandardButton_PythonToCpp_QMessageBox_StandardButton_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]))
        return QMessageBox_StandardButton_PythonToCpp_QMessageBox_StandardButton;
    return 0;
}
static PyObject* QMessageBox_StandardButton_CppToPython_QMessageBox_StandardButton(const void* cppIn) {
    int castCppIn = *((::QMessageBox::StandardButton*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX], castCppIn);

}

static void QFlags_QMessageBox_StandardButton__PythonToCpp_QFlags_QMessageBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QMessageBox::StandardButton>*)cppOut) = ::QFlags<QMessageBox::StandardButton>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QMessageBox_StandardButton__PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]))
        return QFlags_QMessageBox_StandardButton__PythonToCpp_QFlags_QMessageBox_StandardButton_;
    return 0;
}
static PyObject* QFlags_QMessageBox_StandardButton__CppToPython_QFlags_QMessageBox_StandardButton_(const void* cppIn) {
    int castCppIn = *((::QFlags<QMessageBox::StandardButton>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]));

}

static void QMessageBox_StandardButton_PythonToCpp_QFlags_QMessageBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QMessageBox::StandardButton>*)cppOut) = ::QFlags<QMessageBox::StandardButton>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QMessageBox_StandardButton_PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX]))
        return QMessageBox_StandardButton_PythonToCpp_QFlags_QMessageBox_StandardButton_;
    return 0;
}
static void number_PythonToCpp_QFlags_QMessageBox_StandardButton_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QMessageBox::StandardButton>*)cppOut) = ::QFlags<QMessageBox::StandardButton>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QMessageBox_StandardButton_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QMessageBox_PythonToCpp_QMessageBox_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QMessageBox_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QMessageBox_PythonToCpp_QMessageBox_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QMessageBox_Type))
        return QMessageBox_PythonToCpp_QMessageBox_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QMessageBox_PTR_CppToPython_QMessageBox(const void* cppIn) {
    return PySide::getWrapperForQObject((::QMessageBox*)cppIn, &Sbk_QMessageBox_Type);

}

void init_QMessageBox(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QMessageBox_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QMessageBox", "QMessageBox*",
        &Sbk_QMessageBox_Type, &Shiboken::callCppDestructor< ::QMessageBox >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDIALOG_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QMessageBox_Type,
        QMessageBox_PythonToCpp_QMessageBox_PTR,
        is_QMessageBox_PythonToCpp_QMessageBox_PTR_Convertible,
        QMessageBox_PTR_CppToPython_QMessageBox);

    Shiboken::Conversions::registerConverterName(converter, "QMessageBox");
    Shiboken::Conversions::registerConverterName(converter, "QMessageBox*");
    Shiboken::Conversions::registerConverterName(converter, "QMessageBox&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMessageBox).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QMessageBoxWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QMessageBox_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QMessageBox_Type, &Sbk_QMessageBoxSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QMessageBox_Type, &Sbk_QMessageBox_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Icon'.
    SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMessageBox_Type,
        "Icon",
        "PySide.QtGui.QMessageBox.Icon",
        "QMessageBox::Icon");
    if (!SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
        &Sbk_QMessageBox_Type, "NoIcon", (long) QMessageBox::NoIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
        &Sbk_QMessageBox_Type, "Information", (long) QMessageBox::Information))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
        &Sbk_QMessageBox_Type, "Warning", (long) QMessageBox::Warning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
        &Sbk_QMessageBox_Type, "Critical", (long) QMessageBox::Critical))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
        &Sbk_QMessageBox_Type, "Question", (long) QMessageBox::Question))
        return ;
    // Register converter for enum 'QMessageBox::Icon'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX],
            QMessageBox_Icon_CppToPython_QMessageBox_Icon);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMessageBox_Icon_PythonToCpp_QMessageBox_Icon,
            is_QMessageBox_Icon_PythonToCpp_QMessageBox_Icon_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_ICON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMessageBox::Icon");
        Shiboken::Conversions::registerConverterName(converter, "Icon");
    }
    // End of 'Icon' enum.

    // Initialization of enum 'ButtonRole'.
    SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMessageBox_Type,
        "ButtonRole",
        "PySide.QtGui.QMessageBox.ButtonRole",
        "QMessageBox::ButtonRole");
    if (!SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "InvalidRole", (long) QMessageBox::InvalidRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "AcceptRole", (long) QMessageBox::AcceptRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "RejectRole", (long) QMessageBox::RejectRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "DestructiveRole", (long) QMessageBox::DestructiveRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "ActionRole", (long) QMessageBox::ActionRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "HelpRole", (long) QMessageBox::HelpRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "YesRole", (long) QMessageBox::YesRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "NoRole", (long) QMessageBox::NoRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "ResetRole", (long) QMessageBox::ResetRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "ApplyRole", (long) QMessageBox::ApplyRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
        &Sbk_QMessageBox_Type, "NRoles", (long) QMessageBox::NRoles))
        return ;
    // Register converter for enum 'QMessageBox::ButtonRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX],
            QMessageBox_ButtonRole_CppToPython_QMessageBox_ButtonRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMessageBox_ButtonRole_PythonToCpp_QMessageBox_ButtonRole,
            is_QMessageBox_ButtonRole_PythonToCpp_QMessageBox_ButtonRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_BUTTONROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMessageBox::ButtonRole");
        Shiboken::Conversions::registerConverterName(converter, "ButtonRole");
    }
    // End of 'ButtonRole' enum.

    // Initialization of enum 'StandardButton'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX] = PySide::QFlags::create("StandardButtons", &SbkPySide_QtGui_QMessageBox_StandardButton_as_number);
    SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QMessageBox_Type,
        "StandardButton",
        "PySide.QtGui.QMessageBox.StandardButton",
        "QMessageBox::StandardButton",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "NoButton", (long) QMessageBox::NoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Ok", (long) QMessageBox::Ok))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Save", (long) QMessageBox::Save))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "SaveAll", (long) QMessageBox::SaveAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Open", (long) QMessageBox::Open))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Yes", (long) QMessageBox::Yes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "YesToAll", (long) QMessageBox::YesToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "No", (long) QMessageBox::No))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "NoToAll", (long) QMessageBox::NoToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Abort", (long) QMessageBox::Abort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Retry", (long) QMessageBox::Retry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Ignore", (long) QMessageBox::Ignore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Close", (long) QMessageBox::Close))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Cancel", (long) QMessageBox::Cancel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Discard", (long) QMessageBox::Discard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Help", (long) QMessageBox::Help))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Apply", (long) QMessageBox::Apply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Reset", (long) QMessageBox::Reset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "RestoreDefaults", (long) QMessageBox::RestoreDefaults))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "FirstButton", (long) QMessageBox::FirstButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "LastButton", (long) QMessageBox::LastButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "YesAll", (long) QMessageBox::YesAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "NoAll", (long) QMessageBox::NoAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Default", (long) QMessageBox::Default))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "Escape", (long) QMessageBox::Escape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "FlagMask", (long) QMessageBox::FlagMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
        &Sbk_QMessageBox_Type, "ButtonMask", (long) QMessageBox::ButtonMask))
        return ;
    // Register converter for enum 'QMessageBox::StandardButton'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX],
            QMessageBox_StandardButton_CppToPython_QMessageBox_StandardButton);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMessageBox_StandardButton_PythonToCpp_QMessageBox_StandardButton,
            is_QMessageBox_StandardButton_PythonToCpp_QMessageBox_StandardButton_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QMESSAGEBOX_STANDARDBUTTON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QMessageBox::StandardButton");
        Shiboken::Conversions::registerConverterName(converter, "StandardButton");
    }
    // Register converter for flag 'QFlags<QMessageBox::StandardButton>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX],
            QFlags_QMessageBox_StandardButton__CppToPython_QFlags_QMessageBox_StandardButton_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QMessageBox_StandardButton_PythonToCpp_QFlags_QMessageBox_StandardButton_,
            is_QMessageBox_StandardButton_PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QMessageBox_StandardButton__PythonToCpp_QFlags_QMessageBox_StandardButton_,
            is_QFlags_QMessageBox_StandardButton__PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QMessageBox_StandardButton_,
            is_number_PythonToCpp_QFlags_QMessageBox_StandardButton__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QMESSAGEBOX_STANDARDBUTTON__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QMessageBox::StandardButton>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StandardButton>");
    }
    // End of 'StandardButton' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QMessageBox_Type, &::QMessageBox::staticMetaObject);

    qRegisterMetaType< ::QMessageBox::Icon >("QMessageBox::Icon");
    qRegisterMetaType< ::QMessageBox::ButtonRole >("QMessageBox::ButtonRole");
    qRegisterMetaType< ::QMessageBox::StandardButton >("QMessageBox::StandardButton");
    qRegisterMetaType< ::QMessageBox::StandardButtons >("QMessageBox::StandardButtons");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QMessageBox_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QMessageBox_Type, &::QMessageBox::staticMetaObject, sizeof(::QMessageBox));
}
