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

#include "qtreewidgetitem_wrapper.h"

// Extra includes
#include <QList>
#include <qbrush.h>
#include <qdatastream.h>
#include <qfont.h>
#include <qicon.h>
#include <qsize.h>
#include <qtreewidget.h>


// Native ---------------------------------------------------------

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidget * view, QTreeWidgetItem * after, int type) : QTreeWidgetItem(view, after, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidget * view, const QStringList & strings, int type) : QTreeWidgetItem(view, strings, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidget * view, int type) : QTreeWidgetItem(view, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidgetItem * parent, QTreeWidgetItem * after, int type) : QTreeWidgetItem(parent, after, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidgetItem * parent, const QStringList & strings, int type) : QTreeWidgetItem(parent, strings, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(QTreeWidgetItem * parent, int type) : QTreeWidgetItem(parent, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(const QStringList & strings, int type) : QTreeWidgetItem(strings, type) {
    // ... middle
}

QTreeWidgetItemWrapper::QTreeWidgetItemWrapper(int type) : QTreeWidgetItem(type) {
    // ... middle
}

QTreeWidgetItem * QTreeWidgetItemWrapper::clone() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QTreeWidgetItem*)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clone"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::clone();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QTreeWidgetItem*)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTreeWidgetItem.clone", Shiboken::SbkType< QTreeWidgetItem >()->tp_name, pyResult->ob_type->tp_name);
        return ((::QTreeWidgetItem*)0);
    }
    ::QTreeWidgetItem* cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QVariant QTreeWidgetItemWrapper::data(int column, int role) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QVariant();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "data"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::data(column, role);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ii)",
        column,
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTreeWidgetItem.data", "QVariant", pyResult->ob_type->tp_name);
        return ::QVariant();
    }
    ::QVariant cppResult = ::QVariant();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool QTreeWidgetItemWrapper::operator<(const QTreeWidgetItem & other) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "__lt__"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::operator<(other);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::referenceToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], &other)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTreeWidgetItem.__lt__", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QTreeWidgetItemWrapper::read(QDataStream & in)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "read"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::read(in);
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

void QTreeWidgetItemWrapper::setData(int column, int role, const QVariant & value)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setData"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::setData(column, role, value);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(iiN)",
        column,
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

void QTreeWidgetItemWrapper::write(QDataStream & out) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "write"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTreeWidgetItem::write(out);
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

