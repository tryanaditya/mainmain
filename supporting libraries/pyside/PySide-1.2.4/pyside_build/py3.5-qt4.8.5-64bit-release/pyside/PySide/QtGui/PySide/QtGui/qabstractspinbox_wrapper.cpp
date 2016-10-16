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

#include "qabstractspinbox_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractspinbox.h>
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
#include <qlineedit.h>
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
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QAbstractSpinBoxWrapper::QAbstractSpinBoxWrapper(QWidget * parent) : QAbstractSpinBox(parent) {
    // ... middle
}

void QAbstractSpinBoxWrapper::actionEvent(QActionEvent * event)
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

void QAbstractSpinBoxWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::changeEvent(event);
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

void QAbstractSpinBoxWrapper::childEvent(QChildEvent * arg__1)
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

void QAbstractSpinBoxWrapper::clear()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clear"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::clear();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QAbstractSpinBoxWrapper::closeEvent(QCloseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::closeEvent(event);
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

void QAbstractSpinBoxWrapper::connectNotify(const char * signal)
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

void QAbstractSpinBoxWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::contextMenuEvent(event);
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

void QAbstractSpinBoxWrapper::customEvent(QEvent * arg__1)
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

int QAbstractSpinBoxWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::disconnectNotify(const char * signal)
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

void QAbstractSpinBoxWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void QAbstractSpinBoxWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void QAbstractSpinBoxWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void QAbstractSpinBoxWrapper::dropEvent(QDropEvent * event)
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

void QAbstractSpinBoxWrapper::enterEvent(QEvent * event)
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

bool QAbstractSpinBoxWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QAbstractSpinBoxWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QAbstractSpinBoxWrapper::fixup(QString & input) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fixup"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractSpinBox::fixup(input);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &input)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }

}

void QAbstractSpinBoxWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::focusInEvent(event);
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

bool QAbstractSpinBoxWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::focusOutEvent(event);
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

int QAbstractSpinBoxWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::hideEvent(QHideEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hideEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::hideEvent(event);
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

void QAbstractSpinBoxWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant QAbstractSpinBoxWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::inputMethodQuery(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::keyPressEvent(event);
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

void QAbstractSpinBoxWrapper::keyReleaseEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::keyReleaseEvent(event);
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

void QAbstractSpinBoxWrapper::languageChange()
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

void QAbstractSpinBoxWrapper::leaveEvent(QEvent * event)
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

int QAbstractSpinBoxWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QAbstractSpinBoxWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::minimumSizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void QAbstractSpinBoxWrapper::mouseMoveEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::mouseMoveEvent(event);
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

void QAbstractSpinBoxWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::mousePressEvent(event);
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

void QAbstractSpinBoxWrapper::mouseReleaseEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::mouseReleaseEvent(event);
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

void QAbstractSpinBoxWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QAbstractSpinBoxWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::paintEvent(event);
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

void QAbstractSpinBoxWrapper::resizeEvent(QResizeEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::resizeEvent(event);
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

void QAbstractSpinBoxWrapper::setVisible(bool visible)
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

void QAbstractSpinBoxWrapper::showEvent(QShowEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::showEvent(event);
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

QSize QAbstractSpinBoxWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::stepBy(int steps)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stepBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::stepBy(steps);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        steps
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QFlags<QAbstractSpinBox::StepEnabledFlag> QAbstractSpinBoxWrapper::stepEnabled() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stepEnabled"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::stepEnabled();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAbstractSpinBox.stepEnabled", Shiboken::SbkType< QFlags<QAbstractSpinBox::StepEnabledFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    }
    ::QFlags<QAbstractSpinBox::StepEnabledFlag> cppResult = ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QAbstractSpinBoxWrapper::tabletEvent(QTabletEvent * event)
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

void QAbstractSpinBoxWrapper::timerEvent(QTimerEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::timerEvent(event);
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

QValidator::State QAbstractSpinBoxWrapper::validate(QString & input, int & pos) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QValidator::State)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "validate"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QAbstractSpinBox::validate(input, pos);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &input),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &pos)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QValidator::State)0);
    }
    // Begin code injection

    // TEMPLATE - validator_conversionrule - START
    QValidator::State cppResult;

    if (PySequence_Check(pyResult)) {
    Shiboken::AutoDecRef seq(PySequence_Fast(pyResult, 0));
    int size = PySequence_Fast_GET_SIZE(seq.object());

    if (size > 1) {
        if (Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(seq.object(), 1)))
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(seq.object(), 1), &(input));
        else
            qWarning("QAbstractSpinBox::validate: Second tuple element is not convertible to unicode.");
    }

    if (size > 2) {
        if (Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2)))
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2), &(pos));
        else
            qWarning("QAbstractSpinBox::validate: Second tuple element is not convertible to int.");
    }
    pyResult = PySequence_Fast_GET_ITEM(seq.object(), 0);
    Py_INCREF(pyResult); // we need to incref, because "pyResult = ..." will decref the tuple and the tuple will be decrefed again at the end of this scope.
    }

    // check retrun value
    if (Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), pyResult)) {
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), pyResult, &(cppResult));
    } else {
    PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.",
                "QValidator.validate",
                "PySide.QtGui.QValidator.State, (PySide.QtGui.QValidator.State,), (PySide.QtGui.QValidator.State, unicode) or (PySide.QtGui.QValidator.State, unicode, int)",
                pyResult->ob_type->tp_name);
    return QValidator::State();
    }
    // TEMPLATE - validator_conversionrule - END

    // End of code injection

    return cppResult;
}

void QAbstractSpinBoxWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractSpinBox::wheelEvent(event);
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

const QMetaObject* QAbstractSpinBoxWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAbstractSpinBox::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QAbstractSpinBoxWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAbstractSpinBox::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QAbstractSpinBoxWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QAbstractSpinBoxWrapper* >(this));
        return QAbstractSpinBox::qt_metacast(_clname);
}

QAbstractSpinBoxWrapper::~QAbstractSpinBoxWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAbstractSpinBox_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAbstractSpinBox >()))
        return -1;

    ::QAbstractSpinBoxWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QAbstractSpinBox", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QAbstractSpinBox(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QAbstractSpinBox(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAbstractSpinBox(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBox_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAbstractSpinBox(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QAbstractSpinBox_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QAbstractSpinBox(QWidget*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QAbstractSpinBoxWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QAbstractSpinBoxWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAbstractSpinBox >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAbstractSpinBox_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QAbstractSpinBox_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractSpinBox", overloads);
        return -1;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_alignment(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->alignment();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_buttonSymbols(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttonSymbols()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSpinBox::ButtonSymbols cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->buttonSymbols();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_clear(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::clear() : cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_closeEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: closeEvent(QCloseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // closeEvent(QCloseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_closeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCloseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeEvent(QCloseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::closeEvent(cppArg0) : cppSelf->closeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_closeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCloseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.closeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_correctionMode(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // correctionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractSpinBox::CorrectionMode cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->correctionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSpinBoxFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.event", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_fixup(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fixup(QString&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fixup(QString&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_fixup_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fixup(QString&)const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSpinBox*>(cppSelf)->::QAbstractSpinBox::fixup(cppArg0) : const_cast<const ::QAbstractSpinBox*>(cppSelf)->fixup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            // Begin code injection

            // TEMPLATE - return_QString - START
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg0);
            // TEMPLATE - return_QString - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSpinBoxFunc_fixup_TypeError:
        const char* overloads[] = {"PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.fixup", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_hasAcceptableInput(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasAcceptableInput()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->hasAcceptableInput();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_hasFrame(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->hasFrame();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_hideEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hideEvent(QHideEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QHIDEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // hideEvent(QHideEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_hideEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QHideEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hideEvent(QHideEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::hideEvent(cppArg0) : cppSelf->hideEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_hideEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QHideEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.hideEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_initStyleOption(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: initStyleOption(QStyleOptionSpinBox*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSPINBOX_IDX], (pyArg)))) {
        overloadId = 0; // initStyleOption(QStyleOptionSpinBox*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_initStyleOption_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStyleOptionSpinBox* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // initStyleOption(QStyleOptionSpinBox*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QAbstractSpinBox*>(cppSelf)->initStyleOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_initStyleOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyleOptionSpinBox", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.initStyleOption", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSpinBox*>(cppSelf)->::QAbstractSpinBox::inputMethodQuery(cppArg0) : const_cast<const ::QAbstractSpinBox*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSpinBoxFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_interpretText(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // interpretText()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->interpretText();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_isAccelerated(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isAccelerated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->isAccelerated();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_isReadOnly(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_keyReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyReleaseEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_keyboardTracking(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // keyboardTracking()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->keyboardTracking();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_lineEdit(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineEdit()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLineEdit * cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->lineEdit();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_minimumSizeHint(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSpinBox*>(cppSelf)->::QAbstractSpinBox::minimumSizeHint() : const_cast<const ::QAbstractSpinBox*>(cppSelf)->minimumSizeHint();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_paintEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_resizeEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QResizeEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_selectAll(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QAbstractSpinBoxFunc_setAccelerated(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccelerated(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAccelerated(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setAccelerated_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccelerated(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccelerated(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setAccelerated_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setAccelerated", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setAlignment(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setAlignment_TypeError;

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

    Sbk_QAbstractSpinBoxFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setButtonSymbols(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setButtonSymbols(QAbstractSpinBox::ButtonSymbols)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX]), (pyArg)))) {
        overloadId = 0; // setButtonSymbols(QAbstractSpinBox::ButtonSymbols)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setButtonSymbols_TypeError;

    // Call function/method
    {
        ::QAbstractSpinBox::ButtonSymbols cppArg0 = ((::QAbstractSpinBox::ButtonSymbols)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setButtonSymbols(QAbstractSpinBox::ButtonSymbols)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setButtonSymbols(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setButtonSymbols_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractSpinBox.ButtonSymbols", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setButtonSymbols", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setCorrectionMode(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCorrectionMode(QAbstractSpinBox::CorrectionMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setCorrectionMode(QAbstractSpinBox::CorrectionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setCorrectionMode_TypeError;

    // Call function/method
    {
        ::QAbstractSpinBox::CorrectionMode cppArg0 = ((::QAbstractSpinBox::CorrectionMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCorrectionMode(QAbstractSpinBox::CorrectionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCorrectionMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setCorrectionMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractSpinBox.CorrectionMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setCorrectionMode", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setFrame(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFrame(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFrame(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setFrame_TypeError;

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

    Sbk_QAbstractSpinBoxFunc_setFrame_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setFrame", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setKeyboardTracking(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setKeyboardTracking(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setKeyboardTracking(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setKeyboardTracking_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setKeyboardTracking(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setKeyboardTracking(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setKeyboardTracking_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setKeyboardTracking", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setLineEdit(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLineEdit(QLineEdit*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLINEEDIT_IDX], (pyArg)))) {
        overloadId = 0; // setLineEdit(QLineEdit*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setLineEdit_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLineEdit* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLineEdit(QLineEdit*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLineEdit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setLineEdit_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLineEdit", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setLineEdit", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setReadOnly_TypeError;

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

    Sbk_QAbstractSpinBoxFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setSpecialValueText(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpecialValueText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setSpecialValueText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setSpecialValueText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSpecialValueText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSpecialValueText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setSpecialValueText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setSpecialValueText", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_setWrapping(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWrapping(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWrapping(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_setWrapping_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWrapping(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWrapping(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_setWrapping_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.setWrapping", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_showEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: showEvent(QShowEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], (pyArg)))) {
        overloadId = 0; // showEvent(QShowEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_showEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QShowEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // showEvent(QShowEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::showEvent(cppArg0) : cppSelf->showEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_showEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QShowEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.showEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_sizeHint(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSpinBox*>(cppSelf)->::QAbstractSpinBox::sizeHint() : const_cast<const ::QAbstractSpinBox*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_specialValueText(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // specialValueText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->specialValueText();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_stepBy(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stepBy(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // stepBy(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_stepBy_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // stepBy(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::stepBy(cppArg0) : cppSelf->stepBy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_stepBy_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.stepBy", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_stepDown(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stepDown()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stepDown();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_stepEnabled(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stepEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QAbstractSpinBox::StepEnabledFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QAbstractSpinBox*>(cppSelf)->::QAbstractSpinBox::stepEnabled() : const_cast<const ::QAbstractSpinBox*>(cppSelf)->stepEnabled();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_stepUp(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stepUp()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stepUp();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_text(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->text();
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

static PyObject* Sbk_QAbstractSpinBoxFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_validate(PyObject* self, PyObject* args)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "validate", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: validate(QString&,int&)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // validate(QString&,int&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_validate_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // validate(QString&,int&)const


            // Begin code injection

            // TEMPLATE - return_tuple_QValidator_QString_int - START
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QValidator::State retval_ = QValidator::State((Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::validate(cppArg0, cppArg1) : cppSelf->validate(cppArg0, cppArg1)));
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg0));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppArg1));
            // TEMPLATE - return_tuple_QValidator_QString_int - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QAbstractSpinBoxFunc_validate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QString, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAbstractSpinBox.validate", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAbstractSpinBoxFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAbstractSpinBox::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QAbstractSpinBoxFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAbstractSpinBox.wheelEvent", overloads);
        return 0;
}

static PyObject* Sbk_QAbstractSpinBoxFunc_wrapping(PyObject* self)
{
    ::QAbstractSpinBox* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAbstractSpinBox*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wrapping()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAbstractSpinBox*>(cppSelf)->wrapping();
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

static PyMethodDef Sbk_QAbstractSpinBox_methods[] = {
    {"alignment", (PyCFunction)Sbk_QAbstractSpinBoxFunc_alignment, METH_NOARGS},
    {"buttonSymbols", (PyCFunction)Sbk_QAbstractSpinBoxFunc_buttonSymbols, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_changeEvent, METH_O},
    {"clear", (PyCFunction)Sbk_QAbstractSpinBoxFunc_clear, METH_NOARGS},
    {"closeEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_closeEvent, METH_O},
    {"contextMenuEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_contextMenuEvent, METH_O},
    {"correctionMode", (PyCFunction)Sbk_QAbstractSpinBoxFunc_correctionMode, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QAbstractSpinBoxFunc_event, METH_O},
    {"fixup", (PyCFunction)Sbk_QAbstractSpinBoxFunc_fixup, METH_O},
    {"focusInEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_focusInEvent, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_focusOutEvent, METH_O},
    {"hasAcceptableInput", (PyCFunction)Sbk_QAbstractSpinBoxFunc_hasAcceptableInput, METH_NOARGS},
    {"hasFrame", (PyCFunction)Sbk_QAbstractSpinBoxFunc_hasFrame, METH_NOARGS},
    {"hideEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_hideEvent, METH_O},
    {"initStyleOption", (PyCFunction)Sbk_QAbstractSpinBoxFunc_initStyleOption, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QAbstractSpinBoxFunc_inputMethodQuery, METH_O},
    {"interpretText", (PyCFunction)Sbk_QAbstractSpinBoxFunc_interpretText, METH_NOARGS},
    {"isAccelerated", (PyCFunction)Sbk_QAbstractSpinBoxFunc_isAccelerated, METH_NOARGS},
    {"isReadOnly", (PyCFunction)Sbk_QAbstractSpinBoxFunc_isReadOnly, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_keyReleaseEvent, METH_O},
    {"keyboardTracking", (PyCFunction)Sbk_QAbstractSpinBoxFunc_keyboardTracking, METH_NOARGS},
    {"lineEdit", (PyCFunction)Sbk_QAbstractSpinBoxFunc_lineEdit, METH_NOARGS},
    {"minimumSizeHint", (PyCFunction)Sbk_QAbstractSpinBoxFunc_minimumSizeHint, METH_NOARGS},
    {"mouseMoveEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_mouseReleaseEvent, METH_O},
    {"paintEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_paintEvent, METH_O},
    {"resizeEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_resizeEvent, METH_O},
    {"selectAll", (PyCFunction)Sbk_QAbstractSpinBoxFunc_selectAll, METH_NOARGS},
    {"setAccelerated", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setAccelerated, METH_O},
    {"setAlignment", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setAlignment, METH_O},
    {"setButtonSymbols", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setButtonSymbols, METH_O},
    {"setCorrectionMode", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setCorrectionMode, METH_O},
    {"setFrame", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setFrame, METH_O},
    {"setKeyboardTracking", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setKeyboardTracking, METH_O},
    {"setLineEdit", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setLineEdit, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setReadOnly, METH_O},
    {"setSpecialValueText", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setSpecialValueText, METH_O},
    {"setWrapping", (PyCFunction)Sbk_QAbstractSpinBoxFunc_setWrapping, METH_O},
    {"showEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_showEvent, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QAbstractSpinBoxFunc_sizeHint, METH_NOARGS},
    {"specialValueText", (PyCFunction)Sbk_QAbstractSpinBoxFunc_specialValueText, METH_NOARGS},
    {"stepBy", (PyCFunction)Sbk_QAbstractSpinBoxFunc_stepBy, METH_O},
    {"stepDown", (PyCFunction)Sbk_QAbstractSpinBoxFunc_stepDown, METH_NOARGS},
    {"stepEnabled", (PyCFunction)Sbk_QAbstractSpinBoxFunc_stepEnabled, METH_NOARGS},
    {"stepUp", (PyCFunction)Sbk_QAbstractSpinBoxFunc_stepUp, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QAbstractSpinBoxFunc_text, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_timerEvent, METH_O},
    {"validate", (PyCFunction)Sbk_QAbstractSpinBoxFunc_validate, METH_VARARGS},
    {"wheelEvent", (PyCFunction)Sbk_QAbstractSpinBoxFunc_wheelEvent, METH_O},
    {"wrapping", (PyCFunction)Sbk_QAbstractSpinBoxFunc_wrapping, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAbstractSpinBox_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAbstractSpinBox_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QAbstractSpinBoxSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QAbstractSpinBox* me = reinterpret_cast< ::QAbstractSpinBox*>(obj);
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
static SbkObjectType Sbk_QAbstractSpinBox_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QAbstractSpinBox",
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
    /*tp_traverse*/         Sbk_QAbstractSpinBox_traverse,
    /*tp_clear*/            Sbk_QAbstractSpinBox_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAbstractSpinBox_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAbstractSpinBox_Init,
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

static void* Sbk_QAbstractSpinBox_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAbstractSpinBox*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QAbstractSpinBox*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox::StepEnabled cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyLong_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyInt_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox::StepEnabled cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyLong_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyInt_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox::StepEnabled cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyLong_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QAbstractSpinBox::StepEnabled)PyInt_AsLong(self);
    cppArg = (QAbstractSpinBox::StepEnabled)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QAbstractSpinBox::StepEnabled cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), self, &cppSelf);
    ::QAbstractSpinBox::StepEnabled cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag_long,
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
static void QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QAbstractSpinBox_StepEnabledFlag(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSpinBox::StepEnabledFlag*)cppOut) = (::QAbstractSpinBox::StepEnabledFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QAbstractSpinBox_StepEnabledFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX]))
        return QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QAbstractSpinBox_StepEnabledFlag;
    return 0;
}
static PyObject* QAbstractSpinBox_StepEnabledFlag_CppToPython_QAbstractSpinBox_StepEnabledFlag(const void* cppIn) {
    int castCppIn = *((::QAbstractSpinBox::StepEnabledFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX], castCppIn);

}

static void QFlags_QAbstractSpinBox_StepEnabledFlag__PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractSpinBox::StepEnabledFlag>*)cppOut) = ::QFlags<QAbstractSpinBox::StepEnabledFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QAbstractSpinBox_StepEnabledFlag__PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]))
        return QFlags_QAbstractSpinBox_StepEnabledFlag__PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_;
    return 0;
}
static PyObject* QFlags_QAbstractSpinBox_StepEnabledFlag__CppToPython_QFlags_QAbstractSpinBox_StepEnabledFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QAbstractSpinBox::StepEnabledFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]));

}

static void QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QAbstractSpinBox::StepEnabledFlag>*)cppOut) = ::QFlags<QAbstractSpinBox::StepEnabledFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX]))
        return QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QAbstractSpinBox::StepEnabledFlag>*)cppOut) = ::QFlags<QAbstractSpinBox::StepEnabledFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_;
    return 0;
}
static void QAbstractSpinBox_ButtonSymbols_PythonToCpp_QAbstractSpinBox_ButtonSymbols(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSpinBox::ButtonSymbols*)cppOut) = (::QAbstractSpinBox::ButtonSymbols) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSpinBox_ButtonSymbols_PythonToCpp_QAbstractSpinBox_ButtonSymbols_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX]))
        return QAbstractSpinBox_ButtonSymbols_PythonToCpp_QAbstractSpinBox_ButtonSymbols;
    return 0;
}
static PyObject* QAbstractSpinBox_ButtonSymbols_CppToPython_QAbstractSpinBox_ButtonSymbols(const void* cppIn) {
    int castCppIn = *((::QAbstractSpinBox::ButtonSymbols*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX], castCppIn);

}

