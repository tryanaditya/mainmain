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

#include "qprintengine_wrapper.h"

// Extra includes


// Native ---------------------------------------------------------

QPrintEngineWrapper::QPrintEngineWrapper() : QPrintEngine() {
    // ... middle
}

bool QPrintEngineWrapper::abort()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "abort"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.abort()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrintEngine.abort", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPrintEngineWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.metric()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]), &arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrintEngine.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QPrintEngineWrapper::newPage()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "newPage"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.newPage()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrintEngine.newPage", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPrinter::PrinterState QPrintEngineWrapper::printerState() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPrinter::PrinterState)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "printerState"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.printerState()' not implemented.");
        return ((::QPrinter::PrinterState)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QPrinter::PrinterState)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX]), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrintEngine.printerState", Shiboken::SbkType< QPrinter::PrinterState >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPrinter::PrinterState)0);
    }
    ::QPrinter::PrinterState cppResult = ((::QPrinter::PrinterState)0);
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QPrintEngineWrapper::property(QPrintEngine::PrintEnginePropertyKey key) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "property"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.property()' not implemented.");
        return ::QVariant();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX]), &key)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrintEngine.property", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QPrintEngineWrapper::setProperty(QPrintEngine::PrintEnginePropertyKey key, const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setProperty"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.setProperty()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX]), &key),
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QPrintEngineWrapper::~QPrintEngineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPrintEngine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QPrintEngine' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPrintEngine >()))
        return -1;

    ::QPrintEngineWrapper* cptr = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // QPrintEngine()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QPrintEngineWrapper();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPrintEngine >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_QPrintEngineFunc_abort(PyObject* self)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // abort()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.abort()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->abort();
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

static PyObject* Sbk_QPrintEngineFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPrintEngineFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.metric()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrintEngine*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrintEngineFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrintEngine.metric", overloads);
        return 0;
}

static PyObject* Sbk_QPrintEngineFunc_newPage(PyObject* self)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newPage()
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.newPage()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->newPage();
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

