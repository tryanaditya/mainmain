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
#include "pyside_qtgui_python.h"

#include "qstyle_wrapper.h"

// Extra includes
#include <QList>
#include <qapplication.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qfontmetrics.h>
#include <qicon.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qpalette.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qsize.h>
#include <qstyle.h>
#include <qstyleoption.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QStyleWrapper::QStyleWrapper() : QStyle() {
    // ... middle
}

void QStyleWrapper::childEvent(QChildEvent * arg__1)
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

void QStyleWrapper::connectNotify(const char * signal)
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

void QStyleWrapper::customEvent(QEvent * arg__1)
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

void QStyleWrapper::disconnectNotify(const char * signal)
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

void QStyleWrapper::drawComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, QPainter * p, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawComplexControl"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawComplexControl()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), &cc),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], opt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], p),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
}

void QStyleWrapper::drawControl(QStyle::ControlElement element, const QStyleOption * opt, QPainter * p, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawControl"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawControl()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX]), &element),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], p),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
}

void QStyleWrapper::drawItemPixmap(QPainter * painter, const QRect & rect, int alignment, const QPixmap & pixmap) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawItemPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::drawItemPixmap(painter, rect, alignment, pixmap);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNiN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect),
        alignment,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pixmap)
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

void QStyleWrapper::drawItemText(QPainter * painter, const QRect & rect, int flags, const QPalette & pal, bool enabled, const QString & text, QPalette::ColorRole textRole) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawItemText"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::drawItemText(painter, rect, flags, pal, enabled, text, textRole);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNiNNNN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect),
        flags,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &pal),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &enabled),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &text),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), &textRole)
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

void QStyleWrapper::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption * opt, QPainter * p, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPrimitive"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawPrimitive()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX]), &pe),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], p),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));
    bool invalidateArg3 = PyTuple_GET_ITEM(pyArgs, 2)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg3)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 2));
}

bool QStyleWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QStyleWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QPixmap QStyleWrapper::generatedIconPixmap(QIcon::Mode iconMode, const QPixmap & pixmap, const QStyleOption * opt) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "generatedIconPixmap"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.generatedIconPixmap()' not implemented.");
        return ::QPixmap();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), &iconMode),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pixmap),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPixmap();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.generatedIconPixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStyle::SubControl QStyleWrapper::hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, const QPoint & pt, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QStyle::SubControl)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hitTestComplexControl"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.hitTestComplexControl()' not implemented.");
        return ((::QStyle::SubControl)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), &cc),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], opt),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &pt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QStyle::SubControl)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.hitTestComplexControl", Shiboken::SbkType< QStyle::SubControl >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QStyle::SubControl)0);
    }
    ::QStyle::SubControl cppResult = ((::QStyle::SubControl)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QStyleWrapper::itemPixmapRect(const QRect & r, int flags, const QPixmap & pixmap) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemPixmapRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::itemPixmapRect(r, flags, pixmap);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &r),
        flags,
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pixmap)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.itemPixmapRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QStyleWrapper::itemTextRect(const QFontMetrics & fm, const QRect & r, int flags, bool enabled, const QString & text) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemTextRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::itemTextRect(fm, r, flags, enabled, text);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNiNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], &fm),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &r),
        flags,
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &enabled),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &text)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.itemTextRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QStyleWrapper::pixelMetric(QStyle::PixelMetric metric, const QStyleOption * option, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pixelMetric"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.pixelMetric()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX]), &metric),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.pixelMetric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStyleWrapper::polish(QApplication * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::polish(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStyleWrapper::polish(QPalette & arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::polish(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStyleWrapper::polish(QWidget * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::polish(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSize QStyleWrapper::sizeFromContents(QStyle::ContentsType ct, const QStyleOption * opt, const QSize & contentsSize, const QWidget * w) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeFromContents"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.sizeFromContents()' not implemented.");
        return ::QSize();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX]), &ct),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &contentsSize),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], w)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSize();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.sizeFromContents", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPalette QStyleWrapper::standardPalette() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPalette();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "standardPalette"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::standardPalette();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPalette();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.standardPalette", Shiboken::SbkType< QPalette >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPalette();
    }
    ::QPalette cppResult = ::QPalette();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPixmap QStyleWrapper::standardPixmap(QStyle::StandardPixmap standardPixmap, const QStyleOption * opt, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "standardPixmap"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.standardPixmap()' not implemented.");
        return ::QPixmap();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]), &standardPixmap),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPixmap();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.standardPixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QStyleWrapper::styleHint(QStyle::StyleHint stylehint, const QStyleOption * opt, const QWidget * widget, QStyleHintReturn * returnData) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "styleHint"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.styleHint()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX]), &stylehint),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], returnData)
    ));
    bool invalidateArg4 = PyTuple_GET_ITEM(pyArgs, 3)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.styleHint", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg4)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 3));
    return cppResult;
}

QRect QStyleWrapper::subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, QStyle::SubControl sc, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "subControlRect"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.subControlRect()' not implemented.");
        return ::QRect();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), &cc),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], opt),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), &sc),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.subControlRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QStyleWrapper::subElementRect(QStyle::SubElement subElement, const QStyleOption * option, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "subElementRect"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.subElementRect()' not implemented.");
        return ::QRect();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX]), &subElement),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QRect();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStyle.subElementRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStyleWrapper::timerEvent(QTimerEvent * arg__1)
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