static void QAbstractSpinBox_CorrectionMode_PythonToCpp_QAbstractSpinBox_CorrectionMode(PyObject* pyIn, void* cppOut) {
    *((::QAbstractSpinBox::CorrectionMode*)cppOut) = (::QAbstractSpinBox::CorrectionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAbstractSpinBox_CorrectionMode_PythonToCpp_QAbstractSpinBox_CorrectionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX]))
        return QAbstractSpinBox_CorrectionMode_PythonToCpp_QAbstractSpinBox_CorrectionMode;
    return 0;
}
static PyObject* QAbstractSpinBox_CorrectionMode_CppToPython_QAbstractSpinBox_CorrectionMode(const void* cppIn) {
    int castCppIn = *((::QAbstractSpinBox::CorrectionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAbstractSpinBox_PythonToCpp_QAbstractSpinBox_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAbstractSpinBox_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAbstractSpinBox_PythonToCpp_QAbstractSpinBox_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAbstractSpinBox_Type))
        return QAbstractSpinBox_PythonToCpp_QAbstractSpinBox_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAbstractSpinBox_PTR_CppToPython_QAbstractSpinBox(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAbstractSpinBox*)cppIn, &Sbk_QAbstractSpinBox_Type);

}

void init_QAbstractSpinBox(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAbstractSpinBox_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAbstractSpinBox", "QAbstractSpinBox*",
        &Sbk_QAbstractSpinBox_Type, &Shiboken::callCppDestructor< ::QAbstractSpinBox >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAbstractSpinBox_Type,
        QAbstractSpinBox_PythonToCpp_QAbstractSpinBox_PTR,
        is_QAbstractSpinBox_PythonToCpp_QAbstractSpinBox_PTR_Convertible,
        QAbstractSpinBox_PTR_CppToPython_QAbstractSpinBox);

    Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox*");
    Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractSpinBox).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAbstractSpinBoxWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QAbstractSpinBox_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QAbstractSpinBox_Type, &Sbk_QAbstractSpinBoxSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAbstractSpinBox_Type, &Sbk_QAbstractSpinBox_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'StepEnabledFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX] = PySide::QFlags::create("StepEnabled", &SbkPySide_QtGui_QAbstractSpinBox_StepEnabledFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSpinBox_Type,
        "StepEnabledFlag",
        "PySide.QtGui.QAbstractSpinBox.StepEnabledFlag",
        "QAbstractSpinBox::StepEnabledFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX],
        &Sbk_QAbstractSpinBox_Type, "StepNone", (long) QAbstractSpinBox::StepNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX],
        &Sbk_QAbstractSpinBox_Type, "StepUpEnabled", (long) QAbstractSpinBox::StepUpEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX],
        &Sbk_QAbstractSpinBox_Type, "StepDownEnabled", (long) QAbstractSpinBox::StepDownEnabled))
        return ;
    // Register converter for enum 'QAbstractSpinBox::StepEnabledFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX],
            QAbstractSpinBox_StepEnabledFlag_CppToPython_QAbstractSpinBox_StepEnabledFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QAbstractSpinBox_StepEnabledFlag,
            is_QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QAbstractSpinBox_StepEnabledFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_STEPENABLEDFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox::StepEnabledFlag");
        Shiboken::Conversions::registerConverterName(converter, "StepEnabledFlag");
    }
    // Register converter for flag 'QFlags<QAbstractSpinBox::StepEnabledFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX],
            QFlags_QAbstractSpinBox_StepEnabledFlag__CppToPython_QFlags_QAbstractSpinBox_StepEnabledFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_,
            is_QAbstractSpinBox_StepEnabledFlag_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QAbstractSpinBox_StepEnabledFlag__PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_,
            is_QFlags_QAbstractSpinBox_StepEnabledFlag__PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag_,
            is_number_PythonToCpp_QFlags_QAbstractSpinBox_StepEnabledFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QABSTRACTSPINBOX_STEPENABLEDFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QAbstractSpinBox::StepEnabledFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StepEnabledFlag>");
    }
    // End of 'StepEnabledFlag' enum/flags.

    // Initialization of enum 'ButtonSymbols'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSpinBox_Type,
        "ButtonSymbols",
        "PySide.QtGui.QAbstractSpinBox.ButtonSymbols",
        "QAbstractSpinBox::ButtonSymbols");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX],
        &Sbk_QAbstractSpinBox_Type, "UpDownArrows", (long) QAbstractSpinBox::UpDownArrows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX],
        &Sbk_QAbstractSpinBox_Type, "PlusMinus", (long) QAbstractSpinBox::PlusMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX],
        &Sbk_QAbstractSpinBox_Type, "NoButtons", (long) QAbstractSpinBox::NoButtons))
        return ;
    // Register converter for enum 'QAbstractSpinBox::ButtonSymbols'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX],
            QAbstractSpinBox_ButtonSymbols_CppToPython_QAbstractSpinBox_ButtonSymbols);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSpinBox_ButtonSymbols_PythonToCpp_QAbstractSpinBox_ButtonSymbols,
            is_QAbstractSpinBox_ButtonSymbols_PythonToCpp_QAbstractSpinBox_ButtonSymbols_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_BUTTONSYMBOLS_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox::ButtonSymbols");
        Shiboken::Conversions::registerConverterName(converter, "ButtonSymbols");
    }
    // End of 'ButtonSymbols' enum.

    // Initialization of enum 'CorrectionMode'.
    SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAbstractSpinBox_Type,
        "CorrectionMode",
        "PySide.QtGui.QAbstractSpinBox.CorrectionMode",
        "QAbstractSpinBox::CorrectionMode");
    if (!SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX],
        &Sbk_QAbstractSpinBox_Type, "CorrectToPreviousValue", (long) QAbstractSpinBox::CorrectToPreviousValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX],
        &Sbk_QAbstractSpinBox_Type, "CorrectToNearestValue", (long) QAbstractSpinBox::CorrectToNearestValue))
        return ;
    // Register converter for enum 'QAbstractSpinBox::CorrectionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX],
            QAbstractSpinBox_CorrectionMode_CppToPython_QAbstractSpinBox_CorrectionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAbstractSpinBox_CorrectionMode_PythonToCpp_QAbstractSpinBox_CorrectionMode,
            is_QAbstractSpinBox_CorrectionMode_PythonToCpp_QAbstractSpinBox_CorrectionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_CORRECTIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAbstractSpinBox::CorrectionMode");
        Shiboken::Conversions::registerConverterName(converter, "CorrectionMode");
    }
    // End of 'CorrectionMode' enum.

    PySide::Signal::registerSignals(&Sbk_QAbstractSpinBox_Type, &::QAbstractSpinBox::staticMetaObject);

    qRegisterMetaType< ::QAbstractSpinBox::StepEnabledFlag >("QAbstractSpinBox::StepEnabledFlag");
    qRegisterMetaType< ::QAbstractSpinBox::StepEnabled >("QAbstractSpinBox::StepEnabled");
    qRegisterMetaType< ::QAbstractSpinBox::ButtonSymbols >("QAbstractSpinBox::ButtonSymbols");
    qRegisterMetaType< ::QAbstractSpinBox::CorrectionMode >("QAbstractSpinBox::CorrectionMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAbstractSpinBox_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAbstractSpinBox_Type, &::QAbstractSpinBox::staticMetaObject, sizeof(::QAbstractSpinBox));
}
