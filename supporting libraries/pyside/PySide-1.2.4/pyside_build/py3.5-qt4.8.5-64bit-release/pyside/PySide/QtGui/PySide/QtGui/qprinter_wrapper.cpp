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

#include "qprinter_wrapper.h"

// Extra includes
#include <QList>
#include <QPrinterInfo>
#include <qpaintengine.h>
#include <qprintengine.h>
#include <qprinter.h>
#include <qprinterinfo.h>
#include <qrect.h>
#include <qsize.h>


// Native ---------------------------------------------------------

QPrinterWrapper::QPrinterWrapper(QPrinter::PrinterMode mode) : QPrinter(mode) {
    // ... middle
}

QPrinterWrapper::QPrinterWrapper(const QPrinterInfo & printer, QPrinter::PrinterMode mode) : QPrinter(printer, mode) {
    // ... middle
}

int QPrinterWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPrinter::devType();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrinter.devType", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

int QPrinterWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPrinter::metric(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrinter.metric", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPaintEngine * QPrinterWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QPaintEngine*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QPrinter::paintEngine();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QPrinter.paintEngine", Shiboken::SbkType< QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QPaintEngine*)0);
    }
    ::QPaintEngine* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QPrinterWrapper::~QPrinterWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPrinter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPrinter >()))
        return -1;

    ::QPrinterWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPrinter(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QPrinter", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QPrinter(QPrinter::PrinterMode)
    // 1: QPrinter(QPrinterInfo,QPrinter::PrinterMode)
    if (numArgs == 0) {
        overloadId = 0; // QPrinter(QPrinter::PrinterMode)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QPrinter(QPrinterInfo,QPrinter::PrinterMode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // QPrinter(QPrinterInfo,QPrinter::PrinterMode)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // QPrinter(QPrinter::PrinterMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPrinter(QPrinter::PrinterMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPrinter(): got multiple values for keyword argument 'mode'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX]), (pyArgs[0]))))
                        goto Sbk_QPrinter_Init_TypeError;
                }
            }
            ::QPrinter::PrinterMode cppArg0 = QPrinter::ScreenResolution;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPrinter(QPrinter::PrinterMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPrinterWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPrinter(const QPrinterInfo & printer, QPrinter::PrinterMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPrinter(): got multiple values for keyword argument 'mode'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPrinter_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPrinterInfo cppArg0_local = ::QPrinterInfo();
            ::QPrinterInfo* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTERINFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QPrinter::PrinterMode cppArg1 = QPrinter::ScreenResolution;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QPrinter(QPrinterInfo,QPrinter::PrinterMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPrinterWrapper(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPrinter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPrinter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPrinter_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PrinterMode = ScreenResolution", "PySide.QtGui.QPrinterInfo, PySide.QtGui.QPrinter.PrinterMode = ScreenResolution", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter", overloads);
        return -1;
}

static PyObject* Sbk_QPrinterFunc_abort(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // abort()
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

static PyObject* Sbk_QPrinterFunc_actualNumCopies(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // actualNumCopies()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->actualNumCopies();
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

static PyObject* Sbk_QPrinterFunc_collateCopies(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // collateCopies()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->collateCopies();
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

static PyObject* Sbk_QPrinterFunc_colorMode(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colorMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::ColorMode cppResult = const_cast<const ::QPrinter*>(cppSelf)->colorMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_copyCount(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // copyCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->copyCount();
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

static PyObject* Sbk_QPrinterFunc_creator(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // creator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinter*>(cppSelf)->creator();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_devType(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // devType()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPrinter*>(cppSelf)->::QPrinter::devType() : const_cast<const ::QPrinter*>(cppSelf)->devType();
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

static PyObject* Sbk_QPrinterFunc_docName(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // docName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinter*>(cppSelf)->docName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_doubleSidedPrinting(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // doubleSidedPrinting()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->doubleSidedPrinting();
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

static PyObject* Sbk_QPrinterFunc_duplex(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // duplex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::DuplexMode cppResult = const_cast<const ::QPrinter*>(cppSelf)->duplex();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_fontEmbeddingEnabled(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontEmbeddingEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->fontEmbeddingEnabled();
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

static PyObject* Sbk_QPrinterFunc_fromPage(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fromPage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->fromPage();
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

static PyObject* Sbk_QPrinterFunc_fullPage(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fullPage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->fullPage();
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

static PyObject* Sbk_QPrinterFunc_getPageMargins(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getPageMargins(qreal*,qreal*,qreal*,qreal*,QPrinter::Unit)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArg)))) {
        overloadId = 0; // getPageMargins(qreal*,qreal*,qreal*,qreal*,QPrinter::Unit)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_getPageMargins_TypeError;

    // Call function/method
    {
        ::QPrinter::Unit cppArg0 = ((::QPrinter::Unit)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getPageMargins(qreal*,qreal*,qreal*,qreal*,QPrinter::Unit)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number*,args - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QPrinter::getPageMargins(&a, &b, &c, &d, cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number*,args - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrinterFunc_getPageMargins_TypeError:
        const char* overloads[] = {"PySide.QtCore.qreal, PySide.QtCore.qreal, PySide.QtCore.qreal, PySide.QtCore.qreal, PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.getPageMargins", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_isValid(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isValid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->isValid();
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

static PyObject* Sbk_QPrinterFunc_metric(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QPrinterFunc_metric_TypeError;

    // Call function/method
    {
        ::QPaintDevice::PaintDeviceMetric cppArg0 = ((::QPaintDevice::PaintDeviceMetric)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // metric(QPaintDevice::PaintDeviceMetric)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPrinter*>(cppSelf)->::QPrinter::metric(cppArg0) : const_cast<const ::QPrinter*>(cppSelf)->metric(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrinterFunc_metric_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice.PaintDeviceMetric", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.metric", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_newPage(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newPage()
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

static PyObject* Sbk_QPrinterFunc_numCopies(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // numCopies()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->numCopies();
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

static PyObject* Sbk_QPrinterFunc_orientation(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // orientation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::Orientation cppResult = const_cast<const ::QPrinter*>(cppSelf)->orientation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_outputFileName(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // outputFileName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinter*>(cppSelf)->outputFileName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_outputFormat(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // outputFormat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::OutputFormat cppResult = const_cast<const ::QPrinter*>(cppSelf)->outputFormat();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_pageOrder(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageOrder()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PageOrder cppResult = const_cast<const ::QPrinter*>(cppSelf)->pageOrder();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_pageRect(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "pageRect", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: pageRect()const
    // 1: pageRect(QPrinter::Unit)const
    if (numArgs == 0) {
        overloadId = 0; // pageRect()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArgs[0])))) {
        overloadId = 1; // pageRect(QPrinter::Unit)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_pageRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // pageRect() const
        {

            if (!PyErr_Occurred()) {
                // pageRect()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QPrinter*>(cppSelf)->pageRect();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 1: // pageRect(QPrinter::Unit arg__1) const
        {
            ::QPrinter::Unit cppArg0 = ((::QPrinter::Unit)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // pageRect(QPrinter::Unit)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QPrinter*>(cppSelf)->pageRect(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrinterFunc_pageRect_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.pageRect", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_pageSize(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pageSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PageSize cppResult = const_cast<const ::QPrinter*>(cppSelf)->pageSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_paintEngine(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QPrinter*>(cppSelf)->::QPrinter::paintEngine() : const_cast<const ::QPrinter*>(cppSelf)->paintEngine();
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

static PyObject* Sbk_QPrinterFunc_paperRect(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "paperRect", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: paperRect()const
    // 1: paperRect(QPrinter::Unit)const
    if (numArgs == 0) {
        overloadId = 0; // paperRect()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArgs[0])))) {
        overloadId = 1; // paperRect(QPrinter::Unit)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_paperRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // paperRect() const
        {

            if (!PyErr_Occurred()) {
                // paperRect()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = const_cast<const ::QPrinter*>(cppSelf)->paperRect();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 1: // paperRect(QPrinter::Unit arg__1) const
        {
            ::QPrinter::Unit cppArg0 = ((::QPrinter::Unit)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // paperRect(QPrinter::Unit)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = const_cast<const ::QPrinter*>(cppSelf)->paperRect(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrinterFunc_paperRect_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.paperRect", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_paperSize(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "paperSize", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: paperSize()const
    // 1: paperSize(QPrinter::Unit)const
    if (numArgs == 0) {
        overloadId = 0; // paperSize()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArgs[0])))) {
        overloadId = 1; // paperSize(QPrinter::Unit)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_paperSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // paperSize() const
        {

            if (!PyErr_Occurred()) {
                // paperSize()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPrinter::PageSize cppResult = const_cast<const ::QPrinter*>(cppSelf)->paperSize();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), &cppResult);
            }
            break;
        }
        case 1: // paperSize(QPrinter::Unit unit) const
        {
            ::QPrinter::Unit cppArg0 = ((::QPrinter::Unit)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // paperSize(QPrinter::Unit)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QSizeF cppResult = const_cast<const ::QPrinter*>(cppSelf)->paperSize(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPrinterFunc_paperSize_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.paperSize", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_paperSource(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paperSource()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PaperSource cppResult = const_cast<const ::QPrinter*>(cppSelf)->paperSource();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_printEngine(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrintEngine * cppResult = const_cast<const ::QPrinter*>(cppSelf)->printEngine();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_printProgram(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printProgram()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinter*>(cppSelf)->printProgram();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_printRange(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printRange()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PrintRange cppResult = const_cast<const ::QPrinter*>(cppSelf)->printRange();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_printerName(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printerName()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QPrinter*>(cppSelf)->printerName();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_printerState(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // printerState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPrinter::PrinterState cppResult = const_cast<const ::QPrinter*>(cppSelf)->printerState();
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

static PyObject* Sbk_QPrinterFunc_resolution(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resolution()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->resolution();
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

static PyObject* Sbk_QPrinterFunc_setCollateCopies(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCollateCopies(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCollateCopies(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setCollateCopies_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCollateCopies(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCollateCopies(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setCollateCopies_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setCollateCopies", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setColorMode(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColorMode(QPrinter::ColorMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setColorMode(QPrinter::ColorMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setColorMode_TypeError;

    // Call function/method
    {
        ::QPrinter::ColorMode cppArg0 = ((::QPrinter::ColorMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColorMode(QPrinter::ColorMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColorMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setColorMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.ColorMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setColorMode", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setCopyCount(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCopyCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCopyCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setCopyCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCopyCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCopyCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setCopyCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setCopyCount", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setCreator(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCreator(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setCreator(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setCreator_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCreator(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCreator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setCreator_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setCreator", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setDocName(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDocName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDocName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setDocName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDocName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDocName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setDocName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setDocName", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setDoubleSidedPrinting(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDoubleSidedPrinting(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDoubleSidedPrinting(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setDoubleSidedPrinting_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDoubleSidedPrinting(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDoubleSidedPrinting(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setDoubleSidedPrinting_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setDoubleSidedPrinting", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setDuplex(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDuplex(QPrinter::DuplexMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setDuplex(QPrinter::DuplexMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setDuplex_TypeError;

    // Call function/method
    {
        ::QPrinter::DuplexMode cppArg0 = ((::QPrinter::DuplexMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDuplex(QPrinter::DuplexMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDuplex(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setDuplex_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.DuplexMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setDuplex", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setEngines(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setEngines", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setEngines(QPrintEngine*,QPaintEngine*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPRINTENGINE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTENGINE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setEngines(QPrintEngine*,QPaintEngine*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setEngines_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPrintEngine* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPaintEngine* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setEngines(QPrintEngine*,QPaintEngine*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEngines(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[0]);
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setEngines_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrintEngine, PySide.QtGui.QPaintEngine", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.setEngines", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setFontEmbeddingEnabled(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFontEmbeddingEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFontEmbeddingEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setFontEmbeddingEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFontEmbeddingEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFontEmbeddingEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setFontEmbeddingEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setFontEmbeddingEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setFromTo(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFromTo", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFromTo(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setFromTo(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setFromTo_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFromTo(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFromTo(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setFromTo_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.setFromTo", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setFullPage(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFullPage(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFullPage(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setFullPage_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFullPage(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFullPage(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setFullPage_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setFullPage", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setNumCopies(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNumCopies(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setNumCopies(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setNumCopies_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNumCopies(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNumCopies(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setNumCopies_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setNumCopies", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setOrientation(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOrientation(QPrinter::Orientation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX]), (pyArg)))) {
        overloadId = 0; // setOrientation(QPrinter::Orientation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setOrientation_TypeError;

    // Call function/method
    {
        ::QPrinter::Orientation cppArg0 = ((::QPrinter::Orientation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOrientation(QPrinter::Orientation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOrientation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setOrientation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.Orientation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setOrientation", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setOutputFileName(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOutputFileName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOutputFileName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setOutputFileName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOutputFileName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOutputFileName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setOutputFileName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setOutputFileName", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setOutputFormat(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOutputFormat(QPrinter::OutputFormat)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX]), (pyArg)))) {
        overloadId = 0; // setOutputFormat(QPrinter::OutputFormat)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setOutputFormat_TypeError;

    // Call function/method
    {
        ::QPrinter::OutputFormat cppArg0 = ((::QPrinter::OutputFormat)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOutputFormat(QPrinter::OutputFormat)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOutputFormat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setOutputFormat_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.OutputFormat", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setOutputFormat", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPageMargins(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPageMargins", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setPageMargins(qreal,qreal,qreal,qreal,QPrinter::Unit)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArgs[4])))) {
        overloadId = 0; // setPageMargins(qreal,qreal,qreal,qreal,QPrinter::Unit)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPageMargins_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QPrinter::Unit cppArg4 = ((::QPrinter::Unit)0);
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // setPageMargins(qreal,qreal,qreal,qreal,QPrinter::Unit)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPageMargins(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPageMargins_TypeError:
        const char* overloads[] = {"float, float, float, float, PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.setPageMargins", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPageOrder(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPageOrder(QPrinter::PageOrder)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX]), (pyArg)))) {
        overloadId = 0; // setPageOrder(QPrinter::PageOrder)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPageOrder_TypeError;

    // Call function/method
    {
        ::QPrinter::PageOrder cppArg0 = ((::QPrinter::PageOrder)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPageOrder(QPrinter::PageOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPageOrder(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPageOrder_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PageOrder", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPageOrder", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPageSize(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPageSize(QPrinter::PageSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), (pyArg)))) {
        overloadId = 0; // setPageSize(QPrinter::PageSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPageSize_TypeError;

    // Call function/method
    {
        ::QPrinter::PageSize cppArg0 = ((::QPrinter::PageSize)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPageSize(QPrinter::PageSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPageSize(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPageSize_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PageSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPageSize", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPaperSize(PyObject* self, PyObject* args)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPaperSize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPaperSize(QPrinter::PageSize)
    // 1: setPaperSize(QSizeF,QPrinter::Unit)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]), (pyArgs[1])))) {
        overloadId = 1; // setPaperSize(QSizeF,QPrinter::Unit)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // setPaperSize(QPrinter::PageSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPaperSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPaperSize(QPrinter::PageSize arg__1)
        {
            ::QPrinter::PageSize cppArg0 = ((::QPrinter::PageSize)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // setPaperSize(QPrinter::PageSize)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPaperSize(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPaperSize(const QSizeF & paperSize, QPrinter::Unit unit)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QPrinter::Unit cppArg1 = ((::QPrinter::Unit)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPaperSize(QSizeF,QPrinter::Unit)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPaperSize(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPaperSize_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PageSize", "PySide.QtCore.QSizeF, PySide.QtGui.QPrinter.Unit", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPrinter.setPaperSize", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPaperSource(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPaperSource(QPrinter::PaperSource)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX]), (pyArg)))) {
        overloadId = 0; // setPaperSource(QPrinter::PaperSource)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPaperSource_TypeError;

    // Call function/method
    {
        ::QPrinter::PaperSource cppArg0 = ((::QPrinter::PaperSource)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPaperSource(QPrinter::PaperSource)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPaperSource(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPaperSource_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PaperSource", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPaperSource", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPrintProgram(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrintProgram(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPrintProgram(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPrintProgram_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrintProgram(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrintProgram(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPrintProgram_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPrintProgram", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPrintRange(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrintRange(QPrinter::PrintRange)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX]), (pyArg)))) {
        overloadId = 0; // setPrintRange(QPrinter::PrintRange)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPrintRange_TypeError;

    // Call function/method
    {
        ::QPrinter::PrintRange cppArg0 = ((::QPrinter::PrintRange)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrintRange(QPrinter::PrintRange)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrintRange(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPrintRange_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPrinter.PrintRange", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPrintRange", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setPrinterName(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPrinterName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setPrinterName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setPrinterName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPrinterName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPrinterName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setPrinterName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setPrinterName", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_setResolution(PyObject* self, PyObject* pyArg)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setResolution(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setResolution(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPrinterFunc_setResolution_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setResolution(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setResolution(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPrinterFunc_setResolution_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPrinter.setResolution", overloads);
        return 0;
}

static PyObject* Sbk_QPrinterFunc_supportedResolutions(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportedResolutions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<int > cppResult = const_cast<const ::QPrinter*>(cppSelf)->supportedResolutions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_INT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPrinterFunc_supportsMultipleCopies(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsMultipleCopies()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPrinter*>(cppSelf)->supportsMultipleCopies();
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

static PyObject* Sbk_QPrinterFunc_toPage(PyObject* self)
{
    ::QPrinter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPrinter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toPage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPrinter*>(cppSelf)->toPage();
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

static PyMethodDef Sbk_QPrinter_methods[] = {
    {"abort", (PyCFunction)Sbk_QPrinterFunc_abort, METH_NOARGS},
    {"actualNumCopies", (PyCFunction)Sbk_QPrinterFunc_actualNumCopies, METH_NOARGS},
    {"collateCopies", (PyCFunction)Sbk_QPrinterFunc_collateCopies, METH_NOARGS},
    {"colorMode", (PyCFunction)Sbk_QPrinterFunc_colorMode, METH_NOARGS},
    {"copyCount", (PyCFunction)Sbk_QPrinterFunc_copyCount, METH_NOARGS},
    {"creator", (PyCFunction)Sbk_QPrinterFunc_creator, METH_NOARGS},
    {"devType", (PyCFunction)Sbk_QPrinterFunc_devType, METH_NOARGS},
    {"docName", (PyCFunction)Sbk_QPrinterFunc_docName, METH_NOARGS},
    {"doubleSidedPrinting", (PyCFunction)Sbk_QPrinterFunc_doubleSidedPrinting, METH_NOARGS},
    {"duplex", (PyCFunction)Sbk_QPrinterFunc_duplex, METH_NOARGS},
    {"fontEmbeddingEnabled", (PyCFunction)Sbk_QPrinterFunc_fontEmbeddingEnabled, METH_NOARGS},
    {"fromPage", (PyCFunction)Sbk_QPrinterFunc_fromPage, METH_NOARGS},
    {"fullPage", (PyCFunction)Sbk_QPrinterFunc_fullPage, METH_NOARGS},
    {"getPageMargins", (PyCFunction)Sbk_QPrinterFunc_getPageMargins, METH_O},
    {"isValid", (PyCFunction)Sbk_QPrinterFunc_isValid, METH_NOARGS},
    {"metric", (PyCFunction)Sbk_QPrinterFunc_metric, METH_O},
    {"newPage", (PyCFunction)Sbk_QPrinterFunc_newPage, METH_NOARGS},
    {"numCopies", (PyCFunction)Sbk_QPrinterFunc_numCopies, METH_NOARGS},
    {"orientation", (PyCFunction)Sbk_QPrinterFunc_orientation, METH_NOARGS},
    {"outputFileName", (PyCFunction)Sbk_QPrinterFunc_outputFileName, METH_NOARGS},
    {"outputFormat", (PyCFunction)Sbk_QPrinterFunc_outputFormat, METH_NOARGS},
    {"pageOrder", (PyCFunction)Sbk_QPrinterFunc_pageOrder, METH_NOARGS},
    {"pageRect", (PyCFunction)Sbk_QPrinterFunc_pageRect, METH_VARARGS},
    {"pageSize", (PyCFunction)Sbk_QPrinterFunc_pageSize, METH_NOARGS},
    {"paintEngine", (PyCFunction)Sbk_QPrinterFunc_paintEngine, METH_NOARGS},
    {"paperRect", (PyCFunction)Sbk_QPrinterFunc_paperRect, METH_VARARGS},
    {"paperSize", (PyCFunction)Sbk_QPrinterFunc_paperSize, METH_VARARGS},
    {"paperSource", (PyCFunction)Sbk_QPrinterFunc_paperSource, METH_NOARGS},
    {"printEngine", (PyCFunction)Sbk_QPrinterFunc_printEngine, METH_NOARGS},
    {"printProgram", (PyCFunction)Sbk_QPrinterFunc_printProgram, METH_NOARGS},
    {"printRange", (PyCFunction)Sbk_QPrinterFunc_printRange, METH_NOARGS},
    {"printerName", (PyCFunction)Sbk_QPrinterFunc_printerName, METH_NOARGS},
    {"printerState", (PyCFunction)Sbk_QPrinterFunc_printerState, METH_NOARGS},
    {"resolution", (PyCFunction)Sbk_QPrinterFunc_resolution, METH_NOARGS},
    {"setCollateCopies", (PyCFunction)Sbk_QPrinterFunc_setCollateCopies, METH_O},
    {"setColorMode", (PyCFunction)Sbk_QPrinterFunc_setColorMode, METH_O},
    {"setCopyCount", (PyCFunction)Sbk_QPrinterFunc_setCopyCount, METH_O},
    {"setCreator", (PyCFunction)Sbk_QPrinterFunc_setCreator, METH_O},
    {"setDocName", (PyCFunction)Sbk_QPrinterFunc_setDocName, METH_O},
    {"setDoubleSidedPrinting", (PyCFunction)Sbk_QPrinterFunc_setDoubleSidedPrinting, METH_O},
    {"setDuplex", (PyCFunction)Sbk_QPrinterFunc_setDuplex, METH_O},
    {"setEngines", (PyCFunction)Sbk_QPrinterFunc_setEngines, METH_VARARGS},
    {"setFontEmbeddingEnabled", (PyCFunction)Sbk_QPrinterFunc_setFontEmbeddingEnabled, METH_O},
    {"setFromTo", (PyCFunction)Sbk_QPrinterFunc_setFromTo, METH_VARARGS},
    {"setFullPage", (PyCFunction)Sbk_QPrinterFunc_setFullPage, METH_O},
    {"setNumCopies", (PyCFunction)Sbk_QPrinterFunc_setNumCopies, METH_O},
    {"setOrientation", (PyCFunction)Sbk_QPrinterFunc_setOrientation, METH_O},
    {"setOutputFileName", (PyCFunction)Sbk_QPrinterFunc_setOutputFileName, METH_O},
    {"setOutputFormat", (PyCFunction)Sbk_QPrinterFunc_setOutputFormat, METH_O},
    {"setPageMargins", (PyCFunction)Sbk_QPrinterFunc_setPageMargins, METH_VARARGS},
    {"setPageOrder", (PyCFunction)Sbk_QPrinterFunc_setPageOrder, METH_O},
    {"setPageSize", (PyCFunction)Sbk_QPrinterFunc_setPageSize, METH_O},
    {"setPaperSize", (PyCFunction)Sbk_QPrinterFunc_setPaperSize, METH_VARARGS},
    {"setPaperSource", (PyCFunction)Sbk_QPrinterFunc_setPaperSource, METH_O},
    {"setPrintProgram", (PyCFunction)Sbk_QPrinterFunc_setPrintProgram, METH_O},
    {"setPrintRange", (PyCFunction)Sbk_QPrinterFunc_setPrintRange, METH_O},
    {"setPrinterName", (PyCFunction)Sbk_QPrinterFunc_setPrinterName, METH_O},
    {"setResolution", (PyCFunction)Sbk_QPrinterFunc_setResolution, METH_O},
    {"supportedResolutions", (PyCFunction)Sbk_QPrinterFunc_supportedResolutions, METH_NOARGS},
    {"supportsMultipleCopies", (PyCFunction)Sbk_QPrinterFunc_supportsMultipleCopies, METH_NOARGS},
    {"toPage", (PyCFunction)Sbk_QPrinterFunc_toPage, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QPrinter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPrinter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPrinter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPrinter",
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
    /*tp_traverse*/         Sbk_QPrinter_traverse,
    /*tp_clear*/            Sbk_QPrinter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPrinter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPrinter_Init,
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

static void* Sbk_QPrinter_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QPaintDevice >()))
        return dynamic_cast< ::QPrinter*>(reinterpret_cast< ::QPaintDevice*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QPrinter_PrinterMode_PythonToCpp_QPrinter_PrinterMode(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PrinterMode*)cppOut) = (::QPrinter::PrinterMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PrinterMode_PythonToCpp_QPrinter_PrinterMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX]))
        return QPrinter_PrinterMode_PythonToCpp_QPrinter_PrinterMode;
    return 0;
}
static PyObject* QPrinter_PrinterMode_CppToPython_QPrinter_PrinterMode(const void* cppIn) {
    int castCppIn = *((::QPrinter::PrinterMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX], castCppIn);

}

static void QPrinter_Orientation_PythonToCpp_QPrinter_Orientation(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::Orientation*)cppOut) = (::QPrinter::Orientation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_Orientation_PythonToCpp_QPrinter_Orientation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX]))
        return QPrinter_Orientation_PythonToCpp_QPrinter_Orientation;
    return 0;
}
static PyObject* QPrinter_Orientation_CppToPython_QPrinter_Orientation(const void* cppIn) {
    int castCppIn = *((::QPrinter::Orientation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX], castCppIn);

}

static void QPrinter_PageSize_PythonToCpp_QPrinter_PageSize(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PageSize*)cppOut) = (::QPrinter::PageSize) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PageSize_PythonToCpp_QPrinter_PageSize_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX]))
        return QPrinter_PageSize_PythonToCpp_QPrinter_PageSize;
    return 0;
}
static PyObject* QPrinter_PageSize_CppToPython_QPrinter_PageSize(const void* cppIn) {
    int castCppIn = *((::QPrinter::PageSize*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX], castCppIn);

}

static void QPrinter_PageOrder_PythonToCpp_QPrinter_PageOrder(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PageOrder*)cppOut) = (::QPrinter::PageOrder) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PageOrder_PythonToCpp_QPrinter_PageOrder_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX]))
        return QPrinter_PageOrder_PythonToCpp_QPrinter_PageOrder;
    return 0;
}
static PyObject* QPrinter_PageOrder_CppToPython_QPrinter_PageOrder(const void* cppIn) {
    int castCppIn = *((::QPrinter::PageOrder*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX], castCppIn);

}

static void QPrinter_ColorMode_PythonToCpp_QPrinter_ColorMode(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::ColorMode*)cppOut) = (::QPrinter::ColorMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_ColorMode_PythonToCpp_QPrinter_ColorMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX]))
        return QPrinter_ColorMode_PythonToCpp_QPrinter_ColorMode;
    return 0;
}
static PyObject* QPrinter_ColorMode_CppToPython_QPrinter_ColorMode(const void* cppIn) {
    int castCppIn = *((::QPrinter::ColorMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX], castCppIn);

}

static void QPrinter_PaperSource_PythonToCpp_QPrinter_PaperSource(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PaperSource*)cppOut) = (::QPrinter::PaperSource) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PaperSource_PythonToCpp_QPrinter_PaperSource_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX]))
        return QPrinter_PaperSource_PythonToCpp_QPrinter_PaperSource;
    return 0;
}
static PyObject* QPrinter_PaperSource_CppToPython_QPrinter_PaperSource(const void* cppIn) {
    int castCppIn = *((::QPrinter::PaperSource*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX], castCppIn);

}

static void QPrinter_PrinterState_PythonToCpp_QPrinter_PrinterState(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PrinterState*)cppOut) = (::QPrinter::PrinterState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PrinterState_PythonToCpp_QPrinter_PrinterState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX]))
        return QPrinter_PrinterState_PythonToCpp_QPrinter_PrinterState;
    return 0;
}
static PyObject* QPrinter_PrinterState_CppToPython_QPrinter_PrinterState(const void* cppIn) {
    int castCppIn = *((::QPrinter::PrinterState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX], castCppIn);

}

static void QPrinter_OutputFormat_PythonToCpp_QPrinter_OutputFormat(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::OutputFormat*)cppOut) = (::QPrinter::OutputFormat) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_OutputFormat_PythonToCpp_QPrinter_OutputFormat_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX]))
        return QPrinter_OutputFormat_PythonToCpp_QPrinter_OutputFormat;
    return 0;
}
static PyObject* QPrinter_OutputFormat_CppToPython_QPrinter_OutputFormat(const void* cppIn) {
    int castCppIn = *((::QPrinter::OutputFormat*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX], castCppIn);

}

static void QPrinter_PrintRange_PythonToCpp_QPrinter_PrintRange(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::PrintRange*)cppOut) = (::QPrinter::PrintRange) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_PrintRange_PythonToCpp_QPrinter_PrintRange_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX]))
        return QPrinter_PrintRange_PythonToCpp_QPrinter_PrintRange;
    return 0;
}
static PyObject* QPrinter_PrintRange_CppToPython_QPrinter_PrintRange(const void* cppIn) {
    int castCppIn = *((::QPrinter::PrintRange*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX], castCppIn);

}

static void QPrinter_Unit_PythonToCpp_QPrinter_Unit(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::Unit*)cppOut) = (::QPrinter::Unit) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_Unit_PythonToCpp_QPrinter_Unit_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX]))
        return QPrinter_Unit_PythonToCpp_QPrinter_Unit;
    return 0;
}
static PyObject* QPrinter_Unit_CppToPython_QPrinter_Unit(const void* cppIn) {
    int castCppIn = *((::QPrinter::Unit*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX], castCppIn);

}

static void QPrinter_DuplexMode_PythonToCpp_QPrinter_DuplexMode(PyObject* pyIn, void* cppOut) {
    *((::QPrinter::DuplexMode*)cppOut) = (::QPrinter::DuplexMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPrinter_DuplexMode_PythonToCpp_QPrinter_DuplexMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX]))
        return QPrinter_DuplexMode_PythonToCpp_QPrinter_DuplexMode;
    return 0;
}
static PyObject* QPrinter_DuplexMode_CppToPython_QPrinter_DuplexMode(const void* cppIn) {
    int castCppIn = *((::QPrinter::DuplexMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPrinter_PythonToCpp_QPrinter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPrinter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPrinter_PythonToCpp_QPrinter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPrinter_Type))
        return QPrinter_PythonToCpp_QPrinter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPrinter_PTR_CppToPython_QPrinter(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPrinter*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPrinter_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPrinter(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPRINTER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPrinter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPrinter", "QPrinter*",
        &Sbk_QPrinter_Type, &Shiboken::callCppDestructor< ::QPrinter >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPrinter_Type,
        QPrinter_PythonToCpp_QPrinter_PTR,
        is_QPrinter_PythonToCpp_QPrinter_PTR_Convertible,
        QPrinter_PTR_CppToPython_QPrinter);

    Shiboken::Conversions::registerConverterName(converter, "QPrinter");
    Shiboken::Conversions::registerConverterName(converter, "QPrinter*");
    Shiboken::Conversions::registerConverterName(converter, "QPrinter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPrinter).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPrinterWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QPrinter_Type, &Sbk_QPrinter_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'PrinterMode'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PrinterMode",
        "PySide.QtGui.QPrinter.PrinterMode",
        "QPrinter::PrinterMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX],
        &Sbk_QPrinter_Type, "ScreenResolution", (long) QPrinter::ScreenResolution))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX],
        &Sbk_QPrinter_Type, "PrinterResolution", (long) QPrinter::PrinterResolution))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX],
        &Sbk_QPrinter_Type, "HighResolution", (long) QPrinter::HighResolution))
        return ;
    // Register converter for enum 'QPrinter::PrinterMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX],
            QPrinter_PrinterMode_CppToPython_QPrinter_PrinterMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PrinterMode_PythonToCpp_QPrinter_PrinterMode,
            is_QPrinter_PrinterMode_PythonToCpp_QPrinter_PrinterMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PrinterMode");
        Shiboken::Conversions::registerConverterName(converter, "PrinterMode");
    }
    // End of 'PrinterMode' enum.

    // Initialization of enum 'Orientation'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "Orientation",
        "PySide.QtGui.QPrinter.Orientation",
        "QPrinter::Orientation");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX],
        &Sbk_QPrinter_Type, "Portrait", (long) QPrinter::Portrait))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX],
        &Sbk_QPrinter_Type, "Landscape", (long) QPrinter::Landscape))
        return ;
    // Register converter for enum 'QPrinter::Orientation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX],
            QPrinter_Orientation_CppToPython_QPrinter_Orientation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_Orientation_PythonToCpp_QPrinter_Orientation,
            is_QPrinter_Orientation_PythonToCpp_QPrinter_Orientation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_ORIENTATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::Orientation");
        Shiboken::Conversions::registerConverterName(converter, "Orientation");
    }
    // End of 'Orientation' enum.

    // Initialization of enum 'PageSize'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PageSize",
        "PySide.QtGui.QPrinter.PageSize",
        "QPrinter::PageSize");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A4", (long) QPrinter::A4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B5", (long) QPrinter::B5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Letter", (long) QPrinter::Letter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Legal", (long) QPrinter::Legal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Executive", (long) QPrinter::Executive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A0", (long) QPrinter::A0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A1", (long) QPrinter::A1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A2", (long) QPrinter::A2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A3", (long) QPrinter::A3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A5", (long) QPrinter::A5))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A6", (long) QPrinter::A6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A7", (long) QPrinter::A7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A8", (long) QPrinter::A8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "A9", (long) QPrinter::A9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B0", (long) QPrinter::B0))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B1", (long) QPrinter::B1))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B10", (long) QPrinter::B10))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B2", (long) QPrinter::B2))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B3", (long) QPrinter::B3))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B4", (long) QPrinter::B4))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B6", (long) QPrinter::B6))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B7", (long) QPrinter::B7))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B8", (long) QPrinter::B8))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "B9", (long) QPrinter::B9))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "C5E", (long) QPrinter::C5E))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Comm10E", (long) QPrinter::Comm10E))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "DLE", (long) QPrinter::DLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Folio", (long) QPrinter::Folio))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Ledger", (long) QPrinter::Ledger))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Tabloid", (long) QPrinter::Tabloid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "Custom", (long) QPrinter::Custom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "NPageSize", (long) QPrinter::NPageSize))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
        &Sbk_QPrinter_Type, "NPaperSize", (long) QPrinter::NPaperSize))
        return ;
    // Register converter for enum 'QPrinter::PageSize'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX],
            QPrinter_PageSize_CppToPython_QPrinter_PageSize);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PageSize_PythonToCpp_QPrinter_PageSize,
            is_QPrinter_PageSize_PythonToCpp_QPrinter_PageSize_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGESIZE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PageSize");
        Shiboken::Conversions::registerConverterName(converter, "PageSize");
    }
    // End of 'PageSize' enum.

    // Initialization of enum 'PageOrder'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PageOrder",
        "PySide.QtGui.QPrinter.PageOrder",
        "QPrinter::PageOrder");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX],
        &Sbk_QPrinter_Type, "FirstPageFirst", (long) QPrinter::FirstPageFirst))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX],
        &Sbk_QPrinter_Type, "LastPageFirst", (long) QPrinter::LastPageFirst))
        return ;
    // Register converter for enum 'QPrinter::PageOrder'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX],
            QPrinter_PageOrder_CppToPython_QPrinter_PageOrder);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PageOrder_PythonToCpp_QPrinter_PageOrder,
            is_QPrinter_PageOrder_PythonToCpp_QPrinter_PageOrder_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAGEORDER_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PageOrder");
        Shiboken::Conversions::registerConverterName(converter, "PageOrder");
    }
    // End of 'PageOrder' enum.

    // Initialization of enum 'ColorMode'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "ColorMode",
        "PySide.QtGui.QPrinter.ColorMode",
        "QPrinter::ColorMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX],
        &Sbk_QPrinter_Type, "GrayScale", (long) QPrinter::GrayScale))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX],
        &Sbk_QPrinter_Type, "Color", (long) QPrinter::Color))
        return ;
    // Register converter for enum 'QPrinter::ColorMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX],
            QPrinter_ColorMode_CppToPython_QPrinter_ColorMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_ColorMode_PythonToCpp_QPrinter_ColorMode,
            is_QPrinter_ColorMode_PythonToCpp_QPrinter_ColorMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_COLORMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::ColorMode");
        Shiboken::Conversions::registerConverterName(converter, "ColorMode");
    }
    // End of 'ColorMode' enum.

    // Initialization of enum 'PaperSource'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PaperSource",
        "PySide.QtGui.QPrinter.PaperSource",
        "QPrinter::PaperSource");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "OnlyOne", (long) QPrinter::OnlyOne))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Lower", (long) QPrinter::Lower))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Middle", (long) QPrinter::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Manual", (long) QPrinter::Manual))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Envelope", (long) QPrinter::Envelope))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "EnvelopeManual", (long) QPrinter::EnvelopeManual))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Auto", (long) QPrinter::Auto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Tractor", (long) QPrinter::Tractor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "SmallFormat", (long) QPrinter::SmallFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "LargeFormat", (long) QPrinter::LargeFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "LargeCapacity", (long) QPrinter::LargeCapacity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "Cassette", (long) QPrinter::Cassette))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "FormSource", (long) QPrinter::FormSource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
        &Sbk_QPrinter_Type, "MaxPageSource", (long) QPrinter::MaxPageSource))
        return ;
    // Register converter for enum 'QPrinter::PaperSource'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX],
            QPrinter_PaperSource_CppToPython_QPrinter_PaperSource);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PaperSource_PythonToCpp_QPrinter_PaperSource,
            is_QPrinter_PaperSource_PythonToCpp_QPrinter_PaperSource_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PAPERSOURCE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PaperSource");
        Shiboken::Conversions::registerConverterName(converter, "PaperSource");
    }
    // End of 'PaperSource' enum.

    // Initialization of enum 'PrinterState'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PrinterState",
        "PySide.QtGui.QPrinter.PrinterState",
        "QPrinter::PrinterState");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX],
        &Sbk_QPrinter_Type, "Idle", (long) QPrinter::Idle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX],
        &Sbk_QPrinter_Type, "Active", (long) QPrinter::Active))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX],
        &Sbk_QPrinter_Type, "Aborted", (long) QPrinter::Aborted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX],
        &Sbk_QPrinter_Type, "Error", (long) QPrinter::Error))
        return ;
    // Register converter for enum 'QPrinter::PrinterState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX],
            QPrinter_PrinterState_CppToPython_QPrinter_PrinterState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PrinterState_PythonToCpp_QPrinter_PrinterState,
            is_QPrinter_PrinterState_PythonToCpp_QPrinter_PrinterState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTERSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PrinterState");
        Shiboken::Conversions::registerConverterName(converter, "PrinterState");
    }
    // End of 'PrinterState' enum.

    // Initialization of enum 'OutputFormat'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "OutputFormat",
        "PySide.QtGui.QPrinter.OutputFormat",
        "QPrinter::OutputFormat");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX],
        &Sbk_QPrinter_Type, "NativeFormat", (long) QPrinter::NativeFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX],
        &Sbk_QPrinter_Type, "PdfFormat", (long) QPrinter::PdfFormat))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX],
        &Sbk_QPrinter_Type, "PostScriptFormat", (long) QPrinter::PostScriptFormat))
        return ;
    // Register converter for enum 'QPrinter::OutputFormat'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX],
            QPrinter_OutputFormat_CppToPython_QPrinter_OutputFormat);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_OutputFormat_PythonToCpp_QPrinter_OutputFormat,
            is_QPrinter_OutputFormat_PythonToCpp_QPrinter_OutputFormat_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_OUTPUTFORMAT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::OutputFormat");
        Shiboken::Conversions::registerConverterName(converter, "OutputFormat");
    }
    // End of 'OutputFormat' enum.

    // Initialization of enum 'PrintRange'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "PrintRange",
        "PySide.QtGui.QPrinter.PrintRange",
        "QPrinter::PrintRange");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX],
        &Sbk_QPrinter_Type, "AllPages", (long) QPrinter::AllPages))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX],
        &Sbk_QPrinter_Type, "Selection", (long) QPrinter::Selection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX],
        &Sbk_QPrinter_Type, "PageRange", (long) QPrinter::PageRange))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX],
        &Sbk_QPrinter_Type, "CurrentPage", (long) QPrinter::CurrentPage))
        return ;
    // Register converter for enum 'QPrinter::PrintRange'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX],
            QPrinter_PrintRange_CppToPython_QPrinter_PrintRange);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_PrintRange_PythonToCpp_QPrinter_PrintRange,
            is_QPrinter_PrintRange_PythonToCpp_QPrinter_PrintRange_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_PRINTRANGE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::PrintRange");
        Shiboken::Conversions::registerConverterName(converter, "PrintRange");
    }
    // End of 'PrintRange' enum.

    // Initialization of enum 'Unit'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "Unit",
        "PySide.QtGui.QPrinter.Unit",
        "QPrinter::Unit");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Millimeter", (long) QPrinter::Millimeter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Point", (long) QPrinter::Point))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Inch", (long) QPrinter::Inch))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Pica", (long) QPrinter::Pica))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Didot", (long) QPrinter::Didot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "Cicero", (long) QPrinter::Cicero))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
        &Sbk_QPrinter_Type, "DevicePixel", (long) QPrinter::DevicePixel))
        return ;
    // Register converter for enum 'QPrinter::Unit'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX],
            QPrinter_Unit_CppToPython_QPrinter_Unit);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_Unit_PythonToCpp_QPrinter_Unit,
            is_QPrinter_Unit_PythonToCpp_QPrinter_Unit_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_UNIT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::Unit");
        Shiboken::Conversions::registerConverterName(converter, "Unit");
    }
    // End of 'Unit' enum.

    // Initialization of enum 'DuplexMode'.
    SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPrinter_Type,
        "DuplexMode",
        "PySide.QtGui.QPrinter.DuplexMode",
        "QPrinter::DuplexMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX],
        &Sbk_QPrinter_Type, "DuplexNone", (long) QPrinter::DuplexNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX],
        &Sbk_QPrinter_Type, "DuplexAuto", (long) QPrinter::DuplexAuto))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX],
        &Sbk_QPrinter_Type, "DuplexLongSide", (long) QPrinter::DuplexLongSide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX],
        &Sbk_QPrinter_Type, "DuplexShortSide", (long) QPrinter::DuplexShortSide))
        return ;
    // Register converter for enum 'QPrinter::DuplexMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX],
            QPrinter_DuplexMode_CppToPython_QPrinter_DuplexMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPrinter_DuplexMode_PythonToCpp_QPrinter_DuplexMode,
            is_QPrinter_DuplexMode_PythonToCpp_QPrinter_DuplexMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPRINTER_DUPLEXMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPrinter::DuplexMode");
        Shiboken::Conversions::registerConverterName(converter, "DuplexMode");
    }
    // End of 'DuplexMode' enum.


    qRegisterMetaType< ::QPrinter::PrinterMode >("QPrinter::PrinterMode");
    qRegisterMetaType< ::QPrinter::Orientation >("QPrinter::Orientation");
    qRegisterMetaType< ::QPrinter::PageSize >("QPrinter::PageSize");
    qRegisterMetaType< ::QPrinter::PageOrder >("QPrinter::PageOrder");
    qRegisterMetaType< ::QPrinter::ColorMode >("QPrinter::ColorMode");
    qRegisterMetaType< ::QPrinter::PaperSource >("QPrinter::PaperSource");
    qRegisterMetaType< ::QPrinter::PrinterState >("QPrinter::PrinterState");
    qRegisterMetaType< ::QPrinter::OutputFormat >("QPrinter::OutputFormat");
    qRegisterMetaType< ::QPrinter::PrintRange >("QPrinter::PrintRange");
    qRegisterMetaType< ::QPrinter::Unit >("QPrinter::Unit");
    qRegisterMetaType< ::QPrinter::DuplexMode >("QPrinter::DuplexMode");
}
