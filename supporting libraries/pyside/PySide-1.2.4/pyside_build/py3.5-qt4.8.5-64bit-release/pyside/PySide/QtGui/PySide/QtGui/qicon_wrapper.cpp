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

#include "qicon_wrapper.h"

// Extra includes
#include <QList>
#include <qdatastream.h>
#include <qicon.h>
#include <qiconengine.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qrect.h>
#include <qsize.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QIcon_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QIcon >()))
        return -1;

    ::QIcon* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QIcon", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QIcon()
    // 1: QIcon(QIconEngine*)
    // 2: QIcon(QIconEngineV2*)
    // 3: QIcon(QIcon)
    // 4: QIcon(QPixmap)
    // 5: QIcon(QString)
    if (numArgs == 0) {
        overloadId = 0; // QIcon()
    } else if (numArgs == 1
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICONENGINEV2_IDX], (pyArgs[0]))))) {
        overloadId = 2; // QIcon(QIconEngineV2*)
    } else if (numArgs == 1
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICONENGINE_IDX], (pyArgs[0]))))) {
        overloadId = 1; // QIcon(QIconEngine*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 5; // QIcon(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        overloadId = 4; // QIcon(QPixmap)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[0])))) {
        overloadId = 3; // QIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIcon_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QIcon()
        {

            if (!PyErr_Occurred()) {
                // QIcon()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QIcon(QIconEngine * engine)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIconEngine* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QIcon(QIconEngine*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 2: // QIcon(QIconEngineV2 * engine)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIconEngineV2* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QIcon(QIconEngineV2*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 3: // QIcon(const QIcon & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIcon cppArg0_local = ::QIcon();
            ::QIcon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QIcon(QIcon)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QIcon(const QPixmap & pixmap)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPixmap cppArg0_local = ::QPixmap();
            ::QPixmap* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QIcon(QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QIcon(const QString & fileName)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QIcon(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QIcon(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QIcon >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QIcon_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QIcon_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QIconEngine", "PySide.QtGui.QIconEngineV2", "PySide.QtGui.QIcon", "PySide.QtGui.QPixmap", "unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon", overloads);
        return -1;
}

static PyObject* Sbk_QIconFunc_actualSize(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.actualSize(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.actualSize(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:actualSize", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: actualSize(QSize,QIcon::Mode,QIcon::State)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // actualSize(QSize,QIcon::Mode,QIcon::State)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // actualSize(QSize,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // actualSize(QSize,QIcon::Mode,QIcon::State)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_actualSize_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.actualSize(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QIconFunc_actualSize_TypeError;
            }
            value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.actualSize(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2]))))
                    goto Sbk_QIconFunc_actualSize_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QIcon::Mode cppArg1 = QIcon::Normal;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QIcon::State cppArg2 = QIcon::Off;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // actualSize(QSize,QIcon::Mode,QIcon::State)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QIcon*>(cppSelf)->actualSize(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconFunc_actualSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.actualSize", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_addFile(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addFile(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addFile(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:addFile", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addFile(QString,QSize,QIcon::Mode,QIcon::State)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addFile(QString,QSize,QIcon::Mode,QIcon::State)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addFile(QString,QSize,QIcon::Mode,QIcon::State)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // addFile(QString,QSize,QIcon::Mode,QIcon::State)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[3])))) {
                    overloadId = 0; // addFile(QString,QSize,QIcon::Mode,QIcon::State)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_addFile_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "size");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addFile(): got multiple values for keyword argument 'size'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1]))))
                    goto Sbk_QIconFunc_addFile_TypeError;
            }
            value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addFile(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[2]))))
                    goto Sbk_QIconFunc_addFile_TypeError;
            }
            value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addFile(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[3]))))
                    goto Sbk_QIconFunc_addFile_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSize cppArg1_local = QSize();
        ::QSize* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }
        ::QIcon::Mode cppArg2 = QIcon::Normal;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QIcon::State cppArg3 = QIcon::Off;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // addFile(QString,QSize,QIcon::Mode,QIcon::State)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addFile(cppArg0, *cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_addFile_TypeError:
        const char* overloads[] = {"unicode, PySide.QtCore.QSize = QSize(), PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.addFile", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_addPixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addPixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addPixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addPixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addPixmap(QPixmap,QIcon::Mode,QIcon::State)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // addPixmap(QPixmap,QIcon::Mode,QIcon::State)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // addPixmap(QPixmap,QIcon::Mode,QIcon::State)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // addPixmap(QPixmap,QIcon::Mode,QIcon::State)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_addPixmap_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addPixmap(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1]))))
                    goto Sbk_QIconFunc_addPixmap_TypeError;
            }
            value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.addPixmap(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2]))))
                    goto Sbk_QIconFunc_addPixmap_TypeError;
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

        ::QIcon::Mode cppArg1 = QIcon::Normal;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QIcon::State cppArg2 = QIcon::Off;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addPixmap(QPixmap,QIcon::Mode,QIcon::State)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addPixmap(*cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_addPixmap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.addPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_availableSizes(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.availableSizes(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:availableSizes", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: availableSizes(QIcon::Mode,QIcon::State)const
    if (numArgs == 0) {
        overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[1])))) {
            overloadId = 0; // availableSizes(QIcon::Mode,QIcon::State)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_availableSizes_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "mode");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.availableSizes(): got multiple values for keyword argument 'mode'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[0]))))
                    goto Sbk_QIconFunc_availableSizes_TypeError;
            }
            value = PyDict_GetItemString(kwds, "state");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.availableSizes(): got multiple values for keyword argument 'state'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[1]))))
                    goto Sbk_QIconFunc_availableSizes_TypeError;
            }
        }
        ::QIcon::Mode cppArg0 = QIcon::Normal;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QIcon::State cppArg1 = QIcon::Off;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // availableSizes(QIcon::Mode,QIcon::State)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QSize > cppResult = const_cast<const ::QIcon*>(cppSelf)->availableSizes(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconFunc_availableSizes_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.availableSizes", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_cacheKey(PyObject* self)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QIcon*>(cppSelf)->cacheKey();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QIconFunc_fromTheme(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.fromTheme(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.fromTheme(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:fromTheme", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fromTheme(QString,QIcon)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // fromTheme(QString,QIcon)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[1])))) {
            overloadId = 0; // fromTheme(QString,QIcon)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_fromTheme_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "fallback");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.fromTheme(): got multiple values for keyword argument 'fallback'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[1]))))
                    goto Sbk_QIconFunc_fromTheme_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QIcon cppArg1_local = QIcon();
        ::QIcon* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // fromTheme(QString,QIcon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = ::QIcon::fromTheme(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconFunc_fromTheme_TypeError:
        const char* overloads[] = {"unicode, PySide.QtGui.QIcon = QIcon()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.fromTheme", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_hasThemeIcon(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: hasThemeIcon(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // hasThemeIcon(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_hasThemeIcon_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hasThemeIcon(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QIcon::hasThemeIcon(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconFunc_hasThemeIcon_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.hasThemeIcon", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_isNull(PyObject* self)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QIcon*>(cppSelf)->isNull();
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

static PyObject* Sbk_QIconFunc_name(PyObject* self)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // name()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QIcon*>(cppSelf)->name();
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

static PyObject* Sbk_QIconFunc_paint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 8) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOO:paint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return 0;


    // Overloaded function decisor
    // 0: paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
    // 1: paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (pyArgs[0])))) {
        if (numArgs >= 5
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5])))) {
                if (numArgs == 6) {
                    overloadId = 1; // paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[6])))) {
                    if (numArgs == 7) {
                        overloadId = 1; // paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                    } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[7])))) {
                        overloadId = 1; // paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                    }
                }
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[4])))) {
                        overloadId = 0; // paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_paint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // paint(QPainter * painter, const QRect & rect, QFlags<Qt::AlignmentFlag> alignment, QIcon::Mode mode, QIcon::State state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[2]))))
                        goto Sbk_QIconFunc_paint_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QIconFunc_paint_TypeError;
                }
                value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[4]))))
                        goto Sbk_QIconFunc_paint_TypeError;
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

            ::QFlags<Qt::AlignmentFlag> cppArg2 = Qt::AlignCenter;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QIcon::Mode cppArg3 = QIcon::Normal;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QIcon::State cppArg4 = QIcon::Off;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // paint(QPainter*,QRect,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const_cast<const ::QIcon*>(cppSelf)->paint(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // paint(QPainter * painter, int x, int y, int w, int h, QFlags<Qt::AlignmentFlag> alignment, QIcon::Mode mode, QIcon::State state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5]))))
                        goto Sbk_QIconFunc_paint_TypeError;
                }
                value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[6]))))
                        goto Sbk_QIconFunc_paint_TypeError;
                }
                value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.paint(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[7]))))
                        goto Sbk_QIconFunc_paint_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::AlignmentFlag> cppArg5 = Qt::AlignCenter;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            ::QIcon::Mode cppArg6 = QIcon::Normal;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            ::QIcon::State cppArg7 = QIcon::Off;
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);

            if (!PyErr_Occurred()) {
                // paint(QPainter*,int,int,int,int,QFlags<Qt::AlignmentFlag>,QIcon::Mode,QIcon::State)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const_cast<const ::QIcon*>(cppSelf)->paint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_paint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter, PySide.QtCore.QRect, PySide.QtCore.Qt.Alignment = Qt.AlignCenter, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", "PySide.QtGui.QPainter, int, int, int, int, PySide.QtCore.Qt.Alignment = Qt.AlignCenter, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.paint", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_pixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:pixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: pixmap(QSize,QIcon::Mode,QIcon::State)const
    // 1: pixmap(int,QIcon::Mode,QIcon::State)const
    // 2: pixmap(int,int,QIcon::Mode,QIcon::State)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // pixmap(int,QIcon::Mode,QIcon::State)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // pixmap(int,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2])))) {
                overloadId = 1; // pixmap(int,QIcon::Mode,QIcon::State)const
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // pixmap(int,int,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 2; // pixmap(int,int,QIcon::Mode,QIcon::State)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[3])))) {
                    overloadId = 2; // pixmap(int,int,QIcon::Mode,QIcon::State)const
                }
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // pixmap(QSize,QIcon::Mode,QIcon::State)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // pixmap(QSize,QIcon::Mode,QIcon::State)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2])))) {
                overloadId = 0; // pixmap(QSize,QIcon::Mode,QIcon::State)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_pixmap_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // pixmap(const QSize & size, QIcon::Mode mode, QIcon::State state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
                value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSize cppArg0_local = ::QSize();
            ::QSize* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QIcon::Mode cppArg1 = QIcon::Normal;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QIcon::State cppArg2 = QIcon::Off;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // pixmap(QSize,QIcon::Mode,QIcon::State)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap cppResult = const_cast<const ::QIcon*>(cppSelf)->pixmap(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 1: // pixmap(int extent, QIcon::Mode mode, QIcon::State state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[1]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
                value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[2]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QIcon::Mode cppArg1 = QIcon::Normal;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QIcon::State cppArg2 = QIcon::Off;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // pixmap(int,QIcon::Mode,QIcon::State)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap cppResult = const_cast<const ::QIcon*>(cppSelf)->pixmap(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
        case 2: // pixmap(int w, int h, QIcon::Mode mode, QIcon::State state) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]), (pyArgs[2]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
                value = PyDict_GetItemString(kwds, "state");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QIcon.pixmap(): got multiple values for keyword argument 'state'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]), (pyArgs[3]))))
                        goto Sbk_QIconFunc_pixmap_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QIcon::Mode cppArg2 = QIcon::Normal;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QIcon::State cppArg3 = QIcon::Off;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // pixmap(int,int,QIcon::Mode,QIcon::State)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPixmap cppResult = const_cast<const ::QIcon*>(cppSelf)->pixmap(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QIconFunc_pixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", "int, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", "int, int, PySide.QtGui.QIcon.Mode = Normal, PySide.QtGui.QIcon.State = Off", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QIcon.pixmap", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_setThemeName(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setThemeName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setThemeName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_setThemeName_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setThemeName(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QIcon::setThemeName(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_setThemeName_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.setThemeName", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_setThemeSearchPaths(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setThemeSearchPaths(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setThemeSearchPaths(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_setThemeSearchPaths_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0 = ::QStringList();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setThemeSearchPaths(QStringList)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QIcon::setThemeSearchPaths(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_setThemeSearchPaths_TypeError:
        const char* overloads[] = {"QStringList", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.setThemeSearchPaths", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QIcon&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // swap(QIcon&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIcon cppArg0_local = ::QIcon();
        ::QIcon* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QIcon&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QIconFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.swap", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc_themeName(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // themeName()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = ::QIcon::themeName();
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

static PyObject* Sbk_QIconFunc_themeSearchPaths(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // themeSearchPaths()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = ::QIcon::themeSearchPaths();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QIcon___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QIcon& cppSelf = *(((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QIcon_methods[] = {
    {"actualSize", (PyCFunction)Sbk_QIconFunc_actualSize, METH_VARARGS|METH_KEYWORDS},
    {"addFile", (PyCFunction)Sbk_QIconFunc_addFile, METH_VARARGS|METH_KEYWORDS},
    {"addPixmap", (PyCFunction)Sbk_QIconFunc_addPixmap, METH_VARARGS|METH_KEYWORDS},
    {"availableSizes", (PyCFunction)Sbk_QIconFunc_availableSizes, METH_VARARGS|METH_KEYWORDS},
    {"cacheKey", (PyCFunction)Sbk_QIconFunc_cacheKey, METH_NOARGS},
    {"fromTheme", (PyCFunction)Sbk_QIconFunc_fromTheme, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"hasThemeIcon", (PyCFunction)Sbk_QIconFunc_hasThemeIcon, METH_O|METH_STATIC},
    {"isNull", (PyCFunction)Sbk_QIconFunc_isNull, METH_NOARGS},
    {"name", (PyCFunction)Sbk_QIconFunc_name, METH_NOARGS},
    {"paint", (PyCFunction)Sbk_QIconFunc_paint, METH_VARARGS|METH_KEYWORDS},
    {"pixmap", (PyCFunction)Sbk_QIconFunc_pixmap, METH_VARARGS|METH_KEYWORDS},
    {"setThemeName", (PyCFunction)Sbk_QIconFunc_setThemeName, METH_O|METH_STATIC},
    {"setThemeSearchPaths", (PyCFunction)Sbk_QIconFunc_setThemeSearchPaths, METH_O|METH_STATIC},
    {"swap", (PyCFunction)Sbk_QIconFunc_swap, METH_O},
    {"themeName", (PyCFunction)Sbk_QIconFunc_themeName, METH_NOARGS|METH_STATIC},
    {"themeSearchPaths", (PyCFunction)Sbk_QIconFunc_themeSearchPaths, METH_NOARGS|METH_STATIC},

    {"__copy__", (PyCFunction)Sbk_QIcon___copy__, METH_NOARGS},
    {0} // Sentinel
};

static int Sbk_QIcon___nb_bool(PyObject* self)
{
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return -1;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
    int result;
    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
    result = !cppSelf->isNull();
    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
    return result;
}

static PyObject* Sbk_QIconFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QICON_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QIcon)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QIcon)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QIcon) [reverse operator]
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

    Sbk_QIconFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QIconFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QICON_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QICON_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QIcon&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QIcon&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QIconFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QIcon&) [reverse operator]
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

    Sbk_QIconFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QIcon.__rshift__", overloads);
        return 0;
}

} // extern "C"

