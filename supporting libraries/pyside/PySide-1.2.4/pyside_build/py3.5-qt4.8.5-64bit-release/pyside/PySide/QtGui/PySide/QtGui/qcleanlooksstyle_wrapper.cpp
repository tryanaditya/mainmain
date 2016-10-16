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

#include "qcleanlooksstyle_wrapper.h"

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
#include <qwindowsstyle.h>


// Native ---------------------------------------------------------

QCleanlooksStyleWrapper::QCleanlooksStyleWrapper() : QCleanlooksStyle() {
    // ... middle
}

void QCleanlooksStyleWrapper::childEvent(QChildEvent * arg__1)
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

void QCleanlooksStyleWrapper::connectNotify(const char * signal)
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

void QCleanlooksStyleWrapper::customEvent(QEvent * arg__1)
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

void QCleanlooksStyleWrapper::disconnectNotify(const char * signal)
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

void QCleanlooksStyleWrapper::drawComplexControl(QStyle::ComplexControl control, const QStyleOptionComplex * option, QPainter * painter, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawComplexControl"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::drawComplexControl(control, option, painter, widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), &control),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
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

void QCleanlooksStyleWrapper::drawControl(QStyle::ControlElement ce, const QStyleOption * option, QPainter * painter, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawControl"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::drawControl(ce, option, painter, widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTROLELEMENT_IDX]), &ce),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
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

void QCleanlooksStyleWrapper::drawItemPixmap(QPainter * painter, const QRect & rect, int alignment, const QPixmap & pixmap) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawItemPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::drawItemPixmap(painter, rect, alignment, pixmap);
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

void QCleanlooksStyleWrapper::drawItemText(QPainter * painter, const QRect & rect, int flags, const QPalette & pal, bool enabled, const QString & text, QPalette::ColorRole textRole) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawItemText"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::drawItemText(painter, rect, flags, pal, enabled, text, textRole);
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

void QCleanlooksStyleWrapper::drawPrimitive(QStyle::PrimitiveElement elem, const QStyleOption * option, QPainter * painter, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPrimitive"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::drawPrimitive(elem, option, painter, widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_PRIMITIVEELEMENT_IDX]), &elem),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], painter),
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

bool QCleanlooksStyleWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QCleanlooksStyleWrapper::eventFilter(QObject * o, QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWindowsStyle::eventFilter(o, e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], o),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QPixmap QCleanlooksStyleWrapper::generatedIconPixmap(QIcon::Mode iconMode, const QPixmap & pixmap, const QStyleOption * opt) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "generatedIconPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::generatedIconPixmap(iconMode, pixmap, opt);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.generatedIconPixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStyle::SubControl QCleanlooksStyleWrapper::hitTestComplexControl(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, const QPoint & pt, const QWidget * w) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QStyle::SubControl)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hitTestComplexControl"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::hitTestComplexControl(cc, opt, pt, w);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), &cc),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], opt),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &pt),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], w)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.hitTestComplexControl", Shiboken::SbkType< QStyle::SubControl >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QStyle::SubControl)0);
    }
    ::QStyle::SubControl cppResult = ((::QStyle::SubControl)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QCleanlooksStyleWrapper::itemPixmapRect(const QRect & r, int flags, const QPixmap & pixmap) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemPixmapRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::itemPixmapRect(r, flags, pixmap);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.itemPixmapRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QCleanlooksStyleWrapper::itemTextRect(const QFontMetrics & fm, const QRect & r, int flags, bool enabled, const QString & text) const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.itemTextRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QCleanlooksStyleWrapper::pixelMetric(QStyle::PixelMetric metric, const QStyleOption * option, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pixelMetric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::pixelMetric(metric, option, widget);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.pixelMetric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QCleanlooksStyleWrapper::polish(QApplication * app)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::polish(app);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], app)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QCleanlooksStyleWrapper::polish(QPalette & pal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::polish(pal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &pal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QCleanlooksStyleWrapper::polish(QWidget * widget)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "polish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::polish(widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSize QCleanlooksStyleWrapper::sizeFromContents(QStyle::ContentsType type, const QStyleOption * option, const QSize & size, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSize();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeFromContents"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::sizeFromContents(type, option, size, widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX]), &type),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &size),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.sizeFromContents", Shiboken::SbkType< QSize >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSize();
    }
    ::QSize cppResult = ::QSize();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPalette QCleanlooksStyleWrapper::standardPalette() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPalette();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "standardPalette"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::standardPalette();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.standardPalette", Shiboken::SbkType< QPalette >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPalette();
    }
    ::QPalette cppResult = ::QPalette();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPixmap QCleanlooksStyleWrapper::standardPixmap(QStyle::StandardPixmap standardPixmap, const QStyleOption * opt, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPixmap();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "standardPixmap"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QCleanlooksStyle.standardPixmap()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.standardPixmap", Shiboken::SbkType< QPixmap >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPixmap();
    }
    ::QPixmap cppResult = ::QPixmap();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QCleanlooksStyleWrapper::styleHint(QStyle::StyleHint hint, const QStyleOption * option, const QWidget * widget, QStyleHintReturn * returnData) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "styleHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::styleHint(hint, option, widget, returnData);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STYLEHINT_IDX]), &hint),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], option),
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.styleHint", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg4)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 3));
    return cppResult;
}