void QStyleWrapper::unpolish(QApplication * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unpolish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::unpolish(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QStyleWrapper::unpolish(QWidget * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unpolish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStyle::unpolish(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

const QMetaObject* QStyleWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QStyle::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QStyleWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QStyle::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QStyleWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QStyleWrapper* >(this));
        return QStyle::qt_metacast(_clname);
}

QStyleWrapper::~QStyleWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyle_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QStyle' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyle >()))
        return -1;

    ::QStyleWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QStyle()
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QStyleWrapper();
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QStyleWrapper();
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyle >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;
}

static PyObject* Sbk_QStyleFunc_alignedRect(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "alignedRect", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: alignedRect(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>,QSize,QRect)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[3])))) {
        overloadId = 0; // alignedRect(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>,QSize,QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_alignedRect_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::AlignmentFlag> cppArg1 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QSize cppArg2_local = ::QSize();
        ::QSize* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QRect cppArg3_local = ::QRect();
        ::QRect* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);


        if (!PyErr_Occurred()) {
            // alignedRect(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>,QSize,QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = ::QStyle::alignedRect(cppArg0, cppArg1, *cppArg2, *cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_alignedRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection, PySide.QtCore.Qt.Alignment, PySide.QtCore.QSize, PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.alignedRect", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_combinedLayoutSpacing(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.combinedLayoutSpacing(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.combinedLayoutSpacing(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:combinedLayoutSpacing", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: combinedLayoutSpacing(QFlags<QSizePolicy::ControlType>,QFlags<QSizePolicy::ControlType>,Qt::Orientation,QStyleOption*,QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSIZEPOLICY_CONTROLTYPE__IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // combinedLayoutSpacing(QFlags<QSizePolicy::ControlType>,QFlags<QSizePolicy::ControlType>,Qt::Orientation,QStyleOption*,QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // combinedLayoutSpacing(QFlags<QSizePolicy::ControlType>,QFlags<QSizePolicy::ControlType>,Qt::Orientation,QStyleOption*,QWidget*)const
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4])))) {
                overloadId = 0; // combinedLayoutSpacing(QFlags<QSizePolicy::ControlType>,QFlags<QSizePolicy::ControlType>,Qt::Orientation,QStyleOption*,QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_combinedLayoutSpacing_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.combinedLayoutSpacing(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_combinedLayoutSpacing_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.combinedLayoutSpacing(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4]))))
                    goto Sbk_QStyleFunc_combinedLayoutSpacing_TypeError;
            }
        }
        ::QFlags<QSizePolicy::ControlType> cppArg0 = ((::QFlags<QSizePolicy::ControlType>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<QSizePolicy::ControlType> cppArg1 = ((::QFlags<QSizePolicy::ControlType>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::Orientation cppArg2 = ((::Qt::Orientation)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QStyleOption* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QWidget* cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // combinedLayoutSpacing(QFlags<QSizePolicy::ControlType>,QFlags<QSizePolicy::ControlType>,Qt::Orientation,QStyleOption*,QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStyle*>(cppSelf)->combinedLayoutSpacing(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_combinedLayoutSpacing_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.ControlTypes, PySide.QtGui.QSizePolicy.ControlTypes, PySide.QtCore.Qt.Orientation, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.combinedLayoutSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_drawComplexControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawComplexControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawComplexControl(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:drawComplexControl", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPainter*,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPainter*,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // drawComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPainter*,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_drawComplexControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawComplexControl(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_drawComplexControl_TypeError;
            }
        }
        ::QStyle::ComplexControl cppArg0 = ((::QStyle::ComplexControl)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionComplex* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPainter* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // drawComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPainter*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawComplexControl()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QStyle*>(cppSelf)->drawComplexControl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_drawComplexControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtGui.QPainter, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.drawComplexControl", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_drawControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawControl(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:drawControl", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawControl(QStyle::ControlElement,const QStyleOption*,QPainter*,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawControl(QStyle::ControlElement,const QStyleOption*,QPainter*,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // drawControl(QStyle::ControlElement,const QStyleOption*,QPainter*,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_drawControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawControl(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_drawControl_TypeError;
            }
        }
        ::QStyle::ControlElement cppArg0 = ((::QStyle::ControlElement)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPainter* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // drawControl(QStyle::ControlElement,const QStyleOption*,QPainter*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawControl()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QStyle*>(cppSelf)->drawControl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_drawControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ControlElement, PySide.QtGui.QStyleOption, PySide.QtGui.QPainter, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.drawControl", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_drawItemPixmap(PyObject* self, PyObject* args)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawItemPixmap", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawItemPixmap(QPainter*,QRect,int,QPixmap)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[3])))) {
        overloadId = 0; // drawItemPixmap(QPainter*,QRect,int,QPixmap)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_drawItemPixmap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPixmap cppArg3_local = ::QPixmap();
        ::QPixmap* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);


        if (!PyErr_Occurred()) {
            // drawItemPixmap(QPainter*,QRect,int,QPixmap)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStyle*>(cppSelf)->::QStyle::drawItemPixmap(cppArg0, *cppArg1, cppArg2, *cppArg3) : const_cast<const ::QStyle*>(cppSelf)->drawItemPixmap(cppArg0, *cppArg1, cppArg2, *cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_drawItemPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRect, int, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.drawItemPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_drawItemText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawItemText(): too many arguments");
        return 0;
    } else if (numArgs < 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawItemText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOO:drawItemText", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: drawItemText(QPainter*,QRect,int,QPalette,bool,QString,QPalette::ColorRole)const
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 0; // drawItemText(QPainter*,QRect,int,QPalette,bool,QString,QPalette::ColorRole)const
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[6])))) {
            overloadId = 0; // drawItemText(QPainter*,QRect,int,QPalette,bool,QString,QPalette::ColorRole)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_drawItemText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "textRole");
            if (value && pyArgs[6]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawItemText(): got multiple values for keyword argument 'textRole'.");
                return 0;
            } else if (value) {
                pyArgs[6] = value;
                if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[6]))))
                    goto Sbk_QStyleFunc_drawItemText_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QPalette cppArg3_local = ::QPalette();
        ::QPalette* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);

        bool cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        ::QString cppArg5 = ::QString();
        pythonToCpp[5](pyArgs[5], &cppArg5);
        ::QPalette::ColorRole cppArg6 = QPalette::NoRole;
        if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!PyErr_Occurred()) {
            // drawItemText(QPainter*,QRect,int,QPalette,bool,QString,QPalette::ColorRole)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStyle*>(cppSelf)->::QStyle::drawItemText(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4, cppArg5, cppArg6) : const_cast<const ::QStyle*>(cppSelf)->drawItemText(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4, cppArg5, cppArg6);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_drawItemText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRect, int, PySide.QtGui.QPalette, bool, unicode, PySide.QtGui.QPalette.ColorRole = QPalette.NoRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.drawItemText", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_drawPrimitive(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawPrimitive(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawPrimitive(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:drawPrimitive", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawPrimitive(QStyle::PrimitiveElement,const QStyleOption*,QPainter*,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawPrimitive(QStyle::PrimitiveElement,const QStyleOption*,QPainter*,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // drawPrimitive(QStyle::PrimitiveElement,const QStyleOption*,QPainter*,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_drawPrimitive_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.drawPrimitive(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_drawPrimitive_TypeError;
            }
        }
        ::QStyle::PrimitiveElement cppArg0 = ((::QStyle::PrimitiveElement)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPainter* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // drawPrimitive(QStyle::PrimitiveElement,const QStyleOption*,QPainter*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.drawPrimitive()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const_cast<const ::QStyle*>(cppSelf)->drawPrimitive(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_drawPrimitive_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.PrimitiveElement, PySide.QtGui.QStyleOption, PySide.QtGui.QPainter, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.drawPrimitive", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_generatedIconPixmap(PyObject* self, PyObject* args)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "generatedIconPixmap", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: generatedIconPixmap(QIcon::Mode,QPixmap,const QStyleOption*)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[2])))) {
        overloadId = 0; // generatedIconPixmap(QIcon::Mode,QPixmap,const QStyleOption*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_generatedIconPixmap_TypeError;

    // Call function/method
    {
        ::QIcon::Mode cppArg0 = ((::QIcon::Mode)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPixmap cppArg1_local = ::QPixmap();
        ::QPixmap* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QStyleOption* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // generatedIconPixmap(QIcon::Mode,QPixmap,const QStyleOption*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.generatedIconPixmap()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QStyle*>(cppSelf)->generatedIconPixmap(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_generatedIconPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon.Mode, PySide.QtGui.QPixmap, PySide.QtGui.QStyleOption", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.generatedIconPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_hitTestComplexControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.hitTestComplexControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.hitTestComplexControl(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:hitTestComplexControl", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: hitTestComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPoint,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // hitTestComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPoint,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // hitTestComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPoint,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_hitTestComplexControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.hitTestComplexControl(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_hitTestComplexControl_TypeError;
            }
        }
        ::QStyle::ComplexControl cppArg0 = ((::QStyle::ComplexControl)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionComplex* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPoint cppArg2_local = ::QPoint();
        ::QPoint* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // hitTestComplexControl(QStyle::ComplexControl,const QStyleOptionComplex*,QPoint,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.hitTestComplexControl()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStyle::SubControl cppResult = const_cast<const ::QStyle*>(cppSelf)->hitTestComplexControl(cppArg0, cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_hitTestComplexControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtCore.QPoint, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.hitTestComplexControl", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_itemPixmapRect(PyObject* self, PyObject* args)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemPixmapRect", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: itemPixmapRect(QRect,int,QPixmap)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[2])))) {
        overloadId = 0; // itemPixmapRect(QRect,int,QPixmap)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_itemPixmapRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRect cppArg0_local = ::QRect();
        ::QRect* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPixmap cppArg2_local = ::QPixmap();
        ::QPixmap* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // itemPixmapRect(QRect,int,QPixmap)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStyle*>(cppSelf)->::QStyle::itemPixmapRect(*cppArg0, cppArg1, *cppArg2) : const_cast<const ::QStyle*>(cppSelf)->itemPixmapRect(*cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_itemPixmapRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.itemPixmapRect", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_itemTextRect(PyObject* self, PyObject* args)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemTextRect", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: itemTextRect(QFontMetrics,QRect,int,bool,QString)const
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
        overloadId = 0; // itemTextRect(QFontMetrics,QRect,int,bool,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_itemTextRect_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QFontMetrics cppArg0_local = ::QFontMetrics(::QFont());
        ::QFontMetrics* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        bool cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = ::QString();
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // itemTextRect(QFontMetrics,QRect,int,bool,QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStyle*>(cppSelf)->::QStyle::itemTextRect(*cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4) : const_cast<const ::QStyle*>(cppSelf)->itemTextRect(*cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_itemTextRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFontMetrics, PySide.QtCore.QRect, int, bool, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.itemTextRect", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_layoutSpacing(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacing(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacing(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:layoutSpacing", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: layoutSpacing(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // layoutSpacing(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // layoutSpacing(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4])))) {
                overloadId = 0; // layoutSpacing(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_layoutSpacing_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacing(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_layoutSpacing_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacing(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4]))))
                    goto Sbk_QStyleFunc_layoutSpacing_TypeError;
            }
        }
        ::QSizePolicy::ControlType cppArg0 = ((::QSizePolicy::ControlType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSizePolicy::ControlType cppArg1 = ((::QSizePolicy::ControlType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::Orientation cppArg2 = ((::Qt::Orientation)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QStyleOption* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QWidget* cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // layoutSpacing(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStyle*>(cppSelf)->layoutSpacing(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_layoutSpacing_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.ControlType, PySide.QtGui.QSizePolicy.ControlType, PySide.QtCore.Qt.Orientation, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.layoutSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_layoutSpacingImplementation(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacingImplementation(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacingImplementation(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:layoutSpacingImplementation", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 0; // layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4])))) {
                overloadId = 0; // layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_layoutSpacingImplementation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacingImplementation(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_layoutSpacingImplementation_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.layoutSpacingImplementation(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[4]))))
                    goto Sbk_QStyleFunc_layoutSpacingImplementation_TypeError;
            }
        }
        ::QSizePolicy::ControlType cppArg0 = ((::QSizePolicy::ControlType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QSizePolicy::ControlType cppArg1 = ((::QSizePolicy::ControlType)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::Qt::Orientation cppArg2 = ((::Qt::Orientation)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QStyleOption* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QWidget* cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // layoutSpacingImplementation(QSizePolicy::ControlType,QSizePolicy::ControlType,Qt::Orientation,const QStyleOption*,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStyle*>(cppSelf)->layoutSpacingImplementation(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_layoutSpacingImplementation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.ControlType, PySide.QtGui.QSizePolicy.ControlType, PySide.QtCore.Qt.Orientation, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.layoutSpacingImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_pixelMetric(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.pixelMetric(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.pixelMetric(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:pixelMetric", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: pixelMetric(QStyle::PixelMetric,const QStyleOption*,const QWidget*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // pixelMetric(QStyle::PixelMetric,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // pixelMetric(QStyle::PixelMetric,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // pixelMetric(QStyle::PixelMetric,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_pixelMetric_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.pixelMetric(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QStyleFunc_pixelMetric_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.pixelMetric(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_pixelMetric_TypeError;
            }
        }
        ::QStyle::PixelMetric cppArg0 = ((::QStyle::PixelMetric)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // pixelMetric(QStyle::PixelMetric,const QStyleOption*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.pixelMetric()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStyle*>(cppSelf)->pixelMetric(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_pixelMetric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.PixelMetric, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.pixelMetric", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_polish(PyObject* self, PyObject* pyArg)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: polish(QApplication*)
    // 1: polish(QPalette&)
    // 2: polish(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 2; // polish(QWidget*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
        overloadId = 1; // polish(QPalette&)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (pyArg)))) {
        overloadId = 0; // polish(QApplication*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_polish_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // polish(QApplication * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QApplication* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // polish(QApplication*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStyle::polish(cppArg0) : cppSelf->polish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // polish(QPalette & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPalette cppArg0_local = ::QPalette();
            ::QPalette* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // polish(QPalette&)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStyle::polish(*cppArg0) : cppSelf->polish(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // polish(QWidget * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // polish(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStyle::polish(cppArg0) : cppSelf->polish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_polish_TypeError:
        const char* overloads[] = {"PySide.QtGui.QApplication", "PySide.QtGui.QPalette", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStyle.polish", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_proxy(PyObject* self)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // proxy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QStyle * cppResult = const_cast<const ::QStyle*>(cppSelf)->proxy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStyleFunc_sizeFromContents(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sizeFromContents(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sizeFromContents(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:sizeFromContents", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_sizeFromContents_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "w");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sizeFromContents(): got multiple values for keyword argument 'w'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_sizeFromContents_TypeError;
            }
        }
        ::QStyle::ContentsType cppArg0 = ((::QStyle::ContentsType)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QSize cppArg2_local = ::QSize();
        ::QSize* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.sizeFromContents()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QStyle*>(cppSelf)->sizeFromContents(cppArg0, cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_sizeFromContents_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ContentsType, PySide.QtGui.QStyleOption, PySide.QtCore.QSize, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.sizeFromContents", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_sliderPositionFromValue(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderPositionFromValue(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderPositionFromValue(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:sliderPositionFromValue", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: sliderPositionFromValue(int,int,int,int,bool)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // sliderPositionFromValue(int,int,int,int,bool)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4])))) {
            overloadId = 0; // sliderPositionFromValue(int,int,int,int,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_sliderPositionFromValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "upsideDown");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderPositionFromValue(): got multiple values for keyword argument 'upsideDown'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4]))))
                    goto Sbk_QStyleFunc_sliderPositionFromValue_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        bool cppArg4 = false;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // sliderPositionFromValue(int,int,int,int,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QStyle::sliderPositionFromValue(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_sliderPositionFromValue_TypeError:
        const char* overloads[] = {"int, int, int, int, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.sliderPositionFromValue", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_sliderValueFromPosition(PyObject* self, PyObject* args, PyObject* kwds)
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
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderValueFromPosition(): too many arguments");
        return 0;
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderValueFromPosition(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:sliderValueFromPosition", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: sliderValueFromPosition(int,int,int,int,bool)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // sliderValueFromPosition(int,int,int,int,bool)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4])))) {
            overloadId = 0; // sliderValueFromPosition(int,int,int,int,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_sliderValueFromPosition_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "upsideDown");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.sliderValueFromPosition(): got multiple values for keyword argument 'upsideDown'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4]))))
                    goto Sbk_QStyleFunc_sliderValueFromPosition_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        bool cppArg4 = false;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // sliderValueFromPosition(int,int,int,int,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QStyle::sliderValueFromPosition(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_sliderValueFromPosition_TypeError:
        const char* overloads[] = {"int, int, int, int, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.sliderValueFromPosition", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_standardIcon(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIcon(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIcon(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:standardIcon", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: standardIcon(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // standardIcon(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // standardIcon(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // standardIcon(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_standardIcon_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIcon(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QStyleFunc_standardIcon_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIcon(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_standardIcon_TypeError;
            }
        }
        ::QStyle::StandardPixmap cppArg0 = ((::QStyle::StandardPixmap)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // standardIcon(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QStyle*>(cppSelf)->standardIcon(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_standardIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StandardPixmap, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.standardIcon", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_standardIconImplementation(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIconImplementation(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIconImplementation(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:standardIconImplementation", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_standardIconImplementation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "opt");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIconImplementation(): got multiple values for keyword argument 'opt'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QStyleFunc_standardIconImplementation_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardIconImplementation(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_standardIconImplementation_TypeError;
            }
        }
        ::QStyle::StandardPixmap cppArg0 = ((::QStyle::StandardPixmap)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QStyle*>(cppSelf)->standardIconImplementation(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_standardIconImplementation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StandardPixmap, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.standardIconImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_standardPalette(PyObject* self)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardPalette()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPalette cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStyle*>(cppSelf)->::QStyle::standardPalette() : const_cast<const ::QStyle*>(cppSelf)->standardPalette();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStyleFunc_standardPixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardPixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardPixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:standardPixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: standardPixmap(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // standardPixmap(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // standardPixmap(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                overloadId = 0; // standardPixmap(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_standardPixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "opt");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardPixmap(): got multiple values for keyword argument 'opt'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QStyleFunc_standardPixmap_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.standardPixmap(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_standardPixmap_TypeError;
            }
        }
        ::QStyle::StandardPixmap cppArg0 = ((::QStyle::StandardPixmap)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // standardPixmap(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.standardPixmap()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QStyle*>(cppSelf)->standardPixmap(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_standardPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StandardPixmap, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.standardPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_styleHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.styleHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.styleHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:styleHint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (pyArgs[3])))) {
                    overloadId = 0; // styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_styleHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "opt");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.styleHint(): got multiple values for keyword argument 'opt'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QStyleFunc_styleHint_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.styleHint(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_styleHint_TypeError;
            }
            value = PyDict_GetItemString(kwds, "returnData");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.styleHint(): got multiple values for keyword argument 'returnData'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_styleHint_TypeError;
            }
        }
        ::QStyle::StyleHint cppArg0 = ((::QStyle::StyleHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QStyleHintReturn* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // styleHint(QStyle::StyleHint,const QStyleOption*,const QWidget*,QStyleHintReturn*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.styleHint()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStyle*>(cppSelf)->styleHint(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_styleHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StyleHint, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None, PySide.QtGui.QStyleHintReturn = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.styleHint", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_subControlRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subControlRect(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subControlRect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:subControlRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
            overloadId = 0; // subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_subControlRect_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subControlRect(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QStyleFunc_subControlRect_TypeError;
            }
        }
        ::QStyle::ComplexControl cppArg0 = ((::QStyle::ComplexControl)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOptionComplex* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QStyle::SubControl cppArg2 = ((::QStyle::SubControl)0);
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QWidget* cppArg3 = 0;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.subControlRect()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QStyle*>(cppSelf)->subControlRect(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_subControlRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtGui.QStyle.SubControl, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.subControlRect", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_subElementRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subElementRect(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subElementRect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:subElementRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: subElementRect(QStyle::SubElement,const QStyleOption*,const QWidget*)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // subElementRect(QStyle::SubElement,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
            overloadId = 0; // subElementRect(QStyle::SubElement,const QStyleOption*,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_subElementRect_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyle.subElementRect(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QStyleFunc_subElementRect_TypeError;
            }
        }
        ::QStyle::SubElement cppArg0 = ((::QStyle::SubElement)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QStyleOption* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QWidget* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // subElementRect(QStyle::SubElement,const QStyleOption*,const QWidget*)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QStyle.subElementRect()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QStyle*>(cppSelf)->subElementRect(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_subElementRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.SubElement, PySide.QtGui.QStyleOption, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.subElementRect", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_unpolish(PyObject* self, PyObject* pyArg)
{
    ::QStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: unpolish(QApplication*)
    // 1: unpolish(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 1; // unpolish(QWidget*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], (pyArg)))) {
        overloadId = 0; // unpolish(QApplication*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_unpolish_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // unpolish(QApplication * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QApplication* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // unpolish(QApplication*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStyle::unpolish(cppArg0) : cppSelf->unpolish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // unpolish(QWidget * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // unpolish(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStyle::unpolish(cppArg0) : cppSelf->unpolish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStyleFunc_unpolish_TypeError:
        const char* overloads[] = {"PySide.QtGui.QApplication", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStyle.unpolish", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_visualAlignment(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "visualAlignment", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: visualAlignment(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // visualAlignment(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_visualAlignment_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::AlignmentFlag> cppArg1 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // visualAlignment(Qt::LayoutDirection,QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = ::QStyle::visualAlignment(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_visualAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection, PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.visualAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_visualPos(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "visualPos", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: visualPos(Qt::LayoutDirection,QRect,QPoint)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))) {
        overloadId = 0; // visualPos(Qt::LayoutDirection,QRect,QPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_visualPos_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPoint cppArg2_local = ::QPoint();
        ::QPoint* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // visualPos(Qt::LayoutDirection,QRect,QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = ::QStyle::visualPos(cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_visualPos_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection, PySide.QtCore.QRect, PySide.QtCore.QPoint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.visualPos", overloads);
        return 0;
}

static PyObject* Sbk_QStyleFunc_visualRect(PyObject* self, PyObject* args)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "visualRect", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: visualRect(Qt::LayoutDirection,QRect,QRect)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
        overloadId = 0; // visualRect(Qt::LayoutDirection,QRect,QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleFunc_visualRect_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QRect cppArg1_local = ::QRect();
        ::QRect* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QRect cppArg2_local = ::QRect();
        ::QRect* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // visualRect(Qt::LayoutDirection,QRect,QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = ::QStyle::visualRect(cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleFunc_visualRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection, PySide.QtCore.QRect, PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyle.visualRect", overloads);
        return 0;
}

static PyMethodDef Sbk_QStyle_methods[] = {
    {"alignedRect", (PyCFunction)Sbk_QStyleFunc_alignedRect, METH_VARARGS|METH_STATIC},
    {"combinedLayoutSpacing", (PyCFunction)Sbk_QStyleFunc_combinedLayoutSpacing, METH_VARARGS|METH_KEYWORDS},
    {"drawComplexControl", (PyCFunction)Sbk_QStyleFunc_drawComplexControl, METH_VARARGS|METH_KEYWORDS},
    {"drawControl", (PyCFunction)Sbk_QStyleFunc_drawControl, METH_VARARGS|METH_KEYWORDS},
    {"drawItemPixmap", (PyCFunction)Sbk_QStyleFunc_drawItemPixmap, METH_VARARGS},
    {"drawItemText", (PyCFunction)Sbk_QStyleFunc_drawItemText, METH_VARARGS|METH_KEYWORDS},
    {"drawPrimitive", (PyCFunction)Sbk_QStyleFunc_drawPrimitive, METH_VARARGS|METH_KEYWORDS},
    {"generatedIconPixmap", (PyCFunction)Sbk_QStyleFunc_generatedIconPixmap, METH_VARARGS},
    {"hitTestComplexControl", (PyCFunction)Sbk_QStyleFunc_hitTestComplexControl, METH_VARARGS|METH_KEYWORDS},
    {"itemPixmapRect", (PyCFunction)Sbk_QStyleFunc_itemPixmapRect, METH_VARARGS},
    {"itemTextRect", (PyCFunction)Sbk_QStyleFunc_itemTextRect, METH_VARARGS},
    {"layoutSpacing", (PyCFunction)Sbk_QStyleFunc_layoutSpacing, METH_VARARGS|METH_KEYWORDS},
    {"layoutSpacingImplementation", (PyCFunction)Sbk_QStyleFunc_layoutSpacingImplementation, METH_VARARGS|METH_KEYWORDS},
    {"pixelMetric", (PyCFunction)Sbk_QStyleFunc_pixelMetric, METH_VARARGS|METH_KEYWORDS},
    {"polish", (PyCFunction)Sbk_QStyleFunc_polish, METH_O},
    {"proxy", (PyCFunction)Sbk_QStyleFunc_proxy, METH_NOARGS},
    {"sizeFromContents", (PyCFunction)Sbk_QStyleFunc_sizeFromContents, METH_VARARGS|METH_KEYWORDS},
    {"sliderPositionFromValue", (PyCFunction)Sbk_QStyleFunc_sliderPositionFromValue, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"sliderValueFromPosition", (PyCFunction)Sbk_QStyleFunc_sliderValueFromPosition, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"standardIcon", (PyCFunction)Sbk_QStyleFunc_standardIcon, METH_VARARGS|METH_KEYWORDS},
    {"standardIconImplementation", (PyCFunction)Sbk_QStyleFunc_standardIconImplementation, METH_VARARGS|METH_KEYWORDS},
    {"standardPalette", (PyCFunction)Sbk_QStyleFunc_standardPalette, METH_NOARGS},
    {"standardPixmap", (PyCFunction)Sbk_QStyleFunc_standardPixmap, METH_VARARGS|METH_KEYWORDS},
    {"styleHint", (PyCFunction)Sbk_QStyleFunc_styleHint, METH_VARARGS|METH_KEYWORDS},
    {"subControlRect", (PyCFunction)Sbk_QStyleFunc_subControlRect, METH_VARARGS|METH_KEYWORDS},
    {"subElementRect", (PyCFunction)Sbk_QStyleFunc_subElementRect, METH_VARARGS|METH_KEYWORDS},
    {"unpolish", (PyCFunction)Sbk_QStyleFunc_unpolish, METH_O},
    {"visualAlignment", (PyCFunction)Sbk_QStyleFunc_visualAlignment, METH_VARARGS|METH_STATIC},
    {"visualPos", (PyCFunction)Sbk_QStyleFunc_visualPos, METH_VARARGS|METH_STATIC},
    {"visualRect", (PyCFunction)Sbk_QStyleFunc_visualRect, METH_VARARGS|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QStyle_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyle_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyle_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyle",
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
    /*tp_traverse*/         Sbk_QStyle_traverse,
    /*tp_clear*/            Sbk_QStyle_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyle_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyle_Init,
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

static void* Sbk_QStyle_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QStyle*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QStyle_StateFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::State cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::State)PyLong_AsLong(self);
    cppArg = (QStyle::State)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::State)PyInt_AsLong(self);
    cppArg = (QStyle::State)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_StateFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::State cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::State)PyLong_AsLong(self);
    cppArg = (QStyle::State)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::State)PyInt_AsLong(self);
    cppArg = (QStyle::State)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_StateFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::State cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::State)PyLong_AsLong(self);
    cppArg = (QStyle::State)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::State)PyInt_AsLong(self);
    cppArg = (QStyle::State)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_StateFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::State cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), self, &cppSelf);
    ::QStyle::State cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyle_StateFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyle_StateFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyle_StateFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyle_StateFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyle_StateFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyle_StateFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyle_StateFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyle_StateFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyle_StateFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyle_StateFlag_long,
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


PyObject* SbkPySide_QtGui_QStyle_SubControl___and__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::SubControls cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::SubControls)PyLong_AsLong(self);
    cppArg = (QStyle::SubControls)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::SubControls)PyInt_AsLong(self);
    cppArg = (QStyle::SubControls)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_SubControl___or__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::SubControls cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::SubControls)PyLong_AsLong(self);
    cppArg = (QStyle::SubControls)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::SubControls)PyInt_AsLong(self);
    cppArg = (QStyle::SubControls)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_SubControl___xor__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::SubControls cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QStyle::SubControls)PyLong_AsLong(self);
    cppArg = (QStyle::SubControls)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QStyle::SubControls)PyInt_AsLong(self);
    cppArg = (QStyle::SubControls)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QStyle_SubControl___invert__(PyObject* self, PyObject* pyArg)
{
    ::QStyle::SubControls cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), self, &cppSelf);
    ::QStyle::SubControls cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QStyle_SubControl_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QStyle_SubControl__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QStyle_SubControl_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QStyle_SubControl__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QStyle_SubControl___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QStyle_SubControl___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QStyle_SubControl___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QStyle_SubControl___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QStyle_SubControl_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QStyle_SubControl_long,
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
static void QStyle_StateFlag_PythonToCpp_QStyle_StateFlag(PyObject* pyIn, void* cppOut) {
    *((::QStyle::StateFlag*)cppOut) = (::QStyle::StateFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_StateFlag_PythonToCpp_QStyle_StateFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX]))
        return QStyle_StateFlag_PythonToCpp_QStyle_StateFlag;
    return 0;
}
static PyObject* QStyle_StateFlag_CppToPython_QStyle_StateFlag(const void* cppIn) {
    int castCppIn = *((::QStyle::StateFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX], castCppIn);

}

