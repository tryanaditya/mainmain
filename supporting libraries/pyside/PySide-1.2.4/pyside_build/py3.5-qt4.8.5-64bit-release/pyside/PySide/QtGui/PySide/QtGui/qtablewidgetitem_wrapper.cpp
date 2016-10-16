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

#include "qtablewidgetitem_wrapper.h"

// Extra includes
#include <qbrush.h>
#include <qdatastream.h>
#include <qfont.h>
#include <qicon.h>
#include <qsize.h>
#include <qtablewidget.h>


// Native ---------------------------------------------------------

QTableWidgetItemWrapper::QTableWidgetItemWrapper(const QIcon & icon, const QString & text, int type) : QTableWidgetItem(icon, text, type) {
    // ... middle
}

QTableWidgetItemWrapper::QTableWidgetItemWrapper(const QString & text, int type) : QTableWidgetItem(text, type) {
    // ... middle
}

QTableWidgetItemWrapper::QTableWidgetItemWrapper(int type) : QTableWidgetItem(type) {
    // ... middle
}

QTableWidgetItem * QTableWidgetItemWrapper::clone() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QTableWidgetItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clone"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::clone();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QTableWidgetItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTableWidgetItem.clone", Shiboken::SbkType< QTableWidgetItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QTableWidgetItem*)0);
    }
    ::QTableWidgetItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QTableWidgetItemWrapper::data(int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::data(role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        role
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QVariant();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTableWidgetItem.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QTableWidgetItemWrapper::operator<(const QTableWidgetItem & other) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "__lt__"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::operator<(other);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], &other)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTableWidgetItem.__lt__", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QTableWidgetItemWrapper::read(QDataStream & in)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::read(in);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &in)
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

void QTableWidgetItemWrapper::setData(int role, const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::setData(role, value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iN)",
        role,
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QTableWidgetItemWrapper::write(QDataStream & out) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTableWidgetItem::write(out);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &out)
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

