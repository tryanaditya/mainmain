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

#include "qgraphicslayoutitem_wrapper.h"

// Extra includes
#include <qgraphicsitem.h>
#include <qgraphicslayoutitem.h>
#include <qrect.h>
#include <qsize.h>
#include <qsizepolicy.h>


// Native ---------------------------------------------------------

QGraphicsLayoutItemWrapper::QGraphicsLayoutItemWrapper(QGraphicsLayoutItem * parent, bool isLayout) : QGraphicsLayoutItem(parent, isLayout) {
    // ... middle
}

void QGraphicsLayoutItemWrapper::getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getContentsMargins"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QGraphicsLayoutItem::getContentsMargins(left, top, right, bottom);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }

    // Begin code injection

    // TEMPLATE - fix_native_return_number*,number*,number*,number* - START
    PyObject* _obj = pyResult.object();
    if (!PySequence_Check(_obj)
    || PySequence_Fast_GET_SIZE(_obj) != 4
    || !SbkNumber_Check(PySequence_Fast_GET_ITEM(_obj, 0))
    || !SbkNumber_Check(PySequence_Fast_GET_ITEM(_obj, 1))
    || !SbkNumber_Check(PySequence_Fast_GET_ITEM(_obj, 2))
    || !SbkNumber_Check(PySequence_Fast_GET_ITEM(_obj, 3))) {
    PyErr_SetString(PyExc_TypeError, "Sequence of 4 numbers expected");
    } else {
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(_obj, 0), (left));
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(_obj, 1), (top));
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(_obj, 2), (right));
    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), PySequence_Fast_GET_ITEM(_obj, 3), (bottom));
    }
    // TEMPLATE - fix_native_return_number*,number*,number*,number* - END

    // End of code injection
}

