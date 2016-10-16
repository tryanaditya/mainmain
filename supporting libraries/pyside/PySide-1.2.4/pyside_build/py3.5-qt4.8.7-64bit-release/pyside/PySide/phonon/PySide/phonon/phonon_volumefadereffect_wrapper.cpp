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
#include <set>
#include "pyside_phonon_python.h"

#include "phonon_volumefadereffect_wrapper.h"

// Extra includes
#include <QList>
#include <effectparameter.h>
#include <objectdescription.h>
#include <path.h>
#include <qcoreevent.h>
#include <qobject.h>
#include <qobjectdefs.h>

using namespace Phonon;

// Native ---------------------------------------------------------

VolumeFaderEffectWrapper::VolumeFaderEffectWrapper(QObject * parent) : Phonon::VolumeFaderEffect(parent) {
    // ... middle
}

void VolumeFaderEffectWrapper::childEvent(QChildEvent * arg__1)
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

void VolumeFaderEffectWrapper::connectNotify(const char * signal)
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

void VolumeFaderEffectWrapper::customEvent(QEvent * arg__1)
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

void VolumeFaderEffectWrapper::disconnectNotify(const char * signal)
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

bool VolumeFaderEffectWrapper::event(QEvent * arg__1)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VolumeFaderEffect.event", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 0));
    return cppResult;
}

bool VolumeFaderEffectWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "VolumeFaderEffect.eventFilter", "bool", pyResult->ob_type->tp_name);
        return ((bool)0);
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    if (invalidateArg2)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyArgs, 1));
    return cppResult;
}

void VolumeFaderEffectWrapper::timerEvent(QTimerEvent * arg__1)
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

const QMetaObject* VolumeFaderEffectWrapper::metaObject() const
{
    #if QT_VERSION >= 0x040700
    if (QObject::d_ptr->metaObject) return QObject::d_ptr->metaObject;
    #endif
    SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
    if (pySelf == NULL)
        return Phonon::VolumeFaderEffect::metaObject();
    return PySide::SignalManager::retriveMetaObject(reinterpret_cast<PyObject*>(pySelf));
}

int VolumeFaderEffectWrapper::qt_metacall(QMetaObject::Call call, int id, void** args)
{
    int result = Phonon::VolumeFaderEffect::qt_metacall(call, id, args);
    return result < 0 ? result : PySide::SignalManager::qt_metacall(this, call, id, args);
}

void* VolumeFaderEffectWrapper::qt_metacast(const char* _clname)
{
        if (!_clname) return 0;
        SbkObject* pySelf = Shiboken::BindingManager::instance().retrieveWrapper(this);
        if (pySelf && PySide::inherits(Py_TYPE(pySelf), _clname))
                return static_cast<void*>(const_cast< VolumeFaderEffectWrapper* >(this));
        return Phonon::VolumeFaderEffect::qt_metacast(_clname);
}

