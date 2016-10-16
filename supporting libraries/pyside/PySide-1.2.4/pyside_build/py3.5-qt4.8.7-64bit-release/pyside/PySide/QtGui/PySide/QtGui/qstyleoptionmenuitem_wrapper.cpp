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

#include "qstyleoptionmenuitem_wrapper.h"

// Extra includes
#include <qstyleoption.h>
#include <qwidget.h>



// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStyleOptionMenuItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStyleOptionMenuItem >()))
        return -1;

    ::QStyleOptionMenuItem* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QStyleOptionMenuItem", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QStyleOptionMenuItem()
    // 1: QStyleOptionMenuItem(QStyleOptionMenuItem)
    // 2: QStyleOptionMenuItem(int)
    if (numArgs == 0) {
        overloadId = 0; // QStyleOptionMenuItem()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 2; // QStyleOptionMenuItem(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (pyArgs[0])))) {
        overloadId = 1; // QStyleOptionMenuItem(QStyleOptionMenuItem)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStyleOptionMenuItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStyleOptionMenuItem()
        {

            if (!PyErr_Occurred()) {
                // QStyleOptionMenuItem()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionMenuItem();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStyleOptionMenuItem(const QStyleOptionMenuItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStyleOptionMenuItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionMenuItem(QStyleOptionMenuItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionMenuItem(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStyleOptionMenuItem(int version)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStyleOptionMenuItem(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStyleOptionMenuItem(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStyleOptionMenuItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStyleOptionMenuItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStyleOptionMenuItem_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QStyleOptionMenuItem", "int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStyleOptionMenuItem", overloads);
        return -1;
}

static PyMethodDef Sbk_QStyleOptionMenuItem_methods[] = {

    {0} // Sentinel
};

static PyObject* Sbk_QStyleOptionMenuItem_get_menuHasCheckableItems(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->menuHasCheckableItems;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_menuHasCheckableItems(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'menuHasCheckableItems' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'menuHasCheckableItems', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->menuHasCheckableItems;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->menuHasCheckableItems = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_menuRect(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &(cppSelf->menuRect), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_menuRect(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'menuRect' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'menuRect', 'QRect' or convertible type expected");
        return -1;
    }

    ::QRect& cppOut_ptr = cppSelf->menuRect;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_checkType(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    ::QStyleOptionMenuItem::CheckType cppOut_local = cppSelf->checkType;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_checkType(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'checkType' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'checkType', 'CheckType' or convertible type expected");
        return -1;
    }

    ::QStyleOptionMenuItem::CheckType cppOut_local = cppSelf->checkType;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->checkType = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_icon(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &(cppSelf->icon), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_icon(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionMenuItem_get_checked(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    bool cppOut_local = cppSelf->checked;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_checked(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'checked' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'checked', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->checked;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->checked = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_maxIconWidth(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->maxIconWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_maxIconWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'maxIconWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'maxIconWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->maxIconWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->maxIconWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_tabWidth(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    int cppOut_local = cppSelf->tabWidth;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_tabWidth(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'tabWidth' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'tabWidth', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->tabWidth;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->tabWidth = cppOut_local;

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_text(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->text);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_text(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
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

static PyObject* Sbk_QStyleOptionMenuItem_get_font(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    PyObject* pyOut = Shiboken::Object::newObject((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &(cppSelf->font), false, true);
    Shiboken::Object::setParent(self, pyOut);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_font(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'font' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'font', 'QFont' or convertible type expected");
        return -1;
    }

    ::QFont& cppOut_ptr = cppSelf->font;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_QStyleOptionMenuItem_get_menuItemType(PyObject* self, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    ::QStyleOptionMenuItem::MenuItemType cppOut_local = cppSelf->menuItemType;
    PyObject* pyOut = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX]), &cppOut_local);
    return pyOut;
}
static int Sbk_QStyleOptionMenuItem_set_menuItemType(PyObject* self, PyObject* pyIn, void*)
{
    ::QStyleOptionMenuItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStyleOptionMenuItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX], (SbkObject*)self));
    if (pyIn == 0) {
        PyErr_SetString(PyExc_TypeError, "'menuItemType' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp;
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX]), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'menuItemType', 'MenuItemType' or convertible type expected");
        return -1;
    }

    ::QStyleOptionMenuItem::MenuItemType cppOut_local = cppSelf->menuItemType;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->menuItemType = cppOut_local;

    return 0;
}

// Getters and Setters for QStyleOptionMenuItem
static PyGetSetDef Sbk_QStyleOptionMenuItem_getsetlist[] = {
    {const_cast<char*>("menuHasCheckableItems"), Sbk_QStyleOptionMenuItem_get_menuHasCheckableItems, Sbk_QStyleOptionMenuItem_set_menuHasCheckableItems},
    {const_cast<char*>("menuRect"), Sbk_QStyleOptionMenuItem_get_menuRect, Sbk_QStyleOptionMenuItem_set_menuRect},
    {const_cast<char*>("checkType"), Sbk_QStyleOptionMenuItem_get_checkType, Sbk_QStyleOptionMenuItem_set_checkType},
    {const_cast<char*>("icon"), Sbk_QStyleOptionMenuItem_get_icon, Sbk_QStyleOptionMenuItem_set_icon},
    {const_cast<char*>("checked"), Sbk_QStyleOptionMenuItem_get_checked, Sbk_QStyleOptionMenuItem_set_checked},
    {const_cast<char*>("maxIconWidth"), Sbk_QStyleOptionMenuItem_get_maxIconWidth, Sbk_QStyleOptionMenuItem_set_maxIconWidth},
    {const_cast<char*>("tabWidth"), Sbk_QStyleOptionMenuItem_get_tabWidth, Sbk_QStyleOptionMenuItem_set_tabWidth},
    {const_cast<char*>("text"), Sbk_QStyleOptionMenuItem_get_text, Sbk_QStyleOptionMenuItem_set_text},
    {const_cast<char*>("font"), Sbk_QStyleOptionMenuItem_get_font, Sbk_QStyleOptionMenuItem_set_font},
    {const_cast<char*>("menuItemType"), Sbk_QStyleOptionMenuItem_get_menuItemType, Sbk_QStyleOptionMenuItem_set_menuItemType},
    {0}  // Sentinel
};

} // extern "C"

static int Sbk_QStyleOptionMenuItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStyleOptionMenuItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QStyleOptionMenuItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStyleOptionMenuItem",
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
    /*tp_traverse*/         Sbk_QStyleOptionMenuItem_traverse,
    /*tp_clear*/            Sbk_QStyleOptionMenuItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStyleOptionMenuItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QStyleOptionMenuItem_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStyleOptionMenuItem_Init,
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
static void QStyleOptionMenuItem_StyleOptionType_PythonToCpp_QStyleOptionMenuItem_StyleOptionType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionMenuItem::StyleOptionType*)cppOut) = (::QStyleOptionMenuItem::StyleOptionType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionMenuItem_StyleOptionType_PythonToCpp_QStyleOptionMenuItem_StyleOptionType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX]))
        return QStyleOptionMenuItem_StyleOptionType_PythonToCpp_QStyleOptionMenuItem_StyleOptionType;
    return 0;
}
static PyObject* QStyleOptionMenuItem_StyleOptionType_CppToPython_QStyleOptionMenuItem_StyleOptionType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionMenuItem::StyleOptionType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX], castCppIn);

}

