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

#include "qstyleoptiongraphicsitem_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qtransform.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionGraphicsItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionGraphicsItem >()))
        return -1;

    ::QStyleOptionGraphicsItem* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionGraphicsItem", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionGraphicsItem()
    // 1: QStyleOptionGraphicsItem(QStyleOptionGraphicsItem)
    // 2: QStyleOptionGraphicsItem(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionGraphicsItem()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionGraphicsItem(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionGraphicsItem(QStyleOptionGraphicsItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionGraphicsItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionGraphicsItem()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionGraphicsItem()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGraphicsItem();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionGraphicsItem(const QStyleOptionGraphicsItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionGraphicsItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionGraphicsItem(QStyleOptionGraphicsItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGraphicsItem(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionGraphicsItem(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionGraphicsItem(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionGraphicsItem(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionGraphicsItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionGraphicsItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionGraphicsItem_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionGraphicsItem", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionGraphicsItem", overloads);
        return -1;
}

static PyObject* Sbk_QStyleOptionGraphicsItemFunc_levelOfDetailFromTransform(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: levelOfDetailFromTransform(QTransform)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTRANSFORM_IDX], (pyArg)))) {
        overloadId = 0; // levelOfDetailFromTransform(QTransform)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionGraphicsItemFunc_levelOfDetailFromTransform_TypeError;

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
            // levelOfDetailFromTransform(QTransform)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = ::QStyleOptionGraphicsItem::levelOfDetailFromTransform(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStyleOptionGraphicsItemFunc_levelOfDetailFromTransform_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTransform", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStyleOptionGraphicsItem.levelOfDetailFromTransform", overloads);
        return 0;
}

static PyMethodDef Sbk_QStyleOptionGraphicsItem_methods[] = {
    {"levelOfDetailFromTransform", (PyCFunction)Sbk_QStyleOptionGraphicsItemFunc_levelOfDetailFromTransform, METH_O|METH_STATIC},

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionGraphicsItem_get_exposedRect(PyObject* self, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &(cppSelf->exposedRect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionGraphicsItem_set_exposedRect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'exposedRect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'exposedRect', 'QRectF' or convertible type expected");
        return -1;
    }

    ::QRectF& cppOut_ptr = cppSelf->exposedRect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionGraphicsItem_get_matrix(PyObject* self, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], &(cppSelf->matrix), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionGraphicsItem_set_matrix(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'matrix' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMATRIX_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'matrix', 'QMatrix' or convertible type expected");
        return -1;
    }

    ::QMatrix& cppOut_ptr = cppSelf->matrix;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionGraphicsItem_get_levelOfDetail(PyObject* self, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppSelf->levelOfDetail);
    return pyOut;
}
static int Sbk_QStyleOptionGraphicsItem_set_levelOfDetail(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionGraphicsItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionGraphicsItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'levelOfDetail' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'levelOfDetail', 'qreal' or convertible type expected");
        return -1;
    }

    qreal& cppOut_ptr = cppSelf->levelOfDetail;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for QStyleOptionGraphicsItem
static PyGetSetDef Sbk_QStyleOptionGraphicsItem_getsetlist[] = {
    {const_cast<char*>("exposedRect"), Sbk_QStyleOptionGraphicsItem_get_exposedRect, Sbk_QStyleOptionGraphicsItem_set_exposedRect},
    {const_cast<char*>("matrix"), Sbk_QStyleOptionGraphicsItem_get_matrix, Sbk_QStyleOptionGraphicsItem_set_matrix},
    {const_cast<char*>("levelOfDetail"), Sbk_QStyleOptionGraphicsItem_get_levelOfDetail, Sbk_QStyleOptionGraphicsItem_set_levelOfDetail},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionGraphicsItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionGraphicsItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionGraphicsItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionGraphicsItem",
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
    /*tp_traverse*/         Sbk_QStyleOptionGraphicsItem_traverse,
    /*tp_clear*/            Sbk_QStyleOptionGraphicsItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionGraphicsItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionGraphicsItem_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionGraphicsItem_Init,
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
static void QStyleOptionGraphicsItem_StyleOptionType_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionGraphicsItem::StyleOptionType*)cppOut) = (::QStyleOptionGraphicsItem::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionGraphicsItem_StyleOptionType_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionGraphicsItem_StyleOptionType_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionGraphicsItem_StyleOptionType_CppToPython_QStyleOptionGraphicsItem_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionGraphicsItem::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionGraphicsItem_StyleOptionVersion_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionGraphicsItem::StyleOptionVersion*)cppOut) = (::QStyleOptionGraphicsItem::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionGraphicsItem_StyleOptionVersion_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionGraphicsItem_StyleOptionVersion_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionGraphicsItem_StyleOptionVersion_CppToPython_QStyleOptionGraphicsItem_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionGraphicsItem::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionGraphicsItem_PythonToCpp_QStyleOptionGraphicsItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionGraphicsItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionGraphicsItem_PythonToCpp_QStyleOptionGraphicsItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionGraphicsItem_Type))
        return QStyleOptionGraphicsItem_PythonToCpp_QStyleOptionGraphicsItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionGraphicsItem_PTR_CppToPython_QStyleOptionGraphicsItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionGraphicsItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionGraphicsItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionGraphicsItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionGraphicsItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionGraphicsItem", "QStyleOptionGraphicsItem*",
        &Sbk_QStyleOptionGraphicsItem_Type, &Shiboken::callCppDestructor< ::QStyleOptionGraphicsItem >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionGraphicsItem_Type,
        QStyleOptionGraphicsItem_PythonToCpp_QStyleOptionGraphicsItem_PTR,
        is_QStyleOptionGraphicsItem_PythonToCpp_QStyleOptionGraphicsItem_PTR_Convertible,
        QStyleOptionGraphicsItem_PTR_CppToPython_QStyleOptionGraphicsItem);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGraphicsItem");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGraphicsItem*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGraphicsItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionGraphicsItem).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionGraphicsItem_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionGraphicsItem.StyleOptionType",
        "QStyleOptionGraphicsItem::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionGraphicsItem_Type, "Type", (long) QStyleOptionGraphicsItem::Type))
        return ;
    // Register converter for enum 'QStyleOptionGraphicsItem::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX],
            QStyleOptionGraphicsItem_StyleOptionType_CppToPython_QStyleOptionGraphicsItem_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionGraphicsItem_StyleOptionType_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionType,
            is_QStyleOptionGraphicsItem_StyleOptionType_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGraphicsItem::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionGraphicsItem_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionGraphicsItem.StyleOptionVersion",
        "QStyleOptionGraphicsItem::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionGraphicsItem_Type, "Version", (long) QStyleOptionGraphicsItem::Version))
        return ;
    // Register converter for enum 'QStyleOptionGraphicsItem::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX],
            QStyleOptionGraphicsItem_StyleOptionVersion_CppToPython_QStyleOptionGraphicsItem_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionGraphicsItem_StyleOptionVersion_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionVersion,
            is_QStyleOptionGraphicsItem_StyleOptionVersion_PythonToCpp_QStyleOptionGraphicsItem_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONGRAPHICSITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionGraphicsItem::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.


    qRegisterMetaType< ::QStyleOptionGraphicsItem::StyleOptionType >("QStyleOptionGraphicsItem::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionGraphicsItem::StyleOptionVersion >("QStyleOptionGraphicsItem::StyleOptionVersion");
}