VolumeFaderEffectWrapper::~VolumeFaderEffectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Phonon_VolumeFaderEffect_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    const char* argNames[] = {"parent"};
    const QMetaObject* metaObject;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Phonon::VolumeFaderEffect >()))
        return -1;

    ::VolumeFaderEffectWrapper* cptr = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:VolumeFaderEffect", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: VolumeFaderEffect(QObject*)
    if (numArgs == 0) {
        overloadId = 0; // VolumeFaderEffect(QObject*)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0])))) {
        overloadId = 0; // VolumeFaderEffect(QObject*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffect_Init_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "parent");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "PySide.phonon.VolumeFaderEffect(): got multiple values for keyword argument 'parent'.");
                return -1;
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX], (pyArgs[0]))))
                    goto Sbk_Phonon_VolumeFaderEffect_Init_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return -1;
        ::QObject* cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // VolumeFaderEffect(QObject*)
            void* addr = PySide::nextQObjectMemoryAddr();
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            if (addr) {
                cptr = new (addr) ::VolumeFaderEffectWrapper(cppArg0);
                PySide::setNextQObjectMemoryAddr(0);
            } else {
                cptr = new ::VolumeFaderEffectWrapper(cppArg0);
            }

            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            Shiboken::Object::setParent(pyArgs[0], self);
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Phonon::VolumeFaderEffect >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Phonon_VolumeFaderEffect_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);

    // QObject setup
    PySide::Signal::updateSourceObject(self);
    metaObject = cptr->metaObject(); // <- init python qt properties
    if (kwds && !PySide::fillQtProperties(self, metaObject, kwds, argNames, 1))
        return -1;


    return 1;

    Sbk_Phonon_VolumeFaderEffect_Init_TypeError:
        const char* overloads[] = {"PySide.QtCore.QObject = None", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.VolumeFaderEffect", overloads);
        return -1;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_fadeCurve(PyObject* self)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // fadeCurve()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            Phonon::VolumeFaderEffect::FadeCurve cppResult = const_cast<const ::Phonon::VolumeFaderEffect*>(cppSelf)->fadeCurve();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_fadeIn(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fadeIn(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fadeIn(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_fadeIn_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fadeIn(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->fadeIn(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_fadeIn_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderEffect.fadeIn", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_fadeOut(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: fadeOut(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // fadeOut(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_fadeOut_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fadeOut(int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->fadeOut(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_fadeOut_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderEffect.fadeOut", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_fadeTo(PyObject* self, PyObject* args)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fadeTo", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: fadeTo(float,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // fadeTo(float,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_fadeTo_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // fadeTo(float,int)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->fadeTo(cppArg0, cppArg1);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_fadeTo_TypeError:
        const char* overloads[] = {"float, int", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PySide.phonon.VolumeFaderEffect.fadeTo", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_setFadeCurve(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]), (pyArg)))) {
        overloadId = 0; // setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_setFadeCurve_TypeError;

    // Call function/method
    {
        ::Phonon::VolumeFaderEffect::FadeCurve cppArg0 = ((::Phonon::VolumeFaderEffect::FadeCurve)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setFadeCurve(Phonon::VolumeFaderEffect::FadeCurve)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setFadeCurve(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_setFadeCurve_TypeError:
        const char* overloads[] = {"PySide.phonon.Phonon::VolumeFaderEffect.FadeCurve", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderEffect.setFadeCurve", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_setVolume(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVolume(float)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<float>(), (pyArg)))) {
        overloadId = 0; // setVolume(float)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_setVolume_TypeError;

    // Call function/method
    {
        float cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVolume(float)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVolume(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_setVolume_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderEffect.setVolume", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_setVolumeDecibel(PyObject* self, PyObject* pyArg)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: setVolumeDecibel(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // setVolumeDecibel(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Phonon_VolumeFaderEffectFunc_setVolumeDecibel_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVolumeDecibel(double)
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            cppSelf->setVolumeDecibel(cppArg0);
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_Phonon_VolumeFaderEffectFunc_setVolumeDecibel_TypeError:
        const char* overloads[] = {"float", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "PySide.phonon.VolumeFaderEffect.setVolumeDecibel", overloads);
        return 0;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_volume(PyObject* self)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // volume()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            float cppResult = const_cast<const ::Phonon::VolumeFaderEffect*>(cppSelf)->volume();
            PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<float>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_Phonon_VolumeFaderEffectFunc_volumeDecibel(PyObject* self)
{
    ::Phonon::VolumeFaderEffect* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Phonon::VolumeFaderEffect*)Shiboken::Conversions::cppPointer(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // volumeDecibel()const
            PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
            double cppResult = const_cast<const ::Phonon::VolumeFaderEffect*>(cppSelf)->volumeDecibel();
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

static PyMethodDef Sbk_Phonon_VolumeFaderEffect_methods[] = {
    {"fadeCurve", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_fadeCurve, METH_NOARGS},
    {"fadeIn", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_fadeIn, METH_O},
    {"fadeOut", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_fadeOut, METH_O},
    {"fadeTo", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_fadeTo, METH_VARARGS},
    {"setFadeCurve", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_setFadeCurve, METH_O},
    {"setVolume", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_setVolume, METH_O},
    {"setVolumeDecibel", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_setVolumeDecibel, METH_O},
    {"volume", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_volume, METH_NOARGS},
    {"volumeDecibel", (PyCFunction)Sbk_Phonon_VolumeFaderEffectFunc_volumeDecibel, METH_NOARGS},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Phonon_VolumeFaderEffect_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Phonon_VolumeFaderEffect_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
static void* Sbk_Phonon_VolumeFaderEffectSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    Phonon::VolumeFaderEffect* me = reinterpret_cast< ::Phonon::VolumeFaderEffect*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX]))
        return static_cast< ::Phonon::Effect*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast< ::QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_MEDIANODE_IDX]))
        return static_cast< ::Phonon::MediaNode*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Phonon_VolumeFaderEffect_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "PySide.phonon.Phonon.VolumeFaderEffect",
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
    /*tp_traverse*/         Sbk_Phonon_VolumeFaderEffect_traverse,
    /*tp_clear*/            Sbk_Phonon_VolumeFaderEffect_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Phonon_VolumeFaderEffect_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_Phonon_VolumeFaderEffect_Init,
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

static void* Sbk_Phonon_VolumeFaderEffect_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::QObject >()))
        return dynamic_cast< ::Phonon::VolumeFaderEffect*>(reinterpret_cast< ::QObject*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Phonon::MediaNode >()))
        return dynamic_cast< ::Phonon::VolumeFaderEffect*>(reinterpret_cast< ::Phonon::MediaNode*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ enum conversion.
static void Phonon_VolumeFaderEffect_FadeCurve_PythonToCpp_Phonon_VolumeFaderEffect_FadeCurve(PyObject* pyIn, void* cppOut) {
    *((::Phonon::VolumeFaderEffect::FadeCurve*)cppOut) = (::Phonon::VolumeFaderEffect::FadeCurve) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_Phonon_VolumeFaderEffect_FadeCurve_PythonToCpp_Phonon_VolumeFaderEffect_FadeCurve_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX]))
        return Phonon_VolumeFaderEffect_FadeCurve_PythonToCpp_Phonon_VolumeFaderEffect_FadeCurve;
    return 0;
}
static PyObject* Phonon_VolumeFaderEffect_FadeCurve_CppToPython_Phonon_VolumeFaderEffect_FadeCurve(const void* cppIn) {
    int castCppIn = *((::Phonon::VolumeFaderEffect::FadeCurve*)cppIn);
    return Shiboken::Enum::newItem(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void VolumeFaderEffect_PythonToCpp_VolumeFaderEffect_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Phonon_VolumeFaderEffect_Type, pyIn, cppOut);
}
static PythonToCppFunc is_VolumeFaderEffect_PythonToCpp_VolumeFaderEffect_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Phonon_VolumeFaderEffect_Type))
        return VolumeFaderEffect_PythonToCpp_VolumeFaderEffect_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* VolumeFaderEffect_PTR_CppToPython_VolumeFaderEffect(const void* cppIn) {
    return PySide::getWrapperForQObject((::Phonon::VolumeFaderEffect*)cppIn, &Sbk_Phonon_VolumeFaderEffect_Type);

}

