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
#include "pyside_qtscript_python.h"

#include "qscriptengine_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qdatetime.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qregexp.h>
#include <qscriptclass.h>
#include <qscriptcontext.h>
#include <qscriptengine.h>
#include <qscriptengineagent.h>
#include <qscriptprogram.h>
#include <qscriptstring.h>
#include <qscriptvalue.h>
#include <qthread.h>


// Native ---------------------------------------------------------

QScriptEngineWrapper::QScriptEngineWrapper() : QScriptEngine() {
    // ... middle
}

QScriptEngineWrapper::QScriptEngineWrapper(QObject * parent) : QScriptEngine(parent) {
    // ... middle
}

void QScriptEngineWrapper::childEvent(QChildEvent * arg__1)
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

void QScriptEngineWrapper::connectNotify(const char * signal)
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

void QScriptEngineWrapper::customEvent(QEvent * arg__1)
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

void QScriptEngineWrapper::disconnectNotify(const char * signal)
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

bool QScriptEngineWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngine.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QScriptEngineWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QScriptEngine.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QScriptEngineWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* QScriptEngineWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QScriptEngine::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QScriptEngineWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QScriptEngine::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QScriptEngineWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QScriptEngineWrapper* >(this));
        return QScriptEngine::qt_metacast(_clname);
}

QScriptEngineWrapper::~QScriptEngineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QScriptEngine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char** argNames = 0;
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QScriptEngine >()))
        return -1;

    ::QScriptEngineWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "QScriptEngine", 0, 1, &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: QScriptEngine()
    // 1: QScriptEngine(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QScriptEngine()
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 1; // QScriptEngine(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngine_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QScriptEngine()
        {

            if (!PyErr_Occurred()) {
                // QScriptEngine()
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QScriptEngineWrapper();
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QScriptEngineWrapper();
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
            break;
        }
        case 1: // QScriptEngine(QObject * parent)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QScriptEngine(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QScriptEngineWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QScriptEngineWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QScriptEngine >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QScriptEngine_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 0))
        return -1;


    return 1;

    Sbk_QScriptEngine_Init_TypeError:
        const char* overloads[] = {"", "PySide.QtCore.QObject", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine", overloads);
        return -1;
}

static PyObject* Sbk_QScriptEngineFunc_abortEvaluation(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.abortEvaluation(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:abortEvaluation", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: abortEvaluation(QScriptValue)
    if (numArgs == 0) {
        overloadId = 0; // abortEvaluation(QScriptValue)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        overloadId = 0; // abortEvaluation(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_abortEvaluation_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "result");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.abortEvaluation(): got multiple values for keyword argument 'result'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0]))))
                    goto Sbk_QScriptEngineFunc_abortEvaluation_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QScriptValue cppArg0_local = QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // abortEvaluation(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->abortEvaluation(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_abortEvaluation_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue = QScriptValue()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.abortEvaluation", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_agent(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // agent()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptEngineAgent * cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->agent();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_availableExtensions(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // availableExtensions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->availableExtensions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_canEvaluate(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: canEvaluate(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // canEvaluate(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_canEvaluate_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // canEvaluate(QString)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->canEvaluate(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_canEvaluate_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.canEvaluate", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_clearExceptions(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearExceptions()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->clearExceptions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QScriptEngineFunc_collectGarbage(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // collectGarbage()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->collectGarbage();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QScriptEngineFunc_currentContext(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentContext()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptContext * cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->currentContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_defaultPrototype(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: defaultPrototype(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // defaultPrototype(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_defaultPrototype_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // defaultPrototype(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->defaultPrototype(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_defaultPrototype_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.defaultPrototype", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_evaluate(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.evaluate(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.evaluate(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:evaluate", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: evaluate(QScriptProgram)
    // 1: evaluate(QString,QString,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // evaluate(QString,QString,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // evaluate(QString,QString,int)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                overloadId = 1; // evaluate(QString,QString,int)
            }
        }
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], (pyArgs[0])))) {
        overloadId = 0; // evaluate(QScriptProgram)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_evaluate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // evaluate(const QScriptProgram & program)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptProgram cppArg0_local = ::QScriptProgram();
            ::QScriptProgram* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTPROGRAM_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // evaluate(QScriptProgram)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->evaluate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // evaluate(const QString & program, const QString & fileName, int lineNumber)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "fileName");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.evaluate(): got multiple values for keyword argument 'fileName'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_QScriptEngineFunc_evaluate_TypeError;
                }
                value = PyDict_GetItemString(kwds, "lineNumber");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.evaluate(): got multiple values for keyword argument 'lineNumber'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                        goto Sbk_QScriptEngineFunc_evaluate_TypeError;
                }
            }
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QString();
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2 = 1;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // evaluate(QString,QString,int)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->evaluate(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_evaluate_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptProgram", "unicode, unicode = QString(), int = 1", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.evaluate", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_globalObject(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // globalObject()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->globalObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_hasUncaughtException(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // hasUncaughtException()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->hasUncaughtException();
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