QTableWidgetItemWrapper::~QTableWidgetItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTableWidgetItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTableWidgetItem >()))
        return -1;

    ::QTableWidgetItemWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTableWidgetItem(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QTableWidgetItem", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QTableWidgetItem(QIcon,QString,int)
    // 1: QTableWidgetItem(QString,int)
    // 2: QTableWidgetItem(QTableWidgetItem)
    // 3: QTableWidgetItem(int)
    if (numArgs == 0) {
        overloadId = 3; // QTableWidgetItem(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 3; // QTableWidgetItem(int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (pyArgs[0])))) {
        overloadId = 2; // QTableWidgetItem(QTableWidgetItem)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QTableWidgetItem(QString,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // QTableWidgetItem(QString,int)
        }
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // QTableWidgetItem(QIcon,QString,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // QTableWidgetItem(QIcon,QString,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTableWidgetItem(const QIcon & icon, const QString & text, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTableWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTableWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QIcon cppArg0_local = ::QIcon();
            ::QIcon* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = QTableWidgetItem::Type;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QTableWidgetItem(QIcon,QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetItemWrapper(*cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QTableWidgetItem(const QString & text, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTableWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTableWidgetItem_Init_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QTableWidgetItem::Type;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTableWidgetItem(QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetItemWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QTableWidgetItem(const QTableWidgetItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTableWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTableWidgetItem(QTableWidgetItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetItemWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QTableWidgetItem(int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTableWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QTableWidgetItem_Init_TypeError;
                }
            }
            int cppArg0 = QTableWidgetItem::Type;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTableWidgetItem(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTableWidgetItemWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTableWidgetItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTableWidgetItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTableWidgetItem_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon, unicode, int = Type", "unicode, int = Type", "PySide.QtGui.QTableWidgetItem", "int = Type", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTableWidgetItem", overloads);
        return -1;
}

static PyObject* Sbk_QTableWidgetItemFunc_background(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // background()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->background();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_checkState(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // checkState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CheckState cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->checkState();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_clone(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clone()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTableWidgetItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTableWidgetItem*>(cppSelf)->::QTableWidgetItem::clone() : const_cast<const ::QTableWidgetItem*>(cppSelf)->clone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_column(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // column()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->column();
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

static PyObject* Sbk_QTableWidgetItemFunc_data(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: data(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // data(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_data_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // data(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTableWidgetItem*>(cppSelf)->::QTableWidgetItem::data(cppArg0) : const_cast<const ::QTableWidgetItem*>(cppSelf)->data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTableWidgetItemFunc_data_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.data", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_flags(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->flags();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_font(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->font();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_foreground(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // foreground()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->foreground();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_icon(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->icon();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_isSelected(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelected()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->isSelected();
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

static PyObject* Sbk_QTableWidgetItemFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(QDataStream&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // read(QDataStream&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(QDataStream&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTableWidgetItem::read(*cppArg0) : cppSelf->read(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_read_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.read", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_row(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // row()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->row();
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

static PyObject* Sbk_QTableWidgetItemFunc_setBackground(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setBackground_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setBackground(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackground(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setBackground", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setCheckState(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCheckState(Qt::CheckState)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), (pyArg)))) {
        overloadId = 0; // setCheckState(Qt::CheckState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setCheckState_TypeError;

    // Call function/method
    {
        ::Qt::CheckState cppArg0 = ((::Qt::CheckState)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCheckState(Qt::CheckState)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCheckState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setCheckState_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CheckState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setCheckState", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setData(PyObject* self, PyObject* args)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setData", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setData(int,QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setData(int,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QVariant cppArg1 = ::QVariant();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setData(int,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTableWidgetItem::setData(cppArg0, cppArg1) : cppSelf->setData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setData_TypeError:
        const char* overloads[] = {"int, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTableWidgetItem.setData", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setFlags(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFlags(QFlags<Qt::ItemFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFlags(QFlags<Qt::ItemFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setFlags_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::ItemFlag> cppArg0 = ((::QFlags<Qt::ItemFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFlags(QFlags<Qt::ItemFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFlags(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ItemFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setFlags", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setFont_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QFont cppArg0_local = ::QFont();
        ::QFont* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setFont(QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFont(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setForeground(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForeground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setForeground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setForeground_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QBrush cppArg0_local = ::QBrush();
        ::QBrush* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setForeground(QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForeground(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setForeground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setForeground", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setIcon_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QIcon cppArg0_local = ::QIcon();
        ::QIcon* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setIcon(QIcon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIcon(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setSelected(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelected(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSelected(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setSelected_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelected(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelected(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setSelected_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setSelected", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setSizeHint(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSizeHint(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setSizeHint(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setSizeHint_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QSize cppArg0_local = ::QSize();
        ::QSize* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setSizeHint(QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSizeHint(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setSizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setSizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setStatusTip(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatusTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatusTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setStatusTip_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStatusTip(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatusTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setStatusTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setStatusTip", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setText(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setText", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setTextAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextAlignment(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setTextAlignment(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setTextAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextAlignment(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setTextAlignment_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setTextAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setToolTip_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setToolTip(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToolTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_setWhatsThis(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWhatsThis(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWhatsThis(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_setWhatsThis_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWhatsThis(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWhatsThis(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_setWhatsThis_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.setWhatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc_sizeHint(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->sizeHint();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_statusTip(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // statusTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->statusTip();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_tableWidget(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // tableWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTableWidget * cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->tableWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_text(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->text();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_textAlignment(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->textAlignment();
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

static PyObject* Sbk_QTableWidgetItemFunc_toolTip(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->toolTip();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_type(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->type();
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

static PyObject* Sbk_QTableWidgetItemFunc_whatsThis(PyObject* self)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // whatsThis()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTableWidgetItem*>(cppSelf)->whatsThis();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTableWidgetItemFunc_write(PyObject* self, PyObject* pyArg)
{
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QDataStream&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // write(QDataStream&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // write(QDataStream&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTableWidgetItem*>(cppSelf)->::QTableWidgetItem::write(*cppArg0) : const_cast<const ::QTableWidgetItem*>(cppSelf)->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTableWidgetItemFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QTableWidgetItem_methods[] = {
    {"background", (PyCFunction)Sbk_QTableWidgetItemFunc_background, METH_NOARGS},
    {"checkState", (PyCFunction)Sbk_QTableWidgetItemFunc_checkState, METH_NOARGS},
    {"clone", (PyCFunction)Sbk_QTableWidgetItemFunc_clone, METH_NOARGS},
    {"column", (PyCFunction)Sbk_QTableWidgetItemFunc_column, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QTableWidgetItemFunc_data, METH_O},
    {"flags", (PyCFunction)Sbk_QTableWidgetItemFunc_flags, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QTableWidgetItemFunc_font, METH_NOARGS},
    {"foreground", (PyCFunction)Sbk_QTableWidgetItemFunc_foreground, METH_NOARGS},
    {"icon", (PyCFunction)Sbk_QTableWidgetItemFunc_icon, METH_NOARGS},
    {"isSelected", (PyCFunction)Sbk_QTableWidgetItemFunc_isSelected, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QTableWidgetItemFunc_read, METH_O},
    {"row", (PyCFunction)Sbk_QTableWidgetItemFunc_row, METH_NOARGS},
    {"setBackground", (PyCFunction)Sbk_QTableWidgetItemFunc_setBackground, METH_O},
    {"setCheckState", (PyCFunction)Sbk_QTableWidgetItemFunc_setCheckState, METH_O},
    {"setData", (PyCFunction)Sbk_QTableWidgetItemFunc_setData, METH_VARARGS},
    {"setFlags", (PyCFunction)Sbk_QTableWidgetItemFunc_setFlags, METH_O},
    {"setFont", (PyCFunction)Sbk_QTableWidgetItemFunc_setFont, METH_O},
    {"setForeground", (PyCFunction)Sbk_QTableWidgetItemFunc_setForeground, METH_O},
    {"setIcon", (PyCFunction)Sbk_QTableWidgetItemFunc_setIcon, METH_O},
    {"setSelected", (PyCFunction)Sbk_QTableWidgetItemFunc_setSelected, METH_O},
    {"setSizeHint", (PyCFunction)Sbk_QTableWidgetItemFunc_setSizeHint, METH_O},
    {"setStatusTip", (PyCFunction)Sbk_QTableWidgetItemFunc_setStatusTip, METH_O},
    {"setText", (PyCFunction)Sbk_QTableWidgetItemFunc_setText, METH_O},
    {"setTextAlignment", (PyCFunction)Sbk_QTableWidgetItemFunc_setTextAlignment, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QTableWidgetItemFunc_setToolTip, METH_O},
    {"setWhatsThis", (PyCFunction)Sbk_QTableWidgetItemFunc_setWhatsThis, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QTableWidgetItemFunc_sizeHint, METH_NOARGS},
    {"statusTip", (PyCFunction)Sbk_QTableWidgetItemFunc_statusTip, METH_NOARGS},
    {"tableWidget", (PyCFunction)Sbk_QTableWidgetItemFunc_tableWidget, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QTableWidgetItemFunc_text, METH_NOARGS},
    {"textAlignment", (PyCFunction)Sbk_QTableWidgetItemFunc_textAlignment, METH_NOARGS},
    {"toolTip", (PyCFunction)Sbk_QTableWidgetItemFunc_toolTip, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QTableWidgetItemFunc_type, METH_NOARGS},
    {"whatsThis", (PyCFunction)Sbk_QTableWidgetItemFunc_whatsThis, METH_NOARGS},
    {"write", (PyCFunction)Sbk_QTableWidgetItemFunc_write, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QTableWidgetItemFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rlshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rlshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator<<(QDataStream&,QTableWidgetItem)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QTableWidgetItem)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QTableWidgetItem) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) << (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTableWidgetItemFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QTableWidgetItemFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTableWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    if (!isReverse
        && Shiboken::Object::checkType(pyArg)
        && !PyObject_TypeCheck(pyArg, self->ob_type)
        && PyObject_HasAttrString(pyArg, const_cast<char*>("__rrshift__"))) {
        PyObject* revOpMethod = PyObject_GetAttrString(pyArg, const_cast<char*>("__rrshift__"));
        if (revOpMethod && PyCallable_Check(revOpMethod)) {
            pyResult = PyObject_CallFunction(revOpMethod, const_cast<char*>("O"), self);
            if (PyErr_Occurred() && (PyErr_ExceptionMatches(PyExc_NotImplementedError) || PyErr_ExceptionMatches(PyExc_AttributeError))) {
                PyErr_Clear();
                Py_XDECREF(pyResult);
                pyResult = 0;
            }
        }
        Py_XDECREF(revOpMethod);

    }
    // Do not enter here if other object has implemented a reverse operator.
    if (!pyResult) {

    // Overloaded function decisor
    // 0: operator>>(QDataStream&,QTableWidgetItem&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QTableWidgetItem&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTableWidgetItemFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QTableWidgetItem&) [reverse operator]
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDataStream & cppResult = (*cppArg0) >> (*cppSelf);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], &cppResult);
        }
    }

    } // End of "if (!pyResult)"

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTableWidgetItemFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTableWidgetItem.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QTableWidgetItem_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTableWidgetItem& cppSelf = *(((::QTableWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_LT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX], (pyArg)))) {
                // operator<(const QTableWidgetItem & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTableWidgetItem* cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTableWidgetItem_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QTableWidgetItem_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTableWidgetItem_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QTableWidgetItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTableWidgetItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTableWidgetItem_TypeAsNumber;

static SbkObjectType Sbk_QTableWidgetItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTableWidgetItem",
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
    /*tp_traverse*/         Sbk_QTableWidgetItem_traverse,
    /*tp_clear*/            Sbk_QTableWidgetItem_clear,
    /*tp_richcompare*/      Sbk_QTableWidgetItem_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTableWidgetItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTableWidgetItem_Init,
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
static void QTableWidgetItem_ItemType_PythonToCpp_QTableWidgetItem_ItemType(PyObject* pyIn, void* cppOut) {
    *((::QTableWidgetItem::ItemType*)cppOut) = (::QTableWidgetItem::ItemType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTableWidgetItem_ItemType_PythonToCpp_QTableWidgetItem_ItemType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX]))
        return QTableWidgetItem_ItemType_PythonToCpp_QTableWidgetItem_ItemType;
    return 0;
}
static PyObject* QTableWidgetItem_ItemType_CppToPython_QTableWidgetItem_ItemType(const void* cppIn) {
    int castCppIn = *((::QTableWidgetItem::ItemType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTableWidgetItem_PythonToCpp_QTableWidgetItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTableWidgetItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTableWidgetItem_PythonToCpp_QTableWidgetItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTableWidgetItem_Type))
        return QTableWidgetItem_PythonToCpp_QTableWidgetItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTableWidgetItem_PTR_CppToPython_QTableWidgetItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTableWidgetItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTableWidgetItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTableWidgetItem(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTableWidgetItem_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTableWidgetItem_TypeAsNumber.nb_rshift = Sbk_QTableWidgetItemFunc___rshift__;
    Sbk_QTableWidgetItem_TypeAsNumber.nb_lshift = Sbk_QTableWidgetItemFunc___lshift__;
    Sbk_QTableWidgetItem_Type.super.ht_type.tp_as_number = &Sbk_QTableWidgetItem_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTableWidgetItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTableWidgetItem", "QTableWidgetItem*",
        &Sbk_QTableWidgetItem_Type, &Shiboken::callCppDestructor< ::QTableWidgetItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTableWidgetItem_Type,
        QTableWidgetItem_PythonToCpp_QTableWidgetItem_PTR,
        is_QTableWidgetItem_PythonToCpp_QTableWidgetItem_PTR_Convertible,
        QTableWidgetItem_PTR_CppToPython_QTableWidgetItem);

    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetItem");
    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetItem*");
    Shiboken::Conversions::registerConverterName(converter, "QTableWidgetItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTableWidgetItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTableWidgetItemWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ItemType'.
    SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTableWidgetItem_Type,
        "ItemType",
        "PySide.QtGui.QTableWidgetItem.ItemType",
        "QTableWidgetItem::ItemType");
    if (!SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX],
        &Sbk_QTableWidgetItem_Type, "Type", (long) QTableWidgetItem::Type))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX],
        &Sbk_QTableWidgetItem_Type, "UserType", (long) QTableWidgetItem::UserType))
        return ;
    // Register converter for enum 'QTableWidgetItem::ItemType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX],
            QTableWidgetItem_ItemType_CppToPython_QTableWidgetItem_ItemType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTableWidgetItem_ItemType_PythonToCpp_QTableWidgetItem_ItemType,
            is_QTableWidgetItem_ItemType_PythonToCpp_QTableWidgetItem_ItemType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTABLEWIDGETITEM_ITEMTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTableWidgetItem::ItemType");
        Shiboken::Conversions::registerConverterName(converter, "ItemType");
    }
    // End of 'ItemType' enum.


    qRegisterMetaType< ::QTableWidgetItem::ItemType >("QTableWidgetItem::ItemType");
}
