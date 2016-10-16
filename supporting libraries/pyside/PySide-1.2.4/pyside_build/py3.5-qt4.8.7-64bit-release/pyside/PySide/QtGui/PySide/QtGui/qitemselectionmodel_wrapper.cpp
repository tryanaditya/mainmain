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

#include "qitemselectionmodel_wrapper.h"

// Extra includes
#include <QList>
#include <qabstractitemmodel.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qitemselectionmodel.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QItemSelectionModelWrapper::QItemSelectionModelWrapper(QAbstractItemModel * model) : QItemSelectionModel(model) {
    // ... middle
}

QItemSelectionModelWrapper::QItemSelectionModelWrapper(QAbstractItemModel * model, QObject * parent) : QItemSelectionModel(model, parent) {
    // ... middle
}

void QItemSelectionModelWrapper::childEvent(QChildEvent * arg__1)
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

void QItemSelectionModelWrapper::clear()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "clear"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemSelectionModel::clear();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QItemSelectionModelWrapper::connectNotify(const char * signal)
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

void QItemSelectionModelWrapper::customEvent(QEvent * arg__1)
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

void QItemSelectionModelWrapper::disconnectNotify(const char * signal)
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

bool QItemSelectionModelWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemSelectionModel.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QItemSelectionModelWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], arg__1),
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QItemSelectionModel.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QItemSelectionModelWrapper::reset()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "reset"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemSelectionModel::reset();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QItemSelectionModelWrapper::select(const QItemSelection & selection, QFlags<QItemSelectionModel::SelectionFlag> command)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "select"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemSelectionModel::select(selection, command);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &selection),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &command)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QItemSelectionModelWrapper::select(const QModelIndex & index, QFlags<QItemSelectionModel::SelectionFlag> command)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "select"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QItemSelectionModel::select(index, command);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], &index),
        Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &command)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QItemSelectionModelWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QItemSelectionModelWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QItemSelectionModel::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QItemSelectionModelWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QItemSelectionModel::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QItemSelectionModelWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QItemSelectionModelWrapper* >(this));
        return QItemSelectionModel::qt_metacast(_clname);
}

QItemSelectionModelWrapper::~QItemSelectionModelWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QItemSelectionModel_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QItemSelectionModel >()))
        return -1;

    ::QItemSelectionModelWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QItemSelectionModel", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QItemSelectionModel(QAbstractItemModel*)
    // 1: QItemSelectionModel(QAbstractItemModel*,QObject*)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QABSTRACTITEMMODEL_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QItemSelectionModel(QAbstractItemModel*)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QItemSelectionModel(QAbstractItemModel*,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModel_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QItemSelectionModel(QAbstractItemModel * model)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAbstractItemModel* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QItemSelectionModel(QAbstractItemModel*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QItemSelectionModelWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QItemSelectionModelWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QItemSelectionModel(QAbstractItemModel * model, QObject * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QAbstractItemModel* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QItemSelectionModel(QAbstractItemModel*,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QItemSelectionModelWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QItemSelectionModelWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QItemSelectionModel >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QItemSelectionModel_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QItemSelectionModel_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QAbstractItemModel", "PySide.QtCore.QAbstractItemModel, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel", overloads);
        return -1;
}