static PyObject* Sbk_QScriptEngineFunc_importExtension(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: importExtension(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // importExtension(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_importExtension_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // importExtension(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->importExtension(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_importExtension_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.importExtension", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_importedExtensions(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // importedExtensions()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->importedExtensions();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_installTranslatorFunctions(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.installTranslatorFunctions(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:installTranslatorFunctions", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: installTranslatorFunctions(QScriptValue)
    if (numArgs == 0) {
        overloadId = 0; // installTranslatorFunctions(QScriptValue)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))) {
        overloadId = 0; // installTranslatorFunctions(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_installTranslatorFunctions_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "object");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.installTranslatorFunctions(): got multiple values for keyword argument 'object'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0]))))
                    goto Sbk_QScriptEngineFunc_installTranslatorFunctions_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QScriptValue cppArg0_local = QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (pythonToCpp[0]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
            pythonToCpp[0](pyArgs[0], &cppArg0_local);
        else
            pythonToCpp[0](pyArgs[0], &cppArg0);
        }

        if (!PyErr_Occurred()) {
            // installTranslatorFunctions(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->installTranslatorFunctions(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_installTranslatorFunctions_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue = QScriptValue()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.installTranslatorFunctions", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_isEvaluating(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isEvaluating()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            bool cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->isEvaluating();
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

static PyObject* Sbk_QScriptEngineFunc_newActivationObject(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newActivationObject()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->newActivationObject();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_newArray(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newArray(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|O:newArray", &(pyArgs[0])))
        return 0;


    // Overloaded function decisor
    // 0: newArray(uint)
    if (numArgs == 0) {
        overloadId = 0; // newArray(uint)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0])))) {
        overloadId = 0; // newArray(uint)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newArray_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "length");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newArray(): got multiple values for keyword argument 'length'.");
                return 0;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<uint>(), (pyArgs[0]))))
                    goto Sbk_QScriptEngineFunc_newArray_TypeError;
            }
        }
        uint cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // newArray(uint)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->newArray(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newArray_TypeError:
        const char* overloads[] = {"unsigned int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newArray", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newDate(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: newDate(QDateTime)
    // 1: newDate(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 1; // newDate(double)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], (pyArg)))) {
        overloadId = 0; // newDate(QDateTime)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newDate_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // newDate(const QDateTime & value)
        {
            if (!Shiboken::Object::isValid(pyArg))
                return 0;
            ::QDateTime cppArg0_local = ::QDateTime();
            ::QDateTime* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QDATETIME_IDX], pythonToCpp))
                pythonToCpp(pyArg, &cppArg0_local);
            else
                pythonToCpp(pyArg, &cppArg0);


            if (!PyErr_Occurred()) {
                // newDate(QDateTime)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newDate(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // newDate(double value)
        {
            double cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // newDate(double)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newDate(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newDate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QDateTime", "float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.newDate", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newObject(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newObject(): too many arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:newObject", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: newObject()
    // 1: newObject(QScriptClass*,QScriptValue)
    if (numArgs == 0) {
        overloadId = 0; // newObject()
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCLASS_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // newObject(QScriptClass*,QScriptValue)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
            overloadId = 1; // newObject(QScriptClass*,QScriptValue)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newObject_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // newObject()
        {

            if (!PyErr_Occurred()) {
                // newObject()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newObject();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // newObject(QScriptClass * scriptClass, const QScriptValue & data)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "data");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newObject(): got multiple values for keyword argument 'data'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1]))))
                        goto Sbk_QScriptEngineFunc_newObject_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptClass* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QScriptValue cppArg1_local = QScriptValue();
            ::QScriptValue* cppArg1 = &cppArg1_local;
            if (pythonToCpp[1]) {
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
                pythonToCpp[1](pyArgs[1], &cppArg1_local);
            else
                pythonToCpp[1](pyArgs[1], &cppArg1);
            }

            if (!PyErr_Occurred()) {
                // newObject(QScriptClass*,QScriptValue)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newObject(cppArg0, *cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newObject_TypeError:
        const char* overloads[] = {"", "PySide.QtScript.QScriptClass, PySide.QtScript.QScriptValue = QScriptValue()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newQMetaObject(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQMetaObject(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQMetaObject(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:newQMetaObject", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: newQMetaObject(const QMetaObject*,QScriptValue)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QMETAOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // newQMetaObject(const QMetaObject*,QScriptValue)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
            overloadId = 0; // newQMetaObject(const QMetaObject*,QScriptValue)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newQMetaObject_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "ctor");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQMetaObject(): got multiple values for keyword argument 'ctor'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1]))))
                    goto Sbk_QScriptEngineFunc_newQMetaObject_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::QMetaObject* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QScriptValue cppArg1_local = QScriptValue();
        ::QScriptValue* cppArg1 = &cppArg1_local;
        if (pythonToCpp[1]) {
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);
        }

        if (!PyErr_Occurred()) {
            // newQMetaObject(const QMetaObject*,QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->newQMetaObject(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newQMetaObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QMetaObject, PySide.QtScript.QScriptValue = QScriptValue()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newQMetaObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newQObject(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:newQObject", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: newQObject(QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
    // 1: newQObject(QScriptValue,QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 1; // newQObject(QScriptValue,QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX]), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // newQObject(QScriptValue,QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), (pyArgs[3])))) {
                overloadId = 1; // newQObject(QScriptValue,QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // newQObject(QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // newQObject(QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), (pyArgs[2])))) {
                overloadId = 0; // newQObject(QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newQObject_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // newQObject(QObject * object, QScriptEngine::ValueOwnership ownership, const QFlags<QScriptEngine::QObjectWrapOption> & options)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "ownership");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): got multiple values for keyword argument 'ownership'.");
                    return 0;
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX]), (pyArgs[1]))))
                        goto Sbk_QScriptEngineFunc_newQObject_TypeError;
                }
                value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), (pyArgs[2]))))
                        goto Sbk_QScriptEngineFunc_newQObject_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QObject* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QScriptEngine::ValueOwnership cppArg1 = QScriptEngine::QtOwnership;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QFlags<QScriptEngine::QObjectWrapOption> cppArg2 = QFlags<QScriptEngine::QObjectWrapOption> (0);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // newQObject(QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newQObject(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // newQObject(const QScriptValue & scriptObject, QObject * qtObject, QScriptEngine::ValueOwnership ownership, const QFlags<QScriptEngine::QObjectWrapOption> & options)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "ownership");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): got multiple values for keyword argument 'ownership'.");
                    return 0;
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX]), (pyArgs[2]))))
                        goto Sbk_QScriptEngineFunc_newQObject_TypeError;
                }
                value = PyDict_GetItemString(kwds, "options");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtScript.QScriptEngine.newQObject(): got multiple values for keyword argument 'options'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), (pyArgs[3]))))
                        goto Sbk_QScriptEngineFunc_newQObject_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptValue cppArg0_local = ::QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!Shiboken::Object::isValid(pyArgs[1]))
                return 0;
            ::QObject* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QScriptEngine::ValueOwnership cppArg2 = QScriptEngine::QtOwnership;
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QFlags<QScriptEngine::QObjectWrapOption> cppArg3 = QFlags<QScriptEngine::QObjectWrapOption> (0);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // newQObject(QScriptValue,QObject*,QScriptEngine::ValueOwnership,QFlags<QScriptEngine::QObjectWrapOption>)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newQObject(*cppArg0, cppArg1, cppArg2, cppArg3);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newQObject_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject, PySide.QtScript.QScriptEngine.ValueOwnership = QtOwnership, PySide.QtScript.QScriptEngine.QObjectWrapOptions = 0", "PySide.QtScript.QScriptValue, PySide.QtCore.QObject, PySide.QtScript.QScriptEngine.ValueOwnership = QtOwnership, PySide.QtScript.QScriptEngine.QObjectWrapOptions = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newQObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newRegExp(PyObject* self, PyObject* args)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "newRegExp", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: newRegExp(QRegExp)
    // 1: newRegExp(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 1; // newRegExp(QString,QString)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], (pyArgs[0])))) {
        overloadId = 0; // newRegExp(QRegExp)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newRegExp_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // newRegExp(const QRegExp & regexp)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QRegExp cppArg0_local = ::QRegExp();
            ::QRegExp* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QREGEXP_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);


            if (!PyErr_Occurred()) {
                // newRegExp(QRegExp)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newRegExp(*cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // newRegExp(const QString & pattern, const QString & flags)
        {
            ::QString cppArg0 = ::QString();
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = ::QString();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // newRegExp(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newRegExp(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newRegExp_TypeError:
        const char* overloads[] = {"PySide.QtCore.QRegExp", "unicode, unicode", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newRegExp", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_newVariant(PyObject* self, PyObject* args)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "newVariant", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: newVariant(QScriptValue,QVariant)
    // 1: newVariant(QVariant)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[1])))) {
        overloadId = 0; // newVariant(QScriptValue,QVariant)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QVARIANT_IDX], (pyArgs[0])))) {
        overloadId = 1; // newVariant(QVariant)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_newVariant_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // newVariant(const QScriptValue & object, const QVariant & value)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::QScriptValue cppArg0_local = ::QScriptValue();
            ::QScriptValue* cppArg0 = &cppArg0_local;
            if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[0]))
                pythonToCpp[0](pyArgs[0], &cppArg0_local);
            else
                pythonToCpp[0](pyArgs[0], &cppArg0);

            ::QVariant cppArg1 = ::QVariant();
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // newVariant(QScriptValue,QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newVariant(*cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
        case 1: // newVariant(const QVariant & value)
        {
            ::QVariant cppArg0 = ::QVariant();
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // newVariant(QVariant)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QScriptValue cppResult = cppSelf->newVariant(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_newVariant_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue, QVariant", "QVariant", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.newVariant", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_nullValue(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // nullValue()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->nullValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_objectById(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: objectById(qint64)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qint64>(), (pyArg)))) {
        overloadId = 0; // objectById(qint64)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_objectById_TypeError;

    // Call function/method
    {
        qint64 cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // objectById(qint64)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->objectById(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_objectById_TypeError:
        const char* overloads[] = {"long long", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.objectById", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_popContext(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // popContext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->popContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QScriptEngineFunc_processEventsInterval(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // processEventsInterval()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->processEventsInterval();
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

static PyObject* Sbk_QScriptEngineFunc_pushContext(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pushContext()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptContext * cppResult = cppSelf->pushContext();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTCONTEXT_IDX], cppResult);
            Shiboken::Object::setParent(self, pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_reportAdditionalMemoryCost(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: reportAdditionalMemoryCost(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // reportAdditionalMemoryCost(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_reportAdditionalMemoryCost_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // reportAdditionalMemoryCost(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->reportAdditionalMemoryCost(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_reportAdditionalMemoryCost_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.reportAdditionalMemoryCost", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_setAgent(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setAgent(QScriptEngineAgent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINEAGENT_IDX], (pyArg)))) {
        overloadId = 0; // setAgent(QScriptEngineAgent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_setAgent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptEngineAgent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAgent(QScriptEngineAgent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setAgent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_setAgent_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptEngineAgent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.setAgent", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_setDefaultPrototype(PyObject* self, PyObject* args)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDefaultPrototype", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setDefaultPrototype(int,QScriptValue)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArgs[1])))) {
        overloadId = 0; // setDefaultPrototype(int,QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_setDefaultPrototype_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::QScriptValue cppArg1_local = ::QScriptValue();
        ::QScriptValue* cppArg1 = &cppArg1_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp[1]))
            pythonToCpp[1](pyArgs[1], &cppArg1_local);
        else
            pythonToCpp[1](pyArgs[1], &cppArg1);


        if (!PyErr_Occurred()) {
            // setDefaultPrototype(int,QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDefaultPrototype(cppArg0, *cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_setDefaultPrototype_TypeError:
        const char* overloads[] = {"int, PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtScript.QScriptEngine.setDefaultPrototype", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_setGlobalObject(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setGlobalObject(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // setGlobalObject(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_setGlobalObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setGlobalObject(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setGlobalObject(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_setGlobalObject_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.setGlobalObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_setProcessEventsInterval(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setProcessEventsInterval(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setProcessEventsInterval(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_setProcessEventsInterval_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProcessEventsInterval(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setProcessEventsInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QScriptEngineFunc_setProcessEventsInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.setProcessEventsInterval", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_toObject(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toObject(QScriptValue)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], (pyArg)))) {
        overloadId = 0; // toObject(QScriptValue)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_toObject_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QScriptValue cppArg0_local = ::QScriptValue();
        ::QScriptValue* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // toObject(QScriptValue)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->toObject(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_toObject_TypeError:
        const char* overloads[] = {"PySide.QtScript.QScriptValue", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.toObject", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_toStringHandle(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: toStringHandle(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // toStringHandle(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QScriptEngineFunc_toStringHandle_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // toStringHandle(QString)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptString cppResult = cppSelf->toStringHandle(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QScriptEngineFunc_toStringHandle_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtScript.QScriptEngine.toStringHandle", overloads);
        return 0;
}

static PyObject* Sbk_QScriptEngineFunc_uncaughtException(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uncaughtException()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->uncaughtException();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_uncaughtExceptionBacktrace(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uncaughtExceptionBacktrace()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QStringList cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->uncaughtExceptionBacktrace();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QScriptEngineFunc_uncaughtExceptionLineNumber(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // uncaughtExceptionLineNumber()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QScriptEngine*>(cppSelf)->uncaughtExceptionLineNumber();
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

static PyObject* Sbk_QScriptEngineFunc_undefinedValue(PyObject* self)
{
    ::QScriptEngine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QScriptEngine*)Shiboken::Conversions::cppPointer(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // undefinedValue()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QScriptValue cppResult = cppSelf->undefinedValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtScriptTypes[SBK_QSCRIPTVALUE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyMethodDef Sbk_QScriptEngine_methods[] = {
    {"abortEvaluation", (PyCFunction)Sbk_QScriptEngineFunc_abortEvaluation, METH_VARARGS|METH_KEYWORDS},
    {"agent", (PyCFunction)Sbk_QScriptEngineFunc_agent, METH_NOARGS},
    {"availableExtensions", (PyCFunction)Sbk_QScriptEngineFunc_availableExtensions, METH_NOARGS},
    {"canEvaluate", (PyCFunction)Sbk_QScriptEngineFunc_canEvaluate, METH_O},
    {"clearExceptions", (PyCFunction)Sbk_QScriptEngineFunc_clearExceptions, METH_NOARGS},
    {"collectGarbage", (PyCFunction)Sbk_QScriptEngineFunc_collectGarbage, METH_NOARGS},
    {"currentContext", (PyCFunction)Sbk_QScriptEngineFunc_currentContext, METH_NOARGS},
    {"defaultPrototype", (PyCFunction)Sbk_QScriptEngineFunc_defaultPrototype, METH_O},
    {"evaluate", (PyCFunction)Sbk_QScriptEngineFunc_evaluate, METH_VARARGS|METH_KEYWORDS},
    {"globalObject", (PyCFunction)Sbk_QScriptEngineFunc_globalObject, METH_NOARGS},
    {"hasUncaughtException", (PyCFunction)Sbk_QScriptEngineFunc_hasUncaughtException, METH_NOARGS},
    {"importExtension", (PyCFunction)Sbk_QScriptEngineFunc_importExtension, METH_O},
    {"importedExtensions", (PyCFunction)Sbk_QScriptEngineFunc_importedExtensions, METH_NOARGS},
    {"installTranslatorFunctions", (PyCFunction)Sbk_QScriptEngineFunc_installTranslatorFunctions, METH_VARARGS|METH_KEYWORDS},
    {"isEvaluating", (PyCFunction)Sbk_QScriptEngineFunc_isEvaluating, METH_NOARGS},
    {"newActivationObject", (PyCFunction)Sbk_QScriptEngineFunc_newActivationObject, METH_NOARGS},
    {"newArray", (PyCFunction)Sbk_QScriptEngineFunc_newArray, METH_VARARGS|METH_KEYWORDS},
    {"newDate", (PyCFunction)Sbk_QScriptEngineFunc_newDate, METH_O},
    {"newObject", (PyCFunction)Sbk_QScriptEngineFunc_newObject, METH_VARARGS|METH_KEYWORDS},
    {"newQMetaObject", (PyCFunction)Sbk_QScriptEngineFunc_newQMetaObject, METH_VARARGS|METH_KEYWORDS},
    {"newQObject", (PyCFunction)Sbk_QScriptEngineFunc_newQObject, METH_VARARGS|METH_KEYWORDS},
    {"newRegExp", (PyCFunction)Sbk_QScriptEngineFunc_newRegExp, METH_VARARGS},
    {"newVariant", (PyCFunction)Sbk_QScriptEngineFunc_newVariant, METH_VARARGS},
    {"nullValue", (PyCFunction)Sbk_QScriptEngineFunc_nullValue, METH_NOARGS},
    {"objectById", (PyCFunction)Sbk_QScriptEngineFunc_objectById, METH_O},
    {"popContext", (PyCFunction)Sbk_QScriptEngineFunc_popContext, METH_NOARGS},
    {"processEventsInterval", (PyCFunction)Sbk_QScriptEngineFunc_processEventsInterval, METH_NOARGS},
    {"pushContext", (PyCFunction)Sbk_QScriptEngineFunc_pushContext, METH_NOARGS},
    {"reportAdditionalMemoryCost", (PyCFunction)Sbk_QScriptEngineFunc_reportAdditionalMemoryCost, METH_O},
    {"setAgent", (PyCFunction)Sbk_QScriptEngineFunc_setAgent, METH_O},
    {"setDefaultPrototype", (PyCFunction)Sbk_QScriptEngineFunc_setDefaultPrototype, METH_VARARGS},
    {"setGlobalObject", (PyCFunction)Sbk_QScriptEngineFunc_setGlobalObject, METH_O},
    {"setProcessEventsInterval", (PyCFunction)Sbk_QScriptEngineFunc_setProcessEventsInterval, METH_O},
    {"toObject", (PyCFunction)Sbk_QScriptEngineFunc_toObject, METH_O},
    {"toStringHandle", (PyCFunction)Sbk_QScriptEngineFunc_toStringHandle, METH_O},
    {"uncaughtException", (PyCFunction)Sbk_QScriptEngineFunc_uncaughtException, METH_NOARGS},
    {"uncaughtExceptionBacktrace", (PyCFunction)Sbk_QScriptEngineFunc_uncaughtExceptionBacktrace, METH_NOARGS},
    {"uncaughtExceptionLineNumber", (PyCFunction)Sbk_QScriptEngineFunc_uncaughtExceptionLineNumber, METH_NOARGS},
    {"undefinedValue", (PyCFunction)Sbk_QScriptEngineFunc_undefinedValue, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QScriptEngine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QScriptEngine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QScriptEngine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtScript.QScriptEngine",
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
    /*tp_traverse*/         Sbk_QScriptEngine_traverse,
    /*tp_clear*/            Sbk_QScriptEngine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QScriptEngine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QScriptEngine_Init,
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

static void* Sbk_QScriptEngine_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QScriptEngine*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}

PyObject* SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___and__(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine::QObjectWrapOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyLong_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyInt_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___or__(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine::QObjectWrapOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyLong_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyInt_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___xor__(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine::QObjectWrapOptions cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyLong_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyLong_AsLong(pyArg);
#else
    cppSelf = (::QScriptEngine::QObjectWrapOptions)PyInt_AsLong(self);
    cppArg = (QScriptEngine::QObjectWrapOptions)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), &cppResult);
}

PyObject* SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___invert__(PyObject* self, PyObject* pyArg)
{
    ::QScriptEngine::QObjectWrapOptions cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), self, &cppSelf);
    ::QScriptEngine::QObjectWrapOptions cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), &cppResult);
}

static PyObject* SbkPySide_QtScript_QScriptEngine_QObjectWrapOption_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkPySide_QtScript_QScriptEngine_QObjectWrapOption__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkPySide_QtScript_QScriptEngine_QObjectWrapOption_as_number = {
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
    /*nb_nonzero*/              SbkPySide_QtScript_QScriptEngine_QObjectWrapOption__nonzero,
    /*nb_invert*/               (unaryfunc)SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___and__,
    /*nb_xor*/                  (binaryfunc)SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___xor__,
    /*nb_or*/                   (binaryfunc)SbkPySide_QtScript_QScriptEngine_QObjectWrapOption___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkPySide_QtScript_QScriptEngine_QObjectWrapOption_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkPySide_QtScript_QScriptEngine_QObjectWrapOption_long,
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
static void QScriptEngine_ValueOwnership_PythonToCpp_QScriptEngine_ValueOwnership(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngine::ValueOwnership*)cppOut) = (::QScriptEngine::ValueOwnership) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngine_ValueOwnership_PythonToCpp_QScriptEngine_ValueOwnership_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX]))
        return QScriptEngine_ValueOwnership_PythonToCpp_QScriptEngine_ValueOwnership;
    return 0;
}
static PyObject* QScriptEngine_ValueOwnership_CppToPython_QScriptEngine_ValueOwnership(const void* cppIn) {
    int castCppIn = *((::QScriptEngine::ValueOwnership*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX], castCppIn);

}

static void QScriptEngine_QObjectWrapOption_PythonToCpp_QScriptEngine_QObjectWrapOption(PyObject* pyIn, void* cppOut) {
    *((::QScriptEngine::QObjectWrapOption*)cppOut) = (::QScriptEngine::QObjectWrapOption) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QScriptEngine_QObjectWrapOption_PythonToCpp_QScriptEngine_QObjectWrapOption_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX]))
        return QScriptEngine_QObjectWrapOption_PythonToCpp_QScriptEngine_QObjectWrapOption;
    return 0;
}
static PyObject* QScriptEngine_QObjectWrapOption_CppToPython_QScriptEngine_QObjectWrapOption(const void* cppIn) {
    int castCppIn = *((::QScriptEngine::QObjectWrapOption*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX], castCppIn);

}

