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

#include "qlineedit_wrapper.h"

// Extra includes
#include <QList>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcompleter.h>
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
#include <qlineedit.h>
#include <qlocale.h>
#include <qmargins.h>
#include <qmenu.h>
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
#include <qstyle.h>
#include <qstyleoption.h>
#include <qvalidator.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QLineEditWrapper::QLineEditWrapper(QWidget * parent) : QLineEdit(parent) {
    // ... middle
}

QLineEditWrapper::QLineEditWrapper(const QString & arg__1, QWidget * parent) : QLineEdit(arg__1, parent) {
    // ... middle
}

void QLineEditWrapper::actionEvent(QActionEvent * event)
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

void QLineEditWrapper::changeEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::changeEvent(arg__1);
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

void QLineEditWrapper::childEvent(QChildEvent * arg__1)
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

void QLineEditWrapper::closeEvent(QCloseEvent * event)
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

void QLineEditWrapper::connectNotify(const char * signal)
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

void QLineEditWrapper::contextMenuEvent(QContextMenuEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::contextMenuEvent(arg__1);
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

void QLineEditWrapper::customEvent(QEvent * arg__1)
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

int QLineEditWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::disconnectNotify(const char * signal)
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

void QLineEditWrapper::dragEnterEvent(QDragEnterEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::dragEnterEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], arg__1)
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

void QLineEditWrapper::dragLeaveEvent(QDragLeaveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::dragLeaveEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], e)
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

void QLineEditWrapper::dragMoveEvent(QDragMoveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::dragMoveEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], e)
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

void QLineEditWrapper::dropEvent(QDropEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::dropEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], arg__1)
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

void QLineEditWrapper::enterEvent(QEvent * event)
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

bool QLineEditWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QLineEditWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QLineEditWrapper::focusInEvent(QFocusEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::focusInEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], arg__1)
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

bool QLineEditWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::focusOutEvent(QFocusEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::focusOutEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], arg__1)
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

int QLineEditWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::hideEvent(QHideEvent * event)
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

void QLineEditWrapper::inputMethodEvent(QInputMethodEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::inputMethodEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], arg__1)
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

QVariant QLineEditWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::inputMethodQuery(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::keyPressEvent(QKeyEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::keyPressEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], arg__1)
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

void QLineEditWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QLineEditWrapper::languageChange()
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

void QLineEditWrapper::leaveEvent(QEvent * event)
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

int QLineEditWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QLineEditWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::minimumSizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::mouseDoubleClickEvent(QMouseEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::mouseDoubleClickEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], arg__1)
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

void QLineEditWrapper::mouseMoveEvent(QMouseEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::mouseMoveEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], arg__1)
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

void QLineEditWrapper::mousePressEvent(QMouseEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::mousePressEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], arg__1)
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

void QLineEditWrapper::mouseReleaseEvent(QMouseEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::mouseReleaseEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], arg__1)
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

void QLineEditWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QLineEditWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::paintEvent(QPaintEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::paintEvent(arg__1);
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

void QLineEditWrapper::resizeEvent(QResizeEvent * event)
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

void QLineEditWrapper::setVisible(bool visible)
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

void QLineEditWrapper::showEvent(QShowEvent * event)
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

QSize QLineEditWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLineEdit::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QLineEdit.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QLineEditWrapper::tabletEvent(QTabletEvent * event)
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

void QLineEditWrapper::timerEvent(QTimerEvent * arg__1)
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

void QLineEditWrapper::wheelEvent(QWheelEvent * event)
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

const QMetaObject* QLineEditWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QLineEdit::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QLineEditWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QLineEdit::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QLineEditWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QLineEditWrapper* >(this));
        return QLineEdit::qt_metacast(_clname);
}

QLineEditWrapper::~QLineEditWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QLineEdit_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QLineEdit >()))
        return -1;

    ::QLineEditWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QLineEdit", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QLineEdit(QWidget*)
    // 1: QLineEdit(QString,QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QLineEdit(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QLineEdit(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QLineEdit(QString,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 1; // QLineEdit(QString,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEdit_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QLineEdit(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QLineEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QLineEdit(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QLineEditWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QLineEditWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QLineEdit(const QString & arg__1, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QLineEdit_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QLineEdit(QString,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QLineEditWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QLineEditWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QLineEdit >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QLineEdit_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QLineEdit_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", "unicode, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QLineEdit", overloads);
        return -1;
}

