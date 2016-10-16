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

#include "qboxlayout_wrapper.h"

// Extra includes
#include <qboxlayout.h>
#include <qcoreevent.h>
#include <qlayout.h>
#include <qlayoutitem.h>
#include <qmargins.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qrect.h>
#include <qsize.h>
#include <qwidget.h>


// Begin code injection
// ========================================================================
// START of custom code block [file: glue/qlayout_help_functions.cpp]
void addLayoutOwnership(QLayout* layout, QLayoutItem* item);
void removeLayoutOwnership(QLayout* layout, QWidget* widget);

inline QByteArray retrieveObjectName(PyObject* obj)
{
    Shiboken::AutoDecRef objName(PyObject_Str(obj));
    return Shiboken::String::toCString(objName);
}

inline void addLayoutOwnership(QLayout* layout, QWidget* widget)
{
    //transfer ownership to parent widget
    QWidget *lw = layout->parentWidget();
    QWidget *pw = widget->parentWidget();

   Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget));

    //Transfer parent to layout widget
    if (pw && lw && pw != lw)
        Shiboken::Object::setParent(0, pyChild);

    if (!lw && !pw) {
        //keep the reference while the layout is orphan
        Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], layout));
        Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(pyParent.object()), retrieveObjectName(pyParent).data(), pyChild, true);
    } else {
        if (!lw)
            lw = pw;
        Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], lw));
        Shiboken::Object::setParent(pyParent, pyChild);
    }
}

inline void addLayoutOwnership(QLayout* layout, QLayout* other)
{
    //transfer all children widgets from other to layout parent widget
    QWidget* parent = layout->parentWidget();
    if (!parent) {
        //keep the reference while the layout is orphan
        Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], layout));
        Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], other));
        Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(pyParent.object()), retrieveObjectName(pyParent).data(), pyChild, true);
        return;
    }

    for (int i=0, i_max=other->count(); i < i_max; i++) {
        QLayoutItem* item = other->itemAt(i);
        if (PyErr_Occurred() || !item)
            return;
        addLayoutOwnership(layout, item);
    }

    Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], layout));
    Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], other));
    Shiboken::Object::setParent(pyParent, pyChild);
}

inline void addLayoutOwnership(QLayout* layout, QLayoutItem* item)
{
    if (!item)
        return;

    QWidget* w = item->widget();
    if (w)
        addLayoutOwnership(layout, w);
    else {
        QLayout* l = item->layout();
        if (l)
            addLayoutOwnership(layout, l);
    }

    Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], layout));
    Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], item));
    Shiboken::Object::setParent(pyParent, pyChild);
}

static void removeWidgetFromLayout(QLayout* layout, QWidget* widget)
{
    QWidget* parent = widget->parentWidget();

    if (!parent) {
        //remove reference on layout
        Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], layout));
        Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget));
        Shiboken::Object::removeReference(reinterpret_cast<SbkObject*>(pyParent.object()), retrieveObjectName(pyParent).data(), pyChild);
    } else {
        //give the ownership to parent
        Shiboken::AutoDecRef pyParent(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], parent));
        Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget));
        Shiboken::Object::setParent(pyParent, pyChild);
    }
}

inline void removeLayoutOwnership(QLayout* layout, QLayoutItem* item)
{
    QWidget* w = item->widget();
    if (w)
        removeWidgetFromLayout(layout, w);
    else {
        QLayout* l = item->layout();
        if (l)
            removeLayoutOwnership(layout, l);
    }

    Shiboken::AutoDecRef pyChild(Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], item));
    Shiboken::Object::invalidate(pyChild);
    Shiboken::Object::setParent(0, pyChild);
}

inline void removeLayoutOwnership(QLayout* layout, QWidget* widget)
{
    if (!widget)
        return;

    for (int i=0, i_max=layout->count(); i < i_max; i++) {
        QLayoutItem* item = layout->itemAt(i);
        if (PyErr_Occurred() || !item)
            return;
        if (item->widget() == widget)
            removeLayoutOwnership(layout, item);
    }
}

// END of custom code block [file: glue/qlayout_help_functions.cpp]
// ========================================================================

// End of code injection

// Native ---------------------------------------------------------

QBoxLayoutWrapper::QBoxLayoutWrapper(QBoxLayout::Direction arg__1, QWidget * parent) : QBoxLayout(arg__1, parent) {
    // ... middle
}

