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
#include "pyside_qtgui_python.h"

#include "qpaintengine_wrapper.h"

// Extra includes
#include <QVarLengthArray>
#include <qimage.h>
#include <qline.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>


// Native ---------------------------------------------------------

QPaintEngineWrapper::QPaintEngineWrapper(QFlags<QPaintEngine::PaintEngineFeature> features) : QPaintEngine(features) {
    // ... middle
}

bool QPaintEngineWrapper::begin(QPaintDevice * pdev)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "begin"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.begin()' not implemented.");
        return ((bool)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], pdev)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintEngine.begin", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

QPoint QPaintEngineWrapper::coordinateOffset() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QPoint();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "coordinateOffset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::coordinateOffset();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QPoint();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintEngine.coordinateOffset", Shiboken::SbkType< QPoint >()->tp_name, pyResult->ob_type->tp_name);
        return ::QPoint();
    }
    ::QPoint cppResult = ::QPoint();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPaintEngineWrapper::drawEllipse(const QRect & r)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawEllipse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawEllipse(r);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &r)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawEllipse(const QRectF & r)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawEllipse"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawEllipse(r);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &r)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawImage(const QRectF & r, const QImage & pm, const QRectF & sr, QFlags<Qt::ImageConversionFlag> flags)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawImage"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawImage(r, pm, sr, flags);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &r),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &pm),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &sr),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), &flags)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawLines(const QLine * lines, int lineCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawLines"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawLines(lines, lineCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], lines),
        lineCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawLines(const QLineF * lines, int lineCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawLines"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawLines(lines, lineCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], lines),
        lineCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPath(const QPainterPath & path)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawPath(path);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &path)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPixmap(const QRectF & r, const QPixmap & pm, const QRectF & sr)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPixmap"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.drawPixmap()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &r),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pm),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &sr)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPoints(const QPoint * points, int pointCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPoints"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawPoints(points, pointCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], points),
        pointCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPoints(const QPointF * points, int pointCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPoints"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawPoints(points, pointCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], points),
        pointCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPolygon(const QPoint * points, int pointCount, QPaintEngine::PolygonDrawMode mode)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPolygon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawPolygon(points, pointCount, mode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], points),
        pointCount,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]), &mode)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawPolygon(const QPointF * points, int pointCount, QPaintEngine::PolygonDrawMode mode)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawPolygon"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawPolygon(points, pointCount, mode);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NiN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], points),
        pointCount,
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]), &mode)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawRects(const QRect * rects, int rectCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawRects"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawRects(rects, rectCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], rects),
        rectCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawRects(const QRectF * rects, int rectCount)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawRects"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawRects(rects, rectCount);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], rects),
        rectCount
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QPaintEngineWrapper::drawTextItem(const QPointF & p, const QTextItem & textItem)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawTextItem"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawTextItem(p, textItem);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &p),
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], &textItem)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
}