static void QFlags_QStyle_StateFlag__PythonToCpp_QFlags_QStyle_StateFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyle::StateFlag>*)cppOut) = ::QFlags<QStyle::StateFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyle_StateFlag__PythonToCpp_QFlags_QStyle_StateFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]))
        return QFlags_QStyle_StateFlag__PythonToCpp_QFlags_QStyle_StateFlag_;
    return 0;
}
static PyObject* QFlags_QStyle_StateFlag__CppToPython_QFlags_QStyle_StateFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyle::StateFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]));

}

static void QStyle_StateFlag_PythonToCpp_QFlags_QStyle_StateFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyle::StateFlag>*)cppOut) = ::QFlags<QStyle::StateFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyle_StateFlag_PythonToCpp_QFlags_QStyle_StateFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX]))
        return QStyle_StateFlag_PythonToCpp_QFlags_QStyle_StateFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyle_StateFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyle::StateFlag>*)cppOut) = ::QFlags<QStyle::StateFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyle_StateFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyle_StateFlag_;
    return 0;
}
static void QStyle_PrimitiveElement_PythonToCpp_QStyle_PrimitiveElement(PyObject* pyIn, void* cppOut) {
    *((::QStyle::PrimitiveElement*)cppOut) = (::QStyle::PrimitiveElement) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_PrimitiveElement_PythonToCpp_QStyle_PrimitiveElement_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX]))
        return QStyle_PrimitiveElement_PythonToCpp_QStyle_PrimitiveElement;
    return 0;
}
static PyObject* QStyle_PrimitiveElement_CppToPython_QStyle_PrimitiveElement(const void* cppIn) {
    int castCppIn = *((::QStyle::PrimitiveElement*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX], castCppIn);

}

