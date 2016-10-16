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

#include "qshortcut_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qkeysequence.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QShortcutWrapper::QShortcutWrapper(QWidget * parent) : QShortcut(parent) {
    // ... middle
}

QShortcutWrapper::QShortcutWrapper(const QKeySequence & key, QWidget * parent, const char * member, const char * ambiguousMember, Qt::ShortcutContext context) : QShortcut(key, parent, member, ambiguousMember, context) {
    // ... middle
}

void QShortcutWrapper::childEvent(QChildEvent * arg__1)
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

void QShortcutWrapper::connectNotify(const char * signal)
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

void QShortcutWrapper::customEvent(QEvent * arg__1)
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

void QShortcutWrapper::disconnectNotify(const char * signal)
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

bool QShortcutWrapper::event(QEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((bool)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QShortcut::event(e);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEVENT_IDX], e)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QShortcut.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QShortcutWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QShortcut.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QShortcutWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QShortcutWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QShortcut::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QShortcutWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QShortcut::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QShortcutWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QShortcutWrapper* >(this));
        return QShortcut::qt_metacast(_clname);
}

QShortcutWrapper::~QShortcutWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QShortcut_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"ambiguousMember", "arg__4", "context", "member"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QShortcut >()))
        return -1;

    ::QShortcutWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QShortcut(): not enough arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:QShortcut", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return -1;


    // Overloaded function decisor
    // 0: QShortcut(QKeySequence&,QWidget*,PyCallable*,Qt::ShortcutContext)
    // 1: QShortcut(QWidget*)
    // 2: QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
    if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[0])))) {
        overloadId = 1; // QShortcut(QWidget*)
    } else if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 2; // QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
        } else if (Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 2; // QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
            } else if (Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3])))) {
                if (numArgs == 4) {
                    overloadId = 2; // QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
                } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArgs[4])))) {
                    overloadId = 2; // QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
                }
            }
        } else if (PyCallable_Check(pyArgs[2])) {
            if (numArgs == 3) {
                overloadId = 0; // QShortcut(QKeySequence&,QWidget*,PyCallable*,Qt::ShortcutContext)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArgs[3])))) {
                overloadId = 0; // QShortcut(QKeySequence&,QWidget*,PyCallable*,Qt::ShortcutContext)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcut_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QShortcut(QKeySequence & arg__1, QWidget * arg__2, PyCallable * arg__3, Qt::ShortcutContext arg__4)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "arg__4");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QShortcut(): got multiple values for keyword argument 'arg__4'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArgs[3]))))
                        goto Sbk_QShortcut_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QKeySequence cppArg0_local = ::QKeySequence();
            ::QKeySequence* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            SBK_UNUSED(cppArg0)
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            SBK_UNUSED(cppArg1)
            ::Qt::ShortcutContext cppArg3 = Qt::WindowShortcut;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            SBK_UNUSED(cppArg3)

            if (!PyErr_Occurred()) {
                // QShortcut(QKeySequence&,QWidget*,PyCallable*,Qt::ShortcutContext)
                overloadId = 0;
                // Begin code injection

                cptr = new QShortcutWrapper(*cppArg0, cppArg1);

                // End of code injection

            }
            break;
        }
        case 1: // QShortcut(QWidget * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QWidget* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QShortcut(QWidget*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QShortcutWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QShortcutWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 2: // QShortcut(const QKeySequence & key, QWidget * parent, const char * member, const char * ambiguousMember, Qt::ShortcutContext context)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "member");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QShortcut(): got multiple values for keyword argument 'member'.");
                    return -1;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!Shiboken::String::check(pyArgs[2]) && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[2]))))
                        goto Sbk_QShortcut_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "ambiguousMember");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QShortcut(): got multiple values for keyword argument 'ambiguousMember'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!Shiboken::String::check(pyArgs[3]) && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<const char*>(), (pyArgs[3]))))
                        goto Sbk_QShortcut_Init_TypeError;
                }
                value = PyDict_GetItemString(kwds, "context");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QShortcut(): got multiple values for keyword argument 'context'.");
                    return -1;
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArgs[4]))))
                        goto Sbk_QShortcut_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QKeySequence cppArg0_local = ::QKeySequence();
            ::QKeySequence* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return -1;
            ::QWidget* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            const char* cppArg2 = 0;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            const char* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
            ::Qt::ShortcutContext cppArg4 = Qt::WindowShortcut;
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // QShortcut(QKeySequence,QWidget*,const char*,const char*,Qt::ShortcutContext)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QShortcutWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QShortcutWrapper(*cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[1], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QShortcut >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QShortcut_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 4))
        return -1;
    switch(overloadId) {
        case 0:
        {
            // Begin code injection

            Shiboken::AutoDecRef result(PyObject_CallMethod(self, "connect", "OsO", self, SIGNAL(activated()), pyArgs[3-1]));
            if (!result.isNull())
                Shiboken::Object::setParent(pyArgs[2-1], self);

            // End of code injection
        }
}


    return 1;

    Sbk_QShortcut_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence, PySide.QtGui.QWidget, callable, PySide.QtCore.Qt.ShortcutContext = Qt.WindowShortcut", "PySide.QtGui.QWidget", "PySide.QtGui.QKeySequence, PySide.QtGui.QWidget, " SBK_STR_NAME " = None, " SBK_STR_NAME " = None, PySide.QtCore.Qt.ShortcutContext = Qt.WindowShortcut", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QShortcut", overloads);
        return -1;
}

