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

#include "qgridlayout_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qgridlayout.h>
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

QGridLayoutWrapper::QGridLayoutWrapper() : QGridLayout() {
    // ... middle
}

QGridLayoutWrapper::QGridLayoutWrapper(QWidget * parent) : QGridLayout(parent) {
    // ... middle
}

void QGridLayoutWrapper::addItem(QLayoutItem * arg__1)
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "addItem"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QGridLayout::addItem(arg__1);
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

void QGridLayoutWrapper::childEvent(QChildEvent * e)
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

void QGridLayoutWrapper::connectNotify(const char * signal)
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

int QGridLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::count();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGridLayoutWrapper::customEvent(QEvent * arg__1)
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

void QGridLayoutWrapper::disconnectNotify(const char * signal)
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

bool QGridLayoutWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QGridLayoutWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QFlags<Qt::Orientation> QGridLayoutWrapper::expandingDirections() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QFlags<Qt::Orientation>)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "expandingDirections"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::expandingDirections();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.expandingDirections", Shiboken::SbkType< QFlags<Qt::Orientation> >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QFlags<Qt::Orientation>)0);
    }
    ::QFlags<Qt::Orientation> cppResult = ((::QFlags<Qt::Orientation>)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QGridLayoutWrapper::geometry() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.geometry", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QGridLayoutWrapper::hasHeightForWidth() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hasHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::hasHeightForWidth();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.hasHeightForWidth", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGridLayoutWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::heightForWidth(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.heightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGridLayoutWrapper::indexOf(QWidget * arg__1) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.indexOf", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGridLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QGridLayoutWrapper::isEmpty() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.isEmpty", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QGridLayoutWrapper::itemAt(int index) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QGridLayout::itemAt(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.itemAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);

    return cppResult;
}

QLayout * QGridLayoutWrapper::layout()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.layout", Shiboken::SbkType< QLayout >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayout*)0);
    }
    ::QLayout* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QGridLayoutWrapper::maximumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "maximumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::maximumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.maximumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QGridLayoutWrapper::minimumHeightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumHeightForWidth"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::minimumHeightForWidth(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.minimumHeightForWidth", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSize QGridLayoutWrapper::minimumSize() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "minimumSize"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::minimumSize();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.minimumSize", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGridLayoutWrapper::setGeometry(const QRect & arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::setGeometry(arg__1);
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

QSize QGridLayoutWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::sizeHint();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.sizeHint", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QSpacerItem * QGridLayoutWrapper::spacerItem()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.spacerItem", Shiboken::SbkType< QSpacerItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QSpacerItem*)0);
    }
    ::QSpacerItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QLayoutItem * QGridLayoutWrapper::takeAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "takeAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGridLayout::takeAt(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.takeAt", Shiboken::SbkType< QLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QLayoutItem*)0);
    }
    ::QLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGridLayoutWrapper::timerEvent(QTimerEvent * arg__1)
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

QWidget * QGridLayoutWrapper::widget()
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGridLayout.widget", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QGridLayoutWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QGridLayout::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QGridLayoutWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QGridLayout::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QGridLayoutWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QGridLayoutWrapper* >(this));
        return QGridLayout::qt_metacast(_clname);
}

