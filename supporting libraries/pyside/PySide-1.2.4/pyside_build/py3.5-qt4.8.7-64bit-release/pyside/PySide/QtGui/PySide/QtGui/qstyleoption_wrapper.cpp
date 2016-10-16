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

#include "qstyleoption_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOption_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOption >()))
        return -1;

    ::QStyleOption* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOption(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QStyleOption", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOption(QStyleOption)
    // 1: QStyleOption(int,int)
    if (numArgs == 0) {
        overloadId = 1; // QStyleOption(int,int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QStyleOption(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // QStyleOption(int,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (pyArgs[0])))) {
        overloadId = 0; // QStyleOption(QStyleOption)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOption_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOption(const QStyleOption & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOption* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOption(QStyleOption)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOption(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOption(int version, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "version");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOption(): got multiple values for keyword argument 'version'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QStyleOption_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStyleOption(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QStyleOption_Init_TypeError;
                }
            }
            int cppArg0 = QStyleOption::Version;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QStyleOption::SO_Default;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QStyleOption(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOption(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOption >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOption_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOption_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStyleOption", "int = QStyleOption.Version, int = SO_Default", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOption", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionFunc_initFrom(PyObject* self, PyObject* pyArg)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: initFrom(const QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // initFrom(const QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionFunc_initFrom_TypeError;

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

    Sbk_QStyleOptionFunc_initFrom_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStyleOption.initFrom", overloads);
        return 0;
}

static PyMethodDef Sbk_QStyleOption_methods[] = {
    {"initFrom", (PyCFunction)Sbk_QStyleOptionFunc_initFrom, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOption_get_palette(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], &(cppSelf->palette), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOption_set_palette(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'palette' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPALETTE_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'palette', 'QPalette' or convertible type expected");
        return -1;
    }

    ::QPalette& cppOut_ptr = cppSelf->palette;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOption_get_version(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->version;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOption_set_version(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'version' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'version', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->version;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->version = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOption_get_direction(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    ::Qt::LayoutDirection cppOut_local = cppSelf->direction;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOption_set_direction(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'direction' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_LAYOUTDIRECTION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'direction', 'LayoutDirection' or convertible type expected");
        return -1;
    }

    ::Qt::LayoutDirection cppOut_local = cppSelf->direction;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->direction = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOption_get_rect(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &(cppSelf->rect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOption_set_rect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'rect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'rect', 'QRect' or convertible type expected");
        return -1;
    }

    ::QRect& cppOut_ptr = cppSelf->rect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOption_get_type(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->type;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOption_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->type = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOption_get_state(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), &cppSelf->state);
    return pyOut;
}
static int Sbk_QStyleOption_set_state(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'state' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QSTYLE_STATEFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'state', 'State' or convertible type expected");
        return -1;
    }

    ::QFlags<QStyle::StateFlag> cppOut_local = cppSelf->state;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->state = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOption_get_fontMetrics(PyObject* self, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], &(cppSelf->fontMetrics), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOption_set_fontMetrics(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'fontMetrics' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONTMETRICS_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'fontMetrics', 'QFontMetrics' or convertible type expected");
        return -1;
    }

    ::QFontMetrics& cppOut_ptr = cppSelf->fontMetrics;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOption
static PyGetSetDef Sbk_QStyleOption_getsetlist[] = {
    {const_cast<char*>("palette"), Sbk_QStyleOption_get_palette, Sbk_QStyleOption_set_palette},
    {const_cast<char*>("version"), Sbk_QStyleOption_get_version, Sbk_QStyleOption_set_version},
    {const_cast<char*>("direction"), Sbk_QStyleOption_get_direction, Sbk_QStyleOption_set_direction},
    {const_cast<char*>("rect"), Sbk_QStyleOption_get_rect, Sbk_QStyleOption_set_rect},
    {const_cast<char*>("type"), Sbk_QStyleOption_get_type, Sbk_QStyleOption_set_type},
    {const_cast<char*>("state"), Sbk_QStyleOption_get_state, Sbk_QStyleOption_set_state},
    {const_cast<char*>("fontMetrics"), Sbk_QStyleOption_get_fontMetrics, Sbk_QStyleOption_set_fontMetrics},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOption_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOption_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
extern "C"
{
static PyObject* Sbk_QStyleOption__repr__(PyObject* self)
{
    ::QStyleOption* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOption*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX], (SbkObject*)self));
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDebug dbg(&buffer);
    dbg << cppSelf;
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
static SbkObjectType Sbk_QStyleOption_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOption",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             Sbk_QStyleOption__repr__,
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
    /*tp_traverse*/         Sbk_QStyleOption_traverse,
    /*tp_clear*/            Sbk_QStyleOption_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOption_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOption_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOption_Init,
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
static void QStyleOption_OptionType_PythonToCpp_QStyleOption_OptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOption::OptionType*)cppOut) = (::QStyleOption::OptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOption_OptionType_PythonToCpp_QStyleOption_OptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX]))
        return QStyleOption_OptionType_PythonToCpp_QStyleOption_OptionType;
    return 0;
}
static PyObject* QStyleOption_OptionType_CppToPython_QStyleOption_OptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOption::OptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX], castCppIn);

}

