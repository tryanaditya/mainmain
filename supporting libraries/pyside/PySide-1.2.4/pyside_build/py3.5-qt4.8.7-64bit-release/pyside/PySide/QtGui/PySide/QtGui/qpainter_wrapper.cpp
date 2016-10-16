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

#include "qpainter_wrapper.h"
#include "qpainter_pixmapfragment_wrapper.h"

// Extra includes
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
#include <QVector>
#include <QWidget>
#include <qbrush.h>
#include <qcolor.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qimage.h>
#include <qline.h>
#include <qmatrix.h>
#include <qpaintdevice.h>
#include <qpaintengine.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qpen.h>
#include <qpicture.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qpolygon.h>
#include <qrect.h>
#include <qregion.h>
#include <qtextoption.h>
#include <qtransform.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPainter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPainter >()))
        return -1;

    ::QPainter* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QPainter", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QPainter()
    // 1: QPainter(QPaintDevice*)
    if (numArgs == 0) {
        overloadId = 0; // QPainter()
    } else if (numArgs == 1
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[0]))))) {
        overloadId = 1; // QPainter(QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QPainter()
        {

            if (!PyErr_Occurred()) {
                // QPainter()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainter();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QPainter(QPaintDevice * arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPaintDevice* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QPainter(QPaintDevice*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainter(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPainter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPainter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPainter_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter", overloads);
        return -1;
}

static PyObject* Sbk_QPainterFunc_background(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // background()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPainter*>(cppSelf)->background();
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

static PyObject* Sbk_QPainterFunc_backgroundMode(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // backgroundMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::BGMode cppResult = const_cast<const ::QPainter*>(cppSelf)->backgroundMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_begin(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: begin(QPaintDevice*)
    if ((pyArg != Py_None && (pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg))))) {
        overloadId = 0; // begin(QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_begin_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // begin(QPaintDevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->begin(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterFunc_begin_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.begin", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_beginNativePainting(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beginNativePainting()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->beginNativePainting();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_boundingRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.boundingRect(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.boundingRect(): not enough arguments");
        return 0;
    } else if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterFunc_boundingRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOO:boundingRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: boundingRect(QRect,int,QString)
    // 1: boundingRect(QRectF,QString,QTextOption)
    // 2: boundingRect(QRectF,int,QString)
    // 3: boundingRect(int,int,int,int,int,QString)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
        overloadId = 3; // boundingRect(int,int,int,int,int,QString)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // boundingRect(QRect,int,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 2; // boundingRect(QRectF,int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // boundingRect(QRectF,QString,QTextOption)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArgs[2])))) {
                overloadId = 1; // boundingRect(QRectF,QString,QTextOption)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_boundingRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // boundingRect(const QRect & rect, int flags, const QString & text)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // boundingRect(QRect,int,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = cppSelf->boundingRect(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
        case 1: // boundingRect(const QRectF & rect, const QString & text, const QTextOption & o)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "o");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.boundingRect(): got multiple values for keyword argument 'o'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArgs[2]))))
                        goto Sbk_QPainterFunc_boundingRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextOption cppArg2_local = QTextOption();
            ::QTextOption* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // boundingRect(QRectF,QString,QTextOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = cppSelf->boundingRect(*cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 2: // boundingRect(const QRectF & rect, int flags, const QString & text)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // boundingRect(QRectF,int,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRectF cppResult = cppSelf->boundingRect(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
            }
            break;
        }
        case 3: // boundingRect(int x, int y, int w, int h, int flags, const QString & text)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QString cppArg5 = ::QString();
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // boundingRect(int,int,int,int,int,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QRect cppResult = cppSelf->boundingRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterFunc_boundingRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, unicode", "PySide.QtCore.QRectF, unicode, PySide.QtGui.QTextOption = QTextOption()", "PySide.QtCore.QRectF, int, unicode", "int, int, int, int, int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.boundingRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_brush(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brush()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QBrush & cppResult = const_cast<const ::QPainter*>(cppSelf)->brush();
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