static PyObject* Sbk_QItemSelectionModelFunc_clear(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QItemSelectionModel::clear() : cppSelf->clear();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionModelFunc_clearSelection(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearSelection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearSelection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionModelFunc_columnIntersectsSelection(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "columnIntersectsSelection", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: columnIntersectsSelection(int,QModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // columnIntersectsSelection(int,QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_columnIntersectsSelection_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // columnIntersectsSelection(int,QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->columnIntersectsSelection(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_columnIntersectsSelection_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.columnIntersectsSelection", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_currentIndex(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentIndex()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndex cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->currentIndex();
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

static PyObject* Sbk_QItemSelectionModelFunc_emitSelectionChanged(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "emitSelectionChanged", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: emitSelectionChanged(QItemSelection,QItemSelection)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[1])))) {
        overloadId = 0; // emitSelectionChanged(QItemSelection,QItemSelection)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_emitSelectionChanged_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QItemSelection cppArg0_local = ::QItemSelection();
        ::QItemSelection* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QItemSelection cppArg1_local = ::QItemSelection();
        ::QItemSelection* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // emitSelectionChanged(QItemSelection,QItemSelection)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->emitSelectionChanged(*cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionModelFunc_emitSelectionChanged_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelection, PySide.QtGui.QItemSelection", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.emitSelectionChanged", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_hasSelection(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasSelection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->hasSelection();
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

static PyObject* Sbk_QItemSelectionModelFunc_isColumnSelected(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isColumnSelected", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isColumnSelected(int,QModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // isColumnSelected(int,QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_isColumnSelected_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // isColumnSelected(int,QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->isColumnSelected(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_isColumnSelected_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.isColumnSelected", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_isRowSelected(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "isRowSelected", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: isRowSelected(int,QModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // isRowSelected(int,QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_isRowSelected_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // isRowSelected(int,QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->isRowSelected(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_isRowSelected_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.isRowSelected", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_isSelected(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isSelected(QModelIndex)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArg)))) {
        overloadId = 0; // isSelected(QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_isSelected_TypeError;

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
            // isSelected(QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->isSelected(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_isSelected_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QItemSelectionModel.isSelected", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_model(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // model()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QAbstractItemModel * cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->model();
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

static PyObject* Sbk_QItemSelectionModelFunc_reset(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reset()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QItemSelectionModel::reset() : cppSelf->reset();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QItemSelectionModelFunc_rowIntersectsSelection(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "rowIntersectsSelection", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: rowIntersectsSelection(int,QModelIndex)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[1])))) {
        overloadId = 0; // rowIntersectsSelection(int,QModelIndex)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_rowIntersectsSelection_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QModelIndex cppArg1_local = ::QModelIndex();
        ::QModelIndex* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // rowIntersectsSelection(int,QModelIndex)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->rowIntersectsSelection(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_rowIntersectsSelection_TypeError:
        const char* overloads[] = {"int, PySide.QtCore.QModelIndex", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.rowIntersectsSelection", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_select(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "select", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: select(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
    // 1: select(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 1; // select(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // select(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_select_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // select(const QItemSelection & selection, QFlags<QItemSelectionModel::SelectionFlag> command)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QItemSelection cppArg0_local = ::QItemSelection();
            ::QItemSelection* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QFlags<QItemSelectionModel::SelectionFlag> cppArg1 = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // select(QItemSelection,QFlags<QItemSelectionModel::SelectionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QItemSelectionModel::select(*cppArg0, cppArg1) : cppSelf->select(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // select(const QModelIndex & index, QFlags<QItemSelectionModel::SelectionFlag> command)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QModelIndex cppArg0_local = ::QModelIndex();
            ::QModelIndex* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QFlags<QItemSelectionModel::SelectionFlag> cppArg1 = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // select(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QItemSelectionModel::select(*cppArg0, cppArg1) : cppSelf->select(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionModelFunc_select_TypeError:
        const char* overloads[] = {"PySide.QtGui.QItemSelection, PySide.QtGui.QItemSelectionModel.SelectionFlags", "PySide.QtCore.QModelIndex, PySide.QtGui.QItemSelectionModel.SelectionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.select", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_selectedColumns(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelectionModel.selectedColumns(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:selectedColumns", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: selectedColumns(int)const
    if (numArgs == 0) {
        overloadId = 0; // selectedColumns(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // selectedColumns(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_selectedColumns_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "row");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelectionModel.selectedColumns(): got multiple values for keyword argument 'row'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QItemSelectionModelFunc_selectedColumns_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // selectedColumns(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->selectedColumns(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_selectedColumns_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.selectedColumns", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_selectedIndexes(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selectedIndexes()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->selectedIndexes();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionModelFunc_selectedRows(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelectionModel.selectedRows(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:selectedRows", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: selectedRows(int)const
    if (numArgs == 0) {
        overloadId = 0; // selectedRows(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // selectedRows(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_selectedRows_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "column");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QItemSelectionModel.selectedRows(): got multiple values for keyword argument 'column'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QItemSelectionModelFunc_selectedRows_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // selectedRows(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QModelIndexList cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->selectedRows(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QMODELINDEXLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QItemSelectionModelFunc_selectedRows_TypeError:
        const char* overloads[] = {"int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.selectedRows", overloads);
        return 0;
}

static PyObject* Sbk_QItemSelectionModelFunc_selection(PyObject* self)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // selection()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            const QItemSelection cppResult = const_cast<const ::QItemSelectionModel*>(cppSelf)->selection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QITEMSELECTION_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QItemSelectionModelFunc_setCurrentIndex(PyObject* self, PyObject* args)
{
    ::QItemSelectionModel* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QItemSelectionModel*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setCurrentIndex", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setCurrentIndex(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), (pyArgs[1])))) {
        overloadId = 0; // setCurrentIndex(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QItemSelectionModelFunc_setCurrentIndex_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QModelIndex cppArg0_local = ::QModelIndex();
        ::QModelIndex* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMODELINDEX_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);

        ::QFlags<QItemSelectionModel::SelectionFlag> cppArg1 = ((::QFlags<QItemSelectionModel::SelectionFlag>)0);
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setCurrentIndex(QModelIndex,QFlags<QItemSelectionModel::SelectionFlag>)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentIndex(*cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QItemSelectionModelFunc_setCurrentIndex_TypeError:
        const char* overloads[] = {"PySide.QtCore.QModelIndex, PySide.QtGui.QItemSelectionModel.SelectionFlags", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QItemSelectionModel.setCurrentIndex", overloads);
        return 0;
}

static PyMethodDef Sbk_QItemSelectionModel_methods[] = {
    {"clear", (PyCFunction)Sbk_QItemSelectionModelFunc_clear, METH_NOARGS},
    {"clearSelection", (PyCFunction)Sbk_QItemSelectionModelFunc_clearSelection, METH_NOARGS},
    {"columnIntersectsSelection", (PyCFunction)Sbk_QItemSelectionModelFunc_columnIntersectsSelection, METH_VARARGS},
    {"currentIndex", (PyCFunction)Sbk_QItemSelectionModelFunc_currentIndex, METH_NOARGS},
    {"emitSelectionChanged", (PyCFunction)Sbk_QItemSelectionModelFunc_emitSelectionChanged, METH_VARARGS},
    {"hasSelection", (PyCFunction)Sbk_QItemSelectionModelFunc_hasSelection, METH_NOARGS},
    {"isColumnSelected", (PyCFunction)Sbk_QItemSelectionModelFunc_isColumnSelected, METH_VARARGS},
    {"isRowSelected", (PyCFunction)Sbk_QItemSelectionModelFunc_isRowSelected, METH_VARARGS},
    {"isSelected", (PyCFunction)Sbk_QItemSelectionModelFunc_isSelected, METH_O},
    {"model", (PyCFunction)Sbk_QItemSelectionModelFunc_model, METH_NOARGS},
    {"reset", (PyCFunction)Sbk_QItemSelectionModelFunc_reset, METH_NOARGS},
    {"rowIntersectsSelection", (PyCFunction)Sbk_QItemSelectionModelFunc_rowIntersectsSelection, METH_VARARGS},
    {"select", (PyCFunction)Sbk_QItemSelectionModelFunc_select, METH_VARARGS},
    {"selectedColumns", (PyCFunction)Sbk_QItemSelectionModelFunc_selectedColumns, METH_VARARGS|METH_KEYWORDS},
    {"selectedIndexes", (PyCFunction)Sbk_QItemSelectionModelFunc_selectedIndexes, METH_NOARGS},
    {"selectedRows", (PyCFunction)Sbk_QItemSelectionModelFunc_selectedRows, METH_VARARGS|METH_KEYWORDS},
    {"selection", (PyCFunction)Sbk_QItemSelectionModelFunc_selection, METH_NOARGS},
    {"setCurrentIndex", (PyCFunction)Sbk_QItemSelectionModelFunc_setCurrentIndex, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QItemSelectionModel_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QItemSelectionModel_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QItemSelectionModel_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QItemSelectionModel",
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
    /*tp_traverse*/         Sbk_QItemSelectionModel_traverse,
    /*tp_clear*/            Sbk_QItemSelectionModel_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QItemSelectionModel_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QItemSelectionModel_Init,
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

static void* Sbk_QItemSelectionModel_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QItemSelectionModel*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___and__(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionModel::SelectionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyLong_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyInt_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___or__(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionModel::SelectionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyLong_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyInt_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___xor__(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionModel::SelectionFlags cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyLong_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QItemSelectionModel::SelectionFlags)PyInt_AsLong(self);
    cppArg = (QItemSelectionModel::SelectionFlags)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &cppResult);
}

PyObject* SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___invert__(PyObject* self, PyObject* pyArg)
{
    ::QItemSelectionModel::SelectionFlags cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), self, &cppSelf);
    ::QItemSelectionModel::SelectionFlags cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtGui_QItemSelectionModel_SelectionFlag_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtGui_QItemSelectionModel_SelectionFlag__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtGui_QItemSelectionModel_SelectionFlag_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkPySide_QtGui_QItemSelectionModel_SelectionFlag__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtGui_QItemSelectionModel_SelectionFlag___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtGui_QItemSelectionModel_SelectionFlag_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtGui_QItemSelectionModel_SelectionFlag_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void QItemSelectionModel_SelectionFlag_PythonToCpp_QItemSelectionModel_SelectionFlag(PyObject* pyIn, void* cppOut) {
    *((::QItemSelectionModel::SelectionFlag*)cppOut) = (::QItemSelectionModel::SelectionFlag) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QItemSelectionModel_SelectionFlag_PythonToCpp_QItemSelectionModel_SelectionFlag_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX]))
        return QItemSelectionModel_SelectionFlag_PythonToCpp_QItemSelectionModel_SelectionFlag;
    return 0;
}
static PyObject* QItemSelectionModel_SelectionFlag_CppToPython_QItemSelectionModel_SelectionFlag(const void* cppIn) {
    int castCppIn = *((::QItemSelectionModel::SelectionFlag*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX], castCppIn);

}

static void QFlags_QItemSelectionModel_SelectionFlag__PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QItemSelectionModel::SelectionFlag>*)cppOut) = ::QFlags<QItemSelectionModel::SelectionFlag>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QItemSelectionModel_SelectionFlag__PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]))
        return QFlags_QItemSelectionModel_SelectionFlag__PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_;
    return 0;
}
static PyObject* QFlags_QItemSelectionModel_SelectionFlag__CppToPython_QFlags_QItemSelectionModel_SelectionFlag_(const void* cppIn) {
    int castCppIn = *((::QFlags<QItemSelectionModel::SelectionFlag>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]));

}

static void QItemSelectionModel_SelectionFlag_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QItemSelectionModel::SelectionFlag>*)cppOut) = ::QFlags<QItemSelectionModel::SelectionFlag>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QItemSelectionModel_SelectionFlag_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX]))
        return QItemSelectionModel_SelectionFlag_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_;
    return 0;
}
static void number_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QItemSelectionModel::SelectionFlag>*)cppOut) = ::QFlags<QItemSelectionModel::SelectionFlag>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QItemSelectionModel_PythonToCpp_QItemSelectionModel_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QItemSelectionModel_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QItemSelectionModel_PythonToCpp_QItemSelectionModel_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QItemSelectionModel_Type))
        return QItemSelectionModel_PythonToCpp_QItemSelectionModel_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QItemSelectionModel_PTR_CppToPython_QItemSelectionModel(const void* cppIn) {
    return PySide::getWrapperForQObject((::QItemSelectionModel*)cppIn, &Sbk_QItemSelectionModel_Type);

}