static PyObject* Sbk_QPrintEngineFunc_printerState(PyObject* self)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printerState()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.printerState()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PrinterState cppResult = const_cast<const ::QPrintEngine*>(cppSelf)->printerState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrintEngineFunc_property(PyObject* self, PyObject* pyArg)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: property(QPrintEngine::PrintEnginePropertyKey)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX]), (pyArg)))) {
        overloadId = 0; // property(QPrintEngine::PrintEnginePropertyKey)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrintEngineFunc_property_TypeError;

    // Call function/method
    {
        ::QPrintEngine::PrintEnginePropertyKey cppArg0 = ((::QPrintEngine::PrintEnginePropertyKey)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // property(QPrintEngine::PrintEnginePropertyKey)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.property()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QPrintEngine*>(cppSelf)->property(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrintEngineFunc_property_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrintEngine.PrintEnginePropertyKey", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrintEngine.property", overloads);
        return 0;
}

static PyObject* Sbk_QPrintEngineFunc_setProperty(PyObject* self, PyObject* args)
{
    ::QPrintEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrintEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setProperty", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setProperty(QPrintEngine::PrintEnginePropertyKey,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setProperty(QPrintEngine::PrintEnginePropertyKey,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrintEngineFunc_setProperty_TypeError;

    // Call function/method
    {
        ::QPrintEngine::PrintEnginePropertyKey cppArg0 = ((::QPrintEngine::PrintEnginePropertyKey)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setProperty(QPrintEngine::PrintEnginePropertyKey,QVariant)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QPrintEngine.setProperty()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProperty(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrintEngineFunc_setProperty_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrintEngine.PrintEnginePropertyKey, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrintEngine.setProperty", overloads);
        return 0;
}

static PyMethodDef Sbk_QPrintEngine_methods[] = {
    {"abort", (PyCFunction)Sbk_QPrintEngineFunc_abort, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QPrintEngineFunc_metric, METH_O},
    {"newPage", (PyCFunction)Sbk_QPrintEngineFunc_newPage, METH_NOARGS},
    {"printerState", (PyCFunction)Sbk_QPrintEngineFunc_printerState, METH_NOARGS},
    {"property", (PyCFunction)Sbk_QPrintEngineFunc_property, METH_O},
    {"setProperty", (PyCFunction)Sbk_QPrintEngineFunc_setProperty, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QPrintEngine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPrintEngine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPrintEngine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPrintEngine",
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
    /*tp_traverse*/         Sbk_QPrintEngine_traverse,
    /*tp_clear*/            Sbk_QPrintEngine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPrintEngine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPrintEngine_Init,
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
static void QPrintEngine_PrintEnginePropertyKey_PythonToCpp_QPrintEngine_PrintEnginePropertyKey(PyObject* pyIn, void* cppOut) {
    *((::QPrintEngine::PrintEnginePropertyKey*)cppOut) = (::QPrintEngine::PrintEnginePropertyKey) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrintEngine_PrintEnginePropertyKey_PythonToCpp_QPrintEngine_PrintEnginePropertyKey_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX]))
        return QPrintEngine_PrintEnginePropertyKey_PythonToCpp_QPrintEngine_PrintEnginePropertyKey;
    return 0;
}
static PyObject* QPrintEngine_PrintEnginePropertyKey_CppToPython_QPrintEngine_PrintEnginePropertyKey(const void* cppIn) {
    int castCppIn = *((::QPrintEngine::PrintEnginePropertyKey*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPrintEngine_PythonToCpp_QPrintEngine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPrintEngine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPrintEngine_PythonToCpp_QPrintEngine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPrintEngine_Type))
        return QPrintEngine_PythonToCpp_QPrintEngine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPrintEngine_PTR_CppToPython_QPrintEngine(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPrintEngine*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPrintEngine_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPrintEngine(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPrintEngine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPrintEngine", "QPrintEngine*",
        &Sbk_QPrintEngine_Type, &Shiboken::callCppDestructor< ::QPrintEngine >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPrintEngine_Type,
        QPrintEngine_PythonToCpp_QPrintEngine_PTR,
        is_QPrintEngine_PythonToCpp_QPrintEngine_PTR_Convertible,
        QPrintEngine_PTR_CppToPython_QPrintEngine);

    Shiboken::Conversions::registerConverterName(converter, "QPrintEngine");
    Shiboken::Conversions::registerConverterName(converter, "QPrintEngine*");
    Shiboken::Conversions::registerConverterName(converter, "QPrintEngine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPrintEngine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPrintEngineWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'PrintEnginePropertyKey'.
    SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrintEngine_Type,
        "PrintEnginePropertyKey",
        "PySide.QtGui.QPrintEngine.PrintEnginePropertyKey",
        "QPrintEngine::PrintEnginePropertyKey");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_CollateCopies", (long) QPrintEngine::PPK_CollateCopies))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_ColorMode", (long) QPrintEngine::PPK_ColorMode))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_Creator", (long) QPrintEngine::PPK_Creator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_DocumentName", (long) QPrintEngine::PPK_DocumentName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_FullPage", (long) QPrintEngine::PPK_FullPage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_NumberOfCopies", (long) QPrintEngine::PPK_NumberOfCopies))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_Orientation", (long) QPrintEngine::PPK_Orientation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_OutputFileName", (long) QPrintEngine::PPK_OutputFileName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PageOrder", (long) QPrintEngine::PPK_PageOrder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PageRect", (long) QPrintEngine::PPK_PageRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PageSize", (long) QPrintEngine::PPK_PageSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PaperRect", (long) QPrintEngine::PPK_PaperRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PaperSource", (long) QPrintEngine::PPK_PaperSource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PrinterName", (long) QPrintEngine::PPK_PrinterName))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PrinterProgram", (long) QPrintEngine::PPK_PrinterProgram))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_Resolution", (long) QPrintEngine::PPK_Resolution))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_SelectionOption", (long) QPrintEngine::PPK_SelectionOption))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_SupportedResolutions", (long) QPrintEngine::PPK_SupportedResolutions))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_WindowsPageSize", (long) QPrintEngine::PPK_WindowsPageSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_FontEmbedding", (long) QPrintEngine::PPK_FontEmbedding))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_SuppressSystemPrintStatus", (long) QPrintEngine::PPK_SuppressSystemPrintStatus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_Duplex", (long) QPrintEngine::PPK_Duplex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PaperSources", (long) QPrintEngine::PPK_PaperSources))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_CustomPaperSize", (long) QPrintEngine::PPK_CustomPaperSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PageMargins", (long) QPrintEngine::PPK_PageMargins))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_CopyCount", (long) QPrintEngine::PPK_CopyCount))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_SupportsMultipleCopies", (long) QPrintEngine::PPK_SupportsMultipleCopies))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_PaperSize", (long) QPrintEngine::PPK_PaperSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
        &Sbk_QPrintEngine_Type, "PPK_CustomBase", (long) QPrintEngine::PPK_CustomBase))
        return ;
    // Register converter for enum 'QPrintEngine::PrintEnginePropertyKey'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX],
            QPrintEngine_PrintEnginePropertyKey_CppToPython_QPrintEngine_PrintEnginePropertyKey);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrintEngine_PrintEnginePropertyKey_PythonToCpp_QPrintEngine_PrintEnginePropertyKey,
            is_QPrintEngine_PrintEnginePropertyKey_PythonToCpp_QPrintEngine_PrintEnginePropertyKey_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_PRINTENGINEPROPERTYKEY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrintEngine::PrintEnginePropertyKey");
        Shiboken::Conversions::registerConverterName(converter, "PrintEnginePropertyKey");
    }
    // End of 'PrintEnginePropertyKey' enum.


    qRegisterMetaType< ::QPrintEngine::PrintEnginePropertyKey >("QPrintEngine::PrintEnginePropertyKey");
}