static PyObject* Sbk_QPainterFunc_brushOrigin(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // brushOrigin()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPoint cppResult = const_cast<const ::QPainter*>(cppSelf)->brushOrigin();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_clipBoundingRect(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipBoundingRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QPainter*>(cppSelf)->clipBoundingRect();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_clipPath(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipPath()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainterPath cppResult = const_cast<const ::QPainter*>(cppSelf)->clipPath();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_clipRegion(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clipRegion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRegion cppResult = const_cast<const ::QPainter*>(cppSelf)->clipRegion();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_combinedMatrix(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // combinedMatrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMatrix cppResult = const_cast<const ::QPainter*>(cppSelf)->combinedMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_combinedTransform(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // combinedTransform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QPainter*>(cppSelf)->combinedTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_compositionMode(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // compositionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainter::CompositionMode cppResult = const_cast<const ::QPainter*>(cppSelf)->compositionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_device(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // device()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintDevice * cppResult = const_cast<const ::QPainter*>(cppSelf)->device();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_deviceMatrix(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceMatrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMatrix & cppResult = const_cast<const ::QPainter*>(cppSelf)->deviceMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_deviceTransform(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // deviceTransform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QTransform & cppResult = const_cast<const ::QPainter*>(cppSelf)->deviceTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_drawArc(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterFunc_drawArc_TypeError;

    if (!PyArg_UnpackTuple(args, "drawArc", 3, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: drawArc(QRect,int,int)
    // 1: drawArc(QRectF,int,int)
    // 2: drawArc(int,int,int,int,int,int)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        overloadId = 2; // drawArc(int,int,int,int,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // drawArc(QRect,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // drawArc(QRectF,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawArc_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawArc(const QRect & arg__1, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawArc(QRect,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawArc(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawArc(const QRectF & rect, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawArc(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawArc(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawArc(int x, int y, int w, int h, int a, int alen)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // drawArc(int,int,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawArc(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawArc_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, int", "PySide.QtCore.QRectF, int, int", "int, int, int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawArc", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawChord(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterFunc_drawChord_TypeError;

    if (!PyArg_UnpackTuple(args, "drawChord", 3, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: drawChord(QRect,int,int)
    // 1: drawChord(QRectF,int,int)
    // 2: drawChord(int,int,int,int,int,int)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        overloadId = 2; // drawChord(int,int,int,int,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // drawChord(QRect,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // drawChord(QRectF,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawChord_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawChord(const QRect & arg__1, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawChord(QRect,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawChord(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawChord(const QRectF & rect, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawChord(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawChord(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawChord(int x, int y, int w, int h, int a, int alen)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // drawChord(int,int,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawChord(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawChord_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, int", "PySide.QtCore.QRectF, int, int", "int, int, int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawChord", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawConvexPolygon(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawConvexPolygon(QVector<QPoint>)
    // 1: drawConvexPolygon(QVector<QPointF>)
    // 2: drawConvexPolygon(QPolygon)
    // 3: drawConvexPolygon(QPolygonF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // drawConvexPolygon(QVector<QPoint>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArg)))) {
        overloadId = 2; // drawConvexPolygon(QPolygon)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 1; // drawConvexPolygon(QVector<QPointF>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 3; // drawConvexPolygon(QPolygonF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawConvexPolygon_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawConvexPolygon(QVector<QPoint > arg__1)
        {
            ::QVector<QPoint > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawConvexPolygon(QVector<QPoint>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawConvexPolygon(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 1: // drawConvexPolygon(QVector<QPointF > arg__1)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawConvexPolygon(QVector<QPointF>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawConvexPolygon(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 2: // drawConvexPolygon(const QPolygon & polygon)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawConvexPolygon(QPolygon)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawConvexPolygon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawConvexPolygon(const QPolygonF & polygon)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawConvexPolygon(QPolygonF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawConvexPolygon(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawConvexPolygon_TypeError:
        const char* overloads[] = {"list", "list", "PySide.QtGui.QPolygon", "PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawConvexPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawEllipse(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QPainterFunc_drawEllipse_TypeError;

    if (!PyArg_UnpackTuple(args, "drawEllipse", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawEllipse(QPoint,int,int)
    // 1: drawEllipse(QPointF,qreal,qreal)
    // 2: drawEllipse(QRect)
    // 3: drawEllipse(QRectF)
    // 4: drawEllipse(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 4; // drawEllipse(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 2; // drawEllipse(QRect)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 3; // drawEllipse(QRectF)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // drawEllipse(QPoint,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        overloadId = 1; // drawEllipse(QPointF,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawEllipse_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawEllipse(const QPoint & center, int rx, int ry)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawEllipse(QPoint,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawEllipse(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawEllipse(const QPointF & center, qreal rx, qreal ry)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawEllipse(QPointF,qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawEllipse(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawEllipse(const QRect & r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawEllipse(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawEllipse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawEllipse(const QRectF & r)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawEllipse(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawEllipse(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // drawEllipse(int x, int y, int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawEllipse(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawEllipse(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawEllipse_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, int, int", "PySide.QtCore.QPointF, float, float", "PySide.QtCore.QRect", "PySide.QtCore.QRectF", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawEllipse", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawImage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 8) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOO:drawImage", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return 0;


    // Overloaded function decisor
    // 0: drawImage(QPoint,QImage)
    // 1: drawImage(QPoint,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
    // 2: drawImage(QPointF,QImage)
    // 3: drawImage(QPointF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
    // 4: drawImage(QRect,QImage)
    // 5: drawImage(QRect,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
    // 6: drawImage(QRectF,QImage)
    // 7: drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
    // 8: drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            if (numArgs == 4) {
                overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
                if (numArgs == 5) {
                    overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
                } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                    if (numArgs == 6) {
                        overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
                    } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
                        if (numArgs == 7) {
                            overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
                        } else if ((pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[7])))) {
                            overloadId = 8; // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
                        }
                    }
                }
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // drawImage(QRect,QImage)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 5; // drawImage(QRect,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 5; // drawImage(QRect,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 6; // drawImage(QRectF,QImage)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 7; // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 7; // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // drawImage(QPoint,QImage)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // drawImage(QPoint,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 1; // drawImage(QPoint,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // drawImage(QPointF,QImage)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 3; // drawImage(QPointF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3])))) {
                overloadId = 3; // drawImage(QPointF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawImage_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawImage(const QPoint & p, const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawImage(QPoint,QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawImage(const QPoint & p, const QImage & image, const QRect & sr, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRect cppArg2_local = ::QRect();
            ::QRect* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QFlags<Qt::ImageConversionFlag> cppArg3 = Qt::AutoColor;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawImage(QPoint,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawImage(const QPointF & p, const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawImage(QPointF,QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawImage(const QPointF & p, const QImage & image, const QRectF & sr, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRectF cppArg2_local = ::QRectF();
            ::QRectF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QFlags<Qt::ImageConversionFlag> cppArg3 = Qt::AutoColor;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawImage(QPointF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // drawImage(const QRect & r, const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawImage(QRect,QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // drawImage(const QRect & targetRect, const QImage & image, const QRect & sourceRect, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRect cppArg2_local = ::QRect();
            ::QRect* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QFlags<Qt::ImageConversionFlag> cppArg3 = Qt::AutoColor;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawImage(QRect,QImage,QRect,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // drawImage(const QRectF & r, const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawImage(QRectF,QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // drawImage(const QRectF & targetRect, const QImage & image, const QRectF & sourceRect, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QImage cppArg1_local = ::QImage();
            ::QImage* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRectF cppArg2_local = ::QRectF();
            ::QRectF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QFlags<Qt::ImageConversionFlag> cppArg3 = Qt::AutoColor;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawImage(QRectF,QImage,QRectF,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(*cppArg0, *cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // drawImage(int x, int y, const QImage & image, int sx, int sy, int sw, int sh, QFlags<Qt::ImageConversionFlag> flags)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "sx");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'sx'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sy");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'sy'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sw");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'sw'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sh");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'sh'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
                value = PyDict_GetItemString(kwds, "flags");
                if (value && pyArgs[7]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawImage(): got multiple values for keyword argument 'flags'.");
                    return 0;
                } else if (value) {
                    pyArgs[7] = value;
                    if (!(pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_IMAGECONVERSIONFLAG__IDX]), (pyArgs[7]))))
                        goto Sbk_QPainterFunc_drawImage_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QImage cppArg2_local = ::QImage();
            ::QImage* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 0;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5 = -1;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            int cppArg6 = -1;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);
            ::QFlags<Qt::ImageConversionFlag> cppArg7 = Qt::AutoColor;
            if (pythonToCpp[7]) pythonToCpp[7](pyArgs[7], &cppArg7);

            if (!PyErr_Occurred()) {
                // drawImage(int,int,QImage,int,int,int,int,QFlags<Qt::ImageConversionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawImage(cppArg0, cppArg1, *cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawImage_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtGui.QImage", "PySide.QtCore.QPoint, PySide.QtGui.QImage, PySide.QtCore.QRect, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtCore.QPointF, PySide.QtGui.QImage", "PySide.QtCore.QPointF, PySide.QtGui.QImage, PySide.QtCore.QRectF, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtCore.QRect, PySide.QtGui.QImage", "PySide.QtCore.QRect, PySide.QtGui.QImage, PySide.QtCore.QRect, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "PySide.QtCore.QRectF, PySide.QtGui.QImage", "PySide.QtCore.QRectF, PySide.QtGui.QImage, PySide.QtCore.QRectF, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", "int, int, PySide.QtGui.QImage, int = 0, int = 0, int = -1, int = -1, PySide.QtCore.Qt.ImageConversionFlags = Qt.AutoColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawImage", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawLine(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3)
        goto Sbk_QPainterFunc_drawLine_TypeError;

    if (!PyArg_UnpackTuple(args, "drawLine", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawLine(QLine)
    // 1: drawLine(QLineF)
    // 2: drawLine(QPoint,QPoint)
    // 3: drawLine(QPointF,QPointF)
    // 4: drawLine(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 4; // drawLine(int,int,int,int)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[1])))) {
        overloadId = 2; // drawLine(QPoint,QPoint)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[1])))) {
        overloadId = 3; // drawLine(QPointF,QPointF)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], (pyArgs[0])))) {
        overloadId = 0; // drawLine(QLine)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], (pyArgs[0])))) {
        overloadId = 1; // drawLine(QLineF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawLine_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawLine(const QLine & line)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLine cppArg0_local = ::QLine();
            ::QLine* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawLine(QLine)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLine(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawLine(const QLineF & line)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QLineF cppArg0_local = ::QLineF();
            ::QLineF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QLINEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawLine(QLineF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLine(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawLine(const QPoint & p1, const QPoint & p2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPoint cppArg1_local = ::QPoint();
            ::QPoint* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawLine(QPoint,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLine(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawLine(const QPointF & p1, const QPointF & p2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPointF cppArg1_local = ::QPointF();
            ::QPointF* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawLine(QPointF,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLine(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // drawLine(int x1, int y1, int x2, int y2)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawLine(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLine(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawLine_TypeError:
        const char* overloads[] = {"PySide.QtCore.QLine", "PySide.QtCore.QLineF", "PySide.QtCore.QPoint, PySide.QtCore.QPoint", "PySide.QtCore.QPointF, PySide.QtCore.QPointF", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawLine", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawLines(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawLines(QVector<QLine>)
    // 1: drawLines(QVector<QLineF>)
    // 2: drawLines(QVector<QPoint>)
    // 3: drawLines(QVector<QPointF>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], (pyArg)))) {
        overloadId = 2; // drawLines(QVector<QPoint>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 3; // drawLines(QVector<QPointF>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINE_IDX], (pyArg)))) {
        overloadId = 0; // drawLines(QVector<QLine>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QLINEF_IDX], (pyArg)))) {
        overloadId = 1; // drawLines(QVector<QLineF>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawLines_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawLines(const QVector<QLine > & lines)
        {
            ::QVector<QLine > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawLines(QVector<QLine>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLines(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawLines(const QVector<QLineF > & lines)
        {
            ::QVector<QLineF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawLines(QVector<QLineF>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLines(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawLines(const QVector<QPoint > & pointPairs)
        {
            ::QVector<QPoint > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawLines(QVector<QPoint>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLines(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawLines(const QVector<QPointF > & pointPairs)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawLines(QVector<QPointF>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawLines(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawLines_TypeError:
        const char* overloads[] = {"list", "list", "list", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawLines", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPath(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawPath(QPainterPath)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArg)))) {
        overloadId = 0; // drawPath(QPainterPath)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // drawPath(QPainterPath)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->drawPath(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawPath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPicture(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawPicture", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawPicture(QPoint,QPicture)
    // 1: drawPicture(QPointF,QPicture)
    // 2: drawPicture(int,int,QPicture)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (pyArgs[2])))) {
        overloadId = 2; // drawPicture(int,int,QPicture)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawPicture(QPoint,QPicture)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], (pyArgs[1])))) {
        overloadId = 1; // drawPicture(QPointF,QPicture)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPicture_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPicture(const QPoint & p, const QPicture & picture)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPicture cppArg1_local = ::QPicture(((int)0));
            ::QPicture* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawPicture(QPoint,QPicture)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPicture(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPicture(const QPointF & p, const QPicture & picture)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPicture cppArg1_local = ::QPicture(((int)0));
            ::QPicture* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawPicture(QPointF,QPicture)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPicture(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawPicture(int x, int y, const QPicture & picture)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPicture cppArg2_local = ::QPicture(((int)0));
            ::QPicture* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPICTURE_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPicture(int,int,QPicture)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPicture(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPicture_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtGui.QPicture", "PySide.QtCore.QPointF, PySide.QtGui.QPicture", "int, int, PySide.QtGui.QPicture", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPicture", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPie(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterFunc_drawPie_TypeError;

    if (!PyArg_UnpackTuple(args, "drawPie", 3, 6, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: drawPie(QRect,int,int)
    // 1: drawPie(QRectF,int,int)
    // 2: drawPie(int,int,int,int,int,int)
    if (numArgs == 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
        overloadId = 2; // drawPie(int,int,int,int,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // drawPie(QRect,int,int)
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 1; // drawPie(QRectF,int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPie_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPie(const QRect & arg__1, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawPie(QRect,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPie(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPie(const QRectF & rect, int a, int alen)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawPie(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPie(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawPie(int x, int y, int w, int h, int a, int alen)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // drawPie(int,int,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPie(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPie_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int, int", "PySide.QtCore.QRectF, int, int", "int, int, int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPie", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPixmap(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 4 || numArgs == 6 || numArgs == 8)
        goto Sbk_QPainterFunc_drawPixmap_TypeError;

    if (!PyArg_UnpackTuple(args, "drawPixmap", 2, 9, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return 0;


    // Overloaded function decisor
    // 0: drawPixmap(QPoint,QPixmap)
    // 1: drawPixmap(QPoint,QPixmap,QRect)
    // 2: drawPixmap(QPointF,QPixmap)
    // 3: drawPixmap(QPointF,QPixmap,QRectF)
    // 4: drawPixmap(QRect,QPixmap)
    // 5: drawPixmap(QRect,QPixmap,QRect)
    // 6: drawPixmap(QRectF,QPixmap,QRectF)
    // 7: drawPixmap(int,int,QPixmap)
    // 8: drawPixmap(int,int,QPixmap,int,int,int,int)
    // 9: drawPixmap(int,int,int,int,QPixmap)
    // 10: drawPixmap(int,int,int,int,QPixmap,int,int,int,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs >= 5
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 9; // drawPixmap(int,int,int,int,QPixmap)
            } else if (numArgs == 9
                && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))
                && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))
                && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[7])))
                && (pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[8])))) {
                overloadId = 10; // drawPixmap(int,int,int,int,QPixmap,int,int,int,int)
            }
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 7; // drawPixmap(int,int,QPixmap)
            } else if (numArgs == 7
                && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
                && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
                && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))
                && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
                overloadId = 8; // drawPixmap(int,int,QPixmap,int,int,int,int)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 4; // drawPixmap(QRect,QPixmap)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
            overloadId = 5; // drawPixmap(QRect,QPixmap,QRect)
        }
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
        overloadId = 6; // drawPixmap(QRectF,QPixmap,QRectF)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // drawPixmap(QPoint,QPixmap)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[2])))) {
            overloadId = 1; // drawPixmap(QPoint,QPixmap,QRect)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // drawPixmap(QPointF,QPixmap)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[2])))) {
            overloadId = 3; // drawPixmap(QPointF,QPixmap,QRectF)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPixmap_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPixmap(const QPoint & p, const QPixmap & pm)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawPixmap(QPoint,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPixmap(const QPoint & p, const QPixmap & pm, const QRect & sr)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRect cppArg2_local = ::QRect();
            ::QRect* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPixmap(QPoint,QPixmap,QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawPixmap(const QPointF & p, const QPixmap & pm)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawPixmap(QPointF,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawPixmap(const QPointF & p, const QPixmap & pm, const QRectF & sr)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRectF cppArg2_local = ::QRectF();
            ::QRectF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPixmap(QPointF,QPixmap,QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // drawPixmap(const QRect & r, const QPixmap & pm)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // drawPixmap(QRect,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // drawPixmap(const QRect & targetRect, const QPixmap & pixmap, const QRect & sourceRect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRect cppArg2_local = ::QRect();
            ::QRect* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPixmap(QRect,QPixmap,QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // drawPixmap(const QRectF & targetRect, const QPixmap & pixmap, const QRectF & sourceRect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QRectF cppArg2_local = ::QRectF();
            ::QRectF* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPixmap(QRectF,QPixmap,QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // drawPixmap(int x, int y, const QPixmap & pm)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPixmap cppArg2_local = ::QPixmap();
            ::QPixmap* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);


            if (!PyErr_Occurred()) {
                // drawPixmap(int,int,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // drawPixmap(int x, int y, const QPixmap & pm, int sx, int sy, int sw, int sh)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPixmap cppArg2_local = ::QPixmap();
            ::QPixmap* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            int cppArg6;
            pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // drawPixmap(int,int,QPixmap,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(cppArg0, cppArg1, *cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // drawPixmap(int x, int y, int w, int h, const QPixmap & pm)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPixmap cppArg4_local = ::QPixmap();
            ::QPixmap* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);


            if (!PyErr_Occurred()) {
                // drawPixmap(int,int,int,int,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // drawPixmap(int x, int y, int w, int h, const QPixmap & pm, int sx, int sy, int sw, int sh)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPixmap cppArg4_local = ::QPixmap();
            ::QPixmap* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);

            int cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            int cppArg6;
            pythonToCpp[6](pyArgs[6], &cppArg6);
            int cppArg7;
            pythonToCpp[7](pyArgs[7], &cppArg7);
            int cppArg8;
            pythonToCpp[8](pyArgs[8], &cppArg8);

            if (!PyErr_Occurred()) {
                // drawPixmap(int,int,int,int,QPixmap,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmap(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtGui.QPixmap", "PySide.QtCore.QPoint, PySide.QtGui.QPixmap, PySide.QtCore.QRect", "PySide.QtCore.QPointF, PySide.QtGui.QPixmap", "PySide.QtCore.QPointF, PySide.QtGui.QPixmap, PySide.QtCore.QRectF", "PySide.QtCore.QRect, PySide.QtGui.QPixmap", "PySide.QtCore.QRect, PySide.QtGui.QPixmap, PySide.QtCore.QRect", "PySide.QtCore.QRectF, PySide.QtGui.QPixmap, PySide.QtCore.QRectF", "int, int, PySide.QtGui.QPixmap", "int, int, PySide.QtGui.QPixmap, int, int, int, int", "int, int, int, int, PySide.QtGui.QPixmap", "int, int, int, int, PySide.QtGui.QPixmap, int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPixmapFragments(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPixmapFragments(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPixmapFragments(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:drawPixmapFragments", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: drawPixmapFragments(const QPainter::PixmapFragment*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
    // 1: drawPixmapFragments(const QRectF*,const QRectF*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 1; // drawPixmapFragments(const QRectF*,const QRectF*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), (pyArgs[4])))) {
            overloadId = 1; // drawPixmapFragments(const QRectF*,const QRectF*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
        }
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawPixmapFragments(const QPainter::PixmapFragment*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), (pyArgs[3])))) {
            overloadId = 0; // drawPixmapFragments(const QPainter::PixmapFragment*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPixmapFragments_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPixmapFragments(const QPainter::PixmapFragment * fragments, int fragmentCount, const QPixmap & pixmap, QFlags<QPainter::PixmapFragmentHint> hints)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "hints");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPixmapFragments(): got multiple values for keyword argument 'hints'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawPixmapFragments_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPainter::PixmapFragment* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPixmap cppArg2_local = ::QPixmap();
            ::QPixmap* cppArg2 = &cppArg2_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);

            ::QFlags<QPainter::PixmapFragmentHint> cppArg3 = QFlags<QPainter::PixmapFragmentHint>(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawPixmapFragments(const QPainter::PixmapFragment*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmapFragments(cppArg0, cppArg1, *cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPixmapFragments(const QRectF * targetRects, const QRectF * sourceRects, int fragmentCount, const QPixmap & pixmap, QFlags<QPainter::PixmapFragmentHint> hints)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "hints");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPixmapFragments(): got multiple values for keyword argument 'hints'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), (pyArgs[4]))))
                        goto Sbk_QPainterFunc_drawPixmapFragments_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QRectF* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return 0;
            ::QPixmap cppArg3_local = ::QPixmap();
            ::QPixmap* cppArg3 = &cppArg3_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[3]))
                pythonToCpp[3](pyArgs[3], &cppArg3_local);
            else
                pythonToCpp[3](pyArgs[3], &cppArg3);

            ::QFlags<QPainter::PixmapFragmentHint> cppArg4 = QFlags<QPainter::PixmapFragmentHint>(0);
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // drawPixmapFragments(const QRectF*,const QRectF*,int,QPixmap,QFlags<QPainter::PixmapFragmentHint>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPixmapFragments(cppArg0, cppArg1, cppArg2, *cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPixmapFragments_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter::PixmapFragment, int, PySide.QtGui.QPixmap, PySide.QtGui.QPainter.PixmapFragmentHints = 0", "PySide.QtCore.QRectF, PySide.QtCore.QRectF, int, PySide.QtGui.QPixmap, PySide.QtGui.QPainter.PixmapFragmentHints = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPixmapFragments", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPoint(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawPoint", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawPoint(QPoint)
    // 1: drawPoint(QPointF)
    // 2: drawPoint(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 2; // drawPoint(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // drawPoint(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // drawPoint(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPoint_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPoint(const QPoint & p)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPoint(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoint(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawPoint(const QPointF & pt)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPoint(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoint(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawPoint(int x, int y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawPoint(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoint(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPoint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPoint", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPoints(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawPoints(QVector<QPoint>)
    // 1: drawPoints(QVector<QPointF>)
    // 2: drawPoints(QPolygon)
    // 3: drawPoints(QPolygonF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // drawPoints(QVector<QPoint>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArg)))) {
        overloadId = 2; // drawPoints(QPolygon)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 1; // drawPoints(QVector<QPointF>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 3; // drawPoints(QPolygonF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPoints_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPoints(QVector<QPoint > arg__1)
        {
            ::QVector<QPoint > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawPoints(QVector<QPoint>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoints(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 1: // drawPoints(QVector<QPointF > arg__1)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawPoints(QVector<QPointF>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoints(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 2: // drawPoints(const QPolygon & points)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPoints(QPolygon)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoints(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawPoints(const QPolygonF & points)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPoints(QPolygonF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPoints(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPoints_TypeError:
        const char* overloads[] = {"list", "list", "PySide.QtGui.QPolygon", "PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawPoints", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPolygon(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPolygon(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPolygon(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:drawPolygon", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: drawPolygon(QVector<QPoint>,Qt::FillRule)
    // 1: drawPolygon(QVector<QPointF>,Qt::FillRule)
    // 2: drawPolygon(QPolygon,Qt::FillRule)
    // 3: drawPolygon(QPolygonF,Qt::FillRule)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // drawPolygon(QVector<QPoint>,Qt::FillRule)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // drawPolygon(QPolygon,Qt::FillRule)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1])))) {
            overloadId = 2; // drawPolygon(QPolygon,Qt::FillRule)
        }
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1])))) {
        overloadId = 1; // drawPolygon(QVector<QPointF>,Qt::FillRule)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 3; // drawPolygon(QPolygonF,Qt::FillRule)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1])))) {
            overloadId = 3; // drawPolygon(QPolygonF,Qt::FillRule)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPolygon_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPolygon(QVector<QPoint > arg__1, Qt::FillRule arg__2)
        {
            ::QVector<QPoint > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            ::Qt::FillRule cppArg1 = ((::Qt::FillRule)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // drawPolygon(QVector<QPoint>,Qt::FillRule)
                // Begin code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolygon(cppArg0.data(), cppArg0.size(), cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // End of code injection


            }
            break;
        }
        case 1: // drawPolygon(QVector<QPointF > arg__1, Qt::FillRule arg__2)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            SBK_UNUSED(cppArg0)
            ::Qt::FillRule cppArg1 = ((::Qt::FillRule)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)

            if (!PyErr_Occurred()) {
                // drawPolygon(QVector<QPointF>,Qt::FillRule)
                // Begin code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolygon(cppArg0.data(), cppArg0.size(), cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                // End of code injection


            }
            break;
        }
        case 2: // drawPolygon(const QPolygon & polygon, Qt::FillRule fillRule)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fillRule");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPolygon(): got multiple values for keyword argument 'fillRule'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_drawPolygon_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::FillRule cppArg1 = Qt::OddEvenFill;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawPolygon(QPolygon,Qt::FillRule)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolygon(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawPolygon(const QPolygonF & polygon, Qt::FillRule fillRule)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fillRule");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawPolygon(): got multiple values for keyword argument 'fillRule'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_FILLRULE_IDX]), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_drawPolygon_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::FillRule cppArg1 = Qt::OddEvenFill;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawPolygon(QPolygonF,Qt::FillRule)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolygon(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPolygon_TypeError:
        const char* overloads[] = {"list, PySide.QtCore.Qt.FillRule", "list, PySide.QtCore.Qt.FillRule", "PySide.QtGui.QPolygon, PySide.QtCore.Qt.FillRule = Qt.OddEvenFill", "PySide.QtGui.QPolygonF, PySide.QtCore.Qt.FillRule = Qt.OddEvenFill", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawPolygon", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawPolyline(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawPolyline(QVector<QPoint>)
    // 1: drawPolyline(QVector<QPointF>)
    // 2: drawPolyline(QPolygon)
    // 3: drawPolyline(QPolygonF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINT_IDX], (pyArg)))) {
        overloadId = 0; // drawPolyline(QVector<QPoint>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], (pyArg)))) {
        overloadId = 2; // drawPolyline(QPolygon)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QPOINTF_IDX], (pyArg)))) {
        overloadId = 1; // drawPolyline(QVector<QPointF>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], (pyArg)))) {
        overloadId = 3; // drawPolyline(QPolygonF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawPolyline_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawPolyline(QVector<QPoint > arg__1)
        {
            ::QVector<QPoint > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawPolyline(QVector<QPoint>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolyline(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 1: // drawPolyline(QVector<QPointF > arg__1)
        {
            ::QVector<QPointF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);
            SBK_UNUSED(cppArg0)

            if (!PyErr_Occurred()) {
                // drawPolyline(QVector<QPointF>)
                // Begin code injection

                // TEMPLATE - qpainter_drawlist - START
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolyline(cppArg0.data(), cppArg0.size());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                // TEMPLATE - qpainter_drawlist - END

                // End of code injection


            }
            break;
        }
        case 2: // drawPolyline(const QPolygon & polygon)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygon cppArg0_local = ::QPolygon();
            ::QPolygon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGON_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPolyline(QPolygon)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolyline(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // drawPolyline(const QPolygonF & polyline)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QPolygonF cppArg0_local = ::QPolygonF();
            ::QPolygonF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPOLYGONF_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // drawPolyline(QPolygonF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawPolyline(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawPolyline_TypeError:
        const char* overloads[] = {"list", "list", "PySide.QtGui.QPolygon", "PySide.QtGui.QPolygonF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawPolyline", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawRect(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPainterFunc_drawRect_TypeError;

    if (!PyArg_UnpackTuple(args, "drawRect", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: drawRect(QRect)
    // 1: drawRect(QRectF)
    // 2: drawRect(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 2; // drawRect(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // drawRect(QRect)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // drawRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawRect(const QRect & rect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawRect(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawRect(const QRectF & rect)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // drawRect(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawRect(int x1, int y1, int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawRect(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRect(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "PySide.QtCore.QRectF", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawRects(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: drawRects(QVector<QRect>)
    // 1: drawRects(QVector<QRectF>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECT_IDX], (pyArg)))) {
        overloadId = 0; // drawRects(QVector<QRect>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QVECTOR_QRECTF_IDX], (pyArg)))) {
        overloadId = 1; // drawRects(QVector<QRectF>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawRects_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawRects(const QVector<QRect > & rectangles)
        {
            ::QVector<QRect > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawRects(QVector<QRect>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRects(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawRects(const QVector<QRectF > & rectangles)
        {
            ::QVector<QRectF > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // drawRects(QVector<QRectF>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRects(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawRects_TypeError:
        const char* overloads[] = {"list", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.drawRects", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawRoundRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:drawRoundRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: drawRoundRect(QRect,int,int)
    // 1: drawRoundRect(QRectF,int,int)
    // 2: drawRoundRect(int,int,int,int,int,int)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 2; // drawRoundRect(int,int,int,int,int,int)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 2; // drawRoundRect(int,int,int,int,int,int)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
                overloadId = 2; // drawRoundRect(int,int,int,int,int,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // drawRoundRect(QRect,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // drawRoundRect(QRect,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // drawRoundRect(QRect,int,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // drawRoundRect(QRectF,int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // drawRoundRect(QRectF,int,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // drawRoundRect(QRectF,int,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawRoundRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawRoundRect(const QRect & r, int xround, int yround)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xround");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'xround'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "yround");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'yround'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = 25;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 25;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawRoundRect(QRect,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundRect(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawRoundRect(const QRectF & r, int xround, int yround)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xround");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'xround'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "yround");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'yround'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1 = 25;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 25;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawRoundRect(QRectF,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundRect(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawRoundRect(int x, int y, int w, int h, int xRound, int yRound)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "xRound");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'xRound'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
                value = PyDict_GetItemString(kwds, "yRound");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundRect(): got multiple values for keyword argument 'yRound'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QPainterFunc_drawRoundRect_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4 = 25;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
            int cppArg5 = 25;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // drawRoundRect(int,int,int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawRoundRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, int = 25, int = 25", "PySide.QtCore.QRectF, int = 25, int = 25", "int, int, int, int, int = 25, int = 25", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawRoundRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawRoundedRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundedRect(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundedRect(): not enough arguments");
        return 0;
    } else if (numArgs == 5)
        goto Sbk_QPainterFunc_drawRoundedRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOO:drawRoundedRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: drawRoundedRect(QRect,qreal,qreal,Qt::SizeMode)
    // 1: drawRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
    // 2: drawRoundedRect(int,int,int,int,qreal,qreal,Qt::SizeMode)
    if (numArgs >= 6
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
        if (numArgs == 6) {
            overloadId = 2; // drawRoundedRect(int,int,int,int,qreal,qreal,Qt::SizeMode)
        } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[6])))) {
            overloadId = 2; // drawRoundedRect(int,int,int,int,qreal,qreal,Qt::SizeMode)
        }
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // drawRoundedRect(QRect,qreal,qreal,Qt::SizeMode)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3])))) {
            overloadId = 0; // drawRoundedRect(QRect,qreal,qreal,Qt::SizeMode)
        }
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 1; // drawRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3])))) {
            overloadId = 1; // drawRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawRoundedRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawRoundedRect(const QRect & rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundedRect(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawRoundedRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::SizeMode cppArg3 = Qt::AbsoluteSize;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawRoundedRect(QRect,qreal,qreal,Qt::SizeMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundedRect(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawRoundedRect(const QRectF & rect, qreal xRadius, qreal yRadius, Qt::SizeMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundedRect(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[3]))))
                        goto Sbk_QPainterFunc_drawRoundedRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            qreal cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::Qt::SizeMode cppArg3 = Qt::AbsoluteSize;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // drawRoundedRect(QRectF,qreal,qreal,Qt::SizeMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundedRect(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawRoundedRect(int x, int y, int w, int h, qreal xRadius, qreal yRadius, Qt::SizeMode mode)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "mode");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawRoundedRect(): got multiple values for keyword argument 'mode'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEMODE_IDX]), (pyArgs[6]))))
                        goto Sbk_QPainterFunc_drawRoundedRect_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            qreal cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            qreal cppArg5;
            pythonToCpp[5](pyArgs[5], &cppArg5);
            ::Qt::SizeMode cppArg6 = Qt::AbsoluteSize;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // drawRoundedRect(int,int,int,int,qreal,qreal,Qt::SizeMode)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawRoundedRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawRoundedRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, float, float, PySide.QtCore.Qt.SizeMode = Qt.AbsoluteSize", "PySide.QtCore.QRectF, float, float, PySide.QtCore.Qt.SizeMode = Qt.AbsoluteSize", "int, int, int, int, float, float, PySide.QtCore.Qt.SizeMode = Qt.AbsoluteSize", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawRoundedRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawText(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawText(): not enough arguments");
        return 0;
    } else if (numArgs == 4 || numArgs == 5)
        goto Sbk_QPainterFunc_drawText_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOO:drawText", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: drawText(QPoint,QString)
    // 1: drawText(QPointF,QString)
    // 2: drawText(QRect,int,QString,QRect*)
    // 3: drawText(QRectF,QString,QTextOption)
    // 4: drawText(QRectF,int,QString,QRectF*)
    // 5: drawText(int,int,QString)
    // 6: drawText(int,int,int,int,int,QString,QRect*)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 6
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))
            && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
            overloadId = 6; // drawText(int,int,int,int,int,QString,QRect*)
        } else if (numArgs == 3
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 5; // drawText(int,int,QString)
        }
    } else if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 2; // drawText(QRect,int,QString,QRect*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 4; // drawText(QRectF,int,QString,QRectF*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // drawText(QRectF,QString,QTextOption)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArgs[2])))) {
                overloadId = 3; // drawText(QRectF,QString,QTextOption)
            }
        }
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawText(QPoint,QString)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // drawText(QPointF,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawText_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawText(const QPoint & p, const QString & s)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawText(QPoint,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 1: // drawText(const QPointF & p, const QString & s)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawText(QPointF,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 2: // drawText(const QRect & r, int flags, const QString & text, QRect * br)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawText(QRect,int,QString,QRect*)
                // Begin code injection

                // TEMPLATE - fix_args,QRect* - START
                QRect rect_;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(*cppArg0, cppArg1, cppArg2, &rect_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect_);
                // TEMPLATE - fix_args,QRect* - END

                // End of code injection


            }
            break;
        }
        case 3: // drawText(const QRectF & r, const QString & text, const QTextOption & o)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "o");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawText(): got multiple values for keyword argument 'o'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], (pyArgs[2]))))
                        goto Sbk_QPainterFunc_drawText_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextOption cppArg2_local = QTextOption();
            ::QTextOption* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTOPTION_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // drawText(QRectF,QString,QTextOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(*cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 4: // drawText(const QRectF & r, int flags, const QString & text, QRectF * br)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawText(QRectF,int,QString,QRectF*)
                // Begin code injection

                // TEMPLATE - fix_args,QRectF* - START
                QRectF rect_;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(*cppArg0, cppArg1, cppArg2, &rect_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &rect_);
                // TEMPLATE - fix_args,QRectF* - END

                // End of code injection


            }
            break;
        }
        case 5: // drawText(int x, int y, const QString & s)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = ::QString();
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawText(int,int,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Py_None;
                Py_INCREF(Py_None);
            }
            break;
        }
        case 6: // drawText(int x, int y, int w, int h, int flags, const QString & text, QRect * br)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QString cppArg5 = ::QString();
            pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // drawText(int,int,int,int,int,QString,QRect*)
                // Begin code injection

                // TEMPLATE - fix_args,QRect* - START
                QRect rect_;
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawText(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, &rect_);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &rect_);
                // TEMPLATE - fix_args,QRect* - END

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

    Sbk_QPainterFunc_drawText_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, unicode", "PySide.QtCore.QPointF, unicode", "PySide.QtCore.QRect, int, unicode, PySide.QtCore.QRect", "PySide.QtCore.QRectF, unicode, PySide.QtGui.QTextOption = QTextOption()", "PySide.QtCore.QRectF, int, unicode, PySide.QtCore.QRectF", "int, int, unicode", "int, int, int, int, int, unicode, PySide.QtCore.QRect", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawText", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawTextItem(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "drawTextItem", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: drawTextItem(QPoint,QTextItem)
    // 1: drawTextItem(QPointF,QTextItem)
    // 2: drawTextItem(int,int,QTextItem)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (pyArgs[2])))) {
        overloadId = 2; // drawTextItem(int,int,QTextItem)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // drawTextItem(QPoint,QTextItem)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTEXTITEM_IDX], (pyArgs[1])))) {
        overloadId = 1; // drawTextItem(QPointF,QTextItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawTextItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawTextItem(const QPoint & p, const QTextItem & ti)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawTextItem(QPoint,QTextItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTextItem(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawTextItem(const QPointF & p, const QTextItem & ti)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QTextItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // drawTextItem(QPointF,QTextItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTextItem(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawTextItem(int x, int y, const QTextItem & ti)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QTextItem* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // drawTextItem(int,int,QTextItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTextItem(cppArg0, cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawTextItem_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint, PySide.QtGui.QTextItem", "PySide.QtCore.QPointF, PySide.QtGui.QTextItem", "int, int, PySide.QtGui.QTextItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawTextItem", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_drawTiledPixmap(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 7) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): not enough arguments");
        return 0;
    } else if (numArgs == 4)
        goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOOOO:drawTiledPixmap", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return 0;


    // Overloaded function decisor
    // 0: drawTiledPixmap(QRect,QPixmap,QPoint)
    // 1: drawTiledPixmap(QRectF,QPixmap,QPointF)
    // 2: drawTiledPixmap(int,int,int,int,QPixmap,int,int)
    if (numArgs >= 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[4])))) {
        if (numArgs == 5) {
            overloadId = 2; // drawTiledPixmap(int,int,int,int,QPixmap,int,int)
        } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5])))) {
            if (numArgs == 6) {
                overloadId = 2; // drawTiledPixmap(int,int,int,int,QPixmap,int,int)
            } else if ((pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6])))) {
                overloadId = 2; // drawTiledPixmap(int,int,int,int,QPixmap,int,int)
            }
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // drawTiledPixmap(QRect,QPixmap,QPoint)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))) {
            overloadId = 0; // drawTiledPixmap(QRect,QPixmap,QPoint)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // drawTiledPixmap(QRectF,QPixmap,QPointF)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2])))) {
            overloadId = 1; // drawTiledPixmap(QRectF,QPixmap,QPointF)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // drawTiledPixmap(const QRect & arg__1, const QPixmap & arg__2, const QPoint & pos)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "pos");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): got multiple values for keyword argument 'pos'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2]))))
                        goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPoint cppArg2_local = QPoint();
            ::QPoint* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // drawTiledPixmap(QRect,QPixmap,QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTiledPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // drawTiledPixmap(const QRectF & rect, const QPixmap & pm, const QPointF & offset)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "offset");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): got multiple values for keyword argument 'offset'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[2]))))
                        goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QPointF cppArg2_local = QPointF();
            ::QPointF* cppArg2 = &cppArg2_local;
            if (pythonToCpp[2]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[2]))
                pythonToCpp[2](pyArgs[2], &cppArg2_local);
            else
                pythonToCpp[2](pyArgs[2], &cppArg2);
            }

            if (!PyErr_Occurred()) {
                // drawTiledPixmap(QRectF,QPixmap,QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTiledPixmap(*cppArg0, *cppArg1, *cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // drawTiledPixmap(int x, int y, int w, int h, const QPixmap & arg__5, int sx, int sy)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "sx");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): got multiple values for keyword argument 'sx'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[5]))))
                        goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;
                }
                value = PyDict_GetItemString(kwds, "sy");
                if (value && pyArgs[6]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.drawTiledPixmap(): got multiple values for keyword argument 'sy'.");
                    return 0;
                } else if (value) {
                    pyArgs[6] = value;
                    if (!(pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[6]))))
                        goto Sbk_QPainterFunc_drawTiledPixmap_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QPixmap cppArg4_local = ::QPixmap();
            ::QPixmap* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);

            int cppArg5 = 0;
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);
            int cppArg6 = 0;
            if (pythonToCpp[6]) pythonToCpp[6](pyArgs[6], &cppArg6);

            if (!PyErr_Occurred()) {
                // drawTiledPixmap(int,int,int,int,QPixmap,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->drawTiledPixmap(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4, cppArg5, cppArg6);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_drawTiledPixmap_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, PySide.QtGui.QPixmap, PySide.QtCore.QPoint = QPoint()", "PySide.QtCore.QRectF, PySide.QtGui.QPixmap, PySide.QtCore.QPointF = QPointF()", "int, int, int, int, PySide.QtGui.QPixmap, int = 0, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.drawTiledPixmap", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_end(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // end()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->end();
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

static PyObject* Sbk_QPainterFunc_endNativePainting(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endNativePainting()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->endNativePainting();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_eraseRect(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPainterFunc_eraseRect_TypeError;

    if (!PyArg_UnpackTuple(args, "eraseRect", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: eraseRect(QRect)
    // 1: eraseRect(QRectF)
    // 2: eraseRect(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 2; // eraseRect(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // eraseRect(QRect)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // eraseRect(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_eraseRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // eraseRect(const QRect & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // eraseRect(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->eraseRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // eraseRect(const QRectF & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // eraseRect(QRectF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->eraseRect(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // eraseRect(int x, int y, int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // eraseRect(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->eraseRect(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_eraseRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "PySide.QtCore.QRectF", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.eraseRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_fillPath(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fillPath", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fillPath(QPainterPath,QBrush)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
        overloadId = 0; // fillPath(QPainterPath,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_fillPath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
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
            // fillPath(QPainterPath,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->fillPath(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_fillPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath, PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.fillPath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_fillRect(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_QPainterFunc_fillRect_TypeError;

    if (!PyArg_UnpackTuple(args, "fillRect", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: fillRect(QRect,QBrush)
    // 1: fillRect(QRect,QColor)
    // 2: fillRect(QRect,Qt::BrushStyle)
    // 3: fillRect(QRect,Qt::GlobalColor)
    // 4: fillRect(QRectF,QBrush)
    // 5: fillRect(QRectF,QColor)
    // 6: fillRect(QRectF,Qt::BrushStyle)
    // 7: fillRect(QRectF,Qt::GlobalColor)
    // 8: fillRect(int,int,int,int,Qt::BrushStyle)
    // 9: fillRect(int,int,int,int,Qt::GlobalColor)
    // 10: fillRect(int,int,int,int,QBrush)
    // 11: fillRect(int,int,int,int,QColor)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 5
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[4])))) {
            overloadId = 9; // fillRect(int,int,int,int,Qt::GlobalColor)
        } else if (numArgs == 5
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[4])))) {
            overloadId = 8; // fillRect(int,int,int,int,Qt::BrushStyle)
        } else if (numArgs == 5
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[4])))) {
            overloadId = 11; // fillRect(int,int,int,int,QColor)
        } else if (numArgs == 5
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[4])))) {
            overloadId = 10; // fillRect(int,int,int,int,QBrush)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[1])))) {
            overloadId = 3; // fillRect(QRect,Qt::GlobalColor)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 2; // fillRect(QRect,Qt::BrushStyle)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 1; // fillRect(QRect,QColor)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
            overloadId = 0; // fillRect(QRect,QBrush)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[1])))) {
            overloadId = 7; // fillRect(QRectF,Qt::GlobalColor)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 6; // fillRect(QRectF,Qt::BrushStyle)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[1])))) {
            overloadId = 5; // fillRect(QRectF,QColor)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
            overloadId = 4; // fillRect(QRectF,QBrush)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_fillRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // fillRect(const QRect & arg__1, const QBrush & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
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
                // fillRect(QRect,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // fillRect(const QRect & arg__1, const QColor & color)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
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
                // fillRect(QRect,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // fillRect(const QRect & r, Qt::BrushStyle style)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::BrushStyle cppArg1 = ((::Qt::BrushStyle)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fillRect(QRect,Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // fillRect(const QRect & r, Qt::GlobalColor c)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::GlobalColor cppArg1 = ((::Qt::GlobalColor)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fillRect(QRect,Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // fillRect(const QRectF & arg__1, const QBrush & arg__2)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
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
                // fillRect(QRectF,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // fillRect(const QRectF & arg__1, const QColor & color)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
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
                // fillRect(QRectF,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // fillRect(const QRectF & r, Qt::BrushStyle style)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::BrushStyle cppArg1 = ((::Qt::BrushStyle)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fillRect(QRectF,Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // fillRect(const QRectF & r, Qt::GlobalColor c)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::GlobalColor cppArg1 = ((::Qt::GlobalColor)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // fillRect(QRectF,Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // fillRect(int x, int y, int w, int h, Qt::BrushStyle style)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::BrushStyle cppArg4 = ((::Qt::BrushStyle)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // fillRect(int,int,int,int,Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // fillRect(int x, int y, int w, int h, Qt::GlobalColor c)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::GlobalColor cppArg4 = ((::Qt::GlobalColor)0);
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // fillRect(int,int,int,int,Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 10: // fillRect(int x, int y, int w, int h, const QBrush & arg__5)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QBrush cppArg4_local = ::QBrush();
            ::QBrush* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);


            if (!PyErr_Occurred()) {
                // fillRect(int,int,int,int,QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 11: // fillRect(int x, int y, int w, int h, const QColor & color)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return 0;
            ::QColor cppArg4_local = ::QColor();
            ::QColor* cppArg4 = &cppArg4_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[4]))
                pythonToCpp[4](pyArgs[4], &cppArg4_local);
            else
                pythonToCpp[4](pyArgs[4], &cppArg4);


            if (!PyErr_Occurred()) {
                // fillRect(int,int,int,int,QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->fillRect(cppArg0, cppArg1, cppArg2, cppArg3, *cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_fillRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, PySide.QtGui.QBrush", "PySide.QtCore.QRect, PySide.QtGui.QColor", "PySide.QtCore.QRect, PySide.QtCore.Qt.BrushStyle", "PySide.QtCore.QRect, PySide.QtCore.Qt.GlobalColor", "PySide.QtCore.QRectF, PySide.QtGui.QBrush", "PySide.QtCore.QRectF, PySide.QtGui.QColor", "PySide.QtCore.QRectF, PySide.QtCore.Qt.BrushStyle", "PySide.QtCore.QRectF, PySide.QtCore.Qt.GlobalColor", "int, int, int, int, PySide.QtCore.Qt.BrushStyle", "int, int, int, int, PySide.QtCore.Qt.GlobalColor", "int, int, int, int, PySide.QtGui.QBrush", "int, int, int, int, PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.fillRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_font(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QFont & cppResult = const_cast<const ::QPainter*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_fontInfo(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontInfo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFontInfo cppResult = const_cast<const ::QPainter*>(cppSelf)->fontInfo();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTINFO_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_fontMetrics(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fontMetrics()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFontMetrics cppResult = const_cast<const ::QPainter*>(cppSelf)->fontMetrics();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_hasClipping(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasClipping()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainter*>(cppSelf)->hasClipping();
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

static PyObject* Sbk_QPainterFunc_initFrom(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: initFrom(const QWidget*)
    if ((pyArg != Py_None && (pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg))))) {
        overloadId = 0; // initFrom(const QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_initFrom_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // initFrom(const QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->initFrom(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_initFrom_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.initFrom", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_isActive(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActive()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainter*>(cppSelf)->isActive();
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

static PyObject* Sbk_QPainterFunc_layoutDirection(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // layoutDirection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::LayoutDirection cppResult = const_cast<const ::QPainter*>(cppSelf)->layoutDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_opacity(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // opacity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QPainter*>(cppSelf)->opacity();
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

static PyObject* Sbk_QPainterFunc_paintEngine(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // paintEngine()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPaintEngine * cppResult = const_cast<const ::QPainter*>(cppSelf)->paintEngine();
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

static PyObject* Sbk_QPainterFunc_pen(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pen()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QPen & cppResult = const_cast<const ::QPainter*>(cppSelf)->pen();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_renderHints(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // renderHints()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<QPainter::RenderHint> cppResult = const_cast<const ::QPainter*>(cppSelf)->renderHints();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_resetMatrix(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetMatrix()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_resetTransform(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetTransform()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resetTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_restore(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restore()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->restore();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_restoreRedirected(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: restoreRedirected(const QPaintDevice*)
    if ((pyArg != Py_None && (pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArg))))) {
        overloadId = 0; // restoreRedirected(const QPaintDevice*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_restoreRedirected_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // restoreRedirected(const QPaintDevice*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QPainter::restoreRedirected(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_restoreRedirected_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.restoreRedirected", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_rotate(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rotate(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // rotate(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_rotate_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rotate(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->rotate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_rotate_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.rotate", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_save(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // save()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->save();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QPainterFunc_scale(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "scale", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: scale(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // scale(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_scale_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // scale(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->scale(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_scale_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.scale", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setBackground(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setBackground_TypeError;

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
            // setBackground(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackground(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setBackground", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setBackgroundMode(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackgroundMode(Qt::BGMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BGMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setBackgroundMode(Qt::BGMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setBackgroundMode_TypeError;

    // Call function/method
    {
        ::Qt::BGMode cppArg0 = ((::Qt::BGMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBackgroundMode(Qt::BGMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackgroundMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setBackgroundMode_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.BGMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setBackgroundMode", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setBrush(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBrush(Qt::BrushStyle)
    // 1: setBrush(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setBrush(Qt::BrushStyle)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 1; // setBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setBrush_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setBrush(Qt::BrushStyle style)
        {
            ::Qt::BrushStyle cppArg0 = ((::Qt::BrushStyle)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setBrush(Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrush(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setBrush(const QBrush & brush)
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
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setBrush_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.BrushStyle", "PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setBrush", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setBrushOrigin(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setBrushOrigin", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setBrushOrigin(QPoint)
    // 1: setBrushOrigin(QPointF)
    // 2: setBrushOrigin(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 2; // setBrushOrigin(int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // setBrushOrigin(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // setBrushOrigin(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setBrushOrigin_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setBrushOrigin(const QPoint & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setBrushOrigin(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrushOrigin(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setBrushOrigin(const QPointF & arg__1)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setBrushOrigin(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrushOrigin(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setBrushOrigin(int x, int y)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setBrushOrigin(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setBrushOrigin(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setBrushOrigin_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setBrushOrigin", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setClipPath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipPath(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipPath(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setClipPath", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setClipPath(QPainterPath,Qt::ClipOperation)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setClipPath(QPainterPath,Qt::ClipOperation)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setClipPath(QPainterPath,Qt::ClipOperation)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setClipPath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "op");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipPath(): got multiple values for keyword argument 'op'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setClipPath_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::Qt::ClipOperation cppArg1 = Qt::ReplaceClip;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setClipPath(QPainterPath,Qt::ClipOperation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setClipPath(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setClipPath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath, PySide.QtCore.Qt.ClipOperation = Qt.ReplaceClip", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setClipPath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setClipRect(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRect(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRect(): not enough arguments");
        return 0;
    } else if (numArgs == 3)
        goto Sbk_QPainterFunc_setClipRect_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOOO:setClipRect", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return 0;


    // Overloaded function decisor
    // 0: setClipRect(QRect,Qt::ClipOperation)
    // 1: setClipRect(QRectF,Qt::ClipOperation)
    // 2: setClipRect(int,int,int,int,Qt::ClipOperation)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 2; // setClipRect(int,int,int,int,Qt::ClipOperation)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[4])))) {
            overloadId = 2; // setClipRect(int,int,int,int,Qt::ClipOperation)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setClipRect(QRect,Qt::ClipOperation)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setClipRect(QRect,Qt::ClipOperation)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setClipRect(QRectF,Qt::ClipOperation)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1])))) {
            overloadId = 1; // setClipRect(QRectF,Qt::ClipOperation)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setClipRect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setClipRect(const QRect & arg__1, Qt::ClipOperation op)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "op");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRect(): got multiple values for keyword argument 'op'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_setClipRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ClipOperation cppArg1 = Qt::ReplaceClip;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setClipRect(QRect,Qt::ClipOperation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setClipRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setClipRect(const QRectF & arg__1, Qt::ClipOperation op)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "op");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRect(): got multiple values for keyword argument 'op'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1]))))
                        goto Sbk_QPainterFunc_setClipRect_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRectF cppArg0_local = ::QRectF();
            ::QRectF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::ClipOperation cppArg1 = Qt::ReplaceClip;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setClipRect(QRectF,Qt::ClipOperation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setClipRect(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setClipRect(int x, int y, int w, int h, Qt::ClipOperation op)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "op");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRect(): got multiple values for keyword argument 'op'.");
                    return 0;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[4]))))
                        goto Sbk_QPainterFunc_setClipRect_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::ClipOperation cppArg4 = Qt::ReplaceClip;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // setClipRect(int,int,int,int,Qt::ClipOperation)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setClipRect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setClipRect_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect, PySide.QtCore.Qt.ClipOperation = Qt.ReplaceClip", "PySide.QtCore.QRectF, PySide.QtCore.Qt.ClipOperation = Qt.ReplaceClip", "int, int, int, int, PySide.QtCore.Qt.ClipOperation = Qt.ReplaceClip", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setClipRect", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setClipRegion(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRegion(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRegion(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setClipRegion", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setClipRegion(QRegion,Qt::ClipOperation)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setClipRegion(QRegion,Qt::ClipOperation)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1])))) {
            overloadId = 0; // setClipRegion(QRegion,Qt::ClipOperation)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setClipRegion_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "op");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setClipRegion(): got multiple values for keyword argument 'op'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CLIPOPERATION_IDX]), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setClipRegion_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRegion cppArg0_local = ::QRegion();
        ::QRegion* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QREGION_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::Qt::ClipOperation cppArg1 = Qt::ReplaceClip;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setClipRegion(QRegion,Qt::ClipOperation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setClipRegion(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setClipRegion_TypeError:
        const char* overloads[] = {"PySide.QtGui.QRegion, PySide.QtCore.Qt.ClipOperation = Qt.ReplaceClip", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setClipRegion", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setClipping(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setClipping(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setClipping(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setClipping_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setClipping(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setClipping(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setClipping_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setClipping", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setCompositionMode(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompositionMode(QPainter::CompositionMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setCompositionMode(QPainter::CompositionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setCompositionMode_TypeError;

    // Call function/method
    {
        ::QPainter::CompositionMode cppArg0 = ((::QPainter::CompositionMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompositionMode(QPainter::CompositionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompositionMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setCompositionMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.CompositionMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setCompositionMode", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setLayoutDirection(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLayoutDirection(Qt::LayoutDirection)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setLayoutDirection(Qt::LayoutDirection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setLayoutDirection_TypeError;

    // Call function/method
    {
        ::Qt::LayoutDirection cppArg0 = ((::Qt::LayoutDirection)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLayoutDirection(Qt::LayoutDirection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLayoutDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setLayoutDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.LayoutDirection", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setLayoutDirection", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setOpacity(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOpacity(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setOpacity(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setOpacity_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOpacity(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOpacity(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setOpacity_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setOpacity", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setPen(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPen(Qt::PenStyle)
    // 1: setPen(QColor)
    // 2: setPen(QPen)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_PENSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setPen(Qt::PenStyle)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 1; // setPen(QColor)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArg)))) {
        overloadId = 2; // setPen(QPen)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setPen_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPen(Qt::PenStyle style)
        {
            ::Qt::PenStyle cppArg0 = ((::Qt::PenStyle)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setPen(Qt::PenStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPen(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPen(const QColor & color)
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
                // setPen(QColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPen(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // setPen(const QPen & pen)
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
                // setPen(QPen)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPen(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setPen_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.PenStyle", "PySide.QtGui.QColor", "PySide.QtGui.QPen", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setPen", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setRedirected(PyObject* self, PyObject* args, PyObject* kwds)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRedirected(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRedirected(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setRedirected", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setRedirected(const QPaintDevice*,QPaintDevice*,QPoint)
    if (numArgs >= 2
        && (pyArgs[0] != Py_None && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[0]))))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setRedirected(const QPaintDevice*,QPaintDevice*,QPoint)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2])))) {
            overloadId = 0; // setRedirected(const QPaintDevice*,QPaintDevice*,QPoint)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setRedirected_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "offset");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRedirected(): got multiple values for keyword argument 'offset'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[2]))))
                    goto Sbk_QPainterFunc_setRedirected_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPaintDevice* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPaintDevice* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QPoint cppArg2_local = QPoint();
        ::QPoint* cppArg2 = &cppArg2_local;
        if (pythonToCpp[2]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[2]))
            pythonToCpp[2](pyArgs[2], &cppArg2_local);
        else
            pythonToCpp[2](pyArgs[2], &cppArg2);
        }

        if (!PyErr_Occurred()) {
            // setRedirected(const QPaintDevice*,QPaintDevice*,QPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QPainter::setRedirected(cppArg0, cppArg1, *cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setRedirected_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintDevice, PySide.QtGui.QPaintDevice, PySide.QtCore.QPoint = QPoint()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setRedirected", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setRenderHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setRenderHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRenderHint(QPainter::RenderHint,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setRenderHint(QPainter::RenderHint,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setRenderHint(QPainter::RenderHint,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setRenderHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "on");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHint(): got multiple values for keyword argument 'on'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setRenderHint_TypeError;
            }
        }
        ::QPainter::RenderHint cppArg0 = ((::QPainter::RenderHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRenderHint(QPainter::RenderHint,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRenderHint(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setRenderHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.RenderHint, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setRenderHint", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setRenderHints(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHints(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHints(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setRenderHints", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRenderHints(QFlags<QPainter::RenderHint>,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setRenderHints(QFlags<QPainter::RenderHint>,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setRenderHints(QFlags<QPainter::RenderHint>,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setRenderHints_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "on");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setRenderHints(): got multiple values for keyword argument 'on'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setRenderHints_TypeError;
            }
        }
        ::QFlags<QPainter::RenderHint> cppArg0 = ((::QFlags<QPainter::RenderHint>)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRenderHints(QFlags<QPainter::RenderHint>,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRenderHints(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setRenderHints_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.RenderHints, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setRenderHints", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setTransform(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setTransform(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setTransform(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setTransform", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTransform(QTransform,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setTransform(QTransform,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setTransform(QTransform,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setTransform_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setTransform(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setTransform_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setTransform(QTransform,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransform(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setTransform", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setViewTransformEnabled(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setViewTransformEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setViewTransformEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setViewTransformEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewTransformEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setViewTransformEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setViewTransformEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setViewTransformEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setViewport(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPainterFunc_setViewport_TypeError;

    if (!PyArg_UnpackTuple(args, "setViewport", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setViewport(QRect)
    // 1: setViewport(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // setViewport(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // setViewport(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setViewport_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setViewport(const QRect & viewport)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setViewport(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setViewport(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setViewport(int x, int y, int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setViewport(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setViewport(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setViewport_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setViewport", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setWindow(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_QPainterFunc_setWindow_TypeError;

    if (!PyArg_UnpackTuple(args, "setWindow", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setWindow(QRect)
    // 1: setWindow(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // setWindow(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // setWindow(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setWindow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setWindow(const QRect & window)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRect cppArg0_local = ::QRect();
            ::QRect* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setWindow(QRect)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setWindow(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setWindow(int x, int y, int w, int h)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // setWindow(int,int,int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setWindow(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setWindow_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect", "int, int, int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setWindow", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setWorldMatrix(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldMatrix(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldMatrix(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setWorldMatrix", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setWorldMatrix(QMatrix,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setWorldMatrix(QMatrix,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setWorldMatrix(QMatrix,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setWorldMatrix_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldMatrix(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setWorldMatrix_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QMatrix cppArg0_local = ::QMatrix();
        ::QMatrix* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setWorldMatrix(QMatrix,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWorldMatrix(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setWorldMatrix_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setWorldMatrix", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setWorldMatrixEnabled(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWorldMatrixEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWorldMatrixEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setWorldMatrixEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWorldMatrixEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWorldMatrixEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setWorldMatrixEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.setWorldMatrixEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_setWorldTransform(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldTransform(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldTransform(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setWorldTransform", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setWorldTransform(QTransform,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setWorldTransform(QTransform,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setWorldTransform(QTransform,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_setWorldTransform_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "combine");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QPainter.setWorldTransform(): got multiple values for keyword argument 'combine'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QPainterFunc_setWorldTransform_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setWorldTransform(QTransform,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWorldTransform(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_setWorldTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.setWorldTransform", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_shear(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "shear", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: shear(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // shear(qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_shear_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // shear(qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->shear(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_shear_TypeError:
        const char* overloads[] = {"float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.shear", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_strokePath(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "strokePath", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: strokePath(QPainterPath,QPen)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], (pyArgs[1])))) {
        overloadId = 0; // strokePath(QPainterPath,QPen)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_strokePath_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QPainterPath cppArg0_local = ::QPainterPath();
        ::QPainterPath* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QPen cppArg1_local = ::QPen();
        ::QPen* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPEN_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // strokePath(QPainterPath,QPen)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->strokePath(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_strokePath_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainterPath, PySide.QtGui.QPen", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.strokePath", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_testRenderHint(PyObject* self, PyObject* pyArg)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: testRenderHint(QPainter::RenderHint)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]), (pyArg)))) {
        overloadId = 0; // testRenderHint(QPainter::RenderHint)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_testRenderHint_TypeError;

    // Call function/method
    {
        ::QPainter::RenderHint cppArg0 = ((::QPainter::RenderHint)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // testRenderHint(QPainter::RenderHint)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainter*>(cppSelf)->testRenderHint(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainterFunc_testRenderHint_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPainter.RenderHint", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QPainter.testRenderHint", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_transform(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QTransform & cppResult = const_cast<const ::QPainter*>(cppSelf)->transform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_translate(PyObject* self, PyObject* args)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translate", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: translate(QPoint)
    // 1: translate(QPointF)
    // 2: translate(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 2; // translate(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], (pyArgs[0])))) {
        overloadId = 0; // translate(QPoint)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))) {
        overloadId = 1; // translate(QPointF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterFunc_translate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // translate(const QPoint & offset)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPoint cppArg0_local = ::QPoint();
            ::QPoint* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // translate(QPoint)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // translate(const QPointF & offset)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QPointF cppArg0_local = ::QPointF();
            ::QPointF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // translate(QPointF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // translate(qreal dx, qreal dy)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // translate(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->translate(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QPainterFunc_translate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPoint", "PySide.QtCore.QPointF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QPainter.translate", overloads);
        return 0;
}

static PyObject* Sbk_QPainterFunc_viewTransformEnabled(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewTransformEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainter*>(cppSelf)->viewTransformEnabled();
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

static PyObject* Sbk_QPainterFunc_viewport(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // viewport()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QPainter*>(cppSelf)->viewport();
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

static PyObject* Sbk_QPainterFunc_window(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // window()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QPainter*>(cppSelf)->window();
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

static PyObject* Sbk_QPainterFunc_worldMatrix(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // worldMatrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMatrix & cppResult = const_cast<const ::QPainter*>(cppSelf)->worldMatrix();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QPainterFunc_worldMatrixEnabled(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // worldMatrixEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainter*>(cppSelf)->worldMatrixEnabled();
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

static PyObject* Sbk_QPainterFunc_worldTransform(PyObject* self)
{
    ::QPainter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // worldTransform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QTransform & cppResult = const_cast<const ::QPainter*>(cppSelf)->worldTransform();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPainter_methods[] = {
    {"background", (PyCFunction)Sbk_QPainterFunc_background, METH_NOARGS},
    {"backgroundMode", (PyCFunction)Sbk_QPainterFunc_backgroundMode, METH_NOARGS},
    {"begin", (PyCFunction)Sbk_QPainterFunc_begin, METH_O},
    {"beginNativePainting", (PyCFunction)Sbk_QPainterFunc_beginNativePainting, METH_NOARGS},
    {"boundingRect", (PyCFunction)Sbk_QPainterFunc_boundingRect, METH_VARARGS|METH_KEYWORDS},
    {"brush", (PyCFunction)Sbk_QPainterFunc_brush, METH_NOARGS},
    {"brushOrigin", (PyCFunction)Sbk_QPainterFunc_brushOrigin, METH_NOARGS},
    {"clipBoundingRect", (PyCFunction)Sbk_QPainterFunc_clipBoundingRect, METH_NOARGS},
    {"clipPath", (PyCFunction)Sbk_QPainterFunc_clipPath, METH_NOARGS},
    {"clipRegion", (PyCFunction)Sbk_QPainterFunc_clipRegion, METH_NOARGS},
    {"combinedMatrix", (PyCFunction)Sbk_QPainterFunc_combinedMatrix, METH_NOARGS},
    {"combinedTransform", (PyCFunction)Sbk_QPainterFunc_combinedTransform, METH_NOARGS},
    {"compositionMode", (PyCFunction)Sbk_QPainterFunc_compositionMode, METH_NOARGS},
    {"device", (PyCFunction)Sbk_QPainterFunc_device, METH_NOARGS},
    {"deviceMatrix", (PyCFunction)Sbk_QPainterFunc_deviceMatrix, METH_NOARGS},
    {"deviceTransform", (PyCFunction)Sbk_QPainterFunc_deviceTransform, METH_NOARGS},
    {"drawArc", (PyCFunction)Sbk_QPainterFunc_drawArc, METH_VARARGS},
    {"drawChord", (PyCFunction)Sbk_QPainterFunc_drawChord, METH_VARARGS},
    {"drawConvexPolygon", (PyCFunction)Sbk_QPainterFunc_drawConvexPolygon, METH_O},
    {"drawEllipse", (PyCFunction)Sbk_QPainterFunc_drawEllipse, METH_VARARGS},
    {"drawImage", (PyCFunction)Sbk_QPainterFunc_drawImage, METH_VARARGS|METH_KEYWORDS},
    {"drawLine", (PyCFunction)Sbk_QPainterFunc_drawLine, METH_VARARGS},
    {"drawLines", (PyCFunction)Sbk_QPainterFunc_drawLines, METH_O},
    {"drawPath", (PyCFunction)Sbk_QPainterFunc_drawPath, METH_O},
    {"drawPicture", (PyCFunction)Sbk_QPainterFunc_drawPicture, METH_VARARGS},
    {"drawPie", (PyCFunction)Sbk_QPainterFunc_drawPie, METH_VARARGS},
    {"drawPixmap", (PyCFunction)Sbk_QPainterFunc_drawPixmap, METH_VARARGS},
    {"drawPixmapFragments", (PyCFunction)Sbk_QPainterFunc_drawPixmapFragments, METH_VARARGS|METH_KEYWORDS},
    {"drawPoint", (PyCFunction)Sbk_QPainterFunc_drawPoint, METH_VARARGS},
    {"drawPoints", (PyCFunction)Sbk_QPainterFunc_drawPoints, METH_O},
    {"drawPolygon", (PyCFunction)Sbk_QPainterFunc_drawPolygon, METH_VARARGS|METH_KEYWORDS},
    {"drawPolyline", (PyCFunction)Sbk_QPainterFunc_drawPolyline, METH_O},
    {"drawRect", (PyCFunction)Sbk_QPainterFunc_drawRect, METH_VARARGS},
    {"drawRects", (PyCFunction)Sbk_QPainterFunc_drawRects, METH_O},
    {"drawRoundRect", (PyCFunction)Sbk_QPainterFunc_drawRoundRect, METH_VARARGS|METH_KEYWORDS},
    {"drawRoundedRect", (PyCFunction)Sbk_QPainterFunc_drawRoundedRect, METH_VARARGS|METH_KEYWORDS},
    {"drawText", (PyCFunction)Sbk_QPainterFunc_drawText, METH_VARARGS|METH_KEYWORDS},
    {"drawTextItem", (PyCFunction)Sbk_QPainterFunc_drawTextItem, METH_VARARGS},
    {"drawTiledPixmap", (PyCFunction)Sbk_QPainterFunc_drawTiledPixmap, METH_VARARGS|METH_KEYWORDS},
    {"end", (PyCFunction)Sbk_QPainterFunc_end, METH_NOARGS},
    {"endNativePainting", (PyCFunction)Sbk_QPainterFunc_endNativePainting, METH_NOARGS},
    {"eraseRect", (PyCFunction)Sbk_QPainterFunc_eraseRect, METH_VARARGS},
    {"fillPath", (PyCFunction)Sbk_QPainterFunc_fillPath, METH_VARARGS},
    {"fillRect", (PyCFunction)Sbk_QPainterFunc_fillRect, METH_VARARGS},
    {"font", (PyCFunction)Sbk_QPainterFunc_font, METH_NOARGS},
    {"fontInfo", (PyCFunction)Sbk_QPainterFunc_fontInfo, METH_NOARGS},
    {"fontMetrics", (PyCFunction)Sbk_QPainterFunc_fontMetrics, METH_NOARGS},
    {"hasClipping", (PyCFunction)Sbk_QPainterFunc_hasClipping, METH_NOARGS},
    {"initFrom", (PyCFunction)Sbk_QPainterFunc_initFrom, METH_O},
    {"isActive", (PyCFunction)Sbk_QPainterFunc_isActive, METH_NOARGS},
    {"layoutDirection", (PyCFunction)Sbk_QPainterFunc_layoutDirection, METH_NOARGS},
    {"opacity", (PyCFunction)Sbk_QPainterFunc_opacity, METH_NOARGS},
    {"paintEngine", (PyCFunction)Sbk_QPainterFunc_paintEngine, METH_NOARGS},
    {"pen", (PyCFunction)Sbk_QPainterFunc_pen, METH_NOARGS},
    {"renderHints", (PyCFunction)Sbk_QPainterFunc_renderHints, METH_NOARGS},
    {"resetMatrix", (PyCFunction)Sbk_QPainterFunc_resetMatrix, METH_NOARGS},
    {"resetTransform", (PyCFunction)Sbk_QPainterFunc_resetTransform, METH_NOARGS},
    {"restore", (PyCFunction)Sbk_QPainterFunc_restore, METH_NOARGS},
    {"restoreRedirected", (PyCFunction)Sbk_QPainterFunc_restoreRedirected, METH_O|METH_STATIC},
    {"rotate", (PyCFunction)Sbk_QPainterFunc_rotate, METH_O},
    {"save", (PyCFunction)Sbk_QPainterFunc_save, METH_NOARGS},
    {"scale", (PyCFunction)Sbk_QPainterFunc_scale, METH_VARARGS},
    {"setBackground", (PyCFunction)Sbk_QPainterFunc_setBackground, METH_O},
    {"setBackgroundMode", (PyCFunction)Sbk_QPainterFunc_setBackgroundMode, METH_O},
    {"setBrush", (PyCFunction)Sbk_QPainterFunc_setBrush, METH_O},
    {"setBrushOrigin", (PyCFunction)Sbk_QPainterFunc_setBrushOrigin, METH_VARARGS},
    {"setClipPath", (PyCFunction)Sbk_QPainterFunc_setClipPath, METH_VARARGS|METH_KEYWORDS},
    {"setClipRect", (PyCFunction)Sbk_QPainterFunc_setClipRect, METH_VARARGS|METH_KEYWORDS},
    {"setClipRegion", (PyCFunction)Sbk_QPainterFunc_setClipRegion, METH_VARARGS|METH_KEYWORDS},
    {"setClipping", (PyCFunction)Sbk_QPainterFunc_setClipping, METH_O},
    {"setCompositionMode", (PyCFunction)Sbk_QPainterFunc_setCompositionMode, METH_O},
    {"setFont", (PyCFunction)Sbk_QPainterFunc_setFont, METH_O},
    {"setLayoutDirection", (PyCFunction)Sbk_QPainterFunc_setLayoutDirection, METH_O},
    {"setOpacity", (PyCFunction)Sbk_QPainterFunc_setOpacity, METH_O},
    {"setPen", (PyCFunction)Sbk_QPainterFunc_setPen, METH_O},
    {"setRedirected", (PyCFunction)Sbk_QPainterFunc_setRedirected, METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"setRenderHint", (PyCFunction)Sbk_QPainterFunc_setRenderHint, METH_VARARGS|METH_KEYWORDS},
    {"setRenderHints", (PyCFunction)Sbk_QPainterFunc_setRenderHints, METH_VARARGS|METH_KEYWORDS},
    {"setTransform", (PyCFunction)Sbk_QPainterFunc_setTransform, METH_VARARGS|METH_KEYWORDS},
    {"setViewTransformEnabled", (PyCFunction)Sbk_QPainterFunc_setViewTransformEnabled, METH_O},
    {"setViewport", (PyCFunction)Sbk_QPainterFunc_setViewport, METH_VARARGS},
    {"setWindow", (PyCFunction)Sbk_QPainterFunc_setWindow, METH_VARARGS},
    {"setWorldMatrix", (PyCFunction)Sbk_QPainterFunc_setWorldMatrix, METH_VARARGS|METH_KEYWORDS},
    {"setWorldMatrixEnabled", (PyCFunction)Sbk_QPainterFunc_setWorldMatrixEnabled, METH_O},
    {"setWorldTransform", (PyCFunction)Sbk_QPainterFunc_setWorldTransform, METH_VARARGS|METH_KEYWORDS},
    {"shear", (PyCFunction)Sbk_QPainterFunc_shear, METH_VARARGS},
    {"strokePath", (PyCFunction)Sbk_QPainterFunc_strokePath, METH_VARARGS},
    {"testRenderHint", (PyCFunction)Sbk_QPainterFunc_testRenderHint, METH_O},
    {"transform", (PyCFunction)Sbk_QPainterFunc_transform, METH_NOARGS},
    {"translate", (PyCFunction)Sbk_QPainterFunc_translate, METH_VARARGS},
    {"viewTransformEnabled", (PyCFunction)Sbk_QPainterFunc_viewTransformEnabled, METH_NOARGS},
    {"viewport", (PyCFunction)Sbk_QPainterFunc_viewport, METH_NOARGS},
    {"window", (PyCFunction)Sbk_QPainterFunc_window, METH_NOARGS},
    {"worldMatrix", (PyCFunction)Sbk_QPainterFunc_worldMatrix, METH_NOARGS},
    {"worldMatrixEnabled", (PyCFunction)Sbk_QPainterFunc_worldMatrixEnabled, METH_NOARGS},
    {"worldTransform", (PyCFunction)Sbk_QPainterFunc_worldTransform, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QPainter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPainter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPainter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPainter",
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
    /*tp_traverse*/         Sbk_QPainter_traverse,
    /*tp_clear*/            Sbk_QPainter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPainter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPainter_Init,
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

PyObject* SbkPySide_QtGui_QPainter_RenderHint___and__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::RenderHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::RenderHints)PyLong_AsLong(self);
    cppArg = (QPainter::RenderHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::RenderHints)PyInt_AsLong(self);
    cppArg = (QPainter::RenderHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_RenderHint___or__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::RenderHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::RenderHints)PyLong_AsLong(self);
    cppArg = (QPainter::RenderHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::RenderHints)PyInt_AsLong(self);
    cppArg = (QPainter::RenderHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_RenderHint___xor__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::RenderHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::RenderHints)PyLong_AsLong(self);
    cppArg = (QPainter::RenderHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::RenderHints)PyInt_AsLong(self);
    cppArg = (QPainter::RenderHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_RenderHint___invert__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::RenderHints cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), self, &cppSelf);
    ::QPainter::RenderHints cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QPainter_RenderHint_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QPainter_RenderHint__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QPainter_RenderHint_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QPainter_RenderHint__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QPainter_RenderHint___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QPainter_RenderHint___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QPainter_RenderHint___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QPainter_RenderHint___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QPainter_RenderHint_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QPainter_RenderHint_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};


PyObject* SbkPySide_QtGui_QPainter_PixmapFragmentHint___and__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::PixmapFragmentHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::PixmapFragmentHints)PyLong_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::PixmapFragmentHints)PyInt_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_PixmapFragmentHint___or__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::PixmapFragmentHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::PixmapFragmentHints)PyLong_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::PixmapFragmentHints)PyInt_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_PixmapFragmentHint___xor__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::PixmapFragmentHints cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QPainter::PixmapFragmentHints)PyLong_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QPainter::PixmapFragmentHints)PyInt_AsLong(self);
    cppArg = (QPainter::PixmapFragmentHints)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QPainter_PixmapFragmentHint___invert__(PyObject* self, PyObject* pyArg)
{
    ::QPainter::PixmapFragmentHints cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), self, &cppSelf);
    ::QPainter::PixmapFragmentHints cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QPainter_PixmapFragmentHint_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QPainter_PixmapFragmentHint__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QPainter_PixmapFragmentHint_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QPainter_PixmapFragmentHint__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QPainter_PixmapFragmentHint___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QPainter_PixmapFragmentHint___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QPainter_PixmapFragmentHint___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QPainter_PixmapFragmentHint___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QPainter_PixmapFragmentHint_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QPainter_PixmapFragmentHint_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QPainter_RenderHint_PythonToCpp_QPainter_RenderHint(PyObject* pyIn, void* cppOut) {
    *((::QPainter::RenderHint*)cppOut) = (::QPainter::RenderHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPainter_RenderHint_PythonToCpp_QPainter_RenderHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]))
        return QPainter_RenderHint_PythonToCpp_QPainter_RenderHint;
    return 0;
}
static PyObject* QPainter_RenderHint_CppToPython_QPainter_RenderHint(const void* cppIn) {
    int castCppIn = *((::QPainter::RenderHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX], castCppIn);

}

static void QFlags_QPainter_RenderHint__PythonToCpp_QFlags_QPainter_RenderHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPainter::RenderHint>*)cppOut) = ::QFlags<QPainter::RenderHint>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QPainter_RenderHint__PythonToCpp_QFlags_QPainter_RenderHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]))
        return QFlags_QPainter_RenderHint__PythonToCpp_QFlags_QPainter_RenderHint_;
    return 0;
}
static PyObject* QFlags_QPainter_RenderHint__CppToPython_QFlags_QPainter_RenderHint_(const void* cppIn) {
    int castCppIn = *((::QFlags<QPainter::RenderHint>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]));

}

static void QPainter_RenderHint_PythonToCpp_QFlags_QPainter_RenderHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPainter::RenderHint>*)cppOut) = ::QFlags<QPainter::RenderHint>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QPainter_RenderHint_PythonToCpp_QFlags_QPainter_RenderHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]))
        return QPainter_RenderHint_PythonToCpp_QFlags_QPainter_RenderHint_;
    return 0;
}
static void number_PythonToCpp_QFlags_QPainter_RenderHint_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QPainter::RenderHint>*)cppOut) = ::QFlags<QPainter::RenderHint>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QPainter_RenderHint__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QPainter_RenderHint_;
    return 0;
}
static void QPainter_PixmapFragmentHint_PythonToCpp_QPainter_PixmapFragmentHint(PyObject* pyIn, void* cppOut) {
    *((::QPainter::PixmapFragmentHint*)cppOut) = (::QPainter::PixmapFragmentHint) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPainter_PixmapFragmentHint_PythonToCpp_QPainter_PixmapFragmentHint_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX]))
        return QPainter_PixmapFragmentHint_PythonToCpp_QPainter_PixmapFragmentHint;
    return 0;
}
static PyObject* QPainter_PixmapFragmentHint_CppToPython_QPainter_PixmapFragmentHint(const void* cppIn) {
    int castCppIn = *((::QPainter::PixmapFragmentHint*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX], castCppIn);

}

static void QFlags_QPainter_PixmapFragmentHint__PythonToCpp_QFlags_QPainter_PixmapFragmentHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPainter::PixmapFragmentHint>*)cppOut) = ::QFlags<QPainter::PixmapFragmentHint>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QPainter_PixmapFragmentHint__PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]))
        return QFlags_QPainter_PixmapFragmentHint__PythonToCpp_QFlags_QPainter_PixmapFragmentHint_;
    return 0;
}
static PyObject* QFlags_QPainter_PixmapFragmentHint__CppToPython_QFlags_QPainter_PixmapFragmentHint_(const void* cppIn) {
    int castCppIn = *((::QFlags<QPainter::PixmapFragmentHint>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]));

}

static void QPainter_PixmapFragmentHint_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QPainter::PixmapFragmentHint>*)cppOut) = ::QFlags<QPainter::PixmapFragmentHint>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QPainter_PixmapFragmentHint_PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX]))
        return QPainter_PixmapFragmentHint_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_;
    return 0;
}
static void number_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QPainter::PixmapFragmentHint>*)cppOut) = ::QFlags<QPainter::PixmapFragmentHint>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_;
    return 0;
}
static void QPainter_CompositionMode_PythonToCpp_QPainter_CompositionMode(PyObject* pyIn, void* cppOut) {
    *((::QPainter::CompositionMode*)cppOut) = (::QPainter::CompositionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QPainter_CompositionMode_PythonToCpp_QPainter_CompositionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX]))
        return QPainter_CompositionMode_PythonToCpp_QPainter_CompositionMode;
    return 0;
}
static PyObject* QPainter_CompositionMode_CppToPython_QPainter_CompositionMode(const void* cppIn) {
    int castCppIn = *((::QPainter::CompositionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QPainter_PythonToCpp_QPainter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPainter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QPainter_PythonToCpp_QPainter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainter_Type))
        return QPainter_PythonToCpp_QPainter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QPainter_PTR_CppToPython_QPainter(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPainter*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPainter_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QPainter(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPainter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QPainter", "QPainter*",
        &Sbk_QPainter_Type, &Shiboken::callCppDestructor< ::QPainter >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPainter_Type,
        QPainter_PythonToCpp_QPainter_PTR,
        is_QPainter_PythonToCpp_QPainter_PTR_Convertible,
        QPainter_PTR_CppToPython_QPainter);

    Shiboken::Conversions::registerConverterName(converter, "QPainter");
    Shiboken::Conversions::registerConverterName(converter, "QPainter*");
    Shiboken::Conversions::registerConverterName(converter, "QPainter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPainter).name());


    // Initialization of enums.

    // Initialization of enum 'RenderHint'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX] = PySide::QFlags::create("RenderHints", &SbkPySide_QtGui_QPainter_RenderHint_as_number);
    SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPainter_Type,
        "RenderHint",
        "PySide.QtGui.QPainter.RenderHint",
        "QPainter::RenderHint",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
        &Sbk_QPainter_Type, "Antialiasing", (long) QPainter::Antialiasing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
        &Sbk_QPainter_Type, "TextAntialiasing", (long) QPainter::TextAntialiasing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
        &Sbk_QPainter_Type, "SmoothPixmapTransform", (long) QPainter::SmoothPixmapTransform))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
        &Sbk_QPainter_Type, "HighQualityAntialiasing", (long) QPainter::HighQualityAntialiasing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
        &Sbk_QPainter_Type, "NonCosmeticDefaultPen", (long) QPainter::NonCosmeticDefaultPen))
        return ;
    // Register converter for enum 'QPainter::RenderHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX],
            QPainter_RenderHint_CppToPython_QPainter_RenderHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainter_RenderHint_PythonToCpp_QPainter_RenderHint,
            is_QPainter_RenderHint_PythonToCpp_QPainter_RenderHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPainter::RenderHint");
        Shiboken::Conversions::registerConverterName(converter, "RenderHint");
    }
    // Register converter for flag 'QFlags<QPainter::RenderHint>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX],
            QFlags_QPainter_RenderHint__CppToPython_QFlags_QPainter_RenderHint_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainter_RenderHint_PythonToCpp_QFlags_QPainter_RenderHint_,
            is_QPainter_RenderHint_PythonToCpp_QFlags_QPainter_RenderHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QPainter_RenderHint__PythonToCpp_QFlags_QPainter_RenderHint_,
            is_QFlags_QPainter_RenderHint__PythonToCpp_QFlags_QPainter_RenderHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QPainter_RenderHint_,
            is_number_PythonToCpp_QFlags_QPainter_RenderHint__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QPainter::RenderHint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<RenderHint>");
    }
    // End of 'RenderHint' enum/flags.

    // Initialization of enum 'PixmapFragmentHint'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX] = PySide::QFlags::create("PixmapFragmentHints", &SbkPySide_QtGui_QPainter_PixmapFragmentHint_as_number);
    SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPainter_Type,
        "PixmapFragmentHint",
        "PySide.QtGui.QPainter.PixmapFragmentHint",
        "QPainter::PixmapFragmentHint",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX],
        &Sbk_QPainter_Type, "OpaqueHint", (long) QPainter::OpaqueHint))
        return ;
    // Register converter for enum 'QPainter::PixmapFragmentHint'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX],
            QPainter_PixmapFragmentHint_CppToPython_QPainter_PixmapFragmentHint);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainter_PixmapFragmentHint_PythonToCpp_QPainter_PixmapFragmentHint,
            is_QPainter_PixmapFragmentHint_PythonToCpp_QPainter_PixmapFragmentHint_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPainter::PixmapFragmentHint");
        Shiboken::Conversions::registerConverterName(converter, "PixmapFragmentHint");
    }
    // Register converter for flag 'QFlags<QPainter::PixmapFragmentHint>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX],
            QFlags_QPainter_PixmapFragmentHint__CppToPython_QFlags_QPainter_PixmapFragmentHint_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainter_PixmapFragmentHint_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_,
            is_QPainter_PixmapFragmentHint_PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QPainter_PixmapFragmentHint__PythonToCpp_QFlags_QPainter_PixmapFragmentHint_,
            is_QFlags_QPainter_PixmapFragmentHint__PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QPainter_PixmapFragmentHint_,
            is_number_PythonToCpp_QFlags_QPainter_PixmapFragmentHint__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QPainter::PixmapFragmentHint>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<PixmapFragmentHint>");
    }
    // End of 'PixmapFragmentHint' enum/flags.

    // Initialization of enum 'CompositionMode'.
    SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QPainter_Type,
        "CompositionMode",
        "PySide.QtGui.QPainter.CompositionMode",
        "QPainter::CompositionMode");
    if (!SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_SourceOver", (long) QPainter::CompositionMode_SourceOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_DestinationOver", (long) QPainter::CompositionMode_DestinationOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Clear", (long) QPainter::CompositionMode_Clear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Source", (long) QPainter::CompositionMode_Source))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Destination", (long) QPainter::CompositionMode_Destination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_SourceIn", (long) QPainter::CompositionMode_SourceIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_DestinationIn", (long) QPainter::CompositionMode_DestinationIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_SourceOut", (long) QPainter::CompositionMode_SourceOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_DestinationOut", (long) QPainter::CompositionMode_DestinationOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_SourceAtop", (long) QPainter::CompositionMode_SourceAtop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_DestinationAtop", (long) QPainter::CompositionMode_DestinationAtop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Xor", (long) QPainter::CompositionMode_Xor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Plus", (long) QPainter::CompositionMode_Plus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Multiply", (long) QPainter::CompositionMode_Multiply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Screen", (long) QPainter::CompositionMode_Screen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Overlay", (long) QPainter::CompositionMode_Overlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Darken", (long) QPainter::CompositionMode_Darken))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Lighten", (long) QPainter::CompositionMode_Lighten))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_ColorDodge", (long) QPainter::CompositionMode_ColorDodge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_ColorBurn", (long) QPainter::CompositionMode_ColorBurn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_HardLight", (long) QPainter::CompositionMode_HardLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_SoftLight", (long) QPainter::CompositionMode_SoftLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Difference", (long) QPainter::CompositionMode_Difference))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "CompositionMode_Exclusion", (long) QPainter::CompositionMode_Exclusion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_SourceOrDestination", (long) QPainter::RasterOp_SourceOrDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_SourceAndDestination", (long) QPainter::RasterOp_SourceAndDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_SourceXorDestination", (long) QPainter::RasterOp_SourceXorDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_NotSourceAndNotDestination", (long) QPainter::RasterOp_NotSourceAndNotDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_NotSourceOrNotDestination", (long) QPainter::RasterOp_NotSourceOrNotDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_NotSourceXorDestination", (long) QPainter::RasterOp_NotSourceXorDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_NotSource", (long) QPainter::RasterOp_NotSource))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_NotSourceAndDestination", (long) QPainter::RasterOp_NotSourceAndDestination))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
        &Sbk_QPainter_Type, "RasterOp_SourceAndNotDestination", (long) QPainter::RasterOp_SourceAndNotDestination))
        return ;
    // Register converter for enum 'QPainter::CompositionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX],
            QPainter_CompositionMode_CppToPython_QPainter_CompositionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QPainter_CompositionMode_PythonToCpp_QPainter_CompositionMode,
            is_QPainter_CompositionMode_PythonToCpp_QPainter_CompositionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QPainter::CompositionMode");
        Shiboken::Conversions::registerConverterName(converter, "CompositionMode");
    }
    // End of 'CompositionMode' enum.


    qRegisterMetaType< ::QPainter::RenderHint >("QPainter::RenderHint");
    qRegisterMetaType< ::QPainter::RenderHints >("QPainter::RenderHints");
    qRegisterMetaType< ::QPainter::PixmapFragmentHint >("QPainter::PixmapFragmentHint");
    qRegisterMetaType< ::QPainter::PixmapFragmentHints >("QPainter::PixmapFragmentHints");
    qRegisterMetaType< ::QPainter::CompositionMode >("QPainter::CompositionMode");
}