QRect QCleanlooksStyleWrapper::subControlRect(QStyle::ComplexControl cc, const QStyleOptionComplex * opt, QStyle::SubControl sc, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "subControlRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::subControlRect(cc, opt, sc, widget);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.subControlRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QRect QCleanlooksStyleWrapper::subElementRect(QStyle::SubElement r, const QStyleOption * opt, const QWidget * widget) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QRect();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "subElementRect"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::subElementRect(r, opt, widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBELEMENT_IDX]), &r),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], opt),
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCleanlooksStyle.subElementRect", Shiboken::SbkType< QRect >()->tp_name, pyResult->ob_type->tp_name);
        return ::QRect();
    }
    ::QRect cppResult = ::QRect();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QCleanlooksStyleWrapper::timerEvent(QTimerEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QWindowsStyle::timerEvent(event);
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

void QCleanlooksStyleWrapper::unpolish(QApplication * app)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unpolish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::unpolish(app);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QAPPLICATION_IDX], app)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QCleanlooksStyleWrapper::unpolish(QWidget * widget)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "unpolish"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCleanlooksStyle::unpolish(widget);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], widget)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

const QMetaObject* QCleanlooksStyleWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QCleanlooksStyle::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QCleanlooksStyleWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QCleanlooksStyle::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QCleanlooksStyleWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QCleanlooksStyleWrapper* >(this));
        return QCleanlooksStyle::qt_metacast(_clname);
}

