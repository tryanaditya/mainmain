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
#include "pyside_qtscripttools_python.h"

#include "qscriptenginedebugger_wrapper.h"

// Extra includes
#include <QList>
#include <QScriptEngine>
#include <qaction.h>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qmainwindow.h>
#include <qmenu.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qscriptengine.h>
#include <qscriptenginedebugger.h>
#include <qthread.h>
#include <qtoolbar.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QScriptEngineDebuggerWrapper::QScriptEngineDebuggerWrapper(QObject * parent) : QScriptEngineDebugger(parent) {
    // ... middle
}

void QScriptEngineDebuggerWrapper::childEvent(QChildEvent * arg__1)
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

void QScriptEngineDebuggerWrapper::connectNotify(const char * signal)
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

void QScriptEngineDebuggerWrapper::customEvent(QEvent * arg__1)
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

void QScriptEngineDebuggerWrapper::disconnectNotify(const char * signal)
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

bool QScriptEngineDebuggerWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngineDebugger.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QScriptEngineDebuggerWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngineDebugger.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QScriptEngineDebuggerWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QScriptEngineDebuggerWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QScriptEngineDebugger::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QScriptEngineDebuggerWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QScriptEngineDebugger::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QScriptEngineDebuggerWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QScriptEngineDebuggerWrapper* >(this));
        return QScriptEngineDebugger::qt_metacast(_clname);
}

