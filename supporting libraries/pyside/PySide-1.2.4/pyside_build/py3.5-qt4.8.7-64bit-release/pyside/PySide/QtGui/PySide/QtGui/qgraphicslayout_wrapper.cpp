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

#include "qgraphicslayout_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qgraphicsitem.h>
#include <qgraphicslayout.h>
#include <qgraphicslayoutitem.h>
#include <qrect.h>
#include <qsize.h>
#include <qsizepolicy.h>


// Native ---------------------------------------------------------

QGraphicsLayoutWrapper::QGraphicsLayoutWrapper(QGraphicsLayoutItem * parent) : QGraphicsLayout(parent) {
    // ... middle
}

int QGraphicsLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.count()' not implemented.");
        return ((int)0);
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((int)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsLayoutWrapper::getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "getContentsMargins"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QGraphicsLayout::getContentsMargins(left, top, right, bottom);
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

void QGraphicsLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QGraphicsLayoutItem * QGraphicsLayoutWrapper::itemAt(int i) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QGraphicsLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.itemAt()' not implemented.");
        return ((::QGraphicsLayoutItem*)0);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        i
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QGraphicsLayoutItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsLayout.itemAt", Shiboken::SbkType< QGraphicsLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QGraphicsLayoutItem*)0);
    }
    ::QGraphicsLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsLayoutWrapper::removeAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeAt"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.removeAt()' not implemented.");
        return ;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsLayoutWrapper::setGeometry(const QRectF & rect)
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

QSizeF QGraphicsLayoutWrapper::sizeHint(Qt::SizeHint which, const QSizeF & constraint) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSizeF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.sizeHint()' not implemented.");
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsLayout.sizeHint", Shiboken::SbkType< QSizeF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSizeF();
    }
    ::QSizeF cppResult = ::QSizeF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsLayoutWrapper::updateGeometry()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "updateGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsLayout::updateGeometry();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QGraphicsLayoutWrapper::widgetEvent(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "widgetEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsLayout::widgetEvent(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
}

