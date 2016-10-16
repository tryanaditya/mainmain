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

#include "qaction_wrapper.h"

// Extra includes
#include <QList>
#include <qaction.h>
#include <qactiongroup.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qfont.h>
#include <qgraphicswidget.h>
#include <qicon.h>
#include <qkeysequence.h>
#include <qmenu.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QActionWrapper::QActionWrapper(QObject * parent) : QAction(parent) {
    // ... middle
}

QActionWrapper::QActionWrapper(const QIcon & icon, const QString & text, QObject * parent) : QAction(icon, text, parent) {
    // ... middle
}

QActionWrapper::QActionWrapper(const QString & text, QObject * parent) : QAction(text, parent) {
    // ... middle
}

void QActionWrapper::childEvent(QChildEvent * arg__1)
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

void QActionWrapper::connectNotify(const char * signal)
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

void QActionWrapper::customEvent(QEvent * arg__1)
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

void QActionWrapper::disconnectNotify(const char * signal)
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

bool QActionWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QAction::event(arg__1);
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAction.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QActionWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QAction.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QActionWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QActionWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QAction::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QActionWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QAction::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QActionWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QActionWrapper* >(this));
        return QAction::qt_metacast(_clname);
}

QActionWrapper::~QActionWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QAction_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QAction >()))
        return -1;

    ::QActionWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QAction", 1, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return -1;


    // Overloaded function decisor
    // 0: QAction(QObject*)
    // 1: QAction(QIcon,QString,QObject*)
    // 2: QAction(QString,QObject*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[2])))) {
        overloadId = 1; // QAction(QIcon,QString,QObject*)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QAction(QObject*)
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        overloadId = 2; // QAction(QString,QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QAction_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QAction(QObject * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QAction(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QActionWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QActionWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QAction(const QIcon & icon, const QString & text, QObject * parent)
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
            if (!Shiboken::Object::isValid(pyArgs[2]))
                return -1;
            ::QObject* cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // QAction(QIcon,QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QActionWrapper(*cppArg0, cppArg1, cppArg2);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QActionWrapper(*cppArg0, cppArg1, cppArg2);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[2], self);
            }
            break;
        }
        case 2: // QAction(const QString & text, QObject * parent)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QAction(QString,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QActionWrapper(cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QActionWrapper(cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QAction >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QAction_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QAction_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject", "PySide.QtGui.QIcon, unicode, PySide.QtCore.QObject", "unicode, PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAction", overloads);
        return -1;
}

