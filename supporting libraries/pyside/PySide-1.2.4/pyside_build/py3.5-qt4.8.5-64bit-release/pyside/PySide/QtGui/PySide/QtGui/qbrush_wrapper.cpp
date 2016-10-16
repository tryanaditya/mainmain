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

#include "qbrush_wrapper.h"

// Extra includes
#include <QPixmap>
#include <qbrush.h>
#include <qcolor.h>
#include <qdatastream.h>
#include <qimage.h>
#include <qmatrix.h>
#include <qpixmap.h>
#include <qtransform.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QBrush_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QBrush >()))
        return -1;

    ::QBrush* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBrush(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QBrush", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QBrush()
    // 1: QBrush(Qt::BrushStyle)
    // 2: QBrush(Qt::GlobalColor,Qt::BrushStyle)
    // 3: QBrush(Qt::GlobalColor,QPixmap)
    // 4: QBrush(QBrush)
    // 5: QBrush(QColor,Qt::BrushStyle)
    // 6: QBrush(QColor,QPixmap)
    // 7: QBrush(QGradient)
    // 8: QBrush(QImage)
    // 9: QBrush(QPixmap)
    if (numArgs == 0) {
        overloadId = 0; // QBrush()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArgs[0])))) {
        overloadId = 8; // QBrush(QImage)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[0])))) {
        overloadId = 9; // QBrush(QPixmap)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (pyArgs[0])))) {
        overloadId = 7; // QBrush(QGradient)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QBrush(Qt::GlobalColor,Qt::BrushStyle)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
            overloadId = 3; // QBrush(Qt::GlobalColor,QPixmap)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 2; // QBrush(Qt::GlobalColor,Qt::BrushStyle)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[0])))) {
        overloadId = 1; // QBrush(Qt::BrushStyle)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // QBrush(QColor,Qt::BrushStyle)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArgs[1])))) {
            overloadId = 6; // QBrush(QColor,QPixmap)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1])))) {
            overloadId = 5; // QBrush(QColor,Qt::BrushStyle)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[0])))) {
        overloadId = 4; // QBrush(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrush_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QBrush()
        {

            if (!PyErr_Occurred()) {
                // QBrush()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QBrush(Qt::BrushStyle bs)
        {
            ::Qt::BrushStyle cppArg0 = ((::Qt::BrushStyle)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QBrush(Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QBrush(Qt::GlobalColor color, Qt::BrushStyle bs)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "bs");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBrush(): got multiple values for keyword argument 'bs'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1]))))
                        goto Sbk_QBrush_Init_TypeError;
                }
            }
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::Qt::BrushStyle cppArg1 = Qt::SolidPattern;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QBrush(Qt::GlobalColor,Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QBrush(Qt::GlobalColor color, const QPixmap & pixmap)
        {
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QBrush(Qt::GlobalColor,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QBrush(const QBrush & brush)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QBrush cppArg0_local = ::QBrush();
            ::QBrush* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBrush(QBrush)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 5: // QBrush(const QColor & color, Qt::BrushStyle bs)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "bs");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QBrush(): got multiple values for keyword argument 'bs'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArgs[1]))))
                        goto Sbk_QBrush_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QColor cppArg0_local = ::QColor();
            ::QColor* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::Qt::BrushStyle cppArg1 = Qt::SolidPattern;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QBrush(QColor,Qt::BrushStyle)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 6: // QBrush(const QColor & color, const QPixmap & pixmap)
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
            ::QPixmap cppArg1_local = ::QPixmap();
            ::QPixmap* cppArg1 = &cppArg1_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);


            if (!PyErr_Occurred()) {
                // QBrush(QColor,QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QBrush(const QGradient & gradient)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QGradient cppArg0_local = ::QGradient();
            ::QGradient* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBrush(QGradient)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // QBrush(const QImage & image)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QImage cppArg0_local = ::QImage();
            ::QImage* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // QBrush(QImage)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 9: // QBrush(const QPixmap & pixmap)
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
                // QBrush(QPixmap)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QBrush(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QBrush >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QBrush_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QBrush_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.Qt.BrushStyle", "PySide.QtCore.Qt.GlobalColor, PySide.QtCore.Qt.BrushStyle = Qt.SolidPattern", "PySide.QtCore.Qt.GlobalColor, PySide.QtGui.QPixmap", "PySide.QtGui.QBrush", "PySide.QtGui.QColor, PySide.QtCore.Qt.BrushStyle = Qt.SolidPattern", "PySide.QtGui.QColor, PySide.QtGui.QPixmap", "PySide.QtGui.QGradient", "PySide.QtGui.QImage", "PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QBrush", overloads);
        return -1;
}

static PyObject* Sbk_QBrushFunc_color(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // color()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QColor & cppResult = const_cast<const ::QBrush*>(cppSelf)->color();
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

static PyObject* Sbk_QBrushFunc_gradient(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // gradient()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QGradient * cppResult = const_cast<const ::QBrush*>(cppSelf)->gradient();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBrushFunc_isOpaque(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isOpaque()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QBrush*>(cppSelf)->isOpaque();
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

static PyObject* Sbk_QBrushFunc_matrix(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // matrix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QMatrix & cppResult = const_cast<const ::QBrush*>(cppSelf)->matrix();
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

static PyObject* Sbk_QBrushFunc_setColor(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColor(Qt::GlobalColor)
    // 1: setColor(QColor)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), (pyArg)))) {
        overloadId = 0; // setColor(Qt::GlobalColor)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (pyArg)))) {
        overloadId = 1; // setColor(QColor)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setColor_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setColor(Qt::GlobalColor color)
        {
            ::Qt::GlobalColor cppArg0 = ((::Qt::GlobalColor)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setColor(Qt::GlobalColor)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setColor(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setColor(const QColor & color)
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
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setColor_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.GlobalColor", "PySide.QtGui.QColor", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setColor", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_setMatrix(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMatrix(QMatrix)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyArg)))) {
        overloadId = 0; // setMatrix(QMatrix)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setMatrix_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMatrix cppArg0_local = ::QMatrix();
        ::QMatrix* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setMatrix(QMatrix)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMatrix(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setMatrix_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMatrix", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setMatrix", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_setStyle(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStyle(Qt::BrushStyle)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), (pyArg)))) {
        overloadId = 0; // setStyle(Qt::BrushStyle)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setStyle_TypeError;

    // Call function/method
    {
        ::Qt::BrushStyle cppArg0 = ((::Qt::BrushStyle)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStyle(Qt::BrushStyle)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStyle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setStyle_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.BrushStyle", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setStyle", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_setTexture(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTexture(QPixmap)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (pyArg)))) {
        overloadId = 0; // setTexture(QPixmap)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setTexture_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QPixmap cppArg0_local = ::QPixmap();
        ::QPixmap* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTexture(QPixmap)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTexture(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setTexture_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPixmap", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setTexture", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_setTextureImage(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextureImage(QImage)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (pyArg)))) {
        overloadId = 0; // setTextureImage(QImage)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setTextureImage_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QImage cppArg0_local = ::QImage();
        ::QImage* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTextureImage(QImage)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextureImage(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setTextureImage_TypeError:
        const char* overloads[] = {"PySide.QtGui.QImage", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setTextureImage", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_setTransform(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTransform(QTransform)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 0; // setTransform(QTransform)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_setTransform_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTransform cppArg0_local = ::QTransform();
        ::QTransform* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setTransform(QTransform)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTransform(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_setTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.setTransform", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_style(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // style()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::BrushStyle cppResult = const_cast<const ::QBrush*>(cppSelf)->style();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBrushFunc_swap(PyObject* self, PyObject* pyArg)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: swap(QBrush&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // swap(QBrush&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc_swap_TypeError;

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
            // swap(QBrush&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->swap(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QBrushFunc_swap_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.swap", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc_texture(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // texture()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPixmap cppResult = const_cast<const ::QBrush*>(cppSelf)->texture();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBrushFunc_textureImage(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textureImage()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QImage cppResult = const_cast<const ::QBrush*>(cppSelf)->textureImage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QBrushFunc_transform(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // transform()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTransform cppResult = const_cast<const ::QBrush*>(cppSelf)->transform();
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

static PyObject* Sbk_QBrush___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBrush& cppSelf = *(((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QBrush_methods[] = {
    {"color", (PyCFunction)Sbk_QBrushFunc_color, METH_NOARGS},
    {"gradient", (PyCFunction)Sbk_QBrushFunc_gradient, METH_NOARGS},
    {"isOpaque", (PyCFunction)Sbk_QBrushFunc_isOpaque, METH_NOARGS},
    {"matrix", (PyCFunction)Sbk_QBrushFunc_matrix, METH_NOARGS},
    {"setColor", (PyCFunction)Sbk_QBrushFunc_setColor, METH_O},
    {"setMatrix", (PyCFunction)Sbk_QBrushFunc_setMatrix, METH_O},
    {"setStyle", (PyCFunction)Sbk_QBrushFunc_setStyle, METH_O},
    {"setTexture", (PyCFunction)Sbk_QBrushFunc_setTexture, METH_O},
    {"setTextureImage", (PyCFunction)Sbk_QBrushFunc_setTextureImage, METH_O},
    {"setTransform", (PyCFunction)Sbk_QBrushFunc_setTransform, METH_O},
    {"style", (PyCFunction)Sbk_QBrushFunc_style, METH_NOARGS},
    {"swap", (PyCFunction)Sbk_QBrushFunc_swap, METH_O},
    {"texture", (PyCFunction)Sbk_QBrushFunc_texture, METH_NOARGS},
    {"textureImage", (PyCFunction)Sbk_QBrushFunc_textureImage, METH_NOARGS},
    {"transform", (PyCFunction)Sbk_QBrushFunc_transform, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QBrush___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QBrushFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QBrush)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QBrush)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QBrush) [reverse operator]
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

    Sbk_QBrushFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QBrushFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QBrush&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QBrush&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QBrushFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QBrush&) [reverse operator]
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

    Sbk_QBrushFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QBrush.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QBrush_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QBrush& cppSelf = *(((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
                // operator!=(const QBrush & b) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QBrush cppArg0_local = ::QBrush();
                ::QBrush* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
                // operator==(const QBrush & b) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QBrush cppArg0_local = ::QBrush();
                ::QBrush* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
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
            goto Sbk_QBrush_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QBrush_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QBrush_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QBrush_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QBrush__repr__(PyObject* self)
{
    ::QBrush* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)self));
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
static PyNumberMethods Sbk_QBrush_TypeAsNumber;

static SbkObjectType Sbk_QBrush_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QBrush",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QBrush__repr__,
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
    /*tp_traverse*/         Sbk_QBrush_traverse,
    /*tp_clear*/            Sbk_QBrush_clear,
    /*tp_richcompare*/      Sbk_QBrush_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QBrush_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QBrush_Init,
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
static void QBrush_PythonToCpp_QBrush_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QBrush_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QBrush_PythonToCpp_QBrush_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBrush_Type))
        return QBrush_PythonToCpp_QBrush_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QBrush_PTR_CppToPython_QBrush(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QBrush*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QBrush_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* QBrush_COPY_CppToPython_QBrush(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QBrush_Type, new ::QBrush(*((::QBrush*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void QBrush_PythonToCpp_QBrush_COPY(PyObject* pyIn, void* cppOut) {
    *((::QBrush*)cppOut) = *((::QBrush*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_QBrush_PythonToCpp_QBrush_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QBrush_Type))
        return QBrush_PythonToCpp_QBrush_COPY;
    return 0;
}

// Implicit conversions.
static void PySide_QtCore_Qt_BrushStyle_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    ::Qt::BrushStyle cppIn = ((::Qt::BrushStyle)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX]), pyIn, &cppIn);
    *((::QBrush*)cppOut) = ::QBrush(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_BrushStyle_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_BRUSHSTYLE_IDX], pyIn))
        return PySide_QtCore_Qt_BrushStyle_PythonToCpp_QBrush;
    return 0;
}

static void PySide_QtCore_Qt_GlobalColor_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    ::Qt::GlobalColor cppIn = ((::Qt::GlobalColor)0);
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX]), pyIn, &cppIn);
    *((::QBrush*)cppOut) = ::QBrush(cppIn);
}
static PythonToCppFunc is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtCoreTypes[SBK_QT_GLOBALCOLOR_IDX], pyIn))
        return PySide_QtCore_Qt_GlobalColor_PythonToCpp_QBrush;
    return 0;
}

static void constQColorREF_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    *((::QBrush*)cppOut) = ::QBrush(*((::QColor*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQColorREF_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QCOLOR_IDX], pyIn))
        return constQColorREF_PythonToCpp_QBrush;
    return 0;
}

static void constQGradientREF_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    *((::QBrush*)cppOut) = ::QBrush(*((::QGradient*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQGradientREF_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QGRADIENT_IDX], pyIn))
        return constQGradientREF_PythonToCpp_QBrush;
    return 0;
}

static void constQImageREF_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    *((::QBrush*)cppOut) = ::QBrush(*((::QImage*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQImageREF_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QIMAGE_IDX], pyIn))
        return constQImageREF_PythonToCpp_QBrush;
    return 0;
}

