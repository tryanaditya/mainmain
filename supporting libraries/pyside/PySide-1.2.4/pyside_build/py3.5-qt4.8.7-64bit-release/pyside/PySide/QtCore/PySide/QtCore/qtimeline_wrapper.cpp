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
#include "pyside_qtcore_python.h"

#include "qtimeline_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qeasingcurve.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qtimeline.h>


// Native ---------------------------------------------------------

QTimeLineWrapper::QTimeLineWrapper(int duration, QObject * parent) : QTimeLine(duration, parent) {
    // ... middle
}

void QTimeLineWrapper::childEvent(QChildEvent * arg__1)
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

void QTimeLineWrapper::connectNotify(const char * signal)
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

void QTimeLineWrapper::customEvent(QEvent * arg__1)
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

void QTimeLineWrapper::disconnectNotify(const char * signal)
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

bool QTimeLineWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTimeLine.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QTimeLineWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTimeLine.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QTimeLineWrapper::timerEvent(QTimerEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTimeLine::timerEvent(event);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], event)
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

qreal QTimeLineWrapper::valueForTime(int msec) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((qreal)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "valueForTime"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QTimeLine::valueForTime(msec);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(i)",
        msec
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((qreal)0);
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QTimeLine.valueForTime", "qreal", pyResult->ob_type->tp_name);
        return ((qreal)0);
    }
    qreal cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

const QMetaObject* QTimeLineWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QTimeLine::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QTimeLineWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QTimeLine::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QTimeLineWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QTimeLineWrapper* >(this));
        return QTimeLine::qt_metacast(_clname);
}

QTimeLineWrapper::~QTimeLineWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QTimeLine_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"duration", "parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QTimeLine >()))
        return -1;

    ::QTimeLineWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|OO:QTimeLine", &(pyArgs[0]), &(pyArgs[1])))
        return -1;


    // Overloaded function decisor
    // 0: QTimeLine(int,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QTimeLine(int,QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // QTimeLine(int,QObject*)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1])))) {
            overloadId = 0; // QTimeLine(int,QObject*)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLine_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "duration");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTimeLine(): got multiple values for keyword argument 'duration'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_QTimeLine_Init_TypeError;
            }
            value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtCore.QTimeLine(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[1]))))
                    goto Sbk_QTimeLine_Init_TypeError;
            }
        }
        int cppArg0 = 1000;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return -1;
        ::QObject* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // QTimeLine(int,QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::QTimeLineWrapper(cppArg0, cppArg1);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::QTimeLineWrapper(cppArg0, cppArg1);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[1], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QTimeLine >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QTimeLine_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 2))
        return -1;


    return 1;

    Sbk_QTimeLine_Init_TypeError:
        const char* overloads[] = {"int = 1000, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTimeLine", overloads);
        return -1;
}

