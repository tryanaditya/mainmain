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
#include "pyside_phonon_python.h"

#include "phonon_videowidgetinterface_wrapper.h"

// Extra includes
#include <qwidget.h>

using namespace Phonon;

// Native ---------------------------------------------------------

VideoWidgetInterfaceWrapper::VideoWidgetInterfaceWrapper() : Phonon::VideoWidgetInterface() {
    // ... middle
}

Phonon::VideoWidget::AspectRatio VideoWidgetInterfaceWrapper::aspectRatio() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::VideoWidget::AspectRatio)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "aspectRatio"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.aspectRatio()' not implemented.");
        return ((::Phonon::VideoWidget::AspectRatio)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::VideoWidget::AspectRatio)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_ASPECTRATIO_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.aspectRatio", Shiboken::SbkType< Phonon::VideoWidget::AspectRatio >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::VideoWidget::AspectRatio)0);
    }
    ::Phonon::VideoWidget::AspectRatio cppResult = ((::Phonon::VideoWidget::AspectRatio)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qreal VideoWidgetInterfaceWrapper::brightness() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "brightness"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.brightness()' not implemented.");
        return ((qreal)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.brightness", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qreal VideoWidgetInterfaceWrapper::contrast() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "contrast"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.contrast()' not implemented.");
        return ((qreal)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.contrast", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qreal VideoWidgetInterfaceWrapper::hue() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "hue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.hue()' not implemented.");
        return ((qreal)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.hue", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

qreal VideoWidgetInterfaceWrapper::saturation() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "saturation"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.saturation()' not implemented.");
        return ((qreal)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.saturation", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

Phonon::VideoWidget::ScaleMode VideoWidgetInterfaceWrapper::scaleMode() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::Phonon::VideoWidget::ScaleMode)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "scaleMode"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.scaleMode()' not implemented.");
        return ((::Phonon::VideoWidget::ScaleMode)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::Phonon::VideoWidget::ScaleMode)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_SCALEMODE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.scaleMode", Shiboken::SbkType< Phonon::VideoWidget::ScaleMode >()->tp_name, pyResult->ob_type->tp_name);
        return ((::Phonon::VideoWidget::ScaleMode)0);
    }
    ::Phonon::VideoWidget::ScaleMode cppResult = ((::Phonon::VideoWidget::ScaleMode)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void VideoWidgetInterfaceWrapper::setAspectRatio(Phonon::VideoWidget::AspectRatio arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setAspectRatio"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setAspectRatio()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_ASPECTRATIO_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VideoWidgetInterfaceWrapper::setBrightness(qreal arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setBrightness"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setBrightness()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(d)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VideoWidgetInterfaceWrapper::setContrast(qreal arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setContrast"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setContrast()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(d)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VideoWidgetInterfaceWrapper::setHue(qreal arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setHue"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setHue()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(d)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VideoWidgetInterfaceWrapper::setSaturation(qreal arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setSaturation"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setSaturation()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(d)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void VideoWidgetInterfaceWrapper::setScaleMode(Phonon::VideoWidget::ScaleMode arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setScaleMode"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setScaleMode()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_SCALEMODE_IDX]), &arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QWidget * VideoWidgetInterfaceWrapper::widget()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QWidget*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "widget"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.widget()' not implemented.");
        return ((::QWidget*)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VideoWidgetInterface.widget", Shiboken::SbkType< QWidget >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QWidget*)0);
    }
    ::QWidget* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

VideoWidgetInterfaceWrapper::~VideoWidgetInterfaceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_VideoWidgetInterface_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'Phonon::VideoWidgetInterface' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::VideoWidgetInterface >()))
        return -1;

    ::VideoWidgetInterfaceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // VideoWidgetInterface()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::VideoWidgetInterfaceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::VideoWidgetInterface >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_aspectRatio(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // aspectRatio()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.aspectRatio()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::VideoWidget::AspectRatio cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->aspectRatio();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_ASPECTRATIO_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_brightness(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brightness()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.brightness()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->brightness();
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

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_contrast(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contrast()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.contrast()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->contrast();
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

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_hue(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hue()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.hue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->hue();
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

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_saturation(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // saturation()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.saturation()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->saturation();
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

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_scaleMode(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // scaleMode()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.scaleMode()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::VideoWidget::ScaleMode cppResult = const_cast<const ::Phonon::VideoWidgetInterface*>(cppSelf)->scaleMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_SCALEMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setAspectRatio(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAspectRatio(Phonon::VideoWidget::AspectRatio)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_ASPECTRATIO_IDX]), (pyArg)))) {
        overloadId = 0; // setAspectRatio(Phonon::VideoWidget::AspectRatio)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setAspectRatio_TypeError;

    // Call function/method
    {
        ::Phonon::VideoWidget::AspectRatio cppArg0 = ((::Phonon::VideoWidget::AspectRatio)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAspectRatio(Phonon::VideoWidget::AspectRatio)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setAspectRatio()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAspectRatio(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setAspectRatio_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::VideoWidget.AspectRatio", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setAspectRatio", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setBrightness(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBrightness(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setBrightness(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setBrightness_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBrightness(qreal)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setBrightness()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBrightness(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setBrightness_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setBrightness", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setContrast(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContrast(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setContrast(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setContrast_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContrast(qreal)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setContrast()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContrast(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setContrast_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setContrast", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setHue(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHue(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setHue(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setHue_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHue(qreal)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setHue()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHue(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setHue_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setHue", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setSaturation(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSaturation(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setSaturation(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setSaturation_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSaturation(qreal)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setSaturation()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSaturation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setSaturation_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setSaturation", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_setScaleMode(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setScaleMode(Phonon::VideoWidget::ScaleMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGET_SCALEMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setScaleMode(Phonon::VideoWidget::ScaleMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VideoWidgetInterfaceFunc_setScaleMode_TypeError;

    // Call function/method
    {
        ::Phonon::VideoWidget::ScaleMode cppArg0 = ((::Phonon::VideoWidget::ScaleMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScaleMode(Phonon::VideoWidget::ScaleMode)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.setScaleMode()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setScaleMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VideoWidgetInterfaceFunc_setScaleMode_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::VideoWidget.ScaleMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VideoWidgetInterface.setScaleMode", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VideoWidgetInterfaceFunc_widget(PyObject* self)
{
    ::Phonon::VideoWidgetInterface* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VideoWidgetInterface*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widget()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'VideoWidgetInterface.widget()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = cppSelf->widget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_Phonon_VideoWidgetInterface_methods[] = {
    {"aspectRatio", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_aspectRatio, METH_NOARGS},
    {"brightness", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_brightness, METH_NOARGS},
    {"contrast", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_contrast, METH_NOARGS},
    {"hue", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_hue, METH_NOARGS},
    {"saturation", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_saturation, METH_NOARGS},
    {"scaleMode", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_scaleMode, METH_NOARGS},
    {"setAspectRatio", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setAspectRatio, METH_O},
    {"setBrightness", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setBrightness, METH_O},
    {"setContrast", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setContrast, METH_O},
    {"setHue", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setHue, METH_O},
    {"setSaturation", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setSaturation, METH_O},
    {"setScaleMode", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_setScaleMode, METH_O},
    {"widget", (PyCFunction)Sbk_Phonon_VideoWidgetInterfaceFunc_widget, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_VideoWidgetInterface_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_VideoWidgetInterface_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_VideoWidgetInterface_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.VideoWidgetInterface",
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
    /*tp_traverse*/         Sbk_Phonon_VideoWidgetInterface_traverse,
    /*tp_clear*/            Sbk_Phonon_VideoWidgetInterface_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_VideoWidgetInterface_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_VideoWidgetInterface_Init,
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
static void VideoWidgetInterface_PythonToCpp_VideoWidgetInterface_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_VideoWidgetInterface_Type, pyIn, cppOut);
}
static PythonToCppFunc is_VideoWidgetInterface_PythonToCpp_VideoWidgetInterface_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_VideoWidgetInterface_Type))
        return VideoWidgetInterface_PythonToCpp_VideoWidgetInterface_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* VideoWidgetInterface_PTR_CppToPython_VideoWidgetInterface(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Phonon::VideoWidgetInterface*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Phonon_VideoWidgetInterface_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Phonon_VideoWidgetInterface(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_VIDEOWIDGETINTERFACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_VideoWidgetInterface_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "VideoWidgetInterface", "Phonon::VideoWidgetInterface*",
        &Sbk_Phonon_VideoWidgetInterface_Type, &Shiboken::callCppDestructor< ::Phonon::VideoWidgetInterface >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_VideoWidgetInterface_Type,
        VideoWidgetInterface_PythonToCpp_VideoWidgetInterface_PTR,
        is_VideoWidgetInterface_PythonToCpp_VideoWidgetInterface_PTR_Convertible,
        VideoWidgetInterface_PTR_CppToPython_VideoWidgetInterface);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::VideoWidgetInterface");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VideoWidgetInterface*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VideoWidgetInterface&");
    Shiboken::Conversions::registerConverterName(converter, "VideoWidgetInterface");
    Shiboken::Conversions::registerConverterName(converter, "VideoWidgetInterface*");
    Shiboken::Conversions::registerConverterName(converter, "VideoWidgetInterface&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::VideoWidgetInterface).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::VideoWidgetInterfaceWrapper).name());



}
