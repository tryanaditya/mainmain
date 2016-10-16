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

#include "qstyleoptionheader_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionHeader_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionHeader >()))
        return -1;

    ::QStyleOptionHeader* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionHeader", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionHeader()
    // 1: QStyleOptionHeader(QStyleOptionHeader)
    // 2: QStyleOptionHeader(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionHeader()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionHeader(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionHeader(QStyleOptionHeader)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionHeader_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionHeader()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionHeader()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionHeader();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionHeader(const QStyleOptionHeader & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionHeader* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionHeader(QStyleOptionHeader)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionHeader(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionHeader(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionHeader(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionHeader(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionHeader >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionHeader_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionHeader_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionHeader", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionHeader", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionHeader_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionHeader_get_section(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->section;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_section(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'section' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'section', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->section;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->section = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_sortIndicator(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    ::QStyleOptionHeader::SortIndicator cppOut_local = cppSelf->sortIndicator;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_sortIndicator(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'sortIndicator' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'sortIndicator', 'SortIndicator' or convertible type expected");
        return -1;
    }

    ::QStyleOptionHeader::SortIndicator cppOut_local = cppSelf->sortIndicator;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->sortIndicator = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_position(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    ::QStyleOptionHeader::SectionPosition cppOut_local = cppSelf->position;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_position(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'position' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'position', 'SectionPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionHeader::SectionPosition cppOut_local = cppSelf->position;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->position = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_icon(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'icon' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'icon', 'QIcon' or convertible type expected");
        return -1;
    }

    ::QIcon& cppOut_ptr = cppSelf->icon;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_textAlignment(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->textAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_textAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'textAlignment' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'textAlignment', 'Alignment' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::AlignmentFlag> cppOut_local = cppSelf->textAlignment;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->textAlignment = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_text(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'text' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'text', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->text;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_selectedPosition(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    ::QStyleOptionHeader::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_selectedPosition(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'selectedPosition' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'selectedPosition', 'SelectedPosition' or convertible type expected");
        return -1;
    }

    ::QStyleOptionHeader::SelectedPosition cppOut_local = cppSelf->selectedPosition;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->selectedPosition = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_iconAlignment(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppSelf->iconAlignment);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_iconAlignment(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'iconAlignment' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'iconAlignment', 'Alignment' or convertible type expected");
        return -1;
    }

    ::QFlags<Qt::AlignmentFlag> cppOut_local = cppSelf->iconAlignment;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->iconAlignment = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionHeader_get_orientation(PyObject* self, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
    ::Qt::Orientation cppOut_local = cppSelf->orientation;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ORIENTATION_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionHeader_set_orientation(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionHeader* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionHeader*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX], (SbkObject*)self));
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

// Getters and Setters for QStyleOptionHeader
static PyGetSetDef Sbk_QStyleOptionHeader_getsetlist[] = {
    {const_cast<char*>("section"), Sbk_QStyleOptionHeader_get_section, Sbk_QStyleOptionHeader_set_section},
    {const_cast<char*>("sortIndicator"), Sbk_QStyleOptionHeader_get_sortIndicator, Sbk_QStyleOptionHeader_set_sortIndicator},
    {const_cast<char*>("position"), Sbk_QStyleOptionHeader_get_position, Sbk_QStyleOptionHeader_set_position},
    {const_cast<char*>("icon"), Sbk_QStyleOptionHeader_get_icon, Sbk_QStyleOptionHeader_set_icon},
    {const_cast<char*>("textAlignment"), Sbk_QStyleOptionHeader_get_textAlignment, Sbk_QStyleOptionHeader_set_textAlignment},
    {const_cast<char*>("text"), Sbk_QStyleOptionHeader_get_text, Sbk_QStyleOptionHeader_set_text},
    {const_cast<char*>("selectedPosition"), Sbk_QStyleOptionHeader_get_selectedPosition, Sbk_QStyleOptionHeader_set_selectedPosition},
    {const_cast<char*>("iconAlignment"), Sbk_QStyleOptionHeader_get_iconAlignment, Sbk_QStyleOptionHeader_set_iconAlignment},
    {const_cast<char*>("orientation"), Sbk_QStyleOptionHeader_get_orientation, Sbk_QStyleOptionHeader_set_orientation},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionHeader_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionHeader_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionHeader_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionHeader",
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
    /*tp_traverse*/         Sbk_QStyleOptionHeader_traverse,
    /*tp_clear*/            Sbk_QStyleOptionHeader_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionHeader_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionHeader_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionHeader_Init,
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
static void QStyleOptionHeader_StyleOptionType_PythonToCpp_QStyleOptionHeader_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionHeader::StyleOptionType*)cppOut) = (::QStyleOptionHeader::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionHeader_StyleOptionType_PythonToCpp_QStyleOptionHeader_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionHeader_StyleOptionType_PythonToCpp_QStyleOptionHeader_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionHeader_StyleOptionType_CppToPython_QStyleOptionHeader_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionHeader::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionHeader_StyleOptionVersion_PythonToCpp_QStyleOptionHeader_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionHeader::StyleOptionVersion*)cppOut) = (::QStyleOptionHeader::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionHeader_StyleOptionVersion_PythonToCpp_QStyleOptionHeader_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionHeader_StyleOptionVersion_PythonToCpp_QStyleOptionHeader_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionHeader_StyleOptionVersion_CppToPython_QStyleOptionHeader_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionHeader::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionHeader_SectionPosition_PythonToCpp_QStyleOptionHeader_SectionPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionHeader::SectionPosition*)cppOut) = (::QStyleOptionHeader::SectionPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionHeader_SectionPosition_PythonToCpp_QStyleOptionHeader_SectionPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX]))
        return QStyleOptionHeader_SectionPosition_PythonToCpp_QStyleOptionHeader_SectionPosition;
    return 0;
}
static PyObject* QStyleOptionHeader_SectionPosition_CppToPython_QStyleOptionHeader_SectionPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionHeader::SectionPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX], castCppIn);

}

