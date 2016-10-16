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

#include "qpen_wrapper.h"

// Extra includes
#include <QBrush>
#include <QVector>
#include <qbrush.h>
#include <qcolor.h>
#include <qdatastream.h>
#include <qpen.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPen_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPen >()))
        return -1;

    ::QPen* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPen(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QPen", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QPen()
    // 1: QPen(Qt::PenStyle)
    // 2: QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
    // 3: QPen(QColor)
    // 4: QPen(QPen)
    if (numArgs == 0) {
        overloadId = 0; // QPen()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QPen(Qt::PenStyle)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        overloadId = 3; // QPen(QColor)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[0])))) {
        overloadId = 4; // QPen(QPen)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 2; // QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), (pyArgs[4])))) {
                    overloadId = 2; // QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPen_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPen()
        {

            if (!PyErr_Occurred()) {
                // QPen()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPen();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPen(Qt::PenStyle arg__1)
        {
            ::Qt::PenStyle cppArg0 = ((::Qt::PenStyle)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPen(Qt::PenStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPen(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QPen(const QBrush & brush, qreal width, Qt::PenStyle s, Qt::PenCapStyle c, Qt::PenJoinStyle j)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "s");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPen(): got multiple values for keyword argument 's'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArgs[2]))))
                        goto Sbk_QPen_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "c");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPen(): got multiple values for keyword argument 'c'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), (pyArgs[3]))))
                        goto Sbk_QPen_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "j");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPen(): got multiple values for keyword argument 'j'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), (pyArgs[4]))))
                        goto Sbk_QPen_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QBrush cppArg0_local = ::QBrush();
            ::QBrush* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::Qt::PenStyle cppArg2 = Qt::SolidLine;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::PenCapStyle cppArg3 = Qt::SquareCap;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::PenJoinStyle cppArg4 = Qt::BevelJoin;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QPen(QBrush,qreal,Qt::PenStyle,Qt::PenCapStyle,Qt::PenJoinStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPen(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QPen(const QColor & color)
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
                // QPen(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPen(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QPen(const QPen & pen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPen cppArg0_local = ::QPen();
            ::QPen* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QPen(QPen)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPen(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPen >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPen_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPen_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.Qt.PenStyle", "PySide.QtGui.QBrush, float, PySide.QtCore.Qt.PenStyle = Qt.SolidLine, PySide.QtCore.Qt.PenCapStyle = Qt.SquareCap, PySide.QtCore.Qt.PenJoinStyle = Qt.BevelJoin", "PySide.QtGui.QColor", "PySide.QtGui.QPen", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPen", overloads);
        return -1;
}

static PyObject* Sbk_QPenFunc_brush(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QPen*>(cppSelf)->brush();
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

static PyObject* Sbk_QPenFunc_capStyle(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // capStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::PenCapStyle cppResult = const_cast<const ::QPen*>(cppSelf)->capStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPenFunc_color(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // color()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QColor cppResult = const_cast<const ::QPen*>(cppSelf)->color();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPenFunc_dashOffset(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dashOffset()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPen*>(cppSelf)->dashOffset();
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

static PyObject* Sbk_QPenFunc_dashPattern(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // dashPattern()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVector<qreal > cppResult = const_cast<const ::QPen*>(cppSelf)->dashPattern();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPenFunc_isCosmetic(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCosmetic()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPen*>(cppSelf)->isCosmetic();
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

static PyObject* Sbk_QPenFunc_isSolid(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSolid()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPen*>(cppSelf)->isSolid();
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

static PyObject* Sbk_QPenFunc_joinStyle(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // joinStyle()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::PenJoinStyle cppResult = const_cast<const ::QPen*>(cppSelf)->joinStyle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPenFunc_miterLimit(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // miterLimit()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPen*>(cppSelf)->miterLimit();
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

static PyObject* Sbk_QPenFunc_setBrush(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setBrush_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBrush(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBrush(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setBrush_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setBrush", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setCapStyle(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCapStyle(Qt::PenCapStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENCAPSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setCapStyle(Qt::PenCapStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setCapStyle_TypeError;

    // Call function/method
    {
        ::Qt::PenCapStyle cppArg0 = ((::Qt::PenCapStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCapStyle(Qt::PenCapStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCapStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setCapStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenCapStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setCapStyle", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setColor(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColor(QColor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 0; // setColor(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setColor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QColor cppArg0_local = ::QColor();
        ::QColor* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setColor(QColor)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColor(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setColor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setColor", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setCosmetic(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCosmetic(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCosmetic(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setCosmetic_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCosmetic(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCosmetic(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setCosmetic_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setCosmetic", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setDashOffset(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDashOffset(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setDashOffset(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setDashOffset_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDashOffset(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDashOffset(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setDashOffset_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setDashOffset", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setDashPattern(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDashPattern(QVector<qreal>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QREAL_IDX], (pyArg)))) {
        overloadId = 0; // setDashPattern(QVector<qreal>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setDashPattern_TypeError;

    // Call function/method
    {
        ::QVector<qreal > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDashPattern(QVector<qreal>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDashPattern(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setDashPattern_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setDashPattern", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setJoinStyle(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setJoinStyle(Qt::PenJoinStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENJOINSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setJoinStyle(Qt::PenJoinStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setJoinStyle_TypeError;

    // Call function/method
    {
        ::Qt::PenJoinStyle cppArg0 = ((::Qt::PenJoinStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setJoinStyle(Qt::PenJoinStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setJoinStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setJoinStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenJoinStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setJoinStyle", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setMiterLimit(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMiterLimit(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMiterLimit(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setMiterLimit_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMiterLimit(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMiterLimit(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setMiterLimit_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setMiterLimit", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(Qt::PenStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setStyle(Qt::PenStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setStyle_TypeError;

    // Call function/method
    {
        ::Qt::PenStyle cppArg0 = ((::Qt::PenStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyle(Qt::PenStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setWidth(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidth(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setWidth(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidth(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setWidth", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_setWidthF(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidthF(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setWidthF(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_setWidthF_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidthF(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidthF(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_setWidthF_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.setWidthF", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_style(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::PenStyle cppResult = const_cast<const ::QPen*>(cppSelf)->style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPenFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QPen&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArg)))) {
        overloadId = 0; // swap(QPen&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc_swap_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPen cppArg0_local = ::QPen();
        ::QPen* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // swap(QPen&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPenFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPen", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.swap", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc_width(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QPen*>(cppSelf)->width();
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

static PyObject* Sbk_QPenFunc_widthF(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widthF()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPen*>(cppSelf)->widthF();
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

static PyObject* Sbk_QPen___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPen& cppSelf = *(((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPen_methods[] = {
    {"brush", (PyCFunction)Sbk_QPenFunc_brush, METH_NOARGS},
    {"capStyle", (PyCFunction)Sbk_QPenFunc_capStyle, METH_NOARGS},
    {"color", (PyCFunction)Sbk_QPenFunc_color, METH_NOARGS},
    {"dashOffset", (PyCFunction)Sbk_QPenFunc_dashOffset, METH_NOARGS},
    {"dashPattern", (PyCFunction)Sbk_QPenFunc_dashPattern, METH_NOARGS},
    {"isCosmetic", (PyCFunction)Sbk_QPenFunc_isCosmetic, METH_NOARGS},
    {"isSolid", (PyCFunction)Sbk_QPenFunc_isSolid, METH_NOARGS},
    {"joinStyle", (PyCFunction)Sbk_QPenFunc_joinStyle, METH_NOARGS},
    {"miterLimit", (PyCFunction)Sbk_QPenFunc_miterLimit, METH_NOARGS},
    {"setBrush", (PyCFunction)Sbk_QPenFunc_setBrush, METH_O},
    {"setCapStyle", (PyCFunction)Sbk_QPenFunc_setCapStyle, METH_O},
    {"setColor", (PyCFunction)Sbk_QPenFunc_setColor, METH_O},
    {"setCosmetic", (PyCFunction)Sbk_QPenFunc_setCosmetic, METH_O},
    {"setDashOffset", (PyCFunction)Sbk_QPenFunc_setDashOffset, METH_O},
    {"setDashPattern", (PyCFunction)Sbk_QPenFunc_setDashPattern, METH_O},
    {"setJoinStyle", (PyCFunction)Sbk_QPenFunc_setJoinStyle, METH_O},
    {"setMiterLimit", (PyCFunction)Sbk_QPenFunc_setMiterLimit, METH_O},
    {"setStyle", (PyCFunction)Sbk_QPenFunc_setStyle, METH_O},
    {"setWidth", (PyCFunction)Sbk_QPenFunc_setWidth, METH_O},
    {"setWidthF", (PyCFunction)Sbk_QPenFunc_setWidthF, METH_O},
    {"style", (PyCFunction)Sbk_QPenFunc_style, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QPenFunc_swap, METH_O},
    {"width", (PyCFunction)Sbk_QPenFunc_width, METH_NOARGS},
    {"widthF", (PyCFunction)Sbk_QPenFunc_widthF, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QPen___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QPenFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QPen)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QPen)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QPen) [reverse operator]
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

    Sbk_QPenFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QPenFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QPen&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QPen&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPenFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QPen&) [reverse operator]
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

    Sbk_QPenFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPen.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QPen_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPen& cppSelf = *(((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArg)))) {
                // operator!=(const QPen & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPen cppArg0_local = ::QPen();
                ::QPen* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArg)))) {
                // operator==(const QPen & p) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPen cppArg0_local = ::QPen();
                ::QPen* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp))
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
            goto Sbk_QPen_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPen_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QPen_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPen_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QPen__repr__(PyObject* self)
{
    ::QPen* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << *cppSelf;
    buffer.close();
    QByteArray str = buffer.data();
    int idx = str.indexOf('(');
    if (idx >= 0)
        str.replace(0, idx, Py_TYPE(self)->tp_name);
    PyObject* mod = PyDict_GetItemString(Py_TYPE(self)->tp_dict, "__module__");
    if (mod)
        return Shiboken::String::fromFormat("<%s.%s at %p>", Shiboken::String::toCString(mod), str.constData(), self);
    else
        return Shiboken::String::fromFormat("<%s at %p>", str.constData(), self);
}
} // extern C

// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QPen_TypeAsNumber;

static SbkObjectType Sbk_QPen_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPen",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QPen__repr__,
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
    /*tp_traverse*/         Sbk_QPen_traverse,
    /*tp_clear*/            Sbk_QPen_clear,
    /*tp_richcompare*/      Sbk_QPen_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPen_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPen_Init,
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
static void QPen_PythonToCpp_QPen_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPen_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPen_PythonToCpp_QPen_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPen_Type))
        return QPen_PythonToCpp_QPen_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPen_PTR_CppToPython_QPen(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPen*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPen_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QPen_COPY_CppToPython_QPen(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPen_Type, new ::QPen(*((::QPen*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QPen_PythonToCpp_QPen_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPen*)cppOut) = *((::QPen*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QPen_PythonToCpp_QPen_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPen_Type))
        return QPen_PythonToCpp_QPen_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_Qt_PenStyle_PythonToCpp_QPen(PyObject* pyIn, void* cppOut) {
    ::Qt::PenStyle cppIn = ((::Qt::PenStyle)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), pyIn, &cppIn);
    *((::QPen*)cppOut) = ::QPen(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_PenStyle_PythonToCpp_QPen_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX], pyIn))
        return PySide_QtCore_Qt_PenStyle_PythonToCpp_QPen;
    return 0;
}

static void constQColorREF_PythonToCpp_QPen(PyObject* pyIn, void* cppOut) {
    *((::QPen*)cppOut) = ::QPen(*((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQColorREF_PythonToCpp_QPen_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pyIn))
        return constQColorREF_PythonToCpp_QPen;
    return 0;
}

void init_QPen(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QPen_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QPen_TypeAsNumber.nb_rshift = Sbk_QPenFunc___rshift__;
    Sbk_QPen_TypeAsNumber.nb_lshift = Sbk_QPenFunc___lshift__;
    Sbk_QPen_Type.super.ht_type.tp_as_number = &Sbk_QPen_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QPEN_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPen_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPen", "QPen",
        &Sbk_QPen_Type, &Shiboken::callCppDestructor< ::QPen >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPen_Type,
        QPen_PythonToCpp_QPen_PTR,
        is_QPen_PythonToCpp_QPen_PTR_Convertible,
        QPen_PTR_CppToPython_QPen,
        QPen_COPY_CppToPython_QPen);

    Shiboken::Conversions::registerConverterName(converter, "QPen");
    Shiboken::Conversions::registerConverterName(converter, "QPen*");
    Shiboken::Conversions::registerConverterName(converter, "QPen&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPen).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QPen_PythonToCpp_QPen_COPY,
        is_QPen_PythonToCpp_QPen_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_PenStyle_PythonToCpp_QPen,
        is_PySide_QtCore_Qt_PenStyle_PythonToCpp_QPen_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQColorREF_PythonToCpp_QPen,
        is_constQColorREF_PythonToCpp_QPen_Convertible);


    qRegisterMetaType< ::QPen >("QPen");
}
