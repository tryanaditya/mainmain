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

#include "qpaintenginestate_wrapper.h"

// Extra includes
#include <QPainterPath>
#include <qbrush.h>
#include <qfont.h>
#include <qmatrix.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpen.h>
#include <qpoint.h>
#include <qregion.h>
#include <qtransform.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPaintEngineState_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPaintEngineState >()))
        return -1;

    ::QPaintEngineState* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QPaintEngineState()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPaintEngineState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPaintEngineState >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QPaintEngineStateFunc_backgroundBrush(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundBrush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->backgroundBrush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_backgroundMode(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::BGMode cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->backgroundMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_brush(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->brush();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_brushNeedsResolving(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brushNeedsResolving()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->brushNeedsResolving();
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

static PyObject* Sbk_QPaintEngineStateFunc_brushOrigin(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brushOrigin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPointF cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->brushOrigin();
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

static PyObject* Sbk_QPaintEngineStateFunc_clipOperation(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipOperation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ClipOperation cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->clipOperation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_clipPath(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->clipPath();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_clipRegion(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipRegion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegion cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->clipRegion();
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

static PyObject* Sbk_QPaintEngineStateFunc_compositionMode(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // compositionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainter::CompositionMode cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->compositionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_font(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_isClipEnabled(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isClipEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->isClipEnabled();
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

static PyObject* Sbk_QPaintEngineStateFunc_matrix(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // matrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->matrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_opacity(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // opacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->opacity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_painter(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // painter()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainter * cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->painter();
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

static PyObject* Sbk_QPaintEngineStateFunc_pen(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pen()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPen cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->pen();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_penNeedsResolving(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // penNeedsResolving()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->penNeedsResolving();
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

static PyObject* Sbk_QPaintEngineStateFunc_renderHints(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // renderHints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QPainter::RenderHint> cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->renderHints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_state(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QPaintEngine::DirtyFlag> cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintEngineStateFunc_transform(PyObject* self)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QPaintEngineState*>(cppSelf)->transform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPaintEngineState_methods[] = {
    {"backgroundBrush", (PyCFunction)Sbk_QPaintEngineStateFunc_backgroundBrush, METH_NOARGS},
    {"backgroundMode", (PyCFunction)Sbk_QPaintEngineStateFunc_backgroundMode, METH_NOARGS},
    {"brush", (PyCFunction)Sbk_QPaintEngineStateFunc_brush, METH_NOARGS},
    {"brushNeedsResolving", (PyCFunction)Sbk_QPaintEngineStateFunc_brushNeedsResolving, METH_NOARGS},
    {"brushOrigin", (PyCFunction)Sbk_QPaintEngineStateFunc_brushOrigin, METH_NOARGS},
    {"clipOperation", (PyCFunction)Sbk_QPaintEngineStateFunc_clipOperation, METH_NOARGS},
    {"clipPath", (PyCFunction)Sbk_QPaintEngineStateFunc_clipPath, METH_NOARGS},
    {"clipRegion", (PyCFunction)Sbk_QPaintEngineStateFunc_clipRegion, METH_NOARGS},
    {"compositionMode", (PyCFunction)Sbk_QPaintEngineStateFunc_compositionMode, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QPaintEngineStateFunc_font, METH_NOARGS},
    {"isClipEnabled", (PyCFunction)Sbk_QPaintEngineStateFunc_isClipEnabled, METH_NOARGS},
    {"matrix", (PyCFunction)Sbk_QPaintEngineStateFunc_matrix, METH_NOARGS},
    {"opacity", (PyCFunction)Sbk_QPaintEngineStateFunc_opacity, METH_NOARGS},
    {"painter", (PyCFunction)Sbk_QPaintEngineStateFunc_painter, METH_NOARGS},
    {"pen", (PyCFunction)Sbk_QPaintEngineStateFunc_pen, METH_NOARGS},
    {"penNeedsResolving", (PyCFunction)Sbk_QPaintEngineStateFunc_penNeedsResolving, METH_NOARGS},
    {"renderHints", (PyCFunction)Sbk_QPaintEngineStateFunc_renderHints, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QPaintEngineStateFunc_state, METH_NOARGS},
    {"transform", (PyCFunction)Sbk_QPaintEngineStateFunc_transform, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_QPaintEngineState_get_dirtyFlags(PyObject* self, void*)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), &cppSelf->dirtyFlags);
    return pyOut;
}
static int Sbk_QPaintEngineState_set_dirtyFlags(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintEngineState* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintEngineState*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'dirtyFlags' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'dirtyFlags', 'DirtyFlags' or convertible type expected");
        return -1;
    }

    ::QFlags<QPaintEngine::DirtyFlag> cppOut_local = cppSelf->dirtyFlags;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->dirtyFlags = cppOut_local;

    return 0;
}

// Getters and Setters for QPaintEngineState
static PyGetSetDef Sbk_QPaintEngineState_getsetlist[] = {
    {const_cast<char*>("dirtyFlags"), Sbk_QPaintEngineState_get_dirtyFlags, Sbk_QPaintEngineState_set_dirtyFlags},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QPaintEngineState_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPaintEngineState_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPaintEngineState_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPaintEngineState",
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
    /*tp_traverse*/         Sbk_QPaintEngineState_traverse,
    /*tp_clear*/            Sbk_QPaintEngineState_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPaintEngineState_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QPaintEngineState_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPaintEngineState_Init,
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


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPaintEngineState_PythonToCpp_QPaintEngineState_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPaintEngineState_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPaintEngineState_PythonToCpp_QPaintEngineState_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPaintEngineState_Type))
        return QPaintEngineState_PythonToCpp_QPaintEngineState_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPaintEngineState_PTR_CppToPython_QPaintEngineState(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPaintEngineState*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPaintEngineState_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPaintEngineState(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPaintEngineState_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPaintEngineState", "QPaintEngineState*",
        &Sbk_QPaintEngineState_Type, &Shiboken::callCppDestructor< ::QPaintEngineState >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPaintEngineState_Type,
        QPaintEngineState_PythonToCpp_QPaintEngineState_PTR,
        is_QPaintEngineState_PythonToCpp_QPaintEngineState_PTR_Convertible,
        QPaintEngineState_PTR_CppToPython_QPaintEngineState);

    Shiboken::Conversions::registerConverterName(converter, "QPaintEngineState");
    Shiboken::Conversions::registerConverterName(converter, "QPaintEngineState*");
    Shiboken::Conversions::registerConverterName(converter, "QPaintEngineState&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPaintEngineState).name());



}
