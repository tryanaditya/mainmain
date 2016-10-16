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

#include "qdatetimeedit_wrapper.h"

// Extra includes
#include <QList>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcalendarwidget.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdatetime.h>
#include <qdatetimeedit.h>
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

QDateTimeEditWrapper::QDateTimeEditWrapper(QWidget * parent) : QDateTimeEdit(parent) {
    // ... middle
}

QDateTimeEditWrapper::QDateTimeEditWrapper(const QDate & d, QWidget * parent) : QDateTimeEdit(d, parent) {
    // ... middle
}

QDateTimeEditWrapper::QDateTimeEditWrapper(const QDateTime & dt, QWidget * parent) : QDateTimeEdit(dt, parent) {
    // ... middle
}

QDateTimeEditWrapper::QDateTimeEditWrapper(const QTime & t, QWidget * parent) : QDateTimeEdit(t, parent) {
    // ... middle
}

QDateTimeEditWrapper::QDateTimeEditWrapper(const QVariant & val, QVariant::Type parserType, QWidget * parent) : QDateTimeEdit(val, parserType, parent) {
    // ... middle
}

void QDateTimeEditWrapper::actionEvent(QActionEvent * event)
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

void QDateTimeEditWrapper::changeEvent(QEvent * event)
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

void QDateTimeEditWrapper::childEvent(QChildEvent * arg__1)
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

void QDateTimeEditWrapper::clear()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clear"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::clear();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QDateTimeEditWrapper::closeEvent(QCloseEvent * event)
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

void QDateTimeEditWrapper::connectNotify(const char * signal)
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

void QDateTimeEditWrapper::contextMenuEvent(QContextMenuEvent * event)
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

void QDateTimeEditWrapper::customEvent(QEvent * arg__1)
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

QDateTime QDateTimeEditWrapper::dateTimeFromText(const QString & text) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QDateTime();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dateTimeFromText"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::dateTimeFromText(text);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &text)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QDateTime();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.dateTimeFromText", Shiboken::SbkType< QDateTime >()->tp_name, pyResult->ob_type->tp_name);
        return ::QDateTime();
    }
    ::QDateTime cppResult = ::QDateTime();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QDateTimeEditWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::disconnectNotify(const char * signal)
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

void QDateTimeEditWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void QDateTimeEditWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void QDateTimeEditWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void QDateTimeEditWrapper::dropEvent(QDropEvent * event)
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

void QDateTimeEditWrapper::enterEvent(QEvent * event)
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

bool QDateTimeEditWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::event(event);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDateTimeEditWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDateTimeEditWrapper::fixup(QString & input) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fixup"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QDateTimeEdit::fixup(input);
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

void QDateTimeEditWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::focusInEvent(event);
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

bool QDateTimeEditWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::focusNextPrevChild(next);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::focusOutEvent(QFocusEvent * event)
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

int QDateTimeEditWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::hideEvent(QHideEvent * event)
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

void QDateTimeEditWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant QDateTimeEditWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::keyPressEvent(QKeyEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::keyPressEvent(event);
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

void QDateTimeEditWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QDateTimeEditWrapper::languageChange()
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

void QDateTimeEditWrapper::leaveEvent(QEvent * event)
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

int QDateTimeEditWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QDateTimeEditWrapper::minimumSizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void QDateTimeEditWrapper::mouseMoveEvent(QMouseEvent * event)
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

void QDateTimeEditWrapper::mousePressEvent(QMouseEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::mousePressEvent(event);
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

void QDateTimeEditWrapper::mouseReleaseEvent(QMouseEvent * event)
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

void QDateTimeEditWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QDateTimeEditWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::paintEvent(QPaintEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::paintEvent(event);
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

void QDateTimeEditWrapper::resizeEvent(QResizeEvent * event)
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

void QDateTimeEditWrapper::setVisible(bool visible)
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

void QDateTimeEditWrapper::showEvent(QShowEvent * event)
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

QSize QDateTimeEditWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::stepBy(int steps)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stepBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::stepBy(steps);
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

QFlags<QAbstractSpinBox::StepEnabledFlag> QDateTimeEditWrapper::stepEnabled() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "stepEnabled"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::stepEnabled();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.stepEnabled", Shiboken::SbkType< QFlags<QAbstractSpinBox::StepEnabledFlag> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    }
    ::QFlags<QAbstractSpinBox::StepEnabledFlag> cppResult = ((::QFlags<QAbstractSpinBox::StepEnabledFlag>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::tabletEvent(QTabletEvent * event)
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

QString QDateTimeEditWrapper::textFromDateTime(const QDateTime & dt) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "textFromDateTime"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::textFromDateTime(dt);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &dt)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDateTimeEdit.textFromDateTime", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QDateTimeEditWrapper::timerEvent(QTimerEvent * event)
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

QValidator::State QDateTimeEditWrapper::validate(QString & input, int & pos) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QValidator::State)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "validate"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QDateTimeEdit::validate(input, pos);
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
            qWarning("QDateTimeEdit::validate: Second tuple element is not convertible to unicode.");
    }

    if (size > 2) {
        if (Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2)))
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2), &(pos));
        else
            qWarning("QDateTimeEdit::validate: Second tuple element is not convertible to int.");
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