QGraphicsLayoutWrapper::~QGraphicsLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX]);
    if (type == myType) {
        PyErr_SetString(PyExc_NotImplementedError,
            "'QGraphicsLayout' represents a C++ abstract class and cannot be instantiated");
        return -1;
    }

    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsLayout >()))
        return -1;

    ::QGraphicsLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayout(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsLayout", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsLayout(QGraphicsLayoutItem*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsLayout(QGraphicsLayoutItem*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsLayout(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayout_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsLayout(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsLayout_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGraphicsLayoutItem* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsLayout(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsLayoutWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsLayout_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayout", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsLayoutFunc_activate(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // activate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->activate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsLayoutFunc_addChildLayoutItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addChildLayoutItem(QGraphicsLayoutItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // addChildLayoutItem(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_addChildLayoutItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addChildLayoutItem(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addChildLayoutItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutFunc_addChildLayoutItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayout.addChildLayoutItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutFunc_count(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.count()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsLayout*>(cppSelf)->count();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QGraphicsLayoutFunc_getContentsMargins(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getContentsMargins(qreal*,qreal*,qreal*,qreal*)const
            // Begin code injection

            // TEMPLATE - fix_number*,number*,number*,number* - START
            qreal a, b, c, d;
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->::QGraphicsLayout::getContentsMargins(&a, &b, &c, &d);
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

static PyObject* Sbk_QGraphicsLayoutFunc_instantInvalidatePropagation(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // instantInvalidatePropagation()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QGraphicsLayout::instantInvalidatePropagation();
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

static PyObject* Sbk_QGraphicsLayoutFunc_invalidate(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsLayoutFunc_isActivated(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isActivated()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QGraphicsLayout*>(cppSelf)->isActivated();
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

static PyObject* Sbk_QGraphicsLayoutFunc_itemAt(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: itemAt(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // itemAt(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_itemAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemAt(int)const
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.itemAt()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsLayoutItem * cppResult = const_cast<const ::QGraphicsLayout*>(cppSelf)->itemAt(cppArg0);
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

    Sbk_QGraphicsLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutFunc_removeAt(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_removeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAt(int)
            if (Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self))) {
                PyErr_SetString(PyExc_NotImplementedError, "pure virtual method 'QGraphicsLayout.removeAt()' not implemented.");
                return 0;
            }
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutFunc_removeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayout.removeAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutFunc_setContentsMargins(PyObject* self, PyObject* args)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setContentsMargins", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: setContentsMargins(qreal,qreal,qreal,qreal)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[3])))) {
        overloadId = 0; // setContentsMargins(qreal,qreal,qreal,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_setContentsMargins_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        qreal cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        qreal cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setContentsMargins(qreal,qreal,qreal,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContentsMargins(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutFunc_setContentsMargins_TypeError:
        const char* overloads[] = {"float, float, float, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsLayout.setContentsMargins", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutFunc_setInstantInvalidatePropagation(PyObject* self, PyObject* pyArg)
{
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setInstantInvalidatePropagation(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setInstantInvalidatePropagation(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_setInstantInvalidatePropagation_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setInstantInvalidatePropagation(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            ::QGraphicsLayout::setInstantInvalidatePropagation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutFunc_setInstantInvalidatePropagation_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayout.setInstantInvalidatePropagation", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsLayoutFunc_updateGeometry(PyObject* self)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateGeometry()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsLayout::updateGeometry() : cppSelf->updateGeometry();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsLayoutFunc_widgetEvent(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: widgetEvent(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // widgetEvent(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsLayoutFunc_widgetEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // widgetEvent(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsLayout::widgetEvent(cppArg0) : cppSelf->widgetEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsLayoutFunc_widgetEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsLayout.widgetEvent", overloads);
        return 0;
}

static PyMethodDef Sbk_QGraphicsLayout_methods[] = {
    {"activate", (PyCFunction)Sbk_QGraphicsLayoutFunc_activate, METH_NOARGS},
    {"addChildLayoutItem", (PyCFunction)Sbk_QGraphicsLayoutFunc_addChildLayoutItem, METH_O},
    {"count", (PyCFunction)Sbk_QGraphicsLayoutFunc_count, METH_NOARGS},
    {"getContentsMargins", (PyCFunction)Sbk_QGraphicsLayoutFunc_getContentsMargins, METH_NOARGS},
    {"instantInvalidatePropagation", (PyCFunction)Sbk_QGraphicsLayoutFunc_instantInvalidatePropagation, METH_NOARGS|METH_STATIC},
    {"invalidate", (PyCFunction)Sbk_QGraphicsLayoutFunc_invalidate, METH_NOARGS},
    {"isActivated", (PyCFunction)Sbk_QGraphicsLayoutFunc_isActivated, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGraphicsLayoutFunc_itemAt, METH_O},
    {"removeAt", (PyCFunction)Sbk_QGraphicsLayoutFunc_removeAt, METH_O},
    {"setContentsMargins", (PyCFunction)Sbk_QGraphicsLayoutFunc_setContentsMargins, METH_VARARGS},
    {"setInstantInvalidatePropagation", (PyCFunction)Sbk_QGraphicsLayoutFunc_setInstantInvalidatePropagation, METH_O|METH_STATIC},
    {"updateGeometry", (PyCFunction)Sbk_QGraphicsLayoutFunc_updateGeometry, METH_NOARGS},
    {"widgetEvent", (PyCFunction)Sbk_QGraphicsLayoutFunc_widgetEvent, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsLayout",
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
    /*tp_traverse*/         Sbk_QGraphicsLayout_traverse,
    /*tp_clear*/            Sbk_QGraphicsLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsLayout_Init,
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

static void* Sbk_QGraphicsLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QGraphicsLayoutItem >()))
        return dynamic_cast< ::QGraphicsLayout*>(reinterpret_cast< ::QGraphicsLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsLayout_PythonToCpp_QGraphicsLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsLayout_PythonToCpp_QGraphicsLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsLayout_Type))
        return QGraphicsLayout_PythonToCpp_QGraphicsLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsLayout_PTR_CppToPython_QGraphicsLayout(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsLayout*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsLayout_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsLayout", "QGraphicsLayout*",
        &Sbk_QGraphicsLayout_Type, &Shiboken::callCppDestructor< ::QGraphicsLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsLayout_Type,
        QGraphicsLayout_PythonToCpp_QGraphicsLayout_PTR,
        is_QGraphicsLayout_PythonToCpp_QGraphicsLayout_PTR_Convertible,
        QGraphicsLayout_PTR_CppToPython_QGraphicsLayout);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayout");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsLayoutWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsLayout_Type, &Sbk_QGraphicsLayout_typeDiscovery);


}
