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

#include "qplaintextedit_wrapper.h"

// Extra includes
#include <QAbstractTextDocumentLayout>
#include <QList>
#include <QTextEdit>
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
#include <qmenu.h>
#include <qmimedata.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qplaintextedit.h>
#include <qpoint.h>
#include <qprinter.h>
#include <qrect.h>
#include <qregion.h>
#include <qscrollbar.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qtextcursor.h>
#include <qtextdocument.h>
#include <qtextformat.h>
#include <qtextobject.h>
#include <qurl.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QPlainTextEditWrapper::QPlainTextEditWrapper(QWidget * parent) : QPlainTextEdit(parent) {
    // ... middle
}

QPlainTextEditWrapper::QPlainTextEditWrapper(const QString & text, QWidget * parent) : QPlainTextEdit(text, parent) {
    // ... middle
}

void QPlainTextEditWrapper::actionEvent(QActionEvent * event)
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

bool QPlainTextEditWrapper::canInsertFromMimeData(const QMimeData * source) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "canInsertFromMimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::canInsertFromMimeData(source);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], source)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.canInsertFromMimeData", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::changeEvent(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::changeEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::childEvent(QChildEvent * arg__1)
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

void QPlainTextEditWrapper::closeEvent(QCloseEvent * event)
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

void QPlainTextEditWrapper::connectNotify(const char * signal)
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

void QPlainTextEditWrapper::contextMenuEvent(QContextMenuEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::contextMenuEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QMimeData * QPlainTextEditWrapper::createMimeDataFromSelection() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QMimeData*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "createMimeDataFromSelection"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::createMimeDataFromSelection();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QMimeData*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.createMimeDataFromSelection", Shiboken::SbkType< QMimeData >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QMimeData*)0);
    }
    ::QMimeData* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::customEvent(QEvent * arg__1)
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

int QPlainTextEditWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::disconnectNotify(const char * signal)
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

void QPlainTextEditWrapper::dragEnterEvent(QDragEnterEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::dragEnterEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::dragLeaveEvent(QDragLeaveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::dragLeaveEvent(e);
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

void QPlainTextEditWrapper::dragMoveEvent(QDragMoveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::dragMoveEvent(e);
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

void QPlainTextEditWrapper::dropEvent(QDropEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::dropEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::enterEvent(QEvent * event)
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

bool QPlainTextEditWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::event(e);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QPlainTextEditWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QPlainTextEditWrapper::focusInEvent(QFocusEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::focusInEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QPlainTextEditWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::focusNextPrevChild(next);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::focusOutEvent(QFocusEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::focusOutEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

int QPlainTextEditWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::hideEvent(QHideEvent * event)
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

void QPlainTextEditWrapper::inputMethodEvent(QInputMethodEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::inputMethodEvent(arg__1);
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

QVariant QPlainTextEditWrapper::inputMethodQuery(Qt::InputMethodQuery property) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::inputMethodQuery(property);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_INPUTMETHODQUERY_IDX]), &property)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::insertFromMimeData(const QMimeData * source)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "insertFromMimeData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::insertFromMimeData(source);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], source)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPlainTextEditWrapper::keyPressEvent(QKeyEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::keyPressEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::keyReleaseEvent(QKeyEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::keyReleaseEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::languageChange()
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

void QPlainTextEditWrapper::leaveEvent(QEvent * event)
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

QVariant QPlainTextEditWrapper::loadResource(int type, const QUrl & name)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "loadResource"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::loadResource(type, name);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        type,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], &name)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.loadResource", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPlainTextEditWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QPlainTextEditWrapper::minimumSizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::mouseDoubleClickEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::mouseDoubleClickEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::mouseMoveEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::mouseMoveEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::mousePressEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::mousePressEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::mouseReleaseEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::mouseReleaseEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QPlainTextEditWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::paintEvent(QPaintEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::paintEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::resizeEvent(QResizeEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::resizeEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QPlainTextEditWrapper::scrollContentsBy(int dx, int dy)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scrollContentsBy"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::scrollContentsBy(dx, dy);
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

void QPlainTextEditWrapper::setVisible(bool visible)
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

void QPlainTextEditWrapper::showEvent(QShowEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::showEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QSize QPlainTextEditWrapper::sizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPlainTextEditWrapper::tabletEvent(QTabletEvent * event)
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

void QPlainTextEditWrapper::timerEvent(QTimerEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::timerEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

bool QPlainTextEditWrapper::viewportEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "viewportEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAbstractScrollArea::viewportEvent(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPlainTextEdit.viewportEvent", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

void QPlainTextEditWrapper::wheelEvent(QWheelEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPlainTextEdit::wheelEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

const QMetaObject* QPlainTextEditWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QPlainTextEdit::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QPlainTextEditWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QPlainTextEdit::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QPlainTextEditWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QPlainTextEditWrapper* >(this));
        return QPlainTextEdit::qt_metacast(_clname);
}

QPlainTextEditWrapper::~QPlainTextEditWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPlainTextEdit_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPlainTextEdit >()))
        return -1;

    ::QPlainTextEditWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QPlainTextEdit", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QPlainTextEdit(QWidget*)
    // 1: QPlainTextEdit(QString,QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QPlainTextEdit(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QPlainTextEdit(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QPlainTextEdit(QString,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 1; // QPlainTextEdit(QString,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEdit_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPlainTextEdit(QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QPlainTextEdit_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPlainTextEdit(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QPlainTextEditWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QPlainTextEditWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QPlainTextEdit(const QString & text, QWidget * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                        goto Sbk_QPlainTextEdit_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QPlainTextEdit(QString,QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QPlainTextEditWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QPlainTextEditWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPlainTextEdit >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPlainTextEdit_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QPlainTextEdit_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", "unicode, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit", overloads);
        return -1;
}

static PyObject* Sbk_QPlainTextEditFunc_anchorAt(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: anchorAt(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // anchorAt(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_anchorAt_TypeError;

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
            // anchorAt(QPoint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->anchorAt(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_anchorAt_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.anchorAt", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_appendHtml(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendHtml(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendHtml(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_appendHtml_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendHtml(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendHtml(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_appendHtml_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.appendHtml", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_appendPlainText(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_appendPlainText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendPlainText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendPlainText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_appendPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.appendPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_backgroundVisible(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->backgroundVisible();
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

static PyObject* Sbk_QPlainTextEditFunc_blockBoundingGeometry(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: blockBoundingGeometry(QTextBlock)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
        overloadId = 0; // blockBoundingGeometry(QTextBlock)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_blockBoundingGeometry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlock cppArg0_local = ::QTextBlock();
        ::QTextBlock* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // blockBoundingGeometry(QTextBlock)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->blockBoundingGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_blockBoundingGeometry_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlock", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.blockBoundingGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_blockBoundingRect(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: blockBoundingRect(QTextBlock)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], (pyArg)))) {
        overloadId = 0; // blockBoundingRect(QTextBlock)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_blockBoundingRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextBlock cppArg0_local = ::QTextBlock();
        ::QTextBlock* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // blockBoundingRect(QTextBlock)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->blockBoundingRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_blockBoundingRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextBlock", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.blockBoundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_blockCount(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // blockCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->blockCount();
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

static PyObject* Sbk_QPlainTextEditFunc_canInsertFromMimeData(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: canInsertFromMimeData(const QMimeData*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArg)))) {
        overloadId = 0; // canInsertFromMimeData(const QMimeData*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_canInsertFromMimeData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMimeData* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // canInsertFromMimeData(const QMimeData*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPlainTextEdit*>(cppSelf)->::QPlainTextEdit::canInsertFromMimeData(cppArg0) : const_cast<const ::QPlainTextEdit*>(cppSelf)->canInsertFromMimeData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_canInsertFromMimeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMimeData", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.canInsertFromMimeData", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_canPaste(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // canPaste()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->canPaste();
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

static PyObject* Sbk_QPlainTextEditFunc_centerCursor(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // centerCursor()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->centerCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPlainTextEditFunc_centerOnScroll(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // centerOnScroll()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->centerOnScroll();
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

static PyObject* Sbk_QPlainTextEditFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_clear(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_contentOffset(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contentOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->contentOffset();
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

static PyObject* Sbk_QPlainTextEditFunc_contextMenuEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: contextMenuEvent(QContextMenuEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX], (pyArg)))) {
        overloadId = 0; // contextMenuEvent(QContextMenuEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_contextMenuEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QContextMenuEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // contextMenuEvent(QContextMenuEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::contextMenuEvent(cppArg0) : cppSelf->contextMenuEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_contextMenuEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QContextMenuEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.contextMenuEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_copy(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // copy()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->copy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPlainTextEditFunc_createMimeDataFromSelection(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createMimeDataFromSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMimeData * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPlainTextEdit*>(cppSelf)->::QPlainTextEdit::createMimeDataFromSelection() : const_cast<const ::QPlainTextEdit*>(cppSelf)->createMimeDataFromSelection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_createStandardContextMenu(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QPlainTextEditFunc_currentCharFormat(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentCharFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCharFormat cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->currentCharFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_cursorForPosition(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cursorForPosition(QPoint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // cursorForPosition(QPoint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_cursorForPosition_TypeError;

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
            // cursorForPosition(QPoint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCursor cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->cursorForPosition(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_cursorForPosition_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.cursorForPosition", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_cursorRect(PyObject* self, PyObject* args)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "cursorRect", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: cursorRect()const
    // 1: cursorRect(QTextCursor)const
    if (numArgs == 0) {
        overloadId = 0; // cursorRect()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArgs[0])))) {
        overloadId = 1; // cursorRect(QTextCursor)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_cursorRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // cursorRect() const
        {

            if (!PyErr_Occurred()) {
                // cursorRect()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->cursorRect();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 1: // cursorRect(const QTextCursor & cursor) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QTextCursor cppArg0_local = ::QTextCursor();
            ::QTextCursor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // cursorRect(QTextCursor)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->cursorRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_cursorRect_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit.cursorRect", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_cursorWidth(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cursorWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->cursorWidth();
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

static PyObject* Sbk_QPlainTextEditFunc_cut(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_document(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // document()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextDocument * cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->document();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_documentTitle(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // documentTitle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->documentTitle();
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

static PyObject* Sbk_QPlainTextEditFunc_dragEnterEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragEnterEvent(QDragEnterEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragEnterEvent(QDragEnterEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragEnterEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragEnterEvent(QDragEnterEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragEnterEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_dragLeaveEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragLeaveEvent(QDragLeaveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragLeaveEvent(QDragLeaveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_dragLeaveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragLeaveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragLeaveEvent(QDragLeaveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::dragLeaveEvent(cppArg0) : cppSelf->dragLeaveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_dragLeaveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragLeaveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.dragLeaveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_dragMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dragMoveEvent(QDragMoveEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dragMoveEvent(QDragMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDragMoveEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dragMoveEvent(QDragMoveEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_dropEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: dropEvent(QDropEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDROPEVENT_IDX], (pyArg)))) {
        overloadId = 0; // dropEvent(QDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_dropEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDropEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // dropEvent(QDropEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_ensureCursorVisible(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ensureCursorVisible()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->ensureCursorVisible();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPlainTextEditFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.event", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_extraSelections(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // extraSelections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QTextEdit::ExtraSelection > cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->extraSelections();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTEDIT_EXTRASELECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_find(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.find(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.find(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:find", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: find(QString,QFlags<QTextDocument::FindFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // find(QString,QFlags<QTextDocument::FindFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[1])))) {
            overloadId = 0; // find(QString,QFlags<QTextDocument::FindFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_find_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.find(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]), (pyArgs[1]))))
                    goto Sbk_QPlainTextEditFunc_find_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QTextDocument::FindFlag> cppArg1 = QFlags<QTextDocument::FindFlag>(0);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // find(QString,QFlags<QTextDocument::FindFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->find(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_find_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QTextDocument.FindFlags = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit.find", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_firstVisibleBlock(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // firstVisibleBlock()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextBlock cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->firstVisibleBlock();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTBLOCK_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_focusInEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusInEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusInEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_focusInEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusInEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::focusInEvent(cppArg0) : cppSelf->focusInEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_focusInEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.focusInEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_focusNextPrevChild(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_focusNextPrevChild_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusNextPrevChild(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::focusNextPrevChild(cppArg0) : cppSelf->focusNextPrevChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_focusNextPrevChild_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.focusNextPrevChild", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_focusOutEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: focusOutEvent(QFocusEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFOCUSEVENT_IDX], (pyArg)))) {
        overloadId = 0; // focusOutEvent(QFocusEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_focusOutEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFocusEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // focusOutEvent(QFocusEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::focusOutEvent(cppArg0) : cppSelf->focusOutEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_focusOutEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFocusEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.focusOutEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_getPaintContext(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPaintContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractTextDocumentLayout::PaintContext cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->getPaintContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_inputMethodEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: inputMethodEvent(QInputMethodEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX], (pyArg)))) {
        overloadId = 0; // inputMethodEvent(QInputMethodEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_inputMethodEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QInputMethodEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodEvent(QInputMethodEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::inputMethodEvent(cppArg0) : cppSelf->inputMethodEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_inputMethodEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QInputMethodEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.inputMethodEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_inputMethodQuery(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_inputMethodQuery_TypeError;

    // Call function/method
    {
        ::Qt::InputMethodQuery cppArg0 = ((::Qt::InputMethodQuery)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // inputMethodQuery(Qt::InputMethodQuery)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPlainTextEdit*>(cppSelf)->::QPlainTextEdit::inputMethodQuery(cppArg0) : const_cast<const ::QPlainTextEdit*>(cppSelf)->inputMethodQuery(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_inputMethodQuery_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.InputMethodQuery", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.inputMethodQuery", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_insertFromMimeData(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertFromMimeData(const QMimeData*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArg)))) {
        overloadId = 0; // insertFromMimeData(const QMimeData*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_insertFromMimeData_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMimeData* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // insertFromMimeData(const QMimeData*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::insertFromMimeData(cppArg0) : cppSelf->insertFromMimeData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_insertFromMimeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMimeData", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.insertFromMimeData", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_insertPlainText(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: insertPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // insertPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_insertPlainText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // insertPlainText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertPlainText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_insertPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.insertPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_isReadOnly(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QPlainTextEditFunc_isUndoRedoEnabled(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUndoRedoEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->isUndoRedoEnabled();
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

static PyObject* Sbk_QPlainTextEditFunc_keyPressEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyPressEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_keyReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYEVENT_IDX], (pyArg)))) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeyEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // keyReleaseEvent(QKeyEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_lineWrapMode(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // lineWrapMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPlainTextEdit::LineWrapMode cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->lineWrapMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_loadResource(PyObject* self, PyObject* args)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "loadResource", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: loadResource(int,QUrl)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], (pyArgs[1])))) {
        overloadId = 0; // loadResource(int,QUrl)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_loadResource_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QUrl cppArg1_local = ::QUrl();
        ::QUrl* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QURL_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // loadResource(int,QUrl)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::loadResource(cppArg0, *cppArg1) : cppSelf->loadResource(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPlainTextEditFunc_loadResource_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QUrl", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit.loadResource", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_maximumBlockCount(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumBlockCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->maximumBlockCount();
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

static PyObject* Sbk_QPlainTextEditFunc_mergeCurrentCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mergeCurrentCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // mergeCurrentCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_mergeCurrentCharFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCharFormat cppArg0_local = ::QTextCharFormat();
        ::QTextCharFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // mergeCurrentCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->mergeCurrentCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_mergeCurrentCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.mergeCurrentCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_mouseDoubleClickEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseDoubleClickEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_mouseMoveEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseMoveEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_mousePressEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mousePressEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_mouseReleaseEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMOUSEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMouseEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // mouseReleaseEvent(QMouseEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_moveCursor(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.moveCursor(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.moveCursor(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:moveCursor", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: moveCursor(QTextCursor::MoveOperation,QTextCursor::MoveMode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // moveCursor(QTextCursor::MoveOperation,QTextCursor::MoveMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // moveCursor(QTextCursor::MoveOperation,QTextCursor::MoveMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_moveCursor_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPlainTextEdit.moveCursor(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QPlainTextEditFunc_moveCursor_TypeError;
            }
        }
        ::QTextCursor::MoveOperation cppArg0 = ((::QTextCursor::MoveOperation)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QTextCursor::MoveMode cppArg1 = QTextCursor::MoveAnchor;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // moveCursor(QTextCursor::MoveOperation,QTextCursor::MoveMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->moveCursor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_moveCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCursor.MoveOperation, PySide.QtGui.QTextCursor.MoveMode = QTextCursor.MoveAnchor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit.moveCursor", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_overwriteMode(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // overwriteMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->overwriteMode();
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

static PyObject* Sbk_QPlainTextEditFunc_paintEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTEVENT_IDX], (pyArg)))) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_paintEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // paintEvent(QPaintEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_paste(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_print_(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: print(QPrinter*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (pyArg)))) {
        overloadId = 0; // print(QPrinter*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_print__TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPrinter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // print(QPrinter*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QPlainTextEdit*>(cppSelf)->print(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_print__TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.print_", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_redo(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_resizeEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], (pyArg)))) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_resizeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QResizeEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // resizeEvent(QResizeEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_scrollContentsBy(PyObject* self, PyObject* args)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_scrollContentsBy_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scrollContentsBy(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::scrollContentsBy(cppArg0, cppArg1) : cppSelf->scrollContentsBy(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_scrollContentsBy_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPlainTextEdit.scrollContentsBy", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_selectAll(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_setBackgroundVisible(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackgroundVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setBackgroundVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setBackgroundVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBackgroundVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackgroundVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setBackgroundVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setBackgroundVisible", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setCenterOnScroll(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCenterOnScroll(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCenterOnScroll(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setCenterOnScroll_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCenterOnScroll(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCenterOnScroll(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setCenterOnScroll_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setCenterOnScroll", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setCurrentCharFormat(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentCharFormat(QTextCharFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], (pyArg)))) {
        overloadId = 0; // setCurrentCharFormat(QTextCharFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setCurrentCharFormat_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCharFormat cppArg0_local = ::QTextCharFormat();
        ::QTextCharFormat* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setCurrentCharFormat(QTextCharFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentCharFormat(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setCurrentCharFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCharFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setCurrentCharFormat", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setCursorWidth(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCursorWidth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCursorWidth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setCursorWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCursorWidth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCursorWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setCursorWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setCursorWidth", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setDocument(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocument(QTextDocument*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX], (pyArg)))) {
        overloadId = 0; // setDocument(QTextDocument*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setDocument_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextDocument* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocument(QTextDocument*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocument(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setDocument_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextDocument", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setDocument", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setDocumentTitle(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocumentTitle(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDocumentTitle(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setDocumentTitle_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocumentTitle(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocumentTitle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setDocumentTitle_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setDocumentTitle", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setExtraSelections(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setExtraSelections(QList<QTextEdit::ExtraSelection>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTEXTEDIT_EXTRASELECTION_IDX], (pyArg)))) {
        overloadId = 0; // setExtraSelections(QList<QTextEdit::ExtraSelection>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setExtraSelections_TypeError;

    // Call function/method
    {
        ::QList<QTextEdit::ExtraSelection > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setExtraSelections(QList<QTextEdit::ExtraSelection>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setExtraSelections(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setExtraSelections_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setExtraSelections", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setLineWrapMode(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLineWrapMode(QPlainTextEdit::LineWrapMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setLineWrapMode(QPlainTextEdit::LineWrapMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setLineWrapMode_TypeError;

    // Call function/method
    {
        ::QPlainTextEdit::LineWrapMode cppArg0 = ((::QPlainTextEdit::LineWrapMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLineWrapMode(QPlainTextEdit::LineWrapMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLineWrapMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setLineWrapMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPlainTextEdit.LineWrapMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setLineWrapMode", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setMaximumBlockCount(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumBlockCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setMaximumBlockCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setMaximumBlockCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaximumBlockCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumBlockCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setMaximumBlockCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setMaximumBlockCount", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setOverwriteMode(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOverwriteMode(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOverwriteMode(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setOverwriteMode_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOverwriteMode(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOverwriteMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setOverwriteMode_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setOverwriteMode", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setPlainText(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPlainText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPlainText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setPlainText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPlainText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPlainText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setPlainText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setPlainText", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setReadOnly_TypeError;

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

    Sbk_QPlainTextEditFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setTabChangesFocus(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabChangesFocus(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setTabChangesFocus(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setTabChangesFocus_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabChangesFocus(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabChangesFocus(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setTabChangesFocus_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setTabChangesFocus", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setTabStopWidth(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTabStopWidth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setTabStopWidth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setTabStopWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTabStopWidth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTabStopWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setTabStopWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setTabStopWidth", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setTextCursor(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextCursor(QTextCursor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], (pyArg)))) {
        overloadId = 0; // setTextCursor(QTextCursor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setTextCursor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTextCursor cppArg0_local = ::QTextCursor();
        ::QTextCursor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTextCursor(QTextCursor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextCursor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setTextCursor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextCursor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setTextCursor", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setTextInteractionFlags(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextInteractionFlags(QFlags<Qt::TextInteractionFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setTextInteractionFlags(QFlags<Qt::TextInteractionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setTextInteractionFlags_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::TextInteractionFlag> cppArg0 = ((::QFlags<Qt::TextInteractionFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextInteractionFlags(QFlags<Qt::TextInteractionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextInteractionFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setTextInteractionFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.TextInteractionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setTextInteractionFlags", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setUndoRedoEnabled(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUndoRedoEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setUndoRedoEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setUndoRedoEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUndoRedoEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUndoRedoEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setUndoRedoEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setUndoRedoEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_setWordWrapMode(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWordWrapMode(QTextOption::WrapMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setWordWrapMode(QTextOption::WrapMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_setWordWrapMode_TypeError;

    // Call function/method
    {
        ::QTextOption::WrapMode cppArg0 = ((::QTextOption::WrapMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWordWrapMode(QTextOption::WrapMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWordWrapMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_setWordWrapMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTextOption.WrapMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.setWordWrapMode", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_showEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: showEvent(QShowEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSHOWEVENT_IDX], (pyArg)))) {
        overloadId = 0; // showEvent(QShowEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_showEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QShowEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // showEvent(QShowEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::showEvent(cppArg0) : cppSelf->showEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_showEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QShowEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.showEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_tabChangesFocus(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabChangesFocus()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->tabChangesFocus();
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

static PyObject* Sbk_QPlainTextEditFunc_tabStopWidth(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tabStopWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->tabStopWidth();
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

static PyObject* Sbk_QPlainTextEditFunc_textCursor(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textCursor()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextCursor cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->textCursor();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTCURSOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_textInteractionFlags(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textInteractionFlags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::TextInteractionFlag> cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->textInteractionFlags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_TEXTINTERACTIONFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPlainTextEditFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_toPlainText(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPlainText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->toPlainText();
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

static PyObject* Sbk_QPlainTextEditFunc_undo(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QPlainTextEditFunc_wheelEvent(PyObject* self, PyObject* pyArg)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: wheelEvent(QWheelEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWHEELEVENT_IDX], (pyArg)))) {
        overloadId = 0; // wheelEvent(QWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPlainTextEditFunc_wheelEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWheelEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // wheelEvent(QWheelEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPlainTextEdit::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPlainTextEditFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPlainTextEdit.wheelEvent", overloads);
        return 0;
}

static PyObject* Sbk_QPlainTextEditFunc_wordWrapMode(PyObject* self)
{
    ::QPlainTextEdit* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPlainTextEdit*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wordWrapMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTextOption::WrapMode cppResult = const_cast<const ::QPlainTextEdit*>(cppSelf)->wordWrapMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPlainTextEdit_methods[] = {
    {"anchorAt", (PyCFunction)Sbk_QPlainTextEditFunc_anchorAt, METH_O},
    {"appendHtml", (PyCFunction)Sbk_QPlainTextEditFunc_appendHtml, METH_O},
    {"appendPlainText", (PyCFunction)Sbk_QPlainTextEditFunc_appendPlainText, METH_O},
    {"backgroundVisible", (PyCFunction)Sbk_QPlainTextEditFunc_backgroundVisible, METH_NOARGS},
    {"blockBoundingGeometry", (PyCFunction)Sbk_QPlainTextEditFunc_blockBoundingGeometry, METH_O},
    {"blockBoundingRect", (PyCFunction)Sbk_QPlainTextEditFunc_blockBoundingRect, METH_O},
    {"blockCount", (PyCFunction)Sbk_QPlainTextEditFunc_blockCount, METH_NOARGS},
    {"canInsertFromMimeData", (PyCFunction)Sbk_QPlainTextEditFunc_canInsertFromMimeData, METH_O},
    {"canPaste", (PyCFunction)Sbk_QPlainTextEditFunc_canPaste, METH_NOARGS},
    {"centerCursor", (PyCFunction)Sbk_QPlainTextEditFunc_centerCursor, METH_NOARGS},
    {"centerOnScroll", (PyCFunction)Sbk_QPlainTextEditFunc_centerOnScroll, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QPlainTextEditFunc_changeEvent, METH_O},
    {"clear", (PyCFunction)Sbk_QPlainTextEditFunc_clear, METH_NOARGS},
    {"contentOffset", (PyCFunction)Sbk_QPlainTextEditFunc_contentOffset, METH_NOARGS},
    {"contextMenuEvent", (PyCFunction)Sbk_QPlainTextEditFunc_contextMenuEvent, METH_O},
    {"copy", (PyCFunction)Sbk_QPlainTextEditFunc_copy, METH_NOARGS},
    {"createMimeDataFromSelection", (PyCFunction)Sbk_QPlainTextEditFunc_createMimeDataFromSelection, METH_NOARGS},
    {"createStandardContextMenu", (PyCFunction)Sbk_QPlainTextEditFunc_createStandardContextMenu, METH_NOARGS},
    {"currentCharFormat", (PyCFunction)Sbk_QPlainTextEditFunc_currentCharFormat, METH_NOARGS},
    {"cursorForPosition", (PyCFunction)Sbk_QPlainTextEditFunc_cursorForPosition, METH_O},
    {"cursorRect", (PyCFunction)Sbk_QPlainTextEditFunc_cursorRect, METH_VARARGS},
    {"cursorWidth", (PyCFunction)Sbk_QPlainTextEditFunc_cursorWidth, METH_NOARGS},
    {"cut", (PyCFunction)Sbk_QPlainTextEditFunc_cut, METH_NOARGS},
    {"document", (PyCFunction)Sbk_QPlainTextEditFunc_document, METH_NOARGS},
    {"documentTitle", (PyCFunction)Sbk_QPlainTextEditFunc_documentTitle, METH_NOARGS},
    {"dragEnterEvent", (PyCFunction)Sbk_QPlainTextEditFunc_dragEnterEvent, METH_O},
    {"dragLeaveEvent", (PyCFunction)Sbk_QPlainTextEditFunc_dragLeaveEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QPlainTextEditFunc_dragMoveEvent, METH_O},
    {"dropEvent", (PyCFunction)Sbk_QPlainTextEditFunc_dropEvent, METH_O},
    {"ensureCursorVisible", (PyCFunction)Sbk_QPlainTextEditFunc_ensureCursorVisible, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QPlainTextEditFunc_event, METH_O},
    {"extraSelections", (PyCFunction)Sbk_QPlainTextEditFunc_extraSelections, METH_NOARGS},
    {"find", (PyCFunction)Sbk_QPlainTextEditFunc_find, METH_VARARGS|METH_KEYWORDS},
    {"firstVisibleBlock", (PyCFunction)Sbk_QPlainTextEditFunc_firstVisibleBlock, METH_NOARGS},
    {"focusInEvent", (PyCFunction)Sbk_QPlainTextEditFunc_focusInEvent, METH_O},
    {"focusNextPrevChild", (PyCFunction)Sbk_QPlainTextEditFunc_focusNextPrevChild, METH_O},
    {"focusOutEvent", (PyCFunction)Sbk_QPlainTextEditFunc_focusOutEvent, METH_O},
    {"getPaintContext", (PyCFunction)Sbk_QPlainTextEditFunc_getPaintContext, METH_NOARGS},
    {"inputMethodEvent", (PyCFunction)Sbk_QPlainTextEditFunc_inputMethodEvent, METH_O},
    {"inputMethodQuery", (PyCFunction)Sbk_QPlainTextEditFunc_inputMethodQuery, METH_O},
    {"insertFromMimeData", (PyCFunction)Sbk_QPlainTextEditFunc_insertFromMimeData, METH_O},
    {"insertPlainText", (PyCFunction)Sbk_QPlainTextEditFunc_insertPlainText, METH_O},
    {"isReadOnly", (PyCFunction)Sbk_QPlainTextEditFunc_isReadOnly, METH_NOARGS},
    {"isUndoRedoEnabled", (PyCFunction)Sbk_QPlainTextEditFunc_isUndoRedoEnabled, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QPlainTextEditFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QPlainTextEditFunc_keyReleaseEvent, METH_O},
    {"lineWrapMode", (PyCFunction)Sbk_QPlainTextEditFunc_lineWrapMode, METH_NOARGS},
    {"loadResource", (PyCFunction)Sbk_QPlainTextEditFunc_loadResource, METH_VARARGS},
    {"maximumBlockCount", (PyCFunction)Sbk_QPlainTextEditFunc_maximumBlockCount, METH_NOARGS},
    {"mergeCurrentCharFormat", (PyCFunction)Sbk_QPlainTextEditFunc_mergeCurrentCharFormat, METH_O},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QPlainTextEditFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QPlainTextEditFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QPlainTextEditFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QPlainTextEditFunc_mouseReleaseEvent, METH_O},
    {"moveCursor", (PyCFunction)Sbk_QPlainTextEditFunc_moveCursor, METH_VARARGS|METH_KEYWORDS},
    {"overwriteMode", (PyCFunction)Sbk_QPlainTextEditFunc_overwriteMode, METH_NOARGS},
    {"paintEvent", (PyCFunction)Sbk_QPlainTextEditFunc_paintEvent, METH_O},
    {"paste", (PyCFunction)Sbk_QPlainTextEditFunc_paste, METH_NOARGS},
    {"print_", (PyCFunction)Sbk_QPlainTextEditFunc_print_, METH_O},
    {"redo", (PyCFunction)Sbk_QPlainTextEditFunc_redo, METH_NOARGS},
    {"resizeEvent", (PyCFunction)Sbk_QPlainTextEditFunc_resizeEvent, METH_O},
    {"scrollContentsBy", (PyCFunction)Sbk_QPlainTextEditFunc_scrollContentsBy, METH_VARARGS},
    {"selectAll", (PyCFunction)Sbk_QPlainTextEditFunc_selectAll, METH_NOARGS},
    {"setBackgroundVisible", (PyCFunction)Sbk_QPlainTextEditFunc_setBackgroundVisible, METH_O},
    {"setCenterOnScroll", (PyCFunction)Sbk_QPlainTextEditFunc_setCenterOnScroll, METH_O},
    {"setCurrentCharFormat", (PyCFunction)Sbk_QPlainTextEditFunc_setCurrentCharFormat, METH_O},
    {"setCursorWidth", (PyCFunction)Sbk_QPlainTextEditFunc_setCursorWidth, METH_O},
    {"setDocument", (PyCFunction)Sbk_QPlainTextEditFunc_setDocument, METH_O},
    {"setDocumentTitle", (PyCFunction)Sbk_QPlainTextEditFunc_setDocumentTitle, METH_O},
    {"setExtraSelections", (PyCFunction)Sbk_QPlainTextEditFunc_setExtraSelections, METH_O},
    {"setLineWrapMode", (PyCFunction)Sbk_QPlainTextEditFunc_setLineWrapMode, METH_O},
    {"setMaximumBlockCount", (PyCFunction)Sbk_QPlainTextEditFunc_setMaximumBlockCount, METH_O},
    {"setOverwriteMode", (PyCFunction)Sbk_QPlainTextEditFunc_setOverwriteMode, METH_O},
    {"setPlainText", (PyCFunction)Sbk_QPlainTextEditFunc_setPlainText, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QPlainTextEditFunc_setReadOnly, METH_O},
    {"setTabChangesFocus", (PyCFunction)Sbk_QPlainTextEditFunc_setTabChangesFocus, METH_O},
    {"setTabStopWidth", (PyCFunction)Sbk_QPlainTextEditFunc_setTabStopWidth, METH_O},
    {"setTextCursor", (PyCFunction)Sbk_QPlainTextEditFunc_setTextCursor, METH_O},
    {"setTextInteractionFlags", (PyCFunction)Sbk_QPlainTextEditFunc_setTextInteractionFlags, METH_O},
    {"setUndoRedoEnabled", (PyCFunction)Sbk_QPlainTextEditFunc_setUndoRedoEnabled, METH_O},
    {"setWordWrapMode", (PyCFunction)Sbk_QPlainTextEditFunc_setWordWrapMode, METH_O},
    {"showEvent", (PyCFunction)Sbk_QPlainTextEditFunc_showEvent, METH_O},
    {"tabChangesFocus", (PyCFunction)Sbk_QPlainTextEditFunc_tabChangesFocus, METH_NOARGS},
    {"tabStopWidth", (PyCFunction)Sbk_QPlainTextEditFunc_tabStopWidth, METH_NOARGS},
    {"textCursor", (PyCFunction)Sbk_QPlainTextEditFunc_textCursor, METH_NOARGS},
    {"textInteractionFlags", (PyCFunction)Sbk_QPlainTextEditFunc_textInteractionFlags, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QPlainTextEditFunc_timerEvent, METH_O},
    {"toPlainText", (PyCFunction)Sbk_QPlainTextEditFunc_toPlainText, METH_NOARGS},
    {"undo", (PyCFunction)Sbk_QPlainTextEditFunc_undo, METH_NOARGS},
    {"wheelEvent", (PyCFunction)Sbk_QPlainTextEditFunc_wheelEvent, METH_O},
    {"wordWrapMode", (PyCFunction)Sbk_QPlainTextEditFunc_wordWrapMode, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QPlainTextEdit_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPlainTextEdit_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QPlainTextEditSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QPlainTextEdit* me = reinterpret_cast< ::QPlainTextEdit*>(obj);
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
static SbkObjectType Sbk_QPlainTextEdit_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPlainTextEdit",
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
    /*tp_traverse*/         Sbk_QPlainTextEdit_traverse,
    /*tp_clear*/            Sbk_QPlainTextEdit_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPlainTextEdit_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPlainTextEdit_Init,
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

static void* Sbk_QPlainTextEdit_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QPlainTextEdit*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QPlainTextEdit*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QPlainTextEdit_LineWrapMode_PythonToCpp_QPlainTextEdit_LineWrapMode(PyObject* pyIn, void* cppOut) {
    *((::QPlainTextEdit::LineWrapMode*)cppOut) = (::QPlainTextEdit::LineWrapMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPlainTextEdit_LineWrapMode_PythonToCpp_QPlainTextEdit_LineWrapMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX]))
        return QPlainTextEdit_LineWrapMode_PythonToCpp_QPlainTextEdit_LineWrapMode;
    return 0;
}
static PyObject* QPlainTextEdit_LineWrapMode_CppToPython_QPlainTextEdit_LineWrapMode(const void* cppIn) {
    int castCppIn = *((::QPlainTextEdit::LineWrapMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPlainTextEdit_PythonToCpp_QPlainTextEdit_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPlainTextEdit_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPlainTextEdit_PythonToCpp_QPlainTextEdit_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPlainTextEdit_Type))
        return QPlainTextEdit_PythonToCpp_QPlainTextEdit_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPlainTextEdit_PTR_CppToPython_QPlainTextEdit(const void* cppIn) {
    return PySide::getWrapperForQObject((::QPlainTextEdit*)cppIn, &Sbk_QPlainTextEdit_Type);

}

void init_QPlainTextEdit(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPlainTextEdit_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPlainTextEdit", "QPlainTextEdit*",
        &Sbk_QPlainTextEdit_Type, &Shiboken::callCppDestructor< ::QPlainTextEdit >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTSCROLLAREA_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPlainTextEdit_Type,
        QPlainTextEdit_PythonToCpp_QPlainTextEdit_PTR,
        is_QPlainTextEdit_PythonToCpp_QPlainTextEdit_PTR_Convertible,
        QPlainTextEdit_PTR_CppToPython_QPlainTextEdit);

    Shiboken::Conversions::registerConverterName(converter, "QPlainTextEdit");
    Shiboken::Conversions::registerConverterName(converter, "QPlainTextEdit*");
    Shiboken::Conversions::registerConverterName(converter, "QPlainTextEdit&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPlainTextEdit).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPlainTextEditWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QPlainTextEdit_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QPlainTextEdit_Type, &Sbk_QPlainTextEditSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QPlainTextEdit_Type, &Sbk_QPlainTextEdit_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'LineWrapMode'.
    SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPlainTextEdit_Type,
        "LineWrapMode",
        "PySide.QtGui.QPlainTextEdit.LineWrapMode",
        "QPlainTextEdit::LineWrapMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX],
        &Sbk_QPlainTextEdit_Type, "NoWrap", (long) QPlainTextEdit::NoWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX],
        &Sbk_QPlainTextEdit_Type, "WidgetWidth", (long) QPlainTextEdit::WidgetWidth))
        return ;
    // Register converter for enum 'QPlainTextEdit::LineWrapMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX],
            QPlainTextEdit_LineWrapMode_CppToPython_QPlainTextEdit_LineWrapMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPlainTextEdit_LineWrapMode_PythonToCpp_QPlainTextEdit_LineWrapMode,
            is_QPlainTextEdit_LineWrapMode_PythonToCpp_QPlainTextEdit_LineWrapMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPLAINTEXTEDIT_LINEWRAPMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPlainTextEdit::LineWrapMode");
        Shiboken::Conversions::registerConverterName(converter, "LineWrapMode");
    }
    // End of 'LineWrapMode' enum.

    PySide::Signal::registerSignals(&Sbk_QPlainTextEdit_Type, &::QPlainTextEdit::staticMetaObject);

    qRegisterMetaType< ::QPlainTextEdit::LineWrapMode >("QPlainTextEdit::LineWrapMode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QPlainTextEdit_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QPlainTextEdit_Type, &::QPlainTextEdit::staticMetaObject, sizeof(::QPlainTextEdit));
}