static void QFlags_QScriptEngine_QObjectWrapOption__PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptEngine::QObjectWrapOption>*)cppOut) = ::QFlags<QScriptEngine::QObjectWrapOption>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_QScriptEngine_QObjectWrapOption__PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]))
        return QFlags_QScriptEngine_QObjectWrapOption__PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_;
    return 0;
}
static PyObject* QFlags_QScriptEngine_QObjectWrapOption__CppToPython_QFlags_QScriptEngine_QObjectWrapOption_(const void* cppIn) {
    int castCppIn = *((::QFlags<QScriptEngine::QObjectWrapOption>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]));

}

static void QScriptEngine_QObjectWrapOption_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<QScriptEngine::QObjectWrapOption>*)cppOut) = ::QFlags<QScriptEngine::QObjectWrapOption>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_QScriptEngine_QObjectWrapOption_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX]))
        return QScriptEngine_QObjectWrapOption_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_;
    return 0;
}
static void number_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<QScriptEngine::QObjectWrapOption>*)cppOut) = ::QFlags<QScriptEngine::QObjectWrapOption>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_;
    return 0;
}
// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QScriptEngine_PythonToCpp_QScriptEngine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QScriptEngine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QScriptEngine_PythonToCpp_QScriptEngine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QScriptEngine_Type))
        return QScriptEngine_PythonToCpp_QScriptEngine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QScriptEngine_PTR_CppToPython_QScriptEngine(const void* cppIn) {
    return PySide::getWrapperForQObject((::QScriptEngine*)cppIn, &Sbk_QScriptEngine_Type);

}

