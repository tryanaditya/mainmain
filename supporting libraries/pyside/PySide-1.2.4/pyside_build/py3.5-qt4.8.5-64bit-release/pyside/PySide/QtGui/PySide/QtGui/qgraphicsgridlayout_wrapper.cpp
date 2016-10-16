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

#include "qgraphicsgridlayout_wrapper.h"

// Extra includes
#include <qcoreevent.h>
#include <qgraphicsgridlayout.h>
#include <qgraphicsitem.h>
#include <qgraphicslayoutitem.h>
#include <qrect.h>
#include <qsize.h>
#include <qsizepolicy.h>


// Native ---------------------------------------------------------

QGraphicsGridLayoutWrapper::QGraphicsGridLayoutWrapper(QGraphicsLayoutItem * parent) : QGraphicsGridLayout(parent) {
    // ... middle
}

int QGraphicsGridLayoutWrapper::count() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "count"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::count();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsGridLayout.count", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsGridLayoutWrapper::getContentsMargins(qreal * left, qreal * top, qreal * right, qreal * bottom) const
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

void QGraphicsGridLayoutWrapper::invalidate()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "invalidate"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::invalidate();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

QGraphicsLayoutItem * QGraphicsGridLayoutWrapper::itemAt(int index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QGraphicsLayoutItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "itemAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::itemAt(index);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsGridLayout.itemAt", Shiboken::SbkType< QGraphicsLayoutItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QGraphicsLayoutItem*)0);
    }
    ::QGraphicsLayoutItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsGridLayoutWrapper::removeAt(int index)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "removeAt"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::removeAt(index);
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

void QGraphicsGridLayoutWrapper::setGeometry(const QRectF & rect)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setGeometry"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::setGeometry(rect);
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

QSizeF QGraphicsGridLayoutWrapper::sizeHint(Qt::SizeHint which, const QSizeF & constraint) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QSizeF();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QGraphicsGridLayout::sizeHint(which, constraint);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QGraphicsGridLayout.sizeHint", Shiboken::SbkType< QSizeF >()->tp_name, pyResult->ob_type->tp_name);
        return ::QSizeF();
    }
    ::QSizeF cppResult = ::QSizeF();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QGraphicsGridLayoutWrapper::updateGeometry()
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

void QGraphicsGridLayoutWrapper::widgetEvent(QEvent * e)
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