static PyObject* Sbk_QActionFunc_actionGroup(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // actionGroup()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QActionGroup * cppResult = const_cast<const ::QAction*>(cppSelf)->actionGroup();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONGROUP_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_activate(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: activate(QAction::ActionEvent)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX]), (pyArg)))) {
        overloadId = 0; // activate(QAction::ActionEvent)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_activate_TypeError;

    // Call function/method
    {
        ::QAction::ActionEvent cppArg0 = ((::QAction::ActionEvent)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // activate(QAction::ActionEvent)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->activate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_activate_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction.ActionEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.activate", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_associatedGraphicsWidgets(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // associatedGraphicsWidgets()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QGraphicsWidget * > cppResult = const_cast<const ::QAction*>(cppSelf)->associatedGraphicsWidgets();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QGRAPHICSWIDGETPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_associatedWidgets(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // associatedWidgets()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QWidget * > cppResult = const_cast<const ::QAction*>(cppSelf)->associatedWidgets();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QWIDGETPTR_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_autoRepeat(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoRepeat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->autoRepeat();
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

static PyObject* Sbk_QActionFunc_data(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // data()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QVariant cppResult = const_cast<const ::QAction*>(cppSelf)->data();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QActionFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QAction::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QActionFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.event", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_font(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // font()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QFont cppResult = const_cast<const ::QAction*>(cppSelf)->font();
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

static PyObject* Sbk_QActionFunc_hover(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hover()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hover();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QActionFunc_icon(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QAction*>(cppSelf)->icon();
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

static PyObject* Sbk_QActionFunc_iconText(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // iconText()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAction*>(cppSelf)->iconText();
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

static PyObject* Sbk_QActionFunc_isCheckable(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isCheckable()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isCheckable();
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

static PyObject* Sbk_QActionFunc_isChecked(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isChecked()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isChecked();
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

static PyObject* Sbk_QActionFunc_isEnabled(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_QActionFunc_isIconVisibleInMenu(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isIconVisibleInMenu()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isIconVisibleInMenu();
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

static PyObject* Sbk_QActionFunc_isSeparator(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSeparator()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isSeparator();
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

static PyObject* Sbk_QActionFunc_isVisible(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QAction*>(cppSelf)->isVisible();
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

static PyObject* Sbk_QActionFunc_menu(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // menu()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = const_cast<const ::QAction*>(cppSelf)->menu();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_menuRole(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // menuRole()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction::MenuRole cppResult = const_cast<const ::QAction*>(cppSelf)->menuRole();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_parentWidget(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QAction*>(cppSelf)->parentWidget();
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

static PyObject* Sbk_QActionFunc_priority(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // priority()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction::Priority cppResult = const_cast<const ::QAction*>(cppSelf)->priority();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_setActionGroup(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setActionGroup(QActionGroup*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTIONGROUP_IDX], (pyArg)))) {
        overloadId = 0; // setActionGroup(QActionGroup*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setActionGroup_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QActionGroup* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setActionGroup(QActionGroup*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setActionGroup(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setActionGroup_TypeError:
        const char* overloads[] = {"PySide.QtGui.QActionGroup", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setActionGroup", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setAutoRepeat(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoRepeat(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoRepeat(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setAutoRepeat_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoRepeat(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoRepeat(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setAutoRepeat_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setAutoRepeat", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setCheckable(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCheckable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setCheckable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setCheckable_TypeError;

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

    Sbk_QActionFunc_setCheckable_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setCheckable", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setChecked(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setChecked(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setChecked(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setChecked_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChecked(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setChecked(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setChecked_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setChecked", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setData(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setData(QVariant)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArg)))) {
        overloadId = 0; // setData(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setData_TypeError;

    // Call function/method
    {
        ::QVariant cppArg0 = ::QVariant();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setData(QVariant)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setData(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setData_TypeError:
        const char* overloads[] = {"QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setData", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setDisabled(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDisabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setDisabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setDisabled_TypeError;

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

    Sbk_QActionFunc_setDisabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setDisabled", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setEnabled_TypeError;

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

    Sbk_QActionFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setFont(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFont(QFont)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QFONT_IDX], (pyArg)))) {
        overloadId = 0; // setFont(QFont)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setFont_TypeError;

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

    Sbk_QActionFunc_setFont_TypeError:
        const char* overloads[] = {"PySide.QtGui.QFont", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setFont", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setIcon_TypeError;

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

    Sbk_QActionFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setIconText(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setIconText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setIconText_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconText(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setIconText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setIconText", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setIconVisibleInMenu(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIconVisibleInMenu(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setIconVisibleInMenu(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setIconVisibleInMenu_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconVisibleInMenu(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setIconVisibleInMenu(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setIconVisibleInMenu_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setIconVisibleInMenu", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setMenu(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMenu(QMenu*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyArg)))) {
        overloadId = 0; // setMenu(QMenu*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setMenu_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMenu* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMenu(QMenu*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMenu(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(self, pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setMenu_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMenu", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setMenu", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setMenuRole(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setMenuRole(QAction::MenuRole)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX]), (pyArg)))) {
        overloadId = 0; // setMenuRole(QAction::MenuRole)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setMenuRole_TypeError;

    // Call function/method
    {
        ::QAction::MenuRole cppArg0 = ((::QAction::MenuRole)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setMenuRole(QAction::MenuRole)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setMenuRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setMenuRole_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction.MenuRole", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setMenuRole", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setPriority(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPriority(QAction::Priority)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX]), (pyArg)))) {
        overloadId = 0; // setPriority(QAction::Priority)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setPriority_TypeError;

    // Call function/method
    {
        ::QAction::Priority cppArg0 = ((::QAction::Priority)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPriority(QAction::Priority)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPriority(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setPriority_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction.Priority", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setPriority", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setSeparator(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSeparator(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSeparator(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setSeparator_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSeparator(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSeparator(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setSeparator_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setSeparator", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setShortcut(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setShortcut(QKeySequence)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
        overloadId = 0; // setShortcut(QKeySequence)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setShortcut_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QKeySequence cppArg0_local = ::QKeySequence();
        ::QKeySequence* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setShortcut(QKeySequence)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setShortcut(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setShortcut_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setShortcut", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setShortcutContext(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setShortcutContext(Qt::ShortcutContext)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArg)))) {
        overloadId = 0; // setShortcutContext(Qt::ShortcutContext)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setShortcutContext_TypeError;

    // Call function/method
    {
        ::Qt::ShortcutContext cppArg0 = ((::Qt::ShortcutContext)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setShortcutContext(Qt::ShortcutContext)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setShortcutContext(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setShortcutContext_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ShortcutContext", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setShortcutContext", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setShortcuts(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setShortcuts(QKeySequence::StandardKey)
    // 1: setShortcuts(QList<QKeySequence>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX], (pyArg)))) {
        overloadId = 1; // setShortcuts(QList<QKeySequence>)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]), (pyArg)))) {
        overloadId = 0; // setShortcuts(QKeySequence::StandardKey)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setShortcuts_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setShortcuts(QKeySequence::StandardKey arg__1)
        {
            ::QKeySequence::StandardKey cppArg0 = ((::QKeySequence::StandardKey)0);
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setShortcuts(QKeySequence::StandardKey)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setShortcuts(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // setShortcuts(const QList<QKeySequence > & shortcuts)
        {
            ::QList<QKeySequence > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setShortcuts(QList<QKeySequence>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setShortcuts(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setShortcuts_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence.StandardKey", "list", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setShortcuts", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setSoftKeyRole(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setSoftKeyRole(QAction::SoftKeyRole)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX]), (pyArg)))) {
        overloadId = 0; // setSoftKeyRole(QAction::SoftKeyRole)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setSoftKeyRole_TypeError;

    // Call function/method
    {
        ::QAction::SoftKeyRole cppArg0 = ((::QAction::SoftKeyRole)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSoftKeyRole(QAction::SoftKeyRole)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setSoftKeyRole(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setSoftKeyRole_TypeError:
        const char* overloads[] = {"PySide.QtGui.QAction.SoftKeyRole", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setSoftKeyRole", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setStatusTip(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStatusTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setStatusTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setStatusTip_TypeError;

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

    Sbk_QActionFunc_setStatusTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setStatusTip", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setText(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setText(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setText(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setText_TypeError;

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

    Sbk_QActionFunc_setText_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setText", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setToolTip_TypeError;

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

    Sbk_QActionFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVisible(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QActionFunc_setVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setVisible", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_setWhatsThis(PyObject* self, PyObject* pyArg)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWhatsThis(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWhatsThis(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_setWhatsThis_TypeError;

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

    Sbk_QActionFunc_setWhatsThis_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QAction.setWhatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_shortcut(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shortcut()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeySequence cppResult = const_cast<const ::QAction*>(cppSelf)->shortcut();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_shortcutContext(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shortcutContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ShortcutContext cppResult = const_cast<const ::QAction*>(cppSelf)->shortcutContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_shortcuts(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // shortcuts()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QList<QKeySequence > cppResult = const_cast<const ::QAction*>(cppSelf)->shortcuts();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtGuiTypeConverters[SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_showStatusText(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAction.showStatusText(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:showStatusText", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: showStatusText(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // showStatusText(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // showStatusText(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QActionFunc_showStatusText_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "widget");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QAction.showStatusText(): got multiple values for keyword argument 'widget'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QActionFunc_showStatusText_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // showStatusText(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = cppSelf->showStatusText(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QActionFunc_showStatusText_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QAction.showStatusText", overloads);
        return 0;
}

static PyObject* Sbk_QActionFunc_softKeyRole(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // softKeyRole()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction::SoftKeyRole cppResult = const_cast<const ::QAction*>(cppSelf)->softKeyRole();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QActionFunc_statusTip(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // statusTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAction*>(cppSelf)->statusTip();
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

static PyObject* Sbk_QActionFunc_text(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // text()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAction*>(cppSelf)->text();
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

static PyObject* Sbk_QActionFunc_toggle(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toggle()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toggle();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QActionFunc_toolTip(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAction*>(cppSelf)->toolTip();
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

static PyObject* Sbk_QActionFunc_trigger(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // trigger()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->trigger();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QActionFunc_whatsThis(PyObject* self)
{
    ::QAction* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QAction*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QACTION_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // whatsThis()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QAction*>(cppSelf)->whatsThis();
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

static PyMethodDef Sbk_QAction_methods[] = {
    {"actionGroup", (PyCFunction)Sbk_QActionFunc_actionGroup, METH_NOARGS},
    {"activate", (PyCFunction)Sbk_QActionFunc_activate, METH_O},
    {"associatedGraphicsWidgets", (PyCFunction)Sbk_QActionFunc_associatedGraphicsWidgets, METH_NOARGS},
    {"associatedWidgets", (PyCFunction)Sbk_QActionFunc_associatedWidgets, METH_NOARGS},
    {"autoRepeat", (PyCFunction)Sbk_QActionFunc_autoRepeat, METH_NOARGS},
    {"data", (PyCFunction)Sbk_QActionFunc_data, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QActionFunc_event, METH_O},
    {"font", (PyCFunction)Sbk_QActionFunc_font, METH_NOARGS},
    {"hover", (PyCFunction)Sbk_QActionFunc_hover, METH_NOARGS},
    {"icon", (PyCFunction)Sbk_QActionFunc_icon, METH_NOARGS},
    {"iconText", (PyCFunction)Sbk_QActionFunc_iconText, METH_NOARGS},
    {"isCheckable", (PyCFunction)Sbk_QActionFunc_isCheckable, METH_NOARGS},
    {"isChecked", (PyCFunction)Sbk_QActionFunc_isChecked, METH_NOARGS},
    {"isEnabled", (PyCFunction)Sbk_QActionFunc_isEnabled, METH_NOARGS},
    {"isIconVisibleInMenu", (PyCFunction)Sbk_QActionFunc_isIconVisibleInMenu, METH_NOARGS},
    {"isSeparator", (PyCFunction)Sbk_QActionFunc_isSeparator, METH_NOARGS},
    {"isVisible", (PyCFunction)Sbk_QActionFunc_isVisible, METH_NOARGS},
    {"menu", (PyCFunction)Sbk_QActionFunc_menu, METH_NOARGS},
    {"menuRole", (PyCFunction)Sbk_QActionFunc_menuRole, METH_NOARGS},
    {"parentWidget", (PyCFunction)Sbk_QActionFunc_parentWidget, METH_NOARGS},
    {"priority", (PyCFunction)Sbk_QActionFunc_priority, METH_NOARGS},
    {"setActionGroup", (PyCFunction)Sbk_QActionFunc_setActionGroup, METH_O},
    {"setAutoRepeat", (PyCFunction)Sbk_QActionFunc_setAutoRepeat, METH_O},
    {"setCheckable", (PyCFunction)Sbk_QActionFunc_setCheckable, METH_O},
    {"setChecked", (PyCFunction)Sbk_QActionFunc_setChecked, METH_O},
    {"setData", (PyCFunction)Sbk_QActionFunc_setData, METH_O},
    {"setDisabled", (PyCFunction)Sbk_QActionFunc_setDisabled, METH_O},
    {"setEnabled", (PyCFunction)Sbk_QActionFunc_setEnabled, METH_O},
    {"setFont", (PyCFunction)Sbk_QActionFunc_setFont, METH_O},
    {"setIcon", (PyCFunction)Sbk_QActionFunc_setIcon, METH_O},
    {"setIconText", (PyCFunction)Sbk_QActionFunc_setIconText, METH_O},
    {"setIconVisibleInMenu", (PyCFunction)Sbk_QActionFunc_setIconVisibleInMenu, METH_O},
    {"setMenu", (PyCFunction)Sbk_QActionFunc_setMenu, METH_O},
    {"setMenuRole", (PyCFunction)Sbk_QActionFunc_setMenuRole, METH_O},
    {"setPriority", (PyCFunction)Sbk_QActionFunc_setPriority, METH_O},
    {"setSeparator", (PyCFunction)Sbk_QActionFunc_setSeparator, METH_O},
    {"setShortcut", (PyCFunction)Sbk_QActionFunc_setShortcut, METH_O},
    {"setShortcutContext", (PyCFunction)Sbk_QActionFunc_setShortcutContext, METH_O},
    {"setShortcuts", (PyCFunction)Sbk_QActionFunc_setShortcuts, METH_O},
    {"setSoftKeyRole", (PyCFunction)Sbk_QActionFunc_setSoftKeyRole, METH_O},
    {"setStatusTip", (PyCFunction)Sbk_QActionFunc_setStatusTip, METH_O},
    {"setText", (PyCFunction)Sbk_QActionFunc_setText, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QActionFunc_setToolTip, METH_O},
    {"setVisible", (PyCFunction)Sbk_QActionFunc_setVisible, METH_O},
    {"setWhatsThis", (PyCFunction)Sbk_QActionFunc_setWhatsThis, METH_O},
    {"shortcut", (PyCFunction)Sbk_QActionFunc_shortcut, METH_NOARGS},
    {"shortcutContext", (PyCFunction)Sbk_QActionFunc_shortcutContext, METH_NOARGS},
    {"shortcuts", (PyCFunction)Sbk_QActionFunc_shortcuts, METH_NOARGS},
    {"showStatusText", (PyCFunction)Sbk_QActionFunc_showStatusText, METH_VARARGS|METH_KEYWORDS},
    {"softKeyRole", (PyCFunction)Sbk_QActionFunc_softKeyRole, METH_NOARGS},
    {"statusTip", (PyCFunction)Sbk_QActionFunc_statusTip, METH_NOARGS},
    {"text", (PyCFunction)Sbk_QActionFunc_text, METH_NOARGS},
    {"toggle", (PyCFunction)Sbk_QActionFunc_toggle, METH_NOARGS},
    {"toolTip", (PyCFunction)Sbk_QActionFunc_toolTip, METH_NOARGS},
    {"trigger", (PyCFunction)Sbk_QActionFunc_trigger, METH_NOARGS},
    {"whatsThis", (PyCFunction)Sbk_QActionFunc_whatsThis, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QAction_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QAction_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QAction_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QAction",
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
    /*tp_traverse*/         Sbk_QAction_traverse,
    /*tp_clear*/            Sbk_QAction_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QAction_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QAction_Init,
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

static void* Sbk_QAction_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QAction*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QAction_MenuRole_PythonToCpp_QAction_MenuRole(PyObject* pyIn, void* cppOut) {
    *((::QAction::MenuRole*)cppOut) = (::QAction::MenuRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAction_MenuRole_PythonToCpp_QAction_MenuRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX]))
        return QAction_MenuRole_PythonToCpp_QAction_MenuRole;
    return 0;
}
static PyObject* QAction_MenuRole_CppToPython_QAction_MenuRole(const void* cppIn) {
    int castCppIn = *((::QAction::MenuRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX], castCppIn);

}

static void QAction_SoftKeyRole_PythonToCpp_QAction_SoftKeyRole(PyObject* pyIn, void* cppOut) {
    *((::QAction::SoftKeyRole*)cppOut) = (::QAction::SoftKeyRole) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAction_SoftKeyRole_PythonToCpp_QAction_SoftKeyRole_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX]))
        return QAction_SoftKeyRole_PythonToCpp_QAction_SoftKeyRole;
    return 0;
}
static PyObject* QAction_SoftKeyRole_CppToPython_QAction_SoftKeyRole(const void* cppIn) {
    int castCppIn = *((::QAction::SoftKeyRole*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX], castCppIn);

}

static void QAction_Priority_PythonToCpp_QAction_Priority(PyObject* pyIn, void* cppOut) {
    *((::QAction::Priority*)cppOut) = (::QAction::Priority) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAction_Priority_PythonToCpp_QAction_Priority_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX]))
        return QAction_Priority_PythonToCpp_QAction_Priority;
    return 0;
}
static PyObject* QAction_Priority_CppToPython_QAction_Priority(const void* cppIn) {
    int castCppIn = *((::QAction::Priority*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX], castCppIn);

}

static void QAction_ActionEvent_PythonToCpp_QAction_ActionEvent(PyObject* pyIn, void* cppOut) {
    *((::QAction::ActionEvent*)cppOut) = (::QAction::ActionEvent) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QAction_ActionEvent_PythonToCpp_QAction_ActionEvent_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX]))
        return QAction_ActionEvent_PythonToCpp_QAction_ActionEvent;
    return 0;
}
static PyObject* QAction_ActionEvent_CppToPython_QAction_ActionEvent(const void* cppIn) {
    int castCppIn = *((::QAction::ActionEvent*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QAction_PythonToCpp_QAction_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QAction_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QAction_PythonToCpp_QAction_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QAction_Type))
        return QAction_PythonToCpp_QAction_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QAction_PTR_CppToPython_QAction(const void* cppIn) {
    return PySide::getWrapperForQObject((::QAction*)cppIn, &Sbk_QAction_Type);

}

void init_QAction(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QACTION_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QAction_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QAction", "QAction*",
        &Sbk_QAction_Type, &Shiboken::callCppDestructor< ::QAction >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QAction_Type,
        QAction_PythonToCpp_QAction_PTR,
        is_QAction_PythonToCpp_QAction_PTR_Convertible,
        QAction_PTR_CppToPython_QAction);

    Shiboken::Conversions::registerConverterName(converter, "QAction");
    Shiboken::Conversions::registerConverterName(converter, "QAction*");
    Shiboken::Conversions::registerConverterName(converter, "QAction&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QAction).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QActionWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QAction_Type, &Sbk_QAction_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'MenuRole'.
    SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAction_Type,
        "MenuRole",
        "PySide.QtGui.QAction.MenuRole",
        "QAction::MenuRole");
    if (!SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "NoRole", (long) QAction::NoRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "TextHeuristicRole", (long) QAction::TextHeuristicRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "ApplicationSpecificRole", (long) QAction::ApplicationSpecificRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "AboutQtRole", (long) QAction::AboutQtRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "AboutRole", (long) QAction::AboutRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "PreferencesRole", (long) QAction::PreferencesRole))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
        &Sbk_QAction_Type, "QuitRole", (long) QAction::QuitRole))
        return ;
    // Register converter for enum 'QAction::MenuRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX],
            QAction_MenuRole_CppToPython_QAction_MenuRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAction_MenuRole_PythonToCpp_QAction_MenuRole,
            is_QAction_MenuRole_PythonToCpp_QAction_MenuRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_MENUROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAction::MenuRole");
        Shiboken::Conversions::registerConverterName(converter, "MenuRole");
    }
    // End of 'MenuRole' enum.

    // Initialization of enum 'SoftKeyRole'.
    SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAction_Type,
        "SoftKeyRole",
        "PySide.QtGui.QAction.SoftKeyRole",
        "QAction::SoftKeyRole");
    if (!SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX],
        &Sbk_QAction_Type, "NoSoftKey", (long) QAction::NoSoftKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX],
        &Sbk_QAction_Type, "PositiveSoftKey", (long) QAction::PositiveSoftKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX],
        &Sbk_QAction_Type, "NegativeSoftKey", (long) QAction::NegativeSoftKey))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX],
        &Sbk_QAction_Type, "SelectSoftKey", (long) QAction::SelectSoftKey))
        return ;
    // Register converter for enum 'QAction::SoftKeyRole'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX],
            QAction_SoftKeyRole_CppToPython_QAction_SoftKeyRole);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAction_SoftKeyRole_PythonToCpp_QAction_SoftKeyRole,
            is_QAction_SoftKeyRole_PythonToCpp_QAction_SoftKeyRole_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_SOFTKEYROLE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAction::SoftKeyRole");
        Shiboken::Conversions::registerConverterName(converter, "SoftKeyRole");
    }
    // End of 'SoftKeyRole' enum.

    // Initialization of enum 'Priority'.
    SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAction_Type,
        "Priority",
        "PySide.QtGui.QAction.Priority",
        "QAction::Priority");
    if (!SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX],
        &Sbk_QAction_Type, "LowPriority", (long) QAction::LowPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX],
        &Sbk_QAction_Type, "NormalPriority", (long) QAction::NormalPriority))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX],
        &Sbk_QAction_Type, "HighPriority", (long) QAction::HighPriority))
        return ;
    // Register converter for enum 'QAction::Priority'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX],
            QAction_Priority_CppToPython_QAction_Priority);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAction_Priority_PythonToCpp_QAction_Priority,
            is_QAction_Priority_PythonToCpp_QAction_Priority_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_PRIORITY_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAction::Priority");
        Shiboken::Conversions::registerConverterName(converter, "Priority");
    }
    // End of 'Priority' enum.

    // Initialization of enum 'ActionEvent'.
    SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QAction_Type,
        "ActionEvent",
        "PySide.QtGui.QAction.ActionEvent",
        "QAction::ActionEvent");
    if (!SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX],
        &Sbk_QAction_Type, "Trigger", (long) QAction::Trigger))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX],
        &Sbk_QAction_Type, "Hover", (long) QAction::Hover))
        return ;
    // Register converter for enum 'QAction::ActionEvent'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX],
            QAction_ActionEvent_CppToPython_QAction_ActionEvent);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QAction_ActionEvent_PythonToCpp_QAction_ActionEvent,
            is_QAction_ActionEvent_PythonToCpp_QAction_ActionEvent_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QACTION_ACTIONEVENT_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QAction::ActionEvent");
        Shiboken::Conversions::registerConverterName(converter, "ActionEvent");
    }
    // End of 'ActionEvent' enum.

    PySide::Signal::registerSignals(&Sbk_QAction_Type, &::QAction::staticMetaObject);

    qRegisterMetaType< ::QAction::MenuRole >("QAction::MenuRole");
    qRegisterMetaType< ::QAction::SoftKeyRole >("QAction::SoftKeyRole");
    qRegisterMetaType< ::QAction::Priority >("QAction::Priority");
    qRegisterMetaType< ::QAction::ActionEvent >("QAction::ActionEvent");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QAction_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QAction_Type, &::QAction::staticMetaObject, sizeof(::QAction));
}