void QDateTimeEditWrapper::wheelEvent(QWheelEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDateTimeEdit::wheelEvent(event);
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

const QMetaObject* QDateTimeEditWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDateTimeEdit::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDateTimeEditWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDateTimeEdit::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDateTimeEditWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDateTimeEditWrapper* >(this));
        return QDateTimeEdit::qt_metacast(_clname);
}

QDateTimeEditWrapper::~QDateTimeEditWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDateTimeEdit_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDateTimeEdit >()))
        return -1;

    ::QDateTimeEditWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOO:QDateTimeEdit", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QDateTimeEdit(QWidget*)
    // 1: QDateTimeEdit(QDate,QWidget*)
    // 2: QDateTimeEdit(QDateTime,QWidget*)
    // 3: QDateTimeEdit(QTime,QWidget*)
    // 4: QDateTimeEdit(QVariant,QVariant::Type,QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QDateTimeEdit(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QDateTimeEdit(QTime,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 3; // QDateTimeEdit(QTime,QWidget*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QDateTimeEdit(QDateTime,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 2; // QDateTimeEdit(QDateTime,QWidget*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QDateTimeEdit(QDate,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 1; // QDateTimeEdit(QDate,QWidget*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QDateTimeEdit(QWidget*)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_TYPE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // QDateTimeEdit(QVariant,QVariant::Type,QWidget*)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
            overloadId = 4; // QDateTimeEdit(QVariant,QVariant::Type,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEdit_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDateTimeEdit(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDateTimeEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QDateTimeEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDateTimeEdit(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDateTimeEditWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDateTimeEditWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QDateTimeEdit(const QDate & d, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDateTimeEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QDateTimeEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDate cppArg0_local = ::QDate();
            ::QDate* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDateTimeEdit(QDate,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 2: // QDateTimeEdit(const QDateTime & dt, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDateTimeEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QDateTimeEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDateTimeEdit(QDateTime,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 3: // QDateTimeEdit(const QTime & t, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDateTimeEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QDateTimeEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTime cppArg0_local = ::QTime();
            ::QTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QDateTimeEdit(QTime,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDateTimeEditWrapper(*cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 4: // QDateTimeEdit(const QVariant & val, QVariant::Type parserType, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDateTimeEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                        goto Sbk_QDateTimeEdit_Init_TypeError;
                }
            }
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QVariant::Type cppArg1 = QVariant::Invalid;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QWidget* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QDateTimeEdit(QVariant,QVariant::Type,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDateTimeEditWrapper(cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDateTimeEditWrapper(cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDateTimeEdit >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDateTimeEdit_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDateTimeEdit_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", "PySide.QtCore.QDate, PySide.QtGui.QWidget = None", "PySide.QtCore.QDateTime, PySide.QtGui.QWidget = None", "PySide.QtCore.QTime, PySide.QtGui.QWidget = None", "QVariant, QVariant::Type, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDateTimeEdit", overloads);
        return -1;
}

static PyObject* Sbk_QDateTimeEditFunc_calendarPopup(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // calendarPopup()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->calendarPopup();
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

static PyObject* Sbk_QDateTimeEditFunc_calendarWidget(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // calendarWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCalendarWidget * cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->calendarWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCALENDARWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_clear(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::clear() : cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMaximumDate(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMaximumDate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMaximumDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMaximumDateTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMaximumDateTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMaximumDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMaximumTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMaximumTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMaximumTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMinimumDate(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMinimumDate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMinimumDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMinimumDateTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMinimumDateTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMinimumDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_clearMinimumTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearMinimumTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearMinimumTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QDateTimeEditFunc_currentSection(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentSection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTimeEdit::Section cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->currentSection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_currentSectionIndex(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentSectionIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->currentSectionIndex();
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

static PyObject* Sbk_QDateTimeEditFunc_date(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // date()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->date();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_dateTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dateTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->dateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_dateTimeFromText(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dateTimeFromText(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // dateTimeFromText(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_dateTimeFromText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dateTimeFromText(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QDateTimeEdit*>(cppSelf)->::QDateTimeEdit::dateTimeFromText(cppArg0) : const_cast<const ::QDateTimeEdit*>(cppSelf)->dateTimeFromText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_dateTimeFromText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.dateTimeFromText", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_displayFormat(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // displayFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->displayFormat();
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

static PyObject* Sbk_QDateTimeEditFunc_displayedSections(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // displayedSections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDateTimeEdit::Section> cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->displayedSections();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.event", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_fixup(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_fixup_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fixup(QString&)const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QDateTimeEdit*>(cppSelf)->::QDateTimeEdit::fixup(cppArg0) : const_cast<const ::QDateTimeEdit*>(cppSelf)->fixup(cppArg0);
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

    Sbk_QDateTimeEditFunc_fixup_TypeError:
        const char* overloads[] = {"PySide.QtCore.QString", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.fixup", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::focusNextPrevChild(cppArg0) : cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_initStyleOption(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: initStyleOption(QStyleOptionSpinBox*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSPINBOX_IDX], (pyArg)))) {
        overloadId = 0; // initStyleOption(QStyleOptionSpinBox*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_initStyleOption_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QStyleOptionSpinBox* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // initStyleOption(QStyleOptionSpinBox*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QDateTimeEdit*>(cppSelf)->initStyleOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_initStyleOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyleOptionSpinBox", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.initStyleOption", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_maximumDate(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->maximumDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_maximumDateTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumDateTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->maximumDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_maximumTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->maximumTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_minimumDate(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumDate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDate cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->minimumDate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_minimumDateTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumDateTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->minimumDateTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_minimumTime(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->minimumTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_paintEvent(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_sectionAt(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sectionAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // sectionAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_sectionAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sectionAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDateTimeEdit::Section cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->sectionAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_sectionAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.sectionAt", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_sectionCount(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sectionCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->sectionCount();
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

static PyObject* Sbk_QDateTimeEditFunc_sectionText(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sectionText(QDateTimeEdit::Section)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]), (pyArg)))) {
        overloadId = 0; // sectionText(QDateTimeEdit::Section)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_sectionText_TypeError;

    // Call function/method
    {
        ::QDateTimeEdit::Section cppArg0 = ((::QDateTimeEdit::Section)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sectionText(QDateTimeEdit::Section)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->sectionText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_sectionText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDateTimeEdit.Section", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.sectionText", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setCalendarPopup(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCalendarPopup(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCalendarPopup(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setCalendarPopup_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCalendarPopup(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCalendarPopup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setCalendarPopup_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setCalendarPopup", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setCalendarWidget(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCalendarWidget(QCalendarWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCALENDARWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setCalendarWidget(QCalendarWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setCalendarWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QCalendarWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCalendarWidget(QCalendarWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCalendarWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setCalendarWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCalendarWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setCalendarWidget", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setCurrentSection(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentSection(QDateTimeEdit::Section)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setCurrentSection(QDateTimeEdit::Section)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setCurrentSection_TypeError;

    // Call function/method
    {
        ::QDateTimeEdit::Section cppArg0 = ((::QDateTimeEdit::Section)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentSection(QDateTimeEdit::Section)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentSection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setCurrentSection_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDateTimeEdit.Section", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setCurrentSection", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setCurrentSectionIndex(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentSectionIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentSectionIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setCurrentSectionIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentSectionIndex(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentSectionIndex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setCurrentSectionIndex_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setCurrentSectionIndex", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setDate(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDate(QDate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 0; // setDate(QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setDate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDate cppArg0_local = ::QDate();
        ::QDate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDate(QDate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setDate", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setDateRange(PyObject* self, PyObject* args)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDateRange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDateRange(QDate,QDate)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setDateRange(QDate,QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setDateRange_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDate cppArg0_local = ::QDate();
        ::QDate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDate cppArg1_local = ::QDate();
        ::QDate* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setDateRange(QDate,QDate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDateRange(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setDateRange_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate, PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDateTimeEdit.setDateRange", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setDateTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDateTime(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setDateTime(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setDateTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setDateTime(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDateTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setDateTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setDateTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setDateTimeRange(PyObject* self, PyObject* args)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDateTimeRange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDateTimeRange(QDateTime,QDateTime)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArgs[1])))) {
        overloadId = 0; // setDateTimeRange(QDateTime,QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setDateTimeRange_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QDateTime cppArg1_local = ::QDateTime();
        ::QDateTime* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setDateTimeRange(QDateTime,QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDateTimeRange(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setDateTimeRange_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime, PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDateTimeEdit.setDateTimeRange", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setDisplayFormat(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDisplayFormat(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDisplayFormat(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setDisplayFormat_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDisplayFormat(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDisplayFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setDisplayFormat_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setDisplayFormat", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMaximumDate(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumDate(QDate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 0; // setMaximumDate(QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMaximumDate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDate cppArg0_local = ::QDate();
        ::QDate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMaximumDate(QDate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumDate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMaximumDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMaximumDate", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMaximumDateTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumDateTime(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setMaximumDateTime(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMaximumDateTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMaximumDateTime(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumDateTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMaximumDateTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMaximumDateTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMaximumTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumTime(QTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // setMaximumTime(QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMaximumTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMaximumTime(QTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMaximumTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMaximumTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMinimumDate(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimumDate(QDate)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], (pyArg)))) {
        overloadId = 0; // setMinimumDate(QDate)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMinimumDate_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDate cppArg0_local = ::QDate();
        ::QDate* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMinimumDate(QDate)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimumDate(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMinimumDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMinimumDate", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMinimumDateTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimumDateTime(QDateTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // setMinimumDateTime(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMinimumDateTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMinimumDateTime(QDateTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimumDateTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMinimumDateTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMinimumDateTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setMinimumTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimumTime(QTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // setMinimumTime(QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setMinimumTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMinimumTime(QTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimumTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setMinimumTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setMinimumTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setSelectedSection(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelectedSection(QDateTimeEdit::Section)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setSelectedSection(QDateTimeEdit::Section)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setSelectedSection_TypeError;

    // Call function/method
    {
        ::QDateTimeEdit::Section cppArg0 = ((::QDateTimeEdit::Section)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelectedSection(QDateTimeEdit::Section)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelectedSection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setSelectedSection_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDateTimeEdit.Section", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setSelectedSection", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTime(QTime)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArg)))) {
        overloadId = 0; // setTime(QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTime(QTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setTimeRange(PyObject* self, PyObject* args)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setTimeRange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTimeRange(QTime,QTime)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], (pyArgs[1])))) {
        overloadId = 0; // setTimeRange(QTime,QTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setTimeRange_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QTime cppArg0_local = ::QTime();
        ::QTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QTime cppArg1_local = ::QTime();
        ::QTime* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setTimeRange(QTime,QTime)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTimeRange(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setTimeRange_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTime, PySide.QtCore.QTime", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDateTimeEdit.setTimeRange", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_setTimeSpec(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTimeSpec(Qt::TimeSpec)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), (pyArg)))) {
        overloadId = 0; // setTimeSpec(Qt::TimeSpec)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_setTimeSpec_TypeError;

    // Call function/method
    {
        ::Qt::TimeSpec cppArg0 = ((::Qt::TimeSpec)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTimeSpec(Qt::TimeSpec)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTimeSpec(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_setTimeSpec_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TimeSpec", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.setTimeSpec", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_sizeHint(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QDateTimeEdit*>(cppSelf)->::QDateTimeEdit::sizeHint() : const_cast<const ::QDateTimeEdit*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QDateTimeEditFunc_stepBy(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stepBy(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // stepBy(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_stepBy_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // stepBy(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::stepBy(cppArg0) : cppSelf->stepBy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_stepBy_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.stepBy", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_stepEnabled(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stepEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QAbstractSpinBox::StepEnabledFlag> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QDateTimeEdit*>(cppSelf)->::QDateTimeEdit::stepEnabled() : const_cast<const ::QDateTimeEdit*>(cppSelf)->stepEnabled();
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

static PyObject* Sbk_QDateTimeEditFunc_textFromDateTime(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: textFromDateTime(QDateTime)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // textFromDateTime(QDateTime)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_textFromDateTime_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDateTime cppArg0_local = ::QDateTime();
        ::QDateTime* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // textFromDateTime(QDateTime)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QDateTimeEdit*>(cppSelf)->::QDateTimeEdit::textFromDateTime(*cppArg0) : const_cast<const ::QDateTimeEdit*>(cppSelf)->textFromDateTime(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDateTimeEditFunc_textFromDateTime_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.textFromDateTime", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_time(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // time()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTime cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->time();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIME_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_timeSpec(PyObject* self)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timeSpec()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::TimeSpec cppResult = const_cast<const ::QDateTimeEdit*>(cppSelf)->timeSpec();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_TIMESPEC_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDateTimeEditFunc_validate(PyObject* self, PyObject* args)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_validate_TypeError;

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
            QValidator::State retval_ = QValidator::State((Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::validate(cppArg0, cppArg1) : cppSelf->validate(cppArg0, cppArg1)));
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

    Sbk_QDateTimeEditFunc_validate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QString, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDateTimeEdit.validate", overloads);
        return 0;
}

static PyObject* Sbk_QDateTimeEditFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDateTimeEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDateTimeEditFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDateTimeEdit::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDateTimeEditFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDateTimeEdit.wheelEvent", overloads);
        return 0;
}

static PyMethodDef Sbk_QDateTimeEdit_methods[] = {
    {"calendarPopup", (PyCFunction)Sbk_QDateTimeEditFunc_calendarPopup, METH_NOARGS},
    {"calendarWidget", (PyCFunction)Sbk_QDateTimeEditFunc_calendarWidget, METH_NOARGS},
    {"clear", (PyCFunction)Sbk_QDateTimeEditFunc_clear, METH_NOARGS},
    {"clearMaximumDate", (PyCFunction)Sbk_QDateTimeEditFunc_clearMaximumDate, METH_NOARGS},
    {"clearMaximumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_clearMaximumDateTime, METH_NOARGS},
    {"clearMaximumTime", (PyCFunction)Sbk_QDateTimeEditFunc_clearMaximumTime, METH_NOARGS},
    {"clearMinimumDate", (PyCFunction)Sbk_QDateTimeEditFunc_clearMinimumDate, METH_NOARGS},
    {"clearMinimumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_clearMinimumDateTime, METH_NOARGS},
    {"clearMinimumTime", (PyCFunction)Sbk_QDateTimeEditFunc_clearMinimumTime, METH_NOARGS},
    {"currentSection", (PyCFunction)Sbk_QDateTimeEditFunc_currentSection, METH_NOARGS},
    {"currentSectionIndex", (PyCFunction)Sbk_QDateTimeEditFunc_currentSectionIndex, METH_NOARGS},
    {"date", (PyCFunction)Sbk_QDateTimeEditFunc_date, METH_NOARGS},
    {"dateTime", (PyCFunction)Sbk_QDateTimeEditFunc_dateTime, METH_NOARGS},
    {"dateTimeFromText", (PyCFunction)Sbk_QDateTimeEditFunc_dateTimeFromText, METH_O},
    {"displayFormat", (PyCFunction)Sbk_QDateTimeEditFunc_displayFormat, METH_NOARGS},
    {"displayedSections", (PyCFunction)Sbk_QDateTimeEditFunc_displayedSections, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QDateTimeEditFunc_event, METH_O},
    {"fixup", (PyCFunction)Sbk_QDateTimeEditFunc_fixup, METH_O},
    {"focusInEvent", (PyCFunction)Sbk_QDateTimeEditFunc_focusInEvent, METH_O},
    {"focusNextPrevChild", (PyCFunction)Sbk_QDateTimeEditFunc_focusNextPrevChild, METH_O},
    {"initStyleOption", (PyCFunction)Sbk_QDateTimeEditFunc_initStyleOption, METH_O},
    {"keyPressEvent", (PyCFunction)Sbk_QDateTimeEditFunc_keyPressEvent, METH_O},
    {"maximumDate", (PyCFunction)Sbk_QDateTimeEditFunc_maximumDate, METH_NOARGS},
    {"maximumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_maximumDateTime, METH_NOARGS},
    {"maximumTime", (PyCFunction)Sbk_QDateTimeEditFunc_maximumTime, METH_NOARGS},
    {"minimumDate", (PyCFunction)Sbk_QDateTimeEditFunc_minimumDate, METH_NOARGS},
    {"minimumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_minimumDateTime, METH_NOARGS},
    {"minimumTime", (PyCFunction)Sbk_QDateTimeEditFunc_minimumTime, METH_NOARGS},
    {"mousePressEvent", (PyCFunction)Sbk_QDateTimeEditFunc_mousePressEvent, METH_O},
    {"paintEvent", (PyCFunction)Sbk_QDateTimeEditFunc_paintEvent, METH_O},
    {"sectionAt", (PyCFunction)Sbk_QDateTimeEditFunc_sectionAt, METH_O},
    {"sectionCount", (PyCFunction)Sbk_QDateTimeEditFunc_sectionCount, METH_NOARGS},
    {"sectionText", (PyCFunction)Sbk_QDateTimeEditFunc_sectionText, METH_O},
    {"setCalendarPopup", (PyCFunction)Sbk_QDateTimeEditFunc_setCalendarPopup, METH_O},
    {"setCalendarWidget", (PyCFunction)Sbk_QDateTimeEditFunc_setCalendarWidget, METH_O},
    {"setCurrentSection", (PyCFunction)Sbk_QDateTimeEditFunc_setCurrentSection, METH_O},
    {"setCurrentSectionIndex", (PyCFunction)Sbk_QDateTimeEditFunc_setCurrentSectionIndex, METH_O},
    {"setDate", (PyCFunction)Sbk_QDateTimeEditFunc_setDate, METH_O},
    {"setDateRange", (PyCFunction)Sbk_QDateTimeEditFunc_setDateRange, METH_VARARGS},
    {"setDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_setDateTime, METH_O},
    {"setDateTimeRange", (PyCFunction)Sbk_QDateTimeEditFunc_setDateTimeRange, METH_VARARGS},
    {"setDisplayFormat", (PyCFunction)Sbk_QDateTimeEditFunc_setDisplayFormat, METH_O},
    {"setMaximumDate", (PyCFunction)Sbk_QDateTimeEditFunc_setMaximumDate, METH_O},
    {"setMaximumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_setMaximumDateTime, METH_O},
    {"setMaximumTime", (PyCFunction)Sbk_QDateTimeEditFunc_setMaximumTime, METH_O},
    {"setMinimumDate", (PyCFunction)Sbk_QDateTimeEditFunc_setMinimumDate, METH_O},
    {"setMinimumDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_setMinimumDateTime, METH_O},
    {"setMinimumTime", (PyCFunction)Sbk_QDateTimeEditFunc_setMinimumTime, METH_O},
    {"setSelectedSection", (PyCFunction)Sbk_QDateTimeEditFunc_setSelectedSection, METH_O},
    {"setTime", (PyCFunction)Sbk_QDateTimeEditFunc_setTime, METH_O},
    {"setTimeRange", (PyCFunction)Sbk_QDateTimeEditFunc_setTimeRange, METH_VARARGS},
    {"setTimeSpec", (PyCFunction)Sbk_QDateTimeEditFunc_setTimeSpec, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QDateTimeEditFunc_sizeHint, METH_NOARGS},
    {"stepBy", (PyCFunction)Sbk_QDateTimeEditFunc_stepBy, METH_O},
    {"stepEnabled", (PyCFunction)Sbk_QDateTimeEditFunc_stepEnabled, METH_NOARGS},
    {"textFromDateTime", (PyCFunction)Sbk_QDateTimeEditFunc_textFromDateTime, METH_O},
    {"time", (PyCFunction)Sbk_QDateTimeEditFunc_time, METH_NOARGS},
    {"timeSpec", (PyCFunction)Sbk_QDateTimeEditFunc_timeSpec, METH_NOARGS},
    {"validate", (PyCFunction)Sbk_QDateTimeEditFunc_validate, METH_VARARGS},
    {"wheelEvent", (PyCFunction)Sbk_QDateTimeEditFunc_wheelEvent, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDateTimeEdit_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDateTimeEdit_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QDateTimeEditSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QDateTimeEdit* me = reinterpret_cast< ::QDateTimeEdit*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX]))
        return static_cast< ::QAbstractSpinBox*>(me);
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
static SbkObjectType Sbk_QDateTimeEdit_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDateTimeEdit",
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
    /*tp_traverse*/         Sbk_QDateTimeEdit_traverse,
    /*tp_clear*/            Sbk_QDateTimeEdit_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDateTimeEdit_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDateTimeEdit_Init,
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

static void* Sbk_QDateTimeEdit_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDateTimeEdit*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QDateTimeEdit*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QDateTimeEdit_Section___and__(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit::Sections cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDateTimeEdit::Sections)PyLong_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDateTimeEdit::Sections)PyInt_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDateTimeEdit_Section___or__(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit::Sections cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDateTimeEdit::Sections)PyLong_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDateTimeEdit::Sections)PyInt_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDateTimeEdit_Section___xor__(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit::Sections cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QDateTimeEdit::Sections)PyLong_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QDateTimeEdit::Sections)PyInt_AsLong(self);
    cppArg = (QDateTimeEdit::Sections)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QDateTimeEdit_Section___invert__(PyObject* self, PyObject* pyArg)
{
    ::QDateTimeEdit::Sections cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), self, &cppSelf);
    ::QDateTimeEdit::Sections cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QDateTimeEdit_Section_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QDateTimeEdit_Section__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QDateTimeEdit_Section_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QDateTimeEdit_Section__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QDateTimeEdit_Section___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QDateTimeEdit_Section___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QDateTimeEdit_Section___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QDateTimeEdit_Section___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QDateTimeEdit_Section_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QDateTimeEdit_Section_long,
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
static void QDateTimeEdit_Section_PythonToCpp_QDateTimeEdit_Section(PyObject* pyIn, void* cppOut) {
    *((::QDateTimeEdit::Section*)cppOut) = (::QDateTimeEdit::Section) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDateTimeEdit_Section_PythonToCpp_QDateTimeEdit_Section_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]))
        return QDateTimeEdit_Section_PythonToCpp_QDateTimeEdit_Section;
    return 0;
}
static PyObject* QDateTimeEdit_Section_CppToPython_QDateTimeEdit_Section(const void* cppIn) {
    int castCppIn = *((::QDateTimeEdit::Section*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX], castCppIn);

}

static void QFlags_QDateTimeEdit_Section__PythonToCpp_QFlags_QDateTimeEdit_Section_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDateTimeEdit::Section>*)cppOut) = ::QFlags<QDateTimeEdit::Section>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QDateTimeEdit_Section__PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]))
        return QFlags_QDateTimeEdit_Section__PythonToCpp_QFlags_QDateTimeEdit_Section_;
    return 0;
}
static PyObject* QFlags_QDateTimeEdit_Section__CppToPython_QFlags_QDateTimeEdit_Section_(const void* cppIn) {
    int castCppIn = *((::QFlags<QDateTimeEdit::Section>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]));

}

static void QDateTimeEdit_Section_PythonToCpp_QFlags_QDateTimeEdit_Section_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QDateTimeEdit::Section>*)cppOut) = ::QFlags<QDateTimeEdit::Section>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QDateTimeEdit_Section_PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX]))
        return QDateTimeEdit_Section_PythonToCpp_QFlags_QDateTimeEdit_Section_;
    return 0;
}
static void number_PythonToCpp_QFlags_QDateTimeEdit_Section_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QDateTimeEdit::Section>*)cppOut) = ::QFlags<QDateTimeEdit::Section>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QDateTimeEdit_Section_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDateTimeEdit_PythonToCpp_QDateTimeEdit_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDateTimeEdit_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDateTimeEdit_PythonToCpp_QDateTimeEdit_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDateTimeEdit_Type))
        return QDateTimeEdit_PythonToCpp_QDateTimeEdit_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDateTimeEdit_PTR_CppToPython_QDateTimeEdit(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDateTimeEdit*)cppIn, &Sbk_QDateTimeEdit_Type);

}

void init_QDateTimeEdit(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDateTimeEdit_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDateTimeEdit", "QDateTimeEdit*",
        &Sbk_QDateTimeEdit_Type, &Shiboken::callCppDestructor< ::QDateTimeEdit >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTSPINBOX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDateTimeEdit_Type,
        QDateTimeEdit_PythonToCpp_QDateTimeEdit_PTR,
        is_QDateTimeEdit_PythonToCpp_QDateTimeEdit_PTR_Convertible,
        QDateTimeEdit_PTR_CppToPython_QDateTimeEdit);

    Shiboken::Conversions::registerConverterName(converter, "QDateTimeEdit");
    Shiboken::Conversions::registerConverterName(converter, "QDateTimeEdit*");
    Shiboken::Conversions::registerConverterName(converter, "QDateTimeEdit&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDateTimeEdit).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDateTimeEditWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QDateTimeEdit_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QDateTimeEdit_Type, &Sbk_QDateTimeEditSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDateTimeEdit_Type, &Sbk_QDateTimeEdit_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Section'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX] = PySide::QFlags::create("Sections", &SbkPySide_QtGui_QDateTimeEdit_Section_as_number);
    SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDateTimeEdit_Type,
        "Section",
        "PySide.QtGui.QDateTimeEdit.Section",
        "QDateTimeEdit::Section",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "NoSection", (long) QDateTimeEdit::NoSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "AmPmSection", (long) QDateTimeEdit::AmPmSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "MSecSection", (long) QDateTimeEdit::MSecSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "SecondSection", (long) QDateTimeEdit::SecondSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "MinuteSection", (long) QDateTimeEdit::MinuteSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "HourSection", (long) QDateTimeEdit::HourSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "DaySection", (long) QDateTimeEdit::DaySection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "MonthSection", (long) QDateTimeEdit::MonthSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "YearSection", (long) QDateTimeEdit::YearSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "TimeSections_Mask", (long) QDateTimeEdit::TimeSections_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
        &Sbk_QDateTimeEdit_Type, "DateSections_Mask", (long) QDateTimeEdit::DateSections_Mask))
        return ;
    // Register converter for enum 'QDateTimeEdit::Section'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX],
            QDateTimeEdit_Section_CppToPython_QDateTimeEdit_Section);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDateTimeEdit_Section_PythonToCpp_QDateTimeEdit_Section,
            is_QDateTimeEdit_Section_PythonToCpp_QDateTimeEdit_Section_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDATETIMEEDIT_SECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDateTimeEdit::Section");
        Shiboken::Conversions::registerConverterName(converter, "Section");
    }
    // Register converter for flag 'QFlags<QDateTimeEdit::Section>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX],
            QFlags_QDateTimeEdit_Section__CppToPython_QFlags_QDateTimeEdit_Section_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDateTimeEdit_Section_PythonToCpp_QFlags_QDateTimeEdit_Section_,
            is_QDateTimeEdit_Section_PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QDateTimeEdit_Section__PythonToCpp_QFlags_QDateTimeEdit_Section_,
            is_QFlags_QDateTimeEdit_Section__PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QDateTimeEdit_Section_,
            is_number_PythonToCpp_QFlags_QDateTimeEdit_Section__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QDATETIMEEDIT_SECTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QDateTimeEdit::Section>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Section>");
    }
    // End of 'Section' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QDateTimeEdit_Type, &::QDateTimeEdit::staticMetaObject);

    qRegisterMetaType< ::QDateTimeEdit::Section >("QDateTimeEdit::Section");
    qRegisterMetaType< ::QDateTimeEdit::Sections >("QDateTimeEdit::Sections");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDateTimeEdit_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDateTimeEdit_Type, &::QDateTimeEdit::staticMetaObject, sizeof(::QDateTimeEdit));
}
