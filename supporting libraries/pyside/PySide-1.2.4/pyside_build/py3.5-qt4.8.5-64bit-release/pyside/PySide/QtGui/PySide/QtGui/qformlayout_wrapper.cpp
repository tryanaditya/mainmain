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

#include "qformlayout_wrapper.h"

// Extra includes
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

QFormLayoutWrapper::QFormLayoutWrapper(QWidget * parent) : QFormLayout(parent) {
    // ... middle
}

void QFormLayoutWrapper::addItem(QLayoutItem * item)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addItem"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QFormLayout::addItem(item);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], item)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }

}

void QFormLayoutWrapper::childEvent(QChildEvent * e)
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

void QFormLayoutWrapper::connectNotify(const char * signal)
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

int QFormLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::count();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFormLayoutWrapper::customEvent(QEvent * arg__1)
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

void QFormLayoutWrapper::disconnectNotify(const char * signal)
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

bool QFormLayoutWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QFormLayoutWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QFlags<Qt::Orientation> QFormLayoutWrapper::expandingDirections() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::Orientation>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "expandingDirections"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::expandingDirections();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.expandingDirections", Shiboken::SbkType< QFlags<Qt::Orientation> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::Orientation>)0);
    }
    ::QFlags<Qt::Orientation> cppResult = ((::QFlags<Qt::Orientation>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QFormLayoutWrapper::geometry() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.geometry", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QFormLayoutWrapper::hasHeightForWidth() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::hasHeightForWidth();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.hasHeightForWidth", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QFormLayoutWrapper::heightForWidth(int width) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::heightForWidth(width);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        width
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QFormLayoutWrapper::indexOf(QWidget * arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.indexOf", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFormLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QFormLayoutWrapper::isEmpty() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.isEmpty", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QFormLayoutWrapper::itemAt(int index) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QFormLayout::itemAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.itemAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);

    return cppResult;
}

QLayout * QFormLayoutWrapper::layout()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.layout", Shiboken::SbkType< QLayout >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayout*)0);
    }
    ::QLayout* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QFormLayoutWrapper::maximumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "maximumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayout::maximumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.maximumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QFormLayoutWrapper::minimumHeightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QLayoutItem::minimumHeightForWidth(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.minimumHeightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QFormLayoutWrapper::minimumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::minimumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.minimumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFormLayoutWrapper::setGeometry(const QRect & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::setGeometry(rect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSize QFormLayoutWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSpacerItem * QFormLayoutWrapper::spacerItem()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.spacerItem", Shiboken::SbkType< QSpacerItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QSpacerItem*)0);
    }
    ::QSpacerItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QFormLayoutWrapper::takeAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QFormLayout::takeAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.takeAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QFormLayoutWrapper::timerEvent(QTimerEvent * arg__1)
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

QWidget * QFormLayoutWrapper::widget()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QFormLayout.widget", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QFormLayoutWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QFormLayout::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QFormLayoutWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QFormLayout::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QFormLayoutWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QFormLayoutWrapper* >(this));
        return QFormLayout::qt_metacast(_clname);
}

QFormLayoutWrapper::~QFormLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QFormLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QFormLayout >()))
        return -1;

    ::QFormLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QFormLayout", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QFormLayout(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QFormLayout(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // QFormLayout(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayout_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QFormLayout(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QFormLayout_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QFormLayout(QWidget*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QFormLayoutWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QFormLayoutWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QFormLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QFormLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QFormLayout_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout", overloads);
        return -1;
}