void QPaintEngineWrapper::drawTiledPixmap(const QRectF & r, const QPixmap & pixmap, const QPointF & s)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "drawTiledPixmap"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintEngine::drawTiledPixmap(r, pixmap, s);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NNN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &r),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &pixmap),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], &s)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QPaintEngineWrapper::end()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "end"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.end()' not implemented.");
        return ((bool)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintEngine.end", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine::Type QPaintEngineWrapper::type() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine::Type)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "type"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.type()' not implemented.");
        return ((::QPaintEngine::Type)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPaintEngine::Type)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintEngine.type", Shiboken::SbkType< QPaintEngine::Type >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine::Type)0);
    }
    ::QPaintEngine::Type cppResult = ((::QPaintEngine::Type)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPaintEngineWrapper::updateState(const QPaintEngineState & state)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateState"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.updateState()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], &state)
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

QPaintEngineWrapper::~QPaintEngineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPaintEngine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QPaintEngine' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPaintEngine >()))
        return -1;

    ::QPaintEngineWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPaintEngine(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QPaintEngine", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPaintEngine(QFlags<QPaintEngine::PaintEngineFeature>)
    if (numArgs == 0) {
        overloadId = 0; // QPaintEngine(QFlags<QPaintEngine::PaintEngineFeature>)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), (pyArgs[0])))) {
        overloadId = 0; // QPaintEngine(QFlags<QPaintEngine::PaintEngineFeature>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngine_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "features");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPaintEngine(): got multiple values for keyword argument 'features'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), (pyArgs[0]))))
                    goto Sbk_QPaintEngine_Init_TypeError;
            }
        }
        ::QFlags<QPaintEngine::PaintEngineFeature> cppArg0 = QFlags<QPaintEngine::PaintEngineFeature>(0);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QPaintEngine(QFlags<QPaintEngine::PaintEngineFeature>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPaintEngineWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPaintEngine >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPaintEngine_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPaintEngine_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.PaintEngineFeatures = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine", overloads);
        return -1;
}

static PyObject* Sbk_QPaintEngineFunc_begin(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: begin(QPaintDevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg)))) {
        overloadId = 0; // begin(QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_begin_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // begin(QPaintDevice*)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.begin()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->begin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaintEngineFunc_begin_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.begin", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_clearDirty(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: clearDirty(QFlags<QPaintEngine::DirtyFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // clearDirty(QFlags<QPaintEngine::DirtyFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_clearDirty_TypeError;

    // Call function/method
    {
        ::QFlags<QPaintEngine::DirtyFlag> cppArg0 = ((::QFlags<QPaintEngine::DirtyFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // clearDirty(QFlags<QPaintEngine::DirtyFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearDirty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_clearDirty_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.DirtyFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.clearDirty", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_coordinateOffset(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // coordinateOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPaintEngine*>(cppSelf)->::QPaintEngine::coordinateOffset() : const_cast<const ::QPaintEngine*>(cppSelf)->coordinateOffset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineFunc_drawEllipse(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawEllipse(QRect)
    // 1: drawEllipse(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // drawEllipse(QRect)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 1; // drawEllipse(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawEllipse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawEllipse(const QRect & r)
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
                // drawEllipse(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawEllipse(*cppArg0) : cppSelf->drawEllipse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawEllipse(const QRectF & r)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawEllipse(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawEllipse(*cppArg0) : cppSelf->drawEllipse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawEllipse_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.drawEllipse", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawImage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPaintEngine.drawImage(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPaintEngine.drawImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:drawImage", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3])))) {
            overloadId = 0; // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawImage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "flags");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPaintEngine.drawImage(): got multiple values for keyword argument 'flags'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3]))))
                    goto Sbk_QPaintEngineFunc_drawImage_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QImage cppArg1_local = ::QImage();
        ::QImage* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QRectF cppArg2_local = ::QRectF();
        ::QRectF* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        ::QFlags<Qt::ImageConversionFlag> cppArg3 = Qt::AutoColor;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3) : cppSelf->drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawImage_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, PySide.QtGui.QImage, PySide.QtCore.QRectF, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawImage", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawLines(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawLines", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawLines(const QLine*,int)
    // 1: drawLines(const QLineF*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // drawLines(const QLine*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // drawLines(const QLineF*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawLines_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawLines(const QLine * lines, int lineCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawLines(const QLine*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawLines(cppArg0, cppArg1) : cppSelf->drawLines(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawLines(const QLineF * lines, int lineCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLineF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawLines(const QLineF*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawLines(cppArg0, cppArg1) : cppSelf->drawLines(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawLines_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLine, int", "PySide.QtCore.QLineF, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawLines", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawPath(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawPath(QPainterPath)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // drawPath(QPainterPath)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // drawPath(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawPath(*cppArg0) : cppSelf->drawPath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.drawPath", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawPixmap(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawPixmap", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawPixmap(QRectF,QPixmap,QRectF)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
        overloadId = 0; // drawPixmap(QRectF,QPixmap,QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawPixmap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
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
        ::QRectF cppArg2_local = ::QRectF();
        ::QRectF* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // drawPixmap(QRectF,QPixmap,QRectF)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.drawPixmap()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->drawPixmap(*cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawPixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, PySide.QtGui.QPixmap, PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawPoints(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawPoints", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawPoints(const QPoint*,int)
    // 1: drawPoints(const QPointF*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // drawPoints(const QPoint*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // drawPoints(const QPointF*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawPoints_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPoints(const QPoint * points, int pointCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawPoints(const QPoint*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawPoints(cppArg0, cppArg1) : cppSelf->drawPoints(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPoints(const QPointF * points, int pointCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawPoints(const QPointF*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawPoints(cppArg0, cppArg1) : cppSelf->drawPoints(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawPoints_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, int", "PySide.QtCore.QPointF, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawPoints", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawPolygon(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawPolygon", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawPolygon(const QPoint*,int,QPaintEngine::PolygonDrawMode)
    // 1: drawPolygon(const QPointF*,int,QPaintEngine::PolygonDrawMode)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]), (pyArgs[2])))) {
        overloadId = 0; // drawPolygon(const QPoint*,int,QPaintEngine::PolygonDrawMode)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]), (pyArgs[2])))) {
        overloadId = 1; // drawPolygon(const QPointF*,int,QPaintEngine::PolygonDrawMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawPolygon_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPolygon(const QPoint * points, int pointCount, QPaintEngine::PolygonDrawMode mode)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QPaintEngine::PolygonDrawMode cppArg2 = ((::QPaintEngine::PolygonDrawMode)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawPolygon(const QPoint*,int,QPaintEngine::PolygonDrawMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawPolygon(cppArg0, cppArg1, cppArg2) : cppSelf->drawPolygon(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPolygon(const QPointF * points, int pointCount, QPaintEngine::PolygonDrawMode mode)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QPaintEngine::PolygonDrawMode cppArg2 = ((::QPaintEngine::PolygonDrawMode)0);
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawPolygon(const QPointF*,int,QPaintEngine::PolygonDrawMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawPolygon(cppArg0, cppArg1, cppArg2) : cppSelf->drawPolygon(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawPolygon_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, int, PySide.QtGui.QPaintEngine.PolygonDrawMode", "PySide.QtCore.QPointF, int, PySide.QtGui.QPaintEngine.PolygonDrawMode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawRects(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawRects", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawRects(const QRect*,int)
    // 1: drawRects(const QRectF*,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // drawRects(const QRect*,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 1; // drawRects(const QRectF*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawRects_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawRects(const QRect * rects, int rectCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawRects(const QRect*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawRects(cppArg0, cppArg1) : cppSelf->drawRects(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawRects(const QRectF * rects, int rectCount)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawRects(const QRectF*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawRects(cppArg0, cppArg1) : cppSelf->drawRects(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawRects_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int", "PySide.QtCore.QRectF, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawRects", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawTextItem(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawTextItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawTextItem(QPointF,QTextItem)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawTextItem(QPointF,QTextItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawTextItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPointF cppArg0_local = ::QPointF();
        ::QPointF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QTextItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // drawTextItem(QPointF,QTextItem)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawTextItem(*cppArg0, *cppArg1) : cppSelf->drawTextItem(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawTextItem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtGui.QTextItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawTextItem", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_drawTiledPixmap(PyObject* self, PyObject* args)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawTiledPixmap", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawTiledPixmap(QRectF,QPixmap,QPointF)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
        overloadId = 0; // drawTiledPixmap(QRectF,QPixmap,QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_drawTiledPixmap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
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
        ::QPointF cppArg2_local = ::QPointF();
        ::QPointF* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);


        if (!PyErr_Occurred()) {
            // drawTiledPixmap(QRectF,QPixmap,QPointF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPaintEngine::drawTiledPixmap(*cppArg0, *cppArg1, *cppArg2) : cppSelf->drawTiledPixmap(*cppArg0, *cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_drawTiledPixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF, PySide.QtGui.QPixmap, PySide.QtCore.QPointF", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPaintEngine.drawTiledPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_end(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // end()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.end()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->end();
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

static PyObject* Sbk_QPaintEngineFunc_hasFeature(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasFeature(QFlags<QPaintEngine::PaintEngineFeature>)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), (pyArg)))) {
        overloadId = 0; // hasFeature(QFlags<QPaintEngine::PaintEngineFeature>)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_hasFeature_TypeError;

    // Call function/method
    {
        ::QFlags<QPaintEngine::PaintEngineFeature> cppArg0 = ((::QFlags<QPaintEngine::PaintEngineFeature>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasFeature(QFlags<QPaintEngine::PaintEngineFeature>)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->hasFeature(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaintEngineFunc_hasFeature_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.PaintEngineFeatures", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.hasFeature", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_isActive(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->isActive();
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

static PyObject* Sbk_QPaintEngineFunc_isExtended(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isExtended()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->isExtended();
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

static PyObject* Sbk_QPaintEngineFunc_paintDevice(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintDevice()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintDevice * cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->paintDevice();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineFunc_painter(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // painter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainter * cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->painter();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineFunc_setActive(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActive(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setActive(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_setActive_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActive(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActive(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_setActive_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.setActive", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_setDirty(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirty(QFlags<QPaintEngine::DirtyFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setDirty(QFlags<QPaintEngine::DirtyFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_setDirty_TypeError;

    // Call function/method
    {
        ::QFlags<QPaintEngine::DirtyFlag> cppArg0 = ((::QFlags<QPaintEngine::DirtyFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDirty(QFlags<QPaintEngine::DirtyFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_setDirty_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.DirtyFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.setDirty", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_setSystemClip(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSystemClip(QRegion)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArg)))) {
        overloadId = 0; // setSystemClip(QRegion)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_setSystemClip_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRegion cppArg0_local = ::QRegion();
        ::QRegion* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSystemClip(QRegion)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSystemClip(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_setSystemClip_TypeError:
        const char* overloads[] = {"PySide.QtGui.QRegion", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.setSystemClip", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_setSystemRect(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSystemRect(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setSystemRect(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_setSystemRect_TypeError;

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
            // setSystemRect(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSystemRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_setSystemRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.setSystemRect", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_syncState(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // syncState()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->syncState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPaintEngineFunc_systemClip(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemClip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegion cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->systemClip();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineFunc_systemRect(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // systemRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->systemRect();
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

static PyObject* Sbk_QPaintEngineFunc_testDirty(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testDirty(QFlags<QPaintEngine::DirtyFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // testDirty(QFlags<QPaintEngine::DirtyFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_testDirty_TypeError;

    // Call function/method
    {
        ::QFlags<QPaintEngine::DirtyFlag> cppArg0 = ((::QFlags<QPaintEngine::DirtyFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testDirty(QFlags<QPaintEngine::DirtyFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->testDirty(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaintEngineFunc_testDirty_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngine.DirtyFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.testDirty", overloads);
        return 0;
}

static PyObject* Sbk_QPaintEngineFunc_type(PyObject* self)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.type()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine::Type cppResult = const_cast<const ::QPaintEngine*>(cppSelf)->type();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineFunc_updateState(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: updateState(QPaintEngineState)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (pyArg)))) {
        overloadId = 0; // updateState(QPaintEngineState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintEngineFunc_updateState_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintEngineState* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // updateState(QPaintEngineState)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintEngine.updateState()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->updateState(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaintEngineFunc_updateState_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEngineState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintEngine.updateState", overloads);
        return 0;
}

static PyMethodDef Sbk_QPaintEngine_methods[] = {
    {"begin", (PyCFunction)Sbk_QPaintEngineFunc_begin, METH_O},
    {"clearDirty", (PyCFunction)Sbk_QPaintEngineFunc_clearDirty, METH_O},
    {"coordinateOffset", (PyCFunction)Sbk_QPaintEngineFunc_coordinateOffset, METH_NOARGS},
    {"drawEllipse", (PyCFunction)Sbk_QPaintEngineFunc_drawEllipse, METH_O},
    {"drawImage", (PyCFunction)Sbk_QPaintEngineFunc_drawImage, METH_VARARGS|METH_KEYWORDS},
    {"drawLines", (PyCFunction)Sbk_QPaintEngineFunc_drawLines, METH_VARARGS},
    {"drawPath", (PyCFunction)Sbk_QPaintEngineFunc_drawPath, METH_O},
    {"drawPixmap", (PyCFunction)Sbk_QPaintEngineFunc_drawPixmap, METH_VARARGS},
    {"drawPoints", (PyCFunction)Sbk_QPaintEngineFunc_drawPoints, METH_VARARGS},
    {"drawPolygon", (PyCFunction)Sbk_QPaintEngineFunc_drawPolygon, METH_VARARGS},
    {"drawRects", (PyCFunction)Sbk_QPaintEngineFunc_drawRects, METH_VARARGS},
    {"drawTextItem", (PyCFunction)Sbk_QPaintEngineFunc_drawTextItem, METH_VARARGS},
    {"drawTiledPixmap", (PyCFunction)Sbk_QPaintEngineFunc_drawTiledPixmap, METH_VARARGS},
    {"end", (PyCFunction)Sbk_QPaintEngineFunc_end, METH_NOARGS},
    {"hasFeature", (PyCFunction)Sbk_QPaintEngineFunc_hasFeature, METH_O},
    {"isActive", (PyCFunction)Sbk_QPaintEngineFunc_isActive, METH_NOARGS},
    {"isExtended", (PyCFunction)Sbk_QPaintEngineFunc_isExtended, METH_NOARGS},
    {"paintDevice", (PyCFunction)Sbk_QPaintEngineFunc_paintDevice, METH_NOARGS},
    {"painter", (PyCFunction)Sbk_QPaintEngineFunc_painter, METH_NOARGS},
    {"setActive", (PyCFunction)Sbk_QPaintEngineFunc_setActive, METH_O},
    {"setDirty", (PyCFunction)Sbk_QPaintEngineFunc_setDirty, METH_O},
    {"setSystemClip", (PyCFunction)Sbk_QPaintEngineFunc_setSystemClip, METH_O},
    {"setSystemRect", (PyCFunction)Sbk_QPaintEngineFunc_setSystemRect, METH_O},
    {"syncState", (PyCFunction)Sbk_QPaintEngineFunc_syncState, METH_NOARGS},
    {"systemClip", (PyCFunction)Sbk_QPaintEngineFunc_systemClip, METH_NOARGS},
    {"systemRect", (PyCFunction)Sbk_QPaintEngineFunc_systemRect, METH_NOARGS},
    {"testDirty", (PyCFunction)Sbk_QPaintEngineFunc_testDirty, METH_O},
    {"type", (PyCFunction)Sbk_QPaintEngineFunc_type, METH_NOARGS},
    {"updateState", (PyCFunction)Sbk_QPaintEngineFunc_updateState, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QPaintEngine_get_extended(PyObject* self, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    uint cppOut_local = cppSelf->extended;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QPaintEngine_set_extended(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'extended' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'extended', 'uint' or convertible type expected");
        return -1;
    }

    uint cppOut_local = cppSelf->extended;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->extended = cppOut_local;

    return 0;
}

static PyObject* Sbk_QPaintEngine_get_selfDestruct(PyObject* self, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    uint cppOut_local = cppSelf->selfDestruct;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QPaintEngine_set_selfDestruct(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'selfDestruct' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'selfDestruct', 'uint' or convertible type expected");
        return -1;
    }

    uint cppOut_local = cppSelf->selfDestruct;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->selfDestruct = cppOut_local;

    return 0;
}

static PyObject* Sbk_QPaintEngine_get_active(PyObject* self, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    uint cppOut_local = cppSelf->active;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QPaintEngine_set_active(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'active' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'active', 'uint' or convertible type expected");
        return -1;
    }

    uint cppOut_local = cppSelf->active;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->active = cppOut_local;

    return 0;
}

static PyObject* Sbk_QPaintEngine_get_state(PyObject* self, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], cppSelf->state);
    return pyOut;
}
static int Sbk_QPaintEngine_set_state(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'state' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'state', 'QPaintEngineState' or convertible type expected");
        return -1;
    }

    ::QPaintEngineState*& cppOut_ptr = cppSelf->state;
    pythonToCpp(pyIn, &cppOut_ptr);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "state", pyIn);
    return 0;
}

static PyObject* Sbk_QPaintEngine_get_gccaps(PyObject* self, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), &cppSelf->gccaps);
    return pyOut;
}
static int Sbk_QPaintEngine_set_gccaps(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'gccaps' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'gccaps', 'PaintEngineFeatures' or convertible type expected");
        return -1;
    }

    ::QFlags<QPaintEngine::PaintEngineFeature> cppOut_local = cppSelf->gccaps;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->gccaps = cppOut_local;

    return 0;
}

// Getters and Setters for QPaintEngine
static PyGetSetDef Sbk_QPaintEngine_getsetlist[] = {
    {const_cast<char*>("extended"), Sbk_QPaintEngine_get_extended, Sbk_QPaintEngine_set_extended},
    {const_cast<char*>("selfDestruct"), Sbk_QPaintEngine_get_selfDestruct, Sbk_QPaintEngine_set_selfDestruct},
    {const_cast<char*>("active"), Sbk_QPaintEngine_get_active, Sbk_QPaintEngine_set_active},
    {const_cast<char*>("state"), Sbk_QPaintEngine_get_state, Sbk_QPaintEngine_set_state},
    {const_cast<char*>("gccaps"), Sbk_QPaintEngine_get_gccaps, Sbk_QPaintEngine_set_gccaps},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QPaintEngine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPaintEngine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPaintEngine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPaintEngine",
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
    /*tp_traverse*/         Sbk_QPaintEngine_traverse,
    /*tp_clear*/            Sbk_QPaintEngine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPaintEngine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QPaintEngine_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPaintEngine_Init,
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

PyObject* SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___and__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::PaintEngineFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyLong_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyInt_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___or__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::PaintEngineFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyLong_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyInt_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___xor__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::PaintEngineFeatures cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyLong_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::PaintEngineFeatures)PyInt_AsLong(self);
    cppArg = (QPaintEngine::PaintEngineFeatures)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___invert__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::PaintEngineFeatures cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), self, &cppSelf);
    ::QPaintEngine::PaintEngineFeatures cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QPaintEngine_PaintEngineFeature_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QPaintEngine_PaintEngineFeature__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QPaintEngine_PaintEngineFeature_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QPaintEngine_PaintEngineFeature__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QPaintEngine_PaintEngineFeature___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QPaintEngine_PaintEngineFeature_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QPaintEngine_PaintEngineFeature_long,
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


PyObject* SbkPySide_QtGui_QPaintEngine_DirtyFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::DirtyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::DirtyFlags)PyLong_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::DirtyFlags)PyInt_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_DirtyFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::DirtyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::DirtyFlags)PyLong_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::DirtyFlags)PyInt_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_DirtyFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::DirtyFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPaintEngine::DirtyFlags)PyLong_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPaintEngine::DirtyFlags)PyInt_AsLong(self);
    cppArg = (QPaintEngine::DirtyFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPaintEngine_DirtyFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QPaintEngine::DirtyFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), self, &cppSelf);
    ::QPaintEngine::DirtyFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QPaintEngine_DirtyFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QPaintEngine_DirtyFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QPaintEngine_DirtyFlag_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtGui_QPaintEngine_DirtyFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QPaintEngine_DirtyFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QPaintEngine_DirtyFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QPaintEngine_DirtyFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QPaintEngine_DirtyFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QPaintEngine_DirtyFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QPaintEngine_DirtyFlag_long,
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
static void QPaintEngine_PaintEngineFeature_PythonToCpp_QPaintEngine_PaintEngineFeature(PyObject* pyIn, void* cppOut) {
    *((::QPaintEngine::PaintEngineFeature*)cppOut) = (::QPaintEngine::PaintEngineFeature) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPaintEngine_PaintEngineFeature_PythonToCpp_QPaintEngine_PaintEngineFeature_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX]))
        return QPaintEngine_PaintEngineFeature_PythonToCpp_QPaintEngine_PaintEngineFeature;
    return 0;
}
static PyObject* QPaintEngine_PaintEngineFeature_CppToPython_QPaintEngine_PaintEngineFeature(const void* cppIn) {
    int castCppIn = *((::QPaintEngine::PaintEngineFeature*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX], castCppIn);

}

static void QFlags_QPaintEngine_PaintEngineFeature__PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPaintEngine::PaintEngineFeature>*)cppOut) = ::QFlags<QPaintEngine::PaintEngineFeature>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QPaintEngine_PaintEngineFeature__PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]))
        return QFlags_QPaintEngine_PaintEngineFeature__PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_;
    return 0;
}
static PyObject* QFlags_QPaintEngine_PaintEngineFeature__CppToPython_QFlags_QPaintEngine_PaintEngineFeature_(const void* cppIn) {
    int castCppIn = *((::QFlags<QPaintEngine::PaintEngineFeature>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]));

}

