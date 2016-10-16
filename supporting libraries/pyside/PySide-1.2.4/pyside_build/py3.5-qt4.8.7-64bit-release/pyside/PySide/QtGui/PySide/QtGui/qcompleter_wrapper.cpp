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
#include <signalmanager.h>
#include <pysidemetafunction.h>
#include "pyside_qtgui_python.h"

#include "qcompleter_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractitemmodel.h>
#include <qabstractitemview.h>
#include <qbytearray.h>
#include <qcompleter.h>
#include <qcoreevent.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qrect.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QCompleterWrapper::QCompleterWrapper(QAbstractItemModel * model, QObject * parent) : QCompleter(model, parent) {
    // ... middle
}

QCompleterWrapper::QCompleterWrapper(QObject * parent) : QCompleter(parent) {
    // ... middle
}

QCompleterWrapper::QCompleterWrapper(const QStringList & completions, QObject * parent) : QCompleter(completions, parent) {
    // ... middle
}

void QCompleterWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QCHILDEVENT_IDX], arg__1)
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

void QCompleterWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QCompleterWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
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

void QCompleterWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

bool QCompleterWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCompleter::event(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__1)
    ));
    bool invalidateArg1 = PyTuple_GET_ITEM(pyArgs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCompleter.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QCompleterWrapper::eventFilter(QObject * o, QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCompleter::eventFilter(o, e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], o),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
    ));
    bool invalidateArg2 = PyTuple_GET_ITEM(pyArgs, 1)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((bool)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCompleter.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

QString QCompleterWrapper::pathFromIndex(const QModelIndex & index) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QString();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "pathFromIndex"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCompleter::pathFromIndex(index);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QString();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCompleter.pathFromIndex", "QString", pyResult->ob_type->tp_name);
        return ::QString();
    }
    ::QString cppResult = ::QString();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

QStringList QCompleterWrapper::splitPath(const QString & path) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ::QStringList();
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "splitPath"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QCompleter::splitPath(path);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &path)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ::QStringList();
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QCompleter.splitPath", "QStringList", pyResult->ob_type->tp_name);
        return ::QStringList();
    }
    ::QStringList cppResult = ::QStringList();
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void QCompleterWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], arg__1)
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

const QMetaObject* QCompleterWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QCompleter::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QCompleterWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QCompleter::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QCompleterWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QCompleterWrapper* >(this));
        return QCompleter::qt_metacast(_clname);
}

QCompleterWrapper::~QCompleterWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QCompleter_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QCompleter >()))
        return -1;

    ::QCompleterWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QCompleter", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QCompleter(QAbstractItemModel*,QObject*)
    // 1: QCompleter(QObject*)
    // 2: QCompleter(QStringList,QObject*)
    if (numArgs == 0) {
        overloadId = 1; // QCompleter(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // QCompleter(QStringList,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 2; // QCompleter(QStringList,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QCompleter(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QCompleter(QAbstractItemModel*,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // QCompleter(QAbstractItemModel*,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleter_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QCompleter(QAbstractItemModel * model, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCompleter(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QCompleter_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAbstractItemModel* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QCompleter(QAbstractItemModel*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QCompleterWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QCompleterWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
        case 1: // QCompleter(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCompleter(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QCompleter_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QCompleter(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QCompleterWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QCompleterWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QCompleter(const QStringList & completions, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCompleter(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QCompleter_Init_TypeError;
                }
            }
            ::QStringList cppArg0 = ::QStringList();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QCompleter(QStringList,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QCompleterWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QCompleterWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QCompleter >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QCompleter_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QCompleter_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractItemModel, PySide.QtCore.QObject = None", "PySide.QtCore.QObject = None", "QStringList, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCompleter", overloads);
        return -1;
}

