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

#include "qdoublevalidator_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcoreevent.h>
#include <qlocale.h>
#include <qmetaobject.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qthread.h>
#include <qvalidator.h>


// Native ---------------------------------------------------------

QDoubleValidatorWrapper::QDoubleValidatorWrapper(QObject * parent) : QDoubleValidator(parent) {
    // ... middle
}

QDoubleValidatorWrapper::QDoubleValidatorWrapper(double bottom, double top, int decimals, QObject * parent) : QDoubleValidator(bottom, top, decimals, parent) {
    // ... middle
}

void QDoubleValidatorWrapper::childEvent(QChildEvent * arg__1)
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

void QDoubleValidatorWrapper::connectNotify(const char * signal)
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

void QDoubleValidatorWrapper::customEvent(QEvent * arg__1)
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

void QDoubleValidatorWrapper::disconnectNotify(const char * signal)
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

bool QDoubleValidatorWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDoubleValidator.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool QDoubleValidatorWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "QDoubleValidator.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void QDoubleValidatorWrapper::fixup(QString & arg__1) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fixup"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QValidator::fixup(arg__1);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &arg__1)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }

}

void QDoubleValidatorWrapper::setRange(double bottom, double top, int decimals)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "setRange"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::QDoubleValidator::setRange(bottom, top, decimals);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(ddi)",
        bottom,
        top,
        decimals
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QDoubleValidatorWrapper::timerEvent(QTimerEvent * arg__1)
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

QValidator::State QDoubleValidatorWrapper::validate(QString & arg__1, int & arg__2) const
{

    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ((::QValidator::State)0);
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "validate"));
    if (pyOverride.isNull()) {

        gil.release();
        return this->::QDoubleValidator::validate(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(NN)",
        Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &arg__1),
        Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &arg__2)
    ));


    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ((::QValidator::State)0);
    }
    // Begin code injection

    // TEMPLATE - validator_conversionrule - START
    QValidator::State cppResult;

    if (PySequence_Check(pyResult)) {
    Shiboken::AutoDecRef seq(PySequence_Fast(pyResult, 0));
    int size = PySequence_Fast_GET_SIZE(seq.object());

    if (size > 1) {
        if (Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(seq.object(), 1)))
            Shiboken::Conversions::pythonToCppCopy(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(seq.object(), 1), &(arg__1));
        else
            qWarning("QDoubleValidator::validate: Second tuple element is not convertible to unicode.");
    }

    if (size > 2) {
        if (Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2)))
            Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PySequence_Fast_GET_ITEM(seq.object(), 2), &(arg__2));
        else
            qWarning("QDoubleValidator::validate: Second tuple element is not convertible to int.");
    }
    pyResult = PySequence_Fast_GET_ITEM(seq.object(), 0);
    Py_INCREF(pyResult); // we need to incref, because "pyResult = ..." will decref the tuple and the tuple will be decrefed again at the end of this scope.
    }

    // check retrun value
    if (Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), pyResult)) {
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), pyResult, &(cppResult));
    } else {
    PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.",
                "QValidator.validate",
                "PySide.QtGui.QValidator.State, (PySide.QtGui.QValidator.State,), (PySide.QtGui.QValidator.State, unicode) or (PySide.QtGui.QValidator.State, unicode, int)",
                pyResult->ob_type->tp_name);
    return QValidator::State();
    }
    // TEMPLATE - validator_conversionrule - END

    // End of code injection

    return cppResult;
}

const QMetaObject* QDoubleValidatorWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return QDoubleValidator::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int QDoubleValidatorWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = QDoubleValidator::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* QDoubleValidatorWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< QDoubleValidatorWrapper* >(this));
        return QDoubleValidator::qt_metacast(_clname);
}

QDoubleValidatorWrapper::~QDoubleValidatorWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QDoubleValidator_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::QDoubleValidator >()))
        return -1;

    ::QDoubleValidatorWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2)
        goto Sbk_QDoubleValidator_Init_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:QDoubleValidator", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: QDoubleValidator(QObject*)
    // 1: QDoubleValidator(double,double,int,QObject*)
    if (numArgs == 0) {
        overloadId = 0; // QDoubleValidator(QObject*)
    } else if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 1; // QDoubleValidator(double,double,int,QObject*)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3])))) {
            overloadId = 1; // QDoubleValidator(double,double,int,QObject*)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // QDoubleValidator(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidator_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // QDoubleValidator(QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDoubleValidator(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                        goto Sbk_QDoubleValidator_Init_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::QObject* cppArg0 = 0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // QDoubleValidator(QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDoubleValidatorWrapper(cppArg0);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDoubleValidatorWrapper(cppArg0);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[0], self);
            }
            break;
        }
        case 1: // QDoubleValidator(double bottom, double top, int decimals, QObject * parent)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDoubleValidator(): got multiple values for keyword argument 'parent'.");
                    return -1;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[3]))))
                        goto Sbk_QDoubleValidator_Init_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            if (!Shiboken::Object::isValid(pyArgs[3]))
                return -1;
            ::QObject* cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // QDoubleValidator(double,double,int,QObject*)
                void* addr = PySide::nextQObjectMemoryAddr();
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                if (addr) {
                    cptr = new (addr) ::QDoubleValidatorWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                    PySide::setNextQObjectMemoryAddr(0);
                } else {
                    cptr = new ::QDoubleValidatorWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
                }

                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                Shiboken::Object::setParent(pyArgs[3], self);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::QDoubleValidator >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QDoubleValidator_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_QDoubleValidator_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", "float, float, int, PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDoubleValidator", overloads);
        return -1;
}