static PyObject* Sbk_QLineEditFunc_alignment(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QLineEdit*>(cppSelf)->alignment();
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

static PyObject* Sbk_QLineEditFunc_backspace(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backspace()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->backspace();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_clear(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QLineEditFunc_completer(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCompleter * cppResult = const_cast<const ::QLineEdit*>(cppSelf)->completer();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_copy(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // copy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QLineEdit*>(cppSelf)->copy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_createStandardContextMenu(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createStandardContextMenu()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = cppSelf->createStandardContextMenu();
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

static PyObject* Sbk_QLineEditFunc_cursorBackward(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorBackward(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorBackward(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:cursorBackward", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: cursorBackward(bool,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // cursorBackward(bool,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // cursorBackward(bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_cursorBackward_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "steps");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorBackward(): got multiple values for keyword argument 'steps'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLineEditFunc_cursorBackward_TypeError;
            }
        }
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // cursorBackward(bool,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cursorBackward(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_cursorBackward_TypeError:
        const char* overloads[] = {"bool, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QLineEdit.cursorBackward", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_cursorForward(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorForward(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorForward(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:cursorForward", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: cursorForward(bool,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // cursorForward(bool,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // cursorForward(bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_cursorForward_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "steps");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QLineEdit.cursorForward(): got multiple values for keyword argument 'steps'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QLineEditFunc_cursorForward_TypeError;
            }
        }
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // cursorForward(bool,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cursorForward(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_cursorForward_TypeError:
        const char* overloads[] = {"bool, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QLineEdit.cursorForward", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_cursorMoveStyle(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorMoveStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CursorMoveStyle cppResult = const_cast<const ::QLineEdit*>(cppSelf)->cursorMoveStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_cursorPosition(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorPosition()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QLineEdit*>(cppSelf)->cursorPosition();
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

static PyObject* Sbk_QLineEditFunc_cursorPositionAt(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cursorPositionAt(QPoint)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // cursorPositionAt(QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_cursorPositionAt_TypeError;

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
            // cursorPositionAt(QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = cppSelf->cursorPositionAt(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineEditFunc_cursorPositionAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.cursorPositionAt", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_cursorRect(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QLineEdit*>(cppSelf)->cursorRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_cursorWordBackward(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cursorWordBackward(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // cursorWordBackward(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_cursorWordBackward_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cursorWordBackward(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cursorWordBackward(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_cursorWordBackward_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.cursorWordBackward", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_cursorWordForward(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cursorWordForward(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // cursorWordForward(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_cursorWordForward_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cursorWordForward(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cursorWordForward(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_cursorWordForward_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.cursorWordForward", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_cut(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cut()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cut();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_del_(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // del()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->del();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_deselect(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deselect()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->deselect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_displayText(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // displayText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLineEdit*>(cppSelf)->displayText();
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

static PyObject* Sbk_QLineEditFunc_dragEnabled(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dragEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->dragEnabled();
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

static PyObject* Sbk_QLineEditFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QDragEnterEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QDragEnterEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragEnterEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QDragEnterEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragEnterEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QDragLeaveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QDragLeaveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragLeaveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QDragLeaveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragLeaveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QDragMoveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QDragMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragMoveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QDragMoveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_echoMode(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // echoMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLineEdit::EchoMode cppResult = const_cast<const ::QLineEdit*>(cppSelf)->echoMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_end(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: end(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // end(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_end_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // end(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->end(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_end_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.end", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QLineEditFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineEditFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.event", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_getTextMargins(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTextMargins(int*,int*,int*,int*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            int a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QLineEdit::getTextMargins(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_hasAcceptableInput(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAcceptableInput()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->hasAcceptableInput();
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

static PyObject* Sbk_QLineEditFunc_hasFrame(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->hasFrame();
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

static PyObject* Sbk_QLineEditFunc_hasSelectedText(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasSelectedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->hasSelectedText();
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

static PyObject* Sbk_QLineEditFunc_home(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: home(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // home(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_home_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // home(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->home(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_home_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.home", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_initStyleOption(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: initStyleOption(QStyleOptionFrame*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONFRAME_IDX], (pyArg)))) {
        overloadId = 0; // initStyleOption(QStyleOptionFrame*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_initStyleOption_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStyleOptionFrame* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // initStyleOption(QStyleOptionFrame*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QLineEdit*>(cppSelf)->initStyleOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_initStyleOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyleOptionFrame", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.initStyleOption", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_inputMask(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // inputMask()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLineEdit*>(cppSelf)->inputMask();
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

static PyObject* Sbk_QLineEditFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QLineEditFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QLineEdit*>(cppSelf)->::QLineEdit::inputMethodQuery(cppArg0) : const_cast<const ::QLineEdit*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QLineEditFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_insert(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insert(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // insert(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_insert_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // insert(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insert(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_insert_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.insert", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_isModified(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isModified()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->isModified();
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

static PyObject* Sbk_QLineEditFunc_isReadOnly(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QLineEditFunc_isRedoAvailable(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isRedoAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->isRedoAvailable();
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

static PyObject* Sbk_QLineEditFunc_isUndoAvailable(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUndoAvailable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QLineEdit*>(cppSelf)->isUndoAvailable();
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

static PyObject* Sbk_QLineEditFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_maxLength(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maxLength()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QLineEdit*>(cppSelf)->maxLength();
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

static PyObject* Sbk_QLineEditFunc_minimumSizeHint(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QLineEdit*>(cppSelf)->::QLineEdit::minimumSizeHint() : const_cast<const ::QLineEdit*>(cppSelf)->minimumSizeHint();
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

static PyObject* Sbk_QLineEditFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_paintEvent(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QLineEdit::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_paste(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paste()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->paste();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_placeholderText(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // placeholderText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLineEdit*>(cppSelf)->placeholderText();
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

static PyObject* Sbk_QLineEditFunc_redo(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // redo()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->redo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_selectAll(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectAll()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->selectAll();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_selectedText(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLineEdit*>(cppSelf)->selectedText();
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

static PyObject* Sbk_QLineEditFunc_selectionStart(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectionStart()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QLineEdit*>(cppSelf)->selectionStart();
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

static PyObject* Sbk_QLineEditFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setAlignment_TypeError;

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

    Sbk_QLineEditFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setCompleter(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompleter(QCompleter*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (pyArg)))) {
        overloadId = 0; // setCompleter(QCompleter*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setCompleter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCompleter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompleter(QCompleter*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompleter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setCompleter_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCompleter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setCompleter", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setCursorMoveStyle(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursorMoveStyle(Qt::CursorMoveStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CURSORMOVESTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setCursorMoveStyle(Qt::CursorMoveStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setCursorMoveStyle_TypeError;

    // Call function/method
    {
        ::Qt::CursorMoveStyle cppArg0 = ((::Qt::CursorMoveStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursorMoveStyle(Qt::CursorMoveStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursorMoveStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setCursorMoveStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CursorMoveStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setCursorMoveStyle", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setCursorPosition(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursorPosition(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCursorPosition(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setCursorPosition_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursorPosition(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursorPosition(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setCursorPosition_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setCursorPosition", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setDragEnabled(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDragEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setDragEnabled_TypeError;

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

    Sbk_QLineEditFunc_setDragEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setDragEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setEchoMode(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEchoMode(QLineEdit::EchoMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setEchoMode(QLineEdit::EchoMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setEchoMode_TypeError;

    // Call function/method
    {
        ::QLineEdit::EchoMode cppArg0 = ((::QLineEdit::EchoMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEchoMode(QLineEdit::EchoMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEchoMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setEchoMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLineEdit.EchoMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setEchoMode", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setFrame(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFrame(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFrame(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setFrame_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFrame(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFrame(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setFrame_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setFrame", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setInputMask(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInputMask(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setInputMask(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setInputMask_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInputMask(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setInputMask(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setInputMask_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setInputMask", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setMaxLength(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaxLength(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setMaxLength(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setMaxLength_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaxLength(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaxLength(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setMaxLength_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setMaxLength", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setModified(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModified(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setModified(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setModified_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModified(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModified(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setModified_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setModified", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setPlaceholderText(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPlaceholderText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPlaceholderText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setPlaceholderText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPlaceholderText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPlaceholderText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setPlaceholderText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setPlaceholderText", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setReadOnly_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setReadOnly(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setReadOnly(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setSelection(PyObject* self, PyObject* args)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSelection", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSelection(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setSelection(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setSelection_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSelection(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelection(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setSelection_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QLineEdit.setSelection", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setText(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setText_TypeError;

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

    Sbk_QLineEditFunc_setText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setText", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setTextMargins(PyObject* self, PyObject* args)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QLineEditFunc_setTextMargins_TypeError;

    if (!PyArg_UnpackTuple(args, "setTextMargins", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setTextMargins(QMargins)
    // 1: setTextMargins(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // setTextMargins(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMARGINS_IDX], (pyArgs[0])))) {
        overloadId = 0; // setTextMargins(QMargins)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setTextMargins_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setTextMargins(const QMargins & margins)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QMargins cppArg0_local = ::QMargins();
            ::QMargins* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMARGINS_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setTextMargins(QMargins)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setTextMargins(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setTextMargins(int left, int top, int right, int bottom)
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
                // setTextMargins(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setTextMargins(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setTextMargins_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMargins", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QLineEdit.setTextMargins", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_setValidator(PyObject* self, PyObject* pyArg)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setValidator(const QValidator*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVALIDATOR_IDX], (pyArg)))) {
        overloadId = 0; // setValidator(const QValidator*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QLineEditFunc_setValidator_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QValidator* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValidator(const QValidator*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setValidator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QLineEditFunc_setValidator_TypeError:
        const char* overloads[] = {"PySide.QtGui.QValidator", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QLineEdit.setValidator", overloads);
        return 0;
}

static PyObject* Sbk_QLineEditFunc_sizeHint(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QLineEdit*>(cppSelf)->::QLineEdit::sizeHint() : const_cast<const ::QLineEdit*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QLineEditFunc_text(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QLineEdit*>(cppSelf)->text();
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

static PyObject* Sbk_QLineEditFunc_textMargins(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textMargins()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMargins cppResult = const_cast<const ::QLineEdit*>(cppSelf)->textMargins();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMARGINS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QLineEditFunc_undo(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // undo()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->undo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QLineEditFunc_validator(PyObject* self)
{
    ::QLineEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QLineEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // validator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QValidator * cppResult = const_cast<const ::QLineEdit*>(cppSelf)->validator();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVALIDATOR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QLineEdit_methods[] = {
    {"alignment", (PyCFunction)Sbk_QLineEditFunc_alignment, METH_NOARGS},
    {"backspace", (PyCFunction)Sbk_QLineEditFunc_backspace, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QLineEditFunc_changeEvent, METH_O},
    {"clear", (PyCFunction)Sbk_QLineEditFunc_clear, METH_NOARGS},
    {"completer", (PyCFunction)Sbk_QLineEditFunc_completer, METH_NOARGS},
    {"contextMenuEvent", (PyCFunction)Sbk_QLineEditFunc_contextMenuEvent, METH_O},
    {"copy", (PyCFunction)Sbk_QLineEditFunc_copy, METH_NOARGS},
    {"createStandardContextMenu", (PyCFunction)Sbk_QLineEditFunc_createStandardContextMenu, METH_NOARGS},
    {"cursorBackward", (PyCFunction)Sbk_QLineEditFunc_cursorBackward, METH_VARARGS|METH_KEYWORDS},
    {"cursorForward", (PyCFunction)Sbk_QLineEditFunc_cursorForward, METH_VARARGS|METH_KEYWORDS},
    {"cursorMoveStyle", (PyCFunction)Sbk_QLineEditFunc_cursorMoveStyle, METH_NOARGS},
    {"cursorPosition", (PyCFunction)Sbk_QLineEditFunc_cursorPosition, METH_NOARGS},
    {"cursorPositionAt", (PyCFunction)Sbk_QLineEditFunc_cursorPositionAt, METH_O},
    {"cursorRect", (PyCFunction)Sbk_QLineEditFunc_cursorRect, METH_NOARGS},
    {"cursorWordBackward", (PyCFunction)Sbk_QLineEditFunc_cursorWordBackward, METH_O},
    {"cursorWordForward", (PyCFunction)Sbk_QLineEditFunc_cursorWordForward, METH_O},
    {"cut", (PyCFunction)Sbk_QLineEditFunc_cut, METH_NOARGS},
    {"del_", (PyCFunction)Sbk_QLineEditFunc_del_, METH_NOARGS},
    {"deselect", (PyCFunction)Sbk_QLineEditFunc_deselect, METH_NOARGS},
    {"displayText", (PyCFunction)Sbk_QLineEditFunc_displayText, METH_NOARGS},
    {"dragEnabled", (PyCFunction)Sbk_QLineEditFunc_dragEnabled, METH_NOARGS},
    {"dragEnterEvent", (PyCFunction)Sbk_QLineEditFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QLineEditFunc_dragLeaveEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QLineEditFunc_dragMoveEvent, METH_O},
    {"dropEvent", (PyCFunction)Sbk_QLineEditFunc_dropEvent, METH_O},
    {"echoMode", (PyCFunction)Sbk_QLineEditFunc_echoMode, METH_NOARGS},
    {"end", (PyCFunction)Sbk_QLineEditFunc_end, METH_O},
    {"event", (PyCFunction)Sbk_QLineEditFunc_event, METH_O},
    {"focusInEvent", (PyCFunction)Sbk_QLineEditFunc_focusInEvent, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QLineEditFunc_focusOutEvent, METH_O},
    {"getTextMargins", (PyCFunction)Sbk_QLineEditFunc_getTextMargins, METH_NOARGS},
    {"hasAcceptableInput", (PyCFunction)Sbk_QLineEditFunc_hasAcceptableInput, METH_NOARGS},
    {"hasFrame", (PyCFunction)Sbk_QLineEditFunc_hasFrame, METH_NOARGS},
    {"hasSelectedText", (PyCFunction)Sbk_QLineEditFunc_hasSelectedText, METH_NOARGS},
    {"home", (PyCFunction)Sbk_QLineEditFunc_home, METH_O},
    {"initStyleOption", (PyCFunction)Sbk_QLineEditFunc_initStyleOption, METH_O},
    {"inputMask", (PyCFunction)Sbk_QLineEditFunc_inputMask, METH_NOARGS},
    {"inputMethodEvent", (PyCFunction)Sbk_QLineEditFunc_inputMethodEvent, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QLineEditFunc_inputMethodQuery, METH_O},
    {"insert", (PyCFunction)Sbk_QLineEditFunc_insert, METH_O},
    {"isModified", (PyCFunction)Sbk_QLineEditFunc_isModified, METH_NOARGS},
    {"isReadOnly", (PyCFunction)Sbk_QLineEditFunc_isReadOnly, METH_NOARGS},
    {"isRedoAvailable", (PyCFunction)Sbk_QLineEditFunc_isRedoAvailable, METH_NOARGS},
    {"isUndoAvailable", (PyCFunction)Sbk_QLineEditFunc_isUndoAvailable, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QLineEditFunc_keyPressEvent, METH_O},
    {"maxLength", (PyCFunction)Sbk_QLineEditFunc_maxLength, METH_NOARGS},
    {"minimumSizeHint", (PyCFunction)Sbk_QLineEditFunc_minimumSizeHint, METH_NOARGS},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QLineEditFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QLineEditFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QLineEditFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QLineEditFunc_mouseReleaseEvent, METH_O},
    {"paintEvent", (PyCFunction)Sbk_QLineEditFunc_paintEvent, METH_O},
    {"paste", (PyCFunction)Sbk_QLineEditFunc_paste, METH_NOARGS},
    {"placeholderText", (PyCFunction)Sbk_QLineEditFunc_placeholderText, METH_NOARGS},
    {"redo", (PyCFunction)Sbk_QLineEditFunc_redo, METH_NOARGS},
    {"selectAll", (PyCFunction)Sbk_QLineEditFunc_selectAll, METH_NOARGS},
    {"selectedText", (PyCFunction)Sbk_QLineEditFunc_selectedText, METH_NOARGS},
    {"selectionStart", (PyCFunction)Sbk_QLineEditFunc_selectionStart, METH_NOARGS},
    {"setAlignment", (PyCFunction)Sbk_QLineEditFunc_setAlignment, METH_O},
    {"setCompleter", (PyCFunction)Sbk_QLineEditFunc_setCompleter, METH_O},
    {"setCursorMoveStyle", (PyCFunction)Sbk_QLineEditFunc_setCursorMoveStyle, METH_O},
    {"setCursorPosition", (PyCFunction)Sbk_QLineEditFunc_setCursorPosition, METH_O},
    {"setDragEnabled", (PyCFunction)Sbk_QLineEditFunc_setDragEnabled, METH_O},
    {"setEchoMode", (PyCFunction)Sbk_QLineEditFunc_setEchoMode, METH_O},
    {"setFrame", (PyCFunction)Sbk_QLineEditFunc_setFrame, METH_O},
    {"setInputMask", (PyCFunction)Sbk_QLineEditFunc_setInputMask, METH_O},
    {"setMaxLength", (PyCFunction)Sbk_QLineEditFunc_setMaxLength, METH_O},
    {"setModified", (PyCFunction)Sbk_QLineEditFunc_setModified, METH_O},
    {"setPlaceholderText", (PyCFunction)Sbk_QLineEditFunc_setPlaceholderText, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QLineEditFunc_setReadOnly, METH_O},
    {"setSelection", (PyCFunction)Sbk_QLineEditFunc_setSelection, METH_VARARGS},
    {"setText", (PyCFunction)Sbk_QLineEditFunc_setText, METH_O},
    {"setTextMargins", (PyCFunction)Sbk_QLineEditFunc_setTextMargins, METH_VARARGS},
    {"setValidator", (PyCFunction)Sbk_QLineEditFunc_setValidator, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QLineEditFunc_sizeHint, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QLineEditFunc_text, METH_NOARGS},
    {"textMargins", (PyCFunction)Sbk_QLineEditFunc_textMargins, METH_NOARGS},
    {"undo", (PyCFunction)Sbk_QLineEditFunc_undo, METH_NOARGS},
    {"validator", (PyCFunction)Sbk_QLineEditFunc_validator, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QLineEdit_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QLineEdit_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QLineEditSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QLineEdit* me = reinterpret_cast< ::QLineEdit*>(obj);
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
static SbkObjectType Sbk_QLineEdit_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QLineEdit",
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
    /*tp_traverse*/         Sbk_QLineEdit_traverse,
    /*tp_clear*/            Sbk_QLineEdit_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QLineEdit_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QLineEdit_Init,
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

static void* Sbk_QLineEdit_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QLineEdit*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QLineEdit*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QLineEdit_EchoMode_PythonToCpp_QLineEdit_EchoMode(PyObject* pyIn, void* cppOut) {
    *((::QLineEdit::EchoMode*)cppOut) = (::QLineEdit::EchoMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QLineEdit_EchoMode_PythonToCpp_QLineEdit_EchoMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX]))
        return QLineEdit_EchoMode_PythonToCpp_QLineEdit_EchoMode;
    return 0;
}
static PyObject* QLineEdit_EchoMode_CppToPython_QLineEdit_EchoMode(const void* cppIn) {
    int castCppIn = *((::QLineEdit::EchoMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QLineEdit_PythonToCpp_QLineEdit_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QLineEdit_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QLineEdit_PythonToCpp_QLineEdit_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QLineEdit_Type))
        return QLineEdit_PythonToCpp_QLineEdit_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QLineEdit_PTR_CppToPython_QLineEdit(const void* cppIn) {
    return PySide::getWrapperForQObject((::QLineEdit*)cppIn, &Sbk_QLineEdit_Type);

}

void init_QLineEdit(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QLineEdit_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QLineEdit", "QLineEdit*",
        &Sbk_QLineEdit_Type, &Shiboken::callCppDestructor< ::QLineEdit >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QLineEdit_Type,
        QLineEdit_PythonToCpp_QLineEdit_PTR,
        is_QLineEdit_PythonToCpp_QLineEdit_PTR_Convertible,
        QLineEdit_PTR_CppToPython_QLineEdit);

    Shiboken::Conversions::registerConverterName(converter, "QLineEdit");
    Shiboken::Conversions::registerConverterName(converter, "QLineEdit*");
    Shiboken::Conversions::registerConverterName(converter, "QLineEdit&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLineEdit).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QLineEditWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QLineEdit_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QLineEdit_Type, &Sbk_QLineEditSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QLineEdit_Type, &Sbk_QLineEdit_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'EchoMode'.
    SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QLineEdit_Type,
        "EchoMode",
        "PySide.QtGui.QLineEdit.EchoMode",
        "QLineEdit::EchoMode");
    if (!SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX],
        &Sbk_QLineEdit_Type, "Normal", (long) QLineEdit::Normal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX],
        &Sbk_QLineEdit_Type, "NoEcho", (long) QLineEdit::NoEcho))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX],
        &Sbk_QLineEdit_Type, "Password", (long) QLineEdit::Password))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX],
        &Sbk_QLineEdit_Type, "PasswordEchoOnEdit", (long) QLineEdit::PasswordEchoOnEdit))
        return ;
    // Register converter for enum 'QLineEdit::EchoMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX],
            QLineEdit_EchoMode_CppToPython_QLineEdit_EchoMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QLineEdit_EchoMode_PythonToCpp_QLineEdit_EchoMode,
            is_QLineEdit_EchoMode_PythonToCpp_QLineEdit_EchoMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QLINEEDIT_ECHOMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QLineEdit::EchoMode");
        Shiboken::Conversions::registerConverterName(converter, "EchoMode");
    }
    // End of 'EchoMode' enum.

    PySide::Signal::registerSignals(&Sbk_QLineEdit_Type, &::QLineEdit::staticMetaObject);

    qRegisterMetaType< ::QLineEdit::EchoMode >("QLineEdit::EchoMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QLineEdit_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QLineEdit_Type, &::QLineEdit::staticMetaObject, sizeof(::QLineEdit));
}
