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

#include "qgraphicsanchorlayout_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qgraphicsanchorlayout.h>
#include <qgraphicsitem.h>
#include <qgraphicslayoutitem.h>
#include <qrect.h>
#include <qsize.h>
#include <qsizepolicy.h>


// Native ---------------------------------------------------------

QGraphicsAnchorLayoutWrapper::QGraphicsAnchorLayoutWrapper(QGraphicsLayoutItem * parent) : QGraphicsAnchorLayout(parent) {
    // ... middle
}

int QGraphicsAnchorLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::count();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsAnchorLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsAnchorLayoutWrapper::getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const
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

void QGraphicsAnchorLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QGraphicsLayoutItem * QGraphicsAnchorLayoutWrapper::itemAt(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QGraphicsLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::itemAt(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        index
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsAnchorLayout.itemAt", Shiboken::SbkType< QGraphicsLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QGraphicsLayoutItem*)0);
    }
    ::QGraphicsLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsAnchorLayoutWrapper::removeAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::removeAt(index);
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

void QGraphicsAnchorLayoutWrapper::setGeometry(const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::setGeometry(rect);
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

QSizeF QGraphicsAnchorLayoutWrapper::sizeHint(Qt::SizeHint which, const QSizeF & constraint) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSizeF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsAnchorLayout::sizeHint(which, constraint);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsAnchorLayout.sizeHint", Shiboken::SbkType< QSizeF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSizeF();
    }
    ::QSizeF cppResult = ::QSizeF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsAnchorLayoutWrapper::updateGeometry()
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

void QGraphicsAnchorLayoutWrapper::widgetEvent(QEvent * e)
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

QGraphicsAnchorLayoutWrapper::~QGraphicsAnchorLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsAnchorLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsAnchorLayout >()))
        return -1;

    ::QGraphicsAnchorLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsAnchorLayout", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsAnchorLayout(QGraphicsLayoutItem*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsAnchorLayout(QGraphicsLayoutItem*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsAnchorLayout(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayout_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsAnchorLayout_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGraphicsLayoutItem* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsAnchorLayout(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsAnchorLayoutWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsAnchorLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsAnchorLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsAnchorLayout_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_addAnchor(PyObject* self, PyObject* args)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addAnchor", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addAnchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX]), (pyArgs[3])))) {
        overloadId = 0; // addAnchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_addAnchor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::AnchorPoint cppArg1 = ((::Qt::AnchorPoint)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QGraphicsLayoutItem* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::AnchorPoint cppArg3 = ((::Qt::AnchorPoint)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // addAnchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsAnchor * cppResult = cppSelf->addAnchor(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHOR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsAnchorLayoutFunc_addAnchor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.AnchorPoint, PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.AnchorPoint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout.addAnchor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_addAnchors(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.addAnchors(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.addAnchors(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:addAnchors", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addAnchors(QGraphicsLayoutItem*,QGraphicsLayoutItem*,QFlags<Qt::Orientation>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addAnchors(QGraphicsLayoutItem*,QGraphicsLayoutItem*,QFlags<Qt::Orientation>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), (pyArgs[2])))) {
            overloadId = 0; // addAnchors(QGraphicsLayoutItem*,QGraphicsLayoutItem*,QFlags<Qt::Orientation>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_addAnchors_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "orientations");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.addAnchors(): got multiple values for keyword argument 'orientations'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ORIENTATION__IDX]), (pyArgs[2]))))
                    goto Sbk_QGraphicsAnchorLayoutFunc_addAnchors_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QGraphicsLayoutItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QFlags<Qt::Orientation> cppArg2 = Qt::Horizontal | Qt::Vertical;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addAnchors(QGraphicsLayoutItem*,QGraphicsLayoutItem*,QFlags<Qt::Orientation>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addAnchors(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_addAnchors_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.Orientations = Qt.Horizontal | Qt.Vertical", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout.addAnchors", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_addCornerAnchors(PyObject* self, PyObject* args)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addCornerAnchors", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: addCornerAnchors(QGraphicsLayoutItem*,Qt::Corner,QGraphicsLayoutItem*,Qt::Corner)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CORNER_IDX]), (pyArgs[3])))) {
        overloadId = 0; // addCornerAnchors(QGraphicsLayoutItem*,Qt::Corner,QGraphicsLayoutItem*,Qt::Corner)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_addCornerAnchors_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::Corner cppArg1 = ((::Qt::Corner)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QGraphicsLayoutItem* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::Corner cppArg3 = ((::Qt::Corner)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // addCornerAnchors(QGraphicsLayoutItem*,Qt::Corner,QGraphicsLayoutItem*,Qt::Corner)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addCornerAnchors(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_addCornerAnchors_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.Corner, PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.Corner", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout.addCornerAnchors", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_anchor(PyObject* self, PyObject* args)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "anchor", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: anchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_ANCHORPOINT_IDX]), (pyArgs[3])))) {
        overloadId = 0; // anchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_anchor_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::AnchorPoint cppArg1 = ((::Qt::AnchorPoint)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::QGraphicsLayoutItem* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::AnchorPoint cppArg3 = ((::Qt::AnchorPoint)0);
        pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // anchor(QGraphicsLayoutItem*,Qt::AnchorPoint,QGraphicsLayoutItem*,Qt::AnchorPoint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsAnchor * cppResult = cppSelf->anchor(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHOR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsAnchorLayoutFunc_anchor_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.AnchorPoint, PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.AnchorPoint", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout.anchor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_count(PyObject* self)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->::QGraphicsAnchorLayout::count() : const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->count();
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

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_horizontalSpacing(PyObject* self)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->horizontalSpacing();
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

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_invalidate(PyObject* self)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsAnchorLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_itemAt(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_itemAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // itemAt(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QGraphicsLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->::QGraphicsAnchorLayout::itemAt(cppArg0) : const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->itemAt(cppArg0);
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

    Sbk_QGraphicsAnchorLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_removeAt(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_removeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsAnchorLayout::removeAt(cppArg0) : cppSelf->removeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_removeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.removeAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_setGeometry_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsAnchorLayout::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_setHorizontalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setHorizontalSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_setHorizontalSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHorizontalSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHorizontalSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_setHorizontalSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.setHorizontalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_setSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_setSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_setSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.setSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_setVerticalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setVerticalSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_setVerticalSpacing_TypeError;

    // Call function/method
    {
        qreal cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVerticalSpacing(qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVerticalSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsAnchorLayoutFunc_setVerticalSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsAnchorLayout.setVerticalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_sizeHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.sizeHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.sizeHint(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QGraphicsAnchorLayoutFunc_sizeHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "constraint");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsAnchorLayout.sizeHint(): got multiple values for keyword argument 'constraint'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsAnchorLayoutFunc_sizeHint_TypeError;
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
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSizeF cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->::QGraphicsAnchorLayout::sizeHint(cppArg0, *cppArg1) : const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->sizeHint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsAnchorLayoutFunc_sizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.SizeHint, PySide.QtCore.QSizeF = QSizeF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsAnchorLayout.sizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsAnchorLayoutFunc_verticalSpacing(PyObject* self)
{
    ::QGraphicsAnchorLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsAnchorLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsAnchorLayout*>(cppSelf)->verticalSpacing();
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

static PyMethodDef Sbk_QGraphicsAnchorLayout_methods[] = {
    {"addAnchor", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_addAnchor, METH_VARARGS},
    {"addAnchors", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_addAnchors, METH_VARARGS|METH_KEYWORDS},
    {"addCornerAnchors", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_addCornerAnchors, METH_VARARGS},
    {"anchor", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_anchor, METH_VARARGS},
    {"count", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_count, METH_NOARGS},
    {"horizontalSpacing", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_horizontalSpacing, METH_NOARGS},
    {"invalidate", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_invalidate, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_itemAt, METH_O},
    {"removeAt", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_removeAt, METH_O},
    {"setGeometry", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_setGeometry, METH_O},
    {"setHorizontalSpacing", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_setHorizontalSpacing, METH_O},
    {"setSpacing", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_setSpacing, METH_O},
    {"setVerticalSpacing", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_setVerticalSpacing, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_sizeHint, METH_VARARGS|METH_KEYWORDS},
    {"verticalSpacing", (PyCFunction)Sbk_QGraphicsAnchorLayoutFunc_verticalSpacing, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsAnchorLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsAnchorLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsAnchorLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsAnchorLayout",
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
    /*tp_traverse*/         Sbk_QGraphicsAnchorLayout_traverse,
    /*tp_clear*/            Sbk_QGraphicsAnchorLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsAnchorLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsAnchorLayout_Init,
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

static void* Sbk_QGraphicsAnchorLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QGraphicsLayoutItem >()))
        return dynamic_cast< ::QGraphicsAnchorLayout*>(reinterpret_cast< ::QGraphicsLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsAnchorLayout_PythonToCpp_QGraphicsAnchorLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsAnchorLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsAnchorLayout_PythonToCpp_QGraphicsAnchorLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsAnchorLayout_Type))
        return QGraphicsAnchorLayout_PythonToCpp_QGraphicsAnchorLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsAnchorLayout_PTR_CppToPython_QGraphicsAnchorLayout(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsAnchorLayout*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsAnchorLayout_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsAnchorLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSANCHORLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsAnchorLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsAnchorLayout", "QGraphicsAnchorLayout*",
        &Sbk_QGraphicsAnchorLayout_Type, &Shiboken::callCppDestructor< ::QGraphicsAnchorLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsAnchorLayout_Type,
        QGraphicsAnchorLayout_PythonToCpp_QGraphicsAnchorLayout_PTR,
        is_QGraphicsAnchorLayout_PythonToCpp_QGraphicsAnchorLayout_PTR_Convertible,
        QGraphicsAnchorLayout_PTR_CppToPython_QGraphicsAnchorLayout);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsAnchorLayout");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsAnchorLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsAnchorLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsAnchorLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsAnchorLayoutWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsAnchorLayout_Type, &Sbk_QGraphicsAnchorLayout_typeDiscovery);


}
