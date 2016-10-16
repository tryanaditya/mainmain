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

#include "qclipboard_wrapper.h"

// Extra includes
#include <QImage>
#include <QList>
#include <QPixmap>
#include <qbytearray.h>
#include <qclipboard.h>
#include <qcoreevent.h>
#include <qimage.h>
#include <qmetaobject.h>
#include <qmimedata.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpixmap.h>
#include <qthread.h>



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_QClipboardFunc_clear(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.clear(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:clear", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: clear(QClipboard::Mode)
    if (numArgs == 0) {
        overloadId = 0; // clear(QClipboard::Mode)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // clear(QClipboard::Mode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_clear_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.clear(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QClipboardFunc_clear_TypeError;
            }
        }
        ::QClipboard::Mode cppArg0 = QClipboard::Clipboard;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // clear(QClipboard::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clear(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_clear_TypeError:
        const char* overloads[] = {"PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.clear", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_connectNotify(PyObject* self, PyObject* pyArg)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: connectNotify(const char*)
    if (Shiboken::String::check(pyArg) && (pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArg)))) {
        overloadId = 0; // connectNotify(const char*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_connectNotify_TypeError;

    // Call function/method
    {
        const char* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // connectNotify(const char*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QClipboard::connectNotify(cppArg0) : cppSelf->connectNotify(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_connectNotify_TypeError:
        const char* overloads[] = {"" SBK_STR_NAME "", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QClipboard.connectNotify", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QClipboard::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QClipboardFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QClipboard.event", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_image(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.image(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:image", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: image(QClipboard::Mode)const
    if (numArgs == 0) {
        overloadId = 0; // image(QClipboard::Mode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // image(QClipboard::Mode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_image_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.image(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QClipboardFunc_image_TypeError;
            }
        }
        ::QClipboard::Mode cppArg0 = QClipboard::Clipboard;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // image(QClipboard::Mode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QClipboard*>(cppSelf)->image(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QClipboardFunc_image_TypeError:
        const char* overloads[] = {"PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.image", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_mimeData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.mimeData(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:mimeData", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: mimeData(QClipboard::Mode)const
    if (numArgs == 0) {
        overloadId = 0; // mimeData(QClipboard::Mode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // mimeData(QClipboard::Mode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_mimeData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.mimeData(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QClipboardFunc_mimeData_TypeError;
            }
        }
        ::QClipboard::Mode cppArg0 = QClipboard::Clipboard;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // mimeData(QClipboard::Mode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMimeData * cppResult = const_cast<const ::QClipboard*>(cppSelf)->mimeData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QClipboardFunc_mimeData_TypeError:
        const char* overloads[] = {"PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.mimeData", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_ownsClipboard(PyObject* self)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownsClipboard()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QClipboard*>(cppSelf)->ownsClipboard();
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

static PyObject* Sbk_QClipboardFunc_ownsFindBuffer(PyObject* self)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownsFindBuffer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QClipboard*>(cppSelf)->ownsFindBuffer();
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

static PyObject* Sbk_QClipboardFunc_ownsSelection(PyObject* self)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownsSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QClipboard*>(cppSelf)->ownsSelection();
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

static PyObject* Sbk_QClipboardFunc_pixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.pixmap(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:pixmap", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: pixmap(QClipboard::Mode)const
    if (numArgs == 0) {
        overloadId = 0; // pixmap(QClipboard::Mode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // pixmap(QClipboard::Mode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_pixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.pixmap(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QClipboardFunc_pixmap_TypeError;
            }
        }
        ::QClipboard::Mode cppArg0 = QClipboard::Clipboard;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // pixmap(QClipboard::Mode)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QClipboard*>(cppSelf)->pixmap(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QClipboardFunc_pixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.pixmap", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_setImage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setImage(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setImage", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setImage(QImage,QClipboard::Mode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setImage(QImage,QClipboard::Mode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setImage(QImage,QClipboard::Mode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_setImage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setImage(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QClipboardFunc_setImage_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QClipboard::Mode cppArg1 = QClipboard::Clipboard;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setImage(QImage,QClipboard::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setImage(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_setImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage, PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.setImage", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_setMimeData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setMimeData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setMimeData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setMimeData", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMimeData(QMimeData*,QClipboard::Mode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMIMEDATA_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMimeData(QMimeData*,QClipboard::Mode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setMimeData(QMimeData*,QClipboard::Mode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_setMimeData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setMimeData(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QClipboardFunc_setMimeData_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QMimeData* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QClipboard::Mode cppArg1 = QClipboard::Clipboard;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMimeData(QMimeData*,QClipboard::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMimeData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[0]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_setMimeData_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMimeData, PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.setMimeData", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_setPixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setPixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setPixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setPixmap", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPixmap(QPixmap,QClipboard::Mode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setPixmap(QPixmap,QClipboard::Mode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setPixmap(QPixmap,QClipboard::Mode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_setPixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setPixmap(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QClipboardFunc_setPixmap_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPixmap cppArg0_local = ::QPixmap();
        ::QPixmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QClipboard::Mode cppArg1 = QClipboard::Clipboard;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setPixmap(QPixmap,QClipboard::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPixmap(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_setPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap, PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.setPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_setText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setText(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setText(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setText", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setText(QString,QClipboard::Mode)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setText(QString,QClipboard::Mode)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setText(QString,QClipboard::Mode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_setText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.setText(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QClipboardFunc_setText_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QClipboard::Mode cppArg1 = QClipboard::Clipboard;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setText(QString,QClipboard::Mode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QClipboardFunc_setText_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QClipboard.Mode = Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.setText", overloads);
        return 0;
}

static PyObject* Sbk_QClipboardFunc_supportsFindBuffer(PyObject* self)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsFindBuffer()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QClipboard*>(cppSelf)->supportsFindBuffer();
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

static PyObject* Sbk_QClipboardFunc_supportsSelection(PyObject* self)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QClipboard*>(cppSelf)->supportsSelection();
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

static PyObject* Sbk_QClipboardFunc_text(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QClipboard* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QClipboard*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.text(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:text", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: text(QClipboard::Mode)const
    // 1: text(QString&,QClipboard::Mode)const
    if (numArgs == 0) {
        overloadId = 0; // text(QClipboard::Mode)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // text(QString&,QClipboard::Mode)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1])))) {
            overloadId = 1; // text(QString&,QClipboard::Mode)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0])))) {
        overloadId = 0; // text(QClipboard::Mode)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QClipboardFunc_text_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // text(QClipboard::Mode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.text(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[0]))))
                        goto Sbk_QClipboardFunc_text_TypeError;
                }
            }
            ::QClipboard::Mode cppArg0 = QClipboard::Clipboard;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // text(QClipboard::Mode)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString cppResult = const_cast<const ::QClipboard*>(cppSelf)->text(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // text(QString & subtype, QClipboard::Mode mode) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QClipboard.text(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QClipboardFunc_text_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QClipboard::Mode cppArg1 = QClipboard::Clipboard;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // text(QString&,QClipboard::Mode)const


                // Begin code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QString retval_ = cppSelf->text(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = PyTuple_New(2);
                PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &retval_));
                PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg0));

                // End of code injection
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QClipboardFunc_text_TypeError:
        const char* overloads[] = {"PySide.QtGui.QClipboard.Mode = Clipboard", "PySide.QtCore.QString, PySide.QtGui.QClipboard.Mode = QClipboard.Clipboard", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QClipboard.text", overloads);
        return 0;
}

static PyMethodDef Sbk_QClipboard_methods[] = {
    {"clear", (PyCFunction)Sbk_QClipboardFunc_clear, METH_VARARGS|METH_KEYWORDS},
    {"connectNotify", (PyCFunction)Sbk_QClipboardFunc_connectNotify, METH_O},
    {"event", (PyCFunction)Sbk_QClipboardFunc_event, METH_O},
    {"image", (PyCFunction)Sbk_QClipboardFunc_image, METH_VARARGS|METH_KEYWORDS},
    {"mimeData", (PyCFunction)Sbk_QClipboardFunc_mimeData, METH_VARARGS|METH_KEYWORDS},
    {"ownsClipboard", (PyCFunction)Sbk_QClipboardFunc_ownsClipboard, METH_NOARGS},
    {"ownsFindBuffer", (PyCFunction)Sbk_QClipboardFunc_ownsFindBuffer, METH_NOARGS},
    {"ownsSelection", (PyCFunction)Sbk_QClipboardFunc_ownsSelection, METH_NOARGS},
    {"pixmap", (PyCFunction)Sbk_QClipboardFunc_pixmap, METH_VARARGS|METH_KEYWORDS},
    {"setImage", (PyCFunction)Sbk_QClipboardFunc_setImage, METH_VARARGS|METH_KEYWORDS},
    {"setMimeData", (PyCFunction)Sbk_QClipboardFunc_setMimeData, METH_VARARGS|METH_KEYWORDS},
    {"setPixmap", (PyCFunction)Sbk_QClipboardFunc_setPixmap, METH_VARARGS|METH_KEYWORDS},
    {"setText", (PyCFunction)Sbk_QClipboardFunc_setText, METH_VARARGS|METH_KEYWORDS},
    {"supportsFindBuffer", (PyCFunction)Sbk_QClipboardFunc_supportsFindBuffer, METH_NOARGS},
    {"supportsSelection", (PyCFunction)Sbk_QClipboardFunc_supportsSelection, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QClipboardFunc_text, METH_VARARGS|METH_KEYWORDS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QClipboard_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QClipboard_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QClipboard_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QClipboard",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          SbkDeallocWrapperWithPrivateDtor,
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
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QClipboard_traverse,
    /*tp_clear*/            Sbk_QClipboard_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QClipboard_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
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

static void* Sbk_QClipboard_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QClipboard*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QClipboard_Mode_PythonToCpp_QClipboard_Mode(PyObject* pyIn, void* cppOut) {
    *((::QClipboard::Mode*)cppOut) = (::QClipboard::Mode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QClipboard_Mode_PythonToCpp_QClipboard_Mode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]))
        return QClipboard_Mode_PythonToCpp_QClipboard_Mode;
    return 0;
}
static PyObject* QClipboard_Mode_CppToPython_QClipboard_Mode(const void* cppIn) {
    int castCppIn = *((::QClipboard::Mode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QClipboard_PythonToCpp_QClipboard_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QClipboard_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QClipboard_PythonToCpp_QClipboard_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QClipboard_Type))
        return QClipboard_PythonToCpp_QClipboard_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QClipboard_PTR_CppToPython_QClipboard(const void* cppIn) {
    return PySide::getWrapperForQObject((::QClipboard*)cppIn, &Sbk_QClipboard_Type);

}

void init_QClipboard(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QClipboard_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QClipboard", "QClipboard*",
        &Sbk_QClipboard_Type, 0, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QClipboard_Type,
        QClipboard_PythonToCpp_QClipboard_PTR,
        is_QClipboard_PythonToCpp_QClipboard_PTR_Convertible,
        QClipboard_PTR_CppToPython_QClipboard);

    Shiboken::Conversions::registerConverterName(converter, "QClipboard");
    Shiboken::Conversions::registerConverterName(converter, "QClipboard*");
    Shiboken::Conversions::registerConverterName(converter, "QClipboard&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QClipboard).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QClipboard_Type, &Sbk_QClipboard_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Mode'.
    SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QClipboard_Type,
        "Mode",
        "PySide.QtGui.QClipboard.Mode",
        "QClipboard::Mode");
    if (!SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX],
        &Sbk_QClipboard_Type, "Clipboard", (long) QClipboard::Clipboard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX],
        &Sbk_QClipboard_Type, "Selection", (long) QClipboard::Selection))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX],
        &Sbk_QClipboard_Type, "FindBuffer", (long) QClipboard::FindBuffer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX],
        &Sbk_QClipboard_Type, "LastMode", (long) QClipboard::LastMode))
        return ;
    // Register converter for enum 'QClipboard::Mode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX],
            QClipboard_Mode_CppToPython_QClipboard_Mode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QClipboard_Mode_PythonToCpp_QClipboard_Mode,
            is_QClipboard_Mode_PythonToCpp_QClipboard_Mode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QClipboard::Mode");
        Shiboken::Conversions::registerConverterName(converter, "Mode");
    }
    // End of 'Mode' enum.

    PySide::Signal::registerSignals(&Sbk_QClipboard_Type, &::QClipboard::staticMetaObject);

    qRegisterMetaType< ::QClipboard::Mode >("QClipboard::Mode");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QClipboard_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QClipboard_Type, &::QClipboard::staticMetaObject, sizeof(::QClipboard));
}