void QBoxLayoutWrapper::addItem(QLayoutItem * arg__1)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addItem"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QBoxLayout::addItem(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], arg__1)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }

}

void QBoxLayoutWrapper::childEvent(QChildEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::childEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

void QBoxLayoutWrapper::connectNotify(const char * signal)
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

int QBoxLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::count();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QBoxLayoutWrapper::customEvent(QEvent * arg__1)
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

void QBoxLayoutWrapper::disconnectNotify(const char * signal)
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

bool QBoxLayoutWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QBoxLayoutWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QFlags<Qt::Orientation> QBoxLayoutWrapper::expandingDirections() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::Orientation>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "expandingDirections"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::expandingDirections();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QFlags<Qt::Orientation>)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.expandingDirections", Shiboken::SbkType< QFlags<Qt::Orientation> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::Orientation>)0);
    }
    ::QFlags<Qt::Orientation> cppResult = ((::QFlags<Qt::Orientation>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QBoxLayoutWrapper::geometry() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "geometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::geometry();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.geometry", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QBoxLayoutWrapper::hasHeightForWidth() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::hasHeightForWidth();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.hasHeightForWidth", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QBoxLayoutWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::heightForWidth(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QBoxLayoutWrapper::indexOf(QWidget * arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "indexOf"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::indexOf(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.indexOf", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QBoxLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QBoxLayoutWrapper::isEmpty() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "isEmpty"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::isEmpty();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.isEmpty", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QBoxLayoutWrapper::itemAt(int arg__1) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QBoxLayout::itemAt(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QLayoutItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.itemAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);

    return cppResult;
}

QLayout * QBoxLayoutWrapper::layout()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayout*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "layout"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::layout();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QLayout*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.layout", Shiboken::SbkType< QLayout >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayout*)0);
    }
    ::QLayout* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QBoxLayoutWrapper::maximumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "maximumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::maximumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.maximumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QBoxLayoutWrapper::minimumHeightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::minimumHeightForWidth(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.minimumHeightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QBoxLayoutWrapper::minimumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::minimumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.minimumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QBoxLayoutWrapper::setGeometry(const QRect & arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::setGeometry(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSize QBoxLayoutWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSpacerItem * QBoxLayoutWrapper::spacerItem()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QSpacerItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "spacerItem"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayoutItem::spacerItem();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QSpacerItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSPACERITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.spacerItem", Shiboken::SbkType< QSpacerItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QSpacerItem*)0);
    }
    ::QSpacerItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QBoxLayoutWrapper::takeAt(int arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QBoxLayout::takeAt(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QLayoutItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.takeAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QBoxLayoutWrapper::timerEvent(QTimerEvent * arg__1)
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

QWidget * QBoxLayoutWrapper::widget()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "widget"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayoutItem::widget();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QWidget*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QBoxLayout.widget", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QBoxLayoutWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QBoxLayout::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QBoxLayoutWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QBoxLayout::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QBoxLayoutWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QBoxLayoutWrapper* >(this));
        return QBoxLayout::qt_metacast(_clname);
}

QBoxLayoutWrapper::~QBoxLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QBoxLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QBoxLayout >()))
        return -1;

    ::QBoxLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QBoxLayout", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QBoxLayout(QBoxLayout::Direction,QWidget*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QBoxLayout(QBoxLayout::Direction,QWidget*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 0; // QBoxLayout(QBoxLayout::Direction,QWidget*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayout_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1]))))
                    goto Sbk_QBoxLayout_Init_TypeError;
            }
        }
        ::QBoxLayout::Direction cppArg0 = ((::QBoxLayout::Direction)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QWidget* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QBoxLayout(QBoxLayout::Direction,QWidget*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QBoxLayoutWrapper(cppArg0, cppArg1);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QBoxLayoutWrapper(cppArg0, cppArg1);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[1], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QBoxLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QBoxLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QBoxLayout_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBoxLayout.Direction, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout", overloads);
        return -1;
}

static PyObject* Sbk_QBoxLayoutFunc_addItem(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addItem(QLayoutItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // addItem(QLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLayoutItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addItem(QLayoutItem*)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg0);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QBoxLayout::addItem(cppArg0) : cppSelf->addItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.addItem", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addLayout(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addLayout(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addLayout(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:addLayout", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addLayout(QLayout*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addLayout(QLayout*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // addLayout(QLayout*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addLayout_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addLayout(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QBoxLayoutFunc_addLayout_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QLayout* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addLayout(QLayout*,int)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg0);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addLayout(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addLayout_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.addLayout", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addSpacerItem(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addSpacerItem(QSpacerItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSPACERITEM_IDX], (pyArg)))) {
        overloadId = 0; // addSpacerItem(QSpacerItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addSpacerItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSpacerItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addSpacerItem(QSpacerItem*)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg0);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addSpacerItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addSpacerItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSpacerItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.addSpacerItem", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addSpacing(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addSpacing(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.addSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addStretch(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addStretch(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:addStretch", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: addStretch(int)
    if (numArgs == 0) {
        overloadId = 0; // addStretch(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // addStretch(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addStretch_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addStretch(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QBoxLayoutFunc_addStretch_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // addStretch(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addStretch_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.addStretch", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addStrut(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addStrut(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // addStrut(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addStrut_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addStrut(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addStrut(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addStrut_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.addStrut", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_addWidget(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addWidget(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addWidget(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addWidget", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addWidget(QWidget*,int,QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addWidget(QWidget*,int,QFlags<Qt::AlignmentFlag>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addWidget(QWidget*,int,QFlags<Qt::AlignmentFlag>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[2])))) {
                overloadId = 0; // addWidget(QWidget*,int,QFlags<Qt::AlignmentFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_addWidget_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addWidget(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QBoxLayoutFunc_addWidget_TypeError;
            }
            value = PyDict_GetItemString(kwds, "alignment");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.addWidget(): got multiple values for keyword argument 'alignment'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[2]))))
                    goto Sbk_QBoxLayoutFunc_addWidget_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::AlignmentFlag> cppArg2 = QFlags<Qt::AlignmentFlag>(0);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addWidget(QWidget*,int,QFlags<Qt::AlignmentFlag>)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg0);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addWidget(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_addWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, int = 0, PySide.QtCore.Qt.Alignment = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.addWidget", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_count(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::count() : const_cast<const ::QBoxLayout*>(cppSelf)->count();
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

static PyObject* Sbk_QBoxLayoutFunc_direction(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // direction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBoxLayout::Direction cppResult = const_cast<const ::QBoxLayout*>(cppSelf)->direction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBoxLayoutFunc_expandingDirections(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expandingDirections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::Orientation> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::expandingDirections() : const_cast<const ::QBoxLayout*>(cppSelf)->expandingDirections();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBoxLayoutFunc_hasHeightForWidth(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasHeightForWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::hasHeightForWidth() : const_cast<const ::QBoxLayout*>(cppSelf)->hasHeightForWidth();
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

static PyObject* Sbk_QBoxLayoutFunc_heightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: heightForWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // heightForWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_heightForWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // heightForWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::heightForWidth(cppArg0) : const_cast<const ::QBoxLayout*>(cppSelf)->heightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBoxLayoutFunc_heightForWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.heightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertItem(PyObject* self, PyObject* args)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertItem(int,QLayoutItem*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertItem(int,QLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QLayoutItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertItem(int,QLayoutItem*)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg1);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertItem", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertLayout(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertLayout(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertLayout(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:insertLayout", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insertLayout(int,QLayout*,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // insertLayout(int,QLayout*,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // insertLayout(int,QLayout*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertLayout_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertLayout(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QBoxLayoutFunc_insertLayout_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QLayout* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // insertLayout(int,QLayout*,int)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg1);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertLayout(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertLayout_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QLayout, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertLayout", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertSpacerItem(PyObject* self, PyObject* args)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertSpacerItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertSpacerItem(int,QSpacerItem*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSPACERITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertSpacerItem(int,QSpacerItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertSpacerItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSpacerItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertSpacerItem(int,QSpacerItem*)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg1);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertSpacerItem(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertSpacerItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QSpacerItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertSpacerItem", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertSpacing(PyObject* self, PyObject* args)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertSpacing", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertSpacing(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // insertSpacing(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertSpacing(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertSpacing(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertSpacing_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertStretch(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertStretch(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertStretch(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:insertStretch", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertStretch(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // insertStretch(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // insertStretch(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertStretch_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertStretch(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QBoxLayoutFunc_insertStretch_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertStretch(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertStretch(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertStretch_TypeError:
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertStretch", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_insertWidget(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertWidget(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertWidget(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:insertWidget", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: insertWidget(int,QWidget*,int,QFlags<Qt::AlignmentFlag>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // insertWidget(int,QWidget*,int,QFlags<Qt::AlignmentFlag>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // insertWidget(int,QWidget*,int,QFlags<Qt::AlignmentFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 0; // insertWidget(int,QWidget*,int,QFlags<Qt::AlignmentFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_insertWidget_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "stretch");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertWidget(): got multiple values for keyword argument 'stretch'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QBoxLayoutFunc_insertWidget_TypeError;
            }
            value = PyDict_GetItemString(kwds, "alignment");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBoxLayout.insertWidget(): got multiple values for keyword argument 'alignment'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3]))))
                    goto Sbk_QBoxLayoutFunc_insertWidget_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QWidget* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QFlags<Qt::AlignmentFlag> cppArg3 = QFlags<Qt::AlignmentFlag>(0);
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // insertWidget(int,QWidget*,int,QFlags<Qt::AlignmentFlag>)
            // Begin code injection

            addLayoutOwnership(cppSelf, cppArg1);

            // End of code injection

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertWidget(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_insertWidget_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QWidget, int = 0, PySide.QtCore.Qt.Alignment = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.insertWidget", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_invalidate(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QBoxLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QBoxLayoutFunc_itemAt(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // itemAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_itemAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemAt(int)const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::itemAt(cppArg0) : const_cast<const ::QBoxLayout*>(cppSelf)->itemAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], cppResult);

            // Begin code injection

            addLayoutOwnership(cppSelf, cppResult);

            // End of code injection

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBoxLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_maximumSize(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::maximumSize() : const_cast<const ::QBoxLayout*>(cppSelf)->maximumSize();
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

static PyObject* Sbk_QBoxLayoutFunc_minimumHeightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: minimumHeightForWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // minimumHeightForWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_minimumHeightForWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // minimumHeightForWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::minimumHeightForWidth(cppArg0) : const_cast<const ::QBoxLayout*>(cppSelf)->minimumHeightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBoxLayoutFunc_minimumHeightForWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.minimumHeightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_minimumSize(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::minimumSize() : const_cast<const ::QBoxLayout*>(cppSelf)->minimumSize();
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

static PyObject* Sbk_QBoxLayoutFunc_setDirection(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirection(QBoxLayout::Direction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDirection(QBoxLayout::Direction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_setDirection_TypeError;

    // Call function/method
    {
        ::QBoxLayout::Direction cppArg0 = ((::QBoxLayout::Direction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDirection(QBoxLayout::Direction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_setDirection_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBoxLayout.Direction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.setDirection", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_setGeometry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRect cppArg0_local = ::QRect();
        ::QRect* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setGeometry(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QBoxLayout::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_setSpacing(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_setSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSpacing(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_setSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.setSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_setStretch(PyObject* self, PyObject* args)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setStretch", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStretch(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setStretch(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_setStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStretch(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStretch(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBoxLayoutFunc_setStretch_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.setStretch", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_setStretchFactor(PyObject* self, PyObject* args)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setStretchFactor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStretchFactor(QLayout*,int)
    // 1: setStretchFactor(QWidget*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // setStretchFactor(QWidget*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setStretchFactor(QLayout*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_setStretchFactor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setStretchFactor(QLayout * l, int stretch)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayout* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setStretchFactor(QLayout*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setStretchFactor(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // setStretchFactor(QWidget * w, int stretch)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setStretchFactor(QWidget*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->setStretchFactor(cppArg0, cppArg1);
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

    Sbk_QBoxLayoutFunc_setStretchFactor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout, int", "PySide.QtGui.QWidget, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBoxLayout.setStretchFactor", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_sizeHint(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QBoxLayout*>(cppSelf)->::QBoxLayout::sizeHint() : const_cast<const ::QBoxLayout*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QBoxLayoutFunc_spacing(PyObject* self)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QBoxLayout*>(cppSelf)->spacing();
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

static PyObject* Sbk_QBoxLayoutFunc_stretch(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: stretch(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // stretch(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_stretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // stretch(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QBoxLayout*>(cppSelf)->stretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBoxLayoutFunc_stretch_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.stretch", overloads);
        return 0;
}

static PyObject* Sbk_QBoxLayoutFunc_takeAt(PyObject* self, PyObject* pyArg)
{
    ::QBoxLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBoxLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBoxLayoutFunc_takeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QBoxLayout::takeAt(cppArg0) : cppSelf->takeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QBoxLayoutFunc_takeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBoxLayout.takeAt", overloads);
        return 0;
}

static PyMethodDef Sbk_QBoxLayout_methods[] = {
    {"addItem", (PyCFunction)Sbk_QBoxLayoutFunc_addItem, METH_O},
    {"addLayout", (PyCFunction)Sbk_QBoxLayoutFunc_addLayout, METH_VARARGS|METH_KEYWORDS},
    {"addSpacerItem", (PyCFunction)Sbk_QBoxLayoutFunc_addSpacerItem, METH_O},
    {"addSpacing", (PyCFunction)Sbk_QBoxLayoutFunc_addSpacing, METH_O},
    {"addStretch", (PyCFunction)Sbk_QBoxLayoutFunc_addStretch, METH_VARARGS|METH_KEYWORDS},
    {"addStrut", (PyCFunction)Sbk_QBoxLayoutFunc_addStrut, METH_O},
    {"addWidget", (PyCFunction)Sbk_QBoxLayoutFunc_addWidget, METH_VARARGS|METH_KEYWORDS},
    {"count", (PyCFunction)Sbk_QBoxLayoutFunc_count, METH_NOARGS},
    {"direction", (PyCFunction)Sbk_QBoxLayoutFunc_direction, METH_NOARGS},
    {"expandingDirections", (PyCFunction)Sbk_QBoxLayoutFunc_expandingDirections, METH_NOARGS},
    {"hasHeightForWidth", (PyCFunction)Sbk_QBoxLayoutFunc_hasHeightForWidth, METH_NOARGS},
    {"heightForWidth", (PyCFunction)Sbk_QBoxLayoutFunc_heightForWidth, METH_O},
    {"insertItem", (PyCFunction)Sbk_QBoxLayoutFunc_insertItem, METH_VARARGS},
    {"insertLayout", (PyCFunction)Sbk_QBoxLayoutFunc_insertLayout, METH_VARARGS|METH_KEYWORDS},
    {"insertSpacerItem", (PyCFunction)Sbk_QBoxLayoutFunc_insertSpacerItem, METH_VARARGS},
    {"insertSpacing", (PyCFunction)Sbk_QBoxLayoutFunc_insertSpacing, METH_VARARGS},
    {"insertStretch", (PyCFunction)Sbk_QBoxLayoutFunc_insertStretch, METH_VARARGS|METH_KEYWORDS},
    {"insertWidget", (PyCFunction)Sbk_QBoxLayoutFunc_insertWidget, METH_VARARGS|METH_KEYWORDS},
    {"invalidate", (PyCFunction)Sbk_QBoxLayoutFunc_invalidate, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QBoxLayoutFunc_itemAt, METH_O},
    {"maximumSize", (PyCFunction)Sbk_QBoxLayoutFunc_maximumSize, METH_NOARGS},
    {"minimumHeightForWidth", (PyCFunction)Sbk_QBoxLayoutFunc_minimumHeightForWidth, METH_O},
    {"minimumSize", (PyCFunction)Sbk_QBoxLayoutFunc_minimumSize, METH_NOARGS},
    {"setDirection", (PyCFunction)Sbk_QBoxLayoutFunc_setDirection, METH_O},
    {"setGeometry", (PyCFunction)Sbk_QBoxLayoutFunc_setGeometry, METH_O},
    {"setSpacing", (PyCFunction)Sbk_QBoxLayoutFunc_setSpacing, METH_O},
    {"setStretch", (PyCFunction)Sbk_QBoxLayoutFunc_setStretch, METH_VARARGS},
    {"setStretchFactor", (PyCFunction)Sbk_QBoxLayoutFunc_setStretchFactor, METH_VARARGS},
    {"sizeHint", (PyCFunction)Sbk_QBoxLayoutFunc_sizeHint, METH_NOARGS},
    {"spacing", (PyCFunction)Sbk_QBoxLayoutFunc_spacing, METH_NOARGS},
    {"stretch", (PyCFunction)Sbk_QBoxLayoutFunc_stretch, METH_O},
    {"takeAt", (PyCFunction)Sbk_QBoxLayoutFunc_takeAt, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QBoxLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QBoxLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QBoxLayoutSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QBoxLayout* me = reinterpret_cast< ::QBoxLayout*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX]))
        return static_cast< ::QLayout*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX]))
        return static_cast< ::QLayoutItem*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QBoxLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QBoxLayout",
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
    /*tp_traverse*/         Sbk_QBoxLayout_traverse,
    /*tp_clear*/            Sbk_QBoxLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QBoxLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QBoxLayout_Init,
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

static void* Sbk_QBoxLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QBoxLayout*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QLayoutItem >()))
        return dynamic_cast< ::QBoxLayout*>(reinterpret_cast< ::QLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QBoxLayout_Direction_PythonToCpp_QBoxLayout_Direction(PyObject* pyIn, void* cppOut) {
    *((::QBoxLayout::Direction*)cppOut) = (::QBoxLayout::Direction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QBoxLayout_Direction_PythonToCpp_QBoxLayout_Direction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX]))
        return QBoxLayout_Direction_PythonToCpp_QBoxLayout_Direction;
    return 0;
}
static PyObject* QBoxLayout_Direction_CppToPython_QBoxLayout_Direction(const void* cppIn) {
    int castCppIn = *((::QBoxLayout::Direction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QBoxLayout_PythonToCpp_QBoxLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QBoxLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QBoxLayout_PythonToCpp_QBoxLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBoxLayout_Type))
        return QBoxLayout_PythonToCpp_QBoxLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QBoxLayout_PTR_CppToPython_QBoxLayout(const void* cppIn) {
    return PySide::getWrapperForQObject((::QBoxLayout*)cppIn, &Sbk_QBoxLayout_Type);

}

void init_QBoxLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QBoxLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QBoxLayout", "QBoxLayout*",
        &Sbk_QBoxLayout_Type, &Shiboken::callCppDestructor< ::QBoxLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QBoxLayout_Type,
        QBoxLayout_PythonToCpp_QBoxLayout_PTR,
        is_QBoxLayout_PythonToCpp_QBoxLayout_PTR_Convertible,
        QBoxLayout_PTR_CppToPython_QBoxLayout);

    Shiboken::Conversions::registerConverterName(converter, "QBoxLayout");
    Shiboken::Conversions::registerConverterName(converter, "QBoxLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QBoxLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBoxLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBoxLayoutWrapper).name());



    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QBoxLayout_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QBoxLayout_Type, &Sbk_QBoxLayoutSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QBoxLayout_Type, &Sbk_QBoxLayout_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Direction'.
    SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QBoxLayout_Type,
        "Direction",
        "PySide.QtGui.QBoxLayout.Direction",
        "QBoxLayout::Direction");
    if (!SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "LeftToRight", (long) QBoxLayout::LeftToRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "RightToLeft", (long) QBoxLayout::RightToLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "TopToBottom", (long) QBoxLayout::TopToBottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "BottomToTop", (long) QBoxLayout::BottomToTop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "Down", (long) QBoxLayout::Down))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
        &Sbk_QBoxLayout_Type, "Up", (long) QBoxLayout::Up))
        return ;
    // Register converter for enum 'QBoxLayout::Direction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX],
            QBoxLayout_Direction_CppToPython_QBoxLayout_Direction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QBoxLayout_Direction_PythonToCpp_QBoxLayout_Direction,
            is_QBoxLayout_Direction_PythonToCpp_QBoxLayout_Direction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QBOXLAYOUT_DIRECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QBoxLayout::Direction");
        Shiboken::Conversions::registerConverterName(converter, "Direction");
    }
    // End of 'Direction' enum.



    qRegisterMetaType< ::QBoxLayout::Direction >("QBoxLayout::Direction");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QBoxLayout_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QBoxLayout_Type, &::QBoxLayout::staticMetaObject, sizeof(::QBoxLayout));
}