QTreeWidgetItemWrapper::~QTreeWidgetItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTreeWidgetItem_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTreeWidgetItem >()))
        return -1;

    ::QTreeWidgetItemWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOO:QTreeWidgetItem", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QTreeWidgetItem(QTreeWidget*,QTreeWidgetItem*,int)
    // 1: QTreeWidgetItem(QTreeWidget*,QStringList,int)
    // 2: QTreeWidgetItem(QTreeWidget*,int)
    // 3: QTreeWidgetItem(QTreeWidgetItem*,QTreeWidgetItem*,int)
    // 4: QTreeWidgetItem(QTreeWidgetItem*,QStringList,int)
    // 5: QTreeWidgetItem(QTreeWidgetItem*,int)
    // 6: QTreeWidgetItem(QStringList,int)
    // 7: QTreeWidgetItem(QTreeWidgetItem)
    // 8: QTreeWidgetItem(int)
    if (numArgs == 0) {
        overloadId = 8; // QTreeWidgetItem(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 8; // QTreeWidgetItem(int)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 6; // QTreeWidgetItem(QStringList,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 6; // QTreeWidgetItem(QStringList,int)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 5; // QTreeWidgetItem(QTreeWidgetItem*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 5; // QTreeWidgetItem(QTreeWidgetItem*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 4; // QTreeWidgetItem(QTreeWidgetItem*,QStringList,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 4; // QTreeWidgetItem(QTreeWidgetItem*,QStringList,int)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 3; // QTreeWidgetItem(QTreeWidgetItem*,QTreeWidgetItem*,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 3; // QTreeWidgetItem(QTreeWidgetItem*,QTreeWidgetItem*,int)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGET_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QTreeWidgetItem(QTreeWidget*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 2; // QTreeWidgetItem(QTreeWidget*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // QTreeWidgetItem(QTreeWidget*,QStringList,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // QTreeWidgetItem(QTreeWidget*,QStringList,int)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // QTreeWidgetItem(QTreeWidget*,QTreeWidgetItem*,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 0; // QTreeWidgetItem(QTreeWidget*,QTreeWidgetItem*,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItem_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QTreeWidgetItem(QTreeWidget * view, QTreeWidgetItem * after, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QTreeWidgetItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = QTreeWidgetItem::Type;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidget*,QTreeWidgetItem*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QTreeWidgetItem(QTreeWidget * view, const QStringList & strings, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = QTreeWidgetItem::Type;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidget*,QStringList,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QTreeWidgetItem(QTreeWidget * view, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QTreeWidgetItem::Type;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidget*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 3: // QTreeWidgetItem(QTreeWidgetItem * parent, QTreeWidgetItem * after, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QTreeWidgetItem* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = QTreeWidgetItem::Type;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidgetItem*,QTreeWidgetItem*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 4: // QTreeWidgetItem(QTreeWidgetItem * parent, const QStringList & strings, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QStringList cppArg1 = ::QStringList();
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = QTreeWidgetItem::Type;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidgetItem*,QStringList,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 5: // QTreeWidgetItem(QTreeWidgetItem * parent, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QTreeWidgetItem::Type;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidgetItem*,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 6: // QTreeWidgetItem(const QStringList & strings, int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            ::QStringList cppArg0 = ::QStringList();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = QTreeWidgetItem::Type;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QStringList,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 7: // QTreeWidgetItem(const QTreeWidgetItem & other)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QTreeWidgetItem* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(QTreeWidgetItem)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 8: // QTreeWidgetItem(int type)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "type");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QTreeWidgetItem(): got multiple values for keyword argument 'type'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                        goto Sbk_QTreeWidgetItem_Init_TypeError;
                }
            }
            int cppArg0 = QTreeWidgetItem::Type;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QTreeWidgetItem(int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new ::QTreeWidgetItemWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTreeWidgetItem >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTreeWidgetItem_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QTreeWidgetItem_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidget, PySide.QtGui.QTreeWidgetItem, int = Type", "PySide.QtGui.QTreeWidget, QStringList, int = Type", "PySide.QtGui.QTreeWidget, int = Type", "PySide.QtGui.QTreeWidgetItem, PySide.QtGui.QTreeWidgetItem, int = Type", "PySide.QtGui.QTreeWidgetItem, QStringList, int = Type", "PySide.QtGui.QTreeWidgetItem, int = Type", "QStringList, int = Type", "PySide.QtGui.QTreeWidgetItem", "int = Type", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem", overloads);
        return -1;
}