static PyObject* Sbk_QDoubleValidatorFunc_bottom(PyObject* self)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottom()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = const_cast<const ::QDoubleValidator*>(cppSelf)->bottom();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDoubleValidatorFunc_decimals(PyObject* self)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // decimals()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            int cppResult = const_cast<const ::QDoubleValidator*>(cppSelf)->decimals();
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

static PyObject* Sbk_QDoubleValidatorFunc_notation(PyObject* self)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // notation()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QDoubleValidator::Notation cppResult = const_cast<const ::QDoubleValidator*>(cppSelf)->notation();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDoubleValidatorFunc_setBottom(PyObject* self, PyObject* pyArg)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setBottom(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // setBottom(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_setBottom_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBottom(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setBottom(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDoubleValidatorFunc_setBottom_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDoubleValidator.setBottom", overloads);
        return 0;
}

static PyObject* Sbk_QDoubleValidatorFunc_setDecimals(PyObject* self, PyObject* pyArg)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setDecimals(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setDecimals(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_setDecimals_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDecimals(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setDecimals(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDoubleValidatorFunc_setDecimals_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDoubleValidator.setDecimals", overloads);
        return 0;
}

static PyObject* Sbk_QDoubleValidatorFunc_setNotation(PyObject* self, PyObject* pyArg)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setNotation(QDoubleValidator::Notation)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX]), (pyArg)))) {
        overloadId = 0; // setNotation(QDoubleValidator::Notation)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_setNotation_TypeError;

    // Call function/method
    {
        ::QDoubleValidator::Notation cppArg0 = ((::QDoubleValidator::Notation)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setNotation(QDoubleValidator::Notation)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setNotation(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDoubleValidatorFunc_setNotation_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDoubleValidator.Notation", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDoubleValidator.setNotation", overloads);
        return 0;
}

static PyObject* Sbk_QDoubleValidatorFunc_setRange(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDoubleValidator.setRange(): too many arguments");
        return 0;
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDoubleValidator.setRange(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:setRange", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: setRange(double,double,int)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setRange(double,double,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            overloadId = 0; // setRange(double,double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_setRange_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "decimals");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "PySide.QtGui.QDoubleValidator.setRange(): got multiple values for keyword argument 'decimals'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_QDoubleValidatorFunc_setRange_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setRange(double,double,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDoubleValidator::setRange(cppArg0, cppArg1, cppArg2) : cppSelf->setRange(cppArg0, cppArg1, cppArg2);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDoubleValidatorFunc_setRange_TypeError:
        const char* overloads[] = {"float, float, int = 0", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDoubleValidator.setRange", overloads);
        return 0;
}

static PyObject* Sbk_QDoubleValidatorFunc_setTop(PyObject* self, PyObject* pyArg)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setTop(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // setTop(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_setTop_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setTop(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setTop(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QDoubleValidatorFunc_setTop_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.QtGui.QDoubleValidator.setTop", overloads);
        return 0;
}

static PyObject* Sbk_QDoubleValidatorFunc_top(PyObject* self)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // top()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = const_cast<const ::QDoubleValidator*>(cppSelf)->top();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QDoubleValidatorFunc_validate(PyObject* self, PyObject* args)
{
    ::QDoubleValidator* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::QDoubleValidator*)Shiboken::Conversions::cppPointer(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "validate", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: validate(QString&,int&)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // validate(QString&,int&)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QDoubleValidatorFunc_validate_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // validate(QString&,int&)const


            // Begin code injection

            // TEMPLATE - return_tuple_QValidator_QString_int - START
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            QValidator::State retval_ = QValidator::State((Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::QDoubleValidator::validate(cppArg0, cppArg1) : cppSelf->validate(cppArg0, cppArg1)));
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]), &retval_));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppArg0));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppArg1));
            // TEMPLATE - return_tuple_QValidator_QString_int - END

            // End of code injection
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QDoubleValidatorFunc_validate_TypeError:
        const char* overloads[] = {"PySide.QtCore.QString, PySide.QtCore.int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.QtGui.QDoubleValidator.validate", overloads);
        return 0;
}