static void QStyle_ControlElement_PythonToCpp_QStyle_ControlElement(PyObject* pyIn, void* cppOut) {
    *((::QStyle::ControlElement*)cppOut) = (::QStyle::ControlElement) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_ControlElement_PythonToCpp_QStyle_ControlElement_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX]))
        return QStyle_ControlElement_PythonToCpp_QStyle_ControlElement;
    return 0;
}
static PyObject* QStyle_ControlElement_CppToPython_QStyle_ControlElement(const void* cppIn) {
    int castCppIn = *((::QStyle::ControlElement*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX], castCppIn);

}

static void QStyle_SubElement_PythonToCpp_QStyle_SubElement(PyObject* pyIn, void* cppOut) {
    *((::QStyle::SubElement*)cppOut) = (::QStyle::SubElement) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_SubElement_PythonToCpp_QStyle_SubElement_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX]))
        return QStyle_SubElement_PythonToCpp_QStyle_SubElement;
    return 0;
}
static PyObject* QStyle_SubElement_CppToPython_QStyle_SubElement(const void* cppIn) {
    int castCppIn = *((::QStyle::SubElement*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX], castCppIn);

}

static void QStyle_ComplexControl_PythonToCpp_QStyle_ComplexControl(PyObject* pyIn, void* cppOut) {
    *((::QStyle::ComplexControl*)cppOut) = (::QStyle::ComplexControl) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_ComplexControl_PythonToCpp_QStyle_ComplexControl_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]))
        return QStyle_ComplexControl_PythonToCpp_QStyle_ComplexControl;
    return 0;
}
static PyObject* QStyle_ComplexControl_CppToPython_QStyle_ComplexControl(const void* cppIn) {
    int castCppIn = *((::QStyle::ComplexControl*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX], castCppIn);

}

static void QStyle_SubControl_PythonToCpp_QStyle_SubControl(PyObject* pyIn, void* cppOut) {
    *((::QStyle::SubControl*)cppOut) = (::QStyle::SubControl) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_SubControl_PythonToCpp_QStyle_SubControl_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]))
        return QStyle_SubControl_PythonToCpp_QStyle_SubControl;
    return 0;
}
static PyObject* QStyle_SubControl_CppToPython_QStyle_SubControl(const void* cppIn) {
    int castCppIn = *((::QStyle::SubControl*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX], castCppIn);

}

static void QFlags_QStyle_SubControl__PythonToCpp_QFlags_QStyle_SubControl_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyle::SubControl>*)cppOut) = ::QFlags<QStyle::SubControl>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QStyle_SubControl__PythonToCpp_QFlags_QStyle_SubControl__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]))
        return QFlags_QStyle_SubControl__PythonToCpp_QFlags_QStyle_SubControl_;
    return 0;
}
static PyObject* QFlags_QStyle_SubControl__CppToPython_QFlags_QStyle_SubControl_(const void* cppIn) {
    int castCppIn = *((::QFlags<QStyle::SubControl>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]));

}

static void QStyle_SubControl_PythonToCpp_QFlags_QStyle_SubControl_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QStyle::SubControl>*)cppOut) = ::QFlags<QStyle::SubControl>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QStyle_SubControl_PythonToCpp_QFlags_QStyle_SubControl__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]))
        return QStyle_SubControl_PythonToCpp_QFlags_QStyle_SubControl_;
    return 0;
}
static void number_PythonToCpp_QFlags_QStyle_SubControl_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QStyle::SubControl>*)cppOut) = ::QFlags<QStyle::SubControl>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QStyle_SubControl__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QStyle_SubControl_;
    return 0;
}
static void QStyle_PixelMetric_PythonToCpp_QStyle_PixelMetric(PyObject* pyIn, void* cppOut) {
    *((::QStyle::PixelMetric*)cppOut) = (::QStyle::PixelMetric) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_PixelMetric_PythonToCpp_QStyle_PixelMetric_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX]))
        return QStyle_PixelMetric_PythonToCpp_QStyle_PixelMetric;
    return 0;
}
static PyObject* QStyle_PixelMetric_CppToPython_QStyle_PixelMetric(const void* cppIn) {
    int castCppIn = *((::QStyle::PixelMetric*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX], castCppIn);

}

static void QStyle_ContentsType_PythonToCpp_QStyle_ContentsType(PyObject* pyIn, void* cppOut) {
    *((::QStyle::ContentsType*)cppOut) = (::QStyle::ContentsType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_ContentsType_PythonToCpp_QStyle_ContentsType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX]))
        return QStyle_ContentsType_PythonToCpp_QStyle_ContentsType;
    return 0;
}
static PyObject* QStyle_ContentsType_CppToPython_QStyle_ContentsType(const void* cppIn) {
    int castCppIn = *((::QStyle::ContentsType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX], castCppIn);

}

static void QStyle_RequestSoftwareInputPanel_PythonToCpp_QStyle_RequestSoftwareInputPanel(PyObject* pyIn, void* cppOut) {
    *((::QStyle::RequestSoftwareInputPanel*)cppOut) = (::QStyle::RequestSoftwareInputPanel) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_RequestSoftwareInputPanel_PythonToCpp_QStyle_RequestSoftwareInputPanel_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX]))
        return QStyle_RequestSoftwareInputPanel_PythonToCpp_QStyle_RequestSoftwareInputPanel;
    return 0;
}
static PyObject* QStyle_RequestSoftwareInputPanel_CppToPython_QStyle_RequestSoftwareInputPanel(const void* cppIn) {
    int castCppIn = *((::QStyle::RequestSoftwareInputPanel*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX], castCppIn);

}

static void QStyle_StyleHint_PythonToCpp_QStyle_StyleHint(PyObject* pyIn, void* cppOut) {
    *((::QStyle::StyleHint*)cppOut) = (::QStyle::StyleHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_StyleHint_PythonToCpp_QStyle_StyleHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX]))
        return QStyle_StyleHint_PythonToCpp_QStyle_StyleHint;
    return 0;
}
static PyObject* QStyle_StyleHint_CppToPython_QStyle_StyleHint(const void* cppIn) {
    int castCppIn = *((::QStyle::StyleHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX], castCppIn);

}