static PyObject* Sbk_QTreeWidgetItemFunc_addChild(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addChild(QTreeWidgetItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArg)))) {
        overloadId = 0; // addChild(QTreeWidgetItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_addChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTreeWidgetItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addChild(QTreeWidgetItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_addChild_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidgetItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.addChild", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_addChildren(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addChildren(QList<QTreeWidgetItem*>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX], (pyArg)))) {
        overloadId = 0; // addChildren(QList<QTreeWidgetItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_addChildren_TypeError;

    // Call function/method
    {
        ::QList<QTreeWidgetItem * > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addChildren(QList<QTreeWidgetItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->addChildren(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_addChildren_TypeError:
        const char* overloads[] = {"list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.addChildren", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_background(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: background(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // background(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_background_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // background(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->background(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_background_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.background", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_checkState(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: checkState(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // checkState(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_checkState_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // checkState(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CheckState cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->checkState(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_checkState_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.checkState", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_child(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: child(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // child(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_child_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // child(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidgetItem * cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->child(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_child_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.child", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_childCount(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->childCount();
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

static PyObject* Sbk_QTreeWidgetItemFunc_childIndicatorPolicy(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // childIndicatorPolicy()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidgetItem::ChildIndicatorPolicy cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->childIndicatorPolicy();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemFunc_clone(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clone()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidgetItem * cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTreeWidgetItem*>(cppSelf)->::QTreeWidgetItem::clone() : const_cast<const ::QTreeWidgetItem*>(cppSelf)->clone();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemFunc_columnCount(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // columnCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->columnCount();
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

static PyObject* Sbk_QTreeWidgetItemFunc_data(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "data", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: data(int,int)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // data(int,int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_data_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // data(int,int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTreeWidgetItem*>(cppSelf)->::QTreeWidgetItem::data(cppArg0, cppArg1) : const_cast<const ::QTreeWidgetItem*>(cppSelf)->data(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_data_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.data", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_emitDataChanged(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));

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

static PyObject* Sbk_QTreeWidgetItemFunc_flags(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // flags()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFlags<Qt::ItemFlag> cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->flags();
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

static PyObject* Sbk_QTreeWidgetItemFunc_font(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: font(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // font(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_font_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // font(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->font(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_font_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.font", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_foreground(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: foreground(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // foreground(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_foreground_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // foreground(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QBrush cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->foreground(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_foreground_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.foreground", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_icon(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: icon(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // icon(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_icon_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // icon(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->icon(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_icon_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.icon", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_indexOfChild(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: indexOfChild(QTreeWidgetItem*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArg)))) {
        overloadId = 0; // indexOfChild(QTreeWidgetItem*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_indexOfChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTreeWidgetItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // indexOfChild(QTreeWidgetItem*)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->indexOfChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_indexOfChild_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidgetItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.indexOfChild", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_insertChild(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertChild", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertChild(int,QTreeWidgetItem*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertChild(int,QTreeWidgetItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_insertChild_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QTreeWidgetItem* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertChild(int,QTreeWidgetItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertChild(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_insertChild_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QTreeWidgetItem", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.insertChild", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_insertChildren(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertChildren", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertChildren(int,QList<QTreeWidgetItem*>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertChildren(int,QList<QTreeWidgetItem*>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_insertChildren_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QList<QTreeWidgetItem * > cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertChildren(int,QList<QTreeWidgetItem*>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->insertChildren(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArgs[1]);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_insertChildren_TypeError:
        const char* overloads[] = {"int, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.insertChildren", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_isDisabled(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isDisabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->isDisabled();
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

static PyObject* Sbk_QTreeWidgetItemFunc_isExpanded(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isExpanded()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->isExpanded();
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

static PyObject* Sbk_QTreeWidgetItemFunc_isFirstColumnSpanned(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isFirstColumnSpanned()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->isFirstColumnSpanned();
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

static PyObject* Sbk_QTreeWidgetItemFunc_isHidden(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isHidden()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->isHidden();
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

static PyObject* Sbk_QTreeWidgetItemFunc_isSelected(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSelected()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->isSelected();
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

static PyObject* Sbk_QTreeWidgetItemFunc_parent(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parent()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidgetItem * cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->parent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppResult);

            // Begin code injection

            // Only call the parent function if this return some value
            // the parent can be the TreeWidget
            if (cppResult)
              Shiboken::Object::setParent(pyResult, self);

            // End of code injection

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemFunc_read(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: read(QDataStream&)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // read(QDataStream&)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_read_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // read(QDataStream&)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTreeWidgetItem::read(*cppArg0) : cppSelf->read(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_read_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.read", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_removeChild(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeChild(QTreeWidgetItem*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArg)))) {
        overloadId = 0; // removeChild(QTreeWidgetItem*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_removeChild_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTreeWidgetItem* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeChild(QTreeWidgetItem*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->removeChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(Py_None, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_removeChild_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidgetItem", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.removeChild", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setBackground(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setBackground", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setBackground(int,QBrush)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
        overloadId = 0; // setBackground(int,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setBackground_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QBrush cppArg1_local = ::QBrush();
        ::QBrush* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setBackground(int,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBackground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setBackground_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setBackground", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setCheckState(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCheckState", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCheckState(int,Qt::CheckState)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CHECKSTATE_IDX]), (pyArgs[1])))) {
        overloadId = 0; // setCheckState(int,Qt::CheckState)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setCheckState_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::CheckState cppArg1 = ((::Qt::CheckState)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setCheckState(int,Qt::CheckState)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCheckState(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setCheckState_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.CheckState", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setCheckState", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setChildIndicatorPolicy(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setChildIndicatorPolicy(QTreeWidgetItem::ChildIndicatorPolicy)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX]), (pyArg)))) {
        overloadId = 0; // setChildIndicatorPolicy(QTreeWidgetItem::ChildIndicatorPolicy)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setChildIndicatorPolicy_TypeError;

    // Call function/method
    {
        ::QTreeWidgetItem::ChildIndicatorPolicy cppArg0 = ((::QTreeWidgetItem::ChildIndicatorPolicy)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChildIndicatorPolicy(QTreeWidgetItem::ChildIndicatorPolicy)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setChildIndicatorPolicy(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setChildIndicatorPolicy_TypeError:
        const char* overloads[] = {"PySide.QtGui.QTreeWidgetItem.ChildIndicatorPolicy", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setChildIndicatorPolicy", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setData(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setData", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setData(int,int,QVariant)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[2])))) {
        overloadId = 0; // setData(int,int,QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setData_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QVariant cppArg2 = ::QVariant();
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setData(int,int,QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTreeWidgetItem::setData(cppArg0, cppArg1, cppArg2) : cppSelf->setData(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setData_TypeError:
        const char* overloads[] = {"int, int, QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setData", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setDisabled(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDisabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDisabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setDisabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDisabled(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDisabled(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setDisabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setDisabled", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setExpanded(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setExpanded(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setExpanded(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setExpanded_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setExpanded(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setExpanded(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setExpanded_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setExpanded", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setFirstColumnSpanned(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFirstColumnSpanned(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setFirstColumnSpanned(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setFirstColumnSpanned_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFirstColumnSpanned(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFirstColumnSpanned(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setFirstColumnSpanned_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setFirstColumnSpanned", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setFlags(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFlags(QFlags<Qt::ItemFlag>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QFLAGS_QT_ITEMFLAG__IDX]), (pyArg)))) {
        overloadId = 0; // setFlags(QFlags<Qt::ItemFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setFlags_TypeError;

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

    Sbk_QTreeWidgetItemFunc_setFlags_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ItemFlags", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setFlags", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setFont(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFont", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFont(int,QFont)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArgs[1])))) {
        overloadId = 0; // setFont(int,QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setFont_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QFont cppArg1_local = ::QFont();
        ::QFont* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setFont(int,QFont)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFont(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setFont_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setForeground(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setForeground", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setForeground(int,QBrush)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], (pyArgs[1])))) {
        overloadId = 0; // setForeground(int,QBrush)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setForeground_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QBrush cppArg1_local = ::QBrush();
        ::QBrush* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QBRUSH_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setForeground(int,QBrush)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setForeground(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setForeground_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QBrush", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setForeground", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setHidden(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setHidden(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setHidden(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setHidden_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHidden(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setHidden(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setHidden_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setHidden", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setIcon(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setIcon", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setIcon(int,QIcon)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[1])))) {
        overloadId = 0; // setIcon(int,QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setIcon_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QIcon cppArg1_local = ::QIcon();
        ::QIcon* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setIcon(int,QIcon)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIcon(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setIcon_TypeError:
        const char* overloads[] = {"int, PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setSelected(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSelected(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSelected(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setSelected_TypeError;

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

    Sbk_QTreeWidgetItemFunc_setSelected_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.setSelected", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setSizeHint(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSizeHint", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setSizeHint(int,QSize)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setSizeHint(int,QSize)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setSizeHint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QSize cppArg1_local = ::QSize();
        ::QSize* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setSizeHint(int,QSize)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSizeHint(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setSizeHint_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QSize", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setSizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setStatusTip(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setStatusTip", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setStatusTip(int,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setStatusTip(int,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setStatusTip_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setStatusTip(int,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStatusTip(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setStatusTip_TypeError:
        const char* overloads[] = {"int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setStatusTip", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setText(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setText", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setText(int,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setText(int,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setText_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setText(int,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setText(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setText_TypeError:
        const char* overloads[] = {"int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setText", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setTextAlignment(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setTextAlignment", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setTextAlignment(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setTextAlignment(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setTextAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setTextAlignment(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTextAlignment(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setTextAlignment_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setTextAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setToolTip(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setToolTip", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setToolTip(int,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setToolTip(int,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setToolTip_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setToolTip(int,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setToolTip(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setToolTip_TypeError:
        const char* overloads[] = {"int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_setWhatsThis(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setWhatsThis", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setWhatsThis(int,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // setWhatsThis(int,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_setWhatsThis_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setWhatsThis(int,QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWhatsThis(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_setWhatsThis_TypeError:
        const char* overloads[] = {"int, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.setWhatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_sizeHint(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: sizeHint(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // sizeHint(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_sizeHint_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // sizeHint(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QSize cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->sizeHint(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QSIZE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_sizeHint_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.sizeHint", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_sortChildren(PyObject* self, PyObject* args)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "sortChildren", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: sortChildren(int,Qt::SortOrder)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SORTORDER_IDX]), (pyArgs[1])))) {
        overloadId = 0; // sortChildren(int,Qt::SortOrder)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_sortChildren_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::Qt::SortOrder cppArg1 = ((::Qt::SortOrder)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

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

    Sbk_QTreeWidgetItemFunc_sortChildren_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.Qt.SortOrder", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QTreeWidgetItem.sortChildren", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_statusTip(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: statusTip(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // statusTip(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_statusTip_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // statusTip(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->statusTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_statusTip_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.statusTip", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_takeChild(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: takeChild(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // takeChild(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_takeChild_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // takeChild(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidgetItem * cppResult = cppSelf->takeChild(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_takeChild_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.takeChild", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_takeChildren(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // takeChildren()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QTreeWidgetItem * > cppResult = cppSelf->takeChildren();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QTREEWIDGETITEMPTR_IDX], &cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemFunc_text(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: text(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // text(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_text_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // text(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->text(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_text_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.text", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_textAlignment(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: textAlignment(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // textAlignment(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_textAlignment_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // textAlignment(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->textAlignment(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_textAlignment_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.textAlignment", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_toolTip(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toolTip(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // toolTip(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_toolTip_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toolTip(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->toolTip(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_toolTip_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.toolTip", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_treeWidget(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // treeWidget()const

            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTreeWidget * cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->treeWidget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGET_IDX], cppResult);

            // Begin code injection

            // Only call the parent function if this return some value
            // the parent can be the TreeWidgetItem
            if (cppResult)
              Shiboken::Object::setParent(pyResult, self);

            // End of code injection

            // Ownership transferences.
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTreeWidgetItemFunc_type(PyObject* self)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // type()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->type();
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

static PyObject* Sbk_QTreeWidgetItemFunc_whatsThis(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: whatsThis(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // whatsThis(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_whatsThis_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // whatsThis(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QTreeWidgetItem*>(cppSelf)->whatsThis(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTreeWidgetItemFunc_whatsThis_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.whatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc_write(PyObject* self, PyObject* pyArg)
{
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: write(QDataStream&)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // write(QDataStream&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc_write_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // write(QDataStream&)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTreeWidgetItem*>(cppSelf)->::QTreeWidgetItem::write(*cppArg0) : const_cast<const ::QTreeWidgetItem*>(cppSelf)->write(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTreeWidgetItemFunc_write_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.write", overloads);
        return 0;
}

static PyMethodDef Sbk_QTreeWidgetItem_methods[] = {
    {"addChild", (PyCFunction)Sbk_QTreeWidgetItemFunc_addChild, METH_O},
    {"addChildren", (PyCFunction)Sbk_QTreeWidgetItemFunc_addChildren, METH_O},
    {"background", (PyCFunction)Sbk_QTreeWidgetItemFunc_background, METH_O},
    {"checkState", (PyCFunction)Sbk_QTreeWidgetItemFunc_checkState, METH_O},
    {"child", (PyCFunction)Sbk_QTreeWidgetItemFunc_child, METH_O},
    {"childCount", (PyCFunction)Sbk_QTreeWidgetItemFunc_childCount, METH_NOARGS},
    {"childIndicatorPolicy", (PyCFunction)Sbk_QTreeWidgetItemFunc_childIndicatorPolicy, METH_NOARGS},
    {"clone", (PyCFunction)Sbk_QTreeWidgetItemFunc_clone, METH_NOARGS},
    {"columnCount", (PyCFunction)Sbk_QTreeWidgetItemFunc_columnCount, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QTreeWidgetItemFunc_data, METH_VARARGS},
    {"emitDataChanged", (PyCFunction)Sbk_QTreeWidgetItemFunc_emitDataChanged, METH_NOARGS},
    {"flags", (PyCFunction)Sbk_QTreeWidgetItemFunc_flags, METH_NOARGS},
    {"font", (PyCFunction)Sbk_QTreeWidgetItemFunc_font, METH_O},
    {"foreground", (PyCFunction)Sbk_QTreeWidgetItemFunc_foreground, METH_O},
    {"icon", (PyCFunction)Sbk_QTreeWidgetItemFunc_icon, METH_O},
    {"indexOfChild", (PyCFunction)Sbk_QTreeWidgetItemFunc_indexOfChild, METH_O},
    {"insertChild", (PyCFunction)Sbk_QTreeWidgetItemFunc_insertChild, METH_VARARGS},
    {"insertChildren", (PyCFunction)Sbk_QTreeWidgetItemFunc_insertChildren, METH_VARARGS},
    {"isDisabled", (PyCFunction)Sbk_QTreeWidgetItemFunc_isDisabled, METH_NOARGS},
    {"isExpanded", (PyCFunction)Sbk_QTreeWidgetItemFunc_isExpanded, METH_NOARGS},
    {"isFirstColumnSpanned", (PyCFunction)Sbk_QTreeWidgetItemFunc_isFirstColumnSpanned, METH_NOARGS},
    {"isHidden", (PyCFunction)Sbk_QTreeWidgetItemFunc_isHidden, METH_NOARGS},
    {"isSelected", (PyCFunction)Sbk_QTreeWidgetItemFunc_isSelected, METH_NOARGS},
    {"parent", (PyCFunction)Sbk_QTreeWidgetItemFunc_parent, METH_NOARGS},
    {"read", (PyCFunction)Sbk_QTreeWidgetItemFunc_read, METH_O},
    {"removeChild", (PyCFunction)Sbk_QTreeWidgetItemFunc_removeChild, METH_O},
    {"setBackground", (PyCFunction)Sbk_QTreeWidgetItemFunc_setBackground, METH_VARARGS},
    {"setCheckState", (PyCFunction)Sbk_QTreeWidgetItemFunc_setCheckState, METH_VARARGS},
    {"setChildIndicatorPolicy", (PyCFunction)Sbk_QTreeWidgetItemFunc_setChildIndicatorPolicy, METH_O},
    {"setData", (PyCFunction)Sbk_QTreeWidgetItemFunc_setData, METH_VARARGS},
    {"setDisabled", (PyCFunction)Sbk_QTreeWidgetItemFunc_setDisabled, METH_O},
    {"setExpanded", (PyCFunction)Sbk_QTreeWidgetItemFunc_setExpanded, METH_O},
    {"setFirstColumnSpanned", (PyCFunction)Sbk_QTreeWidgetItemFunc_setFirstColumnSpanned, METH_O},
    {"setFlags", (PyCFunction)Sbk_QTreeWidgetItemFunc_setFlags, METH_O},
    {"setFont", (PyCFunction)Sbk_QTreeWidgetItemFunc_setFont, METH_VARARGS},
    {"setForeground", (PyCFunction)Sbk_QTreeWidgetItemFunc_setForeground, METH_VARARGS},
    {"setHidden", (PyCFunction)Sbk_QTreeWidgetItemFunc_setHidden, METH_O},
    {"setIcon", (PyCFunction)Sbk_QTreeWidgetItemFunc_setIcon, METH_VARARGS},
    {"setSelected", (PyCFunction)Sbk_QTreeWidgetItemFunc_setSelected, METH_O},
    {"setSizeHint", (PyCFunction)Sbk_QTreeWidgetItemFunc_setSizeHint, METH_VARARGS},
    {"setStatusTip", (PyCFunction)Sbk_QTreeWidgetItemFunc_setStatusTip, METH_VARARGS},
    {"setText", (PyCFunction)Sbk_QTreeWidgetItemFunc_setText, METH_VARARGS},
    {"setTextAlignment", (PyCFunction)Sbk_QTreeWidgetItemFunc_setTextAlignment, METH_VARARGS},
    {"setToolTip", (PyCFunction)Sbk_QTreeWidgetItemFunc_setToolTip, METH_VARARGS},
    {"setWhatsThis", (PyCFunction)Sbk_QTreeWidgetItemFunc_setWhatsThis, METH_VARARGS},
    {"sizeHint", (PyCFunction)Sbk_QTreeWidgetItemFunc_sizeHint, METH_O},
    {"sortChildren", (PyCFunction)Sbk_QTreeWidgetItemFunc_sortChildren, METH_VARARGS},
    {"statusTip", (PyCFunction)Sbk_QTreeWidgetItemFunc_statusTip, METH_O},
    {"takeChild", (PyCFunction)Sbk_QTreeWidgetItemFunc_takeChild, METH_O},
    {"takeChildren", (PyCFunction)Sbk_QTreeWidgetItemFunc_takeChildren, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QTreeWidgetItemFunc_text, METH_O},
    {"textAlignment", (PyCFunction)Sbk_QTreeWidgetItemFunc_textAlignment, METH_O},
    {"toolTip", (PyCFunction)Sbk_QTreeWidgetItemFunc_toolTip, METH_O},
    {"treeWidget", (PyCFunction)Sbk_QTreeWidgetItemFunc_treeWidget, METH_NOARGS},
    {"type", (PyCFunction)Sbk_QTreeWidgetItemFunc_type, METH_NOARGS},
    {"whatsThis", (PyCFunction)Sbk_QTreeWidgetItemFunc_whatsThis, METH_O},
    {"write", (PyCFunction)Sbk_QTreeWidgetItemFunc_write, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QTreeWidgetItemFunc___lshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
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
    // 0: operator<<(QDataStream&,QTreeWidgetItem)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator<<(QDataStream&,QTreeWidgetItem)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc___lshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator<<(QDataStream&,QTreeWidgetItem) [reverse operator]
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

    Sbk_QTreeWidgetItemFunc___lshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.__lshift__", overloads);
        return 0;
}

static PyObject* Sbk_QTreeWidgetItemFunc___rshift__(PyObject* self, PyObject* pyArg)
{
    bool isReverse = SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], pyArg)
                    && !SbkObject_TypeCheck(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], self);
    if (isReverse)
        std::swap(self, pyArg);
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
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
    // 0: operator>>(QDataStream&,QTreeWidgetItem&)
    if (isReverse
        && (pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATASTREAM_IDX], (pyArg)))) {
        overloadId = 0; // operator>>(QDataStream&,QTreeWidgetItem&)
    }

    if (isReverse && overloadId == -1) {
        PyErr_SetString(PyExc_NotImplementedError, "reverse operator not implemented.");
        return 0;
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTreeWidgetItemFunc___rshift___TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QDataStream* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // operator>>(QDataStream&,QTreeWidgetItem&) [reverse operator]
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

    Sbk_QTreeWidgetItemFunc___rshift___TypeError:
        const char* overloads[] = {"PySide.QtCore.QDataStream", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QTreeWidgetItem.__rshift__", overloads);
        return 0;
}

// Rich comparison
static PyObject* Sbk_QTreeWidgetItem_richcompare(PyObject* self, PyObject* pyArg, int op)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    ::QTreeWidgetItem& cppSelf = *(((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self)));
    SBK_UNUSED(cppSelf)
    PyObject* pyResult = 0;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    switch (op) {
        case Py_LT:
            if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (pyArg)))) {
                // operator<(const QTreeWidgetItem & other) const
                if (!Shiboken::Object::isValid(pyArg))
                    return 0;
                ::QTreeWidgetItem* cppArg0;
                pythonToCpp(pyArg, &cppArg0);
                bool cppResult = cppSelf < (*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            } else {
                goto Sbk_QTreeWidgetItem_RichComparison_TypeError;
            }

            break;
        default:
            goto Sbk_QTreeWidgetItem_RichComparison_TypeError;
    }

    if (pyResult && !PyErr_Occurred())
        return pyResult;
    Sbk_QTreeWidgetItem_RichComparison_TypeError:
    PyErr_SetString(PyExc_NotImplementedError, "operator not implemented.");
    return 0;

}

} // extern "C"

static Py_hash_t Sbk_QTreeWidgetItem_HashFunc(PyObject* self) {
    ::QTreeWidgetItem* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTreeWidgetItem*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX], (SbkObject*)self));
    return qHash(cppSelf);
}

static int Sbk_QTreeWidgetItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTreeWidgetItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static PyNumberMethods Sbk_QTreeWidgetItem_TypeAsNumber;

static SbkObjectType Sbk_QTreeWidgetItem_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QTreeWidgetItem",
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
    /*tp_hash*/             &Sbk_QTreeWidgetItem_HashFunc,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_QTreeWidgetItem_traverse,
    /*tp_clear*/            Sbk_QTreeWidgetItem_clear,
    /*tp_richcompare*/      Sbk_QTreeWidgetItem_richcompare,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTreeWidgetItem_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTreeWidgetItem_Init,
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
static void QTreeWidgetItem_ItemType_PythonToCpp_QTreeWidgetItem_ItemType(PyObject* pyIn, void* cppOut) {
    *((::QTreeWidgetItem::ItemType*)cppOut) = (::QTreeWidgetItem::ItemType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTreeWidgetItem_ItemType_PythonToCpp_QTreeWidgetItem_ItemType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX]))
        return QTreeWidgetItem_ItemType_PythonToCpp_QTreeWidgetItem_ItemType;
    return 0;
}
static PyObject* QTreeWidgetItem_ItemType_CppToPython_QTreeWidgetItem_ItemType(const void* cppIn) {
    int castCppIn = *((::QTreeWidgetItem::ItemType*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX], castCppIn);

}

static void QTreeWidgetItem_ChildIndicatorPolicy_PythonToCpp_QTreeWidgetItem_ChildIndicatorPolicy(PyObject* pyIn, void* cppOut) {
    *((::QTreeWidgetItem::ChildIndicatorPolicy*)cppOut) = (::QTreeWidgetItem::ChildIndicatorPolicy) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTreeWidgetItem_ChildIndicatorPolicy_PythonToCpp_QTreeWidgetItem_ChildIndicatorPolicy_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX]))
        return QTreeWidgetItem_ChildIndicatorPolicy_PythonToCpp_QTreeWidgetItem_ChildIndicatorPolicy;
    return 0;
}
static PyObject* QTreeWidgetItem_ChildIndicatorPolicy_CppToPython_QTreeWidgetItem_ChildIndicatorPolicy(const void* cppIn) {
    int castCppIn = *((::QTreeWidgetItem::ChildIndicatorPolicy*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTreeWidgetItem_PythonToCpp_QTreeWidgetItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTreeWidgetItem_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTreeWidgetItem_PythonToCpp_QTreeWidgetItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTreeWidgetItem_Type))
        return QTreeWidgetItem_PythonToCpp_QTreeWidgetItem_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTreeWidgetItem_PTR_CppToPython_QTreeWidgetItem(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::QTreeWidgetItem*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_QTreeWidgetItem_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_QTreeWidgetItem(PyObject* module)
{
    // type has number operators
    memset(&Sbk_QTreeWidgetItem_TypeAsNumber, 0, sizeof(PyNumberMethods));
    Sbk_QTreeWidgetItem_TypeAsNumber.nb_rshift = Sbk_QTreeWidgetItemFunc___rshift__;
    Sbk_QTreeWidgetItem_TypeAsNumber.nb_lshift = Sbk_QTreeWidgetItemFunc___lshift__;
    Sbk_QTreeWidgetItem_Type.super.ht_type.tp_as_number = &Sbk_QTreeWidgetItem_TypeAsNumber;

    SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTreeWidgetItem_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTreeWidgetItem", "QTreeWidgetItem*",
        &Sbk_QTreeWidgetItem_Type, &Shiboken::callCppDestructor< ::QTreeWidgetItem >)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTreeWidgetItem_Type,
        QTreeWidgetItem_PythonToCpp_QTreeWidgetItem_PTR,
        is_QTreeWidgetItem_PythonToCpp_QTreeWidgetItem_PTR_Convertible,
        QTreeWidgetItem_PTR_CppToPython_QTreeWidgetItem);

    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItem");
    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItem*");
    Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTreeWidgetItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTreeWidgetItemWrapper).name());


    // Initialization of enums.

    // Initialization of enum 'ItemType'.
    SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTreeWidgetItem_Type,
        "ItemType",
        "PySide.QtGui.QTreeWidgetItem.ItemType",
        "QTreeWidgetItem::ItemType");
    if (!SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX],
        &Sbk_QTreeWidgetItem_Type, "Type", (long) QTreeWidgetItem::Type))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX],
        &Sbk_QTreeWidgetItem_Type, "UserType", (long) QTreeWidgetItem::UserType))
        return ;
    // Register converter for enum 'QTreeWidgetItem::ItemType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX],
            QTreeWidgetItem_ItemType_CppToPython_QTreeWidgetItem_ItemType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTreeWidgetItem_ItemType_PythonToCpp_QTreeWidgetItem_ItemType,
            is_QTreeWidgetItem_ItemType_PythonToCpp_QTreeWidgetItem_ItemType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_ITEMTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItem::ItemType");
        Shiboken::Conversions::registerConverterName(converter, "ItemType");
    }
    // End of 'ItemType' enum.

    // Initialization of enum 'ChildIndicatorPolicy'.
    SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTreeWidgetItem_Type,
        "ChildIndicatorPolicy",
        "PySide.QtGui.QTreeWidgetItem.ChildIndicatorPolicy",
        "QTreeWidgetItem::ChildIndicatorPolicy");
    if (!SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX],
        &Sbk_QTreeWidgetItem_Type, "ShowIndicator", (long) QTreeWidgetItem::ShowIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX],
        &Sbk_QTreeWidgetItem_Type, "DontShowIndicator", (long) QTreeWidgetItem::DontShowIndicator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX],
        &Sbk_QTreeWidgetItem_Type, "DontShowIndicatorWhenChildless", (long) QTreeWidgetItem::DontShowIndicatorWhenChildless))
        return ;
    // Register converter for enum 'QTreeWidgetItem::ChildIndicatorPolicy'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX],
            QTreeWidgetItem_ChildIndicatorPolicy_CppToPython_QTreeWidgetItem_ChildIndicatorPolicy);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTreeWidgetItem_ChildIndicatorPolicy_PythonToCpp_QTreeWidgetItem_ChildIndicatorPolicy,
            is_QTreeWidgetItem_ChildIndicatorPolicy_PythonToCpp_QTreeWidgetItem_ChildIndicatorPolicy_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QTREEWIDGETITEM_CHILDINDICATORPOLICY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTreeWidgetItem::ChildIndicatorPolicy");
        Shiboken::Conversions::registerConverterName(converter, "ChildIndicatorPolicy");
    }
    // End of 'ChildIndicatorPolicy' enum.


    qRegisterMetaType< ::QTreeWidgetItem::ItemType >("QTreeWidgetItem::ItemType");
    qRegisterMetaType< ::QTreeWidgetItem::ChildIndicatorPolicy >("QTreeWidgetItem::ChildIndicatorPolicy");
}