void init_QItemSelectionModel(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QItemSelectionModel_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QItemSelectionModel", "QItemSelectionModel*",
        &Sbk_QItemSelectionModel_Type, &Shiboken::callCppDestructor< ::QItemSelectionModel >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QItemSelectionModel_Type,
        QItemSelectionModel_PythonToCpp_QItemSelectionModel_PTR,
        is_QItemSelectionModel_PythonToCpp_QItemSelectionModel_PTR_Convertible,
        QItemSelectionModel_PTR_CppToPython_QItemSelectionModel);

    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionModel");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionModel*");
    Shiboken::Conversions::registerConverterName(converter, "QItemSelectionModel&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemSelectionModel).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QItemSelectionModelWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QItemSelectionModel_Type, &Sbk_QItemSelectionModel_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'SelectionFlag'.
    SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX] = PySide::QFlags::create("SelectionFlags", &SbkPySide_QtGui_QItemSelectionModel_SelectionFlag_as_number);
    SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QItemSelectionModel_Type,
        "SelectionFlag",
        "PySide.QtGui.QItemSelectionModel.SelectionFlag",
        "QItemSelectionModel::SelectionFlag",
        SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX]);
    if (!SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "NoUpdate", (long) QItemSelectionModel::NoUpdate))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Clear", (long) QItemSelectionModel::Clear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Select", (long) QItemSelectionModel::Select))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Deselect", (long) QItemSelectionModel::Deselect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Toggle", (long) QItemSelectionModel::Toggle))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Current", (long) QItemSelectionModel::Current))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Rows", (long) QItemSelectionModel::Rows))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "Columns", (long) QItemSelectionModel::Columns))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "SelectCurrent", (long) QItemSelectionModel::SelectCurrent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "ToggleCurrent", (long) QItemSelectionModel::ToggleCurrent))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
        &Sbk_QItemSelectionModel_Type, "ClearAndSelect", (long) QItemSelectionModel::ClearAndSelect))
        return ;
    // Register converter for enum 'QItemSelectionModel::SelectionFlag'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX],
            QItemSelectionModel_SelectionFlag_CppToPython_QItemSelectionModel_SelectionFlag);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QItemSelectionModel_SelectionFlag_PythonToCpp_QItemSelectionModel_SelectionFlag,
            is_QItemSelectionModel_SelectionFlag_PythonToCpp_QItemSelectionModel_SelectionFlag_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QITEMSELECTIONMODEL_SELECTIONFLAG_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QItemSelectionModel::SelectionFlag");
        Shiboken::Conversions::registerConverterName(converter, "SelectionFlag");
    }
    // Register converter for flag 'QFlags<QItemSelectionModel::SelectionFlag>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX],
            QFlags_QItemSelectionModel_SelectionFlag__CppToPython_QFlags_QItemSelectionModel_SelectionFlag_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QItemSelectionModel_SelectionFlag_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_,
            is_QItemSelectionModel_SelectionFlag_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QItemSelectionModel_SelectionFlag__PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_,
            is_QFlags_QItemSelectionModel_SelectionFlag__PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag_,
            is_number_PythonToCpp_QFlags_QItemSelectionModel_SelectionFlag__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QFLAGS_QITEMSELECTIONMODEL_SELECTIONFLAG__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QItemSelectionModel::SelectionFlag>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<SelectionFlag>");
    }
    // End of 'SelectionFlag' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QItemSelectionModel_Type, &::QItemSelectionModel::staticMetaObject);

    qRegisterMetaType< ::QItemSelectionModel::SelectionFlag >("QItemSelectionModel::SelectionFlag");
    qRegisterMetaType< ::QItemSelectionModel::SelectionFlags >("QItemSelectionModel::SelectionFlags");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QItemSelectionModel_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QItemSelectionModel_Type, &::QItemSelectionModel::staticMetaObject, sizeof(::QItemSelectionModel));
}