QCleanlooksStyleWrapper::~QCleanlooksStyleWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QCleanlooksStyle_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QCleanlooksStyle' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QCleanlooksStyle >()))
        return -1;

    ::QCleanlooksStyleWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QCleanlooksStyle()
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QCleanlooksStyleWrapper();
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QCleanlooksStyleWrapper();
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QCleanlooksStyle >(), cptr)) {
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

static PyObject* Sbk_QCleanlooksStyleFunc_drawComplexControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawComplexControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawComplexControl(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_drawComplexControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawComplexControl(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QCleanlooksStyleFunc_drawComplexControl_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::drawComplexControl(cppArg0, cppArg1, cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->drawComplexControl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_drawComplexControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtGui.QPainter, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.drawComplexControl", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_drawControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawControl(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_drawControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawControl(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QCleanlooksStyleFunc_drawControl_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::drawControl(cppArg0, cppArg1, cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->drawControl(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_drawControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ControlElement, PySide.QtGui.QStyleOption, PySide.QtGui.QPainter, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.drawControl", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_drawItemPixmap(PyObject* self, PyObject* args)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_drawItemPixmap_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::drawItemPixmap(cppArg0, *cppArg1, cppArg2, *cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->drawItemPixmap(cppArg0, *cppArg1, cppArg2, *cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_drawItemPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRect, int, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.drawItemPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_drawItemText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawItemText(): too many arguments");
        return 0;
    } else if (numArgs < 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawItemText(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_drawItemText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "textRole");
            if (value && pyArgs[6]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawItemText(): got multiple values for keyword argument 'textRole'.");
                return 0;
            } else if (value) {
                pyArgs[6] = value;
                if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[6]))))
                    goto Sbk_QCleanlooksStyleFunc_drawItemText_TypeError;
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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::drawItemText(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4, cppArg5, cppArg6) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->drawItemText(cppArg0, *cppArg1, cppArg2, *cppArg3, cppArg4, cppArg5, cppArg6);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_drawItemText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRect, int, PySide.QtGui.QPalette, bool, unicode, PySide.QtGui.QPalette.ColorRole = QPalette.NoRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.drawItemText", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_drawPrimitive(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawPrimitive(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawPrimitive(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_drawPrimitive_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.drawPrimitive(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QCleanlooksStyleFunc_drawPrimitive_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::drawPrimitive(cppArg0, cppArg1, cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->drawPrimitive(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_drawPrimitive_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.PrimitiveElement, PySide.QtGui.QStyleOption, PySide.QtGui.QPainter, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.drawPrimitive", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_generatedIconPixmap(PyObject* self, PyObject* args)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_generatedIconPixmap_TypeError;

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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::generatedIconPixmap(cppArg0, *cppArg1, cppArg2) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->generatedIconPixmap(cppArg0, *cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_generatedIconPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon.Mode, PySide.QtGui.QPixmap, PySide.QtGui.QStyleOption", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.generatedIconPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_hitTestComplexControl(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.hitTestComplexControl(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.hitTestComplexControl(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_hitTestComplexControl_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "w");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.hitTestComplexControl(): got multiple values for keyword argument 'w'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3]))))
                    goto Sbk_QCleanlooksStyleFunc_hitTestComplexControl_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStyle::SubControl cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::hitTestComplexControl(cppArg0, cppArg1, *cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->hitTestComplexControl(cppArg0, cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_hitTestComplexControl_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtCore.QPoint, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.hitTestComplexControl", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_itemPixmapRect(PyObject* self, PyObject* args)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_itemPixmapRect_TypeError;

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
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::itemPixmapRect(*cppArg0, cppArg1, *cppArg2) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->itemPixmapRect(*cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_itemPixmapRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.itemPixmapRect", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_pixelMetric(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.pixelMetric(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.pixelMetric(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_pixelMetric_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.pixelMetric(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QCleanlooksStyleFunc_pixelMetric_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.pixelMetric(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QCleanlooksStyleFunc_pixelMetric_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::pixelMetric(cppArg0, cppArg1, cppArg2) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->pixelMetric(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_pixelMetric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.PixelMetric, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.pixelMetric", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_polish(PyObject* self, PyObject* pyArg)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_polish_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // polish(QApplication * app)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QApplication* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // polish(QApplication*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCleanlooksStyle::polish(cppArg0) : cppSelf->polish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // polish(QPalette & pal)
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
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCleanlooksStyle::polish(*cppArg0) : cppSelf->polish(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // polish(QWidget * widget)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // polish(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCleanlooksStyle::polish(cppArg0) : cppSelf->polish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_polish_TypeError:
        const char* overloads[] = {"PySide.QtGui.QApplication", "PySide.QtGui.QPalette", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCleanlooksStyle.polish", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_sizeFromContents(PyObject* self, PyObject* args)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sizeFromContents", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_CONTENTSTYPE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
        overloadId = 0; // sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_sizeFromContents_TypeError;

    // Call function/method
    {
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
        ::QWidget* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // sizeFromContents(QStyle::ContentsType,const QStyleOption*,QSize,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::sizeFromContents(cppArg0, cppArg1, *cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->sizeFromContents(cppArg0, cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_sizeFromContents_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ContentsType, PySide.QtGui.QStyleOption, PySide.QtCore.QSize, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.sizeFromContents", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_standardIconImplementation(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.standardIconImplementation(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.standardIconImplementation(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:standardIconImplementation", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_STANDARDPIXMAP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2])))) {
            overloadId = 0; // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_standardIconImplementation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.standardIconImplementation(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QCleanlooksStyleFunc_standardIconImplementation_TypeError;
            }
        }
        ::QStyle::StandardPixmap cppArg0 = ((::QStyle::StandardPixmap)0);
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
            // standardIconImplementation(QStyle::StandardPixmap,const QStyleOption*,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QCleanlooksStyle*>(cppSelf)->standardIconImplementation(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_standardIconImplementation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StandardPixmap, PySide.QtGui.QStyleOption, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.standardIconImplementation", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_standardPalette(PyObject* self)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardPalette()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPalette cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::standardPalette() : const_cast<const ::QCleanlooksStyle*>(cppSelf)->standardPalette();
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

static PyObject* Sbk_QCleanlooksStyleFunc_styleHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.styleHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.styleHint(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_styleHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "option");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.styleHint(): got multiple values for keyword argument 'option'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[1]))))
                    goto Sbk_QCleanlooksStyleFunc_styleHint_TypeError;
            }
            value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.styleHint(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QCleanlooksStyleFunc_styleHint_TypeError;
            }
            value = PyDict_GetItemString(kwds, "returnData");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.styleHint(): got multiple values for keyword argument 'returnData'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEHINTRETURN_IDX], (pyArgs[3]))))
                    goto Sbk_QCleanlooksStyleFunc_styleHint_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::styleHint(cppArg0, cppArg1, cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->styleHint(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_styleHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.StyleHint, PySide.QtGui.QStyleOption = None, PySide.QtGui.QWidget = None, PySide.QtGui.QStyleHintReturn = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.styleHint", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_subControlRect(PyObject* self, PyObject* args)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "subControlRect", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_COMPLEXCONTROL_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLE_SUBCONTROL_IDX]), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[3])))) {
        overloadId = 0; // subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_subControlRect_TypeError;

    // Call function/method
    {
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
        ::QWidget* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // subControlRect(QStyle::ComplexControl,const QStyleOptionComplex*,QStyle::SubControl,const QWidget*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::subControlRect(cppArg0, cppArg1, cppArg2, cppArg3) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->subControlRect(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_subControlRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.ComplexControl, PySide.QtGui.QStyleOptionComplex, PySide.QtGui.QStyle.SubControl, PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.subControlRect", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_subElementRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.subElementRect(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.subElementRect(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_subElementRect_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCleanlooksStyle.subElementRect(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[2]))))
                    goto Sbk_QCleanlooksStyleFunc_subElementRect_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCleanlooksStyle*>(cppSelf)->::QCleanlooksStyle::subElementRect(cppArg0, cppArg1, cppArg2) : const_cast<const ::QCleanlooksStyle*>(cppSelf)->subElementRect(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCleanlooksStyleFunc_subElementRect_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyle.SubElement, PySide.QtGui.QStyleOption, PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCleanlooksStyle.subElementRect", overloads);
        return 0;
}

static PyObject* Sbk_QCleanlooksStyleFunc_unpolish(PyObject* self, PyObject* pyArg)
{
    ::QCleanlooksStyle* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCleanlooksStyle*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QCleanlooksStyleFunc_unpolish_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // unpolish(QApplication * app)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QApplication* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // unpolish(QApplication*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCleanlooksStyle::unpolish(cppArg0) : cppSelf->unpolish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // unpolish(QWidget * widget)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QWidget* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // unpolish(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCleanlooksStyle::unpolish(cppArg0) : cppSelf->unpolish(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCleanlooksStyleFunc_unpolish_TypeError:
        const char* overloads[] = {"PySide.QtGui.QApplication", "PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCleanlooksStyle.unpolish", overloads);
        return 0;
}

static PyMethodDef Sbk_QCleanlooksStyle_methods[] = {
    {"drawComplexControl", (PyCFunction)Sbk_QCleanlooksStyleFunc_drawComplexControl, METH_VARARGS|METH_KEYWORDS},
    {"drawControl", (PyCFunction)Sbk_QCleanlooksStyleFunc_drawControl, METH_VARARGS|METH_KEYWORDS},
    {"drawItemPixmap", (PyCFunction)Sbk_QCleanlooksStyleFunc_drawItemPixmap, METH_VARARGS},
    {"drawItemText", (PyCFunction)Sbk_QCleanlooksStyleFunc_drawItemText, METH_VARARGS|METH_KEYWORDS},
    {"drawPrimitive", (PyCFunction)Sbk_QCleanlooksStyleFunc_drawPrimitive, METH_VARARGS|METH_KEYWORDS},
    {"generatedIconPixmap", (PyCFunction)Sbk_QCleanlooksStyleFunc_generatedIconPixmap, METH_VARARGS},
    {"hitTestComplexControl", (PyCFunction)Sbk_QCleanlooksStyleFunc_hitTestComplexControl, METH_VARARGS|METH_KEYWORDS},
    {"itemPixmapRect", (PyCFunction)Sbk_QCleanlooksStyleFunc_itemPixmapRect, METH_VARARGS},
    {"pixelMetric", (PyCFunction)Sbk_QCleanlooksStyleFunc_pixelMetric, METH_VARARGS|METH_KEYWORDS},
    {"polish", (PyCFunction)Sbk_QCleanlooksStyleFunc_polish, METH_O},
    {"sizeFromContents", (PyCFunction)Sbk_QCleanlooksStyleFunc_sizeFromContents, METH_VARARGS},
    {"standardIconImplementation", (PyCFunction)Sbk_QCleanlooksStyleFunc_standardIconImplementation, METH_VARARGS|METH_KEYWORDS},
    {"standardPalette", (PyCFunction)Sbk_QCleanlooksStyleFunc_standardPalette, METH_NOARGS},
    {"styleHint", (PyCFunction)Sbk_QCleanlooksStyleFunc_styleHint, METH_VARARGS|METH_KEYWORDS},
    {"subControlRect", (PyCFunction)Sbk_QCleanlooksStyleFunc_subControlRect, METH_VARARGS},
    {"subElementRect", (PyCFunction)Sbk_QCleanlooksStyleFunc_subElementRect, METH_VARARGS|METH_KEYWORDS},
    {"unpolish", (PyCFunction)Sbk_QCleanlooksStyleFunc_unpolish, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QCleanlooksStyle_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QCleanlooksStyle_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QCleanlooksStyle_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QCleanlooksStyle",
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
    /*tp_traverse*/         Sbk_QCleanlooksStyle_traverse,
    /*tp_clear*/            Sbk_QCleanlooksStyle_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QCleanlooksStyle_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QCleanlooksStyle_Init,
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

static void* Sbk_QCleanlooksStyle_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QCleanlooksStyle*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QCleanlooksStyle_PythonToCpp_QCleanlooksStyle_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QCleanlooksStyle_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QCleanlooksStyle_PythonToCpp_QCleanlooksStyle_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QCleanlooksStyle_Type))
        return QCleanlooksStyle_PythonToCpp_QCleanlooksStyle_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QCleanlooksStyle_PTR_CppToPython_QCleanlooksStyle(const void* cppIn) {
    return PySide::getWrapperForQObject((::QCleanlooksStyle*)cppIn, &Sbk_QCleanlooksStyle_Type);

}

void init_QCleanlooksStyle(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QCLEANLOOKSSTYLE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QCleanlooksStyle_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QCleanlooksStyle", "QCleanlooksStyle*",
        &Sbk_QCleanlooksStyle_Type, &Shiboken::callCppDestructor< ::QCleanlooksStyle >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWINDOWSSTYLE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QCleanlooksStyle_Type,
        QCleanlooksStyle_PythonToCpp_QCleanlooksStyle_PTR,
        is_QCleanlooksStyle_PythonToCpp_QCleanlooksStyle_PTR_Convertible,
        QCleanlooksStyle_PTR_CppToPython_QCleanlooksStyle);

    Shiboken::Conversions::registerConverterName(converter, "QCleanlooksStyle");
    Shiboken::Conversions::registerConverterName(converter, "QCleanlooksStyle*");
    Shiboken::Conversions::registerConverterName(converter, "QCleanlooksStyle&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCleanlooksStyle).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCleanlooksStyleWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QCleanlooksStyle_Type, &Sbk_QCleanlooksStyle_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QCleanlooksStyle_Type, &::QCleanlooksStyle::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QCleanlooksStyle_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QCleanlooksStyle_Type, &::QCleanlooksStyle::staticMetaObject, sizeof(::QCleanlooksStyle));
}