void init_Phonon_VolumeFaderEffect(PyObject* enclosingClass)
{
    SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Phonon_VolumeFaderEffect_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(enclosingClass, "VolumeFaderEffect", "Phonon::VolumeFaderEffect*",
        &Sbk_Phonon_VolumeFaderEffect_Type, &Shiboken::callCppDestructor< ::Phonon::VolumeFaderEffect >, (SbkObjectType*)SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX], 0, true)) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Phonon_VolumeFaderEffect_Type,
        VolumeFaderEffect_PythonToCpp_VolumeFaderEffect_PTR,
        is_VolumeFaderEffect_PythonToCpp_VolumeFaderEffect_PTR_Convertible,
        VolumeFaderEffect_PTR_CppToPython_VolumeFaderEffect);

    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderEffect");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderEffect*");
    Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderEffect&");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderEffect");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderEffect*");
    Shiboken::Conversions::registerConverterName(converter, "VolumeFaderEffect&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Phonon::VolumeFaderEffect).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::VolumeFaderEffectWrapper).name());


    MultipleInheritanceInitFunction func = Shiboken::ObjectType::getMultipleIheritanceFunction(reinterpret_cast<SbkObjectType*>(SbkPySide_phononTypes[SBK_PHONON_EFFECT_IDX]));
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_Phonon_VolumeFaderEffect_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_Phonon_VolumeFaderEffect_Type, &Sbk_Phonon_VolumeFaderEffectSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Phonon_VolumeFaderEffect_Type, &Sbk_Phonon_VolumeFaderEffect_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'FadeCurve'.
    SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_Phonon_VolumeFaderEffect_Type,
        "FadeCurve",
        "PySide.phonon.Phonon.VolumeFaderEffect.FadeCurve",
        "Phonon::VolumeFaderEffect::FadeCurve");
    if (!SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX],
        &Sbk_Phonon_VolumeFaderEffect_Type, "Fade3Decibel", (long) Phonon::VolumeFaderEffect::Fade3Decibel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX],
        &Sbk_Phonon_VolumeFaderEffect_Type, "Fade6Decibel", (long) Phonon::VolumeFaderEffect::Fade6Decibel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX],
        &Sbk_Phonon_VolumeFaderEffect_Type, "Fade9Decibel", (long) Phonon::VolumeFaderEffect::Fade9Decibel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX],
        &Sbk_Phonon_VolumeFaderEffect_Type, "Fade12Decibel", (long) Phonon::VolumeFaderEffect::Fade12Decibel))
        return ;
    // Register converter for enum 'Phonon::VolumeFaderEffect::FadeCurve'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX],
            Phonon_VolumeFaderEffect_FadeCurve_CppToPython_Phonon_VolumeFaderEffect_FadeCurve);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Phonon_VolumeFaderEffect_FadeCurve_PythonToCpp_Phonon_VolumeFaderEffect_FadeCurve,
            is_Phonon_VolumeFaderEffect_FadeCurve_PythonToCpp_Phonon_VolumeFaderEffect_FadeCurve_Convertible);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkPySide_phononTypes[SBK_PHONON_VOLUMEFADEREFFECT_FADECURVE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Phonon::VolumeFaderEffect::FadeCurve");
        Shiboken::Conversions::registerConverterName(converter, "VolumeFaderEffect::FadeCurve");
        Shiboken::Conversions::registerConverterName(converter, "FadeCurve");
    }
    // End of 'FadeCurve' enum.


    qRegisterMetaType< ::Phonon::VolumeFaderEffect::FadeCurve >("VolumeFaderEffect::FadeCurve");
    qRegisterMetaType< ::Phonon::VolumeFaderEffect::FadeCurve >("Phonon::VolumeFaderEffect::FadeCurve");
    Shiboken::ObjectType::setSubTypeInitHook(&Sbk_Phonon_VolumeFaderEffect_Type, &PySide::initQObjectSubType);
    PySide::initDynamicMetaObject(&Sbk_Phonon_VolumeFaderEffect_Type, &::Phonon::VolumeFaderEffect::staticMetaObject, sizeof(::Phonon::VolumeFaderEffect));
}