static PyObject* Sbk_QShortcutFunc_autoRepeat(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // autoRepeat()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QShortcut*>(cppSelf)->autoRepeat();
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

static PyObject* Sbk_QShortcutFunc_context(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // context()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Qt::ShortcutContext cppResult = cppSelf->context();
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

static PyObject* Sbk_QShortcutFunc_event(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
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
    if (overloadId == -1) goto Sbk_QShortcutFunc_event_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // event(QEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QShortcut::event(cppArg0) : cppSelf->event(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QShortcutFunc_event_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.event", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_id(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // id()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QShortcut*>(cppSelf)->id();
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

static PyObject* Sbk_QShortcutFunc_isEnabled(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEnabled()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QShortcut*>(cppSelf)->isEnabled();
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

static PyObject* Sbk_QShortcutFunc_key(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // key()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QKeySequence cppResult = const_cast<const ::QShortcut*>(cppSelf)->key();
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

static PyObject* Sbk_QShortcutFunc_parentWidget(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // parentWidget()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QWidget * cppResult = const_cast<const ::QShortcut*>(cppSelf)->parentWidget();
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

static PyObject* Sbk_QShortcutFunc_setAutoRepeat(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAutoRepeat(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAutoRepeat(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcutFunc_setAutoRepeat_TypeError;

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

    Sbk_QShortcutFunc_setAutoRepeat_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.setAutoRepeat", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_setContext(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setContext(Qt::ShortcutContext)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QT_SHORTCUTCONTEXT_IDX]), (pyArg)))) {
        overloadId = 0; // setContext(Qt::ShortcutContext)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcutFunc_setContext_TypeError;

    // Call function/method
    {
        ::Qt::ShortcutContext cppArg0 = ((::Qt::ShortcutContext)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setContext(Qt::ShortcutContext)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setContext(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QShortcutFunc_setContext_TypeError:
        const char* overloads[] = {"PySide.QtCore.Qt.ShortcutContext", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.setContext", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcutFunc_setEnabled_TypeError;

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

    Sbk_QShortcutFunc_setEnabled_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.setEnabled", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_setKey(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setKey(QKeySequence)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QKEYSEQUENCE_IDX], (pyArg)))) {
        overloadId = 0; // setKey(QKeySequence)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcutFunc_setKey_TypeError;

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
            // setKey(QKeySequence)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setKey(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QShortcutFunc_setKey_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeySequence", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.setKey", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_setWhatsThis(PyObject* self, PyObject* pyArg)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setWhatsThis(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setWhatsThis(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QShortcutFunc_setWhatsThis_TypeError;

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

    Sbk_QShortcutFunc_setWhatsThis_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QShortcut.setWhatsThis", overloads);
        return 0;
}

static PyObject* Sbk_QShortcutFunc_whatsThis(PyObject* self)
{
    ::QShortcut* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QShortcut*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // whatsThis()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QString cppResult = const_cast<const ::QShortcut*>(cppSelf)->whatsThis();
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

static PyMethodDef Sbk_QShortcut_methods[] = {
    {"autoRepeat", (PyCFunction)Sbk_QShortcutFunc_autoRepeat, METH_NOARGS},
    {"context", (PyCFunction)Sbk_QShortcutFunc_context, METH_NOARGS},
    {"event", (PyCFunction)Sbk_QShortcutFunc_event, METH_O},
    {"id", (PyCFunction)Sbk_QShortcutFunc_id, METH_NOARGS},
    {"isEnabled", (PyCFunction)Sbk_QShortcutFunc_isEnabled, METH_NOARGS},
    {"key", (PyCFunction)Sbk_QShortcutFunc_key, METH_NOARGS},
    {"parentWidget", (PyCFunction)Sbk_QShortcutFunc_parentWidget, METH_NOARGS},
    {"setAutoRepeat", (PyCFunction)Sbk_QShortcutFunc_setAutoRepeat, METH_O},
    {"setContext", (PyCFunction)Sbk_QShortcutFunc_setContext, METH_O},
    {"setEnabled", (PyCFunction)Sbk_QShortcutFunc_setEnabled, METH_O},
    {"setKey", (PyCFunction)Sbk_QShortcutFunc_setKey, METH_O},
    {"setWhatsThis", (PyCFunction)Sbk_QShortcutFunc_setWhatsThis, METH_O},
    {"whatsThis", (PyCFunction)Sbk_QShortcutFunc_whatsThis, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QShortcut_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QShortcut_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QShortcut_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QShortcut",
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
    /*tp_traverse*/         Sbk_QShortcut_traverse,
    /*tp_clear*/            Sbk_QShortcut_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QShortcut_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QShortcut_Init,
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

static void* Sbk_QShortcut_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QShortcut*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QShortcut_PythonToCpp_QShortcut_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QShortcut_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QShortcut_PythonToCpp_QShortcut_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QShortcut_Type))
        return QShortcut_PythonToCpp_QShortcut_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QShortcut_PTR_CppToPython_QShortcut(const void* cppIn) {
    return PySide::getWrapperForQObject((::QShortcut*)cppIn, &Sbk_QShortcut_Type);

}

void init_QShortcut(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QSHORTCUT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QShortcut_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QShortcut", "QShortcut*",
        &Sbk_QShortcut_Type, &Shiboken::callCppDestructor< ::QShortcut >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QShortcut_Type,
        QShortcut_PythonToCpp_QShortcut_PTR,
        is_QShortcut_PythonToCpp_QShortcut_PTR_Convertible,
        QShortcut_PTR_CppToPython_QShortcut);

    Shiboken::Conversions::registerConverterName(converter, "QShortcut");
    Shiboken::Conversions::registerConverterName(converter, "QShortcut*");
    Shiboken::Conversions::registerConverterName(converter, "QShortcut&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QShortcut).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QShortcutWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QShortcut_Type, &Sbk_QShortcut_typeDiscovery);

    PySide::Signal::registerSignals(&Sbk_QShortcut_Type, &::QShortcut::staticMetaObject);

    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QShortcut_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QShortcut_Type, &::QShortcut::staticMetaObject, sizeof(::QShortcut));
}