static void QStyleOption_StyleOptionType_PythonToCpp_QStyleOption_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOption::StyleOptionType*)cppOut) = (::QStyleOption::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOption_StyleOptionType_PythonToCpp_QStyleOption_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX]))
        return QStyleOption_StyleOptionType_PythonToCpp_QStyleOption_StyleOptionType;
    return 0;
}
static PyObject* QStyleOption_StyleOptionType_CppToPython_QStyleOption_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOption::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOption_StyleOptionVersion_PythonToCpp_QStyleOption_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOption::StyleOptionVersion*)cppOut) = (::QStyleOption::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOption_StyleOptionVersion_PythonToCpp_QStyleOption_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX]))
        return QStyleOption_StyleOptionVersion_PythonToCpp_QStyleOption_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOption_StyleOptionVersion_CppToPython_QStyleOption_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOption::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOption_PythonToCpp_QStyleOption_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOption_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOption_PythonToCpp_QStyleOption_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOption_Type))
        return QStyleOption_PythonToCpp_QStyleOption_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOption_PTR_CppToPython_QStyleOption(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOption*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOption_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOption(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOption_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOption", "QStyleOption*",
        &Sbk_QStyleOption_Type, &Shiboken::callCppDestructor< ::QStyleOption >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOption_Type,
        QStyleOption_PythonToCpp_QStyleOption_PTR,
        is_QStyleOption_PythonToCpp_QStyleOption_PTR_Convertible,
        QStyleOption_PTR_CppToPython_QStyleOption);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOption");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOption*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOption&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOption).name());


    // Initialization of enums.

    // Initialization of enum 'OptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOption_Type,
        "OptionType",
        "PySide.QtGui.QStyleOption.OptionType",
        "QStyleOption::OptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Default", (long) QStyleOption::SO_Default))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_FocusRect", (long) QStyleOption::SO_FocusRect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Button", (long) QStyleOption::SO_Button))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Tab", (long) QStyleOption::SO_Tab))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_MenuItem", (long) QStyleOption::SO_MenuItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Frame", (long) QStyleOption::SO_Frame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ProgressBar", (long) QStyleOption::SO_ProgressBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ToolBox", (long) QStyleOption::SO_ToolBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Header", (long) QStyleOption::SO_Header))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Q3DockWindow", (long) QStyleOption::SO_Q3DockWindow))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_DockWidget", (long) QStyleOption::SO_DockWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Q3ListViewItem", (long) QStyleOption::SO_Q3ListViewItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ViewItem", (long) QStyleOption::SO_ViewItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_TabWidgetFrame", (long) QStyleOption::SO_TabWidgetFrame))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_TabBarBase", (long) QStyleOption::SO_TabBarBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_RubberBand", (long) QStyleOption::SO_RubberBand))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ToolBar", (long) QStyleOption::SO_ToolBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_GraphicsItem", (long) QStyleOption::SO_GraphicsItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Complex", (long) QStyleOption::SO_Complex))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Slider", (long) QStyleOption::SO_Slider))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_SpinBox", (long) QStyleOption::SO_SpinBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ToolButton", (long) QStyleOption::SO_ToolButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ComboBox", (long) QStyleOption::SO_ComboBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_Q3ListView", (long) QStyleOption::SO_Q3ListView))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_TitleBar", (long) QStyleOption::SO_TitleBar))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_GroupBox", (long) QStyleOption::SO_GroupBox))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_SizeGrip", (long) QStyleOption::SO_SizeGrip))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_CustomBase", (long) QStyleOption::SO_CustomBase))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "SO_ComplexCustomBase", (long) QStyleOption::SO_ComplexCustomBase))
        return ;
    // Register converter for enum 'QStyleOption::OptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX],
            QStyleOption_OptionType_CppToPython_QStyleOption_OptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOption_OptionType_PythonToCpp_QStyleOption_OptionType,
            is_QStyleOption_OptionType_PythonToCpp_QStyleOption_OptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_OPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOption::OptionType");
        Shiboken::Conversions::registerConverterName(converter, "OptionType");
    }
    // End of 'OptionType' enum.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOption_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOption.StyleOptionType",
        "QStyleOption::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOption_Type, "Type", (long) QStyleOption::Type))
        return ;
    // Register converter for enum 'QStyleOption::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX],
            QStyleOption_StyleOptionType_CppToPython_QStyleOption_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOption_StyleOptionType_PythonToCpp_QStyleOption_StyleOptionType,
            is_QStyleOption_StyleOptionType_PythonToCpp_QStyleOption_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOption::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOption_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOption.StyleOptionVersion",
        "QStyleOption::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOption_Type, "Version", (long) QStyleOption::Version))
        return ;
    // Register converter for enum 'QStyleOption::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX],
            QStyleOption_StyleOptionVersion_CppToPython_QStyleOption_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOption_StyleOptionVersion_PythonToCpp_QStyleOption_StyleOptionVersion,
            is_QStyleOption_StyleOptionVersion_PythonToCpp_QStyleOption_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOption::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOption::OptionType >("QStyleOption::OptionType");
    qRegisterMetaType< ::QStyleOption::StyleOptionType >("QStyleOption::StyleOptionType");
    qRegisterMetaType< ::QStyleOption::StyleOptionVersion >("QStyleOption::StyleOptionVersion");
}
