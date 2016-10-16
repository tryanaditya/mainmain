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

#include "qstandarditem_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractitemmodel.h>
#include <qbrush.h>
#include <qdatastream.h>
#include <qfont.h>
#include <qicon.h>
#include <qsize.h>
#include <qstandarditemmodel.h>


// Native ---------------------------------------------------------

QStandardItemWrapper::QStandardItemWrapper() : QStandardItem() {
    // ... middle
}

QStandardItemWrapper::QStandardItemWrapper(const QIcon & icon, const QString & text) : QStandardItem(icon, text) {
    // ... middle
}

QStandardItemWrapper::QStandardItemWrapper(const QString & text) : QStandardItem(text) {
    // ... middle
}

QStandardItemWrapper::QStandardItemWrapper(int rows, int columns) : QStandardItem(rows, columns) {
    // ... middle
}

QStandardItem * QStandardItemWrapper::clone() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QStandardItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clone"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::clone();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QStandardItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItem.clone", Shiboken::SbkType< QStandardItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QStandardItem*)0);
    }
    ::QStandardItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (Shiboken::Object::checkType(pyResult))
        Shiboken::Object::releaseOwnership(pyResult);
    return cppResult;
}

QVariant QStandardItemWrapper::data(int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::data(role);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItem.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemWrapper::read(QDataStream & in)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::read(in);
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

void QStandardItemWrapper::setData(const QVariant & value, int role)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::setData(value, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(Ni)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value),
        role
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QStandardItemWrapper::type() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((int)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "type"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::type();
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QStandardItem.type", "int", pyResult->ob_type->tp_name);
        return ((int)0);
    }
    int cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QStandardItemWrapper::write(QDataStream & out) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QStandardItem::write(out);
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

QStandardItemWrapper::~QStandardItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QStandardItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QStandardItem >()))
        return -1;

    ::QStandardItemWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OO:QStandardItem", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QStandardItem()
    // 1: QStandardItem(QIcon,QString)
    // 2: QStandardItem(QStandardItem)
    // 3: QStandardItem(QString)
    // 4: QStandardItem(int,int)
    if (numArgs == 0) {
        overloadId = 0; // QStandardItem()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 4; // QStandardItem(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 4; // QStandardItem(int,int)
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 3; // QStandardItem(QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[0])))) {
        overloadId = 2; // QStandardItem(QStandardItem)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // QStandardItem(QIcon,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QStandardItem()
        {

            if (!PyErr_Occurred()) {
                // QStandardItem()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStandardItemWrapper();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QStandardItem(const QIcon & icon, const QString & text)
        {
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

            if (!PyErr_Occurred()) {
                // QStandardItem(QIcon,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStandardItemWrapper(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 2: // QStandardItem(const QStandardItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QStandardItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStandardItem(QStandardItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStandardItemWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 3: // QStandardItem(const QString & text)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QStandardItem(QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStandardItemWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 4: // QStandardItem(int rows, int columns)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "columns");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem(): got multiple values for keyword argument 'columns'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QStandardItem_Init_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 1;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QStandardItem(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QStandardItemWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QStandardItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QStandardItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QStandardItem_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtGui.QIcon, unicode", "PySide.QtGui.QStandardItem", "unicode", "int, int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem", overloads);
        return -1;
}

static PyObject* Sbk_QStandardItemFunc_accessibleDescription(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accessibleDescription()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->accessibleDescription();
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

static PyObject* Sbk_QStandardItemFunc_accessibleText(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // accessibleText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->accessibleText();
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

static PyObject* Sbk_QStandardItemFunc_appendColumn(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendColumn(QList<QStandardItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArg)))) {
        overloadId = 0; // appendColumn(QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_appendColumn_TypeError;

    // Call function/method
    {
        ::QList<QStandardItem * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendColumn(QList<QStandardItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_appendColumn_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.appendColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_appendRow(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendRow(QStandardItem*)
    // 1: appendRow(QList<QStandardItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArg)))) {
        overloadId = 0; // appendRow(QStandardItem*)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArg)))) {
        overloadId = 1; // appendRow(QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_appendRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // appendRow(QStandardItem * item)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QStandardItem* cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendRow(QStandardItem*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArg);
            }
            break;
        }
        case 1: // appendRow(const QList<QStandardItem * > & items)
        {
            ::QList<QStandardItem * > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // appendRow(QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->appendRow(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArg);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_appendRow_TypeError:
        const char* overloads[] = {"PySide.QtGui.QStandardItem", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.appendRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_appendRows(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: appendRows(QList<QStandardItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArg)))) {
        overloadId = 0; // appendRows(QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_appendRows_TypeError;

    // Call function/method
    {
        ::QList<QStandardItem * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendRows(QList<QStandardItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->appendRows(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_appendRows_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.appendRows", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_background(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // background()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QStandardItem*>(cppSelf)->background();
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

static PyObject* Sbk_QStandardItemFunc_checkState(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // checkState()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CheckState cppResult = const_cast<const ::QStandardItem*>(cppSelf)->checkState();
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

static PyObject* Sbk_QStandardItemFunc_child(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.child(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.child(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:child", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: child(int,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // child(int,int)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // child(int,int)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_child_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.child(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemFunc_child_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // child(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItem*>(cppSelf)->child(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemFunc_child_TypeError:
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.child", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_clone(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clone()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItem*>(cppSelf)->::QStandardItem::clone() : const_cast<const ::QStandardItem*>(cppSelf)->clone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemFunc_column(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // column()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStandardItem*>(cppSelf)->column();
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

static PyObject* Sbk_QStandardItemFunc_columnCount(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStandardItem*>(cppSelf)->columnCount();
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

static PyObject* Sbk_QStandardItemFunc_data(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.data(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:data", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: data(int)const
    if (numArgs == 0) {
        overloadId = 0; // data(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // data(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_data_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.data(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QStandardItemFunc_data_TypeError;
            }
        }
        int cppArg0 = Qt::UserRole + 1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // data(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItem*>(cppSelf)->::QStandardItem::data(cppArg0) : const_cast<const ::QStandardItem*>(cppSelf)->data(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemFunc_data_TypeError:
        const char* overloads[] = {"int = Qt.UserRole + 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.data", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_emitDataChanged(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // emitDataChanged()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->emitDataChanged();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QStandardItemFunc_flags(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = const_cast<const ::QStandardItem*>(cppSelf)->flags();
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

static PyObject* Sbk_QStandardItemFunc_font(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QStandardItem*>(cppSelf)->font();
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

static PyObject* Sbk_QStandardItemFunc_foreground(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // foreground()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QStandardItem*>(cppSelf)->foreground();
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

static PyObject* Sbk_QStandardItemFunc_hasChildren(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasChildren()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->hasChildren();
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

static PyObject* Sbk_QStandardItemFunc_icon(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QStandardItem*>(cppSelf)->icon();
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

static PyObject* Sbk_QStandardItemFunc_index(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // index()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QStandardItem*>(cppSelf)->index();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemFunc_insertColumn(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertColumn", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertColumn(int,QList<QStandardItem*>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertColumn(int,QList<QStandardItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_insertColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QList<QStandardItem * > cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertColumn(int,QList<QStandardItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertColumn(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_insertColumn_TypeError:
        const char* overloads[] = {"int, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.insertColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_insertColumns(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertColumns", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertColumns(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // insertColumns(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_insertColumns_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertColumns(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertColumns(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_insertColumns_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.insertColumns", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_insertRow(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertRow", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertRow(int,QStandardItem*)
    // 1: insertRow(int,QList<QStandardItem*>)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertRow(int,QStandardItem*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArgs[1])))) {
            overloadId = 1; // insertRow(int,QList<QStandardItem*>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_insertRow_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertRow(int row, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QStandardItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QStandardItem*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // insertRow(int row, const QList<QStandardItem * > & items)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QList<QStandardItem * > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRow(int,QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRow(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_insertRow_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", "int, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.insertRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_insertRows(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertRows", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertRows(int,QList<QStandardItem*>)
    // 1: insertRows(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // insertRows(int,int)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], (pyArgs[1])))) {
            overloadId = 0; // insertRows(int,QList<QStandardItem*>)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_insertRows_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // insertRows(int row, const QList<QStandardItem * > & items)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QList<QStandardItem * > cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRows(int,QList<QStandardItem*>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRows(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 1: // insertRows(int row, int count)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // insertRows(int,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->insertRows(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_insertRows_TypeError:
        const char* overloads[] = {"int, list", "int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.insertRows", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_isCheckable(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCheckable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isCheckable();
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

static PyObject* Sbk_QStandardItemFunc_isDragEnabled(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDragEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isDragEnabled();
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

static PyObject* Sbk_QStandardItemFunc_isDropEnabled(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDropEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isDropEnabled();
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

static PyObject* Sbk_QStandardItemFunc_isEditable(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEditable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isEditable();
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

static PyObject* Sbk_QStandardItemFunc_isEnabled(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_QStandardItemFunc_isSelectable(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelectable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isSelectable();
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

static PyObject* Sbk_QStandardItemFunc_isTristate(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isTristate()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QStandardItem*>(cppSelf)->isTristate();
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

static PyObject* Sbk_QStandardItemFunc_model(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItemModel * cppResult = const_cast<const ::QStandardItem*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemFunc_parent(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = const_cast<const ::QStandardItem*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(QDataStream&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // read(QDataStream&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(QDataStream&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItem::read(*cppArg0) : cppSelf->read(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_read_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.read", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_removeColumn(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeColumn(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeColumn(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_removeColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeColumn(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_removeColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.removeColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_removeColumns(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removeColumns", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeColumns(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // removeColumns(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_removeColumns_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeColumns(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeColumns(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_removeColumns_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.removeColumns", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_removeRow(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeRow(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeRow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_removeRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeRow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_removeRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.removeRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_removeRows(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "removeRows", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: removeRows(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // removeRows(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_removeRows_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeRows(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeRows(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_removeRows_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.removeRows", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_row(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // row()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStandardItem*>(cppSelf)->row();
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

static PyObject* Sbk_QStandardItemFunc_rowCount(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // rowCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QStandardItem*>(cppSelf)->rowCount();
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

static PyObject* Sbk_QStandardItemFunc_setAccessibleDescription(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccessibleDescription(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setAccessibleDescription(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setAccessibleDescription_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccessibleDescription(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccessibleDescription(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setAccessibleDescription_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setAccessibleDescription", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setAccessibleText(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAccessibleText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setAccessibleText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setAccessibleText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAccessibleText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAccessibleText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setAccessibleText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setAccessibleText", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setBackground(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBackground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setBackground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setBackground_TypeError;

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

    Sbk_QStandardItemFunc_setBackground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setBackground", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setCheckState(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCheckState(Qt::CheckState)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), (pyArg)))) {
        overloadId = 0; // setCheckState(Qt::CheckState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setCheckState_TypeError;

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

    Sbk_QStandardItemFunc_setCheckState_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CheckState", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setCheckState", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setCheckable(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCheckable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCheckable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setCheckable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCheckable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCheckable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setCheckable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setCheckable", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setChild(PyObject* self, PyObject* args)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setChild", 2, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setChild(int,QStandardItem*)
    // 1: setChild(int,int,QStandardItem*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 3
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
            && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[2])))) {
            overloadId = 1; // setChild(int,int,QStandardItem*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (pyArgs[1])))) {
            overloadId = 0; // setChild(int,QStandardItem*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setChild_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setChild(int row, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QStandardItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setChild(int,QStandardItem*)
                // Begin code injection

                // Clear parent from the old child
                QStandardItem* _i = cppSelf->child(cppArg0);
                if (_i) {
                    PyObject* _pyI = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], _i);
                    Shiboken::Object::setParent(0, _pyI);
                }

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setChild(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                Shiboken::Object::setParent(self, pyArgs[1]);
            }
            break;
        }
        case 1: // setChild(int row, int column, QStandardItem * item)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return 0;
            ::QStandardItem* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // setChild(int,int,QStandardItem*)
                // Begin code injection

                // Clear parent from the old child
                QStandardItem* _i = cppSelf->child(cppArg0, cppArg1);
                if (_i) {
                    PyObject* _pyI = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], _i);
                    Shiboken::Object::setParent(0, _pyI);
                }

                // End of code injection

                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setChild(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS

                Shiboken::Object::setParent(self, pyArgs[2]);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setChild_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QStandardItem", "int, int, PySide.QtGui.QStandardItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.setChild", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setColumnCount(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setColumnCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setColumnCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setColumnCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColumnCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setColumnCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setColumnCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setColumnCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setData(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.setData(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.setData(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:setData", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setData(QVariant,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setData(QVariant,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setData(QVariant,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setData_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "role");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.setData(): got multiple values for keyword argument 'role'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemFunc_setData_TypeError;
            }
        }
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = Qt::UserRole + 1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setData(QVariant,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QStandardItem::setData(cppArg0, cppArg1) : cppSelf->setData(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setData_TypeError:
        const char* overloads[] = {"QVariant, int = Qt.UserRole + 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.setData", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setDragEnabled(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDragEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDragEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setDragEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDragEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDragEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setDragEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setDragEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setDropEnabled(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDropEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDropEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setDropEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDropEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDropEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setDropEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setDropEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setEditable(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEditable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEditable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setEditable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEditable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEditable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setEditable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setEditable", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEnabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setFlags(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFlags(QFlags<Qt::ItemFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFlags(QFlags<Qt::ItemFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setFlags_TypeError;

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

    Sbk_QStandardItemFunc_setFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ItemFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setFlags", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setFont_TypeError;

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

    Sbk_QStandardItemFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setForeground(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setForeground(QBrush)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArg)))) {
        overloadId = 0; // setForeground(QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setForeground_TypeError;

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

    Sbk_QStandardItemFunc_setForeground_TypeError:
        const char* overloads[] = {"PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setForeground", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setIcon_TypeError;

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

    Sbk_QStandardItemFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setRowCount(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setRowCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setRowCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setRowCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setRowCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setRowCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setRowCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setRowCount", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setSelectable(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelectable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSelectable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setSelectable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSelectable(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSelectable(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setSelectable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setSelectable", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setSizeHint(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSizeHint(QSize)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArg)))) {
        overloadId = 0; // setSizeHint(QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setSizeHint_TypeError;

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

    Sbk_QStandardItemFunc_setSizeHint_TypeError:
        const char* overloads[] = {"PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setSizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setStatusTip(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatusTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatusTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setStatusTip_TypeError;

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

    Sbk_QStandardItemFunc_setStatusTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setStatusTip", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setText(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setText_TypeError;

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

    Sbk_QStandardItemFunc_setText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setText", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setTextAlignment(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTextAlignment(QFlags<Qt::AlignmentFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setTextAlignment(QFlags<Qt::AlignmentFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setTextAlignment_TypeError;

    // Call function/method
    {
        ::QFlags<Qt::AlignmentFlag> cppArg0 = ((::QFlags<Qt::AlignmentFlag>)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTextAlignment(QFlags<Qt::AlignmentFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setTextAlignment_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.Alignment", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setTextAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setToolTip_TypeError;

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

    Sbk_QStandardItemFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setTristate(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTristate(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setTristate(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setTristate_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTristate(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTristate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_setTristate_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setTristate", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_setWhatsThis(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWhatsThis(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWhatsThis(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_setWhatsThis_TypeError;

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

    Sbk_QStandardItemFunc_setWhatsThis_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.setWhatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_sizeHint(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // sizeHint()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QStandardItem*>(cppSelf)->sizeHint();
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

static PyObject* Sbk_QStandardItemFunc_sortChildren(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.sortChildren(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.sortChildren(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:sortChildren", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sortChildren(int,Qt::SortOrder)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // sortChildren(int,Qt::SortOrder)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1])))) {
            overloadId = 0; // sortChildren(int,Qt::SortOrder)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_sortChildren_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "order");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.sortChildren(): got multiple values for keyword argument 'order'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1]))))
                    goto Sbk_QStandardItemFunc_sortChildren_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = Qt::AscendingOrder;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // sortChildren(int,Qt::SortOrder)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->sortChildren(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_sortChildren_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder = Qt.AscendingOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.sortChildren", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_statusTip(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // statusTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->statusTip();
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

static PyObject* Sbk_QStandardItemFunc_takeChild(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.takeChild(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.takeChild(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:takeChild", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: takeChild(int,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // takeChild(int,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // takeChild(int,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_takeChild_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QStandardItem.takeChild(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_QStandardItemFunc_takeChild_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // takeChild(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStandardItem * cppResult = cppSelf->takeChild(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], cppResult);
            Shiboken::Object::setParent(Py_None, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemFunc_takeChild_TypeError:
        const char* overloads[] = {"int, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QStandardItem.takeChild", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_takeColumn(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeColumn(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeColumn(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_takeColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeColumn(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QStandardItem * > cppResult = cppSelf->takeColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemFunc_takeColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.takeColumn", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_takeRow(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeRow(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeRow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_takeRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeRow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QStandardItem * > cppResult = cppSelf->takeRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QStandardItemFunc_takeRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.takeRow", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc_text(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->text();
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

static PyObject* Sbk_QStandardItemFunc_textAlignment(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // textAlignment()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::AlignmentFlag> cppResult = const_cast<const ::QStandardItem*>(cppSelf)->textAlignment();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ALIGNMENTFLAG__IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QStandardItemFunc_toolTip(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->toolTip();
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

static PyObject* Sbk_QStandardItemFunc_type(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItem*>(cppSelf)->::QStandardItem::type() : const_cast<const ::QStandardItem*>(cppSelf)->type();
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

static PyObject* Sbk_QStandardItemFunc_whatsThis(PyObject* self)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // whatsThis()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QStandardItem*>(cppSelf)->whatsThis();
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

static PyObject* Sbk_QStandardItemFunc_write(PyObject* self, PyObject* pyArg)
{
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QDataStream&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // write(QDataStream&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // write(QDataStream&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QStandardItem*>(cppSelf)->::QStandardItem::write(*cppArg0) : const_cast<const ::QStandardItem*>(cppSelf)->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QStandardItemFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QStandardItem_methods[] = {
    {"accessibleDescription", (PyCFunction)Sbk_QStandardItemFunc_accessibleDescription, METH_NOARGS},
    {"accessibleText", (PyCFunction)Sbk_QStandardItemFunc_accessibleText, METH_NOARGS},
    {"appendColumn", (PyCFunction)Sbk_QStandardItemFunc_appendColumn, METH_O},
    {"appendRow", (PyCFunction)Sbk_QStandardItemFunc_appendRow, METH_O},
    {"appendRows", (PyCFunction)Sbk_QStandardItemFunc_appendRows, METH_O},
    {"background", (PyCFunction)Sbk_QStandardItemFunc_background, METH_NOARGS},
    {"checkState", (PyCFunction)Sbk_QStandardItemFunc_checkState, METH_NOARGS},
    {"child", (PyCFunction)Sbk_QStandardItemFunc_child, METH_VARARGS|METH_KEYWORDS},
    {"clone", (PyCFunction)Sbk_QStandardItemFunc_clone, METH_NOARGS},
    {"column", (PyCFunction)Sbk_QStandardItemFunc_column, METH_NOARGS},
    {"columnCount", (PyCFunction)Sbk_QStandardItemFunc_columnCount, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QStandardItemFunc_data, METH_VARARGS|METH_KEYWORDS},
    {"emitDataChanged", (PyCFunction)Sbk_QStandardItemFunc_emitDataChanged, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QStandardItemFunc_flags, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QStandardItemFunc_font, METH_NOARGS},
    {"foreground", (PyCFunction)Sbk_QStandardItemFunc_foreground, METH_NOARGS},
    {"hasChildren", (PyCFunction)Sbk_QStandardItemFunc_hasChildren, METH_NOARGS},
    {"icon", (PyCFunction)Sbk_QStandardItemFunc_icon, METH_NOARGS},
    {"index", (PyCFunction)Sbk_QStandardItemFunc_index, METH_NOARGS},
    {"insertColumn", (PyCFunction)Sbk_QStandardItemFunc_insertColumn, METH_VARARGS},
    {"insertColumns", (PyCFunction)Sbk_QStandardItemFunc_insertColumns, METH_VARARGS},
    {"insertRow", (PyCFunction)Sbk_QStandardItemFunc_insertRow, METH_VARARGS},
    {"insertRows", (PyCFunction)Sbk_QStandardItemFunc_insertRows, METH_VARARGS},
    {"isCheckable", (PyCFunction)Sbk_QStandardItemFunc_isCheckable, METH_NOARGS},
    {"isDragEnabled", (PyCFunction)Sbk_QStandardItemFunc_isDragEnabled, METH_NOARGS},
    {"isDropEnabled", (PyCFunction)Sbk_QStandardItemFunc_isDropEnabled, METH_NOARGS},
    {"isEditable", (PyCFunction)Sbk_QStandardItemFunc_isEditable, METH_NOARGS},
    {"isEnabled", (PyCFunction)Sbk_QStandardItemFunc_isEnabled, METH_NOARGS},
    {"isSelectable", (PyCFunction)Sbk_QStandardItemFunc_isSelectable, METH_NOARGS},
    {"isTristate", (PyCFunction)Sbk_QStandardItemFunc_isTristate, METH_NOARGS},
    {"model", (PyCFunction)Sbk_QStandardItemFunc_model, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QStandardItemFunc_parent, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QStandardItemFunc_read, METH_O},
    {"removeColumn", (PyCFunction)Sbk_QStandardItemFunc_removeColumn, METH_O},
    {"removeColumns", (PyCFunction)Sbk_QStandardItemFunc_removeColumns, METH_VARARGS},
    {"removeRow", (PyCFunction)Sbk_QStandardItemFunc_removeRow, METH_O},
    {"removeRows", (PyCFunction)Sbk_QStandardItemFunc_removeRows, METH_VARARGS},
    {"row", (PyCFunction)Sbk_QStandardItemFunc_row, METH_NOARGS},
    {"rowCount", (PyCFunction)Sbk_QStandardItemFunc_rowCount, METH_NOARGS},
    {"setAccessibleDescription", (PyCFunction)Sbk_QStandardItemFunc_setAccessibleDescription, METH_O},
    {"setAccessibleText", (PyCFunction)Sbk_QStandardItemFunc_setAccessibleText, METH_O},
    {"setBackground", (PyCFunction)Sbk_QStandardItemFunc_setBackground, METH_O},
    {"setCheckState", (PyCFunction)Sbk_QStandardItemFunc_setCheckState, METH_O},
    {"setCheckable", (PyCFunction)Sbk_QStandardItemFunc_setCheckable, METH_O},
    {"setChild", (PyCFunction)Sbk_QStandardItemFunc_setChild, METH_VARARGS},
    {"setColumnCount", (PyCFunction)Sbk_QStandardItemFunc_setColumnCount, METH_O},
    {"setData", (PyCFunction)Sbk_QStandardItemFunc_setData, METH_VARARGS|METH_KEYWORDS},
    {"setDragEnabled", (PyCFunction)Sbk_QStandardItemFunc_setDragEnabled, METH_O},
    {"setDropEnabled", (PyCFunction)Sbk_QStandardItemFunc_setDropEnabled, METH_O},
    {"setEditable", (PyCFunction)Sbk_QStandardItemFunc_setEditable, METH_O},
    {"setEnabled", (PyCFunction)Sbk_QStandardItemFunc_setEnabled, METH_O},
    {"setFlags", (PyCFunction)Sbk_QStandardItemFunc_setFlags, METH_O},
    {"setFont", (PyCFunction)Sbk_QStandardItemFunc_setFont, METH_O},
    {"setForeground", (PyCFunction)Sbk_QStandardItemFunc_setForeground, METH_O},
    {"setIcon", (PyCFunction)Sbk_QStandardItemFunc_setIcon, METH_O},
    {"setRowCount", (PyCFunction)Sbk_QStandardItemFunc_setRowCount, METH_O},
    {"setSelectable", (PyCFunction)Sbk_QStandardItemFunc_setSelectable, METH_O},
    {"setSizeHint", (PyCFunction)Sbk_QStandardItemFunc_setSizeHint, METH_O},
    {"setStatusTip", (PyCFunction)Sbk_QStandardItemFunc_setStatusTip, METH_O},
    {"setText", (PyCFunction)Sbk_QStandardItemFunc_setText, METH_O},
    {"setTextAlignment", (PyCFunction)Sbk_QStandardItemFunc_setTextAlignment, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QStandardItemFunc_setToolTip, METH_O},
    {"setTristate", (PyCFunction)Sbk_QStandardItemFunc_setTristate, METH_O},
    {"setWhatsThis", (PyCFunction)Sbk_QStandardItemFunc_setWhatsThis, METH_O},
    {"sizeHint", (PyCFunction)Sbk_QStandardItemFunc_sizeHint, METH_NOARGS},
    {"sortChildren", (PyCFunction)Sbk_QStandardItemFunc_sortChildren, METH_VARARGS|METH_KEYWORDS},
    {"statusTip", (PyCFunction)Sbk_QStandardItemFunc_statusTip, METH_NOARGS},
    {"takeChild", (PyCFunction)Sbk_QStandardItemFunc_takeChild, METH_VARARGS|METH_KEYWORDS},
    {"takeColumn", (PyCFunction)Sbk_QStandardItemFunc_takeColumn, METH_O},
    {"takeRow", (PyCFunction)Sbk_QStandardItemFunc_takeRow, METH_O},
    {"text", (PyCFunction)Sbk_QStandardItemFunc_text, METH_NOARGS},
    {"textAlignment", (PyCFunction)Sbk_QStandardItemFunc_textAlignment, METH_NOARGS},
    {"toolTip", (PyCFunction)Sbk_QStandardItemFunc_toolTip, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QStandardItemFunc_type, METH_NOARGS},
    {"whatsThis", (PyCFunction)Sbk_QStandardItemFunc_whatsThis, METH_NOARGS},
    {"write", (PyCFunction)Sbk_QStandardItemFunc_write, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QStandardItemFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QStandardItem)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QStandardItem)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QStandardItem) [reverse operator]
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

    Sbk_QStandardItemFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QStandardItemFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QStandardItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QStandardItem&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QStandardItem&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QStandardItemFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QStandardItem&) [reverse operator]
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

    Sbk_QStandardItemFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QStandardItem.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QStandardItem_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QStandardItem& cppSelf = *(((::QStandardItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        default:
            goto Sbk_QStandardItem_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QStandardItem_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static int Sbk_QStandardItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QStandardItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QStandardItem_TypeAsNumber;

static SbkObjectType Sbk_QStandardItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QStandardItem",
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
    /*tp_traverse*/         Sbk_QStandardItem_traverse,
    /*tp_clear*/            Sbk_QStandardItem_clear,
    /*tp_richcompare*/      Sbk_QStandardItem_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QStandardItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QStandardItem_Init,
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
static void QStandardItem_ItemType_PythonToCpp_QStandardItem_ItemType(PyObject* pyIn, void* cppOut) {
    *((::QStandardItem::ItemType*)cppOut) = (::QStandardItem::ItemType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QStandardItem_ItemType_PythonToCpp_QStandardItem_ItemType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX]))
        return QStandardItem_ItemType_PythonToCpp_QStandardItem_ItemType;
    return 0;
}
static PyObject* QStandardItem_ItemType_CppToPython_QStandardItem_ItemType(const void* cppIn) {
    int castCppIn = *((::QStandardItem::ItemType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QStandardItem_PythonToCpp_QStandardItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QStandardItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QStandardItem_PythonToCpp_QStandardItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QStandardItem_Type))
        return QStandardItem_PythonToCpp_QStandardItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QStandardItem_PTR_CppToPython_QStandardItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QStandardItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QStandardItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QStandardItem(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QStandardItem_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QStandardItem_TypeAsNumber.nb_rshift = Sbk_QStandardItemFunc___rshift__;
    Sbk_QStandardItem_TypeAsNumber.nb_lshift = Sbk_QStandardItemFunc___lshift__;
    Sbk_QStandardItem_Type.super.ht_type.tp_as_number = &Sbk_QStandardItem_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QStandardItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QStandardItem", "QStandardItem*",
        &Sbk_QStandardItem_Type, &Shiboken::callCppDestructor< ::QStandardItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QStandardItem_Type,
        QStandardItem_PythonToCpp_QStandardItem_PTR,
        is_QStandardItem_PythonToCpp_QStandardItem_PTR_Convertible,
        QStandardItem_PTR_CppToPython_QStandardItem);

    Shiboken::Conversions::registerConverterName(converter, "QStandardItem");
    Shiboken::Conversions::registerConverterName(converter, "QStandardItem*");
    Shiboken::Conversions::registerConverterName(converter, "QStandardItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStandardItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QStandardItemWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ItemType'.
    SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QStandardItem_Type,
        "ItemType",
        "PySide.QtGui.QStandardItem.ItemType",
        "QStandardItem::ItemType");
    if (!SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX],
        &Sbk_QStandardItem_Type, "Type", (long) QStandardItem::Type))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX],
        &Sbk_QStandardItem_Type, "UserType", (long) QStandardItem::UserType))
        return ;
    // Register converter for enum 'QStandardItem::ItemType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX],
            QStandardItem_ItemType_CppToPython_QStandardItem_ItemType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QStandardItem_ItemType_PythonToCpp_QStandardItem_ItemType,
            is_QStandardItem_ItemType_PythonToCpp_QStandardItem_ItemType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QStandardItem::ItemType");
        Shiboken::Conversions::registerConverterName(converter, "ItemType");
    }
    // End of 'ItemType' enum.


    qRegisterMetaType< ::QStandardItem::ItemType >("QStandardItem::ItemType");
}