static void QStyleOptionHeader_SelectedPosition_PythonToCpp_QStyleOptionHeader_SelectedPosition(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionHeader::SelectedPosition*)cppOut) = (::QStyleOptionHeader::SelectedPosition) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionHeader_SelectedPosition_PythonToCpp_QStyleOptionHeader_SelectedPosition_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX]))
        return QStyleOptionHeader_SelectedPosition_PythonToCpp_QStyleOptionHeader_SelectedPosition;
    return 0;
}
static PyObject* QStyleOptionHeader_SelectedPosition_CppToPython_QStyleOptionHeader_SelectedPosition(const void* cppIn) {
    int castCppIn = *((::QStyleOptionHeader::SelectedPosition*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX], castCppIn);

}

static void QStyleOptionHeader_SortIndicator_PythonToCpp_QStyleOptionHeader_SortIndicator(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionHeader::SortIndicator*)cppOut) = (::QStyleOptionHeader::SortIndicator) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionHeader_SortIndicator_PythonToCpp_QStyleOptionHeader_SortIndicator_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX]))
        return QStyleOptionHeader_SortIndicator_PythonToCpp_QStyleOptionHeader_SortIndicator;
    return 0;
}
static PyObject* QStyleOptionHeader_SortIndicator_CppToPython_QStyleOptionHeader_SortIndicator(const void* cppIn) {
    int castCppIn = *((::QStyleOptionHeader::SortIndicator*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionHeader_PythonToCpp_QStyleOptionHeader_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionHeader_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionHeader_PythonToCpp_QStyleOptionHeader_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionHeader_Type))
        return QStyleOptionHeader_PythonToCpp_QStyleOptionHeader_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionHeader_PTR_CppToPython_QStyleOptionHeader(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionHeader*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionHeader_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionHeader(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionHeader_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionHeader", "QStyleOptionHeader*",
        &Sbk_QStyleOptionHeader_Type, &Shiboken::callCppDestructor< ::QStyleOptionHeader >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionHeader_Type,
        QStyleOptionHeader_PythonToCpp_QStyleOptionHeader_PTR,
        is_QStyleOptionHeader_PythonToCpp_QStyleOptionHeader_PTR_Convertible,
        QStyleOptionHeader_PTR_CppToPython_QStyleOptionHeader);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionHeader).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionHeader_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionHeader.StyleOptionType",
        "QStyleOptionHeader::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionHeader_Type, "Type", (long) QStyleOptionHeader::Type))
        return ;
    // Register converter for enum 'QStyleOptionHeader::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX],
            QStyleOptionHeader_StyleOptionType_CppToPython_QStyleOptionHeader_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionHeader_StyleOptionType_PythonToCpp_QStyleOptionHeader_StyleOptionType,
            is_QStyleOptionHeader_StyleOptionType_PythonToCpp_QStyleOptionHeader_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionHeader_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionHeader.StyleOptionVersion",
        "QStyleOptionHeader::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionHeader_Type, "Version", (long) QStyleOptionHeader::Version))
        return ;
    // Register converter for enum 'QStyleOptionHeader::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX],
            QStyleOptionHeader_StyleOptionVersion_CppToPython_QStyleOptionHeader_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionHeader_StyleOptionVersion_PythonToCpp_QStyleOptionHeader_StyleOptionVersion,
            is_QStyleOptionHeader_StyleOptionVersion_PythonToCpp_QStyleOptionHeader_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'SectionPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionHeader_Type,
        "SectionPosition",
        "PySide.QtGui.QStyleOptionHeader.SectionPosition",
        "QStyleOptionHeader::SectionPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "Beginning", (long) QStyleOptionHeader::Beginning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "Middle", (long) QStyleOptionHeader::Middle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "End", (long) QStyleOptionHeader::End))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "OnlyOneSection", (long) QStyleOptionHeader::OnlyOneSection))
        return ;
    // Register converter for enum 'QStyleOptionHeader::SectionPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX],
            QStyleOptionHeader_SectionPosition_CppToPython_QStyleOptionHeader_SectionPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionHeader_SectionPosition_PythonToCpp_QStyleOptionHeader_SectionPosition,
            is_QStyleOptionHeader_SectionPosition_PythonToCpp_QStyleOptionHeader_SectionPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SECTIONPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader::SectionPosition");
        Shiboken::Conversions::registerConverterName(converter, "SectionPosition");
    }
    // End of 'SectionPosition' enum.

    // Initialization of enum 'SelectedPosition'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionHeader_Type,
        "SelectedPosition",
        "PySide.QtGui.QStyleOptionHeader.SelectedPosition",
        "QStyleOptionHeader::SelectedPosition");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "NotAdjacent", (long) QStyleOptionHeader::NotAdjacent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "NextIsSelected", (long) QStyleOptionHeader::NextIsSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "PreviousIsSelected", (long) QStyleOptionHeader::PreviousIsSelected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX],
        &Sbk_QStyleOptionHeader_Type, "NextAndPreviousAreSelected", (long) QStyleOptionHeader::NextAndPreviousAreSelected))
        return ;
    // Register converter for enum 'QStyleOptionHeader::SelectedPosition'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX],
            QStyleOptionHeader_SelectedPosition_CppToPython_QStyleOptionHeader_SelectedPosition);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionHeader_SelectedPosition_PythonToCpp_QStyleOptionHeader_SelectedPosition,
            is_QStyleOptionHeader_SelectedPosition_PythonToCpp_QStyleOptionHeader_SelectedPosition_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SELECTEDPOSITION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader::SelectedPosition");
        Shiboken::Conversions::registerConverterName(converter, "SelectedPosition");
    }
    // End of 'SelectedPosition' enum.

    // Initialization of enum 'SortIndicator'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionHeader_Type,
        "SortIndicator",
        "PySide.QtGui.QStyleOptionHeader.SortIndicator",
        "QStyleOptionHeader::SortIndicator");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX],
        &Sbk_QStyleOptionHeader_Type, "None", (long) QStyleOptionHeader::None))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX],
        &Sbk_QStyleOptionHeader_Type, "SortUp", (long) QStyleOptionHeader::SortUp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX],
        &Sbk_QStyleOptionHeader_Type, "SortDown", (long) QStyleOptionHeader::SortDown))
        return ;
    // Register converter for enum 'QStyleOptionHeader::SortIndicator'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX],
            QStyleOptionHeader_SortIndicator_CppToPython_QStyleOptionHeader_SortIndicator);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionHeader_SortIndicator_PythonToCpp_QStyleOptionHeader_SortIndicator,
            is_QStyleOptionHeader_SortIndicator_PythonToCpp_QStyleOptionHeader_SortIndicator_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONHEADER_SORTINDICATOR_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionHeader::SortIndicator");
        Shiboken::Conversions::registerConverterName(converter, "SortIndicator");
    }
    // End of 'SortIndicator' enum.


    qRegisterMetaType< ::QStyleOptionHeader::StyleOptionType >("QStyleOptionHeader::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionHeader::StyleOptionVersion >("QStyleOptionHeader::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionHeader::SectionPosition >("QStyleOptionHeader::SectionPosition");
    qRegisterMetaType< ::QStyleOptionHeader::SelectedPosition >("QStyleOptionHeader::SelectedPosition");
    qRegisterMetaType< ::QStyleOptionHeader::SortIndicator >("QStyleOptionHeader::SortIndicator");
}
