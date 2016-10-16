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

#include "qpaintdevice_wrapper.h"

// Extra includes
#include <qpaintdevice.h>
#include <qpaintengine.h>


// Native ---------------------------------------------------------

QPaintDeviceWrapper::QPaintDeviceWrapper() : QPaintDevice() {
    // ... middle
}

int QPaintDeviceWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintDevice::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintDevice.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPaintDeviceWrapper::metric(QPaintDevice::PaintDeviceMetric metric) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPaintDevice::metric(metric);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &metric)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintDevice.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QPaintDeviceWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintDevice.paintEngine()' not implemented.");
        return ((::QPaintEngine*)0);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPaintDevice.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintDeviceWrapper::~QPaintDeviceWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPaintDevice_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QPaintDevice' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPaintDevice >()))
        return -1;

    ::QPaintDeviceWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QPaintDevice()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPaintDeviceWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPaintDevice >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QPaintDeviceFunc_colorCount(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->colorCount();
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

static PyObject* Sbk_QPaintDeviceFunc_depth(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->depth();
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

static PyObject* Sbk_QPaintDeviceFunc_devType(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPaintDevice*>(cppSelf)->::QPaintDevice::devType() : const_cast<const ::QPaintDevice*>(cppSelf)->devType();
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

static PyObject* Sbk_QPaintDeviceFunc_height(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->height();
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

static PyObject* Sbk_QPaintDeviceFunc_heightMM(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // heightMM()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->heightMM();
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

static PyObject* Sbk_QPaintDeviceFunc_logicalDpiX(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // logicalDpiX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->logicalDpiX();
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

static PyObject* Sbk_QPaintDeviceFunc_logicalDpiY(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // logicalDpiY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->logicalDpiY();
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

static PyObject* Sbk_QPaintDeviceFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: metric(QPaintDevice::PaintDeviceMetric)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), (pyArg)))) {
        overloadId = 0; // metric(QPaintDevice::PaintDeviceMetric)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaintDeviceFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPaintDevice*>(cppSelf)->::QPaintDevice::metric(cppArg0) : const_cast<const ::QPaintDevice*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaintDeviceFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPaintDevice.metric", overloads);
        return 0;
}

static PyObject* Sbk_QPaintDeviceFunc_numColors(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numColors()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->numColors();
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

static PyObject* Sbk_QPaintDeviceFunc_paintEngine(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPaintDevice.paintEngine()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->paintEngine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaintDeviceFunc_paintingActive(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintingActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->paintingActive();
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

static PyObject* Sbk_QPaintDeviceFunc_physicalDpiX(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // physicalDpiX()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->physicalDpiX();
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

static PyObject* Sbk_QPaintDeviceFunc_physicalDpiY(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // physicalDpiY()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->physicalDpiY();
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

static PyObject* Sbk_QPaintDeviceFunc_width(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->width();
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

static PyObject* Sbk_QPaintDeviceFunc_widthMM(PyObject* self)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widthMM()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPaintDevice*>(cppSelf)->widthMM();
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

static PyMethodDef Sbk_QPaintDevice_methods[] = {
    {"colorCount", (PyCFunction)Sbk_QPaintDeviceFunc_colorCount, METH_NOARGS},
    {"depth", (PyCFunction)Sbk_QPaintDeviceFunc_depth, METH_NOARGS},
    {"devType", (PyCFunction)Sbk_QPaintDeviceFunc_devType, METH_NOARGS},
    {"height", (PyCFunction)Sbk_QPaintDeviceFunc_height, METH_NOARGS},
    {"heightMM", (PyCFunction)Sbk_QPaintDeviceFunc_heightMM, METH_NOARGS},
    {"logicalDpiX", (PyCFunction)Sbk_QPaintDeviceFunc_logicalDpiX, METH_NOARGS},
    {"logicalDpiY", (PyCFunction)Sbk_QPaintDeviceFunc_logicalDpiY, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QPaintDeviceFunc_metric, METH_O},
    {"numColors", (PyCFunction)Sbk_QPaintDeviceFunc_numColors, METH_NOARGS},
    {"paintEngine", (PyCFunction)Sbk_QPaintDeviceFunc_paintEngine, METH_NOARGS},
    {"paintingActive", (PyCFunction)Sbk_QPaintDeviceFunc_paintingActive, METH_NOARGS},
    {"physicalDpiX", (PyCFunction)Sbk_QPaintDeviceFunc_physicalDpiX, METH_NOARGS},
    {"physicalDpiY", (PyCFunction)Sbk_QPaintDeviceFunc_physicalDpiY, METH_NOARGS},
    {"width", (PyCFunction)Sbk_QPaintDeviceFunc_width, METH_NOARGS},
    {"widthMM", (PyCFunction)Sbk_QPaintDeviceFunc_widthMM, METH_NOARGS},

    {0} // Sentinel
};

static PyObject* Sbk_QPaintDevice_get_painters(PyObject* self, void*)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    ushort cppOut_local = cppSelf->painters;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QPaintDevice_set_painters(PyObject* self, PyObject* pyIn, void*)
{
    ::QPaintDevice* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPaintDevice*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'painters' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<ushort>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'painters', 'ushort' or convertible type expected");
        return -1;
    }

    ushort cppOut_local = cppSelf->painters;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->painters = cppOut_local;

    return 0;
}

// Getters and Setters for QPaintDevice
static PyGetSetDef Sbk_QPaintDevice_getsetlist[] = {
    {const_cast<char*>("painters"), Sbk_QPaintDevice_get_painters, Sbk_QPaintDevice_set_painters},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QPaintDevice_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPaintDevice_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPaintDevice_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPaintDevice",
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
    /*tp_traverse*/         Sbk_QPaintDevice_traverse,
    /*tp_clear*/            Sbk_QPaintDevice_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPaintDevice_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QPaintDevice_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPaintDevice_Init,
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

// Python to C++ enum conversion.
static void QPaintDevice_PaintDeviceMetric_PythonToCpp_QPaintDevice_PaintDeviceMetric(PyObject* pyIn, void* cppOut) {
    *((::QPaintDevice::PaintDeviceMetric*)cppOut) = (::QPaintDevice::PaintDeviceMetric) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPaintDevice_PaintDeviceMetric_PythonToCpp_QPaintDevice_PaintDeviceMetric_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]))
        return QPaintDevice_PaintDeviceMetric_PythonToCpp_QPaintDevice_PaintDeviceMetric;
    return 0;
}
static PyObject* QPaintDevice_PaintDeviceMetric_CppToPython_QPaintDevice_PaintDeviceMetric(const void* cppIn) {
    int castCppIn = *((::QPaintDevice::PaintDeviceMetric*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPaintDevice_PythonToCpp_QPaintDevice_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPaintDevice_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPaintDevice_PythonToCpp_QPaintDevice_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPaintDevice_Type))
        return QPaintDevice_PythonToCpp_QPaintDevice_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPaintDevice_PTR_CppToPython_QPaintDevice(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPaintDevice*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPaintDevice_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPaintDevice(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPaintDevice_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPaintDevice", "QPaintDevice*",
        &Sbk_QPaintDevice_Type, &Shiboken::callCppDestructor< ::QPaintDevice >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPaintDevice_Type,
        QPaintDevice_PythonToCpp_QPaintDevice_PTR,
        is_QPaintDevice_PythonToCpp_QPaintDevice_PTR_Convertible,
        QPaintDevice_PTR_CppToPython_QPaintDevice);

    Shiboken::Conversions::registerConverterName(converter, "QPaintDevice");
    Shiboken::Conversions::registerConverterName(converter, "QPaintDevice*");
    Shiboken::Conversions::registerConverterName(converter, "QPaintDevice&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPaintDevice).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPaintDeviceWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'PaintDeviceMetric'.
    SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPaintDevice_Type,
        "PaintDeviceMetric",
        "PySide.QtGui.QPaintDevice.PaintDeviceMetric",
        "QPaintDevice::PaintDeviceMetric");
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmWidth", (long) QPaintDevice::PdmWidth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmHeight", (long) QPaintDevice::PdmHeight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmWidthMM", (long) QPaintDevice::PdmWidthMM))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmHeightMM", (long) QPaintDevice::PdmHeightMM))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmNumColors", (long) QPaintDevice::PdmNumColors))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmDepth", (long) QPaintDevice::PdmDepth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmDpiX", (long) QPaintDevice::PdmDpiX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmDpiY", (long) QPaintDevice::PdmDpiY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmPhysicalDpiX", (long) QPaintDevice::PdmPhysicalDpiX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
        &Sbk_QPaintDevice_Type, "PdmPhysicalDpiY", (long) QPaintDevice::PdmPhysicalDpiY))
        return ;
    // Register converter for enum 'QPaintDevice::PaintDeviceMetric'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX],
            QPaintDevice_PaintDeviceMetric_CppToPython_QPaintDevice_PaintDeviceMetric);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPaintDevice_PaintDeviceMetric_PythonToCpp_QPaintDevice_PaintDeviceMetric,
            is_QPaintDevice_PaintDeviceMetric_PythonToCpp_QPaintDevice_PaintDeviceMetric_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPaintDevice::PaintDeviceMetric");
        Shiboken::Conversions::registerConverterName(converter, "PaintDeviceMetric");
    }
    // End of 'PaintDeviceMetric' enum.


    qRegisterMetaType< ::QPaintDevice::PaintDeviceMetric >("QPaintDevice::PaintDeviceMetric");
}