static void QPaintEngine_PaintEngineFeature_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPaintEngine::PaintEngineFeature>*)cppOut) = ::QFlags<QPaintEngine::PaintEngineFeature>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QPaintEngine_PaintEngineFeature_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX]))
        return QPaintEngine_PaintEngineFeature_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_;
    return 0;
}
static void number_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QPaintEngine::PaintEngineFeature>*)cppOut) = ::QFlags<QPaintEngine::PaintEngineFeature>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_;
    return 0;
}
static void QPaintEngine_DirtyFlag_PythonToCpp_QPaintEngine_DirtyFlag(PyObject* pyIn, void* cppOut) {
    *((::QPaintEngine::DirtyFlag*)cppOut) = (::QPaintEngine::DirtyFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPaintEngine_DirtyFlag_PythonToCpp_QPaintEngine_DirtyFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX]))
        return QPaintEngine_DirtyFlag_PythonToCpp_QPaintEngine_DirtyFlag;
    return 0;
}
static PyObject* QPaintEngine_DirtyFlag_CppToPython_QPaintEngine_DirtyFlag(const void* cppIn) {
    int castCppIn = *((::QPaintEngine::DirtyFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX], castCppIn);

}

static void QFlags_QPaintEngine_DirtyFlag__PythonToCpp_QFlags_QPaintEngine_DirtyFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPaintEngine::DirtyFlag>*)cppOut) = ::QFlags<QPaintEngine::DirtyFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QPaintEngine_DirtyFlag__PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]))
        return QFlags_QPaintEngine_DirtyFlag__PythonToCpp_QFlags_QPaintEngine_DirtyFlag_;
    return 0;
}
static PyObject* QFlags_QPaintEngine_DirtyFlag__CppToPython_QFlags_QPaintEngine_DirtyFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QPaintEngine::DirtyFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]));

}

