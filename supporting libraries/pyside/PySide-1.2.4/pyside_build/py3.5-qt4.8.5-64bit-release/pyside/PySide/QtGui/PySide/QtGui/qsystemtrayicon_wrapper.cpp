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

#include "qsystemtrayicon_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qicon.h>
#include <qmenu.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qrect.h>
#include <qsystemtrayicon.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QSystemTrayIconWrapper::QSystemTrayIconWrapper(QObject * parent) : QSystemTrayIcon(parent) {
    // ... middle
}

QSystemTrayIconWrapper::QSystemTrayIconWrapper(const QIcon & icon, QObject * parent) : QSystemTrayIcon(icon, parent) {
    // ... middle
}

void QSystemTrayIconWrapper::childEvent(QChildEvent * arg__1)
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

void QSystemTrayIconWrapper::connectNotify(const char * signal)
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

void QSystemTrayIconWrapper::customEvent(QEvent * arg__1)
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

void QSystemTrayIconWrapper::disconnectNotify(const char * signal)
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

bool QSystemTrayIconWrapper::event(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QSystemTrayIcon::event(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], event)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSystemTrayIcon.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QSystemTrayIconWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QSystemTrayIcon.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QSystemTrayIconWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QSystemTrayIconWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QSystemTrayIcon::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QSystemTrayIconWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QSystemTrayIcon::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QSystemTrayIconWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QSystemTrayIconWrapper* >(this));
        return QSystemTrayIcon::qt_metacast(_clname);
}

QSystemTrayIconWrapper::~QSystemTrayIconWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSystemTrayIcon_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QSystemTrayIcon >()))
        return -1;

    ::QSystemTrayIconWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QSystemTrayIcon", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QSystemTrayIcon(QObject*)
    // 1: QSystemTrayIcon(QIcon,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QSystemTrayIcon(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // QSystemTrayIcon(QIcon,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 1; // QSystemTrayIcon(QIcon,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QSystemTrayIcon(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIcon_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QSystemTrayIcon(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QSystemTrayIcon_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QSystemTrayIcon(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSystemTrayIconWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSystemTrayIconWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QSystemTrayIcon(const QIcon & icon, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                        goto Sbk_QSystemTrayIcon_Init_TypeError;
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

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QObject* cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // QSystemTrayIcon(QIcon,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QSystemTrayIconWrapper(*cppArg0, cppArg1);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QSystemTrayIconWrapper(*cppArg0, cppArg1);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QSystemTrayIcon >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSystemTrayIcon_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QSystemTrayIcon_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "PySide.QtGui.QIcon, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSystemTrayIcon", overloads);
        return -1;
}