static PyObject* Sbk_QTimeLineFunc_currentFrame(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->currentFrame();
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

static PyObject* Sbk_QTimeLineFunc_currentTime(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentTime()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->currentTime();
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

static PyObject* Sbk_QTimeLineFunc_currentValue(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // currentValue()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = const_cast<const ::QTimeLine*>(cppSelf)->currentValue();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeLineFunc_curveShape(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // curveShape()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTimeLine::CurveShape cppResult = const_cast<const ::QTimeLine*>(cppSelf)->curveShape();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeLineFunc_direction(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // direction()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTimeLine::Direction cppResult = const_cast<const ::QTimeLine*>(cppSelf)->direction();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeLineFunc_duration(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // duration()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->duration();
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

static PyObject* Sbk_QTimeLineFunc_easingCurve(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // easingCurve()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QEasingCurve cppResult = const_cast<const ::QTimeLine*>(cppSelf)->easingCurve();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeLineFunc_endFrame(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->endFrame();
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

static PyObject* Sbk_QTimeLineFunc_frameForTime(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: frameForTime(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // frameForTime(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_frameForTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // frameForTime(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->frameForTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeLineFunc_frameForTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.frameForTime", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_loopCount(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // loopCount()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->loopCount();
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

static PyObject* Sbk_QTimeLineFunc_resume(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resume()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->resume();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTimeLineFunc_setCurrentTime(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurrentTime(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentTime(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setCurrentTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentTime(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurrentTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setCurrentTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setCurrentTime", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setCurveShape(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setCurveShape(QTimeLine::CurveShape)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX]), (pyArg)))) {
        overloadId = 0; // setCurveShape(QTimeLine::CurveShape)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setCurveShape_TypeError;

    // Call function/method
    {
        ::QTimeLine::CurveShape cppArg0 = ((::QTimeLine::CurveShape)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurveShape(QTimeLine::CurveShape)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setCurveShape(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setCurveShape_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimeLine.CurveShape", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setCurveShape", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setDirection(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDirection(QTimeLine::Direction)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX]), (pyArg)))) {
        overloadId = 0; // setDirection(QTimeLine::Direction)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setDirection_TypeError;

    // Call function/method
    {
        ::QTimeLine::Direction cppArg0 = ((::QTimeLine::Direction)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDirection(QTimeLine::Direction)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDirection(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setDirection_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimeLine.Direction", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setDirection", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setDuration(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDuration(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDuration(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setDuration_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDuration(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDuration(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setDuration_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setDuration", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setEasingCurve(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEasingCurve(QEasingCurve)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], (pyArg)))) {
        overloadId = 0; // setEasingCurve(QEasingCurve)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setEasingCurve_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QEasingCurve cppArg0_local = ::QEasingCurve(((::QEasingCurve::Type)0));
        ::QEasingCurve* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QEASINGCURVE_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // setEasingCurve(QEasingCurve)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEasingCurve(*cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setEasingCurve_TypeError:
        const char* overloads[] = {"PySide.QtCore.QEasingCurve", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setEasingCurve", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setEndFrame(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setEndFrame(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setEndFrame(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setEndFrame_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEndFrame(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setEndFrame(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setEndFrame_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setEndFrame", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setFrameRange(PyObject* self, PyObject* args)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFrameRange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setFrameRange(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setFrameRange(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setFrameRange_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFrameRange(int,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFrameRange(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setFrameRange_TypeError:
        const char* overloads[] = {"int, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtCore.QTimeLine.setFrameRange", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setLoopCount(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setLoopCount(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setLoopCount(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setLoopCount_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLoopCount(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setLoopCount(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setLoopCount_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setLoopCount", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setPaused(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setPaused(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setPaused(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setPaused_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPaused(bool)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setPaused(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setPaused_TypeError:
        const char* overloads[] = {"bool", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setPaused", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setStartFrame(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setStartFrame(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setStartFrame(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setStartFrame_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setStartFrame(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setStartFrame(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setStartFrame_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setStartFrame", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_setUpdateInterval(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setUpdateInterval(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setUpdateInterval(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_setUpdateInterval_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setUpdateInterval(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setUpdateInterval(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_setUpdateInterval_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.setUpdateInterval", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_start(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // start()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->start();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTimeLineFunc_startFrame(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startFrame()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->startFrame();
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

static PyObject* Sbk_QTimeLineFunc_state(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // state()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QTimeLine::State cppResult = const_cast<const ::QTimeLine*>(cppSelf)->state();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QTimeLineFunc_stop(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // stop()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->stop();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTimeLineFunc_timerEvent(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timerEvent(QTimerEvent*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QTIMEREVENT_IDX], (pyArg)))) {
        overloadId = 0; // timerEvent(QTimerEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_timerEvent_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::QTimerEvent* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timerEvent(QTimerEvent*)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QTimeLine::timerEvent(cppArg0) : cppSelf->timerEvent(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QTimeLineFunc_timerEvent_TypeError:
        const char* overloads[] = {"PySide.QtCore.QTimerEvent", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.timerEvent", overloads);
        return 0;
}

static PyObject* Sbk_QTimeLineFunc_toggleDirection(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // toggleDirection()
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->toggleDirection();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QTimeLineFunc_updateInterval(PyObject* self)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // updateInterval()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QTimeLine*>(cppSelf)->updateInterval();
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

static PyObject* Sbk_QTimeLineFunc_valueForTime(PyObject* self, PyObject* pyArg)
{
    ::QTimeLine* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QTimeLine*)Shiboken::Conversions::cppPointer(SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: valueForTime(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // valueForTime(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QTimeLineFunc_valueForTime_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // valueForTime(int)const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            qreal cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::QTimeLine*>(cppSelf)->::QTimeLine::valueForTime(cppArg0) : const_cast<const ::QTimeLine*>(cppSelf)->valueForTime(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<qreal>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QTimeLineFunc_valueForTime_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtCore.QTimeLine.valueForTime", overloads);
        return 0;
}

static PyMethodDef Sbk_QTimeLine_methods[] = {
    {"currentFrame", (PyCFunction)Sbk_QTimeLineFunc_currentFrame, METH_NOARGS},
    {"currentTime", (PyCFunction)Sbk_QTimeLineFunc_currentTime, METH_NOARGS},
    {"currentValue", (PyCFunction)Sbk_QTimeLineFunc_currentValue, METH_NOARGS},
    {"curveShape", (PyCFunction)Sbk_QTimeLineFunc_curveShape, METH_NOARGS},
    {"direction", (PyCFunction)Sbk_QTimeLineFunc_direction, METH_NOARGS},
    {"duration", (PyCFunction)Sbk_QTimeLineFunc_duration, METH_NOARGS},
    {"easingCurve", (PyCFunction)Sbk_QTimeLineFunc_easingCurve, METH_NOARGS},
    {"endFrame", (PyCFunction)Sbk_QTimeLineFunc_endFrame, METH_NOARGS},
    {"frameForTime", (PyCFunction)Sbk_QTimeLineFunc_frameForTime, METH_O},
    {"loopCount", (PyCFunction)Sbk_QTimeLineFunc_loopCount, METH_NOARGS},
    {"resume", (PyCFunction)Sbk_QTimeLineFunc_resume, METH_NOARGS},
    {"setCurrentTime", (PyCFunction)Sbk_QTimeLineFunc_setCurrentTime, METH_O},
    {"setCurveShape", (PyCFunction)Sbk_QTimeLineFunc_setCurveShape, METH_O},
    {"setDirection", (PyCFunction)Sbk_QTimeLineFunc_setDirection, METH_O},
    {"setDuration", (PyCFunction)Sbk_QTimeLineFunc_setDuration, METH_O},
    {"setEasingCurve", (PyCFunction)Sbk_QTimeLineFunc_setEasingCurve, METH_O},
    {"setEndFrame", (PyCFunction)Sbk_QTimeLineFunc_setEndFrame, METH_O},
    {"setFrameRange", (PyCFunction)Sbk_QTimeLineFunc_setFrameRange, METH_VARARGS},
    {"setLoopCount", (PyCFunction)Sbk_QTimeLineFunc_setLoopCount, METH_O},
    {"setPaused", (PyCFunction)Sbk_QTimeLineFunc_setPaused, METH_O},
    {"setStartFrame", (PyCFunction)Sbk_QTimeLineFunc_setStartFrame, METH_O},
    {"setUpdateInterval", (PyCFunction)Sbk_QTimeLineFunc_setUpdateInterval, METH_O},
    {"start", (PyCFunction)Sbk_QTimeLineFunc_start, METH_NOARGS},
    {"startFrame", (PyCFunction)Sbk_QTimeLineFunc_startFrame, METH_NOARGS},
    {"state", (PyCFunction)Sbk_QTimeLineFunc_state, METH_NOARGS},
    {"stop", (PyCFunction)Sbk_QTimeLineFunc_stop, METH_NOARGS},
    {"timerEvent", (PyCFunction)Sbk_QTimeLineFunc_timerEvent, METH_O},
    {"toggleDirection", (PyCFunction)Sbk_QTimeLineFunc_toggleDirection, METH_NOARGS},
    {"updateInterval", (PyCFunction)Sbk_QTimeLineFunc_updateInterval, METH_NOARGS},
    {"valueForTime", (PyCFunction)Sbk_QTimeLineFunc_valueForTime, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QTimeLine_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QTimeLine_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QTimeLine_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtCore.QTimeLine",
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
    /*tp_traverse*/         Sbk_QTimeLine_traverse,
    /*tp_clear*/            Sbk_QTimeLine_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QTimeLine_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QTimeLine_Init,
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

static void* Sbk_QTimeLine_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QTimeLine*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QTimeLine_State_PythonToCpp_QTimeLine_State(PyObject* pyIn, void* cppOut) {
    *((::QTimeLine::State*)cppOut) = (::QTimeLine::State) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTimeLine_State_PythonToCpp_QTimeLine_State_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX]))
        return QTimeLine_State_PythonToCpp_QTimeLine_State;
    return 0;
}
static PyObject* QTimeLine_State_CppToPython_QTimeLine_State(const void* cppIn) {
    int castCppIn = *((::QTimeLine::State*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX], castCppIn);

}

static void QTimeLine_Direction_PythonToCpp_QTimeLine_Direction(PyObject* pyIn, void* cppOut) {
    *((::QTimeLine::Direction*)cppOut) = (::QTimeLine::Direction) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTimeLine_Direction_PythonToCpp_QTimeLine_Direction_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX]))
        return QTimeLine_Direction_PythonToCpp_QTimeLine_Direction;
    return 0;
}
static PyObject* QTimeLine_Direction_CppToPython_QTimeLine_Direction(const void* cppIn) {
    int castCppIn = *((::QTimeLine::Direction*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX], castCppIn);

}

static void QTimeLine_CurveShape_PythonToCpp_QTimeLine_CurveShape(PyObject* pyIn, void* cppOut) {
    *((::QTimeLine::CurveShape*)cppOut) = (::QTimeLine::CurveShape) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QTimeLine_CurveShape_PythonToCpp_QTimeLine_CurveShape_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX]))
        return QTimeLine_CurveShape_PythonToCpp_QTimeLine_CurveShape;
    return 0;
}
static PyObject* QTimeLine_CurveShape_CppToPython_QTimeLine_CurveShape(const void* cppIn) {
    int castCppIn = *((::QTimeLine::CurveShape*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QTimeLine_PythonToCpp_QTimeLine_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QTimeLine_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QTimeLine_PythonToCpp_QTimeLine_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QTimeLine_Type))
        return QTimeLine_PythonToCpp_QTimeLine_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QTimeLine_PTR_CppToPython_QTimeLine(const void* cppIn) {
    return PySide::getWrapperForQObject((::QTimeLine*)cppIn, &Sbk_QTimeLine_Type);

}

void init_QTimeLine(PyObject* module)
{
    SbkPySide_QtCoreTypes[SBK_QTIMELINE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QTimeLine_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QTimeLine", "QTimeLine*",
        &Sbk_QTimeLine_Type, &Shiboken::callCppDestructor< ::QTimeLine >, (SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QTimeLine_Type,
        QTimeLine_PythonToCpp_QTimeLine_PTR,
        is_QTimeLine_PythonToCpp_QTimeLine_PTR_Convertible,
        QTimeLine_PTR_CppToPython_QTimeLine);

    Shiboken::Conversions::registerConverterName(converter, "QTimeLine");
    Shiboken::Conversions::registerConverterName(converter, "QTimeLine*");
    Shiboken::Conversions::registerConverterName(converter, "QTimeLine&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTimeLine).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QTimeLineWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QTimeLine_Type, &Sbk_QTimeLine_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'State'.
    SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTimeLine_Type,
        "State",
        "PySide.QtCore.QTimeLine.State",
        "QTimeLine::State");
    if (!SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX],
        &Sbk_QTimeLine_Type, "NotRunning", (long) QTimeLine::NotRunning))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX],
        &Sbk_QTimeLine_Type, "Paused", (long) QTimeLine::Paused))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX],
        &Sbk_QTimeLine_Type, "Running", (long) QTimeLine::Running))
        return ;
    // Register converter for enum 'QTimeLine::State'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX],
            QTimeLine_State_CppToPython_QTimeLine_State);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTimeLine_State_PythonToCpp_QTimeLine_State,
            is_QTimeLine_State_PythonToCpp_QTimeLine_State_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_STATE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTimeLine::State");
        Shiboken::Conversions::registerConverterName(converter, "State");
    }
    // End of 'State' enum.

    // Initialization of enum 'Direction'.
    SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTimeLine_Type,
        "Direction",
        "PySide.QtCore.QTimeLine.Direction",
        "QTimeLine::Direction");
    if (!SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX],
        &Sbk_QTimeLine_Type, "Forward", (long) QTimeLine::Forward))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX],
        &Sbk_QTimeLine_Type, "Backward", (long) QTimeLine::Backward))
        return ;
    // Register converter for enum 'QTimeLine::Direction'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX],
            QTimeLine_Direction_CppToPython_QTimeLine_Direction);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTimeLine_Direction_PythonToCpp_QTimeLine_Direction,
            is_QTimeLine_Direction_PythonToCpp_QTimeLine_Direction_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_DIRECTION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTimeLine::Direction");
        Shiboken::Conversions::registerConverterName(converter, "Direction");
    }
    // End of 'Direction' enum.

    // Initialization of enum 'CurveShape'.
    SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QTimeLine_Type,
        "CurveShape",
        "PySide.QtCore.QTimeLine.CurveShape",
        "QTimeLine::CurveShape");
    if (!SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "EaseInCurve", (long) QTimeLine::EaseInCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "EaseOutCurve", (long) QTimeLine::EaseOutCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "EaseInOutCurve", (long) QTimeLine::EaseInOutCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "LinearCurve", (long) QTimeLine::LinearCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "SineCurve", (long) QTimeLine::SineCurve))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
        &Sbk_QTimeLine_Type, "CosineCurve", (long) QTimeLine::CosineCurve))
        return ;
    // Register converter for enum 'QTimeLine::CurveShape'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX],
            QTimeLine_CurveShape_CppToPython_QTimeLine_CurveShape);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QTimeLine_CurveShape_PythonToCpp_QTimeLine_CurveShape,
            is_QTimeLine_CurveShape_PythonToCpp_QTimeLine_CurveShape_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtCoreTypes[SBK_QTIMELINE_CURVESHAPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QTimeLine::CurveShape");
        Shiboken::Conversions::registerConverterName(converter, "CurveShape");
    }
    // End of 'CurveShape' enum.

    PySide::Signal::registerSignals(&Sbk_QTimeLine_Type, &::QTimeLine::staticMetaObject);

    qRegisterMetaType< ::QTimeLine::State >("QTimeLine::State");
    qRegisterMetaType< ::QTimeLine::Direction >("QTimeLine::Direction");
    qRegisterMetaType< ::QTimeLine::CurveShape >("QTimeLine::CurveShape");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QTimeLine_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QTimeLine_Type, &::QTimeLine::staticMetaObject, sizeof(::QTimeLine));
}