static void QPaintEngine_DirtyFlag_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPaintEngine::DirtyFlag>*)cppOut) = ::QFlags<QPaintEngine::DirtyFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QPaintEngine_DirtyFlag_PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX]))
        return QPaintEngine_DirtyFlag_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QPaintEngine::DirtyFlag>*)cppOut) = ::QFlags<QPaintEngine::DirtyFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_;
    return 0;
}
static void QPaintEngine_PolygonDrawMode_PythonToCpp_QPaintEngine_PolygonDrawMode(PyObject* pyIn, void* cppOut) {
    *((::QPaintEngine::PolygonDrawMode*)cppOut) = (::QPaintEngine::PolygonDrawMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPaintEngine_PolygonDrawMode_PythonToCpp_QPaintEngine_PolygonDrawMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]))
        return QPaintEngine_PolygonDrawMode_PythonToCpp_QPaintEngine_PolygonDrawMode;
    return 0;
}
static PyObject* QPaintEngine_PolygonDrawMode_CppToPython_QPaintEngine_PolygonDrawMode(const void* cppIn) {
    int castCppIn = *((::QPaintEngine::PolygonDrawMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX], castCppIn);

}

static void QPaintEngine_Type_PythonToCpp_QPaintEngine_Type(PyObject* pyIn, void* cppOut) {
    *((::QPaintEngine::Type*)cppOut) = (::QPaintEngine::Type) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPaintEngine_Type_PythonToCpp_QPaintEngine_Type_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX]))
        return QPaintEngine_Type_PythonToCpp_QPaintEngine_Type;
    return 0;
}
static PyObject* QPaintEngine_Type_CppToPython_QPaintEngine_Type(const void* cppIn) {
    int castCppIn = *((::QPaintEngine::Type*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPaintEngine_PythonToCpp_QPaintEngine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPaintEngine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPaintEngine_PythonToCpp_QPaintEngine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPaintEngine_Type))
        return QPaintEngine_PythonToCpp_QPaintEngine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPaintEngine_PTR_CppToPython_QPaintEngine(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPaintEngine*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPaintEngine_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPaintEngine(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPaintEngine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPaintEngine", "QPaintEngine*",
        &Sbk_QPaintEngine_Type, &Shiboken::callCppDestructor< ::QPaintEngine >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPaintEngine_Type,
        QPaintEngine_PythonToCpp_QPaintEngine_PTR,
        is_QPaintEngine_PythonToCpp_QPaintEngine_PTR_Convertible,
        QPaintEngine_PTR_CppToPython_QPaintEngine);

    Shiboken::Conversions::registerConverterName(converter, "QPaintEngine");
    Shiboken::Conversions::registerConverterName(converter, "QPaintEngine*");
    Shiboken::Conversions::registerConverterName(converter, "QPaintEngine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPaintEngine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPaintEngineWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'PaintEngineFeature'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX] = PySide::QFlags::create("PaintEngineFeatures", &SbkPySide_QtGui_QPaintEngine_PaintEngineFeature_as_number);
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPaintEngine_Type,
        "PaintEngineFeature",
        "PySide.QtGui.QPaintEngine.PaintEngineFeature",
        "QPaintEngine::PaintEngineFeature",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PrimitiveTransform", (long) QPaintEngine::PrimitiveTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PatternTransform", (long) QPaintEngine::PatternTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PixmapTransform", (long) QPaintEngine::PixmapTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PatternBrush", (long) QPaintEngine::PatternBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "LinearGradientFill", (long) QPaintEngine::LinearGradientFill))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "RadialGradientFill", (long) QPaintEngine::RadialGradientFill))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "ConicalGradientFill", (long) QPaintEngine::ConicalGradientFill))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "AlphaBlend", (long) QPaintEngine::AlphaBlend))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PorterDuff", (long) QPaintEngine::PorterDuff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PainterPaths", (long) QPaintEngine::PainterPaths))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "Antialiasing", (long) QPaintEngine::Antialiasing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "BrushStroke", (long) QPaintEngine::BrushStroke))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "ConstantOpacity", (long) QPaintEngine::ConstantOpacity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "MaskedBrush", (long) QPaintEngine::MaskedBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PerspectiveTransform", (long) QPaintEngine::PerspectiveTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "BlendModes", (long) QPaintEngine::BlendModes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "ObjectBoundingModeGradients", (long) QPaintEngine::ObjectBoundingModeGradients))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "RasterOpModes", (long) QPaintEngine::RasterOpModes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "PaintOutsidePaintEvent", (long) QPaintEngine::PaintOutsidePaintEvent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
        &Sbk_QPaintEngine_Type, "AllFeatures", (long) QPaintEngine::AllFeatures))
        return ;
    // Register converter for enum 'QPaintEngine::PaintEngineFeature'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX],
            QPaintEngine_PaintEngineFeature_CppToPython_QPaintEngine_PaintEngineFeature);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_PaintEngineFeature_PythonToCpp_QPaintEngine_PaintEngineFeature,
            is_QPaintEngine_PaintEngineFeature_PythonToCpp_QPaintEngine_PaintEngineFeature_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPaintEngine::PaintEngineFeature");
        Shiboken::Conversions::registerConverterName(converter, "PaintEngineFeature");
    }
    // Register converter for flag 'QFlags<QPaintEngine::PaintEngineFeature>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX],
            QFlags_QPaintEngine_PaintEngineFeature__CppToPython_QFlags_QPaintEngine_PaintEngineFeature_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_PaintEngineFeature_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_,
            is_QPaintEngine_PaintEngineFeature_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QPaintEngine_PaintEngineFeature__PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_,
            is_QFlags_QPaintEngine_PaintEngineFeature__PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature_,
            is_number_PythonToCpp_QFlags_QPaintEngine_PaintEngineFeature__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QPaintEngine::PaintEngineFeature>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<PaintEngineFeature>");
    }
    // End of 'PaintEngineFeature' enum/flags.

    // Initialization of enum 'DirtyFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX] = PySide::QFlags::create("DirtyFlags", &SbkPySide_QtGui_QPaintEngine_DirtyFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPaintEngine_Type,
        "DirtyFlag",
        "PySide.QtGui.QPaintEngine.DirtyFlag",
        "QPaintEngine::DirtyFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyPen", (long) QPaintEngine::DirtyPen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyBrush", (long) QPaintEngine::DirtyBrush))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyBrushOrigin", (long) QPaintEngine::DirtyBrushOrigin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyFont", (long) QPaintEngine::DirtyFont))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyBackground", (long) QPaintEngine::DirtyBackground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyBackgroundMode", (long) QPaintEngine::DirtyBackgroundMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyTransform", (long) QPaintEngine::DirtyTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyClipRegion", (long) QPaintEngine::DirtyClipRegion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyClipPath", (long) QPaintEngine::DirtyClipPath))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyHints", (long) QPaintEngine::DirtyHints))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyCompositionMode", (long) QPaintEngine::DirtyCompositionMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyClipEnabled", (long) QPaintEngine::DirtyClipEnabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "DirtyOpacity", (long) QPaintEngine::DirtyOpacity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
        &Sbk_QPaintEngine_Type, "AllDirty", (long) QPaintEngine::AllDirty))
        return ;
    // Register converter for enum 'QPaintEngine::DirtyFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX],
            QPaintEngine_DirtyFlag_CppToPython_QPaintEngine_DirtyFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_DirtyFlag_PythonToCpp_QPaintEngine_DirtyFlag,
            is_QPaintEngine_DirtyFlag_PythonToCpp_QPaintEngine_DirtyFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPaintEngine::DirtyFlag");
        Shiboken::Conversions::registerConverterName(converter, "DirtyFlag");
    }
    // Register converter for flag 'QFlags<QPaintEngine::DirtyFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX],
            QFlags_QPaintEngine_DirtyFlag__CppToPython_QFlags_QPaintEngine_DirtyFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_DirtyFlag_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_,
            is_QPaintEngine_DirtyFlag_PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QPaintEngine_DirtyFlag__PythonToCpp_QFlags_QPaintEngine_DirtyFlag_,
            is_QFlags_QPaintEngine_DirtyFlag__PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QPaintEngine_DirtyFlag_,
            is_number_PythonToCpp_QFlags_QPaintEngine_DirtyFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QPaintEngine::DirtyFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<DirtyFlag>");
    }
    // End of 'DirtyFlag' enum/flags.

    // Initialization of enum 'PolygonDrawMode'.
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPaintEngine_Type,
        "PolygonDrawMode",
        "PySide.QtGui.QPaintEngine.PolygonDrawMode",
        "QPaintEngine::PolygonDrawMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX],
        &Sbk_QPaintEngine_Type, "OddEvenMode", (long) QPaintEngine::OddEvenMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX],
        &Sbk_QPaintEngine_Type, "WindingMode", (long) QPaintEngine::WindingMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX],
        &Sbk_QPaintEngine_Type, "ConvexMode", (long) QPaintEngine::ConvexMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX],
        &Sbk_QPaintEngine_Type, "PolylineMode", (long) QPaintEngine::PolylineMode))
        return ;
    // Register converter for enum 'QPaintEngine::PolygonDrawMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX],
            QPaintEngine_PolygonDrawMode_CppToPython_QPaintEngine_PolygonDrawMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_PolygonDrawMode_PythonToCpp_QPaintEngine_PolygonDrawMode,
            is_QPaintEngine_PolygonDrawMode_PythonToCpp_QPaintEngine_PolygonDrawMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPaintEngine::PolygonDrawMode");
        Shiboken::Conversions::registerConverterName(converter, "PolygonDrawMode");
    }
    // End of 'PolygonDrawMode' enum.

    // Initialization of enum 'Type'.
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPaintEngine_Type,
        "Type",
        "PySide.QtGui.QPaintEngine.Type",
        "QPaintEngine::Type");
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "X11", (long) QPaintEngine::X11))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Windows", (long) QPaintEngine::Windows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "QuickDraw", (long) QPaintEngine::QuickDraw))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "CoreGraphics", (long) QPaintEngine::CoreGraphics))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "MacPrinter", (long) QPaintEngine::MacPrinter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "QWindowSystem", (long) QPaintEngine::QWindowSystem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "PostScript", (long) QPaintEngine::PostScript))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "OpenGL", (long) QPaintEngine::OpenGL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Picture", (long) QPaintEngine::Picture))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "SVG", (long) QPaintEngine::SVG))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Raster", (long) QPaintEngine::Raster))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Direct3D", (long) QPaintEngine::Direct3D))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Pdf", (long) QPaintEngine::Pdf))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "OpenVG", (long) QPaintEngine::OpenVG))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "OpenGL2", (long) QPaintEngine::OpenGL2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "PaintBuffer", (long) QPaintEngine::PaintBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "Blitter", (long) QPaintEngine::Blitter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "User", (long) QPaintEngine::User))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
        &Sbk_QPaintEngine_Type, "MaxUser", (long) QPaintEngine::MaxUser))
        return ;
    // Register converter for enum 'QPaintEngine::Type'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX],
            QPaintEngine_Type_CppToPython_QPaintEngine_Type);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintEngine_Type_PythonToCpp_QPaintEngine_Type,
            is_QPaintEngine_Type_PythonToCpp_QPaintEngine_Type_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPaintEngine::Type");
        Shiboken::Conversions::registerConverterName(converter, "Type");
    }
    // End of 'Type' enum.


    qRegisterMetaType< ::QPaintEngine::PaintEngineFeature >("QPaintEngine::PaintEngineFeature");
    qRegisterMetaType< ::QPaintEngine::PaintEngineFeatures >("QPaintEngine::PaintEngineFeatures");
    qRegisterMetaType< ::QPaintEngine::DirtyFlag >("QPaintEngine::DirtyFlag");
    qRegisterMetaType< ::QPaintEngine::DirtyFlags >("QPaintEngine::DirtyFlags");
    qRegisterMetaType< ::QPaintEngine::PolygonDrawMode >("QPaintEngine::PolygonDrawMode");
    qRegisterMetaType< ::QPaintEngine::Type >("QPaintEngine::Type");
}