static PyObject* Sbk_QSystemTrayIconFunc_contextMenu(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // contextMenu()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = const_cast<const ::QSystemTrayIcon*>(cppSelf)->contextMenu();
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

static PyObject* Sbk_QSystemTrayIconFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QSystemTrayIcon::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSystemTrayIconFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSystemTrayIcon.event", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_geometry(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // geometry()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QRect cppResult = const_cast<const ::QSystemTrayIcon*>(cppSelf)->geometry();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QRECT_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSystemTrayIconFunc_hide(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hide()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->hide();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSystemTrayIconFunc_icon(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // icon()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QIcon cppResult = const_cast<const ::QSystemTrayIcon*>(cppSelf)->icon();
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

static PyObject* Sbk_QSystemTrayIconFunc_isSystemTrayAvailable(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isSystemTrayAvailable()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QSystemTrayIcon::isSystemTrayAvailable();
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

static PyObject* Sbk_QSystemTrayIconFunc_isVisible(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isVisible()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QSystemTrayIcon*>(cppSelf)->isVisible();
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

static PyObject* Sbk_QSystemTrayIconFunc_setContextMenu(PyObject* self, PyObject* pyArg)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContextMenu(QMenu*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMENU_IDX], (pyArg)))) {
        overloadId = 0; // setContextMenu(QMenu*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_setContextMenu_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QMenu* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContextMenu(QMenu*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContextMenu(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "setContextMenu(QMenu*)1", pyArg);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSystemTrayIconFunc_setContextMenu_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMenu", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSystemTrayIcon.setContextMenu", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_setIcon(PyObject* self, PyObject* pyArg)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setIcon(QIcon)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QICON_IDX], (pyArg)))) {
        overloadId = 0; // setIcon(QIcon)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_setIcon_TypeError;

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

    Sbk_QSystemTrayIconFunc_setIcon_TypeError:
        const char* overloads[] = {"PySide.QtGui.QIcon", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSystemTrayIcon.setIcon", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_setToolTip(PyObject* self, PyObject* pyArg)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setToolTip(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setToolTip(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_setToolTip_TypeError;

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

    Sbk_QSystemTrayIconFunc_setToolTip_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSystemTrayIcon.setToolTip", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_setVisible_TypeError;

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

    Sbk_QSystemTrayIconFunc_setVisible_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QSystemTrayIcon.setVisible", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_show(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // show()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->show();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSystemTrayIconFunc_showMessage(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon.showMessage(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon.showMessage(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:showMessage", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
                overloadId = 0; // showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSystemTrayIconFunc_showMessage_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "icon");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon.showMessage(): got multiple values for keyword argument 'icon'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX]), (pyArgs[2]))))
                    goto Sbk_QSystemTrayIconFunc_showMessage_TypeError;
            }
            value = PyDict_GetItemString(kwds, "msecs");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QSystemTrayIcon.showMessage(): got multiple values for keyword argument 'msecs'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                    goto Sbk_QSystemTrayIconFunc_showMessage_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = ::QString();
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QSystemTrayIcon::MessageIcon cppArg2 = QSystemTrayIcon::Information;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3 = 10000;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // showMessage(QString,QString,QSystemTrayIcon::MessageIcon,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->showMessage(cppArg0, cppArg1, cppArg2, cppArg3);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSystemTrayIconFunc_showMessage_TypeError:
        const char* overloads[] = {"unicode, unicode, PySide.QtGui.QSystemTrayIcon.MessageIcon = Information, int = 10000", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QSystemTrayIcon.showMessage", overloads);
        return 0;
}

static PyObject* Sbk_QSystemTrayIconFunc_supportsMessages(PyObject* self)
{
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // supportsMessages()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = ::QSystemTrayIcon::supportsMessages();
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

static PyObject* Sbk_QSystemTrayIconFunc_toolTip(PyObject* self)
{
    ::QSystemTrayIcon* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QSystemTrayIcon*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toolTip()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QSystemTrayIcon*>(cppSelf)->toolTip();
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

static PyMethodDef Sbk_QSystemTrayIcon_methods[] = {
    {"contextMenu", (PyCFunction)Sbk_QSystemTrayIconFunc_contextMenu, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QSystemTrayIconFunc_event, METH_O},
    {"geometry", (PyCFunction)Sbk_QSystemTrayIconFunc_geometry, METH_NOARGS},
    {"hide", (PyCFunction)Sbk_QSystemTrayIconFunc_hide, METH_NOARGS},
    {"icon", (PyCFunction)Sbk_QSystemTrayIconFunc_icon, METH_NOARGS},
    {"isSystemTrayAvailable", (PyCFunction)Sbk_QSystemTrayIconFunc_isSystemTrayAvailable, METH_NOARGS|METH_STATIC},
    {"isVisible", (PyCFunction)Sbk_QSystemTrayIconFunc_isVisible, METH_NOARGS},
    {"setContextMenu", (PyCFunction)Sbk_QSystemTrayIconFunc_setContextMenu, METH_O},
    {"setIcon", (PyCFunction)Sbk_QSystemTrayIconFunc_setIcon, METH_O},
    {"setToolTip", (PyCFunction)Sbk_QSystemTrayIconFunc_setToolTip, METH_O},
    {"setVisible", (PyCFunction)Sbk_QSystemTrayIconFunc_setVisible, METH_O},
    {"show", (PyCFunction)Sbk_QSystemTrayIconFunc_show, METH_NOARGS},
    {"showMessage", (PyCFunction)Sbk_QSystemTrayIconFunc_showMessage, METH_VARARGS|METH_KEYWORDS},
    {"supportsMessages", (PyCFunction)Sbk_QSystemTrayIconFunc_supportsMessages, METH_NOARGS|METH_STATIC},
    {"toolTip", (PyCFunction)Sbk_QSystemTrayIconFunc_toolTip, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QSystemTrayIcon_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QSystemTrayIcon_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSystemTrayIcon_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QSystemTrayIcon",
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
    /*tp_traverse*/         Sbk_QSystemTrayIcon_traverse,
    /*tp_clear*/            Sbk_QSystemTrayIcon_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSystemTrayIcon_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSystemTrayIcon_Init,
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

static void* Sbk_QSystemTrayIcon_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QSystemTrayIcon*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QSystemTrayIcon_ActivationReason_PythonToCpp_QSystemTrayIcon_ActivationReason(PyObject* pyIn, void* cppOut) {
    *((::QSystemTrayIcon::ActivationReason*)cppOut) = (::QSystemTrayIcon::ActivationReason) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSystemTrayIcon_ActivationReason_PythonToCpp_QSystemTrayIcon_ActivationReason_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX]))
        return QSystemTrayIcon_ActivationReason_PythonToCpp_QSystemTrayIcon_ActivationReason;
    return 0;
}
static PyObject* QSystemTrayIcon_ActivationReason_CppToPython_QSystemTrayIcon_ActivationReason(const void* cppIn) {
    int castCppIn = *((::QSystemTrayIcon::ActivationReason*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX], castCppIn);

}

static void QSystemTrayIcon_MessageIcon_PythonToCpp_QSystemTrayIcon_MessageIcon(PyObject* pyIn, void* cppOut) {
    *((::QSystemTrayIcon::MessageIcon*)cppOut) = (::QSystemTrayIcon::MessageIcon) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QSystemTrayIcon_MessageIcon_PythonToCpp_QSystemTrayIcon_MessageIcon_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX]))
        return QSystemTrayIcon_MessageIcon_PythonToCpp_QSystemTrayIcon_MessageIcon;
    return 0;
}
static PyObject* QSystemTrayIcon_MessageIcon_CppToPython_QSystemTrayIcon_MessageIcon(const void* cppIn) {
    int castCppIn = *((::QSystemTrayIcon::MessageIcon*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QSystemTrayIcon_PythonToCpp_QSystemTrayIcon_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QSystemTrayIcon_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QSystemTrayIcon_PythonToCpp_QSystemTrayIcon_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QSystemTrayIcon_Type))
        return QSystemTrayIcon_PythonToCpp_QSystemTrayIcon_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QSystemTrayIcon_PTR_CppToPython_QSystemTrayIcon(const void* cppIn) {
    return PySide::getWrapperForQObject((::QSystemTrayIcon*)cppIn, &Sbk_QSystemTrayIcon_Type);

}

void init_QSystemTrayIcon(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSystemTrayIcon_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QSystemTrayIcon", "QSystemTrayIcon*",
        &Sbk_QSystemTrayIcon_Type, &Shiboken::callCppDestructor< ::QSystemTrayIcon >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QSystemTrayIcon_Type,
        QSystemTrayIcon_PythonToCpp_QSystemTrayIcon_PTR,
        is_QSystemTrayIcon_PythonToCpp_QSystemTrayIcon_PTR_Convertible,
        QSystemTrayIcon_PTR_CppToPython_QSystemTrayIcon);

    Shiboken::Conversions::registerConverterName(converter, "QSystemTrayIcon");
    Shiboken::Conversions::registerConverterName(converter, "QSystemTrayIcon*");
    Shiboken::Conversions::registerConverterName(converter, "QSystemTrayIcon&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSystemTrayIcon).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QSystemTrayIconWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QSystemTrayIcon_Type, &Sbk_QSystemTrayIcon_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ActivationReason'.
    SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSystemTrayIcon_Type,
        "ActivationReason",
        "PySide.QtGui.QSystemTrayIcon.ActivationReason",
        "QSystemTrayIcon::ActivationReason");
    if (!SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Unknown", (long) QSystemTrayIcon::Unknown))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Context", (long) QSystemTrayIcon::Context))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
        &Sbk_QSystemTrayIcon_Type, "DoubleClick", (long) QSystemTrayIcon::DoubleClick))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Trigger", (long) QSystemTrayIcon::Trigger))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
        &Sbk_QSystemTrayIcon_Type, "MiddleClick", (long) QSystemTrayIcon::MiddleClick))
        return ;
    // Register converter for enum 'QSystemTrayIcon::ActivationReason'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX],
            QSystemTrayIcon_ActivationReason_CppToPython_QSystemTrayIcon_ActivationReason);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSystemTrayIcon_ActivationReason_PythonToCpp_QSystemTrayIcon_ActivationReason,
            is_QSystemTrayIcon_ActivationReason_PythonToCpp_QSystemTrayIcon_ActivationReason_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_ACTIVATIONREASON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSystemTrayIcon::ActivationReason");
        Shiboken::Conversions::registerConverterName(converter, "ActivationReason");
    }
    // End of 'ActivationReason' enum.

    // Initialization of enum 'MessageIcon'.
    SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QSystemTrayIcon_Type,
        "MessageIcon",
        "PySide.QtGui.QSystemTrayIcon.MessageIcon",
        "QSystemTrayIcon::MessageIcon");
    if (!SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX],
        &Sbk_QSystemTrayIcon_Type, "NoIcon", (long) QSystemTrayIcon::NoIcon))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Information", (long) QSystemTrayIcon::Information))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Warning", (long) QSystemTrayIcon::Warning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX],
        &Sbk_QSystemTrayIcon_Type, "Critical", (long) QSystemTrayIcon::Critical))
        return ;
    // Register converter for enum 'QSystemTrayIcon::MessageIcon'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX],
            QSystemTrayIcon_MessageIcon_CppToPython_QSystemTrayIcon_MessageIcon);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QSystemTrayIcon_MessageIcon_PythonToCpp_QSystemTrayIcon_MessageIcon,
            is_QSystemTrayIcon_MessageIcon_PythonToCpp_QSystemTrayIcon_MessageIcon_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QSYSTEMTRAYICON_MESSAGEICON_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QSystemTrayIcon::MessageIcon");
        Shiboken::Conversions::registerConverterName(converter, "MessageIcon");
    }
    // End of 'MessageIcon' enum.

    PySide::Signal::registerSignals(&Sbk_QSystemTrayIcon_Type, &::QSystemTrayIcon::staticMetaObject);

    qRegisterMetaType< ::QSystemTrayIcon::ActivationReason >("QSystemTrayIcon::ActivationReason");
    qRegisterMetaType< ::QSystemTrayIcon::MessageIcon >("QSystemTrayIcon::MessageIcon");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QSystemTrayIcon_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QSystemTrayIcon_Type, &::QSystemTrayIcon::staticMetaObject, sizeof(::QSystemTrayIcon));
}