void QGraphicsLayoutItemWrapper::setGeometry(const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsLayoutItem::setGeometry(rect);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], &rect)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QSizeF QGraphicsLayoutItemWrapper::sizeHint(Qt::SizeHint which, const QSizeF & constraint) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSizeF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayoutItem.sizeHint()' not implemented.");
        return ::QSizeF();
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX]), &which),
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &constraint)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QSizeF();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppValueConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsLayoutItem.sizeHint", Shiboken::SbkType< QSizeF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSizeF();
    }
    ::QSizeF cppResult = ::QSizeF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsLayoutItemWrapper::updateGeometry()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsLayoutItem::updateGeometry();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QGraphicsLayoutItemWrapper::~QGraphicsLayoutItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsLayoutItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QGraphicsLayoutItem' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsLayoutItem >()))
        return -1;

    ::QGraphicsLayoutItemWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QGraphicsLayoutItem", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsLayoutItem(QGraphicsLayoutItem*,bool)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsLayoutItem(QGraphicsLayoutItem*,bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QGraphicsLayoutItem(QGraphicsLayoutItem*,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // QGraphicsLayoutItem(QGraphicsLayoutItem*,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItem_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsLayoutItem_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "isLayout");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem(): got multiple values for keyword argument 'isLayout'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_QGraphicsLayoutItem_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGraphicsLayoutItem* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QGraphicsLayoutItem(QGraphicsLayoutItem*,bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsLayoutItemWrapper(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsLayoutItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsLayoutItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsLayoutItem_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem = None, bool = false", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_contentsRect(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contentsRect()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->contentsRect();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_effectiveSizeHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.effectiveSizeHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.effectiveSizeHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:effectiveSizeHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: effectiveSizeHint(Qt::SizeHint,QSizeF)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // effectiveSizeHint(Qt::SizeHint,QSizeF)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1])))) {
            overloadId = 0; // effectiveSizeHint(Qt::SizeHint,QSizeF)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_effectiveSizeHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "constraint");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.effectiveSizeHint(): got multiple values for keyword argument 'constraint'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsLayoutItemFunc_effectiveSizeHint_TypeError;
            }
        }
        ::Qt::SizeHint cppArg0 = ((::Qt::SizeHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSizeF cppArg1_local = QSizeF();
        ::QSizeF* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // effectiveSizeHint(Qt::SizeHint,QSizeF)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->effectiveSizeHint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsLayoutItemFunc_effectiveSizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.SizeHint, PySide.QtCore.QSizeF = QSizeF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.effectiveSizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_geometry(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometry()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRectF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->geometry();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_getContentsMargins(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getContentsMargins(qreal*,qreal*,qreal*,qreal*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QGraphicsLayoutItem::getContentsMargins(&a, &b, &c, &d);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            // TEMPLATE - tuple_abcd_same_type - START
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &a));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &b));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &c));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &d));
            // TEMPLATE - tuple_abcd_same_type - END
            // TEMPLATE - fix_number*,number*,number*,number* - END

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_graphicsItem(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // graphicsItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsItem * cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->graphicsItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_isLayout(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLayout()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->isLayout();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_maximumHeight(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->maximumHeight();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_maximumSize(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->maximumSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_maximumWidth(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maximumWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->maximumWidth();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_minimumHeight(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->minimumHeight();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_minimumSize(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->minimumSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_minimumWidth(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // minimumWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->minimumWidth();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_ownedByLayout(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ownedByLayout()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->ownedByLayout();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_parentLayoutItem(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentLayoutItem()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsLayoutItem * cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->parentLayoutItem();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_preferredHeight(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredHeight()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->preferredHeight();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_preferredSize(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredSize()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->preferredSize();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_preferredWidth(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // preferredWidth()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->preferredWidth();
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

static PyObject* Sbk_QGraphicsLayoutItemFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setGeometry_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QRectF cppArg0_local = ::QRectF();
        ::QRectF* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setGeometry(QRectF)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsLayoutItem::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setGraphicsItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGraphicsItem(QGraphicsItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSITEM_IDX], (pyArg)))) {
        overloadId = 0; // setGraphicsItem(QGraphicsItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setGraphicsItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setGraphicsItem(QGraphicsItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGraphicsItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setGraphicsItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setGraphicsItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMaximumHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumHeight(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMaximumHeight(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMaximumHeight_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaximumHeight(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMaximumHeight_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setMaximumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMaximumSize(PyObject* self, PyObject* args)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setMaximumSize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMaximumSize(QSizeF)
    // 1: setMaximumSize(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setMaximumSize(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setMaximumSize(QSizeF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMaximumSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setMaximumSize(const QSizeF & size)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setMaximumSize(QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setMaximumSize(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setMaximumSize(qreal w, qreal h)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setMaximumSize(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setMaximumSize(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMaximumSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSizeF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.setMaximumSize", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMaximumWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaximumWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMaximumWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMaximumWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaximumWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaximumWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMaximumWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setMaximumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMinimumHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimumHeight(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMinimumHeight(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMinimumHeight_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMinimumHeight(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimumHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMinimumHeight_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setMinimumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMinimumSize(PyObject* self, PyObject* args)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setMinimumSize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setMinimumSize(QSizeF)
    // 1: setMinimumSize(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setMinimumSize(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setMinimumSize(QSizeF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMinimumSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setMinimumSize(const QSizeF & size)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setMinimumSize(QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setMinimumSize(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setMinimumSize(qreal w, qreal h)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setMinimumSize(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setMinimumSize(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMinimumSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSizeF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.setMinimumSize", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setMinimumWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMinimumWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setMinimumWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setMinimumWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMinimumWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMinimumWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setMinimumWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setMinimumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setOwnedByLayout(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setOwnedByLayout(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOwnedByLayout(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setOwnedByLayout_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOwnedByLayout(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setOwnedByLayout(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setOwnedByLayout_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setOwnedByLayout", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setParentLayoutItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setParentLayoutItem(QGraphicsLayoutItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // setParentLayoutItem(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setParentLayoutItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setParentLayoutItem(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setParentLayoutItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setParentLayoutItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setParentLayoutItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setPreferredHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPreferredHeight(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPreferredHeight(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setPreferredHeight_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPreferredHeight(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPreferredHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setPreferredHeight_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setPreferredHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setPreferredSize(PyObject* self, PyObject* args)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPreferredSize", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setPreferredSize(QSizeF)
    // 1: setPreferredSize(qreal,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 1; // setPreferredSize(qreal,qreal)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[0])))) {
        overloadId = 0; // setPreferredSize(QSizeF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setPreferredSize_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setPreferredSize(const QSizeF & size)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSizeF cppArg0_local = ::QSizeF();
            ::QSizeF* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setPreferredSize(QSizeF)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPreferredSize(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setPreferredSize(qreal w, qreal h)
        {
            qreal cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            qreal cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setPreferredSize(qreal,qreal)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setPreferredSize(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setPreferredSize_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSizeF", "float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.setPreferredSize", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setPreferredWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPreferredWidth(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setPreferredWidth(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setPreferredWidth_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPreferredWidth(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPreferredWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setPreferredWidth_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayoutItem.setPreferredWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_setSizePolicy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.setSizePolicy(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.setSizePolicy(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setSizePolicy", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
    // 1: setSizePolicy(QSizePolicy)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], (pyArgs[0])))) {
        overloadId = 1; // setSizePolicy(QSizePolicy)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_POLICY_IDX]), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[2])))) {
            overloadId = 0; // setSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_setSizePolicy_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setSizePolicy(QSizePolicy::Policy hPolicy, QSizePolicy::Policy vPolicy, QSizePolicy::ControlType controlType)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "controlType");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.setSizePolicy(): got multiple values for keyword argument 'controlType'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_CONTROLTYPE_IDX]), (pyArgs[2]))))
                        goto Sbk_QGraphicsLayoutItemFunc_setSizePolicy_TypeError;
                }
            }
            ::QSizePolicy::Policy cppArg0 = ((::QSizePolicy::Policy)0);
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QSizePolicy::Policy cppArg1 = ((::QSizePolicy::Policy)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QSizePolicy::ControlType cppArg2 = QSizePolicy::DefaultType;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setSizePolicy(QSizePolicy::Policy,QSizePolicy::Policy,QSizePolicy::ControlType)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSizePolicy(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setSizePolicy(const QSizePolicy & policy)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QSizePolicy cppArg0_local = ::QSizePolicy();
            ::QSizePolicy* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // setSizePolicy(QSizePolicy)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setSizePolicy(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutItemFunc_setSizePolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QSizePolicy.Policy, PySide.QtGui.QSizePolicy.Policy, PySide.QtGui.QSizePolicy.ControlType = QSizePolicy.DefaultType", "PySide.QtGui.QSizePolicy", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.setSizePolicy", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_sizeHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.sizeHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.sizeHint(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:sizeHint", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sizeHint(Qt::SizeHint,QSizeF)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SIZEHINT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // sizeHint(Qt::SizeHint,QSizeF)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1])))) {
            overloadId = 0; // sizeHint(Qt::SizeHint,QSizeF)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutItemFunc_sizeHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "constraint");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayoutItem.sizeHint(): got multiple values for keyword argument 'constraint'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsLayoutItemFunc_sizeHint_TypeError;
            }
        }
        ::Qt::SizeHint cppArg0 = ((::Qt::SizeHint)0);
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSizeF cppArg1_local = QSizeF();
        ::QSizeF* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // sizeHint(Qt::SizeHint,QSizeF)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayoutItem.sizeHint()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->sizeHint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsLayoutItemFunc_sizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.SizeHint, PySide.QtCore.QSizeF = QSizeF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayoutItem.sizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_sizePolicy(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizePolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizePolicy cppResult = const_cast<const ::QGraphicsLayoutItem*>(cppSelf)->sizePolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSIZEPOLICY_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutItemFunc_updateGeometry(PyObject* self)
{
    ::QGraphicsLayoutItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayoutItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateGeometry()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsLayoutItem::updateGeometry() : cppSelf->updateGeometry();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_QGraphicsLayoutItem_methods[] = {
    {"contentsRect", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_contentsRect, METH_NOARGS},
    {"effectiveSizeHint", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_effectiveSizeHint, METH_VARARGS|METH_KEYWORDS},
    {"geometry", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_geometry, METH_NOARGS},
    {"getContentsMargins", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_getContentsMargins, METH_NOARGS},
    {"graphicsItem", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_graphicsItem, METH_NOARGS},
    {"isLayout", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_isLayout, METH_NOARGS},
    {"maximumHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_maximumHeight, METH_NOARGS},
    {"maximumSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_maximumSize, METH_NOARGS},
    {"maximumWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_maximumWidth, METH_NOARGS},
    {"minimumHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_minimumHeight, METH_NOARGS},
    {"minimumSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_minimumSize, METH_NOARGS},
    {"minimumWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_minimumWidth, METH_NOARGS},
    {"ownedByLayout", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_ownedByLayout, METH_NOARGS},
    {"parentLayoutItem", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_parentLayoutItem, METH_NOARGS},
    {"preferredHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_preferredHeight, METH_NOARGS},
    {"preferredSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_preferredSize, METH_NOARGS},
    {"preferredWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_preferredWidth, METH_NOARGS},
    {"setGeometry", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setGeometry, METH_O},
    {"setGraphicsItem", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setGraphicsItem, METH_O},
    {"setMaximumHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMaximumHeight, METH_O},
    {"setMaximumSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMaximumSize, METH_VARARGS},
    {"setMaximumWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMaximumWidth, METH_O},
    {"setMinimumHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMinimumHeight, METH_O},
    {"setMinimumSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMinimumSize, METH_VARARGS},
    {"setMinimumWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setMinimumWidth, METH_O},
    {"setOwnedByLayout", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setOwnedByLayout, METH_O},
    {"setParentLayoutItem", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setParentLayoutItem, METH_O},
    {"setPreferredHeight", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setPreferredHeight, METH_O},
    {"setPreferredSize", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setPreferredSize, METH_VARARGS},
    {"setPreferredWidth", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setPreferredWidth, METH_O},
    {"setSizePolicy", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_setSizePolicy, METH_VARARGS|METH_KEYWORDS},
    {"sizeHint", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_sizeHint, METH_VARARGS|METH_KEYWORDS},
    {"sizePolicy", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_sizePolicy, METH_NOARGS},
    {"updateGeometry", (PyCFunction)Sbk_QGraphicsLayoutItemFunc_updateGeometry, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsLayoutItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsLayoutItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsLayoutItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsLayoutItem",
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
    /*tp_traverse*/         Sbk_QGraphicsLayoutItem_traverse,
    /*tp_clear*/            Sbk_QGraphicsLayoutItem_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsLayoutItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsLayoutItem_Init,
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
static void QGraphicsLayoutItem_PythonToCpp_QGraphicsLayoutItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsLayoutItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsLayoutItem_PythonToCpp_QGraphicsLayoutItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsLayoutItem_Type))
        return QGraphicsLayoutItem_PythonToCpp_QGraphicsLayoutItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsLayoutItem_PTR_CppToPython_QGraphicsLayoutItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsLayoutItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsLayoutItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsLayoutItem(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsLayoutItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsLayoutItem", "QGraphicsLayoutItem*",
        &Sbk_QGraphicsLayoutItem_Type, &Shiboken::callCppDestructor< ::QGraphicsLayoutItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsLayoutItem_Type,
        QGraphicsLayoutItem_PythonToCpp_QGraphicsLayoutItem_PTR,
        is_QGraphicsLayoutItem_PythonToCpp_QGraphicsLayoutItem_PTR_Convertible,
        QGraphicsLayoutItem_PTR_CppToPython_QGraphicsLayoutItem);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayoutItem");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayoutItem*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayoutItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsLayoutItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsLayoutItemWrapper).name());



}
