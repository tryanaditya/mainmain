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

#include "qpicture_wrapper.h"

// Extra includes
#include <qdatastream.h>
#include <qiodevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpicture.h>
#include <qrect.h>


// Native ---------------------------------------------------------

QPictureWrapper::QPictureWrapper(int formatVersion) : QPicture(formatVersion) {
    // ... middle
}

int QPictureWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPicture::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPicture.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPictureWrapper::metric(QPaintDevice::PaintDeviceMetric m) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPicture::metric(m);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &m)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPicture.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QPictureWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPicture::paintEngine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPicture.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPictureWrapper::setData(const char * data, uint size)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPicture::setData(data, size);
    }

    // Begin code injection

    PyObject* data_out = Shiboken::Buffer::newObject(data, size);

    // End of code injection
    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        data_out
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QPictureWrapper::~QPictureWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPicture_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPicture >()))
        return -1;

    ::QPictureWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QPicture", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPicture(QPicture)
    // 1: QPicture(int)
    if (numArgs == 0) {
        overloadId = 1; // QPicture(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 1; // QPicture(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (pyArgs[0])))) {
        overloadId = 0; // QPicture(QPicture)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPicture_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPicture(const QPicture & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPicture cppArg0_local = ::QPicture(((int)0));
            ::QPicture* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPicture(QPicture)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPictureWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPicture(int formatVersion)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "formatVersion");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture(): got multiple values for keyword argument 'formatVersion'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QPicture_Init_TypeError;
                }
            }
            int cppArg0 = -1;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPicture(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPictureWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPicture >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPicture_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPicture_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPicture", "int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPicture", overloads);
        return -1;
}

