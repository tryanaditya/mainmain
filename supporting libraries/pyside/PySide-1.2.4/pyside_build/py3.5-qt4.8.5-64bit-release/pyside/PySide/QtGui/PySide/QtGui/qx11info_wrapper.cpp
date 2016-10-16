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

#include "qx11info_wrapper.h"

// Extra includes
#include <qpaintdevice.h>
#include <qx11info_x11.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QX11Info_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QX11Info >()))
        return -1;

    ::QX11Info* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QX11Info", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QX11Info()
    // 1: QX11Info(QX11Info)
    if (numArgs == 0) {
        overloadId = 0; // QX11Info()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (pyArgs[0])))) {
        overloadId = 1; // QX11Info(QX11Info)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11Info_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QX11Info()
        {

            if (!PyErr_Occurred()) {
                // QX11Info()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QX11Info();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QX11Info(const QX11Info & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QX11Info cppArg0_local = ::QX11Info();
            ::QX11Info* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QX11Info(QX11Info)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QX11Info(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QX11Info >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QX11Info_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QX11Info_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QX11Info", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info", overloads);
        return -1;
}

static PyObject* Sbk_QX11InfoFunc_appCells(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appCells(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appCells", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appCells(int)
    if (numArgs == 0) {
        overloadId = 0; // appCells(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appCells(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appCells_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appCells(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appCells_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appCells(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QX11Info::appCells(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appCells_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appCells", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appClass(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // appClass()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const char * cppResult = ::QX11Info::appClass();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11InfoFunc_appColormap(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appColormap(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appColormap", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appColormap(int)
    if (numArgs == 0) {
        overloadId = 0; // appColormap(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appColormap(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appColormap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appColormap(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appColormap_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appColormap(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = ::QX11Info::appColormap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appColormap_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appColormap", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appDefaultColormap(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDefaultColormap(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appDefaultColormap", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appDefaultColormap(int)
    if (numArgs == 0) {
        overloadId = 0; // appDefaultColormap(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appDefaultColormap(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appDefaultColormap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDefaultColormap(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appDefaultColormap_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appDefaultColormap(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QX11Info::appDefaultColormap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appDefaultColormap_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appDefaultColormap", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appDefaultVisual(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDefaultVisual(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appDefaultVisual", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appDefaultVisual(int)
    if (numArgs == 0) {
        overloadId = 0; // appDefaultVisual(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appDefaultVisual(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appDefaultVisual_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDefaultVisual(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appDefaultVisual_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appDefaultVisual(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QX11Info::appDefaultVisual(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appDefaultVisual_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appDefaultVisual", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appDepth(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDepth(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appDepth", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appDepth(int)
    if (numArgs == 0) {
        overloadId = 0; // appDepth(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appDepth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appDepth_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDepth(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appDepth_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appDepth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QX11Info::appDepth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appDepth_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appDepth", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appDpiX(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDpiX(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appDpiX", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appDpiX(int)
    if (numArgs == 0) {
        overloadId = 0; // appDpiX(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appDpiX(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appDpiX_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDpiX(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appDpiX_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appDpiX(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QX11Info::appDpiX(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appDpiX_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appDpiX", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appDpiY(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDpiY(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appDpiY", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appDpiY(int)
    if (numArgs == 0) {
        overloadId = 0; // appDpiY(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appDpiY(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appDpiY_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appDpiY(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appDpiY_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appDpiY(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QX11Info::appDpiY(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appDpiY_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appDpiY", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appRootWindow(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appRootWindow(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appRootWindow", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appRootWindow(int)
    if (numArgs == 0) {
        overloadId = 0; // appRootWindow(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appRootWindow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appRootWindow_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appRootWindow(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appRootWindow_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // appRootWindow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = ::QX11Info::appRootWindow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appRootWindow_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appRootWindow", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_appScreen(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // appScreen()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = ::QX11Info::appScreen();
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

static PyObject* Sbk_QX11InfoFunc_appTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // appTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned long cppResult = ::QX11Info::appTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11InfoFunc_appUserTime(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // appUserTime()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            unsigned long cppResult = ::QX11Info::appUserTime();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11InfoFunc_appVisual(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appVisual(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:appVisual", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: appVisual(int)
    if (numArgs == 0) {
        overloadId = 0; // appVisual(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // appVisual(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_appVisual_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "screen");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QX11Info.appVisual(): got multiple values for keyword argument 'screen'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QX11InfoFunc_appVisual_TypeError;
            }
        }

        if (!PyErr_Occurred()) {
            // appVisual(int)
            // Begin code injection

            pyResult = PyLong_FromVoidPtr(QX11Info::appVisual());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QX11InfoFunc_appVisual_TypeError:
        const char* overloads[] = {"int = -1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.appVisual", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_cells(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cells()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QX11Info*>(cppSelf)->cells();
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

static PyObject* Sbk_QX11InfoFunc_cloneX11Data(PyObject* self, PyObject* pyArg)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: cloneX11Data(const QPaintDevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg)))) {
        overloadId = 0; // cloneX11Data(const QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_cloneX11Data_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // cloneX11Data(const QPaintDevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->cloneX11Data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_cloneX11Data_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QX11Info.cloneX11Data", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_colormap(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // colormap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::HANDLE cppResult = const_cast<const ::QX11Info*>(cppSelf)->colormap();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<Qt::HANDLE>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11InfoFunc_copyX11Data(PyObject* self, PyObject* pyArg)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: copyX11Data(const QPaintDevice*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg)))) {
        overloadId = 0; // copyX11Data(const QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_copyX11Data_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // copyX11Data(const QPaintDevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->copyX11Data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_copyX11Data_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QX11Info.copyX11Data", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_defaultColormap(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultColormap()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QX11Info*>(cppSelf)->defaultColormap();
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

static PyObject* Sbk_QX11InfoFunc_defaultVisual(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // defaultVisual()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QX11Info*>(cppSelf)->defaultVisual();
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

static PyObject* Sbk_QX11InfoFunc_depth(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // depth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QX11Info*>(cppSelf)->depth();
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

static PyObject* Sbk_QX11InfoFunc_display(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // display()
            // Begin code injection

            pyResult = PyLong_FromVoidPtr(QX11Info::display());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11InfoFunc_isCompositingManagerRunning(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCompositingManagerRunning()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QX11Info::isCompositingManagerRunning();
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

static PyObject* Sbk_QX11InfoFunc_screen(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // screen()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QX11Info*>(cppSelf)->screen();
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

static PyObject* Sbk_QX11InfoFunc_setAppDpiX(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAppDpiX", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAppDpiX(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setAppDpiX(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_setAppDpiX_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAppDpiX(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QX11Info::setAppDpiX(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_setAppDpiX_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.setAppDpiX", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_setAppDpiY(PyObject* self, PyObject* args)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAppDpiY", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAppDpiY(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setAppDpiY(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_setAppDpiY_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAppDpiY(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QX11Info::setAppDpiY(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_setAppDpiY_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QX11Info.setAppDpiY", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_setAppTime(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAppTime(ulong)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArg)))) {
        overloadId = 0; // setAppTime(ulong)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_setAppTime_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAppTime(ulong)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QX11Info::setAppTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_setAppTime_TypeError:
        const char* overloads[] = {"unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QX11Info.setAppTime", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_setAppUserTime(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAppUserTime(ulong)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long>(), (pyArg)))) {
        overloadId = 0; // setAppUserTime(ulong)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QX11InfoFunc_setAppUserTime_TypeError;

    // Call function/method
    {
        unsigned long cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAppUserTime(ulong)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QX11Info::setAppUserTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QX11InfoFunc_setAppUserTime_TypeError:
        const char* overloads[] = {"unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QX11Info.setAppUserTime", overloads);
        return 0;
}

static PyObject* Sbk_QX11InfoFunc_visual(PyObject* self)
{
    ::QX11Info* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // visual()const
            // Begin code injection

            pyResult = PyLong_FromVoidPtr(cppSelf->visual());

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QX11Info___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QX11Info& cppSelf = *(((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QX11Info_methods[] = {
    {"appCells", (PyCFunction)Sbk_QX11InfoFunc_appCells, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appClass", (PyCFunction)Sbk_QX11InfoFunc_appClass, METH_NOARGS|METH_STATIC},
    {"appColormap", (PyCFunction)Sbk_QX11InfoFunc_appColormap, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appDefaultColormap", (PyCFunction)Sbk_QX11InfoFunc_appDefaultColormap, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appDefaultVisual", (PyCFunction)Sbk_QX11InfoFunc_appDefaultVisual, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appDepth", (PyCFunction)Sbk_QX11InfoFunc_appDepth, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appDpiX", (PyCFunction)Sbk_QX11InfoFunc_appDpiX, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appDpiY", (PyCFunction)Sbk_QX11InfoFunc_appDpiY, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appRootWindow", (PyCFunction)Sbk_QX11InfoFunc_appRootWindow, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"appScreen", (PyCFunction)Sbk_QX11InfoFunc_appScreen, METH_NOARGS|METH_STATIC},
    {"appTime", (PyCFunction)Sbk_QX11InfoFunc_appTime, METH_NOARGS|METH_STATIC},
    {"appUserTime", (PyCFunction)Sbk_QX11InfoFunc_appUserTime, METH_NOARGS|METH_STATIC},
    {"appVisual", (PyCFunction)Sbk_QX11InfoFunc_appVisual, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"cells", (PyCFunction)Sbk_QX11InfoFunc_cells, METH_NOARGS},
    {"cloneX11Data", (PyCFunction)Sbk_QX11InfoFunc_cloneX11Data, METH_O},
    {"colormap", (PyCFunction)Sbk_QX11InfoFunc_colormap, METH_NOARGS},
    {"copyX11Data", (PyCFunction)Sbk_QX11InfoFunc_copyX11Data, METH_O},
    {"defaultColormap", (PyCFunction)Sbk_QX11InfoFunc_defaultColormap, METH_NOARGS},
    {"defaultVisual", (PyCFunction)Sbk_QX11InfoFunc_defaultVisual, METH_NOARGS},
    {"depth", (PyCFunction)Sbk_QX11InfoFunc_depth, METH_NOARGS},
    {"display", (PyCFunction)Sbk_QX11InfoFunc_display, METH_NOARGS|METH_STATIC},
    {"isCompositingManagerRunning", (PyCFunction)Sbk_QX11InfoFunc_isCompositingManagerRunning, METH_NOARGS|METH_STATIC},
    {"screen", (PyCFunction)Sbk_QX11InfoFunc_screen, METH_NOARGS},
    {"setAppDpiX", (PyCFunction)Sbk_QX11InfoFunc_setAppDpiX, METH_VARARGS|METH_STATIC},
    {"setAppDpiY", (PyCFunction)Sbk_QX11InfoFunc_setAppDpiY, METH_VARARGS|METH_STATIC},
    {"setAppTime", (PyCFunction)Sbk_QX11InfoFunc_setAppTime, METH_O|METH_STATIC},
    {"setAppUserTime", (PyCFunction)Sbk_QX11InfoFunc_setAppUserTime, METH_O|METH_STATIC},
    {"visual", (PyCFunction)Sbk_QX11InfoFunc_visual, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QX11Info___copy__, METH_NOARGS},
    {0} // Sentinel
};

} // extern "C"

static int Sbk_QX11Info_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QX11Info_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QX11Info_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QX11Info",
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
    /*tp_traverse*/         Sbk_QX11Info_traverse,
    /*tp_clear*/            Sbk_QX11Info_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QX11Info_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QX11Info_Init,
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
static void QX11Info_PythonToCpp_QX11Info_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QX11Info_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QX11Info_PythonToCpp_QX11Info_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QX11Info_Type))
        return QX11Info_PythonToCpp_QX11Info_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QX11Info_PTR_CppToPython_QX11Info(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QX11Info*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QX11Info_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QX11Info_COPY_CppToPython_QX11Info(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QX11Info_Type, new ::QX11Info(*((::QX11Info*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QX11Info_PythonToCpp_QX11Info_COPY(PyObject* pyIn, void* cppOut) {
    *((::QX11Info*)cppOut) = *((::QX11Info*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QX11Info_PythonToCpp_QX11Info_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QX11Info_Type))
        return QX11Info_PythonToCpp_QX11Info_COPY;
    return 0;
}

void init_QX11Info(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QX11INFO_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QX11Info_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QX11Info", "QX11Info",
        &Sbk_QX11Info_Type, &Shiboken::callCppDestructor< ::QX11Info >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QX11Info_Type,
        QX11Info_PythonToCpp_QX11Info_PTR,
        is_QX11Info_PythonToCpp_QX11Info_PTR_Convertible,
        QX11Info_PTR_CppToPython_QX11Info,
        QX11Info_COPY_CppToPython_QX11Info);

    Shiboken::Conversions::registerConverterName(converter, "QX11Info");
    Shiboken::Conversions::registerConverterName(converter, "QX11Info*");
    Shiboken::Conversions::registerConverterName(converter, "QX11Info&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QX11Info).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QX11Info_PythonToCpp_QX11Info_COPY,
        is_QX11Info_PythonToCpp_QX11Info_COPY_Convertible);


    qRegisterMetaType< ::QX11Info >("QX11Info");
}
