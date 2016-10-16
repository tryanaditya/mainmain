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

#include "qpalette_wrapper.h"

// Extra includes
#include <qbrush.h>
#include <qcolor.h>
#include <qdatastream.h>
#include <qpalette.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPalette_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPalette >()))
        return -1;

    ::QPalette* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4 || numArgs == 5 || numArgs == 6 || numArgs == 7 || numArgs == 8)
        goto Sbk_QPalette_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "QPalette", 0, 9, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return -1;


    // Overloaded function decisor
    // 0: QPalette()
    // 1: QPalette(Qt::GlobalColor)
    // 2: QPalette(QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
    // 3: QPalette(QColor)
    // 4: QPalette(QColor,QColor)
    // 5: QPalette(QPalette)
    if (numArgs == 0) {
        overloadId = 0; // QPalette()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QPalette(Qt::GlobalColor)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // QPalette(QColor)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 4; // QPalette(QColor,QColor)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArgs[0])))) {
        overloadId = 5; // QPalette(QPalette)
    } else if (numArgs == 9
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[8])))) {
        overloadId = 2; // QPalette(QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPalette_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPalette()
        {

            if (!PyErr_Occurred()) {
                // QPalette()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPalette(Qt::GlobalColor button)
        {
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPalette(Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPalette(const QBrush & windowText, const QBrush & button, const QBrush & light, const QBrush & dark, const QBrush & mid, const QBrush & text, const QBrush & bright_text, const QBrush & base, const QBrush & window)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QBrush cppArg0_local = ::QBrush();
            ::QBrush* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QBrush cppArg1_local = ::QBrush();
            ::QBrush* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QBrush cppArg2_local = ::QBrush();
            ::QBrush* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QBrush cppArg3_local = ::QBrush();
            ::QBrush* cppArg3 = &cppArg3_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!Shiboken::Object::isValid(pyArgs[4]))
                return -1;
            ::QBrush cppArg4_local = ::QBrush();
            ::QBrush* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!Shiboken::Object::isValid(pyArgs[5]))
                return -1;
            ::QBrush cppArg5_local = ::QBrush();
            ::QBrush* cppArg5 = &cppArg5_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[5]))
                pythonToCpp[5](pyArgs[5], &cppArg5_local);
            else
                pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!Shiboken::Object::isValid(pyArgs[6]))
                return -1;
            ::QBrush cppArg6_local = ::QBrush();
            ::QBrush* cppArg6 = &cppArg6_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[6]))
                pythonToCpp[6](pyArgs[6], &cppArg6_local);
            else
                pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!Shiboken::Object::isValid(pyArgs[7]))
                return -1;
            ::QBrush cppArg7_local = ::QBrush();
            ::QBrush* cppArg7 = &cppArg7_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[7]))
                pythonToCpp[7](pyArgs[7], &cppArg7_local);
            else
                pythonToCpp[7](pyArgs[7], &cppArg7);

            if (!Shiboken::Object::isValid(pyArgs[8]))
                return -1;
            ::QBrush cppArg8_local = ::QBrush();
            ::QBrush* cppArg8 = &cppArg8_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[8]))
                pythonToCpp[8](pyArgs[8], &cppArg8_local);
            else
                pythonToCpp[8](pyArgs[8], &cppArg8);


            if (!PyErr_Occurred()) {
                // QPalette(QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette(*cppArg0, *cppArg1, *cppArg2, *cppArg3, *cppArg4, *cppArg5, *cppArg6, *cppArg7, *cppArg8);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QPalette(const QColor & button)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPalette(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QPalette(const QColor & button, const QColor & window)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QPalette(QColor,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QPalette(const QPalette & palette)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPalette cppArg0_local = ::QPalette();
            ::QPalette* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPalette(QPalette)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPalette(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPalette >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPalette_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPalette_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.Qt.GlobalColor", "PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush", "PySide.QtGui.QColor", "PySide.QtGui.QColor, PySide.QtGui.QColor", "PySide.QtGui.QPalette", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette", overloads);
        return -1;
}

