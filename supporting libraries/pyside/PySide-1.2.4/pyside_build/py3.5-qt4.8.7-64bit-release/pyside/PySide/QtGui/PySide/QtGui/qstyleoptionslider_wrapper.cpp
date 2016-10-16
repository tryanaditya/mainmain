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

#include "qstyleoptionslider_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionSlider_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionSlider >()))
        return -1;

    ::QStyleOptionSlider* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionSlider", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionSlider()
    // 1: QStyleOptionSlider(QStyleOptionSlider)
    // 2: QStyleOptionSlider(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionSlider()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionSlider(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionSlider(QStyleOptionSlider)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionSlider_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionSlider()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionSlider()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionSlider();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionSlider(const QStyleOptionSlider & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionSlider* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionSlider(QStyleOptionSlider)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionSlider(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionSlider(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionSlider(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionSlider(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionSlider >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionSlider_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionSlider_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionSlider", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionSlider", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionSlider_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionSlider_get_tickInterval(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->tickInterval;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_tickInterval(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tickInterval' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tickInterval', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->tickInterval;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->tickInterval = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_minimum(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->minimum;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_minimum(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'minimum' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'minimum', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->minimum;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->minimum = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_notchTarget(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->notchTarget);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_notchTarget(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'notchTarget' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'notchTarget', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->notchTarget;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_maximum(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->maximum;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_maximum(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'maximum' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'maximum', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->maximum;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->maximum = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_sliderPosition(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->sliderPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_sliderPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'sliderPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'sliderPosition', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->sliderPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->sliderPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_dialWrapping(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->dialWrapping;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_dialWrapping(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'dialWrapping' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'dialWrapping', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->dialWrapping;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->dialWrapping = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_sliderValue(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->sliderValue;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_sliderValue(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'sliderValue' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'sliderValue', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->sliderValue;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->sliderValue = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_singleStep(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->singleStep;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_singleStep(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'singleStep' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'singleStep', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->singleStep;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->singleStep = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_tickPosition(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    ::QSlider::TickPosition cppOut_local = cppSelf->tickPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSLIDER_TICKPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_tickPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tickPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSLIDER_TICKPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tickPosition', 'TickPosition' or convertible type expected");
        return -1;
    }

    ::QSlider::TickPosition cppOut_local = cppSelf->tickPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->tickPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_pageStep(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->pageStep;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_pageStep(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'pageStep' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'pageStep', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->pageStep;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->pageStep = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_orientation(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    ::Qt::Orientation cppOut_local = cppSelf->orientation;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_orientation(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'orientation' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'orientation', 'Orientation' or convertible type expected");
        return -1;
    }

    ::Qt::Orientation cppOut_local = cppSelf->orientation;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->orientation = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionSlider_get_upsideDown(PyObject* self, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->upsideDown;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionSlider_set_upsideDown(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionSlider* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionSlider*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'upsideDown' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'upsideDown', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->upsideDown;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->upsideDown = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionSlider
static PyGetSetDef Sbk_QStyleOptionSlider_getsetlist[] = {
    {const_cast<char*>("tickInterval"), Sbk_QStyleOptionSlider_get_tickInterval, Sbk_QStyleOptionSlider_set_tickInterval},
    {const_cast<char*>("minimum"), Sbk_QStyleOptionSlider_get_minimum, Sbk_QStyleOptionSlider_set_minimum},
    {const_cast<char*>("notchTarget"), Sbk_QStyleOptionSlider_get_notchTarget, Sbk_QStyleOptionSlider_set_notchTarget},
    {const_cast<char*>("maximum"), Sbk_QStyleOptionSlider_get_maximum, Sbk_QStyleOptionSlider_set_maximum},
    {const_cast<char*>("sliderPosition"), Sbk_QStyleOptionSlider_get_sliderPosition, Sbk_QStyleOptionSlider_set_sliderPosition},
    {const_cast<char*>("dialWrapping"), Sbk_QStyleOptionSlider_get_dialWrapping, Sbk_QStyleOptionSlider_set_dialWrapping},
    {const_cast<char*>("sliderValue"), Sbk_QStyleOptionSlider_get_sliderValue, Sbk_QStyleOptionSlider_set_sliderValue},
    {const_cast<char*>("singleStep"), Sbk_QStyleOptionSlider_get_singleStep, Sbk_QStyleOptionSlider_set_singleStep},
    {const_cast<char*>("tickPosition"), Sbk_QStyleOptionSlider_get_tickPosition, Sbk_QStyleOptionSlider_set_tickPosition},
    {const_cast<char*>("pageStep"), Sbk_QStyleOptionSlider_get_pageStep, Sbk_QStyleOptionSlider_set_pageStep},
    {const_cast<char*>("orientation"), Sbk_QStyleOptionSlider_get_orientation, Sbk_QStyleOptionSlider_set_orientation},
    {const_cast<char*>("upsideDown"), Sbk_QStyleOptionSlider_get_upsideDown, Sbk_QStyleOptionSlider_set_upsideDown},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionSlider_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionSlider_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionSlider_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionSlider",
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
    /*tp_traverse*/         Sbk_QStyleOptionSlider_traverse,
    /*tp_clear*/            Sbk_QStyleOptionSlider_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionSlider_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionSlider_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionSlider_Init,
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
static void QStyleOptionSlider_StyleOptionType_PythonToCpp_QStyleOptionSlider_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionSlider::StyleOptionType*)cppOut) = (::QStyleOptionSlider::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionSlider_StyleOptionType_PythonToCpp_QStyleOptionSlider_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionSlider_StyleOptionType_PythonToCpp_QStyleOptionSlider_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionSlider_StyleOptionType_CppToPython_QStyleOptionSlider_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionSlider::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionSlider_StyleOptionVersion_PythonToCpp_QStyleOptionSlider_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionSlider::StyleOptionVersion*)cppOut) = (::QStyleOptionSlider::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionSlider_StyleOptionVersion_PythonToCpp_QStyleOptionSlider_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionSlider_StyleOptionVersion_PythonToCpp_QStyleOptionSlider_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionSlider_StyleOptionVersion_CppToPython_QStyleOptionSlider_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionSlider::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionSlider_PythonToCpp_QStyleOptionSlider_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionSlider_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionSlider_PythonToCpp_QStyleOptionSlider_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionSlider_Type))
        return QStyleOptionSlider_PythonToCpp_QStyleOptionSlider_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionSlider_PTR_CppToPython_QStyleOptionSlider(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionSlider*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionSlider_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionSlider(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionSlider_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionSlider", "QStyleOptionSlider*",
        &Sbk_QStyleOptionSlider_Type, &Shiboken::callCppDestructor< ::QStyleOptionSlider >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONCOMPLEX_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionSlider_Type,
        QStyleOptionSlider_PythonToCpp_QStyleOptionSlider_PTR,
        is_QStyleOptionSlider_PythonToCpp_QStyleOptionSlider_PTR_Convertible,
        QStyleOptionSlider_PTR_CppToPython_QStyleOptionSlider);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionSlider");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionSlider*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionSlider&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionSlider).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionSlider_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionSlider.StyleOptionType",
        "QStyleOptionSlider::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionSlider_Type, "Type", (long) QStyleOptionSlider::Type))
        return ;
    // Register converter for enum 'QStyleOptionSlider::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX],
            QStyleOptionSlider_StyleOptionType_CppToPython_QStyleOptionSlider_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionSlider_StyleOptionType_PythonToCpp_QStyleOptionSlider_StyleOptionType,
            is_QStyleOptionSlider_StyleOptionType_PythonToCpp_QStyleOptionSlider_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionSlider::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionSlider_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionSlider.StyleOptionVersion",
        "QStyleOptionSlider::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionSlider_Type, "Version", (long) QStyleOptionSlider::Version))
        return ;
    // Register converter for enum 'QStyleOptionSlider::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX],
            QStyleOptionSlider_StyleOptionVersion_CppToPython_QStyleOptionSlider_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionSlider_StyleOptionVersion_PythonToCpp_QStyleOptionSlider_StyleOptionVersion,
            is_QStyleOptionSlider_StyleOptionVersion_PythonToCpp_QStyleOptionSlider_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONSLIDER_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionSlider::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionSlider::StyleOptionType >("QStyleOptionSlider::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionSlider::StyleOptionVersion >("QStyleOptionSlider::StyleOptionVersion");
}