static void QStyle_StandardPixmap_PythonToCpp_QStyle_StandardPixmap(PyObject* pyIn, void* cppOut) {
    *((::QStyle::StandardPixmap*)cppOut) = (::QStyle::StandardPixmap) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyle_StandardPixmap_PythonToCpp_QStyle_StandardPixmap_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]))
        return QStyle_StandardPixmap_PythonToCpp_QStyle_StandardPixmap;
    return 0;
}
static PyObject* QStyle_StandardPixmap_CppToPython_QStyle_StandardPixmap(const void* cppIn) {
    int castCppIn = *((::QStyle::StandardPixmap*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyle_PythonToCpp_QStyle_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyle_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyle_PythonToCpp_QStyle_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyle_Type))
        return QStyle_PythonToCpp_QStyle_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyle_PTR_CppToPython_QStyle(const void* cppIn) {
    return PySide::getWrapperForQObject((::QStyle*)cppIn, &Sbk_QStyle_Type);

}

void init_QStyle(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyle_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyle", "QStyle*",
        &Sbk_QStyle_Type, &Shiboken::callCppDestructor< ::QStyle >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyle_Type,
        QStyle_PythonToCpp_QStyle_PTR,
        is_QStyle_PythonToCpp_QStyle_PTR_Convertible,
        QStyle_PTR_CppToPython_QStyle);

    Shiboken::Conversions::registerConverterName(converter, "QStyle");
    Shiboken::Conversions::registerConverterName(converter, "QStyle*");
    Shiboken::Conversions::registerConverterName(converter, "QStyle&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyle).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QStyle_Type, &Sbk_QStyle_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'StateFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX] = PySide::QFlags::create("State", &SbkPySide_QtGui_QStyle_StateFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "StateFlag",
        "PySide.QtGui.QStyle.StateFlag",
        "QStyle::StateFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_None", (long) QStyle::State_None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Enabled", (long) QStyle::State_Enabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Raised", (long) QStyle::State_Raised))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Sunken", (long) QStyle::State_Sunken))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Off", (long) QStyle::State_Off))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_NoChange", (long) QStyle::State_NoChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_On", (long) QStyle::State_On))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_DownArrow", (long) QStyle::State_DownArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Horizontal", (long) QStyle::State_Horizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_HasFocus", (long) QStyle::State_HasFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Top", (long) QStyle::State_Top))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Bottom", (long) QStyle::State_Bottom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_FocusAtBorder", (long) QStyle::State_FocusAtBorder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_AutoRaise", (long) QStyle::State_AutoRaise))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_MouseOver", (long) QStyle::State_MouseOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_UpArrow", (long) QStyle::State_UpArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Selected", (long) QStyle::State_Selected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Active", (long) QStyle::State_Active))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Window", (long) QStyle::State_Window))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Open", (long) QStyle::State_Open))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Children", (long) QStyle::State_Children))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Item", (long) QStyle::State_Item))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Sibling", (long) QStyle::State_Sibling))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Editing", (long) QStyle::State_Editing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_KeyboardFocusChange", (long) QStyle::State_KeyboardFocusChange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_ReadOnly", (long) QStyle::State_ReadOnly))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Small", (long) QStyle::State_Small))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
        &Sbk_QStyle_Type, "State_Mini", (long) QStyle::State_Mini))
        return ;
    // Register converter for enum 'QStyle::StateFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX],
            QStyle_StateFlag_CppToPython_QStyle_StateFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_StateFlag_PythonToCpp_QStyle_StateFlag,
            is_QStyle_StateFlag_PythonToCpp_QStyle_StateFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STATEFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::StateFlag");
        Shiboken::Conversions::registerConverterName(converter, "StateFlag");
    }
    // Register converter for flag 'QFlags<QStyle::StateFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX],
            QFlags_QStyle_StateFlag__CppToPython_QFlags_QStyle_StateFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_StateFlag_PythonToCpp_QFlags_QStyle_StateFlag_,
            is_QStyle_StateFlag_PythonToCpp_QFlags_QStyle_StateFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyle_StateFlag__PythonToCpp_QFlags_QStyle_StateFlag_,
            is_QFlags_QStyle_StateFlag__PythonToCpp_QFlags_QStyle_StateFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyle_StateFlag_,
            is_number_PythonToCpp_QFlags_QStyle_StateFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyle::StateFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StateFlag>");
    }
    // End of 'StateFlag' enum/flags.

    // Initialization of enum 'PrimitiveElement'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "PrimitiveElement",
        "PySide.QtGui.QStyle.PrimitiveElement",
        "QStyle::PrimitiveElement");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Q3CheckListController", (long) QStyle::PE_Q3CheckListController))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Q3CheckListExclusiveIndicator", (long) QStyle::PE_Q3CheckListExclusiveIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Q3CheckListIndicator", (long) QStyle::PE_Q3CheckListIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Q3DockWindowSeparator", (long) QStyle::PE_Q3DockWindowSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Q3Separator", (long) QStyle::PE_Q3Separator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Frame", (long) QStyle::PE_Frame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameDefaultButton", (long) QStyle::PE_FrameDefaultButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameDockWidget", (long) QStyle::PE_FrameDockWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameFocusRect", (long) QStyle::PE_FrameFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameGroupBox", (long) QStyle::PE_FrameGroupBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameLineEdit", (long) QStyle::PE_FrameLineEdit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameMenu", (long) QStyle::PE_FrameMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameStatusBar", (long) QStyle::PE_FrameStatusBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameStatusBarItem", (long) QStyle::PE_FrameStatusBarItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameTabWidget", (long) QStyle::PE_FrameTabWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameWindow", (long) QStyle::PE_FrameWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameButtonBevel", (long) QStyle::PE_FrameButtonBevel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameButtonTool", (long) QStyle::PE_FrameButtonTool))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_FrameTabBarBase", (long) QStyle::PE_FrameTabBarBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelButtonCommand", (long) QStyle::PE_PanelButtonCommand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelButtonBevel", (long) QStyle::PE_PanelButtonBevel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelButtonTool", (long) QStyle::PE_PanelButtonTool))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelMenuBar", (long) QStyle::PE_PanelMenuBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelToolBar", (long) QStyle::PE_PanelToolBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelLineEdit", (long) QStyle::PE_PanelLineEdit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorArrowDown", (long) QStyle::PE_IndicatorArrowDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorArrowLeft", (long) QStyle::PE_IndicatorArrowLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorArrowRight", (long) QStyle::PE_IndicatorArrowRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorArrowUp", (long) QStyle::PE_IndicatorArrowUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorBranch", (long) QStyle::PE_IndicatorBranch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorButtonDropDown", (long) QStyle::PE_IndicatorButtonDropDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorViewItemCheck", (long) QStyle::PE_IndicatorViewItemCheck))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorItemViewItemCheck", (long) QStyle::PE_IndicatorItemViewItemCheck))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorCheckBox", (long) QStyle::PE_IndicatorCheckBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorDockWidgetResizeHandle", (long) QStyle::PE_IndicatorDockWidgetResizeHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorHeaderArrow", (long) QStyle::PE_IndicatorHeaderArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorMenuCheckMark", (long) QStyle::PE_IndicatorMenuCheckMark))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorProgressChunk", (long) QStyle::PE_IndicatorProgressChunk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorRadioButton", (long) QStyle::PE_IndicatorRadioButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorSpinDown", (long) QStyle::PE_IndicatorSpinDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorSpinMinus", (long) QStyle::PE_IndicatorSpinMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorSpinPlus", (long) QStyle::PE_IndicatorSpinPlus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorSpinUp", (long) QStyle::PE_IndicatorSpinUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorToolBarHandle", (long) QStyle::PE_IndicatorToolBarHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorToolBarSeparator", (long) QStyle::PE_IndicatorToolBarSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelTipLabel", (long) QStyle::PE_PanelTipLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorTabTear", (long) QStyle::PE_IndicatorTabTear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelScrollAreaCorner", (long) QStyle::PE_PanelScrollAreaCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_Widget", (long) QStyle::PE_Widget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorColumnViewArrow", (long) QStyle::PE_IndicatorColumnViewArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorItemViewItemDrop", (long) QStyle::PE_IndicatorItemViewItemDrop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelItemViewItem", (long) QStyle::PE_PanelItemViewItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelItemViewRow", (long) QStyle::PE_PanelItemViewRow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelStatusBar", (long) QStyle::PE_PanelStatusBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_IndicatorTabClose", (long) QStyle::PE_IndicatorTabClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_PanelMenu", (long) QStyle::PE_PanelMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
        &Sbk_QStyle_Type, "PE_CustomBase", (long) QStyle::PE_CustomBase))
        return ;
    // Register converter for enum 'QStyle::PrimitiveElement'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX],
            QStyle_PrimitiveElement_CppToPython_QStyle_PrimitiveElement);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_PrimitiveElement_PythonToCpp_QStyle_PrimitiveElement,
            is_QStyle_PrimitiveElement_PythonToCpp_QStyle_PrimitiveElement_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::PrimitiveElement");
        Shiboken::Conversions::registerConverterName(converter, "PrimitiveElement");
    }
    // End of 'PrimitiveElement' enum.

    // Initialization of enum 'ControlElement'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "ControlElement",
        "PySide.QtGui.QStyle.ControlElement",
        "QStyle::ControlElement");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_PushButton", (long) QStyle::CE_PushButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_PushButtonBevel", (long) QStyle::CE_PushButtonBevel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_PushButtonLabel", (long) QStyle::CE_PushButtonLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_CheckBox", (long) QStyle::CE_CheckBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_CheckBoxLabel", (long) QStyle::CE_CheckBoxLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_RadioButton", (long) QStyle::CE_RadioButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_RadioButtonLabel", (long) QStyle::CE_RadioButtonLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_TabBarTab", (long) QStyle::CE_TabBarTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_TabBarTabShape", (long) QStyle::CE_TabBarTabShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_TabBarTabLabel", (long) QStyle::CE_TabBarTabLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ProgressBar", (long) QStyle::CE_ProgressBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ProgressBarGroove", (long) QStyle::CE_ProgressBarGroove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ProgressBarContents", (long) QStyle::CE_ProgressBarContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ProgressBarLabel", (long) QStyle::CE_ProgressBarLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuItem", (long) QStyle::CE_MenuItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuScroller", (long) QStyle::CE_MenuScroller))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuVMargin", (long) QStyle::CE_MenuVMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuHMargin", (long) QStyle::CE_MenuHMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuTearoff", (long) QStyle::CE_MenuTearoff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuEmptyArea", (long) QStyle::CE_MenuEmptyArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuBarItem", (long) QStyle::CE_MenuBarItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_MenuBarEmptyArea", (long) QStyle::CE_MenuBarEmptyArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ToolButtonLabel", (long) QStyle::CE_ToolButtonLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_Header", (long) QStyle::CE_Header))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_HeaderSection", (long) QStyle::CE_HeaderSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_HeaderLabel", (long) QStyle::CE_HeaderLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_Q3DockWindowEmptyArea", (long) QStyle::CE_Q3DockWindowEmptyArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ToolBoxTab", (long) QStyle::CE_ToolBoxTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_SizeGrip", (long) QStyle::CE_SizeGrip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_Splitter", (long) QStyle::CE_Splitter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_RubberBand", (long) QStyle::CE_RubberBand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_DockWidgetTitle", (long) QStyle::CE_DockWidgetTitle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarAddLine", (long) QStyle::CE_ScrollBarAddLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarSubLine", (long) QStyle::CE_ScrollBarSubLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarAddPage", (long) QStyle::CE_ScrollBarAddPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarSubPage", (long) QStyle::CE_ScrollBarSubPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarSlider", (long) QStyle::CE_ScrollBarSlider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarFirst", (long) QStyle::CE_ScrollBarFirst))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ScrollBarLast", (long) QStyle::CE_ScrollBarLast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_FocusFrame", (long) QStyle::CE_FocusFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ComboBoxLabel", (long) QStyle::CE_ComboBoxLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ToolBar", (long) QStyle::CE_ToolBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ToolBoxTabShape", (long) QStyle::CE_ToolBoxTabShape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ToolBoxTabLabel", (long) QStyle::CE_ToolBoxTabLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_HeaderEmptyArea", (long) QStyle::CE_HeaderEmptyArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ColumnViewGrip", (long) QStyle::CE_ColumnViewGrip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ItemViewItem", (long) QStyle::CE_ItemViewItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_ShapedFrame", (long) QStyle::CE_ShapedFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
        &Sbk_QStyle_Type, "CE_CustomBase", (long) QStyle::CE_CustomBase))
        return ;
    // Register converter for enum 'QStyle::ControlElement'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX],
            QStyle_ControlElement_CppToPython_QStyle_ControlElement);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_ControlElement_PythonToCpp_QStyle_ControlElement,
            is_QStyle_ControlElement_PythonToCpp_QStyle_ControlElement_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::ControlElement");
        Shiboken::Conversions::registerConverterName(converter, "ControlElement");
    }
    // End of 'ControlElement' enum.

    // Initialization of enum 'SubElement'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "SubElement",
        "PySide.QtGui.QStyle.SubElement",
        "QStyle::SubElement");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_PushButtonContents", (long) QStyle::SE_PushButtonContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_PushButtonFocusRect", (long) QStyle::SE_PushButtonFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CheckBoxIndicator", (long) QStyle::SE_CheckBoxIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CheckBoxContents", (long) QStyle::SE_CheckBoxContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CheckBoxFocusRect", (long) QStyle::SE_CheckBoxFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CheckBoxClickRect", (long) QStyle::SE_CheckBoxClickRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_RadioButtonIndicator", (long) QStyle::SE_RadioButtonIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_RadioButtonContents", (long) QStyle::SE_RadioButtonContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_RadioButtonFocusRect", (long) QStyle::SE_RadioButtonFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_RadioButtonClickRect", (long) QStyle::SE_RadioButtonClickRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ComboBoxFocusRect", (long) QStyle::SE_ComboBoxFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_SliderFocusRect", (long) QStyle::SE_SliderFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_Q3DockWindowHandleRect", (long) QStyle::SE_Q3DockWindowHandleRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ProgressBarGroove", (long) QStyle::SE_ProgressBarGroove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ProgressBarContents", (long) QStyle::SE_ProgressBarContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ProgressBarLabel", (long) QStyle::SE_ProgressBarLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonAccept", (long) QStyle::SE_DialogButtonAccept))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonReject", (long) QStyle::SE_DialogButtonReject))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonApply", (long) QStyle::SE_DialogButtonApply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonHelp", (long) QStyle::SE_DialogButtonHelp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonAll", (long) QStyle::SE_DialogButtonAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonAbort", (long) QStyle::SE_DialogButtonAbort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonIgnore", (long) QStyle::SE_DialogButtonIgnore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonRetry", (long) QStyle::SE_DialogButtonRetry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonCustom", (long) QStyle::SE_DialogButtonCustom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ToolBoxTabContents", (long) QStyle::SE_ToolBoxTabContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_HeaderLabel", (long) QStyle::SE_HeaderLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_HeaderArrow", (long) QStyle::SE_HeaderArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetTabBar", (long) QStyle::SE_TabWidgetTabBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetTabPane", (long) QStyle::SE_TabWidgetTabPane))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetTabContents", (long) QStyle::SE_TabWidgetTabContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetLeftCorner", (long) QStyle::SE_TabWidgetLeftCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetRightCorner", (long) QStyle::SE_TabWidgetRightCorner))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ViewItemCheckIndicator", (long) QStyle::SE_ViewItemCheckIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ItemViewItemCheckIndicator", (long) QStyle::SE_ItemViewItemCheckIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabBarTearIndicator", (long) QStyle::SE_TabBarTearIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TreeViewDisclosureItem", (long) QStyle::SE_TreeViewDisclosureItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_LineEditContents", (long) QStyle::SE_LineEditContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_FrameContents", (long) QStyle::SE_FrameContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DockWidgetCloseButton", (long) QStyle::SE_DockWidgetCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DockWidgetFloatButton", (long) QStyle::SE_DockWidgetFloatButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DockWidgetTitleBarText", (long) QStyle::SE_DockWidgetTitleBarText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DockWidgetIcon", (long) QStyle::SE_DockWidgetIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CheckBoxLayoutItem", (long) QStyle::SE_CheckBoxLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ComboBoxLayoutItem", (long) QStyle::SE_ComboBoxLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DateTimeEditLayoutItem", (long) QStyle::SE_DateTimeEditLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_DialogButtonBoxLayoutItem", (long) QStyle::SE_DialogButtonBoxLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_LabelLayoutItem", (long) QStyle::SE_LabelLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ProgressBarLayoutItem", (long) QStyle::SE_ProgressBarLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_PushButtonLayoutItem", (long) QStyle::SE_PushButtonLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_RadioButtonLayoutItem", (long) QStyle::SE_RadioButtonLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_SliderLayoutItem", (long) QStyle::SE_SliderLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_SpinBoxLayoutItem", (long) QStyle::SE_SpinBoxLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ToolButtonLayoutItem", (long) QStyle::SE_ToolButtonLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_FrameLayoutItem", (long) QStyle::SE_FrameLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_GroupBoxLayoutItem", (long) QStyle::SE_GroupBoxLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabWidgetLayoutItem", (long) QStyle::SE_TabWidgetLayoutItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ItemViewItemDecoration", (long) QStyle::SE_ItemViewItemDecoration))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ItemViewItemText", (long) QStyle::SE_ItemViewItemText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ItemViewItemFocusRect", (long) QStyle::SE_ItemViewItemFocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabBarTabLeftButton", (long) QStyle::SE_TabBarTabLeftButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabBarTabRightButton", (long) QStyle::SE_TabBarTabRightButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_TabBarTabText", (long) QStyle::SE_TabBarTabText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ShapedFrameContents", (long) QStyle::SE_ShapedFrameContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_ToolBarHandle", (long) QStyle::SE_ToolBarHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
        &Sbk_QStyle_Type, "SE_CustomBase", (long) QStyle::SE_CustomBase))
        return ;
    // Register converter for enum 'QStyle::SubElement'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX],
            QStyle_SubElement_CppToPython_QStyle_SubElement);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_SubElement_PythonToCpp_QStyle_SubElement,
            is_QStyle_SubElement_PythonToCpp_QStyle_SubElement_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::SubElement");
        Shiboken::Conversions::registerConverterName(converter, "SubElement");
    }
    // End of 'SubElement' enum.

    // Initialization of enum 'ComplexControl'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "ComplexControl",
        "PySide.QtGui.QStyle.ComplexControl",
        "QStyle::ComplexControl");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_SpinBox", (long) QStyle::CC_SpinBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_ComboBox", (long) QStyle::CC_ComboBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_ScrollBar", (long) QStyle::CC_ScrollBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_Slider", (long) QStyle::CC_Slider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_ToolButton", (long) QStyle::CC_ToolButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_TitleBar", (long) QStyle::CC_TitleBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_Q3ListView", (long) QStyle::CC_Q3ListView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_Dial", (long) QStyle::CC_Dial))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_GroupBox", (long) QStyle::CC_GroupBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_MdiControls", (long) QStyle::CC_MdiControls))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
        &Sbk_QStyle_Type, "CC_CustomBase", (long) QStyle::CC_CustomBase))
        return ;
    // Register converter for enum 'QStyle::ComplexControl'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX],
            QStyle_ComplexControl_CppToPython_QStyle_ComplexControl);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_ComplexControl_PythonToCpp_QStyle_ComplexControl,
            is_QStyle_ComplexControl_PythonToCpp_QStyle_ComplexControl_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::ComplexControl");
        Shiboken::Conversions::registerConverterName(converter, "ComplexControl");
    }
    // End of 'ComplexControl' enum.

    // Initialization of enum 'SubControl'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX] = PySide::QFlags::create("SubControls", &SbkPySide_QtGui_QStyle_SubControl_as_number);
    SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "SubControl",
        "PySide.QtGui.QStyle.SubControl",
        "QStyle::SubControl",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_None", (long) QStyle::SC_None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarAddLine", (long) QStyle::SC_ScrollBarAddLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarSubLine", (long) QStyle::SC_ScrollBarSubLine))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarAddPage", (long) QStyle::SC_ScrollBarAddPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarSubPage", (long) QStyle::SC_ScrollBarSubPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarFirst", (long) QStyle::SC_ScrollBarFirst))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarLast", (long) QStyle::SC_ScrollBarLast))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarSlider", (long) QStyle::SC_ScrollBarSlider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ScrollBarGroove", (long) QStyle::SC_ScrollBarGroove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SpinBoxUp", (long) QStyle::SC_SpinBoxUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SpinBoxDown", (long) QStyle::SC_SpinBoxDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SpinBoxFrame", (long) QStyle::SC_SpinBoxFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SpinBoxEditField", (long) QStyle::SC_SpinBoxEditField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ComboBoxFrame", (long) QStyle::SC_ComboBoxFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ComboBoxEditField", (long) QStyle::SC_ComboBoxEditField))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ComboBoxArrow", (long) QStyle::SC_ComboBoxArrow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ComboBoxListBoxPopup", (long) QStyle::SC_ComboBoxListBoxPopup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SliderGroove", (long) QStyle::SC_SliderGroove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SliderHandle", (long) QStyle::SC_SliderHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_SliderTickmarks", (long) QStyle::SC_SliderTickmarks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ToolButton", (long) QStyle::SC_ToolButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_ToolButtonMenu", (long) QStyle::SC_ToolButtonMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarSysMenu", (long) QStyle::SC_TitleBarSysMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarMinButton", (long) QStyle::SC_TitleBarMinButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarMaxButton", (long) QStyle::SC_TitleBarMaxButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarCloseButton", (long) QStyle::SC_TitleBarCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarNormalButton", (long) QStyle::SC_TitleBarNormalButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarShadeButton", (long) QStyle::SC_TitleBarShadeButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarUnshadeButton", (long) QStyle::SC_TitleBarUnshadeButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarContextHelpButton", (long) QStyle::SC_TitleBarContextHelpButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_TitleBarLabel", (long) QStyle::SC_TitleBarLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_Q3ListView", (long) QStyle::SC_Q3ListView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_Q3ListViewBranch", (long) QStyle::SC_Q3ListViewBranch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_Q3ListViewExpand", (long) QStyle::SC_Q3ListViewExpand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_DialGroove", (long) QStyle::SC_DialGroove))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_DialHandle", (long) QStyle::SC_DialHandle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_DialTickmarks", (long) QStyle::SC_DialTickmarks))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_GroupBoxCheckBox", (long) QStyle::SC_GroupBoxCheckBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_GroupBoxLabel", (long) QStyle::SC_GroupBoxLabel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_GroupBoxContents", (long) QStyle::SC_GroupBoxContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_GroupBoxFrame", (long) QStyle::SC_GroupBoxFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_MdiMinButton", (long) QStyle::SC_MdiMinButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_MdiNormalButton", (long) QStyle::SC_MdiNormalButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_MdiCloseButton", (long) QStyle::SC_MdiCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_CustomBase", (long) QStyle::SC_CustomBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
        &Sbk_QStyle_Type, "SC_All", (long) QStyle::SC_All))
        return ;
    // Register converter for enum 'QStyle::SubControl'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX],
            QStyle_SubControl_CppToPython_QStyle_SubControl);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_SubControl_PythonToCpp_QStyle_SubControl,
            is_QStyle_SubControl_PythonToCpp_QStyle_SubControl_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::SubControl");
        Shiboken::Conversions::registerConverterName(converter, "SubControl");
    }
    // Register converter for flag 'QFlags<QStyle::SubControl>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX],
            QFlags_QStyle_SubControl__CppToPython_QFlags_QStyle_SubControl_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_SubControl_PythonToCpp_QFlags_QStyle_SubControl_,
            is_QStyle_SubControl_PythonToCpp_QFlags_QStyle_SubControl__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QStyle_SubControl__PythonToCpp_QFlags_QStyle_SubControl_,
            is_QFlags_QStyle_SubControl__PythonToCpp_QFlags_QStyle_SubControl__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QStyle_SubControl_,
            is_number_PythonToCpp_QFlags_QStyle_SubControl__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_SUBCONTROL__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QStyle::SubControl>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<SubControl>");
    }
    // End of 'SubControl' enum/flags.

    // Initialization of enum 'PixelMetric'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "PixelMetric",
        "PySide.QtGui.QStyle.PixelMetric",
        "QStyle::PixelMetric");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ButtonMargin", (long) QStyle::PM_ButtonMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ButtonDefaultIndicator", (long) QStyle::PM_ButtonDefaultIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuButtonIndicator", (long) QStyle::PM_MenuButtonIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ButtonShiftHorizontal", (long) QStyle::PM_ButtonShiftHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ButtonShiftVertical", (long) QStyle::PM_ButtonShiftVertical))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DefaultFrameWidth", (long) QStyle::PM_DefaultFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SpinBoxFrameWidth", (long) QStyle::PM_SpinBoxFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ComboBoxFrameWidth", (long) QStyle::PM_ComboBoxFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MaximumDragDistance", (long) QStyle::PM_MaximumDragDistance))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ScrollBarExtent", (long) QStyle::PM_ScrollBarExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ScrollBarSliderMin", (long) QStyle::PM_ScrollBarSliderMin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SliderThickness", (long) QStyle::PM_SliderThickness))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SliderControlThickness", (long) QStyle::PM_SliderControlThickness))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SliderLength", (long) QStyle::PM_SliderLength))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SliderTickmarkOffset", (long) QStyle::PM_SliderTickmarkOffset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SliderSpaceAvailable", (long) QStyle::PM_SliderSpaceAvailable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DockWidgetSeparatorExtent", (long) QStyle::PM_DockWidgetSeparatorExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DockWidgetHandleExtent", (long) QStyle::PM_DockWidgetHandleExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DockWidgetFrameWidth", (long) QStyle::PM_DockWidgetFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarTabOverlap", (long) QStyle::PM_TabBarTabOverlap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarTabHSpace", (long) QStyle::PM_TabBarTabHSpace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarTabVSpace", (long) QStyle::PM_TabBarTabVSpace))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarBaseHeight", (long) QStyle::PM_TabBarBaseHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarBaseOverlap", (long) QStyle::PM_TabBarBaseOverlap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ProgressBarChunkWidth", (long) QStyle::PM_ProgressBarChunkWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SplitterWidth", (long) QStyle::PM_SplitterWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TitleBarHeight", (long) QStyle::PM_TitleBarHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuScrollerHeight", (long) QStyle::PM_MenuScrollerHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuHMargin", (long) QStyle::PM_MenuHMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuVMargin", (long) QStyle::PM_MenuVMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuPanelWidth", (long) QStyle::PM_MenuPanelWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuTearoffHeight", (long) QStyle::PM_MenuTearoffHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuDesktopFrameWidth", (long) QStyle::PM_MenuDesktopFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuBarPanelWidth", (long) QStyle::PM_MenuBarPanelWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuBarItemSpacing", (long) QStyle::PM_MenuBarItemSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuBarVMargin", (long) QStyle::PM_MenuBarVMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MenuBarHMargin", (long) QStyle::PM_MenuBarHMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_IndicatorWidth", (long) QStyle::PM_IndicatorWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_IndicatorHeight", (long) QStyle::PM_IndicatorHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ExclusiveIndicatorWidth", (long) QStyle::PM_ExclusiveIndicatorWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ExclusiveIndicatorHeight", (long) QStyle::PM_ExclusiveIndicatorHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_CheckListButtonSize", (long) QStyle::PM_CheckListButtonSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_CheckListControllerSize", (long) QStyle::PM_CheckListControllerSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DialogButtonsSeparator", (long) QStyle::PM_DialogButtonsSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DialogButtonsButtonWidth", (long) QStyle::PM_DialogButtonsButtonWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DialogButtonsButtonHeight", (long) QStyle::PM_DialogButtonsButtonHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MdiSubWindowFrameWidth", (long) QStyle::PM_MdiSubWindowFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MDIFrameWidth", (long) QStyle::PM_MDIFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MdiSubWindowMinimizedWidth", (long) QStyle::PM_MdiSubWindowMinimizedWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MDIMinimizedWidth", (long) QStyle::PM_MDIMinimizedWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_HeaderMargin", (long) QStyle::PM_HeaderMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_HeaderMarkSize", (long) QStyle::PM_HeaderMarkSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_HeaderGripMargin", (long) QStyle::PM_HeaderGripMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarTabShiftHorizontal", (long) QStyle::PM_TabBarTabShiftHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarTabShiftVertical", (long) QStyle::PM_TabBarTabShiftVertical))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarScrollButtonWidth", (long) QStyle::PM_TabBarScrollButtonWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarFrameWidth", (long) QStyle::PM_ToolBarFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarHandleExtent", (long) QStyle::PM_ToolBarHandleExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarItemSpacing", (long) QStyle::PM_ToolBarItemSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarItemMargin", (long) QStyle::PM_ToolBarItemMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarSeparatorExtent", (long) QStyle::PM_ToolBarSeparatorExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarExtensionExtent", (long) QStyle::PM_ToolBarExtensionExtent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SpinBoxSliderHeight", (long) QStyle::PM_SpinBoxSliderHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DefaultTopLevelMargin", (long) QStyle::PM_DefaultTopLevelMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DefaultChildMargin", (long) QStyle::PM_DefaultChildMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DefaultLayoutSpacing", (long) QStyle::PM_DefaultLayoutSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolBarIconSize", (long) QStyle::PM_ToolBarIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ListViewIconSize", (long) QStyle::PM_ListViewIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_IconViewIconSize", (long) QStyle::PM_IconViewIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SmallIconSize", (long) QStyle::PM_SmallIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LargeIconSize", (long) QStyle::PM_LargeIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_FocusFrameVMargin", (long) QStyle::PM_FocusFrameVMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_FocusFrameHMargin", (long) QStyle::PM_FocusFrameHMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ToolTipLabelFrameWidth", (long) QStyle::PM_ToolTipLabelFrameWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_CheckBoxLabelSpacing", (long) QStyle::PM_CheckBoxLabelSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBarIconSize", (long) QStyle::PM_TabBarIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SizeGripSize", (long) QStyle::PM_SizeGripSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DockWidgetTitleMargin", (long) QStyle::PM_DockWidgetTitleMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_MessageBoxIconSize", (long) QStyle::PM_MessageBoxIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ButtonIconSize", (long) QStyle::PM_ButtonIconSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_DockWidgetTitleBarButtonMargin", (long) QStyle::PM_DockWidgetTitleBarButtonMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_RadioButtonLabelSpacing", (long) QStyle::PM_RadioButtonLabelSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutLeftMargin", (long) QStyle::PM_LayoutLeftMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutTopMargin", (long) QStyle::PM_LayoutTopMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutRightMargin", (long) QStyle::PM_LayoutRightMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutBottomMargin", (long) QStyle::PM_LayoutBottomMargin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutHorizontalSpacing", (long) QStyle::PM_LayoutHorizontalSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_LayoutVerticalSpacing", (long) QStyle::PM_LayoutVerticalSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabBar_ScrollButtonOverlap", (long) QStyle::PM_TabBar_ScrollButtonOverlap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TextCursorWidth", (long) QStyle::PM_TextCursorWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabCloseIndicatorWidth", (long) QStyle::PM_TabCloseIndicatorWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_TabCloseIndicatorHeight", (long) QStyle::PM_TabCloseIndicatorHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_ScrollView_ScrollBarSpacing", (long) QStyle::PM_ScrollView_ScrollBarSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_SubMenuOverlap", (long) QStyle::PM_SubMenuOverlap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
        &Sbk_QStyle_Type, "PM_CustomBase", (long) QStyle::PM_CustomBase))
        return ;
    // Register converter for enum 'QStyle::PixelMetric'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX],
            QStyle_PixelMetric_CppToPython_QStyle_PixelMetric);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_PixelMetric_PythonToCpp_QStyle_PixelMetric,
            is_QStyle_PixelMetric_PythonToCpp_QStyle_PixelMetric_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_PIXELMETRIC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::PixelMetric");
        Shiboken::Conversions::registerConverterName(converter, "PixelMetric");
    }
    // End of 'PixelMetric' enum.

    // Initialization of enum 'ContentsType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "ContentsType",
        "PySide.QtGui.QStyle.ContentsType",
        "QStyle::ContentsType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_PushButton", (long) QStyle::CT_PushButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_CheckBox", (long) QStyle::CT_CheckBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_RadioButton", (long) QStyle::CT_RadioButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_ToolButton", (long) QStyle::CT_ToolButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_ComboBox", (long) QStyle::CT_ComboBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_Splitter", (long) QStyle::CT_Splitter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_Q3DockWindow", (long) QStyle::CT_Q3DockWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_ProgressBar", (long) QStyle::CT_ProgressBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_MenuItem", (long) QStyle::CT_MenuItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_MenuBarItem", (long) QStyle::CT_MenuBarItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_MenuBar", (long) QStyle::CT_MenuBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_Menu", (long) QStyle::CT_Menu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_TabBarTab", (long) QStyle::CT_TabBarTab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_Slider", (long) QStyle::CT_Slider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_ScrollBar", (long) QStyle::CT_ScrollBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_Q3Header", (long) QStyle::CT_Q3Header))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_LineEdit", (long) QStyle::CT_LineEdit))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_SpinBox", (long) QStyle::CT_SpinBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_SizeGrip", (long) QStyle::CT_SizeGrip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_TabWidget", (long) QStyle::CT_TabWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_DialogButtons", (long) QStyle::CT_DialogButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_HeaderSection", (long) QStyle::CT_HeaderSection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_GroupBox", (long) QStyle::CT_GroupBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_MdiControls", (long) QStyle::CT_MdiControls))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_ItemViewItem", (long) QStyle::CT_ItemViewItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
        &Sbk_QStyle_Type, "CT_CustomBase", (long) QStyle::CT_CustomBase))
        return ;
    // Register converter for enum 'QStyle::ContentsType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX],
            QStyle_ContentsType_CppToPython_QStyle_ContentsType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_ContentsType_PythonToCpp_QStyle_ContentsType,
            is_QStyle_ContentsType_PythonToCpp_QStyle_ContentsType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::ContentsType");
        Shiboken::Conversions::registerConverterName(converter, "ContentsType");
    }
    // End of 'ContentsType' enum.

    // Initialization of enum 'RequestSoftwareInputPanel'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "RequestSoftwareInputPanel",
        "PySide.QtGui.QStyle.RequestSoftwareInputPanel",
        "QStyle::RequestSoftwareInputPanel");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX],
        &Sbk_QStyle_Type, "RSIP_OnMouseClickAndAlreadyFocused", (long) QStyle::RSIP_OnMouseClickAndAlreadyFocused))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX],
        &Sbk_QStyle_Type, "RSIP_OnMouseClick", (long) QStyle::RSIP_OnMouseClick))
        return ;
    // Register converter for enum 'QStyle::RequestSoftwareInputPanel'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX],
            QStyle_RequestSoftwareInputPanel_CppToPython_QStyle_RequestSoftwareInputPanel);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_RequestSoftwareInputPanel_PythonToCpp_QStyle_RequestSoftwareInputPanel,
            is_QStyle_RequestSoftwareInputPanel_PythonToCpp_QStyle_RequestSoftwareInputPanel_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_REQUESTSOFTWAREINPUTPANEL_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::RequestSoftwareInputPanel");
        Shiboken::Conversions::registerConverterName(converter, "RequestSoftwareInputPanel");
    }
    // End of 'RequestSoftwareInputPanel' enum.

    // Initialization of enum 'StyleHint'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "StyleHint",
        "PySide.QtGui.QStyle.StyleHint",
        "QStyle::StyleHint");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_EtchDisabledText", (long) QStyle::SH_EtchDisabledText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DitherDisabledText", (long) QStyle::SH_DitherDisabledText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_MiddleClickAbsolutePosition", (long) QStyle::SH_ScrollBar_MiddleClickAbsolutePosition))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_ScrollWhenPointerLeavesControl", (long) QStyle::SH_ScrollBar_ScrollWhenPointerLeavesControl))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabBar_SelectMouseType", (long) QStyle::SH_TabBar_SelectMouseType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabBar_Alignment", (long) QStyle::SH_TabBar_Alignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Header_ArrowAlignment", (long) QStyle::SH_Header_ArrowAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Slider_SnapToValue", (long) QStyle::SH_Slider_SnapToValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Slider_SloppyKeyEvents", (long) QStyle::SH_Slider_SloppyKeyEvents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ProgressDialog_CenterCancelButton", (long) QStyle::SH_ProgressDialog_CenterCancelButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ProgressDialog_TextLabelAlignment", (long) QStyle::SH_ProgressDialog_TextLabelAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_PrintDialog_RightAlignButtons", (long) QStyle::SH_PrintDialog_RightAlignButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MainWindow_SpaceBelowMenuBar", (long) QStyle::SH_MainWindow_SpaceBelowMenuBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FontDialog_SelectAssociatedText", (long) QStyle::SH_FontDialog_SelectAssociatedText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_AllowActiveAndDisabled", (long) QStyle::SH_Menu_AllowActiveAndDisabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_SpaceActivatesItem", (long) QStyle::SH_Menu_SpaceActivatesItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_SubMenuPopupDelay", (long) QStyle::SH_Menu_SubMenuPopupDelay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollView_FrameOnlyAroundContents", (long) QStyle::SH_ScrollView_FrameOnlyAroundContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MenuBar_AltKeyNavigation", (long) QStyle::SH_MenuBar_AltKeyNavigation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ComboBox_ListMouseTracking", (long) QStyle::SH_ComboBox_ListMouseTracking))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_MouseTracking", (long) QStyle::SH_Menu_MouseTracking))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MenuBar_MouseTracking", (long) QStyle::SH_MenuBar_MouseTracking))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_ChangeHighlightOnFocus", (long) QStyle::SH_ItemView_ChangeHighlightOnFocus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Widget_ShareActivation", (long) QStyle::SH_Widget_ShareActivation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Workspace_FillSpaceOnMaximize", (long) QStyle::SH_Workspace_FillSpaceOnMaximize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ComboBox_Popup", (long) QStyle::SH_ComboBox_Popup))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TitleBar_NoBorder", (long) QStyle::SH_TitleBar_NoBorder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Slider_StopMouseOverSlider", (long) QStyle::SH_Slider_StopMouseOverSlider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_StopMouseOverSlider", (long) QStyle::SH_ScrollBar_StopMouseOverSlider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_BlinkCursorWhenTextSelected", (long) QStyle::SH_BlinkCursorWhenTextSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_RichText_FullWidthSelection", (long) QStyle::SH_RichText_FullWidthSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_Scrollable", (long) QStyle::SH_Menu_Scrollable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_GroupBox_TextLabelVerticalAlignment", (long) QStyle::SH_GroupBox_TextLabelVerticalAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_GroupBox_TextLabelColor", (long) QStyle::SH_GroupBox_TextLabelColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_SloppySubMenus", (long) QStyle::SH_Menu_SloppySubMenus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Table_GridLineColor", (long) QStyle::SH_Table_GridLineColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_LineEdit_PasswordCharacter", (long) QStyle::SH_LineEdit_PasswordCharacter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DialogButtons_DefaultButton", (long) QStyle::SH_DialogButtons_DefaultButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolBox_SelectedPageTitleBold", (long) QStyle::SH_ToolBox_SelectedPageTitleBold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabBar_PreferNoArrows", (long) QStyle::SH_TabBar_PreferNoArrows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_LeftClickAbsolutePosition", (long) QStyle::SH_ScrollBar_LeftClickAbsolutePosition))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Q3ListViewExpand_SelectMouseType", (long) QStyle::SH_Q3ListViewExpand_SelectMouseType))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_UnderlineShortcut", (long) QStyle::SH_UnderlineShortcut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpinBox_AnimateButton", (long) QStyle::SH_SpinBox_AnimateButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpinBox_KeyPressAutoRepeatRate", (long) QStyle::SH_SpinBox_KeyPressAutoRepeatRate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpinBox_ClickAutoRepeatRate", (long) QStyle::SH_SpinBox_ClickAutoRepeatRate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_FillScreenWithScroll", (long) QStyle::SH_Menu_FillScreenWithScroll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolTipLabel_Opacity", (long) QStyle::SH_ToolTipLabel_Opacity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DrawMenuBarSeparator", (long) QStyle::SH_DrawMenuBarSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TitleBar_ModifyNotification", (long) QStyle::SH_TitleBar_ModifyNotification))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Button_FocusPolicy", (long) QStyle::SH_Button_FocusPolicy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MenuBar_DismissOnSecondClick", (long) QStyle::SH_MenuBar_DismissOnSecondClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MessageBox_UseBorderForButtonSpacing", (long) QStyle::SH_MessageBox_UseBorderForButtonSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TitleBar_AutoRaise", (long) QStyle::SH_TitleBar_AutoRaise))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolButton_PopupDelay", (long) QStyle::SH_ToolButton_PopupDelay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FocusFrame_Mask", (long) QStyle::SH_FocusFrame_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_RubberBand_Mask", (long) QStyle::SH_RubberBand_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_WindowFrame_Mask", (long) QStyle::SH_WindowFrame_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpinControls_DisableOnBounds", (long) QStyle::SH_SpinControls_DisableOnBounds))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Dial_BackgroundRole", (long) QStyle::SH_Dial_BackgroundRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ComboBox_LayoutDirection", (long) QStyle::SH_ComboBox_LayoutDirection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_EllipsisLocation", (long) QStyle::SH_ItemView_EllipsisLocation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_ShowDecorationSelected", (long) QStyle::SH_ItemView_ShowDecorationSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_ActivateItemOnSingleClick", (long) QStyle::SH_ItemView_ActivateItemOnSingleClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_ContextMenu", (long) QStyle::SH_ScrollBar_ContextMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ScrollBar_RollBetweenButtons", (long) QStyle::SH_ScrollBar_RollBetweenButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Slider_AbsoluteSetButtons", (long) QStyle::SH_Slider_AbsoluteSetButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Slider_PageSetButtons", (long) QStyle::SH_Slider_PageSetButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_KeyboardSearch", (long) QStyle::SH_Menu_KeyboardSearch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabBar_ElideMode", (long) QStyle::SH_TabBar_ElideMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DialogButtonLayout", (long) QStyle::SH_DialogButtonLayout))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ComboBox_PopupFrameStyle", (long) QStyle::SH_ComboBox_PopupFrameStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MessageBox_TextInteractionFlags", (long) QStyle::SH_MessageBox_TextInteractionFlags))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DialogButtonBox_ButtonsHaveIcons", (long) QStyle::SH_DialogButtonBox_ButtonsHaveIcons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpellCheckUnderlineStyle", (long) QStyle::SH_SpellCheckUnderlineStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_MessageBox_CenterButtons", (long) QStyle::SH_MessageBox_CenterButtons))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_SelectionWrap", (long) QStyle::SH_Menu_SelectionWrap))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_MovementWithoutUpdatingSelection", (long) QStyle::SH_ItemView_MovementWithoutUpdatingSelection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolTip_Mask", (long) QStyle::SH_ToolTip_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FocusFrame_AboveWidget", (long) QStyle::SH_FocusFrame_AboveWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TextControl_FocusIndicatorTextCharFormat", (long) QStyle::SH_TextControl_FocusIndicatorTextCharFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_WizardStyle", (long) QStyle::SH_WizardStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_ArrowKeysNavigateIntoChildren", (long) QStyle::SH_ItemView_ArrowKeysNavigateIntoChildren))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_Mask", (long) QStyle::SH_Menu_Mask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_FlashTriggeredItem", (long) QStyle::SH_Menu_FlashTriggeredItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_Menu_FadeOutOnHide", (long) QStyle::SH_Menu_FadeOutOnHide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_SpinBox_ClickAutoRepeatThreshold", (long) QStyle::SH_SpinBox_ClickAutoRepeatThreshold))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_PaintAlternatingRowColorsForEmptyArea", (long) QStyle::SH_ItemView_PaintAlternatingRowColorsForEmptyArea))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FormLayoutWrapPolicy", (long) QStyle::SH_FormLayoutWrapPolicy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabWidget_DefaultTabPosition", (long) QStyle::SH_TabWidget_DefaultTabPosition))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolBar_Movable", (long) QStyle::SH_ToolBar_Movable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FormLayoutFieldGrowthPolicy", (long) QStyle::SH_FormLayoutFieldGrowthPolicy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FormLayoutFormAlignment", (long) QStyle::SH_FormLayoutFormAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_FormLayoutLabelAlignment", (long) QStyle::SH_FormLayoutLabelAlignment))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ItemView_DrawDelegateFrame", (long) QStyle::SH_ItemView_DrawDelegateFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_TabBar_CloseButtonPosition", (long) QStyle::SH_TabBar_CloseButtonPosition))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_DockWidget_ButtonsHaveFrame", (long) QStyle::SH_DockWidget_ButtonsHaveFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_ToolButtonStyle", (long) QStyle::SH_ToolButtonStyle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_RequestSoftwareInputPanel", (long) QStyle::SH_RequestSoftwareInputPanel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
        &Sbk_QStyle_Type, "SH_CustomBase", (long) QStyle::SH_CustomBase))
        return ;
    // Register converter for enum 'QStyle::StyleHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX],
            QStyle_StyleHint_CppToPython_QStyle_StyleHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_StyleHint_PythonToCpp_QStyle_StyleHint,
            is_QStyle_StyleHint_PythonToCpp_QStyle_StyleHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::StyleHint");
        Shiboken::Conversions::registerConverterName(converter, "StyleHint");
    }
    // End of 'StyleHint' enum.

    // Initialization of enum 'StandardPixmap'.
    SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyle_Type,
        "StandardPixmap",
        "PySide.QtGui.QStyle.StandardPixmap",
        "QStyle::StandardPixmap");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarMenuButton", (long) QStyle::SP_TitleBarMenuButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarMinButton", (long) QStyle::SP_TitleBarMinButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarMaxButton", (long) QStyle::SP_TitleBarMaxButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarCloseButton", (long) QStyle::SP_TitleBarCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarNormalButton", (long) QStyle::SP_TitleBarNormalButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarShadeButton", (long) QStyle::SP_TitleBarShadeButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarUnshadeButton", (long) QStyle::SP_TitleBarUnshadeButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TitleBarContextHelpButton", (long) QStyle::SP_TitleBarContextHelpButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DockWidgetCloseButton", (long) QStyle::SP_DockWidgetCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MessageBoxInformation", (long) QStyle::SP_MessageBoxInformation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MessageBoxWarning", (long) QStyle::SP_MessageBoxWarning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MessageBoxCritical", (long) QStyle::SP_MessageBoxCritical))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MessageBoxQuestion", (long) QStyle::SP_MessageBoxQuestion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DesktopIcon", (long) QStyle::SP_DesktopIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_TrashIcon", (long) QStyle::SP_TrashIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ComputerIcon", (long) QStyle::SP_ComputerIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DriveFDIcon", (long) QStyle::SP_DriveFDIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DriveHDIcon", (long) QStyle::SP_DriveHDIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DriveCDIcon", (long) QStyle::SP_DriveCDIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DriveDVDIcon", (long) QStyle::SP_DriveDVDIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DriveNetIcon", (long) QStyle::SP_DriveNetIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DirOpenIcon", (long) QStyle::SP_DirOpenIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DirClosedIcon", (long) QStyle::SP_DirClosedIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DirLinkIcon", (long) QStyle::SP_DirLinkIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileIcon", (long) QStyle::SP_FileIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileLinkIcon", (long) QStyle::SP_FileLinkIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ToolBarHorizontalExtensionButton", (long) QStyle::SP_ToolBarHorizontalExtensionButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ToolBarVerticalExtensionButton", (long) QStyle::SP_ToolBarVerticalExtensionButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogStart", (long) QStyle::SP_FileDialogStart))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogEnd", (long) QStyle::SP_FileDialogEnd))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogToParent", (long) QStyle::SP_FileDialogToParent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogNewFolder", (long) QStyle::SP_FileDialogNewFolder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogDetailedView", (long) QStyle::SP_FileDialogDetailedView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogInfoView", (long) QStyle::SP_FileDialogInfoView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogContentsView", (long) QStyle::SP_FileDialogContentsView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogListView", (long) QStyle::SP_FileDialogListView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_FileDialogBack", (long) QStyle::SP_FileDialogBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DirIcon", (long) QStyle::SP_DirIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogOkButton", (long) QStyle::SP_DialogOkButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogCancelButton", (long) QStyle::SP_DialogCancelButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogHelpButton", (long) QStyle::SP_DialogHelpButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogOpenButton", (long) QStyle::SP_DialogOpenButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogSaveButton", (long) QStyle::SP_DialogSaveButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogCloseButton", (long) QStyle::SP_DialogCloseButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogApplyButton", (long) QStyle::SP_DialogApplyButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogResetButton", (long) QStyle::SP_DialogResetButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogDiscardButton", (long) QStyle::SP_DialogDiscardButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogYesButton", (long) QStyle::SP_DialogYesButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DialogNoButton", (long) QStyle::SP_DialogNoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowUp", (long) QStyle::SP_ArrowUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowDown", (long) QStyle::SP_ArrowDown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowLeft", (long) QStyle::SP_ArrowLeft))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowRight", (long) QStyle::SP_ArrowRight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowBack", (long) QStyle::SP_ArrowBack))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_ArrowForward", (long) QStyle::SP_ArrowForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_DirHomeIcon", (long) QStyle::SP_DirHomeIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_CommandLink", (long) QStyle::SP_CommandLink))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_VistaShield", (long) QStyle::SP_VistaShield))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_BrowserReload", (long) QStyle::SP_BrowserReload))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_BrowserStop", (long) QStyle::SP_BrowserStop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaPlay", (long) QStyle::SP_MediaPlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaStop", (long) QStyle::SP_MediaStop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaPause", (long) QStyle::SP_MediaPause))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaSkipForward", (long) QStyle::SP_MediaSkipForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaSkipBackward", (long) QStyle::SP_MediaSkipBackward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaSeekForward", (long) QStyle::SP_MediaSeekForward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaSeekBackward", (long) QStyle::SP_MediaSeekBackward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaVolume", (long) QStyle::SP_MediaVolume))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_MediaVolumeMuted", (long) QStyle::SP_MediaVolumeMuted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
        &Sbk_QStyle_Type, "SP_CustomBase", (long) QStyle::SP_CustomBase))
        return ;
    // Register converter for enum 'QStyle::StandardPixmap'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX],
            QStyle_StandardPixmap_CppToPython_QStyle_StandardPixmap);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyle_StandardPixmap_PythonToCpp_QStyle_StandardPixmap,
            is_QStyle_StandardPixmap_PythonToCpp_QStyle_StandardPixmap_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyle::StandardPixmap");
        Shiboken::Conversions::registerConverterName(converter, "StandardPixmap");
    }
    // End of 'StandardPixmap' enum.

    PySide::Signal::registerSignals(&Sbk_QStyle_Type, &::QStyle::staticMetaObject);

    qRegisterMetaType< ::QStyle::StateFlag >("QStyle::StateFlag");
    qRegisterMetaType< ::QStyle::State >("QStyle::State");
    qRegisterMetaType< ::QStyle::PrimitiveElement >("QStyle::PrimitiveElement");
    qRegisterMetaType< ::QStyle::ControlElement >("QStyle::ControlElement");
    qRegisterMetaType< ::QStyle::SubElement >("QStyle::SubElement");
    qRegisterMetaType< ::QStyle::ComplexControl >("QStyle::ComplexControl");
    qRegisterMetaType< ::QStyle::SubControl >("QStyle::SubControl");
    qRegisterMetaType< ::QStyle::SubControls >("QStyle::SubControls");
    qRegisterMetaType< ::QStyle::PixelMetric >("QStyle::PixelMetric");
    qRegisterMetaType< ::QStyle::ContentsType >("QStyle::ContentsType");
    qRegisterMetaType< ::QStyle::RequestSoftwareInputPanel >("QStyle::RequestSoftwareInputPanel");
    qRegisterMetaType< ::QStyle::StyleHint >("QStyle::StyleHint");
    qRegisterMetaType< ::QStyle::StandardPixmap >("QStyle::StandardPixmap");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QStyle_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QStyle_Type, &::QStyle::staticMetaObject, sizeof(::QStyle));
}