QGraphicsGridLayoutWrapper::~QGraphicsGridLayoutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QGraphicsGridLayout_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QGraphicsGridLayout >()))
        return -1;

    ::QGraphicsGridLayoutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:QGraphicsGridLayout", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QGraphicsGridLayout(QGraphicsLayoutItem*)
    if (numArgs == 0) {
        overloadId = 0; // QGraphicsGridLayout(QGraphicsLayoutItem*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))) {
        overloadId = 0; // QGraphicsGridLayout(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayout_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0]))))
                    goto Sbk_QGraphicsGridLayout_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QGraphicsLayoutItem* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QGraphicsGridLayout(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cptr = new ::QGraphicsGridLayoutWrapper(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QGraphicsGridLayout >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QGraphicsGridLayout_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QGraphicsGridLayout_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout", overloads);
        return -1;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_addItem(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.addItem(): too many arguments");
        return 0;
    } else if (numArgs < 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.addItem(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:addItem", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return 0;


    // Overloaded function decisor
    // 0: addItem(QGraphicsLayoutItem*,int,int,QFlags<Qt::AlignmentFlag>)
    // 1: addItem(QGraphicsLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // addItem(QGraphicsLayoutItem*,int,int,QFlags<Qt::AlignmentFlag>)
        } else if (numArgs >= 5
            && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
            && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // addItem(QGraphicsLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5])))) {
                overloadId = 1; // addItem(QGraphicsLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
            }
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3])))) {
            overloadId = 0; // addItem(QGraphicsLayoutItem*,int,int,QFlags<Qt::AlignmentFlag>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_addItem_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // addItem(QGraphicsLayoutItem * item, int row, int column, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.addItem(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[3]))))
                        goto Sbk_QGraphicsGridLayoutFunc_addItem_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsLayoutItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<Qt::AlignmentFlag> cppArg3 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // addItem(QGraphicsLayoutItem*,int,int,QFlags<Qt::AlignmentFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addItem(cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
        case 1: // addItem(QGraphicsLayoutItem * item, int row, int column, int rowSpan, int columnSpan, QFlags<Qt::AlignmentFlag> alignment)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "alignment");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.addItem(): got multiple values for keyword argument 'alignment'.");
                    return 0;
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[5]))))
                        goto Sbk_QGraphicsGridLayoutFunc_addItem_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QGraphicsLayoutItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            int cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);
            ::QFlags<Qt::AlignmentFlag> cppArg5 = QFlags<Qt::AlignmentFlag>(0);
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // addItem(QGraphicsLayoutItem*,int,int,int,int,QFlags<Qt::AlignmentFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->addItem(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[0]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_addItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, int, int, PySide.QtCore.Qt.Alignment = 0", "PySide.QtGui.QGraphicsLayoutItem, int, int, int, int, PySide.QtCore.Qt.Alignment = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.addItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_alignment(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: alignment(QGraphicsLayoutItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // alignment(QGraphicsLayoutItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_alignment_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // alignment(QGraphicsLayoutItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->alignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_alignment_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.alignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnAlignment(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnAlignment(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnAlignment(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnAlignment(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnAlignment_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnCount(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnCount();
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

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnMaximumWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnMaximumWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnMaximumWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnMaximumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnMaximumWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnMaximumWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnMaximumWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnMaximumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnMinimumWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnMinimumWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnMinimumWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnMinimumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnMinimumWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnMinimumWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnMinimumWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnMinimumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnPreferredWidth(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnPreferredWidth(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnPreferredWidth(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnPreferredWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnPreferredWidth(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnPreferredWidth(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnPreferredWidth_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnPreferredWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnSpacing(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnSpacing(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnSpacing(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_columnStretchFactor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: columnStretchFactor(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // columnStretchFactor(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_columnStretchFactor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // columnStretchFactor(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->columnStretchFactor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_columnStretchFactor_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.columnStretchFactor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_count(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsGridLayout*>(cppSelf)->::QGraphicsGridLayout::count() : const_cast<const ::QGraphicsGridLayout*>(cppSelf)->count();
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

static PyObject* Sbk_QGraphicsGridLayoutFunc_horizontalSpacing(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // horizontalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->horizontalSpacing();
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

static PyObject* Sbk_QGraphicsGridLayoutFunc_invalidate(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // invalidate()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsGridLayout::invalidate() : cppSelf->invalidate();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_itemAt(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "itemAt", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: itemAt(int)const
    // 1: itemAt(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // itemAt(int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // itemAt(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_itemAt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // itemAt(int index) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // itemAt(int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsLayoutItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsGridLayout*>(cppSelf)->::QGraphicsGridLayout::itemAt(cppArg0) : const_cast<const ::QGraphicsGridLayout*>(cppSelf)->itemAt(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
        case 1: // itemAt(int row, int column) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // itemAt(int,int)const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QGraphicsLayoutItem * cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->itemAt(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], cppResult);
                Shiboken::Object::setParent(self, pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_itemAt_TypeError:
        const char* overloads[] = {"int", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.itemAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_removeAt(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeAt(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeAt(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_removeAt_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeAt(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsGridLayout::removeAt(cppArg0) : cppSelf->removeAt(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_removeAt_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.removeAt", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_removeItem(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeItem(QGraphicsLayoutItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArg)))) {
        overloadId = 0; // removeItem(QGraphicsLayoutItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_removeItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeItem(QGraphicsLayoutItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeItem(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_removeItem_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.removeItem", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowAlignment(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowAlignment(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowAlignment(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowAlignment(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowAlignment_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowCount(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowCount();
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

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowMaximumHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowMaximumHeight(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowMaximumHeight(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowMaximumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowMaximumHeight(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowMaximumHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowMaximumHeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowMaximumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowMinimumHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowMinimumHeight(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowMinimumHeight(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowMinimumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowMinimumHeight(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowMinimumHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowMinimumHeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowMinimumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowPreferredHeight(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowPreferredHeight(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowPreferredHeight(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowPreferredHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowPreferredHeight(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowPreferredHeight(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowPreferredHeight_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowPreferredHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowSpacing(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowSpacing(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowSpacing(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowSpacing(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowSpacing_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_rowStretchFactor(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: rowStretchFactor(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // rowStretchFactor(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_rowStretchFactor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // rowStretchFactor(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->rowStretchFactor(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_rowStretchFactor_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.rowStretchFactor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setAlignment(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setAlignment", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setAlignment(QGraphicsLayoutItem*,QFlags<Qt::AlignmentFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUTITEM_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // setAlignment(QGraphicsLayoutItem*,QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setAlignment_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QGraphicsLayoutItem* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::AlignmentFlag> cppArg1 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setAlignment(QGraphicsLayoutItem*,QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAlignment(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[0]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setAlignment_TypeError:
        const char* overloads[] = {"PySide.QtGui.QGraphicsLayoutItem, PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnAlignment(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnAlignment", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnAlignment(int,QFlags<Qt::AlignmentFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // setColumnAlignment(int,QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::AlignmentFlag> cppArg1 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnAlignment(int,QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnAlignment(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnAlignment_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnFixedWidth(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnFixedWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnFixedWidth(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnFixedWidth(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnFixedWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnFixedWidth(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnFixedWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnFixedWidth_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnFixedWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnMaximumWidth(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnMaximumWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnMaximumWidth(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnMaximumWidth(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnMaximumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnMaximumWidth(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnMaximumWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnMaximumWidth_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnMaximumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnMinimumWidth(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnMinimumWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnMinimumWidth(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnMinimumWidth(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnMinimumWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnMinimumWidth(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnMinimumWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnMinimumWidth_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnMinimumWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnPreferredWidth(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnPreferredWidth", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnPreferredWidth(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnPreferredWidth(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnPreferredWidth_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnPreferredWidth(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnPreferredWidth(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnPreferredWidth_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnPreferredWidth", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnSpacing(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnSpacing", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnSpacing(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnSpacing(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnSpacing(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnSpacing(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnSpacing_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setColumnStretchFactor(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColumnStretchFactor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setColumnStretchFactor(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setColumnStretchFactor(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setColumnStretchFactor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setColumnStretchFactor(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnStretchFactor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setColumnStretchFactor_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setColumnStretchFactor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setGeometry(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGeometry(QRectF)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECTF_IDX], (pyArg)))) {
        overloadId = 0; // setGeometry(QRectF)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setGeometry_TypeError;

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
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QGraphicsGridLayout::setGeometry(*cppArg0) : cppSelf->setGeometry(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setGeometry_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRectF", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.setGeometry", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setHorizontalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHorizontalSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setHorizontalSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setHorizontalSpacing_TypeError;

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

    Sbk_QGraphicsGridLayoutFunc_setHorizontalSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.setHorizontalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowAlignment(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowAlignment", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowAlignment(int,QFlags<Qt::AlignmentFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // setRowAlignment(int,QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QFlags<Qt::AlignmentFlag> cppArg1 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowAlignment(int,QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowAlignment(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowAlignment_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowFixedHeight(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowFixedHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowFixedHeight(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setRowFixedHeight(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowFixedHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowFixedHeight(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowFixedHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowFixedHeight_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowFixedHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowMaximumHeight(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowMaximumHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowMaximumHeight(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setRowMaximumHeight(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowMaximumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowMaximumHeight(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowMaximumHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowMaximumHeight_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowMaximumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowMinimumHeight(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowMinimumHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowMinimumHeight(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setRowMinimumHeight(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowMinimumHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowMinimumHeight(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowMinimumHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowMinimumHeight_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowMinimumHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowPreferredHeight(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowPreferredHeight", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowPreferredHeight(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setRowPreferredHeight(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowPreferredHeight_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowPreferredHeight(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowPreferredHeight(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowPreferredHeight_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowPreferredHeight", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowSpacing(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowSpacing", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowSpacing(int,qreal)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArgs[1])))) {
        overloadId = 0; // setRowSpacing(int,qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        qreal cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowSpacing(int,qreal)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowSpacing(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowSpacing_TypeError:
        const char* overloads[] = {"int, float", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setRowStretchFactor(PyObject* self, PyObject* args)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setRowStretchFactor", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setRowStretchFactor(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setRowStretchFactor(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setRowStretchFactor_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setRowStretchFactor(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowStretchFactor(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QGraphicsGridLayoutFunc_setRowStretchFactor_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.setRowStretchFactor", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setSpacing_TypeError;

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

    Sbk_QGraphicsGridLayoutFunc_setSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.setSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_setVerticalSpacing(PyObject* self, PyObject* pyArg)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVerticalSpacing(qreal)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), (pyArg)))) {
        overloadId = 0; // setVerticalSpacing(qreal)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_setVerticalSpacing_TypeError;

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

    Sbk_QGraphicsGridLayoutFunc_setVerticalSpacing_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QGraphicsGridLayout.setVerticalSpacing", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_sizeHint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.sizeHint(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.sizeHint(): not enough arguments");
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
    if (overloadId == -1) goto Sbk_QGraphicsGridLayoutFunc_sizeHint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "constraint");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QGraphicsGridLayout.sizeHint(): got multiple values for keyword argument 'constraint'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], (pyArgs[1]))))
                    goto Sbk_QGraphicsGridLayoutFunc_sizeHint_TypeError;
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
            QSizeF cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QGraphicsGridLayout*>(cppSelf)->::QGraphicsGridLayout::sizeHint(cppArg0, *cppArg1) : const_cast<const ::QGraphicsGridLayout*>(cppSelf)->sizeHint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZEF_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QGraphicsGridLayoutFunc_sizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.SizeHint, PySide.QtCore.QSizeF = QSizeF()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QGraphicsGridLayout.sizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QGraphicsGridLayoutFunc_verticalSpacing(PyObject* self)
{
    ::QGraphicsGridLayout* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QGraphicsGridLayout*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // verticalSpacing()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QGraphicsGridLayout*>(cppSelf)->verticalSpacing();
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

static PyMethodDef Sbk_QGraphicsGridLayout_methods[] = {
    {"addItem", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_addItem, METH_VARARGS|METH_KEYWORDS},
    {"alignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_alignment, METH_O},
    {"columnAlignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnAlignment, METH_O},
    {"columnCount", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnCount, METH_NOARGS},
    {"columnMaximumWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnMaximumWidth, METH_O},
    {"columnMinimumWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnMinimumWidth, METH_O},
    {"columnPreferredWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnPreferredWidth, METH_O},
    {"columnSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnSpacing, METH_O},
    {"columnStretchFactor", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_columnStretchFactor, METH_O},
    {"count", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_count, METH_NOARGS},
    {"horizontalSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_horizontalSpacing, METH_NOARGS},
    {"invalidate", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_invalidate, METH_NOARGS},
    {"itemAt", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_itemAt, METH_VARARGS},
    {"removeAt", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_removeAt, METH_O},
    {"removeItem", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_removeItem, METH_O},
    {"rowAlignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowAlignment, METH_O},
    {"rowCount", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowCount, METH_NOARGS},
    {"rowMaximumHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowMaximumHeight, METH_O},
    {"rowMinimumHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowMinimumHeight, METH_O},
    {"rowPreferredHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowPreferredHeight, METH_O},
    {"rowSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowSpacing, METH_O},
    {"rowStretchFactor", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_rowStretchFactor, METH_O},
    {"setAlignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setAlignment, METH_VARARGS},
    {"setColumnAlignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnAlignment, METH_VARARGS},
    {"setColumnFixedWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnFixedWidth, METH_VARARGS},
    {"setColumnMaximumWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnMaximumWidth, METH_VARARGS},
    {"setColumnMinimumWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnMinimumWidth, METH_VARARGS},
    {"setColumnPreferredWidth", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnPreferredWidth, METH_VARARGS},
    {"setColumnSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnSpacing, METH_VARARGS},
    {"setColumnStretchFactor", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setColumnStretchFactor, METH_VARARGS},
    {"setGeometry", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setGeometry, METH_O},
    {"setHorizontalSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setHorizontalSpacing, METH_O},
    {"setRowAlignment", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowAlignment, METH_VARARGS},
    {"setRowFixedHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowFixedHeight, METH_VARARGS},
    {"setRowMaximumHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowMaximumHeight, METH_VARARGS},
    {"setRowMinimumHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowMinimumHeight, METH_VARARGS},
    {"setRowPreferredHeight", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowPreferredHeight, METH_VARARGS},
    {"setRowSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowSpacing, METH_VARARGS},
    {"setRowStretchFactor", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setRowStretchFactor, METH_VARARGS},
    {"setSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setSpacing, METH_O},
    {"setVerticalSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_setVerticalSpacing, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_sizeHint, METH_VARARGS|METH_KEYWORDS},
    {"verticalSpacing", (PyCFunction)Sbk_QGraphicsGridLayoutFunc_verticalSpacing, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QGraphicsGridLayout_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QGraphicsGridLayout_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QGraphicsGridLayout_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QGraphicsGridLayout",
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
    /*tp_traverse*/         Sbk_QGraphicsGridLayout_traverse,
    /*tp_clear*/            Sbk_QGraphicsGridLayout_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QGraphicsGridLayout_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QGraphicsGridLayout_Init,
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

static void* Sbk_QGraphicsGridLayout_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QGraphicsLayoutItem >()))
        return dynamic_cast< ::QGraphicsGridLayout*>(reinterpret_cast< ::QGraphicsLayoutItem*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QGraphicsGridLayout_PythonToCpp_QGraphicsGridLayout_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QGraphicsGridLayout_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QGraphicsGridLayout_PythonToCpp_QGraphicsGridLayout_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QGraphicsGridLayout_Type))
        return QGraphicsGridLayout_PythonToCpp_QGraphicsGridLayout_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QGraphicsGridLayout_PTR_CppToPython_QGraphicsGridLayout(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QGraphicsGridLayout*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QGraphicsGridLayout_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QGraphicsGridLayout(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QGRAPHICSGRIDLAYOUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QGraphicsGridLayout_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QGraphicsGridLayout", "QGraphicsGridLayout*",
        &Sbk_QGraphicsGridLayout_Type, &Shiboken::callCppDestructor< ::QGraphicsGridLayout >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QGRAPHICSLAYOUT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QGraphicsGridLayout_Type,
        QGraphicsGridLayout_PythonToCpp_QGraphicsGridLayout_PTR,
        is_QGraphicsGridLayout_PythonToCpp_QGraphicsGridLayout_PTR_Convertible,
        QGraphicsGridLayout_PTR_CppToPython_QGraphicsGridLayout);

    Shiboken::Conversions::registerConverterName(converter, "QGraphicsGridLayout");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsGridLayout*");
    Shiboken::Conversions::registerConverterName(converter, "QGraphicsGridLayout&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsGridLayout).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QGraphicsGridLayoutWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QGraphicsGridLayout_Type, &Sbk_QGraphicsGridLayout_typeDiscovery);


}
