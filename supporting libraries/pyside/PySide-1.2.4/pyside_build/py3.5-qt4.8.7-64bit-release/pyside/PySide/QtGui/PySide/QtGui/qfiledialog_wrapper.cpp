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

#include "qfiledialog_wrapper.h"

// Extra includes
#include <QAbstractProxyModel>
#include <QList>
#include <QUrl>
#include <qabstractitemdelegate.h>
#include <qabstractproxymodel.h>
#include <qaction.h>
#include <qbitmap.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qcursor.h>
#include <qdir.h>
#include <qevent.h>
#include <qfiledialog.h>
#include <qfileiconprovider.h>
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
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstyle.h>
#include <qurl.h>
#include <qwidget.h>
#include <qx11info_x11.h>


// Native ---------------------------------------------------------

QFileDialogWrapper::QFileDialogWrapper(QWidget * parent, QFlags<Qt::WindowType> f) : QFileDialog(parent, f) {
    // ... middle
}

QFileDialogWrapper::QFileDialogWrapper(QWidget * parent, const QString & caption, const QString & directory, const QString & filter) : QFileDialog(parent, caption, directory, filter) {
    // ... middle
}

void QFileDialogWrapper::accept()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "accept"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileDialog::accept();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QFileDialogWrapper::actionEvent(QActionEvent * event)
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

void QFileDialogWrapper::changeEvent(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileDialog::changeEvent(e);
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

void QFileDialogWrapper::childEvent(QChildEvent * arg__1)
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

void QFileDialogWrapper::closeEvent(QCloseEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::closeEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCLOSEEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QFileDialogWrapper::connectNotify(const char * signal)
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

void QFileDialogWrapper::contextMenuEvent(QContextMenuEvent * arg__1)
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

void QFileDialogWrapper::customEvent(QEvent * arg__1)
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

int QFileDialogWrapper::devType() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::disconnectNotify(const char * signal)
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

void QFileDialogWrapper::done(int result)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "done"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileDialog::done(result);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        result
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QFileDialogWrapper::dragEnterEvent(QDragEnterEvent * event)
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

void QFileDialogWrapper::dragLeaveEvent(QDragLeaveEvent * event)
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

void QFileDialogWrapper::dragMoveEvent(QDragMoveEvent * event)
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

void QFileDialogWrapper::dropEvent(QDropEvent * event)
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

void QFileDialogWrapper::enterEvent(QEvent * event)
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

bool QFileDialogWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWidget::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QFileDialogWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QFileDialogWrapper::focusInEvent(QFocusEvent * event)
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

bool QFileDialogWrapper::focusNextPrevChild(bool next)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::focusOutEvent(QFocusEvent * event)
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

int QFileDialogWrapper::heightForWidth(int arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::hideEvent(QHideEvent * event)
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

void QFileDialogWrapper::inputMethodEvent(QInputMethodEvent * event)
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

QVariant QFileDialogWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::keyPressEvent(QKeyEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::keyPressEvent(arg__1);
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

void QFileDialogWrapper::keyReleaseEvent(QKeyEvent * event)
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

void QFileDialogWrapper::languageChange()
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

void QFileDialogWrapper::leaveEvent(QEvent * event)
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

int QFileDialogWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QFileDialogWrapper::minimumSizeHint() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.minimumSizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::mouseDoubleClickEvent(QMouseEvent * event)
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

void QFileDialogWrapper::mouseMoveEvent(QMouseEvent * event)
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

void QFileDialogWrapper::mousePressEvent(QMouseEvent * event)
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

void QFileDialogWrapper::mouseReleaseEvent(QMouseEvent * event)
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

void QFileDialogWrapper::moveEvent(QMoveEvent * event)
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

QPaintEngine * QFileDialogWrapper::paintEngine() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::paintEvent(QPaintEvent * event)
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

void QFileDialogWrapper::reject()
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

void QFileDialogWrapper::resizeEvent(QResizeEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::resizeEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QRESIZEEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QFileDialogWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFileDialog::setVisible(visible);
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

void QFileDialogWrapper::showEvent(QShowEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::showEvent(arg__1);
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

QSize QFileDialogWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDialog::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFileDialog.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFileDialogWrapper::tabletEvent(QTabletEvent * event)
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

void QFileDialogWrapper::timerEvent(QTimerEvent * arg__1)
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

void QFileDialogWrapper::wheelEvent(QWheelEvent * event)
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

const QMetaObject* QFileDialogWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QFileDialog::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QFileDialogWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QFileDialog::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QFileDialogWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QFileDialogWrapper* >(this));
        return QFileDialog::qt_metacast(_clname);
}

QFileDialogWrapper::~QFileDialogWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFileDialog_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"caption", "directory", "filter", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFileDialog >()))
        return -1;

    ::QFileDialogWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OOOO:QFileDialog", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QFileDialog(QWidget*,QFlags<Qt::WindowType>)
    // 1: QFileDialog(QWidget*,QString,QString,QString)
    if (numArgs == 0) {
        overloadId = 1; // QFileDialog(QWidget*,QString,QString,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QFileDialog(QWidget*,QString,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QFileDialog(QWidget*,QString,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // QFileDialog(QWidget*,QString,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    overloadId = 1; // QFileDialog(QWidget*,QString,QString,QString)
                }
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_WINDOWTYPE__IDX]), (pyArgs[1])))) {
            overloadId = 0; // QFileDialog(QWidget*,QFlags<Qt::WindowType>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialog_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QFileDialog(QWidget * parent, QFlags<Qt::WindowType> f)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFlags<Qt::WindowType> cppArg1 = ((::QFlags<Qt::WindowType>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QFileDialog(QWidget*,QFlags<Qt::WindowType>)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileDialogWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileDialogWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QFileDialog(QWidget * parent, const QString & caption, const QString & directory, const QString & filter)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                        goto Sbk_QFileDialog_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "caption");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog(): got multiple values for keyword argument 'caption'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QFileDialog_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "directory");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog(): got multiple values for keyword argument 'directory'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_QFileDialog_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "filter");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog(): got multiple values for keyword argument 'filter'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_QFileDialog_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QString();
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QString();
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QFileDialog(QWidget*,QString,QString,QString)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QFileDialogWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QFileDialogWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFileDialog >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFileDialog_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 4))
        return -1;


    return 1;

    Sbk_QFileDialog_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.Qt.WindowFlags", "PySide.QtGui.QWidget = None, unicode = QString(), unicode = QString(), unicode = QString()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog", overloads);
        return -1;
}