static PyObject* Sbk_QCompleterFunc_caseSensitivity(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // caseSensitivity()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::CaseSensitivity cppResult = const_cast<const ::QCompleter*>(cppSelf)->caseSensitivity();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_complete(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCompleter.complete(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:complete", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: complete(QRect)
    if (numArgs == 0) {
        overloadId = 0; // complete(QRect)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // complete(QRect)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_complete_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "rect");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QCompleter.complete(): got multiple values for keyword argument 'rect'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], (pyArgs[0]))))
                    goto Sbk_QCompleterFunc_complete_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QRect cppArg0_local = QRect();
        ::QRect* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // complete(QRect)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->complete(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_complete_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRect = QRect()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCompleter.complete", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_completionColumn(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionColumn()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionColumn();
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

static PyObject* Sbk_QCompleterFunc_completionCount(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionCount();
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

static PyObject* Sbk_QCompleterFunc_completionMode(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionMode()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCompleter::CompletionMode cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionMode();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_completionModel(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionModel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemModel * cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionModel();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_completionPrefix(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionPrefix()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionPrefix();
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

static PyObject* Sbk_QCompleterFunc_completionRole(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // completionRole()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QCompleter*>(cppSelf)->completionRole();
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

static PyObject* Sbk_QCompleterFunc_currentCompletion(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentCompletion()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QCompleter*>(cppSelf)->currentCompletion();
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

static PyObject* Sbk_QCompleterFunc_currentIndex(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QCompleter*>(cppSelf)->currentIndex();
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

static PyObject* Sbk_QCompleterFunc_currentRow(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentRow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QCompleter*>(cppSelf)->currentRow();
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

static PyObject* Sbk_QCompleterFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: event(QEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArg)))) {
        overloadId = 0; // event(QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCompleter::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCompleterFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.event", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_eventFilter(PyObject* self, PyObject* args)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "eventFilter", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: eventFilter(QObject*,QEvent*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], (pyArgs[1])))) {
        overloadId = 0; // eventFilter(QObject*,QEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_eventFilter_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QEvent* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // eventFilter(QObject*,QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QCompleter::eventFilter(cppArg0, cppArg1) : cppSelf->eventFilter(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCompleterFunc_eventFilter_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QCompleter.eventFilter", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_maxVisibleItems(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // maxVisibleItems()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QCompleter*>(cppSelf)->maxVisibleItems();
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

static PyObject* Sbk_QCompleterFunc_model(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemModel * cppResult = const_cast<const ::QCompleter*>(cppSelf)->model();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_modelSorting(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // modelSorting()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QCompleter::ModelSorting cppResult = const_cast<const ::QCompleter*>(cppSelf)->modelSorting();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_pathFromIndex(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: pathFromIndex(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // pathFromIndex(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_pathFromIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // pathFromIndex(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCompleter*>(cppSelf)->::QCompleter::pathFromIndex(*cppArg0) : const_cast<const ::QCompleter*>(cppSelf)->pathFromIndex(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCompleterFunc_pathFromIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.pathFromIndex", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_popup(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // popup()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAbstractItemView * cppResult = const_cast<const ::QCompleter*>(cppSelf)->popup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_setCaseSensitivity(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCaseSensitivity(Qt::CaseSensitivity)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_CASESENSITIVITY_IDX]), (pyArg)))) {
        overloadId = 0; // setCaseSensitivity(Qt::CaseSensitivity)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCaseSensitivity_TypeError;

    // Call function/method
    {
        ::Qt::CaseSensitivity cppArg0 = ((::Qt::CaseSensitivity)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCaseSensitivity(Qt::CaseSensitivity)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCaseSensitivity(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setCaseSensitivity_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.CaseSensitivity", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCaseSensitivity", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setCompletionColumn(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompletionColumn(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCompletionColumn(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCompletionColumn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompletionColumn(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompletionColumn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setCompletionColumn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCompletionColumn", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setCompletionMode(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompletionMode(QCompleter::CompletionMode)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX]), (pyArg)))) {
        overloadId = 0; // setCompletionMode(QCompleter::CompletionMode)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCompletionMode_TypeError;

    // Call function/method
    {
        ::QCompleter::CompletionMode cppArg0 = ((::QCompleter::CompletionMode)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompletionMode(QCompleter::CompletionMode)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompletionMode(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setCompletionMode_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCompleter.CompletionMode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCompletionMode", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setCompletionPrefix(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompletionPrefix(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setCompletionPrefix(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCompletionPrefix_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompletionPrefix(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompletionPrefix(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setCompletionPrefix_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCompletionPrefix", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setCompletionRole(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCompletionRole(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCompletionRole(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCompletionRole_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompletionRole(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCompletionRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setCompletionRole_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCompletionRole", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setCurrentRow(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentRow(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentRow(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setCurrentRow_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentRow(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->setCurrentRow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCompleterFunc_setCurrentRow_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setCurrentRow", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setMaxVisibleItems(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMaxVisibleItems(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setMaxVisibleItems(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setMaxVisibleItems_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMaxVisibleItems(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMaxVisibleItems(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setMaxVisibleItems_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setMaxVisibleItems", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setModel(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModel(QAbstractItemModel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], (pyArg)))) {
        overloadId = 0; // setModel(QAbstractItemModel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setModel_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemModel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModel(QAbstractItemModel*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setModel(QAbstractItemModel*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setModel_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractItemModel", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setModel", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setModelSorting(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setModelSorting(QCompleter::ModelSorting)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX]), (pyArg)))) {
        overloadId = 0; // setModelSorting(QCompleter::ModelSorting)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setModelSorting_TypeError;

    // Call function/method
    {
        ::QCompleter::ModelSorting cppArg0 = ((::QCompleter::ModelSorting)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setModelSorting(QCompleter::ModelSorting)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setModelSorting(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setModelSorting_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCompleter.ModelSorting", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setModelSorting", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setPopup(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPopup(QAbstractItemView*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QABSTRACTITEMVIEW_IDX], (pyArg)))) {
        overloadId = 0; // setPopup(QAbstractItemView*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setPopup_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QAbstractItemView* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPopup(QAbstractItemView*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPopup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setPopup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAbstractItemView", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setPopup", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setWidget(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWidget(QWidget*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArg)))) {
        overloadId = 0; // setWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setWidget_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QWidget* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWidget(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWidget(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArg, self);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setWidget_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setWidget", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_setWrapAround(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWrapAround(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setWrapAround(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_setWrapAround_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setWrapAround(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setWrapAround(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QCompleterFunc_setWrapAround_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.setWrapAround", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_splitPath(PyObject* self, PyObject* pyArg)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: splitPath(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // splitPath(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QCompleterFunc_splitPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // splitPath(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QCompleter*>(cppSelf)->::QCompleter::splitPath(cppArg0) : const_cast<const ::QCompleter*>(cppSelf)->splitPath(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QCompleterFunc_splitPath_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QCompleter.splitPath", overloads);
        return 0;
}

static PyObject* Sbk_QCompleterFunc_widget(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // widget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QCompleter*>(cppSelf)->widget();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QCompleterFunc_wrapAround(PyObject* self)
{
    ::QCompleter* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QCompleter*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // wrapAround()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QCompleter*>(cppSelf)->wrapAround();
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

static PyMethodDef Sbk_QCompleter_methods[] = {
    {"caseSensitivity", (PyCFunction)Sbk_QCompleterFunc_caseSensitivity, METH_NOARGS},
    {"complete", (PyCFunction)Sbk_QCompleterFunc_complete, METH_VARARGS|METH_KEYWORDS},
    {"completionColumn", (PyCFunction)Sbk_QCompleterFunc_completionColumn, METH_NOARGS},
    {"completionCount", (PyCFunction)Sbk_QCompleterFunc_completionCount, METH_NOARGS},
    {"completionMode", (PyCFunction)Sbk_QCompleterFunc_completionMode, METH_NOARGS},
    {"completionModel", (PyCFunction)Sbk_QCompleterFunc_completionModel, METH_NOARGS},
    {"completionPrefix", (PyCFunction)Sbk_QCompleterFunc_completionPrefix, METH_NOARGS},
    {"completionRole", (PyCFunction)Sbk_QCompleterFunc_completionRole, METH_NOARGS},
    {"currentCompletion", (PyCFunction)Sbk_QCompleterFunc_currentCompletion, METH_NOARGS},
    {"currentIndex", (PyCFunction)Sbk_QCompleterFunc_currentIndex, METH_NOARGS},
    {"currentRow", (PyCFunction)Sbk_QCompleterFunc_currentRow, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QCompleterFunc_event, METH_O},
    {"eventFilter", (PyCFunction)Sbk_QCompleterFunc_eventFilter, METH_VARARGS},
    {"maxVisibleItems", (PyCFunction)Sbk_QCompleterFunc_maxVisibleItems, METH_NOARGS},
    {"model", (PyCFunction)Sbk_QCompleterFunc_model, METH_NOARGS},
    {"modelSorting", (PyCFunction)Sbk_QCompleterFunc_modelSorting, METH_NOARGS},
    {"pathFromIndex", (PyCFunction)Sbk_QCompleterFunc_pathFromIndex, METH_O},
    {"popup", (PyCFunction)Sbk_QCompleterFunc_popup, METH_NOARGS},
    {"setCaseSensitivity", (PyCFunction)Sbk_QCompleterFunc_setCaseSensitivity, METH_O},
    {"setCompletionColumn", (PyCFunction)Sbk_QCompleterFunc_setCompletionColumn, METH_O},
    {"setCompletionMode", (PyCFunction)Sbk_QCompleterFunc_setCompletionMode, METH_O},
    {"setCompletionPrefix", (PyCFunction)Sbk_QCompleterFunc_setCompletionPrefix, METH_O},
    {"setCompletionRole", (PyCFunction)Sbk_QCompleterFunc_setCompletionRole, METH_O},
    {"setCurrentRow", (PyCFunction)Sbk_QCompleterFunc_setCurrentRow, METH_O},
    {"setMaxVisibleItems", (PyCFunction)Sbk_QCompleterFunc_setMaxVisibleItems, METH_O},
    {"setModel", (PyCFunction)Sbk_QCompleterFunc_setModel, METH_O},
    {"setModelSorting", (PyCFunction)Sbk_QCompleterFunc_setModelSorting, METH_O},
    {"setPopup", (PyCFunction)Sbk_QCompleterFunc_setPopup, METH_O},
    {"setWidget", (PyCFunction)Sbk_QCompleterFunc_setWidget, METH_O},
    {"setWrapAround", (PyCFunction)Sbk_QCompleterFunc_setWrapAround, METH_O},
    {"splitPath", (PyCFunction)Sbk_QCompleterFunc_splitPath, METH_O},
    {"widget", (PyCFunction)Sbk_QCompleterFunc_widget, METH_NOARGS},
    {"wrapAround", (PyCFunction)Sbk_QCompleterFunc_wrapAround, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QCompleter_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QCompleter_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QCompleter_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QCompleter",
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
    /*tp_traverse*/         Sbk_QCompleter_traverse,
    /*tp_clear*/            Sbk_QCompleter_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QCompleter_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QCompleter_Init,
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

static void* Sbk_QCompleter_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QCompleter*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QCompleter_CompletionMode_PythonToCpp_QCompleter_CompletionMode(PyObject* pyIn, void* cppOut) {
    *((::QCompleter::CompletionMode*)cppOut) = (::QCompleter::CompletionMode) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QCompleter_CompletionMode_PythonToCpp_QCompleter_CompletionMode_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX]))
        return QCompleter_CompletionMode_PythonToCpp_QCompleter_CompletionMode;
    return 0;
}
static PyObject* QCompleter_CompletionMode_CppToPython_QCompleter_CompletionMode(const void* cppIn) {
    int castCppIn = *((::QCompleter::CompletionMode*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX], castCppIn);

}

static void QCompleter_ModelSorting_PythonToCpp_QCompleter_ModelSorting(PyObject* pyIn, void* cppOut) {
    *((::QCompleter::ModelSorting*)cppOut) = (::QCompleter::ModelSorting) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QCompleter_ModelSorting_PythonToCpp_QCompleter_ModelSorting_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX]))
        return QCompleter_ModelSorting_PythonToCpp_QCompleter_ModelSorting;
    return 0;
}
static PyObject* QCompleter_ModelSorting_CppToPython_QCompleter_ModelSorting(const void* cppIn) {
    int castCppIn = *((::QCompleter::ModelSorting*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QCompleter_PythonToCpp_QCompleter_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QCompleter_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QCompleter_PythonToCpp_QCompleter_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QCompleter_Type))
        return QCompleter_PythonToCpp_QCompleter_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QCompleter_PTR_CppToPython_QCompleter(const void* cppIn) {
    return PySide::getWrapperForQObject((::QCompleter*)cppIn, &Sbk_QCompleter_Type);

}

void init_QCompleter(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QCOMPLETER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QCompleter_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QCompleter", "QCompleter*",
        &Sbk_QCompleter_Type, &Shiboken::callCppDestructor< ::QCompleter >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QCompleter_Type,
        QCompleter_PythonToCpp_QCompleter_PTR,
        is_QCompleter_PythonToCpp_QCompleter_PTR_Convertible,
        QCompleter_PTR_CppToPython_QCompleter);

    Shiboken::Conversions::registerConverterName(converter, "QCompleter");
    Shiboken::Conversions::registerConverterName(converter, "QCompleter*");
    Shiboken::Conversions::registerConverterName(converter, "QCompleter&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCompleter).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QCompleterWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QCompleter_Type, &Sbk_QCompleter_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'CompletionMode'.
    SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QCompleter_Type,
        "CompletionMode",
        "PySide.QtGui.QCompleter.CompletionMode",
        "QCompleter::CompletionMode");
    if (!SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX],
        &Sbk_QCompleter_Type, "PopupCompletion", (long) QCompleter::PopupCompletion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX],
        &Sbk_QCompleter_Type, "UnfilteredPopupCompletion", (long) QCompleter::UnfilteredPopupCompletion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX],
        &Sbk_QCompleter_Type, "InlineCompletion", (long) QCompleter::InlineCompletion))
        return ;
    // Register converter for enum 'QCompleter::CompletionMode'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX],
            QCompleter_CompletionMode_CppToPython_QCompleter_CompletionMode);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QCompleter_CompletionMode_PythonToCpp_QCompleter_CompletionMode,
            is_QCompleter_CompletionMode_PythonToCpp_QCompleter_CompletionMode_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_COMPLETIONMODE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QCompleter::CompletionMode");
        Shiboken::Conversions::registerConverterName(converter, "CompletionMode");
    }
    // End of 'CompletionMode' enum.

    // Initialization of enum 'ModelSorting'.
    SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QCompleter_Type,
        "ModelSorting",
        "PySide.QtGui.QCompleter.ModelSorting",
        "QCompleter::ModelSorting");
    if (!SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX],
        &Sbk_QCompleter_Type, "UnsortedModel", (long) QCompleter::UnsortedModel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX],
        &Sbk_QCompleter_Type, "CaseSensitivelySortedModel", (long) QCompleter::CaseSensitivelySortedModel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX],
        &Sbk_QCompleter_Type, "CaseInsensitivelySortedModel", (long) QCompleter::CaseInsensitivelySortedModel))
        return ;
    // Register converter for enum 'QCompleter::ModelSorting'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX],
            QCompleter_ModelSorting_CppToPython_QCompleter_ModelSorting);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QCompleter_ModelSorting_PythonToCpp_QCompleter_ModelSorting,
            is_QCompleter_ModelSorting_PythonToCpp_QCompleter_ModelSorting_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QCOMPLETER_MODELSORTING_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QCompleter::ModelSorting");
        Shiboken::Conversions::registerConverterName(converter, "ModelSorting");
    }
    // End of 'ModelSorting' enum.

    PySide::Signal::registerSignals(&Sbk_QCompleter_Type, &::QCompleter::staticMetaObject);

    qRegisterMetaType< ::QCompleter::CompletionMode >("QCompleter::CompletionMode");
    qRegisterMetaType< ::QCompleter::ModelSorting >("QCompleter::ModelSorting");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QCompleter_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QCompleter_Type, &::QCompleter::staticMetaObject, sizeof(::QCompleter));
}