void init_QScriptEngine(PyObject* module)
{
    SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QScriptEngine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QScriptEngine", "QScriptEngine*",
        &Sbk_QScriptEngine_Type, &Shiboken::callCppDestructor< ::QScriptEngine >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QScriptEngine_Type,
        QScriptEngine_PythonToCpp_QScriptEngine_PTR,
        is_QScriptEngine_PythonToCpp_QScriptEngine_PTR_Convertible,
        QScriptEngine_PTR_CppToPython_QScriptEngine);

    Shiboken::Conversions::registerConverterName(converter, "QScriptEngine");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngine*");
    Shiboken::Conversions::registerConverterName(converter, "QScriptEngine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QScriptEngineWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QScriptEngine_Type, &Sbk_QScriptEngine_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'ValueOwnership'.
    SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngine_Type,
        "ValueOwnership",
        "PySide.QtScript.QScriptEngine.ValueOwnership",
        "QScriptEngine::ValueOwnership");
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX],
        &Sbk_QScriptEngine_Type, "QtOwnership", (long) QScriptEngine::QtOwnership))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX],
        &Sbk_QScriptEngine_Type, "ScriptOwnership", (long) QScriptEngine::ScriptOwnership))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX],
        &Sbk_QScriptEngine_Type, "AutoOwnership", (long) QScriptEngine::AutoOwnership))
        return ;
    // Register converter for enum 'QScriptEngine::ValueOwnership'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX],
            QScriptEngine_ValueOwnership_CppToPython_QScriptEngine_ValueOwnership);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngine_ValueOwnership_PythonToCpp_QScriptEngine_ValueOwnership,
            is_QScriptEngine_ValueOwnership_PythonToCpp_QScriptEngine_ValueOwnership_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_VALUEOWNERSHIP_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngine::ValueOwnership");
        Shiboken::Conversions::registerConverterName(converter, "ValueOwnership");
    }
    // End of 'ValueOwnership' enum.

    // Initialization of enum 'QObjectWrapOption'.
    SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX] = PySide::QFlags::create("QObjectWrapOptions", &SbkPySide_QtScript_QScriptEngine_QObjectWrapOption_as_number);
    SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QScriptEngine_Type,
        "QObjectWrapOption",
        "PySide.QtScript.QScriptEngine.QObjectWrapOption",
        "QScriptEngine::QObjectWrapOption",
        SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX]);
    if (!SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeChildObjects", (long) QScriptEngine::ExcludeChildObjects))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeSuperClassMethods", (long) QScriptEngine::ExcludeSuperClassMethods))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeSuperClassProperties", (long) QScriptEngine::ExcludeSuperClassProperties))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeSuperClassContents", (long) QScriptEngine::ExcludeSuperClassContents))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "SkipMethodsInEnumeration", (long) QScriptEngine::SkipMethodsInEnumeration))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeDeleteLater", (long) QScriptEngine::ExcludeDeleteLater))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "ExcludeSlots", (long) QScriptEngine::ExcludeSlots))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "AutoCreateDynamicProperties", (long) QScriptEngine::AutoCreateDynamicProperties))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
        &Sbk_QScriptEngine_Type, "PreferExistingWrapperObject", (long) QScriptEngine::PreferExistingWrapperObject))
        return ;
    // Register converter for enum 'QScriptEngine::QObjectWrapOption'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX],
            QScriptEngine_QObjectWrapOption_CppToPython_QScriptEngine_QObjectWrapOption);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngine_QObjectWrapOption_PythonToCpp_QScriptEngine_QObjectWrapOption,
            is_QScriptEngine_QObjectWrapOption_PythonToCpp_QScriptEngine_QObjectWrapOption_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QSCRIPTENGINE_QOBJECTWRAPOPTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QScriptEngine::QObjectWrapOption");
        Shiboken::Conversions::registerConverterName(converter, "QObjectWrapOption");
    }
    // Register converter for flag 'QFlags<QScriptEngine::QObjectWrapOption>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX],
            QFlags_QScriptEngine_QObjectWrapOption__CppToPython_QFlags_QScriptEngine_QObjectWrapOption_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QScriptEngine_QObjectWrapOption_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_,
            is_QScriptEngine_QObjectWrapOption_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_QScriptEngine_QObjectWrapOption__PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_,
            is_QFlags_QScriptEngine_QObjectWrapOption__PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption_,
            is_number_PythonToCpp_QFlags_QScriptEngine_QObjectWrapOption__Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtScriptTypes[SBK_QFLAGS_QSCRIPTENGINE_QOBJECTWRAPOPTION__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<QScriptEngine::QObjectWrapOption>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QObjectWrapOption>");
    }
    // End of 'QObjectWrapOption' enum/flags.

    PySide::Signal::registerSignals(&Sbk_QScriptEngine_Type, &::QScriptEngine::staticMetaObject);

    qRegisterMetaType< ::QScriptEngine::ValueOwnership >("QScriptEngine::ValueOwnership");
    qRegisterMetaType< ::QScriptEngine::QObjectWrapOption >("QScriptEngine::QObjectWrapOption");
    qRegisterMetaType< ::QScriptEngine::QObjectWrapOptions >("QScriptEngine::QObjectWrapOptions");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QScriptEngine_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QScriptEngine_Type, &::QScriptEngine::staticMetaObject, sizeof(::QScriptEngine));
}