static PyObject* Sbk_QFileDialogFunc_accept(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accept()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileDialog::accept() : cppSelf->accept();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFileDialogFunc_acceptMode(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // acceptMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileDialog::AcceptMode cppResult = const_cast<const ::QFileDialog*>(cppSelf)->acceptMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_changeEvent(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: changeEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // changeEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_changeEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // changeEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileDialog::changeEvent(cppArg0) : cppSelf->changeEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_changeEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.changeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_confirmOverwrite(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // confirmOverwrite()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileDialog*>(cppSelf)->confirmOverwrite();
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

static PyObject* Sbk_QFileDialogFunc_defaultSuffix(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultSuffix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileDialog*>(cppSelf)->defaultSuffix();
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

static PyObject* Sbk_QFileDialogFunc_directory(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // directory()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDir cppResult = const_cast<const ::QFileDialog*>(cppSelf)->directory();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_done(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: done(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // done(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_done_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // done(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileDialog::done(cppArg0) : cppSelf->done(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_done_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.done", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_fileMode(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fileMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileDialog::FileMode cppResult = const_cast<const ::QFileDialog*>(cppSelf)->fileMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_filter(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QDir::Filter> cppResult = const_cast<const ::QFileDialog*>(cppSelf)->filter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_filters(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // filters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFileDialog*>(cppSelf)->filters();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_getExistingDirectory(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getExistingDirectory(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:getExistingDirectory", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
    if (numArgs == 0) {
        overloadId = 0; // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[3])))) {
                    overloadId = 0; // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_getExistingDirectory_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getExistingDirectory(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QFileDialogFunc_getExistingDirectory_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caption");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getExistingDirectory(): got multiple values for keyword argument 'caption'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFileDialogFunc_getExistingDirectory_TypeError;
            }
            value = PyDict_GetItemString(kwds, "dir");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getExistingDirectory(): got multiple values for keyword argument 'dir'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QFileDialogFunc_getExistingDirectory_TypeError;
            }
            value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getExistingDirectory(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[3]))))
                    goto Sbk_QFileDialogFunc_getExistingDirectory_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QFlags<QFileDialog::Option> cppArg3 = QFileDialog::ShowDirsOnly;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // getExistingDirectory(QWidget*,QString,QString,QFlags<QFileDialog::Option>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QFileDialog::getExistingDirectory(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_getExistingDirectory_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, unicode = QString(), unicode = QString(), PySide.QtGui.QFileDialog.Options = QFileDialog.ShowDirsOnly", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.getExistingDirectory", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_getOpenFileName(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:getOpenFileName", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    if (numArgs == 0) {
        overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5])))) {
                            overloadId = 0; // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caption");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'caption'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "dir");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'dir'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "filter");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'filter'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "selectedFilter");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'selectedFilter'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileName(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5]))))
                    goto Sbk_QFileDialogFunc_getOpenFileName_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QString();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QString();
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QFlags<QFileDialog::Option> cppArg5 = QFlags<QFileDialog::Option>(0);
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // getOpenFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)


            // Begin code injection

            // TEMPLATE - return_for_QFileDialog - START
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString retval_ = QFileDialog::getOpenFileName(cppArg0, cppArg1, cppArg2, cppArg3, &cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg4));
            // TEMPLATE - return_for_QFileDialog - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_getOpenFileName_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, unicode = QString(), unicode = QString(), unicode = QString(), PySide.QtCore.QString = QString(), PySide.QtGui.QFileDialog.Options = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.getOpenFileName", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_getOpenFileNames(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:getOpenFileNames", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    if (numArgs == 0) {
        overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5])))) {
                            overloadId = 0; // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caption");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'caption'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
            value = PyDict_GetItemString(kwds, "dir");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'dir'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
            value = PyDict_GetItemString(kwds, "filter");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'filter'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
            value = PyDict_GetItemString(kwds, "selectedFilter");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'selectedFilter'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
            value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getOpenFileNames(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5]))))
                    goto Sbk_QFileDialogFunc_getOpenFileNames_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QString();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QString();
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QFlags<QFileDialog::Option> cppArg5 = QFlags<QFileDialog::Option>(0);
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // getOpenFileNames(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)


            // Begin code injection

            // TEMPLATE - return_for_QFileDialog - START
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList retval_ = QFileDialog::getOpenFileNames(cppArg0, cppArg1, cppArg2, cppArg3, &cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg4));
            // TEMPLATE - return_for_QFileDialog - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_getOpenFileNames_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, unicode = QString(), unicode = QString(), unicode = QString(), PySide.QtCore.QString = QString(), PySide.QtGui.QFileDialog.Options = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.getOpenFileNames", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_getSaveFileName(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:getSaveFileName", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    if (numArgs == 0) {
        overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        if (numArgs == 5) {
                            overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5])))) {
                            overloadId = 0; // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)
                        }
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "caption");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'caption'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "dir");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'dir'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "filter");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'filter'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "selectedFilter");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'selectedFilter'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
            value = PyDict_GetItemString(kwds, "options");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.getSaveFileName(): got multiple values for keyword argument 'options'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArgs[5]))))
                    goto Sbk_QFileDialogFunc_getSaveFileName_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QString();
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QString();
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QString();
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QString();
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QFlags<QFileDialog::Option> cppArg5 = QFlags<QFileDialog::Option>(0);
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // getSaveFileName(QWidget*,QString,QString,QString,QString*,QFlags<QFileDialog::Option>)


            // Begin code injection

            // TEMPLATE - return_for_QFileDialog - START
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString retval_ = QFileDialog::getSaveFileName(cppArg0, cppArg1, cppArg2, cppArg3, &cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg4));
            // TEMPLATE - return_for_QFileDialog - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_getSaveFileName_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None, unicode = QString(), unicode = QString(), unicode = QString(), PySide.QtCore.QString = QString(), PySide.QtGui.QFileDialog.Options = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.getSaveFileName", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_history(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // history()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFileDialog*>(cppSelf)->history();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_iconProvider(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconProvider()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileIconProvider * cppResult = const_cast<const ::QFileDialog*>(cppSelf)->iconProvider();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_isNameFilterDetailsVisible(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNameFilterDetailsVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileDialog*>(cppSelf)->isNameFilterDetailsVisible();
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