static void QStyleOptionMenuItem_StyleOptionVersion_PythonToCpp_QStyleOptionMenuItem_StyleOptionVersion(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionMenuItem::StyleOptionVersion*)cppOut) = (::QStyleOptionMenuItem::StyleOptionVersion) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionMenuItem_StyleOptionVersion_PythonToCpp_QStyleOptionMenuItem_StyleOptionVersion_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX]))
        return QStyleOptionMenuItem_StyleOptionVersion_PythonToCpp_QStyleOptionMenuItem_StyleOptionVersion;
    return 0;
}
static PyObject* QStyleOptionMenuItem_StyleOptionVersion_CppToPython_QStyleOptionMenuItem_StyleOptionVersion(const void* cppIn) {
    int castCppIn = *((::QStyleOptionMenuItem::StyleOptionVersion*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX], castCppIn);

}

static void QStyleOptionMenuItem_MenuItemType_PythonToCpp_QStyleOptionMenuItem_MenuItemType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionMenuItem::MenuItemType*)cppOut) = (::QStyleOptionMenuItem::MenuItemType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionMenuItem_MenuItemType_PythonToCpp_QStyleOptionMenuItem_MenuItemType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX]))
        return QStyleOptionMenuItem_MenuItemType_PythonToCpp_QStyleOptionMenuItem_MenuItemType;
    return 0;
}
static PyObject* QStyleOptionMenuItem_MenuItemType_CppToPython_QStyleOptionMenuItem_MenuItemType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionMenuItem::MenuItemType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX], castCppIn);

}