QScriptEngineDebuggerWrapper::~QScriptEngineDebuggerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptEngineDebugger_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptEngineDebugger >()))
        return -1;

    ::QScriptEngineDebuggerWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QScriptEngineDebugger", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptEngineDebugger(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QScriptEngineDebugger(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QScriptEngineDebugger(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebugger_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScriptTools.QScriptEngineDebugger(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_QScriptEngineDebugger_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // QScriptEngineDebugger(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QScriptEngineDebuggerWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QScriptEngineDebuggerWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptEngineDebugger >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptEngineDebugger_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QScriptEngineDebugger_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScriptTools.QScriptEngineDebugger", overloads);
        return -1;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_action(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: action(QScriptEngineDebugger::DebuggerAction)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX]), (pyArg)))) {
        overloadId = 0; // action(QScriptEngineDebugger::DebuggerAction)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_action_TypeError;

    // Call function/method
    {
        ::QScriptEngineDebugger::DebuggerAction cppArg0 = ((::QScriptEngineDebugger::DebuggerAction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // action(QScriptEngineDebugger::DebuggerAction)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QAction * cppResult = const_cast<const ::QScriptEngineDebugger*>(cppSelf)->action(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QACTION_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineDebuggerFunc_action_TypeError:
        const char* overloads[] = {"PySide.QtScriptTools.QScriptEngineDebugger.DebuggerAction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScriptTools.QScriptEngineDebugger.action", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_attachTo(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: attachTo(QScriptEngine*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (pyArg)))) {
        overloadId = 0; // attachTo(QScriptEngine*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_attachTo_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptEngine* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // attachTo(QScriptEngine*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->attachTo(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineDebuggerFunc_attachTo_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngine", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScriptTools.QScriptEngineDebugger.attachTo", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_autoShowStandardWindow(PyObject* self)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoShowStandardWindow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptEngineDebugger*>(cppSelf)->autoShowStandardWindow();
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

static PyObject* Sbk_QScriptEngineDebuggerFunc_createStandardMenu(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardMenu(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:createStandardMenu", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: createStandardMenu(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // createStandardMenu(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // createStandardMenu(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_createStandardMenu_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardMenu(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QScriptEngineDebuggerFunc_createStandardMenu_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // createStandardMenu(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMenu * cppResult = cppSelf->createStandardMenu(cppArg0);
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

    Sbk_QScriptEngineDebuggerFunc_createStandardMenu_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardMenu", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_createStandardToolBar(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardToolBar(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:createStandardToolBar", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: createStandardToolBar(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // createStandardToolBar(QWidget*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 0; // createStandardToolBar(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_createStandardToolBar_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardToolBar(): got multiple values for keyword argument 'parent'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0]))))
                    goto Sbk_QScriptEngineDebuggerFunc_createStandardToolBar_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QWidget* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // createStandardToolBar(QWidget*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QToolBar * cppResult = cppSelf->createStandardToolBar(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QTOOLBAR_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineDebuggerFunc_createStandardToolBar_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScriptTools.QScriptEngineDebugger.createStandardToolBar", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_setAutoShowStandardWindow(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoShowStandardWindow(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoShowStandardWindow(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_setAutoShowStandardWindow_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAutoShowStandardWindow(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAutoShowStandardWindow(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineDebuggerFunc_setAutoShowStandardWindow_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScriptTools.QScriptEngineDebugger.setAutoShowStandardWindow", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_standardWindow(PyObject* self)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // standardWindow()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QMainWindow * cppResult = const_cast<const ::QScriptEngineDebugger*>(cppSelf)->standardWindow();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QMAINWINDOW_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_state(PyObject* self)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngineDebugger::DebuggerState cppResult = const_cast<const ::QScriptEngineDebugger*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineDebuggerFunc_widget(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngineDebugger* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngineDebugger*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: widget(QScriptEngineDebugger::DebuggerWidget)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX]), (pyArg)))) {
        overloadId = 0; // widget(QScriptEngineDebugger::DebuggerWidget)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineDebuggerFunc_widget_TypeError;

    // Call function/method
    {
        ::QScriptEngineDebugger::DebuggerWidget cppArg0 = ((::QScriptEngineDebugger::DebuggerWidget)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // widget(QScriptEngineDebugger::DebuggerWidget)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QScriptEngineDebugger*>(cppSelf)->widget(cppArg0);
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

    Sbk_QScriptEngineDebuggerFunc_widget_TypeError:
        const char* overloads[] = {"PySide.QtScriptTools.QScriptEngineDebugger.DebuggerWidget", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScriptTools.QScriptEngineDebugger.widget", overloads);
        return 0;
}

static PyMethodDef Sbk_QScriptEngineDebugger_methods[] = {
    {"action", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_action, METH_O},
    {"attachTo", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_attachTo, METH_O},
    {"autoShowStandardWindow", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_autoShowStandardWindow, METH_NOARGS},
    {"createStandardMenu", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_createStandardMenu, METH_VARARGS|METH_KEYWORDS},
    {"createStandardToolBar", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_createStandardToolBar, METH_VARARGS|METH_KEYWORDS},
    {"setAutoShowStandardWindow", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_setAutoShowStandardWindow, METH_O},
    {"standardWindow", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_standardWindow, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_state, METH_NOARGS},
    {"widget", (PyCFunction)Sbk_QScriptEngineDebuggerFunc_widget, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QScriptEngineDebugger_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptEngineDebugger_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QScriptEngineDebugger_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScriptTools.QScriptEngineDebugger",
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
    /*tp_traverse*/         Sbk_QScriptEngineDebugger_traverse,
    /*tp_clear*/            Sbk_QScriptEngineDebugger_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptEngineDebugger_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptEngineDebugger_Init,
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

static void* Sbk_QScriptEngineDebugger_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QScriptEngineDebugger*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QScriptEngineDebugger_DebuggerWidget_PythonToCpp_QScriptEngineDebugger_DebuggerWidget(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngineDebugger::DebuggerWidget*)cppOut) = (::QScriptEngineDebugger::DebuggerWidget) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngineDebugger_DebuggerWidget_PythonToCpp_QScriptEngineDebugger_DebuggerWidget_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX]))
        return QScriptEngineDebugger_DebuggerWidget_PythonToCpp_QScriptEngineDebugger_DebuggerWidget;
    return 0;
}
static PyObject* QScriptEngineDebugger_DebuggerWidget_CppToPython_QScriptEngineDebugger_DebuggerWidget(const void* cppIn) {
    int castCppIn = *((::QScriptEngineDebugger::DebuggerWidget*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX], castCppIn);

}

static void QScriptEngineDebugger_DebuggerAction_PythonToCpp_QScriptEngineDebugger_DebuggerAction(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngineDebugger::DebuggerAction*)cppOut) = (::QScriptEngineDebugger::DebuggerAction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngineDebugger_DebuggerAction_PythonToCpp_QScriptEngineDebugger_DebuggerAction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX]))
        return QScriptEngineDebugger_DebuggerAction_PythonToCpp_QScriptEngineDebugger_DebuggerAction;
    return 0;
}
static PyObject* QScriptEngineDebugger_DebuggerAction_CppToPython_QScriptEngineDebugger_DebuggerAction(const void* cppIn) {
    int castCppIn = *((::QScriptEngineDebugger::DebuggerAction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX], castCppIn);

}

static void QScriptEngineDebugger_DebuggerState_PythonToCpp_QScriptEngineDebugger_DebuggerState(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngineDebugger::DebuggerState*)cppOut) = (::QScriptEngineDebugger::DebuggerState) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngineDebugger_DebuggerState_PythonToCpp_QScriptEngineDebugger_DebuggerState_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX]))
        return QScriptEngineDebugger_DebuggerState_PythonToCpp_QScriptEngineDebugger_DebuggerState;
    return 0;
}
static PyObject* QScriptEngineDebugger_DebuggerState_CppToPython_QScriptEngineDebugger_DebuggerState(const void* cppIn) {
    int castCppIn = *((::QScriptEngineDebugger::DebuggerState*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptEngineDebugger_PythonToCpp_QScriptEngineDebugger_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptEngineDebugger_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptEngineDebugger_PythonToCpp_QScriptEngineDebugger_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptEngineDebugger_Type))
        return QScriptEngineDebugger_PythonToCpp_QScriptEngineDebugger_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptEngineDebugger_PTR_CppToPython_QScriptEngineDebugger(const void* cppIn) {
    return PySide::getWrapperForQObject((::QScriptEngineDebugger*)cppIn, &Sbk_QScriptEngineDebugger_Type);

}

void init_QScriptEngineDebugger(PyObject* module)
{
    SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptEngineDebugger_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptEngineDebugger", "QScriptEngineDebugger*",
        &Sbk_QScriptEngineDebugger_Type, &Shiboken::callCppDestructor< ::QScriptEngineDebugger >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptEngineDebugger_Type,
        QScriptEngineDebugger_PythonToCpp_QScriptEngineDebugger_PTR,
        is_QScriptEngineDebugger_PythonToCpp_QScriptEngineDebugger_PTR_Convertible,
        QScriptEngineDebugger_PTR_CppToPython_QScriptEngineDebugger);

    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngineDebugger).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngineDebuggerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QScriptEngineDebugger_Type, &Sbk_QScriptEngineDebugger_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'DebuggerWidget'.
    SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngineDebugger_Type,
        "DebuggerWidget",
        "PySide.QtScriptTools.QScriptEngineDebugger.DebuggerWidget",
        "QScriptEngineDebugger::DebuggerWidget");
    if (!SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ConsoleWidget", (long) QScriptEngineDebugger::ConsoleWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "StackWidget", (long) QScriptEngineDebugger::StackWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ScriptsWidget", (long) QScriptEngineDebugger::ScriptsWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "LocalsWidget", (long) QScriptEngineDebugger::LocalsWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "CodeWidget", (long) QScriptEngineDebugger::CodeWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "CodeFinderWidget", (long) QScriptEngineDebugger::CodeFinderWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "BreakpointsWidget", (long) QScriptEngineDebugger::BreakpointsWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "DebugOutputWidget", (long) QScriptEngineDebugger::DebugOutputWidget))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ErrorLogWidget", (long) QScriptEngineDebugger::ErrorLogWidget))
        return ;
    // Register converter for enum 'QScriptEngineDebugger::DebuggerWidget'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX],
            QScriptEngineDebugger_DebuggerWidget_CppToPython_QScriptEngineDebugger_DebuggerWidget);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngineDebugger_DebuggerWidget_PythonToCpp_QScriptEngineDebugger_DebuggerWidget,
            is_QScriptEngineDebugger_DebuggerWidget_PythonToCpp_QScriptEngineDebugger_DebuggerWidget_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERWIDGET_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger::DebuggerWidget");
        Shiboken::Conversions::registerConverterName(converter, "DebuggerWidget");
    }
    // End of 'DebuggerWidget' enum.

    // Initialization of enum 'DebuggerAction'.
    SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngineDebugger_Type,
        "DebuggerAction",
        "PySide.QtScriptTools.QScriptEngineDebugger.DebuggerAction",
        "QScriptEngineDebugger::DebuggerAction");
    if (!SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "InterruptAction", (long) QScriptEngineDebugger::InterruptAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ContinueAction", (long) QScriptEngineDebugger::ContinueAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "StepIntoAction", (long) QScriptEngineDebugger::StepIntoAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "StepOverAction", (long) QScriptEngineDebugger::StepOverAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "StepOutAction", (long) QScriptEngineDebugger::StepOutAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "RunToCursorAction", (long) QScriptEngineDebugger::RunToCursorAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "RunToNewScriptAction", (long) QScriptEngineDebugger::RunToNewScriptAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ToggleBreakpointAction", (long) QScriptEngineDebugger::ToggleBreakpointAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ClearDebugOutputAction", (long) QScriptEngineDebugger::ClearDebugOutputAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ClearErrorLogAction", (long) QScriptEngineDebugger::ClearErrorLogAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "ClearConsoleAction", (long) QScriptEngineDebugger::ClearConsoleAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "FindInScriptAction", (long) QScriptEngineDebugger::FindInScriptAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "FindNextInScriptAction", (long) QScriptEngineDebugger::FindNextInScriptAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "FindPreviousInScriptAction", (long) QScriptEngineDebugger::FindPreviousInScriptAction))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
        &Sbk_QScriptEngineDebugger_Type, "GoToLineAction", (long) QScriptEngineDebugger::GoToLineAction))
        return ;
    // Register converter for enum 'QScriptEngineDebugger::DebuggerAction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX],
            QScriptEngineDebugger_DebuggerAction_CppToPython_QScriptEngineDebugger_DebuggerAction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngineDebugger_DebuggerAction_PythonToCpp_QScriptEngineDebugger_DebuggerAction,
            is_QScriptEngineDebugger_DebuggerAction_PythonToCpp_QScriptEngineDebugger_DebuggerAction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERACTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger::DebuggerAction");
        Shiboken::Conversions::registerConverterName(converter, "DebuggerAction");
    }
    // End of 'DebuggerAction' enum.

    // Initialization of enum 'DebuggerState'.
    SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngineDebugger_Type,
        "DebuggerState",
        "PySide.QtScriptTools.QScriptEngineDebugger.DebuggerState",
        "QScriptEngineDebugger::DebuggerState");
    if (!SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX],
        &Sbk_QScriptEngineDebugger_Type, "RunningState", (long) QScriptEngineDebugger::RunningState))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX],
        &Sbk_QScriptEngineDebugger_Type, "SuspendedState", (long) QScriptEngineDebugger::SuspendedState))
        return ;
    // Register converter for enum 'QScriptEngineDebugger::DebuggerState'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX],
            QScriptEngineDebugger_DebuggerState_CppToPython_QScriptEngineDebugger_DebuggerState);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngineDebugger_DebuggerState_PythonToCpp_QScriptEngineDebugger_DebuggerState,
            is_QScriptEngineDebugger_DebuggerState_PythonToCpp_QScriptEngineDebugger_DebuggerState_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptToolsTypes[SBK_QSCRIPTENGINEDEBUGGER_DEBUGGERSTATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngineDebugger::DebuggerState");
        Shiboken::Conversions::registerConverterName(converter, "DebuggerState");
    }
    // End of 'DebuggerState' enum.

    PySide::Signal::registerSignals(&Sbk_QScriptEngineDebugger_Type, &::QScriptEngineDebugger::staticMetaObject);

    qRegisterMetaType< ::QScriptEngineDebugger::DebuggerWidget >("QScriptEngineDebugger::DebuggerWidget");
    qRegisterMetaType< ::QScriptEngineDebugger::DebuggerAction >("QScriptEngineDebugger::DebuggerAction");
    qRegisterMetaType< ::QScriptEngineDebugger::DebuggerState >("QScriptEngineDebugger::DebuggerState");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QScriptEngineDebugger_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QScriptEngineDebugger_Type, &::QScriptEngineDebugger::staticMetaObject, sizeof(::QScriptEngineDebugger));
}