static void constQPixmapREF_PythonToCpp_QBrush(PyObject* pyIn, void* cppOut) {
    *((::QBrush*)cppOut) = ::QBrush(*((::QPixmap*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], (SbkObject*)pyIn)));
}
static PythonToCppFunc is_constQPixmapREF_PythonToCpp_QBrush_Convertible(PyObject* pyIn) {
    if (SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QPIXMAP_IDX], pyIn))
        return constQPixmapREF_PythonToCpp_QBrush;
    return 0;
}

void init_QBrush(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QBrush_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QBrush_TypeAsNumber.nb_rshift = Sbk_QBrushFunc___rshift__;
    Sbk_QBrush_TypeAsNumber.nb_lshift = Sbk_QBrushFunc___lshift__;
    Sbk_QBrush_Type.super.ht_type.tp_as_number = &Sbk_QBrush_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QBrush_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QBrush", "QBrush",
        &Sbk_QBrush_Type, &Shiboken::callCppDestructor< ::QBrush >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QBrush_Type,
        QBrush_PythonToCpp_QBrush_PTR,
        is_QBrush_PythonToCpp_QBrush_PTR_Convertible,
        QBrush_PTR_CppToPython_QBrush,
        QBrush_COPY_CppToPython_QBrush);

    Shiboken::Conversions::registerConverterName(converter, "QBrush");
    Shiboken::Conversions::registerConverterName(converter, "QBrush*");
    Shiboken::Conversions::registerConverterName(converter, "QBrush&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QBrush).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        QBrush_PythonToCpp_QBrush_COPY,
        is_QBrush_PythonToCpp_QBrush_COPY_Convertible);
    // Add implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_BrushStyle_PythonToCpp_QBrush,
        is_PySide_QtCore_Qt_BrushStyle_PythonToCpp_QBrush_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PySide_QtCore_Qt_GlobalColor_PythonToCpp_QBrush,
        is_PySide_QtCore_Qt_GlobalColor_PythonToCpp_QBrush_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQColorREF_PythonToCpp_QBrush,
        is_constQColorREF_PythonToCpp_QBrush_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQGradientREF_PythonToCpp_QBrush,
        is_constQGradientREF_PythonToCpp_QBrush_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQImageREF_PythonToCpp_QBrush,
        is_constQImageREF_PythonToCpp_QBrush_Convertible);
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        constQPixmapREF_PythonToCpp_QBrush,
        is_constQPixmapREF_PythonToCpp_QBrush_Convertible);


    qRegisterMetaType< ::QBrush >("QBrush");
}