QGridLayoutWrapper::~QGridLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGridLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGridLayout >()))
        return -1;

    ::QGridLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QGridLayout", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGridLayout()
    // 1: QGridLayout(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QGridLayout()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QGridLayout(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayout_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QGridLayout()
        {

            if (!PyErr_Occurred()) {
                // QGridLayout()
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGridLayoutWrapper();
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGridLayoutWrapper();
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QGridLayout(QWidget * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QGridLayout(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QGridLayoutWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QGridLayoutWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGridLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGridLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QGridLayout_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout", overloads);
        return -1;
}

static PyObject* Sbk_QGridLayoutFunc_addItem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addItem(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addItem(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QGridLayoutFunc_addItem_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOO:addItem", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addItem(QLayoutItem*)
    // 1: addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUTITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addItem(QLayoutItem*)
        } else if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 1; // addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 1; // addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5])))) {
                        overloadId = 1; // addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_addItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addItem(QLayoutItem * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayoutItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addItem(QLayoutItem*)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGridLayout::addItem(cppArg0) : cppSelf->addItem(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
        case 1: // addItem(QLayoutItem * item, int row, int column, int rowSpan, int columnSpan, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "rowSpan");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addItem(): got multiple values for keyword argument 'rowSpan'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QGridLayoutFunc_addItem_TypeError;
                }
                value = PyDict_GetItemString(kwds, "columnSpan");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addItem(): got multiple values for keyword argument 'columnSpan'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QGridLayoutFunc_addItem_TypeError;
                }
                value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addItem(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5]))))
                        goto Sbk_QGridLayoutFunc_addItem_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayoutItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 1;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::AlignmentFlag> cppArg5 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addItem(QLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_addItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayoutItem", "PySide.QtGui.QLayoutItem, int, int, int = 1, int = 1, PySide.QtCore.Qt.Alignment = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.addItem", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_addLayout(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addLayout(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addLayout(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addLayout", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addLayout(QLayout*,int,int,QFlags<Qt::AlignmentFlag>)
    // 1: addLayout(QLayout*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // addLayout(QLayout*,int,int,QFlags<Qt::AlignmentFlag>)
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addLayout(QLayout*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5])))) {
                overloadId = 1; // addLayout(QLayout*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
            }
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3])))) {
            overloadId = 0; // addLayout(QLayout*,int,int,QFlags<Qt::AlignmentFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_addLayout_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addLayout(QLayout * arg__1, int row, int column, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addLayout(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QGridLayoutFunc_addLayout_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayout* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::AlignmentFlag> cppArg3 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addLayout(QLayout*,int,int,QFlags<Qt::AlignmentFlag>)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addLayout(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
        case 1: // addLayout(QLayout * arg__1, int row, int column, int rowSpan, int columnSpan, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addLayout(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5]))))
                        goto Sbk_QGridLayoutFunc_addLayout_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLayout* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::AlignmentFlag> cppArg5 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addLayout(QLayout*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addLayout(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_addLayout_TypeError:
        const char* overloads[] = {"PySide.QtGui.QLayout, int, int, PySide.QtCore.Qt.Alignment = 0", "PySide.QtGui.QLayout, int, int, int, int, PySide.QtCore.Qt.Alignment = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.addLayout", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_addWidget(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addWidget(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addWidget(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_QGridLayoutFunc_addWidget_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOO:addWidget", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addWidget(QWidget*,int,int,QFlags<Qt::AlignmentFlag>)
    // 1: addWidget(QWidget*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
    // 2: addWidget(QWidget*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // addWidget(QWidget*)
        } else if (numArgs >= 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // addWidget(QWidget*,int,int,QFlags<Qt::AlignmentFlag>)
            } else if (numArgs >= 5
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
                && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                if (numArgs == 5) {
                    overloadId = 1; // addWidget(QWidget*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5])))) {
                    overloadId = 1; // addWidget(QWidget*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                }
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 0; // addWidget(QWidget*,int,int,QFlags<Qt::AlignmentFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_addWidget_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addWidget(QWidget * arg__1, int row, int column, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addWidget(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QGridLayoutFunc_addWidget_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::AlignmentFlag> cppArg3 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addWidget(QWidget*,int,int,QFlags<Qt::AlignmentFlag>)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addWidget(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
        case 1: // addWidget(QWidget * arg__1, int row, int column, int rowSpan, int columnSpan, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGridLayout.addWidget(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5]))))
                        goto Sbk_QGridLayoutFunc_addWidget_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::AlignmentFlag> cppArg5 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addWidget(QWidget*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addWidget(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
        case 2: // addWidget(QWidget * w)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // addWidget(QWidget*)
                // Begin code injection

                addLayoutOwnership(cppSelf, cppArg0);

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addWidget(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_addWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget, int, int, PySide.QtCore.Qt.Alignment = 0", "PySide.QtGui.QWidget, int, int, int, int, PySide.QtCore.Qt.Alignment = 0", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.addWidget", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_cellRect(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "cellRect", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: cellRect(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // cellRect(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_cellRect_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // cellRect(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QGridLayout*>(cppSelf)->cellRect(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_cellRect_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.cellRect", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_columnCount(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->columnCount();
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

static PyObject* Sbk_QGridLayoutFunc_columnMinimumWidth(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnMinimumWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnMinimumWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_columnMinimumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnMinimumWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->columnMinimumWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_columnMinimumWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.columnMinimumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_columnStretch(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnStretch(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnStretch(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_columnStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnStretch(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->columnStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_columnStretch_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.columnStretch", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_count(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::count() : const_cast<const ::QGridLayout*>(cppSelf)->count();
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

static PyObject* Sbk_QGridLayoutFunc_expandingDirections(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // expandingDirections()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::Orientation> cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::expandingDirections() : const_cast<const ::QGridLayout*>(cppSelf)->expandingDirections();
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

static PyObject* Sbk_QGridLayoutFunc_getItemPosition(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getItemPosition(int,int*,int*,int*,int*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getItemPosition(int,int*,int*,int*,int*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_getItemPosition_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getItemPosition(int,int*,int*,int*,int*)
            // Begin code injection

            int a, b, c, d;
            cppSelf->getItemPosition(cppArg0, &a, &b, &c, &d);
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &d));

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_getItemPosition_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.int, PySide.QtCore.int, PySide.QtCore.int, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.getItemPosition", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_hasHeightForWidth(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasHeightForWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::hasHeightForWidth() : const_cast<const ::QGridLayout*>(cppSelf)->hasHeightForWidth();
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

static PyObject* Sbk_QGridLayoutFunc_heightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_heightForWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // heightForWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::heightForWidth(cppArg0) : const_cast<const ::QGridLayout*>(cppSelf)->heightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_heightForWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.heightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_horizontalSpacing(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->horizontalSpacing();
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

static PyObject* Sbk_QGridLayoutFunc_invalidate(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGridLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGridLayoutFunc_itemAt(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_itemAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemAt(int)const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::itemAt(cppArg0) : const_cast<const ::QGridLayout*>(cppSelf)->itemAt(cppArg0);
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

    Sbk_QGridLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_itemAtPosition(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemAtPosition", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: itemAtPosition(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // itemAtPosition(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_itemAtPosition_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // itemAtPosition(int,int)const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = const_cast<const ::QGridLayout*>(cppSelf)->itemAtPosition(cppArg0, cppArg1);
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

    Sbk_QGridLayoutFunc_itemAtPosition_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.itemAtPosition", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_maximumSize(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::maximumSize() : const_cast<const ::QGridLayout*>(cppSelf)->maximumSize();
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

static PyObject* Sbk_QGridLayoutFunc_minimumHeightForWidth(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_minimumHeightForWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // minimumHeightForWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::minimumHeightForWidth(cppArg0) : const_cast<const ::QGridLayout*>(cppSelf)->minimumHeightForWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_minimumHeightForWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.minimumHeightForWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_minimumSize(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::minimumSize() : const_cast<const ::QGridLayout*>(cppSelf)->minimumSize();
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

static PyObject* Sbk_QGridLayoutFunc_originCorner(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // originCorner()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::Corner cppResult = const_cast<const ::QGridLayout*>(cppSelf)->originCorner();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGridLayoutFunc_rowCount(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->rowCount();
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

static PyObject* Sbk_QGridLayoutFunc_rowMinimumHeight(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowMinimumHeight(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowMinimumHeight(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_rowMinimumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowMinimumHeight(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->rowMinimumHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_rowMinimumHeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.rowMinimumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_rowStretch(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowStretch(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowStretch(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_rowStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowStretch(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->rowStretch(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGridLayoutFunc_rowStretch_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.rowStretch", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setColumnMinimumWidth(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnMinimumWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnMinimumWidth(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnMinimumWidth(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setColumnMinimumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnMinimumWidth(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnMinimumWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setColumnMinimumWidth_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.setColumnMinimumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setColumnStretch(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnStretch", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnStretch(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnStretch(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setColumnStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnStretch(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnStretch(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setColumnStretch_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.setColumnStretch", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setDefaultPositioning(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDefaultPositioning", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDefaultPositioning(int,Qt::Orientation)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setDefaultPositioning(int,Qt::Orientation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setDefaultPositioning_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::Orientation cppArg1 = ((::Qt::Orientation)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDefaultPositioning(int,Qt::Orientation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultPositioning(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setDefaultPositioning_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.setDefaultPositioning", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setGeometry_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGridLayout::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setHorizontalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setHorizontalSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setHorizontalSpacing_TypeError;

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

    Sbk_QGridLayoutFunc_setHorizontalSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.setHorizontalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setOriginCorner(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOriginCorner(Qt::Corner)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), (pyArg)))) {
        overloadId = 0; // setOriginCorner(Qt::Corner)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setOriginCorner_TypeError;

    // Call function/method
    {
        ::Qt::Corner cppArg0 = ((::Qt::Corner)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOriginCorner(Qt::Corner)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOriginCorner(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setOriginCorner_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Corner", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.setOriginCorner", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setRowMinimumHeight(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowMinimumHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowMinimumHeight(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setRowMinimumHeight(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setRowMinimumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowMinimumHeight(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowMinimumHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setRowMinimumHeight_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.setRowMinimumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setRowStretch(PyObject* self, PyObject* args)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowStretch", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowStretch(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setRowStretch(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setRowStretch_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowStretch(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowStretch(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGridLayoutFunc_setRowStretch_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGridLayout.setRowStretch", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setSpacing_TypeError;

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

    Sbk_QGridLayoutFunc_setSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.setSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_setVerticalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setVerticalSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_setVerticalSpacing_TypeError;

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

    Sbk_QGridLayoutFunc_setVerticalSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.setVerticalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_sizeHint(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGridLayout*>(cppSelf)->::QGridLayout::sizeHint() : const_cast<const ::QGridLayout*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QGridLayoutFunc_spacing(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // spacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->spacing();
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

static PyObject* Sbk_QGridLayoutFunc_takeAt(PyObject* self, PyObject* pyArg)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGridLayoutFunc_takeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGridLayout::takeAt(cppArg0) : cppSelf->takeAt(cppArg0);
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

    Sbk_QGridLayoutFunc_takeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGridLayout.takeAt", overloads);
        return 0;
}

static PyObject* Sbk_QGridLayoutFunc_verticalSpacing(PyObject* self)
{
    ::QGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGridLayout*>(cppSelf)->verticalSpacing();
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

static PyMethodDef Sbk_QGridLayout_methods[] = {
    {"addItem", (PyCFunction)Sbk_QGridLayoutFunc_addItem, METH_VARARGS|METH_KEYWORDS},
    {"addLayout", (PyCFunction)Sbk_QGridLayoutFunc_addLayout, METH_VARARGS|METH_KEYWORDS},
    {"addWidget", (PyCFunction)Sbk_QGridLayoutFunc_addWidget, METH_VARARGS|METH_KEYWORDS},
    {"cellRect", (PyCFunction)Sbk_QGridLayoutFunc_cellRect, METH_VARARGS},
    {"columnCount", (PyCFunction)Sbk_QGridLayoutFunc_columnCount, METH_NOARGS},
    {"columnMinimumWidth", (PyCFunction)Sbk_QGridLayoutFunc_columnMinimumWidth, METH_O},
    {"columnStretch", (PyCFunction)Sbk_QGridLayoutFunc_columnStretch, METH_O},
    {"count", (PyCFunction)Sbk_QGridLayoutFunc_count, METH_NOARGS},
    {"expandingDirections", (PyCFunction)Sbk_QGridLayoutFunc_expandingDirections, METH_NOARGS},
    {"getItemPosition", (PyCFunction)Sbk_QGridLayoutFunc_getItemPosition, METH_O},
    {"hasHeightForWidth", (PyCFunction)Sbk_QGridLayoutFunc_hasHeightForWidth, METH_NOARGS},
    {"heightForWidth", (PyCFunction)Sbk_QGridLayoutFunc_heightForWidth, METH_O},
    {"horizontalSpacing", (PyCFunction)Sbk_QGridLayoutFunc_horizontalSpacing, METH_NOARGS},
    {"invalidate", (PyCFunction)Sbk_QGridLayoutFunc_invalidate, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGridLayoutFunc_itemAt, METH_O},
    {"itemAtPosition", (PyCFunction)Sbk_QGridLayoutFunc_itemAtPosition, METH_VARARGS},
    {"maximumSize", (PyCFunction)Sbk_QGridLayoutFunc_maximumSize, METH_NOARGS},
    {"minimumHeightForWidth", (PyCFunction)Sbk_QGridLayoutFunc_minimumHeightForWidth, METH_O},
    {"minimumSize", (PyCFunction)Sbk_QGridLayoutFunc_minimumSize, METH_NOARGS},
    {"originCorner", (PyCFunction)Sbk_QGridLayoutFunc_originCorner, METH_NOARGS},
    {"rowCount", (PyCFunction)Sbk_QGridLayoutFunc_rowCount, METH_NOARGS},
    {"rowMinimumHeight", (PyCFunction)Sbk_QGridLayoutFunc_rowMinimumHeight, METH_O},
    {"rowStretch", (PyCFunction)Sbk_QGridLayoutFunc_rowStretch, METH_O},
    {"setColumnMinimumWidth", (PyCFunction)Sbk_QGridLayoutFunc_setColumnMinimumWidth, METH_VARARGS},
    {"setColumnStretch", (PyCFunction)Sbk_QGridLayoutFunc_setColumnStretch, METH_VARARGS},
    {"setDefaultPositioning", (PyCFunction)Sbk_QGridLayoutFunc_setDefaultPositioning, METH_VARARGS},
    {"setGeometry", (PyCFunction)Sbk_QGridLayoutFunc_setGeometry, METH_O},
    {"setHorizontalSpacing", (PyCFunction)Sbk_QGridLayoutFunc_setHorizontalSpacing, METH_O},
    {"setOriginCorner", (PyCFunction)Sbk_QGridLayoutFunc_setOriginCorner, METH_O},
    {"setRowMinimumHeight", (PyCFunction)Sbk_QGridLayoutFunc_setRowMinimumHeight, METH_VARARGS},
    {"setRowStretch", (PyCFunction)Sbk_QGridLayoutFunc_setRowStretch, METH_VARARGS},
    {"setSpacing", (PyCFunction)Sbk_QGridLayoutFunc_setSpacing, METH_O},
    {"setVerticalSpacing", (PyCFunction)Sbk_QGridLayoutFunc_setVerticalSpacing, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QGridLayoutFunc_sizeHint, METH_NOARGS},
    {"spacing", (PyCFunction)Sbk_QGridLayoutFunc_spacing, METH_NOARGS},
    {"takeAt", (PyCFunction)Sbk_QGridLayoutFunc_takeAt, METH_O},
    {"verticalSpacing", (PyCFunction)Sbk_QGridLayoutFunc_verticalSpacing, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGridLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGridLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_QGridLayoutSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QGridLayout* me = reinterpret_cast< ::QGridLayout*>(obj);
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
static SbkObjectType Sbk_QGridLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGridLayout",
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
    /*tp_traverse*/         Sbk_QGridLayout_traverse,
    /*tp_clear*/            Sbk_QGridLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGridLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGridLayout_Init,
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

static void* Sbk_QGridLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QGridLayout*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QLayoutItem >()))
        return dynamic_cast< ::QGridLayout*>(reinterpret_cast< ::QLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGridLayout_PythonToCpp_QGridLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGridLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGridLayout_PythonToCpp_QGridLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGridLayout_Type))
        return QGridLayout_PythonToCpp_QGridLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGridLayout_PTR_CppToPython_QGridLayout(const void* cppIn) {
    return PySide::getWrapperForQObject((::QGridLayout*)cppIn, &Sbk_QGridLayout_Type);

}

void init_QGridLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRIDLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGridLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGridLayout", "QGridLayout*",
        &Sbk_QGridLayout_Type, &Shiboken::callCppDestructor< ::QGridLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGridLayout_Type,
        QGridLayout_PythonToCpp_QGridLayout_PTR,
        is_QGridLayout_PythonToCpp_QGridLayout_PTR_Convertible,
        QGridLayout_PTR_CppToPython_QGridLayout);

    Shiboken::Conversions::registerConverterName(converter, "QGridLayout");
    Shiboken::Conversions::registerConverterName(converter, "QGridLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QGridLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGridLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGridLayoutWrapper).name());



    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QLAYOUT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QGridLayout_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QGridLayout_Type, &Sbk_QGridLayoutSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGridLayout_Type, &Sbk_QGridLayout_typeDiscovery);



    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QGridLayout_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QGridLayout_Type, &::QGridLayout::staticMetaObject, sizeof(::QGridLayout));
}