static PyMethodDef Sbk_QDoubleValidator_methods[] = {
    {"bottom", (PyCFunction)Sbk_QDoubleValidatorFunc_bottom, METH_NOARGS},
    {"decimals", (PyCFunction)Sbk_QDoubleValidatorFunc_decimals, METH_NOARGS},
    {"notation", (PyCFunction)Sbk_QDoubleValidatorFunc_notation, METH_NOARGS},
    {"setBottom", (PyCFunction)Sbk_QDoubleValidatorFunc_setBottom, METH_O},
    {"setDecimals", (PyCFunction)Sbk_QDoubleValidatorFunc_setDecimals, METH_O},
    {"setNotation", (PyCFunction)Sbk_QDoubleValidatorFunc_setNotation, METH_O},
    {"setRange", (PyCFunction)Sbk_QDoubleValidatorFunc_setRange, METH_VARARGS|METH_KEYWORDS},
    {"setTop", (PyCFunction)Sbk_QDoubleValidatorFunc_setTop, METH_O},
    {"top", (PyCFunction)Sbk_QDoubleValidatorFunc_top, METH_NOARGS},
    {"validate", (PyCFunction)Sbk_QDoubleValidatorFunc_validate, METH_VARARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_QDoubleValidator_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_QDoubleValidator_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QDoubleValidator_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.QtGui.QDoubleValidator",
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
    /*tp_traverse*/         Sbk_QDoubleValidator_traverse,
    /*tp_clear*/            Sbk_QDoubleValidator_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QDoubleValidator_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QDoubleValidator_Init,
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

static void* Sbk_QDoubleValidator_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::QDoubleValidator*>(reinterpret_cast< ::QObject*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void QDoubleValidator_Notation_PythonToCpp_QDoubleValidator_Notation(PyObject* pyIn, void* cppOut) {
    *((::QDoubleValidator::Notation*)cppOut) = (::QDoubleValidator::Notation) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_QDoubleValidator_Notation_PythonToCpp_QDoubleValidator_Notation_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX]))
        return QDoubleValidator_Notation_PythonToCpp_QDoubleValidator_Notation;
    return 0;
}
static PyObject* QDoubleValidator_Notation_CppToPython_QDoubleValidator_Notation(const void* cppIn) {
    int castCppIn = *((::QDoubleValidator::Notation*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void QDoubleValidator_PythonToCpp_QDoubleValidator_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_QDoubleValidator_Type, pyIn, cppOut);
}
static PythonToCppFunc is_QDoubleValidator_PythonToCpp_QDoubleValidator_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_QDoubleValidator_Type))
        return QDoubleValidator_PythonToCpp_QDoubleValidator_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* QDoubleValidator_PTR_CppToPython_QDoubleValidator(const void* cppIn) {
    return PySide::getWrapperForQObject((::QDoubleValidator*)cppIn, &Sbk_QDoubleValidator_Type);

}

void init_QDoubleValidator(PyObject* module)
{
    SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QDoubleValidator_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "QDoubleValidator", "QDoubleValidator*",
        &Sbk_QDoubleValidator_Type, &Shiboken::callCppDestructor< ::QDoubleValidator >, (SbkObjectType*)SbkPySide_QtGuiTypes[SBK_QVALIDATOR_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_QDoubleValidator_Type,
        QDoubleValidator_PythonToCpp_QDoubleValidator_PTR,
        is_QDoubleValidator_PythonToCpp_QDoubleValidator_PTR_Convertible,
        QDoubleValidator_PTR_CppToPython_QDoubleValidator);

    Shiboken::Conversions::registerConverterName(converter, "QDoubleValidator");
    Shiboken::Conversions::registerConverterName(converter, "QDoubleValidator*");
    Shiboken::Conversions::registerConverterName(converter, "QDoubleValidator&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDoubleValidator).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::QDoubleValidatorWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_QDoubleValidator_Type, &Sbk_QDoubleValidator_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'Notation'.
    SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_QDoubleValidator_Type,
        "Notation",
        "PySide.QtGui.QDoubleValidator.Notation",
        "QDoubleValidator::Notation");
    if (!SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX],
        &Sbk_QDoubleValidator_Type, "StandardNotation", (long) QDoubleValidator::StandardNotation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX],
        &Sbk_QDoubleValidator_Type, "ScientificNotation", (long) QDoubleValidator::ScientificNotation))
        return ;
    // Register converter for enum 'QDoubleValidator::Notation'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX],
            QDoubleValidator_Notation_CppToPython_QDoubleValidator_Notation);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QDoubleValidator_Notation_PythonToCpp_QDoubleValidator_Notation,
            is_QDoubleValidator_Notation_PythonToCpp_QDoubleValidator_Notation_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QDoubleValidator::Notation");
        Shiboken::Conversions::registerConverterName(converter, "Notation");
    }
    // End of 'Notation' enum.

    PySide::Signal::registerSignals(&Sbk_QDoubleValidator_Type, &::QDoubleValidator::staticMetaObject);

    qRegisterMetaType< ::QDoubleValidator::Notation >("QDoubleValidator::Notation");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_QDoubleValidator_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_QDoubleValidator_Type, &::QDoubleValidator::staticMetaObject, sizeof(::QDoubleValidator));
}