static PyObject* Sbk_QPaletteFunc_alternateBase(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // alternateBase()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->alternateBase();
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

static PyObject* Sbk_QPaletteFunc_base(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // base()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->base();
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

static PyObject* Sbk_QPaletteFunc_brightText(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brightText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->brightText();
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

static PyObject* Sbk_QPaletteFunc_brush(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "brush", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: brush(QPalette::ColorGroup,QPalette::ColorRole)const
    // 1: brush(QPalette::ColorRole)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // brush(QPalette::ColorRole)const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // brush(QPalette::ColorGroup,QPalette::ColorRole)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_brush_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // brush(QPalette::ColorGroup cg, QPalette::ColorRole cr) const
        {
            ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QPalette::ColorRole cppArg1 = ((::QPalette::ColorRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // brush(QPalette::ColorGroup,QPalette::ColorRole)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->brush(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
            }
            break;
        }
        case 1: // brush(QPalette::ColorRole cr) const
        {
            ::QPalette::ColorRole cppArg0 = ((::QPalette::ColorRole)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // brush(QPalette::ColorRole)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->brush(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_brush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorRole", "PySide.QtGui.QPalette.ColorRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.brush", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_button(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // button()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->button();
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

static PyObject* Sbk_QPaletteFunc_buttonText(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // buttonText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->buttonText();
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

static PyObject* Sbk_QPaletteFunc_cacheKey(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cacheKey()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qint64 cppResult = const_cast<const ::QPalette*>(cppSelf)->cacheKey();
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

static PyObject* Sbk_QPaletteFunc_color(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "color", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: color(QPalette::ColorGroup,QPalette::ColorRole)const
    // 1: color(QPalette::ColorRole)const
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // color(QPalette::ColorRole)const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // color(QPalette::ColorGroup,QPalette::ColorRole)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_color_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // color(QPalette::ColorGroup cg, QPalette::ColorRole cr) const
        {
            ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QPalette::ColorRole cppArg1 = ((::QPalette::ColorRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // color(QPalette::ColorGroup,QPalette::ColorRole)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QColor & cppResult = const_cast<const ::QPalette*>(cppSelf)->color(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
            }
            break;
        }
        case 1: // color(QPalette::ColorRole cr) const
        {
            ::QPalette::ColorRole cppArg0 = ((::QPalette::ColorRole)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // color(QPalette::ColorRole)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                const QColor & cppResult = const_cast<const ::QPalette*>(cppSelf)->color(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_color_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorRole", "PySide.QtGui.QPalette.ColorRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.color", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_currentColorGroup(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentColorGroup()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPalette::ColorGroup cppResult = const_cast<const ::QPalette*>(cppSelf)->currentColorGroup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPaletteFunc_dark(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dark()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->dark();
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

static PyObject* Sbk_QPaletteFunc_highlight(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // highlight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->highlight();
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

static PyObject* Sbk_QPaletteFunc_highlightedText(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // highlightedText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->highlightedText();
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

static PyObject* Sbk_QPaletteFunc_isBrushSet(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isBrushSet", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isBrushSet(QPalette::ColorGroup,QPalette::ColorRole)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // isBrushSet(QPalette::ColorGroup,QPalette::ColorRole)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_isBrushSet_TypeError;

    // Call function/method
    {
        ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QPalette::ColorRole cppArg1 = ((::QPalette::ColorRole)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isBrushSet(QPalette::ColorGroup,QPalette::ColorRole)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPalette*>(cppSelf)->isBrushSet(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_isBrushSet_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorRole", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.isBrushSet", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_isCopyOf(PyObject* self, PyObject* pyArg)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isCopyOf(QPalette)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
        overloadId = 0; // isCopyOf(QPalette)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_isCopyOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPalette cppArg0_local = ::QPalette();
        ::QPalette* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // isCopyOf(QPalette)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPalette*>(cppSelf)->isCopyOf(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_isCopyOf_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPalette.isCopyOf", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_isEqual(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isEqual", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isEqual(QPalette::ColorGroup,QPalette::ColorGroup)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[1])))) {
        overloadId = 0; // isEqual(QPalette::ColorGroup,QPalette::ColorGroup)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_isEqual_TypeError;

    // Call function/method
    {
        ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QPalette::ColorGroup cppArg1 = ((::QPalette::ColorGroup)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isEqual(QPalette::ColorGroup,QPalette::ColorGroup)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPalette*>(cppSelf)->isEqual(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_isEqual_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorGroup", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.isEqual", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_light(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // light()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->light();
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

static PyObject* Sbk_QPaletteFunc_link(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // link()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->link();
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

static PyObject* Sbk_QPaletteFunc_linkVisited(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // linkVisited()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->linkVisited();
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

static PyObject* Sbk_QPaletteFunc_mid(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // mid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->mid();
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

static PyObject* Sbk_QPaletteFunc_midlight(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // midlight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->midlight();
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

static PyObject* Sbk_QPaletteFunc_resolve(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "resolve", 0, 1, &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: resolve()const
    // 1: resolve(QPalette)const
    // 2: resolve(uint)
    if (numArgs == 0) {
        overloadId = 0; // resolve()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))) {
        overloadId = 2; // resolve(uint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArgs[0])))) {
        overloadId = 1; // resolve(QPalette)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_resolve_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // resolve() const
        {

            if (!PyErr_Occurred()) {
                // resolve()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                uint cppResult = const_cast<const ::QPalette*>(cppSelf)->resolve();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), &cppResult);
            }
            break;
        }
        case 1: // resolve(const QPalette & arg__1) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPalette cppArg0_local = ::QPalette();
            ::QPalette* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // resolve(QPalette)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPalette cppResult = const_cast<const ::QPalette*>(cppSelf)->resolve(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppResult);
            }
            break;
        }
        case 2: // resolve(uint mask)
        {
            uint cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // resolve(uint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->resolve(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPaletteFunc_resolve_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPalette", "unsigned int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.resolve", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_setBrush(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setBrush", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setBrush(QPalette::ColorGroup,QPalette::ColorRole,QBrush)
    // 1: setBrush(QPalette::ColorRole,QBrush)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
        overloadId = 1; // setBrush(QPalette::ColorRole,QBrush)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))) {
        overloadId = 0; // setBrush(QPalette::ColorGroup,QPalette::ColorRole,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_setBrush_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setBrush(QPalette::ColorGroup cg, QPalette::ColorRole cr, const QBrush & brush)
        {
            ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QPalette::ColorRole cppArg1 = ((::QPalette::ColorRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QBrush cppArg2_local = ::QBrush();
            ::QBrush* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setBrush(QPalette::ColorGroup,QPalette::ColorRole,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrush(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setBrush(QPalette::ColorRole cr, const QBrush & brush)
        {
            ::QPalette::ColorRole cppArg0 = ((::QPalette::ColorRole)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QBrush cppArg1_local = ::QBrush();
            ::QBrush* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setBrush(QPalette::ColorRole,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrush(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaletteFunc_setBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorRole, PySide.QtGui.QBrush", "PySide.QtGui.QPalette.ColorRole, PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.setBrush", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_setColor(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColor", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setColor(QPalette::ColorGroup,QPalette::ColorRole,QColor)
    // 1: setColor(QPalette::ColorRole,QColor)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
        overloadId = 1; // setColor(QPalette::ColorRole,QColor)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[2])))) {
        overloadId = 0; // setColor(QPalette::ColorGroup,QPalette::ColorRole,QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_setColor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setColor(QPalette::ColorGroup cg, QPalette::ColorRole cr, const QColor & color)
        {
            ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QPalette::ColorRole cppArg1 = ((::QPalette::ColorRole)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QColor cppArg2_local = ::QColor();
            ::QColor* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // setColor(QPalette::ColorGroup,QPalette::ColorRole,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setColor(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setColor(QPalette::ColorRole cr, const QColor & color)
        {
            ::QPalette::ColorRole cppArg0 = ((::QPalette::ColorRole)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QColor cppArg1_local = ::QColor();
            ::QColor* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // setColor(QPalette::ColorRole,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setColor(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaletteFunc_setColor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QPalette.ColorRole, PySide.QtGui.QColor", "PySide.QtGui.QPalette.ColorRole, PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.setColor", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_setColorGroup(PyObject* self, PyObject* args)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColorGroup", 10, 10, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8]), &(pyArgs[9])))
        return 0;


    // Overloaded function decisor
    // 0: setColorGroup(QPalette::ColorGroup,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
    if (numArgs == 10
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[7])))
        && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[8])))
        && (pythonToCpp[9] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[9])))) {
        overloadId = 0; // setColorGroup(QPalette::ColorGroup,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_setColorGroup_TypeError;

    // Call function/method
    {
        ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QBrush cppArg1_local = ::QBrush();
        ::QBrush* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QBrush cppArg2_local = ::QBrush();
        ::QBrush* cppArg2 = &cppArg2_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!Shiboken::Object::isValid(pyArgs[3]))
            return 0;
        ::QBrush cppArg3_local = ::QBrush();
        ::QBrush* cppArg3 = &cppArg3_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[3]))
            pythonToCpp[3](pyArgs[3], &cppArg3_local);
        else
            pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!Shiboken::Object::isValid(pyArgs[4]))
            return 0;
        ::QBrush cppArg4_local = ::QBrush();
        ::QBrush* cppArg4 = &cppArg4_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[4]))
            pythonToCpp[4](pyArgs[4], &cppArg4_local);
        else
            pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!Shiboken::Object::isValid(pyArgs[5]))
            return 0;
        ::QBrush cppArg5_local = ::QBrush();
        ::QBrush* cppArg5 = &cppArg5_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[5]))
            pythonToCpp[5](pyArgs[5], &cppArg5_local);
        else
            pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!Shiboken::Object::isValid(pyArgs[6]))
            return 0;
        ::QBrush cppArg6_local = ::QBrush();
        ::QBrush* cppArg6 = &cppArg6_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[6]))
            pythonToCpp[6](pyArgs[6], &cppArg6_local);
        else
            pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!Shiboken::Object::isValid(pyArgs[7]))
            return 0;
        ::QBrush cppArg7_local = ::QBrush();
        ::QBrush* cppArg7 = &cppArg7_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[7]))
            pythonToCpp[7](pyArgs[7], &cppArg7_local);
        else
            pythonToCpp[7](pyArgs[7], &cppArg7);

        if (!Shiboken::Object::isValid(pyArgs[8]))
            return 0;
        ::QBrush cppArg8_local = ::QBrush();
        ::QBrush* cppArg8 = &cppArg8_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[8]))
            pythonToCpp[8](pyArgs[8], &cppArg8_local);
        else
            pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!Shiboken::Object::isValid(pyArgs[9]))
            return 0;
        ::QBrush cppArg9_local = ::QBrush();
        ::QBrush* cppArg9 = &cppArg9_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[9]))
            pythonToCpp[9](pyArgs[9], &cppArg9_local);
        else
            pythonToCpp[9](pyArgs[9], &cppArg9);


        if (!PyErr_Occurred()) {
            // setColorGroup(QPalette::ColorGroup,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColorGroup(cppArg0, *cppArg1, *cppArg2, *cppArg3, *cppArg4, *cppArg5, *cppArg6, *cppArg7, *cppArg8, *cppArg9);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaletteFunc_setColorGroup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush, PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPalette.setColorGroup", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_setCurrentColorGroup(PyObject* self, PyObject* pyArg)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentColorGroup(QPalette::ColorGroup)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]), (pyArg)))) {
        overloadId = 0; // setCurrentColorGroup(QPalette::ColorGroup)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc_setCurrentColorGroup_TypeError;

    // Call function/method
    {
        ::QPalette::ColorGroup cppArg0 = ((::QPalette::ColorGroup)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentColorGroup(QPalette::ColorGroup)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentColorGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPaletteFunc_setCurrentColorGroup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPalette.ColorGroup", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPalette.setCurrentColorGroup", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc_shadow(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shadow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->shadow();
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

static PyObject* Sbk_QPaletteFunc_text(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->text();
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

static PyObject* Sbk_QPaletteFunc_toolTipBase(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTipBase()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->toolTipBase();
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

static PyObject* Sbk_QPaletteFunc_toolTipText(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTipText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->toolTipText();
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

static PyObject* Sbk_QPaletteFunc_window(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // window()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->window();
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

static PyObject* Sbk_QPaletteFunc_windowText(PyObject* self)
{
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // windowText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPalette*>(cppSelf)->windowText();
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

static PyObject* Sbk_QPalette___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPalette& cppSelf = *(((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPalette_methods[] = {
    {"alternateBase", (PyCFunction)Sbk_QPaletteFunc_alternateBase, METH_NOARGS},
    {"base", (PyCFunction)Sbk_QPaletteFunc_base, METH_NOARGS},
    {"brightText", (PyCFunction)Sbk_QPaletteFunc_brightText, METH_NOARGS},
    {"brush", (PyCFunction)Sbk_QPaletteFunc_brush, METH_VARARGS},
    {"button", (PyCFunction)Sbk_QPaletteFunc_button, METH_NOARGS},
    {"buttonText", (PyCFunction)Sbk_QPaletteFunc_buttonText, METH_NOARGS},
    {"cacheKey", (PyCFunction)Sbk_QPaletteFunc_cacheKey, METH_NOARGS},
    {"color", (PyCFunction)Sbk_QPaletteFunc_color, METH_VARARGS},
    {"currentColorGroup", (PyCFunction)Sbk_QPaletteFunc_currentColorGroup, METH_NOARGS},
    {"dark", (PyCFunction)Sbk_QPaletteFunc_dark, METH_NOARGS},
    {"highlight", (PyCFunction)Sbk_QPaletteFunc_highlight, METH_NOARGS},
    {"highlightedText", (PyCFunction)Sbk_QPaletteFunc_highlightedText, METH_NOARGS},
    {"isBrushSet", (PyCFunction)Sbk_QPaletteFunc_isBrushSet, METH_VARARGS},
    {"isCopyOf", (PyCFunction)Sbk_QPaletteFunc_isCopyOf, METH_O},
    {"isEqual", (PyCFunction)Sbk_QPaletteFunc_isEqual, METH_VARARGS},
    {"light", (PyCFunction)Sbk_QPaletteFunc_light, METH_NOARGS},
    {"link", (PyCFunction)Sbk_QPaletteFunc_link, METH_NOARGS},
    {"linkVisited", (PyCFunction)Sbk_QPaletteFunc_linkVisited, METH_NOARGS},
    {"mid", (PyCFunction)Sbk_QPaletteFunc_mid, METH_NOARGS},
    {"midlight", (PyCFunction)Sbk_QPaletteFunc_midlight, METH_NOARGS},
    {"resolve", (PyCFunction)Sbk_QPaletteFunc_resolve, METH_VARARGS},
    {"setBrush", (PyCFunction)Sbk_QPaletteFunc_setBrush, METH_VARARGS},
    {"setColor", (PyCFunction)Sbk_QPaletteFunc_setColor, METH_VARARGS},
    {"setColorGroup", (PyCFunction)Sbk_QPaletteFunc_setColorGroup, METH_VARARGS},
    {"setCurrentColorGroup", (PyCFunction)Sbk_QPaletteFunc_setCurrentColorGroup, METH_O},
    {"shadow", (PyCFunction)Sbk_QPaletteFunc_shadow, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QPaletteFunc_text, METH_NOARGS},
    {"toolTipBase", (PyCFunction)Sbk_QPaletteFunc_toolTipBase, METH_NOARGS},
    {"toolTipText", (PyCFunction)Sbk_QPaletteFunc_toolTipText, METH_NOARGS},
    {"window", (PyCFunction)Sbk_QPaletteFunc_window, METH_NOARGS},
    {"windowText", (PyCFunction)Sbk_QPaletteFunc_windowText, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QPalette___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QPaletteFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QPalette)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPalette)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPalette) [reverse operator]
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

    Sbk_QPaletteFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPalette.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPaletteFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPalette* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QPalette&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPalette&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPaletteFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPalette&) [reverse operator]
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

    Sbk_QPaletteFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPalette.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QPalette_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPalette& cppSelf = *(((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
                // operator!=(const QPalette & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPalette cppArg0_local = ::QPalette();
                ::QPalette* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf != (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_True;
                Py_INCREF(pyResult);
            }

            break;
        case Py_EQ:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyArg)))) {
                // operator==(const QPalette & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPalette cppArg0_local = ::QPalette();
                ::QPalette* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], pythonToCpp))
                    pythonToCpp(pyArg, &cppArg0_local);
                else
                    pythonToCpp(pyArg, &cppArg0);

                bool cppResult = cppSelf == (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                pyResult = Py_False;
                Py_INCREF(pyResult);
            }

            break;
        default:
            goto Sbk_QPalette_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPalette_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QPalette_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPalette_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPalette_TypeAsNumber;

static SbkObjectType Sbk_QPalette_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPalette",
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
    /*tp_traverse*/         Sbk_QPalette_traverse,
    /*tp_clear*/            Sbk_QPalette_clear,
    /*tp_richcompare*/      Sbk_QPalette_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPalette_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPalette_Init,
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
static void QPalette_ColorGroup_PythonToCpp_QPalette_ColorGroup(PyObject* pyIn, void* cppOut) {
    *((::QPalette::ColorGroup*)cppOut) = (::QPalette::ColorGroup) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPalette_ColorGroup_PythonToCpp_QPalette_ColorGroup_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]))
        return QPalette_ColorGroup_PythonToCpp_QPalette_ColorGroup;
    return 0;
}
static PyObject* QPalette_ColorGroup_CppToPython_QPalette_ColorGroup(const void* cppIn) {
    int castCppIn = *((::QPalette::ColorGroup*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX], castCppIn);

}

static void QPalette_ColorRole_PythonToCpp_QPalette_ColorRole(PyObject* pyIn, void* cppOut) {
    *((::QPalette::ColorRole*)cppOut) = (::QPalette::ColorRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPalette_ColorRole_PythonToCpp_QPalette_ColorRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]))
        return QPalette_ColorRole_PythonToCpp_QPalette_ColorRole;
    return 0;
}
static PyObject* QPalette_ColorRole_CppToPython_QPalette_ColorRole(const void* cppIn) {
    int castCppIn = *((::QPalette::ColorRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPalette_PythonToCpp_QPalette_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPalette_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPalette_PythonToCpp_QPalette_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPalette_Type))
        return QPalette_PythonToCpp_QPalette_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPalette_PTR_CppToPython_QPalette(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPalette*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPalette_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPalette_COPY_CppToPython_QPalette(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPalette_Type, new ::QPalette(*((::QPalette*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPalette_PythonToCpp_QPalette_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPalette*)cppOut) = *((::QPalette*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPalette_PythonToCpp_QPalette_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPalette_Type))
        return QPalette_PythonToCpp_QPalette_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_Qt_GlobalColor_PythonToCpp_QPalette(PyObject* pyIn, void* cppOut) {
    ::Qt::GlobalColor cppIn = ((::Qt::GlobalColor)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), pyIn, &cppIn);
    *((::QPalette*)cppOut) = ::QPalette(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QPalette_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], pyIn))
        return PySide_QtCore_Qt_GlobalColor_PythonToCpp_QPalette;
    return 0;
}

static void constQColorREF_PythonToCpp_QPalette(PyObject* pyIn, void* cppOut) {
    *((::QPalette*)cppOut) = ::QPalette(*((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQColorREF_PythonToCpp_QPalette_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pyIn))
        return constQColorREF_PythonToCpp_QPalette;
    return 0;
}

void init_QPalette(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPalette_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPalette_TypeAsNumber.nb_rshift = Sbk_QPaletteFunc___rshift__;
    Sbk_QPalette_TypeAsNumber.nb_lshift = Sbk_QPaletteFunc___lshift__;
    Sbk_QPalette_Type.super.ht_type.tp_as_number = &Sbk_QPalette_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPalette_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPalette", "QPalette",
        &Sbk_QPalette_Type, &Shiboken::callCppDestructor< ::QPalette >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPalette_Type,
        QPalette_PythonToCpp_QPalette_PTR,
        is_QPalette_PythonToCpp_QPalette_PTR_Convertible,
        QPalette_PTR_CppToPython_QPalette,
        QPalette_COPY_CppToPython_QPalette);

    Shiboken::Conversions::registerConverterName(converter, "QPalette");
    Shiboken::Conversions::registerConverterName(converter, "QPalette*");
    Shiboken::Conversions::registerConverterName(converter, "QPalette&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPalette).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPalette_PythonToCpp_QPalette_COPY,
        is_QPalette_PythonToCpp_QPalette_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_GlobalColor_PythonToCpp_QPalette,
        is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QPalette_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQColorREF_PythonToCpp_QPalette,
        is_constQColorREF_PythonToCpp_QPalette_Convertible);

    // Initialization of enums.

    // Initialization of enum 'ColorGroup'.
    SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPalette_Type,
        "ColorGroup",
        "PySide.QtGui.QPalette.ColorGroup",
        "QPalette::ColorGroup");
    if (!SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "Active", (long) QPalette::Active))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "Disabled", (long) QPalette::Disabled))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "Inactive", (long) QPalette::Inactive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "NColorGroups", (long) QPalette::NColorGroups))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "Current", (long) QPalette::Current))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "All", (long) QPalette::All))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
        &Sbk_QPalette_Type, "Normal", (long) QPalette::Normal))
        return ;
    // Register converter for enum 'QPalette::ColorGroup'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX],
            QPalette_ColorGroup_CppToPython_QPalette_ColorGroup);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPalette_ColorGroup_PythonToCpp_QPalette_ColorGroup,
            is_QPalette_ColorGroup_PythonToCpp_QPalette_ColorGroup_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPalette::ColorGroup");
        Shiboken::Conversions::registerConverterName(converter, "ColorGroup");
    }
    // End of 'ColorGroup' enum.

    // Initialization of enum 'ColorRole'.
    SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPalette_Type,
        "ColorRole",
        "PySide.QtGui.QPalette.ColorRole",
        "QPalette::ColorRole");
    if (!SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "WindowText", (long) QPalette::WindowText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Button", (long) QPalette::Button))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Light", (long) QPalette::Light))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Midlight", (long) QPalette::Midlight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Dark", (long) QPalette::Dark))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Mid", (long) QPalette::Mid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Text", (long) QPalette::Text))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "BrightText", (long) QPalette::BrightText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "ButtonText", (long) QPalette::ButtonText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Base", (long) QPalette::Base))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Window", (long) QPalette::Window))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Shadow", (long) QPalette::Shadow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Highlight", (long) QPalette::Highlight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "HighlightedText", (long) QPalette::HighlightedText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Link", (long) QPalette::Link))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "LinkVisited", (long) QPalette::LinkVisited))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "AlternateBase", (long) QPalette::AlternateBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "NoRole", (long) QPalette::NoRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "ToolTipBase", (long) QPalette::ToolTipBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "ToolTipText", (long) QPalette::ToolTipText))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "NColorRoles", (long) QPalette::NColorRoles))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Foreground", (long) QPalette::Foreground))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
        &Sbk_QPalette_Type, "Background", (long) QPalette::Background))
        return ;
    // Register converter for enum 'QPalette::ColorRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX],
            QPalette_ColorRole_CppToPython_QPalette_ColorRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPalette_ColorRole_PythonToCpp_QPalette_ColorRole,
            is_QPalette_ColorRole_PythonToCpp_QPalette_ColorRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPalette::ColorRole");
        Shiboken::Conversions::registerConverterName(converter, "ColorRole");
    }
    // End of 'ColorRole' enum.


    qRegisterMetaType< ::QPalette >("QPalette");
    qRegisterMetaType< ::QPalette::ColorGroup >("QPalette::ColorGroup");
    qRegisterMetaType< ::QPalette::ColorRole >("QPalette::ColorRole");
}