static void QStyleOptionMenuItem_CheckType_PythonToCpp_QStyleOptionMenuItem_CheckType(PyObject* pyIn, void* cppOut) {
    *((::QStyleOptionMenuItem::CheckType*)cppOut) = (::QStyleOptionMenuItem::CheckType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStyleOptionMenuItem_CheckType_PythonToCpp_QStyleOptionMenuItem_CheckType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX]))
        return QStyleOptionMenuItem_CheckType_PythonToCpp_QStyleOptionMenuItem_CheckType;
    return 0;
}
static PyObject* QStyleOptionMenuItem_CheckType_CppToPython_QStyleOptionMenuItem_CheckType(const void* cppIn) {
    int castCppIn = *((::QStyleOptionMenuItem::CheckType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStyleOptionMenuItem_PythonToCpp_QStyleOptionMenuItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStyleOptionMenuItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStyleOptionMenuItem_PythonToCpp_QStyleOptionMenuItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStyleOptionMenuItem_Type))
        return QStyleOptionMenuItem_PythonToCpp_QStyleOptionMenuItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStyleOptionMenuItem_PTR_CppToPython_QStyleOptionMenuItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStyleOptionMenuItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStyleOptionMenuItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStyleOptionMenuItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStyleOptionMenuItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStyleOptionMenuItem", "QStyleOptionMenuItem*",
        &Sbk_QStyleOptionMenuItem_Type, &Shiboken::callCppDestructor< ::QStyleOptionMenuItem >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTYLEOPTION_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStyleOptionMenuItem_Type,
        QStyleOptionMenuItem_PythonToCpp_QStyleOptionMenuItem_PTR,
        is_QStyleOptionMenuItem_PythonToCpp_QStyleOptionMenuItem_PTR_Convertible,
        QStyleOptionMenuItem_PTR_CppToPython_QStyleOptionMenuItem);

    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem*");
    Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStyleOptionMenuItem).name());


    // Initialization of enums.

    // Initialization of enum 'StyleOptionType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionMenuItem_Type,
        "StyleOptionType",
        "PySide.QtGui.QStyleOptionMenuItem.StyleOptionType",
        "QStyleOptionMenuItem::StyleOptionType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Type", (long) QStyleOptionMenuItem::Type))
        return ;
    // Register converter for enum 'QStyleOptionMenuItem::StyleOptionType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX],
            QStyleOptionMenuItem_StyleOptionType_CppToPython_QStyleOptionMenuItem_StyleOptionType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionMenuItem_StyleOptionType_PythonToCpp_QStyleOptionMenuItem_StyleOptionType,
            is_QStyleOptionMenuItem_StyleOptionType_PythonToCpp_QStyleOptionMenuItem_StyleOptionType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem::StyleOptionType");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionType");
    }
    // End of 'StyleOptionType' enum.

    // Initialization of enum 'StyleOptionVersion'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionMenuItem_Type,
        "StyleOptionVersion",
        "PySide.QtGui.QStyleOptionMenuItem.StyleOptionVersion",
        "QStyleOptionMenuItem::StyleOptionVersion");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Version", (long) QStyleOptionMenuItem::Version))
        return ;
    // Register converter for enum 'QStyleOptionMenuItem::StyleOptionVersion'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX],
            QStyleOptionMenuItem_StyleOptionVersion_CppToPython_QStyleOptionMenuItem_StyleOptionVersion);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionMenuItem_StyleOptionVersion_PythonToCpp_QStyleOptionMenuItem_StyleOptionVersion,
            is_QStyleOptionMenuItem_StyleOptionVersion_PythonToCpp_QStyleOptionMenuItem_StyleOptionVersion_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_STYLEOPTIONVERSION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem::StyleOptionVersion");
        Shiboken::Conversions::registerConverterName(converter, "StyleOptionVersion");
    }
    // End of 'StyleOptionVersion' enum.

    // Initialization of enum 'MenuItemType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionMenuItem_Type,
        "MenuItemType",
        "PySide.QtGui.QStyleOptionMenuItem.MenuItemType",
        "QStyleOptionMenuItem::MenuItemType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Normal", (long) QStyleOptionMenuItem::Normal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "DefaultItem", (long) QStyleOptionMenuItem::DefaultItem))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Separator", (long) QStyleOptionMenuItem::Separator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "SubMenu", (long) QStyleOptionMenuItem::SubMenu))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Scroller", (long) QStyleOptionMenuItem::Scroller))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "TearOff", (long) QStyleOptionMenuItem::TearOff))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Margin", (long) QStyleOptionMenuItem::Margin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "EmptyArea", (long) QStyleOptionMenuItem::EmptyArea))
        return ;
    // Register converter for enum 'QStyleOptionMenuItem::MenuItemType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX],
            QStyleOptionMenuItem_MenuItemType_CppToPython_QStyleOptionMenuItem_MenuItemType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionMenuItem_MenuItemType_PythonToCpp_QStyleOptionMenuItem_MenuItemType,
            is_QStyleOptionMenuItem_MenuItemType_PythonToCpp_QStyleOptionMenuItem_MenuItemType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_MENUITEMTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem::MenuItemType");
        Shiboken::Conversions::registerConverterName(converter, "MenuItemType");
    }
    // End of 'MenuItemType' enum.

    // Initialization of enum 'CheckType'.
    SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStyleOptionMenuItem_Type,
        "CheckType",
        "PySide.QtGui.QStyleOptionMenuItem.CheckType",
        "QStyleOptionMenuItem::CheckType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "NotCheckable", (long) QStyleOptionMenuItem::NotCheckable))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "Exclusive", (long) QStyleOptionMenuItem::Exclusive))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX],
        &Sbk_QStyleOptionMenuItem_Type, "NonExclusive", (long) QStyleOptionMenuItem::NonExclusive))
        return ;
    // Register converter for enum 'QStyleOptionMenuItem::CheckType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX],
            QStyleOptionMenuItem_CheckType_CppToPython_QStyleOptionMenuItem_CheckType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStyleOptionMenuItem_CheckType_PythonToCpp_QStyleOptionMenuItem_CheckType,
            is_QStyleOptionMenuItem_CheckType_PythonToCpp_QStyleOptionMenuItem_CheckType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTYLEOPTIONMENUITEM_CHECKTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStyleOptionMenuItem::CheckType");
        Shiboken::Conversions::registerConverterName(converter, "CheckType");
    }
    // End of 'CheckType' enum.


    qRegisterMetaType< ::QStyleOptionMenuItem::StyleOptionType >("QStyleOptionMenuItem::StyleOptionType");
    qRegisterMetaType< ::QStyleOptionMenuItem::StyleOptionVersion >("QStyleOptionMenuItem::StyleOptionVersion");
    qRegisterMetaType< ::QStyleOptionMenuItem::MenuItemType >("QStyleOptionMenuItem::MenuItemType");
    qRegisterMetaType< ::QStyleOptionMenuItem::CheckType >("QStyleOptionMenuItem::CheckType");
}
