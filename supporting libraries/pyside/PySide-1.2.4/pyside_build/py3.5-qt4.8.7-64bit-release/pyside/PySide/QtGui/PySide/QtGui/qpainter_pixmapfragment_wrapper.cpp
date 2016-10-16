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

#include "qpainter_pixmapfragment_wrapper.h"

// Extra includes
#include <QPainter>
#include <qpoint.h>
#include <qrect.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPainter_PixmapFragment_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPainter::PixmapFragment >()))
        return -1;

    ::QPainter::PixmapFragment* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "PixmapFragment", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: PixmapFragment()
    // 1: PixmapFragment(QPainter::PixmapFragment)
    if (numArgs == 0) {
        overloadId = 0; // PixmapFragment()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // PixmapFragment(QPainter::PixmapFragment)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainter_PixmapFragment_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // PixmapFragment()
        {

            if (!PyErr_Occurred()) {
                // PixmapFragment()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainter::PixmapFragment();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // PixmapFragment(const QPainter::PixmapFragment & PixmapFragment)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPainter::PixmapFragment cppArg0_local = ::QPainter::PixmapFragment();
            ::QPainter::PixmapFragment* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // PixmapFragment(QPainter::PixmapFragment)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainter::PixmapFragment(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPainter::PixmapFragment >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPainter_PixmapFragment_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPainter_PixmapFragment_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPainter::PixmapFragment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.PixmapFragment", overloads);
        return -1;
}

static PyObject* Sbk_QPainter_PixmapFragmentFunc_create(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:create", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: create(QPointF,QRectF,qreal,qreal,qreal,qreal)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QPOINTF_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 0; // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4])))) {
                    if (numArgs == 5) {
                        overloadId = 0; // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
                    } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5])))) {
                        overloadId = 0; // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainter_PixmapFragmentFunc_create_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "scaleX");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): got multiple values for keyword argument 'scaleX'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2]))))
                    goto Sbk_QPainter_PixmapFragmentFunc_create_TypeError;
            }
            value = PyDict_GetItemString(kwds, "scaleY");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): got multiple values for keyword argument 'scaleY'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3]))))
                    goto Sbk_QPainter_PixmapFragmentFunc_create_TypeError;
            }
            value = PyDict_GetItemString(kwds, "rotation");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): got multiple values for keyword argument 'rotation'.");
                return 0;
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[4]))))
                    goto Sbk_QPainter_PixmapFragmentFunc_create_TypeError;
            }
            value = PyDict_GetItemString(kwds, "opacity");
            if (value && pyArgs[5]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.PixmapFragment.create(): got multiple values for keyword argument 'opacity'.");
                return 0;
            } else if (value) {
                pyArgs[5] = value;
                if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[5]))))
                    goto Sbk_QPainter_PixmapFragmentFunc_create_TypeError;
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
        ::QRectF cppArg1_local = ::QRectF();
        ::QRectF* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);

        qreal cppArg2 = 1;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3 = 1;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        qreal cppArg4 = 0;
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);
        qreal cppArg5 = 1;
        if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

        if (!PyErr_Occurred()) {
            // create(QPointF,QRectF,qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QPainter::PixmapFragment cppResult = ::QPainter::PixmapFragment::create(*cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QPainter_PixmapFragmentFunc_create_TypeError:
        const char* overloads[] = {"PySide.QtCore.QPointF, PySide.QtCore.QRectF, float = 1, float = 1, float = 0, float = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.PixmapFragment.create", overloads);
        return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPainter::PixmapFragment& cppSelf = *(((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPainter_PixmapFragment_methods[] = {
    {"create", (PyCFunction)Sbk_QPainter_PixmapFragmentFunc_create, METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {"__copy__", (PyCFunction)Sbk_QPainter_PixmapFragment___copy__, METH_NOARGS},
    {0} // Sentinel
};

static PyObject* Sbk_QPainter_PixmapFragment_get_width(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->width);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_width(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'width' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'width', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->width;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_scaleY(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->scaleY);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_scaleY(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'scaleY' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'scaleY', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->scaleY;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_x(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_x(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'x' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->x;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_opacity(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->opacity);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_opacity(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'opacity' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'opacity', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->opacity;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_y(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_y(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'y' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->y;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_rotation(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->rotation);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_rotation(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'rotation' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'rotation', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->rotation;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_sourceLeft(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->sourceLeft);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_sourceLeft(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'sourceLeft' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'sourceLeft', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->sourceLeft;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_height(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->height);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_height(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'height' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'height', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->height;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_sourceTop(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->sourceTop);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_sourceTop(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'sourceTop' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'sourceTop', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->sourceTop;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QPainter_PixmapFragment_get_scaleX(PyObject* self, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->scaleX);
    return pyOut;
}
static int Sbk_QPainter_PixmapFragment_set_scaleX(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainter::PixmapFragment* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'scaleX' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'scaleX', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->scaleX;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for PixmapFragment
static PyGetSetDef Sbk_QPainter_PixmapFragment_getsetlist[] = {
    {const_cast<char*>("width"), Sbk_QPainter_PixmapFragment_get_width, Sbk_QPainter_PixmapFragment_set_width},
    {const_cast<char*>("scaleY"), Sbk_QPainter_PixmapFragment_get_scaleY, Sbk_QPainter_PixmapFragment_set_scaleY},
    {const_cast<char*>("x"), Sbk_QPainter_PixmapFragment_get_x, Sbk_QPainter_PixmapFragment_set_x},
    {const_cast<char*>("opacity"), Sbk_QPainter_PixmapFragment_get_opacity, Sbk_QPainter_PixmapFragment_set_opacity},
    {const_cast<char*>("y"), Sbk_QPainter_PixmapFragment_get_y, Sbk_QPainter_PixmapFragment_set_y},
    {const_cast<char*>("rotation"), Sbk_QPainter_PixmapFragment_get_rotation, Sbk_QPainter_PixmapFragment_set_rotation},
    {const_cast<char*>("sourceLeft"), Sbk_QPainter_PixmapFragment_get_sourceLeft, Sbk_QPainter_PixmapFragment_set_sourceLeft},
    {const_cast<char*>("height"), Sbk_QPainter_PixmapFragment_get_height, Sbk_QPainter_PixmapFragment_set_height},
    {const_cast<char*>("sourceTop"), Sbk_QPainter_PixmapFragment_get_sourceTop, Sbk_QPainter_PixmapFragment_set_sourceTop},
    {const_cast<char*>("scaleX"), Sbk_QPainter_PixmapFragment_get_scaleX, Sbk_QPainter_PixmapFragment_set_scaleX},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QPainter_PixmapFragment_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPainter_PixmapFragment_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPainter_PixmapFragment_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPainter.PixmapFragment",
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
    /*tp_traverse*/         Sbk_QPainter_PixmapFragment_traverse,
    /*tp_clear*/            Sbk_QPainter_PixmapFragment_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPainter_PixmapFragment_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QPainter_PixmapFragment_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPainter_PixmapFragment_Init,
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
static void PixmapFragment_PythonToCpp_PixmapFragment_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPainter_PixmapFragment_Type, pyIn, cppOut);
}
static PythonToCppFunc is_PixmapFragment_PythonToCpp_PixmapFragment_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainter_PixmapFragment_Type))
        return PixmapFragment_PythonToCpp_PixmapFragment_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PixmapFragment_PTR_CppToPython_PixmapFragment(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPainter::PixmapFragment*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPainter_PixmapFragment_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* PixmapFragment_COPY_CppToPython_PixmapFragment(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPainter_PixmapFragment_Type, new ::QPainter::PixmapFragment(*((::QPainter::PixmapFragment*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void PixmapFragment_PythonToCpp_PixmapFragment_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPainter::PixmapFragment*)cppOut) = *((::QPainter::PixmapFragment*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_PixmapFragment_PythonToCpp_PixmapFragment_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainter_PixmapFragment_Type))
        return PixmapFragment_PythonToCpp_PixmapFragment_COPY;
    return 0;
}

void init_QPainter_PixmapFragment(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPainter_PixmapFragment_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "PixmapFragment", "QPainter::PixmapFragment",
        &Sbk_QPainter_PixmapFragment_Type, &Shiboken::callCppDestructor< ::QPainter::PixmapFragment >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPainter_PixmapFragment_Type,
        PixmapFragment_PythonToCpp_PixmapFragment_PTR,
        is_PixmapFragment_PythonToCpp_PixmapFragment_PTR_Convertible,
        PixmapFragment_PTR_CppToPython_PixmapFragment,
        PixmapFragment_COPY_CppToPython_PixmapFragment);

    Shiboken::Conversions::registerConverterName(converter, "QPainter::PixmapFragment");
    Shiboken::Conversions::registerConverterName(converter, "QPainter::PixmapFragment*");
    Shiboken::Conversions::registerConverterName(converter, "QPainter::PixmapFragment&");
    Shiboken::Conversions::registerConverterName(converter, "PixmapFragment");
    Shiboken::Conversions::registerConverterName(converter, "PixmapFragment*");
    Shiboken::Conversions::registerConverterName(converter, "PixmapFragment&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPainter::PixmapFragment).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        PixmapFragment_PythonToCpp_PixmapFragment_COPY,
        is_PixmapFragment_PythonToCpp_PixmapFragment_COPY_Convertible);


    qRegisterMetaType< ::QPainter::PixmapFragment >("PixmapFragment");
    qRegisterMetaType< ::QPainter::PixmapFragment >("QPainter::PixmapFragment");
}