static PyObject* Sbk_QFileDialogFunc_isReadOnly(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReadOnly()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileDialog*>(cppSelf)->isReadOnly();
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

static PyObject* Sbk_QFileDialogFunc_itemDelegate(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // itemDelegate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemDelegate * cppResult = const_cast<const ::QFileDialog*>(cppSelf)->itemDelegate();
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
}

static PyObject* Sbk_QFileDialogFunc_labelText(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: labelText(QFileDialog::DialogLabel)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX]), (pyArg)))) {
        overloadId = 0; // labelText(QFileDialog::DialogLabel)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_labelText_TypeError;

    // Call function/method
    {
        ::QFileDialog::DialogLabel cppArg0 = ((::QFileDialog::DialogLabel)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // labelText(QFileDialog::DialogLabel)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileDialog*>(cppSelf)->labelText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_labelText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.DialogLabel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.labelText", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_nameFilters(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nameFilters()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFileDialog*>(cppSelf)->nameFilters();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_open(PyObject* self, PyObject* args)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs == 1)
        goto Sbk_QFileDialogFunc_open_TypeError;

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
    if (overloadId == -1) goto Sbk_QFileDialogFunc_open_TypeError;

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

    Sbk_QFileDialogFunc_open_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject, " SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.open", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_options(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // options()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QFileDialog::Option> cppResult = const_cast<const ::QFileDialog*>(cppSelf)->options();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_proxyModel(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proxyModel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractProxyModel * cppResult = const_cast<const ::QFileDialog*>(cppSelf)->proxyModel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTPROXYMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_resolveSymlinks(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resolveSymlinks()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileDialog*>(cppSelf)->resolveSymlinks();
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

static PyObject* Sbk_QFileDialogFunc_restoreState(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: restoreState(QByteArray)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], (pyArg)))) {
        overloadId = 0; // restoreState(QByteArray)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_restoreState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QByteArray cppArg0_local = ::QByteArray();
        ::QByteArray* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // restoreState(QByteArray)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->restoreState(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_restoreState_TypeError:
        const char* overloads[] = {"PySide.QtCore.QByteArray", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.restoreState", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_saveState(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // saveState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QByteArray cppResult = const_cast<const ::QFileDialog*>(cppSelf)->saveState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QBYTEARRAY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_selectFile(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: selectFile(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // selectFile(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_selectFile_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // selectFile(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->selectFile(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_selectFile_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.selectFile", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_selectFilter(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: selectFilter(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // selectFilter(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_selectFilter_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // selectFilter(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->selectFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_selectFilter_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.selectFilter", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_selectNameFilter(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: selectNameFilter(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // selectNameFilter(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_selectNameFilter_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // selectNameFilter(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->selectNameFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_selectNameFilter_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.selectNameFilter", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_selectedFiles(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedFiles()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QFileDialog*>(cppSelf)->selectedFiles();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_selectedFilter(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedFilter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileDialog*>(cppSelf)->selectedFilter();
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

static PyObject* Sbk_QFileDialogFunc_selectedNameFilter(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedNameFilter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QFileDialog*>(cppSelf)->selectedNameFilter();
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

static PyObject* Sbk_QFileDialogFunc_setAcceptMode(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAcceptMode(QFileDialog::AcceptMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setAcceptMode(QFileDialog::AcceptMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setAcceptMode_TypeError;

    // Call function/method
    {
        ::QFileDialog::AcceptMode cppArg0 = ((::QFileDialog::AcceptMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAcceptMode(QFileDialog::AcceptMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAcceptMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setAcceptMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.AcceptMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setAcceptMode", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setConfirmOverwrite(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setConfirmOverwrite(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setConfirmOverwrite(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setConfirmOverwrite_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setConfirmOverwrite(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setConfirmOverwrite(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setConfirmOverwrite_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setConfirmOverwrite", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setDefaultSuffix(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDefaultSuffix(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultSuffix(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setDefaultSuffix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultSuffix(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultSuffix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setDefaultSuffix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setDefaultSuffix", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setDirectory(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirectory(QDir)
    // 1: setDirectory(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setDirectory(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], (pyArg)))) {
        overloadId = 0; // setDirectory(QDir)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setDirectory_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setDirectory(const QDir & directory)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDir cppArg0_local = ::QDir(::QString());
            ::QDir* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDIR_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // setDirectory(QDir)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDirectory(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setDirectory(const QString & directory)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDirectory(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setDirectory(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setDirectory_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setDirectory", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setFileMode(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFileMode(QFileDialog::FileMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setFileMode(QFileDialog::FileMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setFileMode_TypeError;

    // Call function/method
    {
        ::QFileDialog::FileMode cppArg0 = ((::QFileDialog::FileMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFileMode(QFileDialog::FileMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFileMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setFileMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.FileMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setFileMode", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setFilter(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFilter(QFlags<QDir::Filter>)
    // 1: setFilter(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setFilter(QString)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QDIR_FILTER__IDX]), (pyArg)))) {
        overloadId = 0; // setFilter(QFlags<QDir::Filter>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setFilter_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setFilter(QFlags<QDir::Filter> filters)
        {
            ::QFlags<QDir::Filter> cppArg0 = ((::QFlags<QDir::Filter>)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setFilter(QFlags<QDir::Filter>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFilter(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setFilter(const QString & filter)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setFilter(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setFilter(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDir.Filters", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setFilter", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setFilters(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFilters(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setFilters(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setFilters_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFilters(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFilters(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setFilters_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setFilters", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setHistory(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHistory(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setHistory(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setHistory_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHistory(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHistory(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setHistory_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setHistory", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setIconProvider(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconProvider(QFileIconProvider*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFILEICONPROVIDER_IDX], (pyArg)))) {
        overloadId = 0; // setIconProvider(QFileIconProvider*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setIconProvider_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFileIconProvider* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconProvider(QFileIconProvider*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconProvider(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setIconProvider_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileIconProvider", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setIconProvider", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setItemDelegate(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setItemDelegate(QAbstractItemDelegate*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMDELEGATE_IDX], (pyArg)))) {
        overloadId = 0; // setItemDelegate(QAbstractItemDelegate*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setItemDelegate_TypeError;

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

    Sbk_QFileDialogFunc_setItemDelegate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemDelegate", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setItemDelegate", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setLabelText(PyObject* self, PyObject* args)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLabelText", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setLabelText(QFileDialog::DialogLabel,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setLabelText(QFileDialog::DialogLabel,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setLabelText_TypeError;

    // Call function/method
    {
        ::QFileDialog::DialogLabel cppArg0 = ((::QFileDialog::DialogLabel)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setLabelText(QFileDialog::DialogLabel,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLabelText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setLabelText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.DialogLabel, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.setLabelText", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setNameFilter(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilter(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setNameFilter(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setNameFilter_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilter(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilter(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setNameFilter_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setNameFilter", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setNameFilterDetailsVisible(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilterDetailsVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setNameFilterDetailsVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setNameFilterDetailsVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilterDetailsVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilterDetailsVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setNameFilterDetailsVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setNameFilterDetailsVisible", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setNameFilters(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNameFilters(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setNameFilters(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setNameFilters_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNameFilters(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNameFilters(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setNameFilters_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setNameFilters", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setOption(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.setOption(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.setOption(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setOption", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setOption(QFileDialog::Option,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setOption(QFileDialog::Option,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setOption(QFileDialog::Option,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setOption_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "on");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFileDialog.setOption(): got multiple values for keyword argument 'on'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QFileDialogFunc_setOption_TypeError;
            }
        }
        ::QFileDialog::Option cppArg0 = ((::QFileDialog::Option)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setOption(QFileDialog::Option,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOption(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.Option, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFileDialog.setOption", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setOptions(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOptions(QFlags<QFileDialog::Option>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), (pyArg)))) {
        overloadId = 0; // setOptions(QFlags<QFileDialog::Option>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setOptions_TypeError;

    // Call function/method
    {
        ::QFlags<QFileDialog::Option> cppArg0 = ((::QFlags<QFileDialog::Option>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOptions(QFlags<QFileDialog::Option>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOptions(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setOptions_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.Options", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setOptions", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setProxyModel(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProxyModel(QAbstractProxyModel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTPROXYMODEL_IDX], (pyArg)))) {
        overloadId = 0; // setProxyModel(QAbstractProxyModel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setProxyModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractProxyModel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProxyModel(QAbstractProxyModel*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProxyModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setProxyModel_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractProxyModel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setProxyModel", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setReadOnly(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setReadOnly(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setReadOnly(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setReadOnly_TypeError;

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

    Sbk_QFileDialogFunc_setReadOnly_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setReadOnly", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setResolveSymlinks(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setResolveSymlinks(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setResolveSymlinks(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setResolveSymlinks_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setResolveSymlinks(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setResolveSymlinks(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setResolveSymlinks_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setResolveSymlinks", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setSidebarUrls(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSidebarUrls(QList<QUrl>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX], (pyArg)))) {
        overloadId = 0; // setSidebarUrls(QList<QUrl>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setSidebarUrls_TypeError;

    // Call function/method
    {
        ::QList<QUrl > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSidebarUrls(QList<QUrl>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSidebarUrls(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setSidebarUrls_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setSidebarUrls", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setViewMode(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setViewMode(QFileDialog::ViewMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setViewMode(QFileDialog::ViewMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setViewMode_TypeError;

    // Call function/method
    {
        ::QFileDialog::ViewMode cppArg0 = ((::QFileDialog::ViewMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewMode(QFileDialog::ViewMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setViewMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setViewMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.ViewMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setViewMode", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFileDialog::setVisible(cppArg0) : cppSelf->setVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFileDialogFunc_setVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.setVisible", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_sidebarUrls(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sidebarUrls()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QUrl > cppResult = const_cast<const ::QFileDialog*>(cppSelf)->sidebarUrls();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QURL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFileDialogFunc_testOption(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testOption(QFileDialog::Option)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX]), (pyArg)))) {
        overloadId = 0; // testOption(QFileDialog::Option)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFileDialogFunc_testOption_TypeError;

    // Call function/method
    {
        ::QFileDialog::Option cppArg0 = ((::QFileDialog::Option)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testOption(QFileDialog::Option)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QFileDialog*>(cppSelf)->testOption(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFileDialogFunc_testOption_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFileDialog.Option", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFileDialog.testOption", overloads);
        return 0;
}

static PyObject* Sbk_QFileDialogFunc_viewMode(PyObject* self)
{
    ::QFileDialog* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFileDialog*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFileDialog::ViewMode cppResult = const_cast<const ::QFileDialog*>(cppSelf)->viewMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QFileDialog_methods[] = {
    {"accept", (PyCFunction)Sbk_QFileDialogFunc_accept, METH_NOARGS},
    {"acceptMode", (PyCFunction)Sbk_QFileDialogFunc_acceptMode, METH_NOARGS},
    {"changeEvent", (PyCFunction)Sbk_QFileDialogFunc_changeEvent, METH_O},
    {"confirmOverwrite", (PyCFunction)Sbk_QFileDialogFunc_confirmOverwrite, METH_NOARGS},
    {"defaultSuffix", (PyCFunction)Sbk_QFileDialogFunc_defaultSuffix, METH_NOARGS},
    {"directory", (PyCFunction)Sbk_QFileDialogFunc_directory, METH_NOARGS},
    {"done", (PyCFunction)Sbk_QFileDialogFunc_done, METH_O},
    {"fileMode", (PyCFunction)Sbk_QFileDialogFunc_fileMode, METH_NOARGS},
    {"filter", (PyCFunction)Sbk_QFileDialogFunc_filter, METH_NOARGS},
    {"filters", (PyCFunction)Sbk_QFileDialogFunc_filters, METH_NOARGS},
    {"getExistingDirectory", (PyCFunction)Sbk_QFileDialogFunc_getExistingDirectory, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"getOpenFileName", (PyCFunction)Sbk_QFileDialogFunc_getOpenFileName, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"getOpenFileNames", (PyCFunction)Sbk_QFileDialogFunc_getOpenFileNames, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"getSaveFileName", (PyCFunction)Sbk_QFileDialogFunc_getSaveFileName, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"history", (PyCFunction)Sbk_QFileDialogFunc_history, METH_NOARGS},
    {"iconProvider", (PyCFunction)Sbk_QFileDialogFunc_iconProvider, METH_NOARGS},
    {"isNameFilterDetailsVisible", (PyCFunction)Sbk_QFileDialogFunc_isNameFilterDetailsVisible, METH_NOARGS},
    {"isReadOnly", (PyCFunction)Sbk_QFileDialogFunc_isReadOnly, METH_NOARGS},
    {"itemDelegate", (PyCFunction)Sbk_QFileDialogFunc_itemDelegate, METH_NOARGS},
    {"labelText", (PyCFunction)Sbk_QFileDialogFunc_labelText, METH_O},
    {"nameFilters", (PyCFunction)Sbk_QFileDialogFunc_nameFilters, METH_NOARGS},
    {"open", (PyCFunction)Sbk_QFileDialogFunc_open, METH_VARARGS},
    {"options", (PyCFunction)Sbk_QFileDialogFunc_options, METH_NOARGS},
    {"proxyModel", (PyCFunction)Sbk_QFileDialogFunc_proxyModel, METH_NOARGS},
    {"resolveSymlinks", (PyCFunction)Sbk_QFileDialogFunc_resolveSymlinks, METH_NOARGS},
    {"restoreState", (PyCFunction)Sbk_QFileDialogFunc_restoreState, METH_O},
    {"saveState", (PyCFunction)Sbk_QFileDialogFunc_saveState, METH_NOARGS},
    {"selectFile", (PyCFunction)Sbk_QFileDialogFunc_selectFile, METH_O},
    {"selectFilter", (PyCFunction)Sbk_QFileDialogFunc_selectFilter, METH_O},
    {"selectNameFilter", (PyCFunction)Sbk_QFileDialogFunc_selectNameFilter, METH_O},
    {"selectedFiles", (PyCFunction)Sbk_QFileDialogFunc_selectedFiles, METH_NOARGS},
    {"selectedFilter", (PyCFunction)Sbk_QFileDialogFunc_selectedFilter, METH_NOARGS},
    {"selectedNameFilter", (PyCFunction)Sbk_QFileDialogFunc_selectedNameFilter, METH_NOARGS},
    {"setAcceptMode", (PyCFunction)Sbk_QFileDialogFunc_setAcceptMode, METH_O},
    {"setConfirmOverwrite", (PyCFunction)Sbk_QFileDialogFunc_setConfirmOverwrite, METH_O},
    {"setDefaultSuffix", (PyCFunction)Sbk_QFileDialogFunc_setDefaultSuffix, METH_O},
    {"setDirectory", (PyCFunction)Sbk_QFileDialogFunc_setDirectory, METH_O},
    {"setFileMode", (PyCFunction)Sbk_QFileDialogFunc_setFileMode, METH_O},
    {"setFilter", (PyCFunction)Sbk_QFileDialogFunc_setFilter, METH_O},
    {"setFilters", (PyCFunction)Sbk_QFileDialogFunc_setFilters, METH_O},
    {"setHistory", (PyCFunction)Sbk_QFileDialogFunc_setHistory, METH_O},
    {"setIconProvider", (PyCFunction)Sbk_QFileDialogFunc_setIconProvider, METH_O},
    {"setItemDelegate", (PyCFunction)Sbk_QFileDialogFunc_setItemDelegate, METH_O},
    {"setLabelText", (PyCFunction)Sbk_QFileDialogFunc_setLabelText, METH_VARARGS},
    {"setNameFilter", (PyCFunction)Sbk_QFileDialogFunc_setNameFilter, METH_O},
    {"setNameFilterDetailsVisible", (PyCFunction)Sbk_QFileDialogFunc_setNameFilterDetailsVisible, METH_O},
    {"setNameFilters", (PyCFunction)Sbk_QFileDialogFunc_setNameFilters, METH_O},
    {"setOption", (PyCFunction)Sbk_QFileDialogFunc_setOption, METH_VARARGS|METH_KEYWORDS},
    {"setOptions", (PyCFunction)Sbk_QFileDialogFunc_setOptions, METH_O},
    {"setProxyModel", (PyCFunction)Sbk_QFileDialogFunc_setProxyModel, METH_O},
    {"setReadOnly", (PyCFunction)Sbk_QFileDialogFunc_setReadOnly, METH_O},
    {"setResolveSymlinks", (PyCFunction)Sbk_QFileDialogFunc_setResolveSymlinks, METH_O},
    {"setSidebarUrls", (PyCFunction)Sbk_QFileDialogFunc_setSidebarUrls, METH_O},
    {"setViewMode", (PyCFunction)Sbk_QFileDialogFunc_setViewMode, METH_O},
    {"setVisible", (PyCFunction)Sbk_QFileDialogFunc_setVisible, METH_O},
    {"sidebarUrls", (PyCFunction)Sbk_QFileDialogFunc_sidebarUrls, METH_NOARGS},
    {"testOption", (PyCFunction)Sbk_QFileDialogFunc_testOption, METH_O},
    {"viewMode", (PyCFunction)Sbk_QFileDialogFunc_viewMode, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFileDialog_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFileDialog_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QFileDialogSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QFileDialog* me = reinterpret_cast< ::QFileDialog*>(obj);
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
static SbkObjectType Sbk_QFileDialog_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFileDialog",
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
    /*tp_traverse*/         Sbk_QFileDialog_traverse,
    /*tp_clear*/            Sbk_QFileDialog_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFileDialog_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFileDialog_Init,
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

static void* Sbk_QFileDialog_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QFileDialog*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QFileDialog*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QFileDialog_Option___and__(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog::Options cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFileDialog::Options)PyLong_AsLong(self);
    cppArg = (QFileDialog::Options)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFileDialog::Options)PyInt_AsLong(self);
    cppArg = (QFileDialog::Options)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QFileDialog_Option___or__(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog::Options cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFileDialog::Options)PyLong_AsLong(self);
    cppArg = (QFileDialog::Options)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFileDialog::Options)PyInt_AsLong(self);
    cppArg = (QFileDialog::Options)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QFileDialog_Option___xor__(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog::Options cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QFileDialog::Options)PyLong_AsLong(self);
    cppArg = (QFileDialog::Options)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QFileDialog::Options)PyInt_AsLong(self);
    cppArg = (QFileDialog::Options)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QFileDialog_Option___invert__(PyObject* self, PyObject* pyArg)
{
    ::QFileDialog::Options cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), self, &cppSelf);
    ::QFileDialog::Options cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QFileDialog_Option_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QFileDialog_Option__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QFileDialog_Option_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QFileDialog_Option__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QFileDialog_Option___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QFileDialog_Option___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QFileDialog_Option___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QFileDialog_Option___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QFileDialog_Option_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QFileDialog_Option_long,
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
static void QFileDialog_ViewMode_PythonToCpp_QFileDialog_ViewMode(PyObject* pyIn, void* cppOut) {
    *((::QFileDialog::ViewMode*)cppOut) = (::QFileDialog::ViewMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileDialog_ViewMode_PythonToCpp_QFileDialog_ViewMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX]))
        return QFileDialog_ViewMode_PythonToCpp_QFileDialog_ViewMode;
    return 0;
}
static PyObject* QFileDialog_ViewMode_CppToPython_QFileDialog_ViewMode(const void* cppIn) {
    int castCppIn = *((::QFileDialog::ViewMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX], castCppIn);

}

static void QFileDialog_FileMode_PythonToCpp_QFileDialog_FileMode(PyObject* pyIn, void* cppOut) {
    *((::QFileDialog::FileMode*)cppOut) = (::QFileDialog::FileMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileDialog_FileMode_PythonToCpp_QFileDialog_FileMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX]))
        return QFileDialog_FileMode_PythonToCpp_QFileDialog_FileMode;
    return 0;
}
static PyObject* QFileDialog_FileMode_CppToPython_QFileDialog_FileMode(const void* cppIn) {
    int castCppIn = *((::QFileDialog::FileMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX], castCppIn);

}

static void QFileDialog_AcceptMode_PythonToCpp_QFileDialog_AcceptMode(PyObject* pyIn, void* cppOut) {
    *((::QFileDialog::AcceptMode*)cppOut) = (::QFileDialog::AcceptMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileDialog_AcceptMode_PythonToCpp_QFileDialog_AcceptMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX]))
        return QFileDialog_AcceptMode_PythonToCpp_QFileDialog_AcceptMode;
    return 0;
}
static PyObject* QFileDialog_AcceptMode_CppToPython_QFileDialog_AcceptMode(const void* cppIn) {
    int castCppIn = *((::QFileDialog::AcceptMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX], castCppIn);

}

static void QFileDialog_DialogLabel_PythonToCpp_QFileDialog_DialogLabel(PyObject* pyIn, void* cppOut) {
    *((::QFileDialog::DialogLabel*)cppOut) = (::QFileDialog::DialogLabel) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileDialog_DialogLabel_PythonToCpp_QFileDialog_DialogLabel_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX]))
        return QFileDialog_DialogLabel_PythonToCpp_QFileDialog_DialogLabel;
    return 0;
}
static PyObject* QFileDialog_DialogLabel_CppToPython_QFileDialog_DialogLabel(const void* cppIn) {
    int castCppIn = *((::QFileDialog::DialogLabel*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX], castCppIn);

}

static void QFileDialog_Option_PythonToCpp_QFileDialog_Option(PyObject* pyIn, void* cppOut) {
    *((::QFileDialog::Option*)cppOut) = (::QFileDialog::Option) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFileDialog_Option_PythonToCpp_QFileDialog_Option_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX]))
        return QFileDialog_Option_PythonToCpp_QFileDialog_Option;
    return 0;
}
static PyObject* QFileDialog_Option_CppToPython_QFileDialog_Option(const void* cppIn) {
    int castCppIn = *((::QFileDialog::Option*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX], castCppIn);

}

static void QFlags_QFileDialog_Option__PythonToCpp_QFlags_QFileDialog_Option_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFileDialog::Option>*)cppOut) = ::QFlags<QFileDialog::Option>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QFileDialog_Option__PythonToCpp_QFlags_QFileDialog_Option__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]))
        return QFlags_QFileDialog_Option__PythonToCpp_QFlags_QFileDialog_Option_;
    return 0;
}
static PyObject* QFlags_QFileDialog_Option__CppToPython_QFlags_QFileDialog_Option_(const void* cppIn) {
    int castCppIn = *((::QFlags<QFileDialog::Option>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]));

}

static void QFileDialog_Option_PythonToCpp_QFlags_QFileDialog_Option_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QFileDialog::Option>*)cppOut) = ::QFlags<QFileDialog::Option>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QFileDialog_Option_PythonToCpp_QFlags_QFileDialog_Option__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX]))
        return QFileDialog_Option_PythonToCpp_QFlags_QFileDialog_Option_;
    return 0;
}
static void number_PythonToCpp_QFlags_QFileDialog_Option_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QFileDialog::Option>*)cppOut) = ::QFlags<QFileDialog::Option>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QFileDialog_Option__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QFileDialog_Option_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFileDialog_PythonToCpp_QFileDialog_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFileDialog_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFileDialog_PythonToCpp_QFileDialog_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFileDialog_Type))
        return QFileDialog_PythonToCpp_QFileDialog_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFileDialog_PTR_CppToPython_QFileDialog(const void* cppIn) {
    return PySide::getWrapperForQObject((::QFileDialog*)cppIn, &Sbk_QFileDialog_Type);

}

void init_QFileDialog(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFileDialog_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFileDialog", "QFileDialog*",
        &Sbk_QFileDialog_Type, &Shiboken::callCppDestructor< ::QFileDialog >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QDIALOG_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFileDialog_Type,
        QFileDialog_PythonToCpp_QFileDialog_PTR,
        is_QFileDialog_PythonToCpp_QFileDialog_PTR_Convertible,
        QFileDialog_PTR_CppToPython_QFileDialog);

    Shiboken::Conversions::registerConverterName(converter, "QFileDialog");
    Shiboken::Conversions::registerConverterName(converter, "QFileDialog*");
    Shiboken::Conversions::registerConverterName(converter, "QFileDialog&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileDialog).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFileDialogWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QFileDialog_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QFileDialog_Type, &Sbk_QFileDialogSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFileDialog_Type, &Sbk_QFileDialog_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ViewMode'.
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileDialog_Type,
        "ViewMode",
        "PySide.QtGui.QFileDialog.ViewMode",
        "QFileDialog::ViewMode");
    if (!SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX],
        &Sbk_QFileDialog_Type, "Detail", (long) QFileDialog::Detail))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX],
        &Sbk_QFileDialog_Type, "List", (long) QFileDialog::List))
        return ;
    // Register converter for enum 'QFileDialog::ViewMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX],
            QFileDialog_ViewMode_CppToPython_QFileDialog_ViewMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_ViewMode_PythonToCpp_QFileDialog_ViewMode,
            is_QFileDialog_ViewMode_PythonToCpp_QFileDialog_ViewMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_VIEWMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileDialog::ViewMode");
        Shiboken::Conversions::registerConverterName(converter, "ViewMode");
    }
    // End of 'ViewMode' enum.

    // Initialization of enum 'FileMode'.
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileDialog_Type,
        "FileMode",
        "PySide.QtGui.QFileDialog.FileMode",
        "QFileDialog::FileMode");
    if (!SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
        &Sbk_QFileDialog_Type, "AnyFile", (long) QFileDialog::AnyFile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
        &Sbk_QFileDialog_Type, "ExistingFile", (long) QFileDialog::ExistingFile))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
        &Sbk_QFileDialog_Type, "Directory", (long) QFileDialog::Directory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
        &Sbk_QFileDialog_Type, "ExistingFiles", (long) QFileDialog::ExistingFiles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
        &Sbk_QFileDialog_Type, "DirectoryOnly", (long) QFileDialog::DirectoryOnly))
        return ;
    // Register converter for enum 'QFileDialog::FileMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX],
            QFileDialog_FileMode_CppToPython_QFileDialog_FileMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_FileMode_PythonToCpp_QFileDialog_FileMode,
            is_QFileDialog_FileMode_PythonToCpp_QFileDialog_FileMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_FILEMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileDialog::FileMode");
        Shiboken::Conversions::registerConverterName(converter, "FileMode");
    }
    // End of 'FileMode' enum.

    // Initialization of enum 'AcceptMode'.
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileDialog_Type,
        "AcceptMode",
        "PySide.QtGui.QFileDialog.AcceptMode",
        "QFileDialog::AcceptMode");
    if (!SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX],
        &Sbk_QFileDialog_Type, "AcceptOpen", (long) QFileDialog::AcceptOpen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX],
        &Sbk_QFileDialog_Type, "AcceptSave", (long) QFileDialog::AcceptSave))
        return ;
    // Register converter for enum 'QFileDialog::AcceptMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX],
            QFileDialog_AcceptMode_CppToPython_QFileDialog_AcceptMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_AcceptMode_PythonToCpp_QFileDialog_AcceptMode,
            is_QFileDialog_AcceptMode_PythonToCpp_QFileDialog_AcceptMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_ACCEPTMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileDialog::AcceptMode");
        Shiboken::Conversions::registerConverterName(converter, "AcceptMode");
    }
    // End of 'AcceptMode' enum.

    // Initialization of enum 'DialogLabel'.
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileDialog_Type,
        "DialogLabel",
        "PySide.QtGui.QFileDialog.DialogLabel",
        "QFileDialog::DialogLabel");
    if (!SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
        &Sbk_QFileDialog_Type, "LookIn", (long) QFileDialog::LookIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
        &Sbk_QFileDialog_Type, "FileName", (long) QFileDialog::FileName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
        &Sbk_QFileDialog_Type, "FileType", (long) QFileDialog::FileType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
        &Sbk_QFileDialog_Type, "Accept", (long) QFileDialog::Accept))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
        &Sbk_QFileDialog_Type, "Reject", (long) QFileDialog::Reject))
        return ;
    // Register converter for enum 'QFileDialog::DialogLabel'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX],
            QFileDialog_DialogLabel_CppToPython_QFileDialog_DialogLabel);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_DialogLabel_PythonToCpp_QFileDialog_DialogLabel,
            is_QFileDialog_DialogLabel_PythonToCpp_QFileDialog_DialogLabel_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_DIALOGLABEL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileDialog::DialogLabel");
        Shiboken::Conversions::registerConverterName(converter, "DialogLabel");
    }
    // End of 'DialogLabel' enum.

    // Initialization of enum 'Option'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX] = PySide::QFlags::create("Options", &SbkPySide_QtGui_QFileDialog_Option_as_number);
    SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFileDialog_Type,
        "Option",
        "PySide.QtGui.QFileDialog.Option",
        "QFileDialog::Option",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "ShowDirsOnly", (long) QFileDialog::ShowDirsOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "DontResolveSymlinks", (long) QFileDialog::DontResolveSymlinks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "DontConfirmOverwrite", (long) QFileDialog::DontConfirmOverwrite))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "DontUseSheet", (long) QFileDialog::DontUseSheet))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "DontUseNativeDialog", (long) QFileDialog::DontUseNativeDialog))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "ReadOnly", (long) QFileDialog::ReadOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "HideNameFilterDetails", (long) QFileDialog::HideNameFilterDetails))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
        &Sbk_QFileDialog_Type, "DontUseCustomDirectoryIcons", (long) QFileDialog::DontUseCustomDirectoryIcons))
        return ;
    // Register converter for enum 'QFileDialog::Option'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX],
            QFileDialog_Option_CppToPython_QFileDialog_Option);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_Option_PythonToCpp_QFileDialog_Option,
            is_QFileDialog_Option_PythonToCpp_QFileDialog_Option_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFILEDIALOG_OPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFileDialog::Option");
        Shiboken::Conversions::registerConverterName(converter, "Option");
    }
    // Register converter for flag 'QFlags<QFileDialog::Option>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX],
            QFlags_QFileDialog_Option__CppToPython_QFlags_QFileDialog_Option_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFileDialog_Option_PythonToCpp_QFlags_QFileDialog_Option_,
            is_QFileDialog_Option_PythonToCpp_QFlags_QFileDialog_Option__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QFileDialog_Option__PythonToCpp_QFlags_QFileDialog_Option_,
            is_QFlags_QFileDialog_Option__PythonToCpp_QFlags_QFileDialog_Option__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QFileDialog_Option_,
            is_number_PythonToCpp_QFlags_QFileDialog_Option__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QFILEDIALOG_OPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QFileDialog::Option>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<Option>");
    }
    // End of 'Option' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QFileDialog_Type, &::QFileDialog::staticMetaObject);

    qRegisterMetaType< ::QFileDialog::ViewMode >("QFileDialog::ViewMode");
    qRegisterMetaType< ::QFileDialog::FileMode >("QFileDialog::FileMode");
    qRegisterMetaType< ::QFileDialog::AcceptMode >("QFileDialog::AcceptMode");
    qRegisterMetaType< ::QFileDialog::DialogLabel >("QFileDialog::DialogLabel");
    qRegisterMetaType< ::QFileDialog::Option >("QFileDialog::Option");
    qRegisterMetaType< ::QFileDialog::Options >("QFileDialog::Options");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QFileDialog_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QFileDialog_Type, &::QFileDialog::staticMetaObject, sizeof(::QFileDialog));
}