static int Sbk_QIcon_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QIcon_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QIcon_TypeAsNumber;

static SbkObjectType Sbk_QIcon_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QIcon",
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
    /*tp_traverse*/         Sbk_QIcon_traverse,
    /*tp_clear*/            Sbk_QIcon_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QIcon_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QIcon_Init,
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
static void QIcon_Mode_PythonToCpp_QIcon_Mode(PyObject* pyIn, void* cppOut) {
    *((::QIcon::Mode*)cppOut) = (::QIcon::Mode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QIcon_Mode_PythonToCpp_QIcon_Mode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX]))
        return QIcon_Mode_PythonToCpp_QIcon_Mode;
    return 0;
}
static PyObject* QIcon_Mode_CppToPython_QIcon_Mode(const void* cppIn) {
    int castCppIn = *((::QIcon::Mode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX], castCppIn);

}

static void QIcon_State_PythonToCpp_QIcon_State(PyObject* pyIn, void* cppOut) {
    *((::QIcon::State*)cppOut) = (::QIcon::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QIcon_State_PythonToCpp_QIcon_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX]))
        return QIcon_State_PythonToCpp_QIcon_State;
    return 0;
}
static PyObject* QIcon_State_CppToPython_QIcon_State(const void* cppIn) {
    int castCppIn = *((::QIcon::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QIcon_PythonToCpp_QIcon_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QIcon_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QIcon_PythonToCpp_QIcon_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QIcon_Type))
        return QIcon_PythonToCpp_QIcon_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QIcon_PTR_CppToPython_QIcon(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QIcon*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QIcon_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QIcon_COPY_CppToPython_QIcon(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QIcon_Type, new ::QIcon(*((::QIcon*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QIcon_PythonToCpp_QIcon_COPY(PyObject* pyIn, void* cppOut) {
    *((::QIcon*)cppOut) = *((::QIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QICON_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QIcon_PythonToCpp_QIcon_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QIcon_Type))
        return QIcon_PythonToCpp_QIcon_COPY;
    return 0;
}

// Implicit conversions.
static void constQPixmapREF_PythonToCpp_QIcon(PyObject* pyIn, void* cppOut) {
    *((::QIcon*)cppOut) = ::QIcon(*((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPixmapREF_PythonToCpp_QIcon_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyIn))
        return constQPixmapREF_PythonToCpp_QIcon;
    return 0;
}

void init_QIcon(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QIcon_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QIcon_TypeAsNumber.nb_rshift = Sbk_QIconFunc___rshift__;
    Sbk_QIcon_TypeAsNumber.nb_lshift = Sbk_QIconFunc___lshift__;
    SBK_NB_BOOL(Sbk_QIcon_TypeAsNumber) = Sbk_QIcon___nb_bool;
    Sbk_QIcon_Type.super.ht_type.tp_as_number = &Sbk_QIcon_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QICON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QIcon_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QIcon", "QIcon",
        &Sbk_QIcon_Type, &Shiboken::callCppDestructor< ::QIcon >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QIcon_Type,
        QIcon_PythonToCpp_QIcon_PTR,
        is_QIcon_PythonToCpp_QIcon_PTR_Convertible,
        QIcon_PTR_CppToPython_QIcon,
        QIcon_COPY_CppToPython_QIcon);

    Shiboken::Conversions::registerConverterName(converter, "QIcon");
    Shiboken::Conversions::registerConverterName(converter, "QIcon*");
    Shiboken::Conversions::registerConverterName(converter, "QIcon&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QIcon).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QIcon_PythonToCpp_QIcon_COPY,
        is_QIcon_PythonToCpp_QIcon_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPixmapREF_PythonToCpp_QIcon,
        is_constQPixmapREF_PythonToCpp_QIcon_Convertible);

    // Initialization of enums.

    // Initialization of enum 'Mode'.
    SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QIcon_Type,
        "Mode",
        "PySide.QtGui.QIcon.Mode",
        "QIcon::Mode");
    if (!SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX],
        &Sbk_QIcon_Type, "Normal", (long) QIcon::Normal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX],
        &Sbk_QIcon_Type, "Disabled", (long) QIcon::Disabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX],
        &Sbk_QIcon_Type, "Active", (long) QIcon::Active))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX],
        &Sbk_QIcon_Type, "Selected", (long) QIcon::Selected))
        return ;
    // Register converter for enum 'QIcon::Mode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX],
            QIcon_Mode_CppToPython_QIcon_Mode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QIcon_Mode_PythonToCpp_QIcon_Mode,
            is_QIcon_Mode_PythonToCpp_QIcon_Mode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICON_MODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QIcon::Mode");
        Shiboken::Conversions::registerConverterName(converter, "Mode");
    }
    // End of 'Mode' enum.

    // Initialization of enum 'State'.
    SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QIcon_Type,
        "State",
        "PySide.QtGui.QIcon.State",
        "QIcon::State");
    if (!SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX],
        &Sbk_QIcon_Type, "On", (long) QIcon::On))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX],
        &Sbk_QIcon_Type, "Off", (long) QIcon::Off))
        return ;
    // Register converter for enum 'QIcon::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX],
            QIcon_State_CppToPython_QIcon_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QIcon_State_PythonToCpp_QIcon_State,
            is_QIcon_State_PythonToCpp_QIcon_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QICON_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QIcon::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.


    qRegisterMetaType< ::QIcon >("QIcon");
    qRegisterMetaType< ::QIcon::Mode >("QIcon::Mode");
    qRegisterMetaType< ::QIcon::State >("QIcon::State");
}