static PyObject* Sbk_QFormLayoutFunc_addItem(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addItem(QLayoutItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // addItem(QLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_addItem_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFormLayout::addItem(cppArg0) : cppSelf->addItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_addItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.addItem", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_addRow(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addRow", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: addRow(QLayout*)
    // 1: addRow(QWidget*,QLayout*)
    // 2: addRow(QWidget*,QWidget*)
    // 3: addRow(QWidget*)
    // 4: addRow(QString,QLayout*)
    // 5: addRow(QString,QWidget*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // addRow(QWidget*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 2; // addRow(QWidget*,QWidget*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[1])))) {
            overloadId = 1; // addRow(QWidget*,QLayout*)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[0])))) {
        overloadId = 0; // addRow(QLayout*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            overloadId = 5; // addRow(QString,QWidget*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[1])))) {
            overloadId = 4; // addRow(QString,QLayout*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_addRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addRow(QLayout * layout)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayout* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addRow(QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 1: // addRow(QWidget * label, QLayout * field)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QLayout* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addRow(QWidget*,QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 2: // addRow(QWidget * label, QWidget * field)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addRow(QWidget*,QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 3: // addRow(QWidget * widget)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addRow(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 4: // addRow(const QString & labelText, QLayout * field)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QLayout* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addRow(QString,QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 5: // addRow(const QString & labelText, QWidget * field)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // addRow(QString,QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addRow(cppArg0, cppArg1);
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

    Sbk_QFormLayoutFunc_addRow_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout", "PySide.QtGui.QWidget, PySide.QtGui.QLayout", "PySide.QtGui.QWidget, PySide.QtGui.QWidget", "PySide.QtGui.QWidget", "unicode, PySide.QtGui.QLayout", "unicode, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.addRow", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_count(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::count() : const_cast<const ::QFormLayout*>(cppSelf)->count();
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

static PyObject* Sbk_QFormLayoutFunc_expandingDirections(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expandingDirections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::Orientation> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::expandingDirections() : const_cast<const ::QFormLayout*>(cppSelf)->expandingDirections();
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

static PyObject* Sbk_QFormLayoutFunc_fieldGrowthPolicy(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fieldGrowthPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFormLayout::FieldGrowthPolicy cppResult = const_cast<const ::QFormLayout*>(cppSelf)->fieldGrowthPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFormLayoutFunc_formAlignment(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // formAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QFormLayout*>(cppSelf)->formAlignment();
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

static PyObject* Sbk_QFormLayoutFunc_getItemPosition(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getItemPosition(int,int*,QFormLayout::ItemRole*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getItemPosition(int,int*,QFormLayout::ItemRole*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_getItemPosition_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getItemPosition(int,int*,QFormLayout::ItemRole*)const
            // Begin code injection

            // TEMPLATE - fix_args,int*,ItemRole* - START
            int _row;
            QFormLayout::ItemRole _role;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getItemPosition(cppArg0, &_row, &_role);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_row));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), &_role));
            // TEMPLATE - fix_args,int*,ItemRole* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFormLayoutFunc_getItemPosition_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.int, PySide.QtGui.QFormLayout.ItemRole", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.getItemPosition", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_getLayoutPosition(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getLayoutPosition(QLayout*,int*,QFormLayout::ItemRole*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArg)))) {
        overloadId = 0; // getLayoutPosition(QLayout*,int*,QFormLayout::ItemRole*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_getLayoutPosition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QLayout* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getLayoutPosition(QLayout*,int*,QFormLayout::ItemRole*)const
            // Begin code injection

            // TEMPLATE - fix_args,int*,ItemRole* - START
            int _row;
            QFormLayout::ItemRole _role;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getLayoutPosition(cppArg0, &_row, &_role);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_row));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), &_role));
            // TEMPLATE - fix_args,int*,ItemRole* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFormLayoutFunc_getLayoutPosition_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout, PySide.QtCore.int, PySide.QtGui.QFormLayout.ItemRole", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.getLayoutPosition", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_getWidgetPosition(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getWidgetPosition(QWidget*,int*,QFormLayout::ItemRole*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // getWidgetPosition(QWidget*,int*,QFormLayout::ItemRole*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_getWidgetPosition_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getWidgetPosition(QWidget*,int*,QFormLayout::ItemRole*)const
            // Begin code injection

            // TEMPLATE - fix_args,int*,ItemRole* - START
            int _row;
            QFormLayout::ItemRole _role;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->getWidgetPosition(cppArg0, &_row, &_role);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &_row));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), &_role));
            // TEMPLATE - fix_args,int*,ItemRole* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFormLayoutFunc_getWidgetPosition_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, PySide.QtCore.int, PySide.QtGui.QFormLayout.ItemRole", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.getWidgetPosition", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_hasHeightForWidth(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasHeightForWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::hasHeightForWidth() : const_cast<const ::QFormLayout*>(cppSelf)->hasHeightForWidth();
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