static PyObject* Sbk_QPictureFunc_boundingRect(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // boundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QPicture*>(cppSelf)->boundingRect();
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

static PyObject* Sbk_QPictureFunc_data(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            // Begin code injection

            pyResult = Shiboken::Buffer::newObject(cppSelf->data(), cppSelf->size());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPictureFunc_devType(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPicture*>(cppSelf)->::QPicture::devType() : const_cast<const ::QPicture*>(cppSelf)->devType();
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

static PyObject* Sbk_QPictureFunc_isNull(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPicture*>(cppSelf)->isNull();
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

static PyObject* Sbk_QPictureFunc_load(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.load(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.load(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:load", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: load(QIODevice*,const char*)
    // 1: load(QString,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // load(QIODevice*,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // load(QIODevice*,const char*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // load(QString,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 1; // load(QString,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_load_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // load(QIODevice * dev, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.load(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPictureFunc_load_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // load(QIODevice*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->load(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // load(const QString & fileName, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.load(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPictureFunc_load_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // load(QString,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->load(cppArg0, cppArg1);
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

    Sbk_QPictureFunc_load_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, " SBK_STR_NAME " = None", "unicode, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPicture.load", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPictureFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPicture*>(cppSelf)->::QPicture::metric(cppArg0) : const_cast<const ::QPicture*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPictureFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.metric", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_paintEngine(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPicture*>(cppSelf)->::QPicture::paintEngine() : const_cast<const ::QPicture*>(cppSelf)->paintEngine();
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

static PyObject* Sbk_QPictureFunc_play(PyObject* self, PyObject* pyArg)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: play(QPainter*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArg)))) {
        overloadId = 0; // play(QPainter*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_play_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainter* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // play(QPainter*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->play(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPictureFunc_play_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.play", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_save(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.save(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.save(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:save", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: save(QIODevice*,const char*)
    // 1: save(QString,const char*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QIODEVICE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // save(QIODevice*,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 0; // save(QIODevice*,const char*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // save(QString,const char*)
        } else if (Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1])))) {
            overloadId = 1; // save(QString,const char*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_save_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // save(QIODevice * dev, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPictureFunc_save_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QIODevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // save(QIODevice*,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->save(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // save(const QString & fileName, const char * format)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "format");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPicture.save(): got multiple values for keyword argument 'format'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!Shiboken::String::check(pyArgs[1]) && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[1]))))
                        goto Sbk_QPictureFunc_save_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            const char* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // save(QString,const char*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->save(cppArg0, cppArg1);
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

    Sbk_QPictureFunc_save_TypeError:
        const char* overloads[] = {"PySide.QtCore.QIODevice, " SBK_STR_NAME " = None", "unicode, " SBK_STR_NAME " = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPicture.save", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_setBoundingRect(PyObject* self, PyObject* pyArg)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBoundingRect(QRect)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // setBoundingRect(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_setBoundingRect_TypeError;

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
            // setBoundingRect(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBoundingRect(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPictureFunc_setBoundingRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.setBoundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_setData(PyObject* self, PyObject* pyArg)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setData(const char*,uint)
    if (Shiboken::Buffer::checkType(pyArg)) {
        overloadId = 0; // setData(const char*,uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_setData_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setData(const char*,uint)
            // Begin code injection

            Py_ssize_t bufferLen;
            char* data_out = (char*) Shiboken::Buffer::getPointer(pyArg, &bufferLen);


            uint size_out = bufferLen;

            // End of code injection
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QPicture::setData(data_out, size_out) : cppSelf->setData(data_out, size_out);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPictureFunc_setData_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME ", unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.setData", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc_size(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // size()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            uint cppResult = const_cast<const ::QPicture*>(cppSelf)->size();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPictureFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QPicture&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (pyArg)))) {
        overloadId = 0; // swap(QPicture&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPicture cppArg0_local = ::QPicture(((int)0));
        ::QPicture* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QPicture&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPictureFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPicture", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.swap", overloads);
        return 0;
}

static PyObject* Sbk_QPicture___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPicture& cppSelf = *(((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPicture_methods[] = {
    {"boundingRect", (PyCFunction)Sbk_QPictureFunc_boundingRect, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QPictureFunc_data, METH_NOARGS},
    {"devType", (PyCFunction)Sbk_QPictureFunc_devType, METH_NOARGS},
    {"isNull", (PyCFunction)Sbk_QPictureFunc_isNull, METH_NOARGS},
    {"load", (PyCFunction)Sbk_QPictureFunc_load, METH_VARARGS|METH_KEYWORDS},
    {"metric", (PyCFunction)Sbk_QPictureFunc_metric, METH_O},
    {"paintEngine", (PyCFunction)Sbk_QPictureFunc_paintEngine, METH_NOARGS},
    {"play", (PyCFunction)Sbk_QPictureFunc_play, METH_O},
    {"save", (PyCFunction)Sbk_QPictureFunc_save, METH_VARARGS|METH_KEYWORDS},
    {"setBoundingRect", (PyCFunction)Sbk_QPictureFunc_setBoundingRect, METH_O},
    {"setData", (PyCFunction)Sbk_QPictureFunc_setData, METH_O},
    {"size", (PyCFunction)Sbk_QPictureFunc_size, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QPictureFunc_swap, METH_O},

    {"__copy__", (PyCFunction)Sbk_QPicture___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QPicture___nb_bool(PyObject* self)
{
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QPictureFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QPicture)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPicture)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPicture) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPictureFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPictureFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPicture* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QPicture&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPicture&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPictureFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPicture&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPictureFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPicture.__rshift__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QPicture_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPicture_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPicture_TypeAsNumber;

static SbkObjectType Sbk_QPicture_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPicture",
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
    /*tp_traverse*/         Sbk_QPicture_traverse,
    /*tp_clear*/            Sbk_QPicture_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPicture_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPicture_Init,
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

static void* Sbk_QPicture_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QPicture*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPicture_PythonToCpp_QPicture_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPicture_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPicture_PythonToCpp_QPicture_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPicture_Type))
        return QPicture_PythonToCpp_QPicture_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPicture_PTR_CppToPython_QPicture(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPicture*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPicture_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPicture_COPY_CppToPython_QPicture(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPicture_Type, new ::QPictureWrapper(*((::QPicture*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPicture_PythonToCpp_QPicture_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPicture*)cppOut) = *((::QPicture*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPicture_PythonToCpp_QPicture_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPicture_Type))
        return QPicture_PythonToCpp_QPicture_COPY;
    return 0;
}

void init_QPicture(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPicture_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPicture_TypeAsNumber.nb_rshift = Sbk_QPictureFunc___rshift__;
    Sbk_QPicture_TypeAsNumber.nb_lshift = Sbk_QPictureFunc___lshift__;
    SBK_NB_BOOL(Sbk_QPicture_TypeAsNumber) = Sbk_QPicture___nb_bool;
    Sbk_QPicture_Type.super.ht_type.tp_as_number = &Sbk_QPicture_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPicture_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPicture", "QPicture",
        &Sbk_QPicture_Type, &Shiboken::callCppDestructor< ::QPictureWrapper >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPicture_Type,
        QPicture_PythonToCpp_QPicture_PTR,
        is_QPicture_PythonToCpp_QPicture_PTR_Convertible,
        QPicture_PTR_CppToPython_QPicture,
        QPicture_COPY_CppToPython_QPicture);

    Shiboken::Conversions::registerConverterName(converter, "QPicture");
    Shiboken::Conversions::registerConverterName(converter, "QPicture*");
    Shiboken::Conversions::registerConverterName(converter, "QPicture&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPicture).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPictureWrapper).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPicture_PythonToCpp_QPicture_COPY,
        is_QPicture_PythonToCpp_QPicture_COPY_Convertible);

    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QPicture_Type, &Sbk_QPicture_typeDiscovery);


}
