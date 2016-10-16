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

#include "qpainterpath_element_wrapper.h"

// Extra includes
#include <QPainterPath>
#include <qpoint.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QPainterPath_Element_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QPainterPath::Element >()))
        return -1;

    ::QPainterPath::Element* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "Element", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: Element()
    // 1: Element(QPainterPath::Element)
    if (numArgs == 0) {
        overloadId = 0; // Element()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (pyArgs[0])))) {
        overloadId = 1; // Element(QPainterPath::Element)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QPainterPath_Element_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // Element()
        {

            if (!PyErr_Occurred()) {
                // Element()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainterPath::Element();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // Element(const QPainterPath::Element & Element)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QPainterPath::Element cppArg0_local = ::QPainterPath::Element();
            ::QPainterPath::Element* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // Element(QPainterPath::Element)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QPainterPath::Element(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QPainterPath::Element >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QPainterPath_Element_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QPainterPath_Element_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QPainterPath::Element", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.Element", overloads);
        return -1;
}

static PyObject* Sbk_QPainterPath_ElementFunc_isCurveTo(PyObject* self)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCurveTo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainterPath::Element*>(cppSelf)->isCurveTo();
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

static PyObject* Sbk_QPainterPath_ElementFunc_isLineTo(PyObject* self)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLineTo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainterPath::Element*>(cppSelf)->isLineTo();
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

static PyObject* Sbk_QPainterPath_ElementFunc_isMoveTo(PyObject* self)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMoveTo()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QPainterPath::Element*>(cppSelf)->isMoveTo();
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

static PyObject* Sbk_QPainterPath_Element___copy__(PyObject* self)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPainterPath::Element& cppSelf = *(((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self)));
    PyObject* pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], &cppSelf);
    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QPainterPath_Element_methods[] = {
    {"isCurveTo", (PyCFunction)Sbk_QPainterPath_ElementFunc_isCurveTo, METH_NOARGS},
    {"isLineTo", (PyCFunction)Sbk_QPainterPath_ElementFunc_isLineTo, METH_NOARGS},
    {"isMoveTo", (PyCFunction)Sbk_QPainterPath_ElementFunc_isMoveTo, METH_NOARGS},

    {"__copy__", (PyCFunction)Sbk_QPainterPath_Element___copy__, METH_NOARGS},
    {0} // Sentinel
};

// Rich comparison
static PyObject* Sbk_QPainterPath_Element_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QPainterPath::Element& cppSelf = *(((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_NE:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (pyArg)))) {
                // operator!=(const QPainterPath::Element & e) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPainterPath::Element cppArg0_local = ::QPainterPath::Element();
                ::QPainterPath::Element* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], pythonToCpp))
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
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (pyArg)))) {
                // operator==(const QPainterPath::Element & e) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QPainterPath::Element cppArg0_local = ::QPainterPath::Element();
                ::QPainterPath::Element* cppArg0 = &cppArg0_local;
                if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], pythonToCpp))
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
            goto Sbk_QPainterPath_Element_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QPainterPath_Element_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

static PyObject* Sbk_QPainterPath_Element_get_x(PyObject* self, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_QPainterPath_Element_set_x(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QPainterPath_Element_get_y(PyObject* self, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_QPainterPath_Element_set_y(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QPainterPath_Element_get_type(PyObject* self, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    ::QPainterPath::ElementType cppOut_local = cppSelf->type;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QPainterPath_Element_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::QPainterPath::Element* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'ElementType' or convertible type expected");
        return -1;
    }

    ::QPainterPath::ElementType cppOut_local = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->type = cppOut_local;

    return 0;
}

// Getters and Setters for Element
static PyGetSetDef Sbk_QPainterPath_Element_getsetlist[] = {
    {const_cast<char*>("x"), Sbk_QPainterPath_Element_get_x, Sbk_QPainterPath_Element_set_x},
    {const_cast<char*>("y"), Sbk_QPainterPath_Element_get_y, Sbk_QPainterPath_Element_set_y},
    {const_cast<char*>("type"), Sbk_QPainterPath_Element_get_type, Sbk_QPainterPath_Element_set_type},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QPainterPath_Element_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QPainterPath_Element_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QPainterPath_Element_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QPainterPath.Element",
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
    /*tp_traverse*/         Sbk_QPainterPath_Element_traverse,
    /*tp_clear*/            Sbk_QPainterPath_Element_clear,
    /*tp_richcompare*/      Sbk_QPainterPath_Element_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QPainterPath_Element_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QPainterPath_Element_getsetlist,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QPainterPath_Element_Init,
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
static void Element_PythonToCpp_Element_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QPainterPath_Element_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Element_PythonToCpp_Element_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainterPath_Element_Type))
        return Element_PythonToCpp_Element_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Element_PTR_CppToPython_Element(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QPainterPath::Element*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QPainterPath_Element_Type, const_cast<void*>(cppIn), false, false, typeName);
}

// C++ to Python copy conversion.
static PyObject* Element_COPY_CppToPython_Element(const void* cppIn) {
    return Shiboken::Object::newObject(&Sbk_QPainterPath_Element_Type, new ::QPainterPath::Element(*((::QPainterPath::Element*)cppIn)), true, true);
}

// Python to C++ copy conversion.
static void Element_PythonToCpp_Element_COPY(PyObject* pyIn, void* cppOut) {
    *((::QPainterPath::Element*)cppOut) = *((::QPainterPath::Element*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX], (SbkObject*)pyIn));
}
static PythonToCppFunc is_Element_PythonToCpp_Element_COPY_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QPainterPath_Element_Type))
        return Element_PythonToCpp_Element_COPY;
    return 0;
}

void init_QPainterPath_Element(PyObject* enclosingClass)
{
    SbkPySide_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QPainterPath_Element_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "Element", "QPainterPath::Element",
        &Sbk_QPainterPath_Element_Type, &Shiboken::callCppDestructor< ::QPainterPath::Element >, 0, 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QPainterPath_Element_Type,
        Element_PythonToCpp_Element_PTR,
        is_Element_PythonToCpp_Element_PTR_Convertible,
        Element_PTR_CppToPython_Element,
        Element_COPY_CppToPython_Element);

    Shiboken::Conversions::registerConverterName(converter, "QPainterPath::Element");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPath::Element*");
    Shiboken::Conversions::registerConverterName(converter, "QPainterPath::Element&");
    Shiboken::Conversions::registerConverterName(converter, "Element");
    Shiboken::Conversions::registerConverterName(converter, "Element*");
    Shiboken::Conversions::registerConverterName(converter, "Element&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QPainterPath::Element).name());

    // Add Python to C++ copy (value, not pointer neither reference) conversion to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(converter,
        Element_PythonToCpp_Element_COPY,
        is_Element_PythonToCpp_Element_COPY_Convertible);


    qRegisterMetaType< ::QPainterPath::Element >("Element");
    qRegisterMetaType< ::QPainterPath::Element >("QPainterPath::Element");
}