static PyObject* Sbk_QFormLayoutFunc_heightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_heightForWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // heightForWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::heightForWidth(cppArg0) : const_cast<const ::QFormLayout*>(cppSelf)->heightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QFormLayoutFunc_heightForWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.heightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_horizontalSpacing(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFormLayout*>(cppSelf)->horizontalSpacing();
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

static PyObject* Sbk_QFormLayoutFunc_insertRow(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertRow", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: insertRow(int,QLayout*)
    // 1: insertRow(int,QWidget*,QLayout*)
    // 2: insertRow(int,QWidget*,QWidget*)
    // 3: insertRow(int,QWidget*)
    // 4: insertRow(int,QString,QLayout*)
    // 5: insertRow(int,QString,QWidget*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // insertRow(int,QWidget*)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 2; // insertRow(int,QWidget*,QWidget*)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[2])))) {
                overloadId = 1; // insertRow(int,QWidget*,QLayout*)
            }
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertRow(int,QLayout*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 5; // insertRow(int,QString,QWidget*)
            } else if (numArgs == 3
                && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[2])))) {
                overloadId = 4; // insertRow(int,QString,QLayout*)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_insertRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertRow(int row, QLayout * layout)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QLayout* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 1: // insertRow(int row, QWidget * label, QLayout * field)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QLayout* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // insertRow(int,QWidget*,QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
        case 2: // insertRow(int row, QWidget * label, QWidget * field)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QWidget* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // insertRow(int,QWidget*,QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
        case 3: // insertRow(int row, QWidget * widget)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 4: // insertRow(int row, const QString & labelText, QLayout * field)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QLayout* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // insertRow(int,QString,QLayout*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
        case 5: // insertRow(int row, const QString & labelText, QWidget * field)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QWidget* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // insertRow(int,QString,QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_insertRow_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QLayout", "int, PySide.QtGui.QWidget, PySide.QtGui.QLayout", "int, PySide.QtGui.QWidget, PySide.QtGui.QWidget", "int, PySide.QtGui.QWidget", "int, unicode, PySide.QtGui.QLayout", "int, unicode, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.insertRow", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_invalidate(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFormLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QFormLayoutFunc_itemAt(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemAt", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: itemAt(int)const
    // 1: itemAt(int,QFormLayout::ItemRole)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // itemAt(int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // itemAt(int,QFormLayout::ItemRole)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_itemAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // itemAt(int index) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // itemAt(int)const

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::itemAt(cppArg0) : const_cast<const ::QFormLayout*>(cppSelf)->itemAt(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], cppResult);

                // Begin code injection

                addLayoutOwnership(cppSelf, cppResult);

                // End of code injection

                // Ownership transferences.
            }
            break;
        }
        case 1: // itemAt(int row, QFormLayout::ItemRole role) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QFormLayout::ItemRole cppArg1 = ((::QFormLayout::ItemRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // itemAt(int,QFormLayout::ItemRole)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QLayoutItem * cppResult = const_cast<const ::QFormLayout*>(cppSelf)->itemAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], cppResult);
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

    Sbk_QFormLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", "int, PySide.QtGui.QFormLayout.ItemRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_labelAlignment(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // labelAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QFormLayout*>(cppSelf)->labelAlignment();
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

static PyObject* Sbk_QFormLayoutFunc_labelForField(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: labelForField(QLayout*)const
    // 1: labelForField(QWidget*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 1; // labelForField(QWidget*)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArg)))) {
        overloadId = 0; // labelForField(QLayout*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_labelForField_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // labelForField(QLayout * field) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QLayout* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // labelForField(QLayout*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = const_cast<const ::QFormLayout*>(cppSelf)->labelForField(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // labelForField(QWidget * field) const
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // labelForField(QWidget*)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QWidget * cppResult = const_cast<const ::QFormLayout*>(cppSelf)->labelForField(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
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

    Sbk_QFormLayoutFunc_labelForField_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.labelForField", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_minimumSize(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::minimumSize() : const_cast<const ::QFormLayout*>(cppSelf)->minimumSize();
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

static PyObject* Sbk_QFormLayoutFunc_rowCount(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFormLayout*>(cppSelf)->rowCount();
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

static PyObject* Sbk_QFormLayoutFunc_rowWrapPolicy(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowWrapPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFormLayout::RowWrapPolicy cppResult = const_cast<const ::QFormLayout*>(cppSelf)->rowWrapPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QFormLayoutFunc_setFieldGrowthPolicy(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setFieldGrowthPolicy_TypeError;

    // Call function/method
    {
        ::QFormLayout::FieldGrowthPolicy cppArg0 = ((::QFormLayout::FieldGrowthPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFieldGrowthPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setFieldGrowthPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFormLayout.FieldGrowthPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setFieldGrowthPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setFormAlignment(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFormAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFormAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setFormAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFormAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFormAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setFormAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setFormAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setGeometry_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFormLayout::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setHorizontalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setHorizontalSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setHorizontalSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalSpacing(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setHorizontalSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setHorizontalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setItem(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setItem", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setItem(int,QFormLayout::ItemRole,QLayoutItem*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], (pyArgs[2])))) {
        overloadId = 0; // setItem(int,QFormLayout::ItemRole,QLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFormLayout::ItemRole cppArg1 = ((::QFormLayout::ItemRole)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QLayoutItem* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setItem(int,QFormLayout::ItemRole,QLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setItem(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[2]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setItem_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QFormLayout.ItemRole, PySide.QtGui.QLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.setItem", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setLabelAlignment(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLabelAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setLabelAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setLabelAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLabelAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLabelAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setLabelAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setLabelAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setLayout(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLayout", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setLayout(int,QFormLayout::ItemRole,QLayout*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[2])))) {
        overloadId = 0; // setLayout(int,QFormLayout::ItemRole,QLayout*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setLayout_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFormLayout::ItemRole cppArg1 = ((::QFormLayout::ItemRole)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QLayout* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setLayout(int,QFormLayout::ItemRole,QLayout*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLayout(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[2]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setLayout_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QFormLayout.ItemRole, PySide.QtGui.QLayout", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.setLayout", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setRowWrapPolicy(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRowWrapPolicy(QFormLayout::RowWrapPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setRowWrapPolicy(QFormLayout::RowWrapPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setRowWrapPolicy_TypeError;

    // Call function/method
    {
        ::QFormLayout::RowWrapPolicy cppArg0 = ((::QFormLayout::RowWrapPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRowWrapPolicy(QFormLayout::RowWrapPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowWrapPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setRowWrapPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFormLayout.RowWrapPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setRowWrapPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setSpacing(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setSpacing_TypeError;

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

    Sbk_QFormLayoutFunc_setSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setVerticalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setVerticalSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setVerticalSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalSpacing(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setVerticalSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.setVerticalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_setWidget(PyObject* self, PyObject* args)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setWidget", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setWidget(int,QFormLayout::ItemRole,QWidget*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
        overloadId = 0; // setWidget(int,QFormLayout::ItemRole,QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_setWidget_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFormLayout::ItemRole cppArg1 = ((::QFormLayout::ItemRole)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setWidget(int,QFormLayout::ItemRole,QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidget(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[2]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QFormLayoutFunc_setWidget_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QFormLayout.ItemRole, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QFormLayout.setWidget", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_sizeHint(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QFormLayout*>(cppSelf)->::QFormLayout::sizeHint() : const_cast<const ::QFormLayout*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QFormLayoutFunc_spacing(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFormLayout*>(cppSelf)->spacing();
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

static PyObject* Sbk_QFormLayoutFunc_takeAt(PyObject* self, PyObject* pyArg)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QFormLayoutFunc_takeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QFormLayout::takeAt(cppArg0) : cppSelf->takeAt(cppArg0);
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

    Sbk_QFormLayoutFunc_takeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QFormLayout.takeAt", overloads);
        return 0;
}

static PyObject* Sbk_QFormLayoutFunc_verticalSpacing(PyObject* self)
{
    ::QFormLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QFormLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QFormLayout*>(cppSelf)->verticalSpacing();
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

static PyMethodDef Sbk_QFormLayout_methods[] = {
    {"addItem", (PyCFunction)Sbk_QFormLayoutFunc_addItem, METH_O},
    {"addRow", (PyCFunction)Sbk_QFormLayoutFunc_addRow, METH_VARARGS},
    {"count", (PyCFunction)Sbk_QFormLayoutFunc_count, METH_NOARGS},
    {"expandingDirections", (PyCFunction)Sbk_QFormLayoutFunc_expandingDirections, METH_NOARGS},
    {"fieldGrowthPolicy", (PyCFunction)Sbk_QFormLayoutFunc_fieldGrowthPolicy, METH_NOARGS},
    {"formAlignment", (PyCFunction)Sbk_QFormLayoutFunc_formAlignment, METH_NOARGS},
    {"getItemPosition", (PyCFunction)Sbk_QFormLayoutFunc_getItemPosition, METH_O},
    {"getLayoutPosition", (PyCFunction)Sbk_QFormLayoutFunc_getLayoutPosition, METH_O},
    {"getWidgetPosition", (PyCFunction)Sbk_QFormLayoutFunc_getWidgetPosition, METH_O},
    {"hasHeightForWidth", (PyCFunction)Sbk_QFormLayoutFunc_hasHeightForWidth, METH_NOARGS},
    {"heightForWidth", (PyCFunction)Sbk_QFormLayoutFunc_heightForWidth, METH_O},
    {"horizontalSpacing", (PyCFunction)Sbk_QFormLayoutFunc_horizontalSpacing, METH_NOARGS},
    {"insertRow", (PyCFunction)Sbk_QFormLayoutFunc_insertRow, METH_VARARGS},
    {"invalidate", (PyCFunction)Sbk_QFormLayoutFunc_invalidate, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QFormLayoutFunc_itemAt, METH_VARARGS},
    {"labelAlignment", (PyCFunction)Sbk_QFormLayoutFunc_labelAlignment, METH_NOARGS},
    {"labelForField", (PyCFunction)Sbk_QFormLayoutFunc_labelForField, METH_O},
    {"minimumSize", (PyCFunction)Sbk_QFormLayoutFunc_minimumSize, METH_NOARGS},
    {"rowCount", (PyCFunction)Sbk_QFormLayoutFunc_rowCount, METH_NOARGS},
    {"rowWrapPolicy", (PyCFunction)Sbk_QFormLayoutFunc_rowWrapPolicy, METH_NOARGS},
    {"setFieldGrowthPolicy", (PyCFunction)Sbk_QFormLayoutFunc_setFieldGrowthPolicy, METH_O},
    {"setFormAlignment", (PyCFunction)Sbk_QFormLayoutFunc_setFormAlignment, METH_O},
    {"setGeometry", (PyCFunction)Sbk_QFormLayoutFunc_setGeometry, METH_O},
    {"setHorizontalSpacing", (PyCFunction)Sbk_QFormLayoutFunc_setHorizontalSpacing, METH_O},
    {"setItem", (PyCFunction)Sbk_QFormLayoutFunc_setItem, METH_VARARGS},
    {"setLabelAlignment", (PyCFunction)Sbk_QFormLayoutFunc_setLabelAlignment, METH_O},
    {"setLayout", (PyCFunction)Sbk_QFormLayoutFunc_setLayout, METH_VARARGS},
    {"setRowWrapPolicy", (PyCFunction)Sbk_QFormLayoutFunc_setRowWrapPolicy, METH_O},
    {"setSpacing", (PyCFunction)Sbk_QFormLayoutFunc_setSpacing, METH_O},
    {"setVerticalSpacing", (PyCFunction)Sbk_QFormLayoutFunc_setVerticalSpacing, METH_O},
    {"setWidget", (PyCFunction)Sbk_QFormLayoutFunc_setWidget, METH_VARARGS},
    {"sizeHint", (PyCFunction)Sbk_QFormLayoutFunc_sizeHint, METH_NOARGS},
    {"spacing", (PyCFunction)Sbk_QFormLayoutFunc_spacing, METH_NOARGS},
    {"takeAt", (PyCFunction)Sbk_QFormLayoutFunc_takeAt, METH_O},
    {"verticalSpacing", (PyCFunction)Sbk_QFormLayoutFunc_verticalSpacing, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QFormLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QFormLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QFormLayoutSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QFormLayout* me = reinterpret_cast< ::QFormLayout*>(obj);
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
static SbkObjectType Sbk_QFormLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QFormLayout",
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
    /*tp_traverse*/         Sbk_QFormLayout_traverse,
    /*tp_clear*/            Sbk_QFormLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QFormLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QFormLayout_Init,
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

static void* Sbk_QFormLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QFormLayout*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QLayoutItem >()))
        return dynamic_cast< ::QFormLayout*>(reinterpret_cast< ::QLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QFormLayout_FieldGrowthPolicy_PythonToCpp_QFormLayout_FieldGrowthPolicy(PyObject* pyIn, void* cppOut) {
    *((::QFormLayout::FieldGrowthPolicy*)cppOut) = (::QFormLayout::FieldGrowthPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFormLayout_FieldGrowthPolicy_PythonToCpp_QFormLayout_FieldGrowthPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX]))
        return QFormLayout_FieldGrowthPolicy_PythonToCpp_QFormLayout_FieldGrowthPolicy;
    return 0;
}
static PyObject* QFormLayout_FieldGrowthPolicy_CppToPython_QFormLayout_FieldGrowthPolicy(const void* cppIn) {
    int castCppIn = *((::QFormLayout::FieldGrowthPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX], castCppIn);

}

static void QFormLayout_RowWrapPolicy_PythonToCpp_QFormLayout_RowWrapPolicy(PyObject* pyIn, void* cppOut) {
    *((::QFormLayout::RowWrapPolicy*)cppOut) = (::QFormLayout::RowWrapPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFormLayout_RowWrapPolicy_PythonToCpp_QFormLayout_RowWrapPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX]))
        return QFormLayout_RowWrapPolicy_PythonToCpp_QFormLayout_RowWrapPolicy;
    return 0;
}
static PyObject* QFormLayout_RowWrapPolicy_CppToPython_QFormLayout_RowWrapPolicy(const void* cppIn) {
    int castCppIn = *((::QFormLayout::RowWrapPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX], castCppIn);

}

static void QFormLayout_ItemRole_PythonToCpp_QFormLayout_ItemRole(PyObject* pyIn, void* cppOut) {
    *((::QFormLayout::ItemRole*)cppOut) = (::QFormLayout::ItemRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QFormLayout_ItemRole_PythonToCpp_QFormLayout_ItemRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX]))
        return QFormLayout_ItemRole_PythonToCpp_QFormLayout_ItemRole;
    return 0;
}
static PyObject* QFormLayout_ItemRole_CppToPython_QFormLayout_ItemRole(const void* cppIn) {
    int castCppIn = *((::QFormLayout::ItemRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QFormLayout_PythonToCpp_QFormLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QFormLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QFormLayout_PythonToCpp_QFormLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QFormLayout_Type))
        return QFormLayout_PythonToCpp_QFormLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QFormLayout_PTR_CppToPython_QFormLayout(const void* cppIn) {
    return PySide::getWrapperForQObject((::QFormLayout*)cppIn, &Sbk_QFormLayout_Type);

}

void init_QFormLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QFormLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QFormLayout", "QFormLayout*",
        &Sbk_QFormLayout_Type, &Shiboken::callCppDestructor< ::QFormLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QFormLayout_Type,
        QFormLayout_PythonToCpp_QFormLayout_PTR,
        is_QFormLayout_PythonToCpp_QFormLayout_PTR_Convertible,
        QFormLayout_PTR_CppToPython_QFormLayout);

    Shiboken::Conversions::registerConverterName(converter, "QFormLayout");
    Shiboken::Conversions::registerConverterName(converter, "QFormLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QFormLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFormLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QFormLayoutWrapper).name());



    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QFormLayout_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QFormLayout_Type, &Sbk_QFormLayoutSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QFormLayout_Type, &Sbk_QFormLayout_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'FieldGrowthPolicy'.
    SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFormLayout_Type,
        "FieldGrowthPolicy",
        "PySide.QtGui.QFormLayout.FieldGrowthPolicy",
        "QFormLayout::FieldGrowthPolicy");
    if (!SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX],
        &Sbk_QFormLayout_Type, "FieldsStayAtSizeHint", (long) QFormLayout::FieldsStayAtSizeHint))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX],
        &Sbk_QFormLayout_Type, "ExpandingFieldsGrow", (long) QFormLayout::ExpandingFieldsGrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX],
        &Sbk_QFormLayout_Type, "AllNonFixedFieldsGrow", (long) QFormLayout::AllNonFixedFieldsGrow))
        return ;
    // Register converter for enum 'QFormLayout::FieldGrowthPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX],
            QFormLayout_FieldGrowthPolicy_CppToPython_QFormLayout_FieldGrowthPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFormLayout_FieldGrowthPolicy_PythonToCpp_QFormLayout_FieldGrowthPolicy,
            is_QFormLayout_FieldGrowthPolicy_PythonToCpp_QFormLayout_FieldGrowthPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_FIELDGROWTHPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFormLayout::FieldGrowthPolicy");
        Shiboken::Conversions::registerConverterName(converter, "FieldGrowthPolicy");
    }
    // End of 'FieldGrowthPolicy' enum.

    // Initialization of enum 'RowWrapPolicy'.
    SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFormLayout_Type,
        "RowWrapPolicy",
        "PySide.QtGui.QFormLayout.RowWrapPolicy",
        "QFormLayout::RowWrapPolicy");
    if (!SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX],
        &Sbk_QFormLayout_Type, "DontWrapRows", (long) QFormLayout::DontWrapRows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX],
        &Sbk_QFormLayout_Type, "WrapLongRows", (long) QFormLayout::WrapLongRows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX],
        &Sbk_QFormLayout_Type, "WrapAllRows", (long) QFormLayout::WrapAllRows))
        return ;
    // Register converter for enum 'QFormLayout::RowWrapPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX],
            QFormLayout_RowWrapPolicy_CppToPython_QFormLayout_RowWrapPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFormLayout_RowWrapPolicy_PythonToCpp_QFormLayout_RowWrapPolicy,
            is_QFormLayout_RowWrapPolicy_PythonToCpp_QFormLayout_RowWrapPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ROWWRAPPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFormLayout::RowWrapPolicy");
        Shiboken::Conversions::registerConverterName(converter, "RowWrapPolicy");
    }
    // End of 'RowWrapPolicy' enum.

    // Initialization of enum 'ItemRole'.
    SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QFormLayout_Type,
        "ItemRole",
        "PySide.QtGui.QFormLayout.ItemRole",
        "QFormLayout::ItemRole");
    if (!SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX],
        &Sbk_QFormLayout_Type, "LabelRole", (long) QFormLayout::LabelRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX],
        &Sbk_QFormLayout_Type, "FieldRole", (long) QFormLayout::FieldRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX],
        &Sbk_QFormLayout_Type, "SpanningRole", (long) QFormLayout::SpanningRole))
        return ;
    // Register converter for enum 'QFormLayout::ItemRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX],
            QFormLayout_ItemRole_CppToPython_QFormLayout_ItemRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFormLayout_ItemRole_PythonToCpp_QFormLayout_ItemRole,
            is_QFormLayout_ItemRole_PythonToCpp_QFormLayout_ItemRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFORMLAYOUT_ITEMROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFormLayout::ItemRole");
        Shiboken::Conversions::registerConverterName(converter, "ItemRole");
    }
    // End of 'ItemRole' enum.



    qRegisterMetaType< ::QFormLayout::FieldGrowthPolicy >("QFormLayout::FieldGrowthPolicy");
    qRegisterMetaType< ::QFormLayout::RowWrapPolicy >("QFormLayout::RowWrapPolicy");
    qRegisterMetaType< ::QFormLayout::ItemRole >("QFormLayout::ItemRole");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QFormLayout_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QFormLayout_Type, &::QFormLayout::staticMetaObject, sizeof(::QFormLayout));
}

